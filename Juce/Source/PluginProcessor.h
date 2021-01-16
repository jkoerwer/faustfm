/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include <JuceHeader.h>
#include "DspFaust.h"

//==============================================================================
/**
*/
class NewProjectAudioProcessor  : public juce::AudioProcessor 
{
public:
    //==============================================================================
    NewProjectAudioProcessor();
    ~NewProjectAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void setFreq(float freq);
    void setGain(float volume);
    void setTempo(float tempo);
    void setGate(bool gate);
    void setGlobAtt(float Global_Attack);
    void setGlobRel(float Global_Release);
    
    void setIndex1(float index1);
    void setIndex2(float index2);
    void setIndex3(float index3);
    void setIndex4(float index4);
    void setIndex5(float index5);
    void setIndex6(float index6);

    void setA1(float Attack1);
    void setA2(float Attack2);
    void setA3(float Attack3);
    void setA4(float Attack4);
    void setA5(float Attack5);
    void setA6(float Attack6);

    void setD1(float Decay1);
    void setD2(float Decay2);
    void setD3(float Decay3);
    void setD4(float Decay4);
    void setD5(float Decay5);
    void setD6(float Decay6);

    void setS1(float Sustain1);
    void setS2(float  Sustain2);
    void setS3(float  Sustain3);
    void setS4(float  Sustain4);
    void setS5(float  Sustain5);
    void setS6(float  Sustain6);

    void setR1(float Release1);
    void setR2(float Release2);
    void setR3(float Release3);
    void setR4(float Release4);
    void setR5(float Release5);
    void setR6(float Release6);

    void setCutoffFreq(float CutOff_Freq);
    void setQ(float Q);
    void setLfoFreq(float LFO_Freq);
    void setLfoDepth(float LFO_Depth);
 

    void setDurL(float duration_l);
    void setFeedbackL(float feedback_l);


    void setDurR(float duration_r);
    void setFeedbackR(float feedback_r);

   

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    void keyOn(int pitch, int velocity);
    void keyOff(int pitch);

private:
    DspFaust dspFaust;



    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NewProjectAudioProcessor)
};
