# Externalizer

Externalizer is a VST3 audio plugin built using the [JUCE framework](https://juce.com/). This project aims to replicate Ableton Live's External Audio Effect device, enabling audio routing to/from external hardware processors from within digital audio workstations (DAWs) and other audio programs. Key features include latency compensation, dry/wet control, and gain staging. Development involves using Projucer, implementing features, designing a user interface, and testing across platforms and DAWs.

## Requirements

- [JUCE v6.x](https://juce.com/get-juce/download) or later
- [Visual Studio 2022](https://visualstudio.microsoft.com/vs/) (for Windows) or Xcode (for macOS)

## Building the Plugin

1. Open the Projucer application and load the `Externalizer.jucer` file.
2. Make sure that the appropriate plugin format (VST3) is selected.
3. Click "Save Project and Open in IDE" to open the project in your preferred IDE (Visual Studio 2022 or Xcode).
4. Build the project using the IDE's build command.

After building, the VST3 plugin will be available in the default output directory (`Builds/<your_OS>/build`).

## Usage

To use the Externalizer plugin, add the built VST3 file to the desired plugin folder. Consult your audio program's documentation for information on how to load and use VST3 plugins.

## Features

- Audio routing to/from external hardware processors within a DAW
- Latency compensation
- Dry/wet control
- Gain staging

## Development

- Use Projucer to manage the project and generate IDE project files
- Implement features in the `Source` folder
- Design UI in the `PluginEditor.cpp` and `PluginEditor.h` files
- Test the plugin in various DAWs on different platforms

## Context

This project uses <https://github.com/mpoon/gpt-repository-loader> to maintain up-to-date code context for use with ChatGPT and GPT4.

Example command:

```bash
python gpt_repository_loader.py "../Externalizer" -p "../Externalizer/.preamble" -o "../Externalizer/context.txt" -t 2048 -m 10
```

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).
