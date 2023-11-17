/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
WaveformTestAudioProcessorEditor::WaveformTestAudioProcessorEditor(WaveformTestAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    Timer::startTimer(120);
    setSize(500, 300);
    setResizable(false, false);
}

WaveformTestAudioProcessorEditor::~WaveformTestAudioProcessorEditor()
{
    Timer::stopTimer();
}

//==============================================================================
void WaveformTestAudioProcessorEditor::paint(juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::black);
    paintHistogram(g);
}

void WaveformTestAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void WaveformTestAudioProcessorEditor::timerCallback()
{
    repaint();
}

void WaveformTestAudioProcessorEditor::paintHistogram(juce::Graphics& g)
{
    int ampHeight = static_cast<int>(audioProcessor.mAmplitude * 300);

    for (int i = 0; i < 499; i++) {
        rectArray[i] = rectArray[i + 1];
    }

    rectArray[499] = ampHeight;
    for (int i = 0; i < 500; i++) {
        g.setColour(juce::Colours::lightgreen);
        g.fillRect(i, 300 - rectArray[i], 1, rectArray[i]);
    }
}
