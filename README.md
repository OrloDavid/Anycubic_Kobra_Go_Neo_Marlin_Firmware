# AnyCubic Kobra Go / Neo TriGorilla Gen_V.3.0.7
## David M. Orlo | 'Kobra Go Neo Marlin' Build

Welcome to the new beginning of the AnyCubic Kobra Go / Neo TriGorilla project. This repository marks a fresh start, deviating from the previous fork. After extensive work and consideration, it became evident that starting anew from scratch would be the most effective approach.

### Background and Approach

The journey began with the original source code provided by Anycubic. To ensure thoroughness and accuracy, various versions of the Marlin firmware were compared and analyzed. This was crucial in identifying and rectifying broken and missing elements. The versions referenced include:

- Marlin-2.0.1.1
- Marlin-2.0.2.1
- Marlin-2.0.3.1
- Marlin-2.0.4.5
- Marlin-2.0.5.5
- Marlin-2.0.6.2
- Marlin-2.0.7.3
- Marlin-2.0.8.1
- Marlin-2.0.8.3
- Marlin-2.0.9.4
- Marlin-2.0.9.7
- Marlin-bugfix-2.0.x
- Marlin-Its-2.0.8
- Marlin-Its-2.0.9

It was observed that the bulk of the code aligns with versions ranging from Marlin-2.0.7.3 to 2.0.8.3. Interestingly, most of the LCD code seems to be derived from Marlin-bugfix-2.0.x.

### Challenges and Learnings

This project was far from straightforward. The nature of Marlin firmware, coupled with the evolution of its versions, posed significant challenges. These were further compounded by the unique SPI implementation of the LCD screen and the integration of code from Bugfix 2x, which often did not align with the main codebase.

As a non-programmer delving deep into this for the first time, the learning curve was steep. This journey involved not just coding, but familiarizing myself with various tools and aspects of Marlin firmware.

### Contributions and Tools

During this endeavor, I developed custom scripts and created User Defined Language (UDL) files for Notepad++, which I found immensely helpful in quickly identifying issues and locating specific areas or keywords in the code. These tools, along with detailed documentation, will be shared to assist others working on similar projects.

Additionally, I have streamlined the codebase by removing irrelevant files and folders, simplifying troubleshooting and maintenance without compromising compatibility with the NEO model. This process included removing unnecessary components such as Delta, Lasers, Disco Balls, and 52" Plasma configurations.

### X-Symmetry Project

The X-Symmetry folder and project will be updated soon. Having completed the Rev.1, and with parts for Rev.2 on their way, this modification is highly recommended for any cartesian style 3D printer, not just the Kobra Go. The potential impact of this modification on the cartesian printer landscape is significant.

### Transition to Klipper

The next phase involves transitioning my printer to Klipper firmware. This move is planned after completing the current project and the X-Symmetry Rev.1 build. The goal is to create an easy path for others to transition to Klipper, potentially utilizing the factory LCD and exploring alternatives to Raspberry Pi for a similar cost.

Stay tuned for more updates and feel free to contribute or reach out with questions and suggestions.
