/*
  ==============================================================================

    PushTheVibe.cpp
    Created: 3 Oct 2014 10:32:42pm
    Author:  niowniow

  ==============================================================================
*/

#include "PushTheVibe.h"
#include "InternalFilters.h"
using namespace std;


void PushTheVibe::initialize()
{
	sharedAudioDeviceManager = new AudioDeviceManager();
	sharedAudioDeviceManager->initialise(2, 2, 0, true, String::empty, 0);
}

void PushTheVibe::setup(int audiodev)
{
	AudioDeviceManager::AudioDeviceSetup setup;
	sharedAudioDeviceManager->getAudioDeviceSetup(setup);
	setup.outputDeviceName = sharedAudioDeviceManager->getCurrentDeviceTypeObject()->getDeviceNames()[audiodev];
	setup.inputDeviceName = sharedAudioDeviceManager->getCurrentDeviceTypeObject()->getDeviceNames(true)[audiodev];
	setup.useDefaultInputChannels = true;
	setup.useDefaultOutputChannels = true;
	setup.sampleRate = 0;
	setup.bufferSize = 0;
	String error = sharedAudioDeviceManager->setAudioDeviceSetup(setup, true);
	cout << "Status: " << error << endl;
}

void PushTheVibe::showAudioDeviceTypes()
{
	cout << "\n-- Audio Device Types --" << endl;
	//sharedAudioDeviceManager->getAvailableDeviceTypes();
	for (int i = 0; i < sharedAudioDeviceManager->getAvailableDeviceTypes().size(); i++)
		std::cout << " [" << i << "] " << sharedAudioDeviceManager->getAvailableDeviceTypes()[i]->getTypeName() << std::endl;


	sharedAudioDeviceManager->getCurrentDeviceTypeObject()->scanForDevices();

	for (int j = 0; j < sharedAudioDeviceManager->getAvailableDeviceTypes().size(); j++)
	{
		sharedAudioDeviceManager->setCurrentAudioDeviceType(sharedAudioDeviceManager->getAvailableDeviceTypes()[j]->getTypeName(), true);

		cout << "\n================ " << sharedAudioDeviceManager->getAvailableDeviceTypes()[j]->getTypeName() << "================ " << endl;
		cout << "-- Input Audio Devices --" << endl;
		for (int i = 0; i < sharedAudioDeviceManager->getCurrentDeviceTypeObject()->getDeviceNames().size(); i++)
			cout << " [" << i << "] " << sharedAudioDeviceManager->getCurrentDeviceTypeObject()->getDeviceNames()[i] << endl;

		cout << "-- Output Audio Devices --" << endl;

		for (int i = 0; i < sharedAudioDeviceManager->getCurrentDeviceTypeObject()->getDeviceNames().size(); i++)
			cout << " [" << i << "] " << sharedAudioDeviceManager->getCurrentDeviceTypeObject()->getDeviceNames(true)[i] << endl;
	}
}

int PushTheVibe::setAudioDeviceType(int audiotype)
{
	if (audiotype >= sharedAudioDeviceManager->getAvailableDeviceTypes().size())
	{
		cout << "No audio device type with number " << audiotype;
		return 1;
	}

	sharedAudioDeviceManager->setCurrentAudioDeviceType(sharedAudioDeviceManager->getAvailableDeviceTypes()[audiotype]->getTypeName(), true);
	cout << sharedAudioDeviceManager->getCurrentDeviceTypeObject()->getTypeName() << endl;
	cout << sharedAudioDeviceManager->getCurrentAudioDeviceType() << endl;

	return 0;
}

void PushTheVibe::loadDefault()
{
	device = sharedAudioDeviceManager->getCurrentAudioDevice();
	AudioProcessorPlayer *audioProcessorPlayer = new AudioProcessorPlayer();
	audioProcessorPlayer->setProcessor(&graph);
	sharedAudioDeviceManager->addAudioCallback(audioProcessorPlayer);
	graph.prepareToPlay(device->getCurrentSampleRate(), device->getCurrentBufferSizeSamples());

	formatManager.addFormat(new InternalPluginFormat());
	//formatManager.addFormat(&format);
	formatManager.addDefaultFormats();
}

bool PushTheVibe::loadFiltergraph(String filtergraphfn)
{

	File dfg = File(filtergraphfn);
	Result status = loadDocument(dfg);
	
	if (status.failed())
	{
		cout << "Trying " << "../data/filtergraphs/" << endl;

		String filename = "../data/filtergraphs/" + filtergraphfn;
		dfg = File(filename);
		Result status2 = loadDocument(dfg);
		if (status2.failed()){
			cout << "Loading filtergraph failed.\nerror:" << status.getErrorMessage() << endl;
			return false;
		}

	}

	for (int i = 0; i < graph.getNumConnections(); i++)
	{
		int sourceNodeId = graph.getConnection(i)->sourceNodeId;
		int destNodeId = graph.getConnection(i)->destNodeId;
		cout << "source: " << graph.getNodeForId(sourceNodeId)->getProcessor()->getName() << "(" << sourceNodeId << ")"
			<< " dest: " << graph.getNodeForId(destNodeId)->getProcessor()->getName() << "(" << destNodeId << ")" << endl;
	}

	return true;
}

