/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class WaveformTestAudioProcessorEditor : public juce::AudioProcessorEditor, public juce::Timer
{
public:
    WaveformTestAudioProcessorEditor(WaveformTestAudioProcessor&);
    ~WaveformTestAudioProcessorEditor() override;

    //==============================================================================
    void paint(juce::Graphics&) override;
    void resized() override;

    void timerCallback() override;
    void paintHistogram(juce::Graphics&);

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    int rectArray[500] = { 0 };
    WaveformTestAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WaveformTestAudioProcessorEditor)
};
