# Loadable kernel module (LKM)
The LKM is a piece of software extends the features of the running kernel and it can be:
1. Static module:
which is compiled with the kernel and integrated with it in the same image. It is loaded when the kernel is booted and it can't be unloaded as it is a part of the kernel image.
2. Dynamic module:
    which is can be loaded or unloaded after the kernel is booted while it is running.
## Creating our own module
Here we will create our own simple hello world module discussing the phases of module creation and the basic concepts of linux modules.
### Setting up the environment
#### Installing kernel headers
Usually kernel headers are installed by default but incase it is not then we need to install the, using the following command:
```bash
sudo apt install linux-headers-$(uname -r)
```
The kernel headers will be found under `/usr/src/linux-headers-5.15.0-105-generic/include` for my machine but `linux-header-x.xx.x-xxx-generic` will be different depending on the version of the kernel.
#### Setting up vs code environment
To use the vs code features as auto complete we need to add the path to the kernel headers to its include path in `.vscode/c_cpp_properties.json` under your working space by appending `/usr/src/linux-headers-5.15.0-105-generic/include` to `includePath` variable using `,` separator.
### Creating module source code
I will create a new directory under my work space for this module `mkdir hello_world_module` then create a C source file for the module source code [hello_world.c](./hello_world_module/hello_world.c).
```
#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");  //this line must be added
MODULE_AUTHOR("Maher");
MODULE_DESCRIPTION("Simple module prints hello world");


static int __init hello_start(void)
{
    printk("hello world\n");
    return 0;
}

static void __exit hello_end(void)
{
    printk("Bye Bye\n");
}

module_init(hello_start);
module_exit(hello_end);
```
In our module we can't use the C libs or its headers as it will run in the kernel space and wont be linked with any library so we use the kernel headers and built-in functions instead. 
* we **MUST** add the module license using `MODULE_LICENSE` macro to avoid errors while building and inserting our module. 
* We defined two functions `hello_start` and `hello_end` to be invoked while loading and unloading the module, these functions are passed to `module_init` and `module_exit` macros to set the role of each function of them (setting then to be invoked when load and unload the module).
* `printk` function is kernel function behaves like the C function `printf` but it prints kernel messages into a buffer exported to `/dev/kmsg` and we can print these messages using `dmesg` command.
* `__init` is a key word that tells to linker to put this function into `.init` section which will be removed from memory after finishing the execution of this function.
* `__exit` is a key word that tells to linker to put this function into `.exit` section which will be not loaded into the memory if the module is a static module as it will be a part of the kernel which will not ever exit.
### Building the module
To build the module we need to invoke a Makefile implemented under `/lib/modules/x.xx.x-xxx-generic/build` so we will create our make file which will invoke it [Makefile](./hello_world_module/Makefile)
```
obj-m = hello_world.o
BDIR=/lib/modules/$(shell uname -r)/build
all:
	make -C $(BDIR) M=$(shell pwd) modules
clean:
	make -C $(BDIR) M=$(shell pwd) clean
```
* `obj-x` as x can take one of the values:
    * `y` to build a static module.
    * `m` to build a dynamic module.
    * `n` to ignore compiling this module
* `BDIR` setting a variable to the path of the build directory which contains the Make file we need to invoke
* `M` variable is uset to set the module directory which have the module source file and to create the compiled module and intermediate files in it

Then we can build our module simply by using `make` command it will generates many files but we are only interested with `hello_world.ko`
### Loading and unloading the module
There is three useful commands for handling modules
1. `lsmod` to show the status of modules in the Linux Kernel.
2. `insmod` to insert a module into the Linux Kernel.
    the init function will be invoked after inserting the module.
3. `rmmod` to remove a module from the Linux Kernel.
    the exit function will be invoked after removing the module.
We can verify that our module works will by using `dmesg` command to see the messages printed by `printk` function