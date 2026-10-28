Switch USB Inspector
Source Code Guide
=================

Welcome to the Switch USB Inspector source code!

This project is open source. You can study, modify, build, and test your
own version of the program.

--------------------------------------------------
1. REQUIREMENTS
--------------------------------------------------

To build the project, you will need:

- GCC
- Make
- pkg-config
- libusb 1.0 development files

On Debian or Ubuntu, install them with:

sudo apt update
sudo apt install build-essential pkg-config libusb-1.0-0-dev

--------------------------------------------------
2. PROJECT STRUCTURE
--------------------------------------------------

switch-usb-inspector/
|
|-- src/
|   `-- main.c
|
|-- include/
|   (Header files can be added here as the project grows.)
|
|-- build/
|   (Generated build files go here.)
|
|-- Makefile
|-- README.md
`-- .gitignore

--------------------------------------------------
3. BUILDING THE PROJECT
--------------------------------------------------

Open a terminal in the project directory and run:

make

The executable will be generated at:

build/switch-inspector

To run the program:

./build/switch-inspector

--------------------------------------------------
4. MODIFYING THE SOURCE CODE
--------------------------------------------------

The main program is located in:

src/main.c

You can modify this file, add features, fix bugs, or experiment with
your own implementations.

After making changes, rebuild the project:

make

To remove the generated build files and rebuild from scratch:

make clean
make

--------------------------------------------------
5. TESTING
--------------------------------------------------

Connect a USB device and run the program to inspect the USB devices
visible to Linux.

The program currently displays:

- Vendor ID (VID)
- Product ID (PID)
- USB version
- USB device class
- Number of configurations

Results depend on which USB devices are visible to the operating system.

--------------------------------------------------
6. USING WSL2
--------------------------------------------------

USB devices are not automatically exposed to WSL2.

You may need to configure USB/IP using usbipd-win on Windows before
the device becomes visible inside your Linux distribution.

On native Linux, the device can usually be inspected directly if the
system detects it and the required permissions are available.

--------------------------------------------------
7. IMPORTANT LIMITATIONS
--------------------------------------------------

This program reads USB device descriptors. It does not automatically
provide access to firmware, battery information, internal storage,
or other proprietary device information.

Not every device exposes a serial number, manufacturer name, or
product name through its USB descriptors.

--------------------------------------------------
8. CONTRIBUTE AND EXPERIMENT
--------------------------------------------------

Feel free to learn from the code, modify it, test your changes, and
create your own builds.

Keep in mind that modifications may introduce bugs or change the
program's behavior.

Check the project's LICENSE file for the applicable terms governing
modification and redistribution.

--------------------------------------------------
Switch USB Inspector - Source Code
Version: 0.1
--------------------------------------------------