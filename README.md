# Switch USB Inspector

A lightweight USB diagnostic tool written in C for Linux, designed to inspect USB devices and investigate the information exposed by the Nintendo Switch.

> **Project status:** Early development. Hardware identification and USB inspection are the initial goals. Access to internal component information depends on the interfaces and protocols exposed by the device.

## Features

- [ ] USB device enumeration using `libusb-1.0`
- [ ] Display USB vendor and product IDs (VID/PID)
- [ ] Inspect USB configurations, interfaces, and endpoints
- [ ] Nintendo Switch device identification
- [ ] Device connection and disconnection monitoring
- [ ] Diagnostic report export
- [ ] Component information investigation, where supported
- [ ] Windows support
- [ ] Optional graphical user interface

## Compatibility

| Platform | Status |
| --- | --- |
| Debian Linux x86_64 | Initial development target |
| Ubuntu Linux | Planned testing |
| Linux Mint | Planned testing |
| Arch Linux | Planned testing |
| Fedora Linux | Planned testing |
| Windows x86_64 | Planned |

Other Linux distributions may work if the required compiler, development libraries, and runtime dependencies are available.

## Requirements

For Debian, Ubuntu, and Linux Mint:

```bash
sudo apt update
sudo apt install build-essential pkg-config libusb-1.0-0-dev
```

For Arch Linux:

```bash
sudo pacman -S --needed base-devel pkgconf libusb
```

For Fedora:

```bash
sudo dnf install gcc make pkgconf-pkg-config libusb1-devel
```

## Build from source

Clone the repository:

```bash
git clone https://github.com/YOUR_USERNAME/switch-usb-inspector.git
cd switch-usb-inspector
```

Compile the program:

```bash
gcc -std=c11 -Wall -Wextra src/main.c -o switch-inspector \
    $(pkg-config --cflags --libs libusb-1.0)
```

Run it:

```bash
./switch-inspector
```

The command assumes that `src/main.c` is present and that the required development packages are installed.

## Download a release

Precompiled binaries will be published on the GitHub Releases page.

Linux release packages are intended to provide a convenient way to run the program without compiling the source code manually.

1. Open the [Releases page](https://github.com/YOUR_USERNAME/switch-usb-inspector/releases).
2. Download the package matching your operating system and architecture.
3. Extract the archive.
4. Run the executable according to the instructions included with the release.

**Note:** Release packages have not necessarily been published yet.

## Hardware information

The program initially inspects USB descriptors, including:

- Vendor and product IDs.
- USB version reported by the device.
- Device class and configuration count.
- Interface classes and endpoint information.

USB descriptors do not automatically provide battery health, component firmware versions, or internal hardware revisions. Such information will only be implemented when a supported protocol or accessible interface is identified.

Use a USB-C cable that supports data transfer when connecting a Nintendo Switch.

## Permissions and troubleshooting

On Linux, access to USB devices may be restricted by system permissions or udev rules.

If the device cannot be accessed, check the system's USB device listing and permissions before attempting further diagnostics. Avoid running the program as root unless necessary for a specific, understood diagnostic step.

## Contributing

Contributions, bug reports, documentation improvements, and compatibility tests are welcome.

Before submitting a contribution, please describe the hardware, operating system, and steps used to reproduce the issue.

## Disclaimer

Switch USB Inspector is an independent experimental project and is not affiliated with or endorsed by Nintendo.

The project does not guarantee access to internal component data. Results depend on the device, firmware, USB interfaces, and supported protocols.

## License

This project is licensed under the GNU General Public License v2.0. See the `LICENSE` file for details.
