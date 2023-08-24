# Redragon K530 Devarajas

K530


Config files for K530 for [SonixQMK](https://github.com/SonixQMK/qmk_firmware) for development branch.
To install, follow instructions on [https://sonixqmk.github.io//SonixDocs/install/](https://sonixqmk.github.io//SonixDocs/install/)
to point 2.1.

Next, use those instructions.

```
qmk setup SonixQMK/qmk_firmware -b sn32_develop
cd ~/qmk_firmware/keyboards/redragon

git clone https://github.com/Steryy/k530

qmk compile -kb redragon/k530 -km via
```
And continue instructions [https://sonixqmk.github.io//SonixDocs/install/](https://sonixqmk.github.io//SonixDocs/install/#4-flashing-the-firmware)
from point 4.0.


![](./assets/preview.jpg)

Config was based on files for [K530 on master branch](https://github.com/SonixQMK/qmk_firmware/tree/sn32_master/keyboards/redragon/k530)
and [k630 on develepment branch](https://github.com/SonixQMK/qmk_firmware/tree/sn32_develop/keyboards/redragon/k630)

