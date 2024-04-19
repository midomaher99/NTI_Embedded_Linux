# Embedded Linux
Here we will create our Linux image for an embedded target discussing and implementing the core concepts of Embedded Linux and customization. In this part we will use QEMU emulator to emulate Versatile Express Cortex-A9 board to be our embedded target.
## Versatile Express Cortex-A9 Booting sequence
### 1.Power-On Self-Test (POST): 
It is a series of diagnostic tests are performed to make sure that the essential components are working correctly. 
### 2.Boot ROM: 
It is a program flashed by the manufacturer into the Boot ROM and is executed by the CPU after POST to initialize the basic system components and loads the primary bootloader.
### 3.Primary Bootloader: 
It is a program loaded by the Boot ROM which is responsible for initializing additional hardware and loading the OS kernel and pass its arguments.
### 4.Operating System Kernel: 
Once loaded into the memory, the bootloader passes the control into it. The kernel will mount its Root Filesystem and then executes **the init process** which is the first process in the user space.
### 5.Init process
The init process is the first process executed by the kernel in the user space which is responsible to initialize the system and start the daemons then launch the user interface whether it is a GUI or a CLI.

## Our work
We will create our linux image for our target manually as we will build and configure each component to understand the core concepts. Then we will use different build systems like BuildRoot and YOCTO project to customize our own linux image using the very powerful features of these build systems