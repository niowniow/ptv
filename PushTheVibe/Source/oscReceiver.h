/*
  ==============================================================================

    oscReceiver.h
    Created: 7 Apr 2014 9:35:59pm
    Author:  niowniow

  ==============================================================================
*/

#ifndef OSCRECEIVER_H_INCLUDED
#define OSCRECEIVER_H_INCLUDED

#include <cstdlib>
#include <cstring>
#include <iostream>

#include "osc/OscReceivedElements.h"

#include "ip/UdpSocket.h"
#include "osc/OscPacketListener.h"

#include "ptvAudioCallback.h"


namespace osc{

	class OscReceiveTestPacketListener : public OscPacketListener{

	public:
		OscReceiveTestPacketListener()
		{
			currentProgram = 14;
		}

		ptvAudioCallback *audioCallback;
		AudioPluginInstance *audioPlugin;

		int currentProgram;

	protected:

		void ProcessMessage(const osc::ReceivedMessage& m,
			const IpEndpointName& remoteEndpoint)
		{
			(void)remoteEndpoint; // suppress unused parameter warning


			try {
				ReceivedMessageArgumentStream args = m.ArgumentStream();
				ReceivedMessage::const_iterator arg = m.ArgumentsBegin();

				//std::cout << "pattern: " << m.AddressPattern() << "\n";

				if (std::strcmp(m.AddressPattern(), "/PushTheVibe/push1") == 0){
					float a = (arg++)->AsFloat();
					if (a == 1){
						if (currentProgram == 0)
							std::cout << "warning: lowest program chosen\n";
						else{
							audioPlugin->setCurrentProgram(--currentProgram);
							std::cout << "Current Program: " << currentProgram << std::endl;
						}
					}
					else
						audioPlugin->setCurrentProgram(currentProgram);
				}
				else if (std::strcmp(m.AddressPattern(), "/PushTheVibe/push2") == 0){
					float a = (arg++)->AsFloat();
					if (a == 1){
						if (currentProgram == audioPlugin->getNumPrograms() - 1)
							std::cout << "warning: highest program chosen. Nr: " << audioPlugin->getNumPrograms() - 1 << std::endl;
						else{
							audioPlugin->setCurrentProgram(++currentProgram);
							std::cout << "Current Program: " << currentProgram << std::endl;
						}
					}
					else
						audioPlugin->setCurrentProgram(currentProgram);
				}
				else{
					std::cout << "unrecognised address pattern: "
						<< m.AddressPattern() << "\n";
				}

			}
			catch (Exception& e){
				std::cout << "error while parsing message: "
					<< m.AddressPattern() << ": " << e.what() << "\n";
			}
		}
	};
} // namespace osc


#endif  // OSCRECEIVER_H_INCLUDED
