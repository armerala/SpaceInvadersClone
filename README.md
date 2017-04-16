# SpaceInvadersClone
Source code for a small, handheld space invaders clone for the AOE common project using the RA882 drive and arduino standard libraries

##Build Instructions

\t For this build to work, it is best (and required, at that) to use the Arduino IDE, as it will handle much of the legwork of managing working directories and such, especially in a cross-platform environment where some developers are using OSX and others Windows. In the interest of time, we will rely on Arduino's built-in library management to handle dependencies, and hard-coded relative paths to `#include` our own source files. In the future, a proper Makefile may be the way to go, but for now this is a good-enough solution.

\t The only important step here is to make sure the appropriate libraries are installed. Because of Arduino's library management system, libraries must be installed in the proper system-specified `libraries` directory, which Arduino's IDE should have created on install. If not, don't worry, the next step will create this directory for us.

\t To install the libraries, open up your Arduino IDE. Then go to the top left and go to `Sketch->Include Library->Manage Libraries...`, which should open up a new window. Then, search for the following two libraries, using the search bar at the top right of the window, and install them using the `Install` button.

`Adafruit GFX Library` (version 1.1.9 or greater)
`Adafruit RA8875` (version 1.0.2 or greater)

Now open up the `SpaceInvaders.ino` in the `<YourProjectDirectory>/SpaceInvadersClone/SpaceInvaders` directory. Hit the big check mark in the top left to compile the code, and all should be well.

##Reporting Issues

If you find any issues, be it in compilation or software bugs, please submit them under the Github issues. This will keep issues centralized and we can make sure they're addressed properly, rather than them falling through the cracks.

##API Reference

Github link for the [RA8875 Driver library](https://github.com/adafruit/Adafruit_RA8875)

See the `docs` folder for relevant datasheets, board pinouts, etc.
