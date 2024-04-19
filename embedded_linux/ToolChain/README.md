# Overview
This is our first step in our journey to build our own linux image from scratch which is customizing and building our cross toolchain to be used to build all other components and to generate the essential static and dynamic libraries for our image. Static and dynamic libraries will be discussed in [Libraries](./Libraries/).
# Crosstool-NG
Crosstool-NG is an open source versatile (cross) toolchain generator which we will use to generate a toolchain for our embedded target. the first step to use Crosstool-NG is to clone its source code from its github repo.
## Cloning Crosstool-NG repo
As Crosstool-Ng is open source we can find its source codes in its github repo, and it is the time to clone it using the following command.
```bash
git clone https://github.com/crosstool-ng/crosstool-ng.git
```
It is very **IMPORTANT** to check out to the following stable commit **25f6dae8** using the following command.
```bash
git checkout 25f6dae8
```
Once we cloned its repo, we have to check its dependencies and install them.
## Installing dependencies
We can install all dependencies in only one step using `apt` utility using this command.
```bash
sudo apt install bison  build-essential flex gawk gettext g++ help2man libncurses-dev libtool-bin texinfo unzip
```
## Installing Crosstool-NG
According to Crosstool-NG documentation we will follow these commands sequence to install it.
```bash
cd crosstool-ng #opening the crosstool-NG directory
./bootstrap
./configure --enable-local
make #to generate the Makefile 
```
To enable the auto completion we need to put this line in the end of our `${HOME}/.bashrc` script.
```bash
source <path to crosstool-NG directory>/crosstoll-ng/bash-completion/ct-ng #replace it with the actual path 
```
## Configuring our Cross-toolchain
Crosstool-NG is supporting many architectures and has a default configurations for many micro controllers, we can list all supported micro controllers using the following command:
```bash 
./ct-ng list-samples
```
And we can find our micro controller using the following command:
```bash 
./ct-ng list-samples | grep " arm-cortexa9"
```
Then use this default configurations as our starting point using the following command:
```bash
./ct-ng arm-cortexa9_neon-linux-gnueabihf
```
After setting these default configurations we can edit these configurations to meet our desired application using the following command:
```bash
./ct-ng menuconfig
```
this command will open a simple user interface which we can reconfigure whatever we want, for our example: 
* support **strace** utility 
* use **glibc** C library for std libs
## Building our Cross-toolchain
After configuring the toolchain to meet our needs we can now built it simply by using the following command:
```bash
./ct-ng build
```
And then we will wait until the build is complete and we will find `x-tools` directory is created under our home directory which contain our generated toolchain under `~/x-tools/arm-cortexa9_neon-linux-gnueabihf`. We care about specifically two sub directories:
* `~/x-tools/arm-cortexa9_neon-linux-gnueabihf/bin` which contains the toolchain bin utils to be used to build the other components like bootloader and kernel.
* `~/x-tools/arm-cortexa9_neon-linux-gnueabihf/arm-cortexa9_neon-linux-gnueabihf/sysroot` which contains a mirror of the target rootFS static and dynamic c std libs and their headers. This libs and headers MUST be a part of the target rootFS.
# Conclusion 
Till now we built and configured a very important component which is the cross-toolchain that is necessary to build other components.