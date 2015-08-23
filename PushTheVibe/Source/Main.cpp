/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"

#include "ptvAudioCallback.h"
#include "PushTheVibe.h"
#include "oscReceiver.h"




using namespace std;


const int midiChannelNumber = 0x1000;
Result loadDocument(const File& file);

//==============================================================================
int main (int argc, char* argv[])
{
	initialiseJuce_GUI();

	ScopedPointer<AudioDeviceManager> sharedAudioDeviceManager;
	ScopedPointer<ptvAudioCallback> ptvCallback;


	PushTheVibe pushTheVibe;
	String error;

	String filtergraph_filename = "";
	filtergraph_filename = "../data/filtergraphs/default.filtergraph";

	int audiodev = 0;
	int audiotype = 1;
	int audiolist = 1;

	for (int i = 0; i < argc; i++)
	{
		if (strcmp(argv[i], "-audiotype") == 0)
		{
			audiotype = atoi(argv[i + 1]);
			i++;
		}
		else if (strcmp(argv[i], "-audiodev") == 0)
		{
			audiodev = atoi(argv[i + 1]);
			i++;
		}
		else if (strcmp(argv[i], "-audiolist") == 0)
		{
			audiolist = 1;
		}
		else if (strcmp(argv[i], "-f") == 0)
		{
			filtergraph_filename = argv[i + 1];
			i++;
		}
	}

	cout << audiotype << audiodev << endl;

	Process::setPriority(Process::HighPriority);

	pushTheVibe.initialize();


	if (audiolist == 1)
		pushTheVibe.showAudioDeviceTypes();

	if (pushTheVibe.setAudioDeviceType(audiotype) == 1)
		return 1;

	//const OwnedArray <AudioIODeviceType>& types = sharedAudioDeviceManager->getAvailableDeviceTypes();

	pushTheVibe.setup(audiodev);

	//sharedAudioDeviceManager = pushTheVibe.sharedAudioDeviceManager;

	//ptvCallback = new ptvAudioCallback;
	//sharedAudioDeviceManager->addAudioCallback(ptvCallback);

	pushTheVibe.loadDefault();
	pushTheVibe.loadFiltergraph(filtergraph_filename);
	pushTheVibe.start();

	// ------------ OSC ---------
	std::cout << "Port 7000\n";

	int port = 7000;

	osc::OscReceiveTestPacketListener listener;

	//listener.audioPlugin = synthInst;

	UdpListeningReceiveSocket s(
		IpEndpointName(IpEndpointName::ANY_ADDRESS, port),
		&listener);

	s.SetAllowReuse(true);

	std::cout << "listening for input on port " << port << "...\n";

	s.RunUntilSigInt();

	std::cout << "finishing.\n";
	
	//while (1)
	{
	}


	shutdownJuce_GUI();
    return 0;
}

