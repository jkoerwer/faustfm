/*
  ==============================================================================

	This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor(NewProjectAudioProcessor& p)
	: AudioProcessorEditor(&p), audioProcessor(p), keyboardComponent(keyboardState, juce::MidiKeyboardComponent::horizontalKeyboard)
{
	// Make sure that before the constructor has finished, you've set the
	// editor's size to whatever you need it to be.
	setSize(1000, 600);

	keyboardState.addListener(this);
	addAndMakeVisible(keyboardComponent);

	addAndMakeVisible(gainSlider);
	gainSlider.setRange(0, 1.f);
	gainSlider.setValue(1.0);
	gainSlider.onValueChange = [this] {audioProcessor.setGain(gainSlider.getValue()); };
	gainSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	gainSlider.setSliderStyle(juce::Slider::LinearVertical);

	addAndMakeVisible(gainLabel);
	gainLabel.setText("Gain", juce::dontSendNotification);


	addAndMakeVisible(AttackSlider1);
	AttackSlider1.setSliderStyle(juce::Slider::Rotary);
	AttackSlider1.setRange(0, 3.0);
	AttackSlider1.setValue(0.1);
	AttackSlider1.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	AttackSlider1.onValueChange = [this] {audioProcessor.setA1(AttackSlider1.getValue()); };

	addAndMakeVisible(AttackSlider2);
	AttackSlider2.setSliderStyle(juce::Slider::Rotary);
	AttackSlider2.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	AttackSlider2.setRange(0, 3.0);
	AttackSlider2.setValue(0.1);
	AttackSlider2.onValueChange = [this] {audioProcessor.setA2(AttackSlider2.getValue()); };

	addAndMakeVisible(AttackSlider3);
	AttackSlider3.setSliderStyle(juce::Slider::Rotary);
	AttackSlider3.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	AttackSlider3.setRange(0, 3.0);
	AttackSlider3.setValue(0.1);
	AttackSlider3.onValueChange = [this] {audioProcessor.setA3(AttackSlider3.getValue()); };

	addAndMakeVisible(AttackSlider4);
	AttackSlider4.setSliderStyle(juce::Slider::Rotary);
	AttackSlider4.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	AttackSlider4.setRange(0, 3.0);
	AttackSlider4.setValue(0.1);
	AttackSlider4.onValueChange = [this] {audioProcessor.setA4(AttackSlider4.getValue()); };

	addAndMakeVisible(AttackSlider5);
	AttackSlider5.setSliderStyle(juce::Slider::Rotary);
	AttackSlider5.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	AttackSlider5.setRange(0, 3.0);
	AttackSlider5.setValue(0.1);
	AttackSlider5.onValueChange = [this] {audioProcessor.setA5(AttackSlider5.getValue()); };

	addAndMakeVisible(AttackSlider6);
	AttackSlider6.setSliderStyle(juce::Slider::Rotary);
	AttackSlider6.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	AttackSlider6.setRange(0, 3.0);
	AttackSlider6.setValue(0.1);
	AttackSlider6.onValueChange = [this] {audioProcessor.setA6(AttackSlider5.getValue()); };

	addAndMakeVisible(DecaySlider1);
	DecaySlider1.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	DecaySlider1.setRange(0, 3.0);
	DecaySlider1.setValue(0.1);
	DecaySlider1.setSliderStyle(juce::Slider::Rotary);
	DecaySlider1.onValueChange = [this] {audioProcessor.setD1(DecaySlider1.getValue()); };

	addAndMakeVisible(DecaySlider2);
	DecaySlider2.setSliderStyle(juce::Slider::Rotary);
	DecaySlider2.setRange(0, 3.0);
	DecaySlider2.setValue(0.1);
	DecaySlider2.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	DecaySlider2.onValueChange = [this] {audioProcessor.setD2(DecaySlider2.getValue()); };

	addAndMakeVisible(DecaySlider3);
	DecaySlider3.setSliderStyle(juce::Slider::Rotary);
	DecaySlider3.setRange(0, 3.0);
	DecaySlider3.setValue(0.1);
	DecaySlider3.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	DecaySlider3.onValueChange = [this] {audioProcessor.setD3(DecaySlider3.getValue()); };

	addAndMakeVisible(DecaySlider4);
	DecaySlider4.setSliderStyle(juce::Slider::Rotary);
	DecaySlider4.setRange(0, 3.0);
	DecaySlider4.setValue(0.1);
	DecaySlider4.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	DecaySlider4.onValueChange = [this] {audioProcessor.setD4(DecaySlider4.getValue()); };

	addAndMakeVisible(DecaySlider5);
	DecaySlider5.setSliderStyle(juce::Slider::Rotary);
	DecaySlider5.setRange(0, 3.0);
	DecaySlider5.setValue(0.1);
	DecaySlider5.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	DecaySlider5.onValueChange = [this] {audioProcessor.setD5(DecaySlider5.getValue()); };

	addAndMakeVisible(DecaySlider6);
	DecaySlider6.setSliderStyle(juce::Slider::Rotary);
	DecaySlider6.setRange(0, 3.0);
	DecaySlider6.setValue(0.1);
	DecaySlider6.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	DecaySlider6.onValueChange = [this] {audioProcessor.setD6(DecaySlider6.getValue()); };

	addAndMakeVisible(SustainSlider1);
	SustainSlider1.setSliderStyle(juce::Slider::Rotary);
	SustainSlider1.setRange(0, 1.0);
	SustainSlider1.setValue(1.0);
	SustainSlider1.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	SustainSlider1.onValueChange = [this] {audioProcessor.setS1(SustainSlider1.getValue()); };

	addAndMakeVisible(SustainSlider2);
	SustainSlider2.setSliderStyle(juce::Slider::Rotary);
	SustainSlider2.setRange(0, 1.0);
	SustainSlider2.setValue(1.0);
	SustainSlider2.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	SustainSlider2.onValueChange = [this] {audioProcessor.setS2(SustainSlider2.getValue()); };

	addAndMakeVisible(SustainSlider3);
	SustainSlider3.setSliderStyle(juce::Slider::Rotary);
	SustainSlider3.setRange(0, 1.0);
	SustainSlider3.setValue(1.0);
	SustainSlider3.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	SustainSlider3.onValueChange = [this] {audioProcessor.setS3(SustainSlider3.getValue()); };

	addAndMakeVisible(SustainSlider4);
	SustainSlider4.setSliderStyle(juce::Slider::Rotary);
	SustainSlider4.setRange(0, 1.0);
	SustainSlider4.setValue(1.0);
	SustainSlider4.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	SustainSlider4.onValueChange = [this] {audioProcessor.setS4(SustainSlider4.getValue()); };

	addAndMakeVisible(SustainSlider5);
	SustainSlider5.setSliderStyle(juce::Slider::Rotary);
	SustainSlider5.setRange(0, 1.0);
	SustainSlider5.setValue(1.0);
	SustainSlider5.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	SustainSlider5.onValueChange = [this] {audioProcessor.setS5(SustainSlider5.getValue()); };

	addAndMakeVisible(SustainSlider6);
	SustainSlider6.setSliderStyle(juce::Slider::Rotary);
	SustainSlider6.setRange(0, 1.0);
	SustainSlider6.setValue(1.0);
	SustainSlider6.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	SustainSlider6.onValueChange = [this] {audioProcessor.setS6(SustainSlider6.getValue()); };

	addAndMakeVisible(ReleaseSlider1);
	ReleaseSlider1.setSliderStyle(juce::Slider::Rotary);
	ReleaseSlider1.setRange(0, 1.0);
	ReleaseSlider1.setValue(1.0);
	ReleaseSlider1.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	ReleaseSlider1.onValueChange = [this] {audioProcessor.setR1(ReleaseSlider1.getValue()); };

	addAndMakeVisible(ReleaseSlider2);
	ReleaseSlider2.setSliderStyle(juce::Slider::Rotary);
	ReleaseSlider2.setRange(0, 1.0);
	ReleaseSlider2.setValue(1.0);
	ReleaseSlider2.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	ReleaseSlider2.onValueChange = [this] {audioProcessor.setR2(ReleaseSlider2.getValue()); };

	addAndMakeVisible(ReleaseSlider3);
	ReleaseSlider3.setSliderStyle(juce::Slider::Rotary);
	ReleaseSlider3.setRange(0, 1.0);
	ReleaseSlider3.setValue(1.0);
	ReleaseSlider3.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	ReleaseSlider3.onValueChange = [this] {audioProcessor.setR3(ReleaseSlider3.getValue()); };

	addAndMakeVisible(ReleaseSlider4);
	ReleaseSlider4.setSliderStyle(juce::Slider::Rotary);
	ReleaseSlider4.setRange(0, 1.0);
	ReleaseSlider4.setValue(1.0);
	ReleaseSlider4.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	ReleaseSlider4.onValueChange = [this] {audioProcessor.setR4(ReleaseSlider4.getValue()); };

	addAndMakeVisible(ReleaseSlider5);
	ReleaseSlider5.setSliderStyle(juce::Slider::Rotary);
	ReleaseSlider5.setRange(0, 1.0);
	ReleaseSlider5.setValue(1.0);
	ReleaseSlider5.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	ReleaseSlider5.onValueChange = [this] {audioProcessor.setR5(ReleaseSlider5.getValue()); };

	addAndMakeVisible(ReleaseSlider6);
	ReleaseSlider6.setSliderStyle(juce::Slider::Rotary);
	ReleaseSlider6.setRange(0, 1.0);
	ReleaseSlider6.setValue(1.0);
	ReleaseSlider6.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	ReleaseSlider6.onValueChange = [this] {audioProcessor.setR6(ReleaseSlider6.getValue()); };

	addAndMakeVisible(IndexSlider1);
	IndexSlider1.setSliderStyle(juce::Slider::Rotary);
	IndexSlider1.setRange(0, 100.0);
	IndexSlider1.setValue(1);
	IndexSlider1.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	IndexSlider1.onValueChange = [this] {audioProcessor.setIndex1(IndexSlider1.getValue()); };


	addAndMakeVisible(IndexSlider2);
	IndexSlider2.setRange(0, 100.0);
	IndexSlider2.setValue(0);
	IndexSlider2.onValueChange = [this] {audioProcessor.setIndex2(IndexSlider2.getValue()); };
	IndexSlider2.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	IndexSlider2.setSliderStyle(juce::Slider::Rotary);

	addAndMakeVisible(IndexSlider3);
	IndexSlider3.setRange(0, 100.0);
	IndexSlider3.setValue(0);
	IndexSlider3.onValueChange = [this] {audioProcessor.setIndex3(IndexSlider3.getValue()); };
	IndexSlider3.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	IndexSlider3.setSliderStyle(juce::Slider::Rotary);

	addAndMakeVisible(IndexSlider4);
	IndexSlider4.setRange(0, 100.0);
	IndexSlider4.setValue(0);
	IndexSlider4.onValueChange = [this] {audioProcessor.setIndex4(IndexSlider4.getValue()); };
	IndexSlider4.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	IndexSlider4.setSliderStyle(juce::Slider::Rotary);

	addAndMakeVisible(IndexSlider5);
	IndexSlider5.setRange(0, 100.0);
	IndexSlider5.setValue(0);
	IndexSlider5.onValueChange = [this] {audioProcessor.setIndex5(IndexSlider5.getValue()); };
	IndexSlider5.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	IndexSlider5.setSliderStyle(juce::Slider::Rotary);

	addAndMakeVisible(IndexSlider6);
	IndexSlider6.setRange(0, 100.0);
	IndexSlider6.setValue(0);
	IndexSlider6.onValueChange = [this] {audioProcessor.setIndex6(IndexSlider6.getValue()); };
	IndexSlider6.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	IndexSlider6.setSliderStyle(juce::Slider::Rotary);

	addAndMakeVisible(globalAttackSlider);
	globalAttackSlider.setRange(0.01, 3.0);
	globalAttackSlider.setValue(0.01);
	globalAttackSlider.onValueChange = [this] {audioProcessor.setGlobAtt(globalAttackSlider.getValue()); };
	globalAttackSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	globalAttackSlider.setSliderStyle(juce::Slider::LinearVertical);

	addAndMakeVisible(globalAttackLabel);
	globalAttackLabel.setText("Global\nAttack", juce::dontSendNotification);

	addAndMakeVisible(globalReleaseSlider);
	globalReleaseSlider.setRange(0.01, 6.0);
	globalReleaseSlider.setValue(0.5);
	globalReleaseSlider.onValueChange = [this] {audioProcessor.setGlobRel(globalReleaseSlider.getValue()); };
	globalReleaseSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
	globalReleaseSlider.setSliderStyle(juce::Slider::LinearVertical);

	addAndMakeVisible(globalReleaseLabel);
	globalReleaseLabel.setText("Global\nRelease", juce::dontSendNotification);


	addAndMakeVisible(CutOffFreqSlider);
	CutOffFreqSlider.setRange(200, 10000.0);
	CutOffFreqSlider.setValue(1000.0);
	CutOffFreqSlider.setSliderStyle(juce::Slider::LinearBarVertical);
	CutOffFreqSlider.onValueChange = [this] {audioProcessor.setCutoffFreq(CutOffFreqSlider.getValue()); };

	addAndMakeVisible(cutoffFreqLabel);
	cutoffFreqLabel.setText("Cutoff Frequency", juce::dontSendNotification);

	addAndMakeVisible(QSlider);
	QSlider.setRange(0, 10.0);
	QSlider.setValue(0);
	QSlider.setSliderStyle(juce::Slider::LinearBarVertical);
	QSlider.onValueChange = [this] {audioProcessor.setQ(QSlider.getValue()); };

	addAndMakeVisible(QLabel);
	QLabel.setText("Q", juce::dontSendNotification);

	addAndMakeVisible(LfoFreqSlider);
	LfoFreqSlider.setRange(0, 30);
	LfoFreqSlider.setValue(0);
	LfoFreqSlider.setSliderStyle(juce::Slider::LinearBarVertical);
	LfoFreqSlider.onValueChange = [this] {audioProcessor.setLfoFreq(LfoFreqSlider.getValue()); };

	addAndMakeVisible(LfoFreqLabel);
	LfoFreqLabel.setText("Lfo Frequency", juce::dontSendNotification);

	addAndMakeVisible(LfoDepthSlider);
	LfoDepthSlider.setRange(0, 10.0);
	LfoDepthSlider.setValue(0);
	LfoDepthSlider.setSliderStyle(juce::Slider::LinearBarVertical);
	LfoDepthSlider.onValueChange = [this] {audioProcessor.setLfoDepth(LfoDepthSlider.getValue()); };

	addAndMakeVisible(LfoDepthLabel);
	LfoDepthLabel.setText("Lfo Depth", juce::dontSendNotification);

	addAndMakeVisible(DurationLeftSlider);
	DurationLeftSlider.setRange(0, 2000.0);
	DurationLeftSlider.setSliderStyle(juce::Slider::LinearBarVertical);
	DurationLeftSlider.onValueChange = [this] {audioProcessor.setDurL(DurationLeftSlider.getValue()); };

	addAndMakeVisible(DurationLeftLabel);
	DurationLeftLabel.setText("Left Channel Delay Duration", juce::dontSendNotification);

	addAndMakeVisible(DurationRightSlider);
	DurationRightSlider.setRange(0, 2000.0);
	DurationRightSlider.setSliderStyle(juce::Slider::LinearBarVertical);
	DurationRightSlider.onValueChange = [this] {audioProcessor.setDurR(DurationRightSlider.getValue()); };

	addAndMakeVisible(DurationRightLabel);
	DurationRightLabel.setText("Right Channel Delay Duration", juce::dontSendNotification);

	addAndMakeVisible(FeedbackLeftSlider);
	FeedbackLeftSlider.setRange(0, 1.0);
	FeedbackLeftSlider.setSliderStyle(juce::Slider::LinearBarVertical);
	FeedbackLeftSlider.onValueChange = [this] {audioProcessor.setFeedbackL(FeedbackLeftSlider.getValue()); };

	addAndMakeVisible(FeedbackLeftLabel);
	FeedbackLeftLabel.setText("Left Channel Feedback", juce::dontSendNotification);

	addAndMakeVisible(FeedbackRightSlider);
	FeedbackRightSlider.setRange(0, 1.0);
	FeedbackRightSlider.setSliderStyle(juce::Slider::LinearBarVertical);
	FeedbackRightSlider.onValueChange = [this] {audioProcessor.setFeedbackR(FeedbackRightSlider.getValue()); };

	addAndMakeVisible(FeedbackRightLabel);
	FeedbackRightLabel.setText("Right Channel Feedback", juce::dontSendNotification);

}


NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
	keyboardState.removeListener(this);
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint(juce::Graphics& g)
{
	// (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

	g.setColour(juce::Colours::brown);
	g.fillAll(juce::Colours::brown);

	g.setColour(juce::Colours::black);
	g.fillRoundedRectangle(20, 5, 600, 500, 5);

	g.setColour(juce::Colours::darkslategrey);
	g.fillRoundedRectangle(625, 5, 360, 450, 5);

	g.setColour(juce::Colours::black);
	g.fillRoundedRectangle(625, 463, 360, 110, 5);

	g.setColour(juce::Colours::whitesmoke);
	g.drawText(L"MODULATION ATTACKS", 25, 0, 200, 40, juce::Justification::left, true);

	g.setColour(juce::Colours::whitesmoke);
	g.drawText(L"MODULATION DECAYS", 25, 90, 200, 40, juce::Justification::left, true);

	g.setColour(juce::Colours::whitesmoke);
	g.drawText(L"MODULATION SUSTAINS", 25, 180, 200, 40, juce::Justification::left, true);

	g.setColour(juce::Colours::whitesmoke);
	g.drawText(L"MODULATION RELEASES", 25, 270, 200, 40, juce::Justification::left, true);

	g.setColour(juce::Colours::whitesmoke);
	g.drawText(L"MODULATION INDEXES", 25, 360, 200, 40, juce::Justification::left, true);

	g.setColour(juce::Colours::whitesmoke);
	g.drawText(L"STEREO ECHO", 635, 0, 200, 40, juce::Justification::left, true);

	g.setColour(juce::Colours::whitesmoke);
	g.drawText(L"RESONANT LOWPASS", 635, 225, 200, 40, juce::Justification::left, true);

	g.setColour(juce::Colours::whitesmoke);
	g.drawRoundedRectangle(20, 5, 600, 90, 5, 2);

	g.setColour(juce::Colours::whitesmoke);
	g.drawRoundedRectangle(20, 95, 600, 90, 5, 2);

	g.setColour(juce::Colours::whitesmoke);
	g.drawRoundedRectangle(20, 185, 600, 90, 5, 2);

	g.setColour(juce::Colours::whitesmoke);
	g.drawRoundedRectangle(20, 275, 600, 90, 5, 2);

	g.setColour(juce::Colours::whitesmoke);
	g.drawRoundedRectangle(20, 365, 600, 90, 5, 2);

	g.setColour(juce::Colours::whitesmoke);
	g.drawRoundedRectangle(625, 5, 360, 230, 5, 2);

	g.setColour(juce::Colours::whitesmoke);
	g.drawRoundedRectangle(625, 235, 360, 220, 5, 2);

	g.setColour(juce::Colours::whitesmoke);
	g.drawRoundedRectangle(688, 465, 45, 110, 5, 2);

	g.setColour(juce::Colours::whitesmoke);
	g.drawRoundedRectangle(798, 465, 43, 110, 5, 2);

	g.setColour(juce::Colours::whitesmoke);
	g.drawRoundedRectangle(908, 465, 43, 110, 5, 2);

	g.setColour(juce::Colours::whitesmoke);
	g.drawRoundedRectangle(625, 465, 360, 110, 5, 2);

}


void NewProjectAudioProcessorEditor::resized()
{

	juce::FlexBox Fx_box;
	Fx_box.flexDirection = juce::FlexBox::Direction::column;
	Fx_box.items = { juce::FlexItem().withHeight(10), juce::FlexItem(DurationLeftLabel).withHeight(15),juce::FlexItem(DurationLeftSlider).withHeight(30), juce::FlexItem().withHeight(5),juce::FlexItem(FeedbackLeftLabel).withHeight(15), juce::FlexItem(FeedbackLeftSlider).withHeight(30),
		juce::FlexItem().withHeight(5),juce::FlexItem(DurationRightLabel).withHeight(15),
	juce::FlexItem(DurationRightSlider).withHeight(30),juce::FlexItem().withHeight(5),juce::FlexItem(FeedbackRightLabel).withHeight(20), juce::FlexItem(FeedbackRightSlider).withHeight(30),juce::FlexItem().withHeight(30),juce::FlexItem(cutoffFreqLabel).withHeight(20),
		juce::FlexItem(CutOffFreqSlider).withFlex(1.f),
		juce::FlexItem().withHeight(5),juce::FlexItem(QLabel).withHeight(15),juce::FlexItem(QSlider).withFlex(1.f),juce::FlexItem().withHeight(5), juce::FlexItem(LfoFreqLabel).withHeight(15),
		juce::FlexItem(LfoFreqSlider).withFlex(1.f),juce::FlexItem().withHeight(5),juce::FlexItem(LfoDepthLabel).withHeight(15),
	juce::FlexItem(LfoDepthSlider).withFlex(1.f),juce::FlexItem().withHeight(10) };


	juce::FlexBox Attack_box;
	Attack_box.items = { juce::FlexItem(AttackSlider1).withFlex(1.f), juce::FlexItem(AttackSlider2).withFlex(1.f), juce::FlexItem(AttackSlider3).withFlex(1.f),
		juce::FlexItem(AttackSlider4).withFlex(1.f), juce::FlexItem(AttackSlider5).withFlex(1.f), juce::FlexItem(AttackSlider6).withFlex(1.f) };

	juce::FlexBox Decay_box;
	Decay_box.items = { juce::FlexItem(DecaySlider1).withFlex(1.f), juce::FlexItem(DecaySlider2).withFlex(1.f), juce::FlexItem(DecaySlider3).withFlex(1.f), juce::FlexItem(DecaySlider4).withFlex(1.f),
	juce::FlexItem(DecaySlider5).withFlex(1.f), juce::FlexItem(DecaySlider6).withFlex(1.f) };

	juce::FlexBox Sustain_box;
	Sustain_box.items = { juce::FlexItem(SustainSlider1).withFlex(1.f), juce::FlexItem(SustainSlider2).withFlex(1.f), juce::FlexItem(SustainSlider3).withFlex(1.f), juce::FlexItem(SustainSlider4).withFlex(1.f),
	juce::FlexItem(SustainSlider5).withFlex(1.f), juce::FlexItem(SustainSlider6).withFlex(1.f) };

	juce::FlexBox Release_box;
	Release_box.items = { juce::FlexItem(ReleaseSlider1).withFlex(1.f), juce::FlexItem(ReleaseSlider2).withFlex(1.f), juce::FlexItem(ReleaseSlider3).withFlex(1.f),
	juce::FlexItem(ReleaseSlider4).withFlex(1.f), juce::FlexItem(ReleaseSlider5).withFlex(1.f), juce::FlexItem(ReleaseSlider6).withFlex(1.f) };

	juce::FlexBox Index_box;
	Index_box.items = { juce::FlexItem(IndexSlider1).withFlex(1.f), juce::FlexItem(IndexSlider2).withFlex(1.f), juce::FlexItem(IndexSlider3).withFlex(1.f),
	juce::FlexItem(IndexSlider4).withFlex(1.f), juce::FlexItem(IndexSlider5).withFlex(1.f), juce::FlexItem(IndexSlider6).withFlex(1.f) };

	juce::FlexBox Fm_box;
	Fm_box.flexDirection = juce::FlexBox::Direction::column;
	Fm_box.items = { juce::FlexItem().withHeight(10), juce::FlexItem(Attack_box).withHeight(60),juce::FlexItem().withHeight(30), juce::FlexItem(Decay_box).withHeight(60), juce::FlexItem().withHeight(30),juce::FlexItem(Sustain_box).withHeight(60),
	   juce::FlexItem().withHeight(30), juce::FlexItem(Release_box).withHeight(60),juce::FlexItem().withHeight(30), juce::FlexItem(Index_box).withHeight(60) };

	juce::FlexBox FM_FX_box;
	FM_FX_box.items = { juce::FlexItem(Fm_box).withWidth(600), juce::FlexItem().withWidth(10),juce::FlexItem(Fx_box).withFlex(0.3f) };

	juce::FlexBox Maincontrol_box;
	Maincontrol_box.flexDirection = juce::FlexBox::Direction::row;
	Maincontrol_box.items = { juce::FlexItem(globalAttackLabel).withWidth(60), juce::FlexItem(globalAttackSlider).withWidth(50),
		juce::FlexItem(globalReleaseLabel).withWidth(60),juce::FlexItem(globalReleaseSlider).withWidth(50),juce::FlexItem(gainLabel).withWidth(60), juce::FlexItem(gainSlider).withWidth(50) };

	juce::FlexBox Midi_Maincontrol_box;
	Midi_Maincontrol_box.items = { juce::FlexItem(keyboardComponent).withWidth(600),juce::FlexItem().withWidth(5), juce::FlexItem(Maincontrol_box).withFlex(1.f) };

	juce::FlexBox box;
	box.flexDirection = juce::FlexBox::Direction::column;
	box.items = {
		juce::FlexItem(FM_FX_box).withFlex(1.f),
		juce::FlexItem(Midi_Maincontrol_box).withHeight(120)
	};
	box.performLayout(getLocalBounds().reduced(20));

}


void NewProjectAudioProcessorEditor::handleNoteOn(juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity)
{
	audioProcessor.keyOn(midiNoteNumber, int(127 * velocity));
}

void NewProjectAudioProcessorEditor::handleNoteOff(juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float /*velocity*/)
{
	audioProcessor.keyOff(midiNoteNumber);
}

void NewProjectAudioProcessorEditor::handleIncomingMidiMessage(juce::MidiInput* source, const juce::MidiMessage& message)
{
	source->start();
}
