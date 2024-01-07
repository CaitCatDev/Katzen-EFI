# KUEFI(Katzen UEFI):
KUEFI is both a set of header files that can be used to develop UEFI applications and a optional library.

To develop a UEFI application you only really need the header files that define the UEFI data structures that UEFI intends for you to use for things such as memory allocations, reading from devices, printing to screen, etc...

However this repo also contains a library by the same name of KUEFI that is purely optional and just comes with some basic utility features such as printing to printf like functions, etc...

## How to install?
If you just want headers it's as simple as running `make install` of course sudo/doas may be needed depending on the directory you are choosing to install to. For the library and the headers `make library`, Followed by `make install-library` as the library itself needs the headers they will just be installed along side the library.

## How to use it?
TODO:

### Why is the library optional?
The library is just utility features my bootloader uses. Your bootloader/UEFI app may not need any of these features or you might want to implement them in different ways. Basically it's optional as all you need are the UEFI headers and while the utility of having helper functions are nice they are by no means needed.
