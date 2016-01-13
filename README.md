# MeleeAI

## Installation

MeleeAI is currently only available on Linux platforms.

First, download:

```bash
$ git clone https://github.com/luckycharms14/MeleeAI.git
```

Next, locate your dolphin home folder.
This folder is most likely named ```dolphin-emu``` or ```.dolphin-emu```.
Possible locations of this folder include your ```$HOME``` directory or ```$HOME/.local/share/```.

Inside the dolphin home folder you must create a FIFO pipe named ```pipe```, a ```Locations.txt``` that contains a list of line-separated memory addresses that MemoryWatcher will watch, and the folders that contain them, respectively.
This is done with the following commands:

```bash
$ cd dolphin-emu
$ mkdir Pipes
$ mkfifo Pipes/pipe
$ mkdir MemoryWatcher
$ touch MemoryWatcher/Locations.txt
```

An example of addresses that can be used to populate ```Locations.txt``` is given at the top of ```MeleeAI/MeleeNotes.txt```.

Next you must tweak and build the source code.
Navigate to the source directory at ```MeleeAI/AI/source```
There are two string (path) variables that need to be changed to match the specifics of your system.
One is in ```MemReader.cpp```: modify

```C++
#define PATH "/home/tom/.dolphin-emu/MemoryWatcher/MemoryWatcher"
```

with respect to the path of your ```MemoryWatcher/``` directory.
```MemoryWatcher/Memorywatcher``` is a socket that is used to watch the addresses listed in ```Locations.txt```.
Next, in ```PipeController.cpp```, modify

```C++
std::string PipeController::pipePath = "/home/tom/.dolphin-emu/Pipes/pipe";
```

with respect to the path of your ```Pipes/pipe``` file.

Navigate to the parent directory of the source folder, ```MeleeAI/AI```, and make and run MeleeAI with

```bash
$ mkdir build
$ make
$ ./MeleeAI
```