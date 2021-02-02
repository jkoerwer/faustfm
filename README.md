# faustfm
A FM synthesizer with 6 oscillators and fixed modulation ratios built in [FAUST](https://faust.grame.fr/ "FAUST") for AKT Sound Synthesis 2020.
Sound Examples can be found under: https://soundcloud.com/user-766578637

### Installation ###
#### JUCE ####
For building and being able to use the Synthesizer you need the projucer and the Juce modules, which are available at https://github.com/juce-framework/JUCE
Start the projucer and load the .jucer file, which is located inside Juce folder.
Select an IDE of your choice and create the project, make sure to include the right path to your juce/modules and that you select an executable DAW to run the VST.
In your IDE just select the standalone or the VST and press build and compile.
Enjoy the sound.
PS: External midi input is not working, when using the standalone. 

#### VST ####
Alternatively a 64-bit VST version is available via the FaustFM.dll. Simply download the file and add it to the vst folder of your DAW.

#### FAUST IDE ####
Finally, you can upload the Faust_code.txt to the FAUST ide at: https://faustide.grame.fr/ and play it from your browser or build it from there.


