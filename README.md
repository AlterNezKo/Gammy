# Gammy
is a tool for adjusting pixel brightness/temperature automatically or manually.

It can dim the screen if its content is too bright, or brighten it otherwise. This can help your eyes adjust when switching between dark and light windows, especially at night or in suboptimal lighting conditions.

Screenshot available on its [website](https://getgammy.com).
#### Planned features

- Proper multi-monitor support
- Command line interface / configurable hotkeys
- Location-based temperature adaptation
- Backlight control
## Installation

### Linux
#### Packages
- (Coming soon)

#### Building from source
Requirements:
- g++ or Clang compiler with C++17 support
- Ubuntu/Debian packages:
```sh
sudo apt install build-essential libgl1-mesa-dev libxxf86vm-dev libxext-dev qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools
```
To install:
```sh
git clone https://github.com/AlterNezKo/Gammy.git
cd Gammy
qmake
make
sudo make install
```
You can then find Gammy in your applications.
To run it from the shell, execute: `gammy`

To uninstall:
```sh
sudo make uninstall
```
On GNOME, the Qt5 Configuration Tool is recommended to improve UI integration:
```sh
sudo apt install qt5ct
```
## Usage

The app appears maximized the first time you start it. On subsequent starts, it's minimized in the system tray. This can be changed by setting `wnd_show_on_startup` to `true` in the config file (`~/.config/gammyconf` on Linux).

The window is shown or hidden by clicking on the tray icon. In some configurations you might need to double click. You can close it by pressing *Esc* when it's focused.

The first *Auto* checkbox activates automatic brightness. The following sliders will be revealed (scroll or expand the window to see all of them):
- **Range**: minimum and maximum brightness.
- **Offset**: higher = brighter image.
- **Threshold**: how much the screen has to change in order to trigger adaptation. The default value is generally good in most cases.
- **Adaptation speed**: how quickly the brightness adapts when a change is detected.
- **Screenshot rate**: the interval between each screenshot. Lowering this value detects brightness changes faster, but may increase CPU usage.

Automatic adjustments can be toggled on or off with a middle click on the tray icon.

The second *Auto* checkbox activates adaptive temperature. The ellipsis button (...) opens a window to control its time schedule, as well as the adaptation speed.

The padlock button allows the brightness range to go up to 200%. (Linux only)


## Known issues and limitations
The brightness is adjusted by changing pixel values, instead of the LCD backlight. This has wildly varying results based on the quality of your screen.

Theoretically, this app looks best on OLEDs, since they don't have a backlight. (If you have one, I'd love to know your experience).

Backlight control is planned. However, not all screens support backlight control via software.

### Multi-monitor issues
On Windows, currently the brightness is detected and adjustable only on the monitor that is set as the primary screen. Temperature affects all screens, however.

On Linux, currently every screen is treated as one single screen when calculating brightness. Both brightness and temperature are changed globally.

## Troubleshooting
### Linux
When building from source, if `make` fails with ```PlaceholderText is not a member of QPalette``` errors in ui_mainwindow.h, the Qt version provided by your distro is older than 5.12. As a workaround you can delete the offending lines in ui_mainwindow.h, then run `make` again.

If you are using a command to run it on startup, and the tray icon does not appear, try [this.](https://github.com/Fushko/gammy/issues/57#issuecomment-751358770)

If you are experiencing an "Invalid gamma ramp size" fatal error, refer to [this post.](https://github.com/Fushko/gammy/issues/20#issuecomment-584473270)

## Third party
- Qt 5 ([LGPL](https://doc.qt.io/qt-5/lgpl.html))
- Plog ([MPL](https://github.com/SergiusTheBest/plog/blob/master/LICENSE))
- JSON for Modern C++ ([MIT](https://github.com/nlohmann/json/blob/develop/LICENSE.MIT))
- Qt-RangeSlider ([MIT](https://github.com/ThisIsClark/Qt-RangeSlider/blob/master/LICENSE))

## License
Copyright (C) Francesco Fusco.

[GPLv3](https://github.com/Fushko/gammy/blob/master/LICENSE)

