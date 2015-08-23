/*
  ==============================================================================

    PushTheVibe.h
    Created: 3 Oct 2014 10:32:42pm
    Author:  niowniow

  ==============================================================================
*/

#ifndef PUSHTHEVIBE_H_INCLUDED
#define PUSHTHEVIBE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class PushTheVibe
{
public:

	void initialize();
	void setup(int audiodev);

	void showAudioDeviceTypes();
	int setAudioDeviceType(int audiotype);

	void start();

	void loadDefault();
	bool loadFiltergraph(String filtergraphfn);


	bool loadFromXmlPTV(const XmlElement& xml, PluginDescription *pd);
	void createNodeFromXml(const XmlElement& xml);
	void restoreFromXml(const XmlElement& xml);
	bool addConnection(uint32 sourceFilterUID, int sourceFilterChannel, 
								uint32 destFilterUID, int destFilterChannel);
	Result loadDocument(const File& file);

	ScopedPointer<AudioDeviceManager> sharedAudioDeviceManager;
	AudioPluginFormatManager formatManager;
	AudioIODevice *device;
	AudioProcessorGraph graph;
};




#endif  // PUSHTHEVIBE_H_INCLUDED
