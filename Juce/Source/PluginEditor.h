/*
  ==============================================================================

	This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "DspFaust.h"

//==============================================================================
/**
*/
class NewProjectAudioProcessorEditor : public juce::AudioProcessorEditor, private juce::MidiInputCallback, private juce::MidiKeyboardStateListener, public juce::LookAndFeel_V4
{


public:


	//==============================================================================
	void paint(juce::Graphics&) override;
	void resized() override;

	NewProjectAudioProcessorEditor(NewProjectAudioProcessor&);
	~NewProjectAudioProcessorEditor() override;


private:
	juce::Slider gainSlider;
	juce::Label gainLabel;
	juce::Slider globalAttackSlider;
	juce::Label globalAttackLabel;
	juce::Slider globalReleaseSlider;
	juce::Label globalReleaseLabel;
	juce::Slider IndexSlider1;
	juce::Slider IndexSlider2;
	juce::Slider IndexSlider3;
	juce::Slider IndexSlider4;
	juce::Slider IndexSlider5;
	juce::Slider IndexSlider6;
	juce::Slider AttackSlider1;
	juce::Slider AttackSlider2;
	juce::Slider AttackSlider3;
	juce::Slider AttackSlider4;
	juce::Slider AttackSlider5;
	juce::Slider AttackSlider6;
	juce::Slider DecaySlider1;
	juce::Slider DecaySlider2;
	juce::Slider DecaySlider3;
	juce::Slider DecaySlider4;
	juce::Slider DecaySlider5;
	juce::Slider DecaySlider6;
	juce::Slider SustainSlider1;
	juce::Slider SustainSlider2;
	juce::Slider SustainSlider3;
	juce::Slider SustainSlider4;
	juce::Slider SustainSlider5;
	juce::Slider SustainSlider6;
	juce::Slider ReleaseSlider1;
	juce::Slider ReleaseSlider2;
	juce::Slider ReleaseSlider3;
	juce::Slider ReleaseSlider4;
	juce::Slider ReleaseSlider5;
	juce::Slider ReleaseSlider6;
	juce::Slider CutOffFreqSlider;
	juce::Label cutoffFreqLabel;
	juce::Slider QSlider;
	juce::Label QLabel;
	juce::Slider LfoFreqSlider;
	juce::Label LfoFreqLabel;
	juce::Slider LfoDepthSlider;
	juce::Label LfoDepthLabel;
	juce::Slider ResFreqSlider;
	juce::Label ResFreqLabel;
	juce::Slider DurationLeftSlider;
	juce::Label DurationLeftLabel;
	juce::Slider FeedbackLeftSlider;
	juce::Label FeedbackLeftLabel;
	juce::Slider DurationRightSlider;
	juce::Label DurationRightLabel;
	juce::Slider FeedbackRightSlider;
	juce::Label FeedbackRightLabel;


	void handleNoteOn(juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity) override;

	void handleNoteOff(juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float /*velocity*/) override;

	void handleIncomingMidiMessage(juce::MidiInput* source, const juce::MidiMessage& message) override;

	juce::MidiKeyboardState keyboardState;
	juce::MidiKeyboardComponent keyboardComponent;

	NewProjectAudioProcessor& audioProcessor;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NewProjectAudioProcessorEditor)
};
