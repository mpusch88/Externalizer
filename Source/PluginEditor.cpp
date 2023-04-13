/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ExternalizerAudioProcessorEditor::ExternalizerAudioProcessorEditor (ExternalizerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Initialize the AudioDeviceManager with no inputs and outputs
    deviceManager.initialise(0, 0, nullptr, true);
    juce::StringArray inputChannelNames;

    // Get the current audio device
    auto* currentAudioDevice = deviceManager.getCurrentAudioDevice();
    if (currentAudioDevice != nullptr)
    {
        // Get the input channel names
        inputChannelNames = currentAudioDevice->getInputChannelNames();

        // Print the input channels
        DBG("Input channels for the current audio device:");
        for (const auto& channelName : inputChannelNames)
        {
            DBG(channelName);
        }
    }
    else
    {
        DBG("No audio device is currently selected.");
    }

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    // Set up input channel ComboBox and Label
    inputChannelComboBox.onChange = [this] { inputChannelComboBoxChanged(); };
    addAndMakeVisible(inputChannelComboBox);
    inputChannelLabel.setText("Input Channel", juce::dontSendNotification);
    inputChannelLabel.attachToComponent(&inputChannelComboBox, false);
    
    // Set up output channel ComboBox and Label
    outputChannelComboBox.onChange = [this] { outputChannelComboBoxChanged(); };
    addAndMakeVisible(outputChannelComboBox);
    outputChannelLabel.setText("Output Channel", juce::dontSendNotification);
    outputChannelLabel.attachToComponent(&outputChannelComboBox, false);

    // Populate ComboBoxes with channel numbers
    for (int i = 1; i <= audioProcessor.getTotalNumInputChannels(); ++i) {
        inputChannelComboBox.addItem("Channel " + juce::String(i), i);
    }
    for (int i = 1; i <= audioProcessor.getTotalNumOutputChannels(); ++i) {
        outputChannelComboBox.addItem("Channel " + juce::String(i), i);
    }
}

ExternalizerAudioProcessorEditor::~ExternalizerAudioProcessorEditor()
{
}

//==============================================================================
void ExternalizerAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void ExternalizerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    // Position input/output channel ComboBoxes
    int comboBoxWidth = 100;
    int comboBoxHeight = 24;
    int comboBoxMargin = 10;

    inputChannelComboBox.setBounds(10, getHeight() - comboBoxHeight - comboBoxMargin, comboBoxWidth, comboBoxHeight);
    outputChannelComboBox.setBounds(10 + comboBoxWidth + comboBoxMargin, getHeight() - comboBoxHeight - comboBoxMargin, comboBoxWidth, comboBoxHeight);

}

void ExternalizerAudioProcessorEditor::inputChannelComboBoxChanged()
{
    int selectedInputChannel = inputChannelComboBox.getSelectedId();
    DBG("Selected input channel: " << selectedInputChannel);
}

void ExternalizerAudioProcessorEditor::outputChannelComboBoxChanged()
{
    int selectedOutputChannel = outputChannelComboBox.getSelectedId();
    DBG("Selected output channel: " << selectedOutputChannel);
}
