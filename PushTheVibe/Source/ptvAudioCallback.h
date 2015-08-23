/*
  ==============================================================================

    ptvAudioCallback.h
    Created: 8 Apr 2014 10:04:57am
    Author:  niowniow

  ==============================================================================
*/

#ifndef PTVAUDIOCALLBACK_H_INCLUDED
#define PTVAUDIOCALLBACK_H_INCLUDED


#include "../JuceLibraryCode/JuceHeader.h"
#include <iostream>

#define PI 3.14159265358979

class ptvAudioCallback : public AudioIODeviceCallback
{
public:
	ptvAudioCallback()
		: sampleRate(0)
	{
	}

	~ptvAudioCallback()
	{
	}

	//==============================================================================
	void audioDeviceAboutToStart(AudioIODevice* device)
	{
		sampleRate = device->getCurrentSampleRate();
		deviceInputLatency = device->getInputLatencyInSamples();
		deviceOutputLatency = device->getOutputLatencyInSamples();

		//std::cout << sampleRate << std::endl;

		cnt = 0;
		theta = 0;
		frequency = 0;
	}

	void audioDeviceStopped()
	{
	}

	void audioDeviceIOCallback(const float** inputChannelData,
		int numInputChannels,
		float** outputChannelData,
		int numOutputChannels,
		int numSamples)
	{
		const ScopedLock sl(lock);

		Random rand;

		for (int i = 0; i < numSamples; ++i)
		{
			float amp = 1;
			float theta_increment = 2 * PI * frequency / sampleRate;
			theta += theta_increment;
			if (theta > 2 * PI)
				theta -= 2 * PI;

			if (theta < PI)
				amp = -1.0;
			else
				amp = 1.0;

			float sample = amp;

			for (int j = numOutputChannels; --j >= 0;)
			{
				if (outputChannelData[j] != 0)
					outputChannelData[j][i] = sample; // rand.nextFloat();
			}
		}
	}

	void setFrequency(float freq)
	{
		frequency = freq;
	}

private:
	CriticalSection lock;
	double sampleRate;
	int deviceInputLatency, deviceOutputLatency;

	int cnt;
	float theta;

	float frequency;


	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ptvAudioCallback);
};


#endif  // PTVAUDIOCALLBACK_H_INCLUDED
