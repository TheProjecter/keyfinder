#Quick HowTo
# Introduction #

This is a simple HowTo for compiling and using KeyFinder.
Note that this program is just been made for WoW SteelSeries 1st edition mouse, at the moment is untested on everything else, and probably it will not work on anything alse before I'll try to make it more flexible.


# Details #

## Requirements: ##

X11 development libraries
Qt4 development libraries

## Compiling: ##

Download sources and uncopress them.

Open a terminal.

```
cd KeyFinderSourceFolderName

qmake
```

## Running: ##

#### Unity: ####
```
gksudo ./KeyFinder
```

#### Gnome: ####
```
gnome-sudo ./KeyFinder
```

#### KDE: ####
```
kdesu ./KeyFinder
```

Note: you may wish to use a convenient path like ~/Key/Finder/Location/KeyFinder

## Shutdown: ##
```
sudo pkill KeyFinder
```

Actually all the buttons are mapped to keypad numbers 0~9; I'm working on a gui to allow key costomization (and eventually macros)