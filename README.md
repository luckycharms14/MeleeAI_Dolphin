# MeleeAI

## Installation

This series of steps will guide you in installing MeleeAI from the terminal.
MeleeAI is currently functional on Linux and OS X platforms.

To begin, download a copy of the MeleeAI repository:

```bash
$ git clone https://github.com/luckycharms14/MeleeAI.git
```

### Setup the Dolphin home folder

Locate your Dolphin home folder.
This folder is most likely named `dolphin-emu` or `.dolphin-emu`.
Possible locations of this folder on Linux include the `$HOME` directory or `$HOME/.local/share/`, and a possible location on OS X is `/Users/username/Library/Application Support/Dolphin`.

Inside the dolphin home folder you must create a FIFO pipe named `pipe`, a `Locations.txt` that contains a list of line-separated memory addresses that MemoryWatcher will watch, and the folders that contain them, respectively.
An example `Locations.txt` that MeleeAI is designed to function with is available in the MeleeAI repository.
This setup can be completed with the following commands:

```bash
$ cd /path/to/dolphin-emu
$ mkdir Pipes
$ mkfifo Pipes/pipe
$ mkdir MemoryWatcher
$ cp /path/to/MeleeAI/Locations.txt MemoryWatcher/
```

### Configure Dolphin

Next, you must provide Dolphin with a GameCube controller profile that can be used to associate MeleeAI outputs with Port 2 inputs (via `Pipes/pipe`).
An example of a profile suitable for use with MeleeAI, `pipe.ini`, is given in the MeleeAI repository.
First, locate your Dolphin config folder.
This folder is mostly likely `/path/to/dolphin-emu/Config` or, if you're on Linux, `$HOME/.config/dolphin-emu`.
Then create the appropriate parent folders and copy `pipe.ini` like so:

```bash
$ cd /path/to/dolphin-emu/config
$ mkdir -p Profiles/GCPad
$ cp /path/to/MeleeAI/pipe.ini Profiles/GCPad/
```

Open Dolphin (restart Dolphin if it is already open) and do the following to prepare Dolphin for MeleeAI outputs:
1. Click on the 'Controllers' menu icon in the top right.
2. Under 'GameCube Controllers', click the drop-down menu next to 'Port 2' and select 'Standard Controller'.
Then click 'Configure' to the right.
3. In the top left corner click the 'Device' drop-down menu.
There should be an option to select 'Pipe/0/pipe' (possibly named 'Pipe/1/pipe').
If there is no such device, go back to [Setup the Dolphin home folder](#Setup-the-Dolphin-home-folder) and make sure that you have created the `pipe` file in the correct location.
4. Having selected the device, click the 'Profile' drop-down menu to the right.
There should be an option to select 'pipe' -- if not, return to the steps above and ensure that `pipe.ini` has been copied to the correct location.
Select 'pipe' and click 'Load' to the right.
5. In the bottom right, under 'Options', click the box next to 'Background Input'.
Then click 'OK' to exit the configure menu and 'OK' again to exit the controllers menu.

### Build and Run MeleeAI

Finally, you must tweak and build the MeleeAI source code.
Navigate to the source directory at `MeleeAI/AI/source`.
There is a string (path) variable that needs to be changed to match the specifics of your system.
In `Global.hpp`, modify the `DOLPHIN_PATH` variable to match the path of your dolphin home folder:

```C++
const std::string DOLPHIN_PATH = "/path/to/dolphin-emu";
```
(Note: If your path contains a space, [as with the OS X example above](#Setup-the-Dolphin-home-folder), you will need to escape it with `\\`, e.g., 
```C++
const std::string DOLPHIN_PATH = /Users/username/Library/Application\\ Support/Dolphin";
```
)

Navigate to the parent directory of the source folder, `MeleeAI/AI`, and make and run MeleeAI with

```bash
$ mkdir build
$ make
```

Inside Dolphin, load up melee.
When on the character select screen, run MeleeAI:

```bash
$ ./MeleeAI
```

Choose your character, select Fox for Player 2 and select a stage.
If MeleeAI is working, when Fox is knocked off the stage, he will attempt to recover intelligently.
