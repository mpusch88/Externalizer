/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <vector>
#include <utility>
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class ExternalizerAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    ExternalizerAudioProcessorEditor (ExternalizerAudioProcessor&);
    ~ExternalizerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ExternalizerAudioProcessor& audioProcessor;

    juce::AudioDeviceManager deviceManager;
    juce::ComboBox inputChannelComboBox;
    juce::ComboBox outputChannelComboBox;
    juce::Label inputChannelLabel;
    juce::Label outputChannelLabel;

    void inputChannelComboBoxChanged();
    void outputChannelComboBoxChanged();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ExternalizerAudioProcessorEditor)
};
