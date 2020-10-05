What is 3GPPDecoder?
=====================

![3GPPDecoder Linux Build](/3gpp-decoder-linux.png?raw=true "3GPPDecoder Linux Build")

3GPPDecoder is a free open source decoder to decode wireless messages and PDUs(Protocol Data Units). The program currently supports Windows and Linux.

You can use 3GPPDecoder Linux to decode 3GPP LTE, UMTS and GSM messages for RRC and NAS. It also supports RLC (Radio Link Control) protocol PDU header decoding.

[3GPP Decoder Home Page](http://www.3glteinfo.com/3gpp-decoder/)

## How to get pre-compiled x86 binary

You can download the 3GPPDecoder Linux installer from this repo:

[https://raw.githubusercontent.com/sickcodes/3gpp-decoder-linux/master/3GPPDecoder](https://raw.githubusercontent.com/sickcodes/3gpp-decoder-linux/master/3GPPDecoder)


## How to use 3GPP Decoder on Linux

Use the following commends to install wireshark, text2pcap and tshark on Ubuntu.

## Ubuntu/Debian
```bash
sudo apt update -y
sudo apt install wireshark tshark qtcreator -y
git clone https://github.com/panigrahip/3gpp-decoder-linux.git

cd 3gpp-decoder-linux
```
## Arch/Manjaro
```bash
sudo pacman -Syu wireshark-qt qtcreator
git clone https://github.com/panigrahip/3gpp-decoder-linux.git

cd 3gpp-decoder-linux
```

# Build & Run

```bash
qtcreator ./3gpp-decoder.pro
```
In the QTCreator, press

`Ctrl` + `R`

Or select `Build` -> `Run` from the menu bar.


## How to build 3GPPDecoder

To develop 3GPPDecoder you need `qtcreator`.

To build the decoder program, open the `3gpp-decoder.pro` in `qtcreator`.
