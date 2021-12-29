# README

## Pre-requisites

This app relies on the [GameBoy Development Project 2020](https://github.com/gbdk-2020/gbdk-2020). It assumes that all gbdk binaries are available in your path.

In my case I installed the gdbk binaries for Linux in `/opt/gbdk` and exported my path by adding the following to my .zshrc* file as:

```
# Gameboy Development Kit
export PATH=/opt/gbdk/bin:$PATH
```

Note that this will work on any Unix shell profile. e.g. `/.zshrc`

## Compilation

Run `make`. This will create binaries in the `bin` folder.

To remove all compilation artifacts run `make clean`

## Run Locally

A copy of [Emulicious] is included for convenience. To compile and run the game in the emulator, simply execute `make run`.

## Licence

Licence: Please note that whilst Emulicious is incloded in this repository, that it is not my emulator and is included simply for convenience.

This source code is made available under the MIT Licence. Please see [LICENCE.txt](LICENCE.txt) for more details.

### NOTE: THIS PROJECT IS STILL UNDER INITIAL DEVELOPMENT AND NOT YET COMPLETE.

All development has occurred on Ubuntu Linux 20.04 and has not been tested on any other system. Compiled using gbdk 4.0.5