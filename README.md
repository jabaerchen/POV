# POV

## Build

### Docs

https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/index.html#

### Building the project

```shell
# set python 2 in pythonpath
export PYTHONPATH=/usr/lib/python2.7/
# source the toolchain
. ~/esp/ESP8266_RTOS_SDK/export.sh
# build
make
```

### Flash the project

```shell
# set python 2 in pythonpath
export PYTHONPATH=/usr/lib/python2.7/
# source the toolchain
. ~/esp/ESP8266_RTOS_SDK/export.sh
# build
sudo -E make flash
```

### Flash the project

```shell
# set python 2 in pythonpath
export PYTHONPATH=/usr/lib/python2.7/
# source the toolchain
. ~/esp/ESP8266_RTOS_SDK/export.sh
# build
sudo -E make monitor
```



## Hardware

Hall sensor: https://www.infineon.com/dgdl/Infineon-TLE49X5L-DataSheet-v01_05-en.pdf?fileId=db3a304316f66ee80117549ac8b206b1

### Programming interface

```shell
-----------------------------------
| GND | RTS | 3V3 | TX | RX | DTR |
-----------------------------------
```

## Lesson learned

- add labels to the PCB
- add measuring points

