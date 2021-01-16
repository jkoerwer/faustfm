/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessor::NewProjectAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    
    dspFaust.start();
}

NewProjectAudioProcessor::~NewProjectAudioProcessor()
{
    dspFaust.stop();
   
}

//==============================================================================
const juce::String NewProjectAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool NewProjectAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}


bool NewProjectAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool NewProjectAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double NewProjectAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int NewProjectAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int NewProjectAudioProcessor::getCurrentProgram()
{
    return 0;
}

void NewProjectAudioProcessor::setCurrentProgram(int index)
{
}


const juce::String NewProjectAudioProcessor::getProgramName (int index)
{
    return {};
}

void NewProjectAudioProcessor::changeProgramName(int index, const juce::String& newName)
{
}



//==============================================================================
void NewProjectAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    juce::ignoreUnused(samplesPerBlock);  
    
}

void NewProjectAudioProcessor::releaseResources()
{
}


#ifndef JucePlugin_PreferredChannelConfigurations
bool NewProjectAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void NewProjectAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    jassert(!isUsingDoublePrecision());

}

//==============================================================================
bool NewProjectAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* NewProjectAudioProcessor::createEditor()
{
    return new NewProjectAudioProcessorEditor (*this);
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new NewProjectAudioProcessor();
}

void NewProjectAudioProcessor::setFreq(float freq)
{
    dspFaust.setParamValue("/FM_Synthesizer/freq", freq);
}
void NewProjectAudioProcessor::setGain(float volume)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/volume",volume);
}
void NewProjectAudioProcessor::setTempo(float tempo)
{
    dspFaust.setParamValue("/synth/tempo", tempo);
}
void NewProjectAudioProcessor::setGate(bool gate)
{
    if(gate){ dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/gate", 1); }
    else { dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/gate", 0); }   
}
void NewProjectAudioProcessor::setGlobAtt(float Global_Attack)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Global_Attack", Global_Attack);
}
void NewProjectAudioProcessor::setGlobRel(float Global_Release)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Global_Release", Global_Release);
}
void NewProjectAudioProcessor::setIndex1(float index1)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Index_Mods/index1", index1);
}
void NewProjectAudioProcessor::setIndex2(float index2)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Index_Mods/index2", index2);
}
void NewProjectAudioProcessor::setIndex3(float index3)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Index_Mods/index3", index3);
}
void NewProjectAudioProcessor::setIndex4(float index4)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Index_Mods/index4", index4);
}
void NewProjectAudioProcessor::setIndex5(float index5)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Index_Mods/index5", index5);
}
void NewProjectAudioProcessor::setIndex6(float index6)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Index_Mods/index6", index6);
}
void NewProjectAudioProcessor::setA1(float Attack1)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Attacks/Attack1", Attack1);
}
void NewProjectAudioProcessor::setA2(float Attack2)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Attacks/Attack2", Attack2);
}
void NewProjectAudioProcessor::setA3(float Attack3)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Attacks/Attack3", Attack3);
}
void NewProjectAudioProcessor::setA4(float Attack4)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Attacks/Attack4", Attack4);
}
void NewProjectAudioProcessor::setA5(float Attack5)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Attacks/Attack5", Attack5);
}
void NewProjectAudioProcessor::setA6(float Attack6)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Attacks/Attack6", Attack6);
}
void NewProjectAudioProcessor::setD1(float d1)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Decays/Decay1", d1);
}
void NewProjectAudioProcessor::setD2(float d2)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Decays/Decay2", d2);
}
void NewProjectAudioProcessor::setD3(float d3)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Decays/Decay3", d3);
}
void NewProjectAudioProcessor::setD4(float d4)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Decays/Decay4", d4);
}
void NewProjectAudioProcessor::setD5(float d5)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Decays/Decay5", d5);
}
void NewProjectAudioProcessor::setD6(float d6)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Decays/Decay6", d6);
}

void NewProjectAudioProcessor::setS1(float Sustain1)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Sustains/Sustain1", Sustain1);
}
void NewProjectAudioProcessor::setS2(float Sustain2)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Sustains/Sustain2", Sustain2);
}
void NewProjectAudioProcessor::setS3(float Sustain3)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Sustains/Sustain3", Sustain3);
}
void NewProjectAudioProcessor::setS4(float Sustain4)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Sustains/Sustain4", Sustain4);
}
void NewProjectAudioProcessor::setS5(float Sustain5)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Sustains/Sustain5", Sustain5);
}
void NewProjectAudioProcessor::setS6(float Sustain6)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Sustains/Sustain6", Sustain6);
}

void NewProjectAudioProcessor::setR1(float r1)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Releases/Release1", r1);
}
void NewProjectAudioProcessor::setR2(float r2)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Releases/Release2", r2);
}
void NewProjectAudioProcessor::setR3(float r3)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Releases/Release3", r3);
}
void NewProjectAudioProcessor::setR4(float r4)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Releases/Release4", r4);
}
void NewProjectAudioProcessor::setR5(float r5)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Releases/Release5", r5);
}
void NewProjectAudioProcessor::setR6(float r6)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Mod_Releases/Release6", r6);
}
void NewProjectAudioProcessor::setCutoffFreq(float ctFreq)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/ResLoFilter_del/CutOff_Freq", ctFreq);
}
void NewProjectAudioProcessor::setQ(float q)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/ResLoFilter_del/Q", q);
}



void NewProjectAudioProcessor::setLfoFreq(float lfoFreq)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/ResLoFilter_del/LFO_Freq", lfoFreq);
}
void NewProjectAudioProcessor::setLfoDepth(float lfoDepth)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/ResLoFilter_del/LFO_Depth", lfoDepth);
}
void NewProjectAudioProcessor::setDurL(float duration_l)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Echo_left/Duration", duration_l);
}
void NewProjectAudioProcessor::setFeedbackL(float feedback_l)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Echo_left/FeedBack", feedback_l);
}

void NewProjectAudioProcessor::setDurR(float duration_r)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Echo_right/Duration", duration_r);
}
void NewProjectAudioProcessor::setFeedbackR(float feedback_r)
{
    dspFaust.setParamValue("/Polyphonic/Voices/FM_Synthesizer/Echo_right/FeedBack", feedback_r);
}

void NewProjectAudioProcessor::getStateInformation(juce::MemoryBlock& destData)
{
}

void NewProjectAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
}

void NewProjectAudioProcessor::keyOn(int pitch, int velocity)
{  
    dspFaust.keyOn(pitch, velocity);   

}
void NewProjectAudioProcessor::keyOff(int pitch)
{
    dspFaust.keyOff(pitch); 
}

