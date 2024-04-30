# Hello world module on RPI3 model b
Here we will discuss how to build and deploy kernel modules into another target machine (RPI3 b) using **YOCTO Project** and its dev tool. This will be our approache for comming modules to be used in (RPI3 b).
## prerequisites
* Raspberrypi 3 model b running with a poky linux image with ssh server.
## Making a layer and a recipe
### 1. Creating a meta-layer 
* `bitbake-layers create-layer meta-hello-module`
* `rm -r  <PATH_TO_LAYER>/README <PATH_TO_LAYER>/recipes-example
### 2. Creating a recipe
There is an example for linux module we will find in `<PATH_TO_POKY>/poky/meta-skeleton/recipes-kernel/hello-mod`, we will copy it into our layer as a skelton for any kernel module we will imlement.
* `cd meta-hello-module`
* `mkdir recipes-hello_module`
* `cp -r <PATH_TO_POKY>/poky/meta-skeleton/recipes-kernel/hello-mod/ recipes-hello_module/`
* `rm hello-mod/files/hello.c` Removing the example source code to add our source code.
* `cp <our src file> .` for this example the src file is imlemented in [1.hello_world_module](../1.hello_world_module/)
* edite the Makefile variable with the name of our src file name `obj-m = hello_world.o`.
* edite the `hello-mod_0.1.bb` vriable `SRC_URI` and chane the src file name with our src file name `hello_world.c`
### 3. Adding the meta-layer into our build environment 
* `source <PATH_TO_POKY>/poky/oe-init-build-env <PATH_TO_BUILD_ENV_DIR>`
* `bitbake-layers add-layer ../layers/meta-hello-module/`
### 4. Cheking that everything is OK
* `bitbake hello-mod` 
## Deploying the module using devtool
* `devtool modify hello-mod` adding the recipe to the workspace.
* `bitbake hello-mod`  building the recipe
* `devtool deploy-target hello-mod <user>@<IP_address>` deploying the compiled module to the (RPI3 b)
hello_world.ko file will be deployed under `/lib/modules/<kernel_version>/extra`, we can simply search for it usinf `find / -iname "hello_world.ko"`
## Inserting and testing the module 
* `insmod /lib/modules/<kernel_version>/extra/hello_world.ko`
* `dmesg` will see the `hello world` message we printed in our module.
* `rmmod hello_world` removinf the module from the kernel
* `dmesg` will see the `Bye Bye` message we printed in our module.