# BrailleTap
### A Wearable Braille-Inspired Keyboard

![BraileTap Prototype](IMG_8108.jpeg)

Here's the first working version of BrailleTap,
built during the 2026 Enable Innovation Hackathon.

BrailleTap is a wearable typing device I developed with a teammate for the **2026 Brooklyn Tech Enable Innovation Hackathon**. The idea was to create an affordable, portable alternative to traditional Braille keyboards, which can be expensive and inconvenient to carry around.

The glove uses five force-sensitive resistors (FSRs) connected to an ESP32 microcontroller. By pressing different combinations of fingers, users can input characters without needing a physical keyboard or touchscreen.

## Hardware

The prototype uses:
- **ESP32** – Reads and processes sensor inputs
- **5 Force-Sensitive Resistors (FSRs)** – Detect pressure from each finger
- **Glove** – Holds the sensors in place
- **Wrist-mounted electronics** – Keeps the controller out of the way while typing

Each finger corresponds to one bit in a five-bit binary input. Different combinations of pressed fingers produce different characters.

## How It Works

When a user presses their fingers against a surface, the FSRs register the pressure and send signals to the ESP32. The microcontroller determines which fingers are being pressed and converts that combination into a character using a predefined mapping.

For example:

| Character | Binary Input |
|---|---|
| H | `01001` |
| E | `10000` |
| L | `10010` |
| O | `11000` |

Because the current prototype only has five sensors, it uses a Braille-inspired chord system rather than the full six-dot Braille alphabet.

## Prototype

During the hackathon, we built a working prototype that demonstrated:

- Pressure detection from individual fingers
- Processing sensor inputs through the ESP32
- Mapping combinations of finger presses to characters

The prototype uses a wired arrangement of sensors connected to a wrist-mounted ESP32. Although it's still an early version, it demonstrates the basic concept of typing using finger combinations.

## Future Improvements

There are several things I'd like to improve in future versions:

- Add a sixth input to support standard six-dot Braille
- Implement Bluetooth keyboard functionality for typing directly into other devices
- Improve sensor accuracy and filter accidental inputs
- Make the wiring less exposed and reduce the size of the electronics
- Experiment with a version that doesn't require wearing a full glove

## Team

This project was developed for the Brooklyn Tech Enable Innovation Hackathon on May 1, 2026.

**William Ferguson Kunstler (Me)**
- Hardware development
- ESP32 programming and input logic
- System integration
- Product design

**Oscar Tutschulte**
- Product design
- Pitch deck and presentation
- Branding and user experience

## Project Presentation

The original hackathon pitch deck includes our design process, technical diagrams, prototype photos, and ideas for future development.

*BrailleTap is an early-stage prototype, not a finished assistive product.*