void PushTheVibe::start()
{
	//midiInDev->start();

	graph.prepareToPlay(device->getCurrentSampleRate(), device->getCurrentBufferSizeSamples());
}

bool PushTheVibe::loadFromXmlPTV(const XmlElement& xml, PluginDescription *pd)
{
	if (xml.hasTagName("PLUGIN"))
	{
		pd->name = xml.getStringAttribute("name");
		pd->descriptiveName = xml.getStringAttribute("descriptiveName", pd->name);
		pd->pluginFormatName = xml.getStringAttribute("format");
		pd->category = xml.getStringAttribute("category");
		pd->manufacturerName = xml.getStringAttribute("manufacturer");
		pd->version = xml.getStringAttribute("version");

		File wdir = File::getSpecialLocation(File::currentExecutableFile).getParentDirectory();
		wdir.setAsCurrentWorkingDirectory();

		String vstpath = "";
		String extension = "";

#if JUCE_WINDOWS
		vstpath = "../data/vst/win32/";
		extension = ".dll";
#endif
#if JUCE_LINUX
		vstpath = "../data/vst/linux/";
		extension = ".so";
#endif
#if JUCE_MAC
		vstpath = "../data/vst/mac/";
		extension = ".so";
#endif
#if PTV_ARMV7
		vstpath = "../data/vst/armv7/";
		extension = ".so";
#endif

		vstpath += pd->name;
		vstpath += extension;
		pd->fileOrIdentifier = vstpath;

		pd->uid = xml.getStringAttribute("uid").getHexValue32();
		pd->isInstrument = xml.getBoolAttribute("isInstrument", false);
		pd->lastFileModTime = Time(xml.getStringAttribute("fileTime").getHexValue64());
		pd->numInputChannels = xml.getIntAttribute("numInputs");
		pd->numOutputChannels = xml.getIntAttribute("numOutputs");
		pd->hasSharedContainer = xml.getBoolAttribute("isShell", false);

		return true;
	}

	return false;

}

void PushTheVibe::createNodeFromXml(const XmlElement& xml)
{
	PluginDescription pd;

	forEachXmlChildElement(xml, e)
	{
		if (loadFromXmlPTV(*e, &pd))
			break;
	}

	String errorMessage;

	AudioPluginInstance* instance = formatManager.createPluginInstance(pd, graph.getSampleRate(), graph.getBlockSize(), errorMessage);

	if (instance == nullptr) 
	{
		// xxx handle ins + outs
	}

	if (instance == nullptr)
		return;

	AudioProcessorGraph::Node::Ptr node(graph.addNode(instance, xml.getIntAttribute("uid")));

	if (const XmlElement* const state = xml.getChildByName("STATE"))
	{
		MemoryBlock m;
		m.fromBase64Encoding(state->getAllSubText());

		node->getProcessor()->setStateInformation(m.getData(), (int)m.getSize());
	}

	cout << pd.name << endl;
	node->properties.set("x", xml.getDoubleAttribute("x"));
	node->properties.set("y", xml.getDoubleAttribute("y"));
	node->properties.set("uiLastX", xml.getIntAttribute("uiLastX"));
	node->properties.set("uiLastY", xml.getIntAttribute("uiLastY"));
}

bool PushTheVibe::addConnection(uint32 sourceFilterUID, int sourceFilterChannel,
	uint32 destFilterUID, int destFilterChannel)
{
	const bool result = graph.addConnection(sourceFilterUID, sourceFilterChannel,
		destFilterUID, destFilterChannel);

//	if (result)
//		changed();

	return result;
}

void PushTheVibe::restoreFromXml(const XmlElement& xml)
{
	graph.clear();

	forEachXmlChildElementWithTagName(xml, e, "FILTER")
	{
		createNodeFromXml(*e);
//		changed();
	}

	forEachXmlChildElementWithTagName(xml, e, "CONNECTION")
	{
		addConnection((uint32)e->getIntAttribute("srcFilter"),
			e->getIntAttribute("srcChannel"),
			(uint32)e->getIntAttribute("dstFilter"),
			e->getIntAttribute("dstChannel"));
	}

	graph.removeIllegalConnections();
}

Result PushTheVibe::loadDocument(const File& file)
{
	XmlDocument doc(file);
	ScopedPointer<XmlElement> xml(doc.getDocumentElement());

	if (xml == nullptr || !xml->hasTagName("FILTERGRAPH"))
		return Result::fail("Not a valid filter graph file");

	restoreFromXml(*xml);
	return Result::ok();
}