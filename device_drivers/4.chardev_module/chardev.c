#include <linux/module.h>
#include <linux/fs.h>
#include <linux/device/class.h>
#include <linux/cdev.h>
#include <linux/kern_levels.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("MAHER");
MODULE_DESCRIPTION("Simple char device module represents read and write operations");

#define MINOR_BASE      (0u)
#define MINOR_COUNT     (4u)


dev_t base_dev_number;
struct class* chardev_class;
struct cdev chardev[MINOR_COUNT];
struct device * my_devices[MINOR_COUNT];
char dev_buff[MINOR_COUNT]; //every device has only one char 


ssize_t my_read (struct file * file, char __user * user_buff, size_t size, loff_t * poffset)
{
    printk("%s is called\n",__FUNCTION__);
    return size;
}
ssize_t my_write (struct file * file, const char __user * user_buff, size_t size, loff_t * poffset)
{
    printk("%s is called\n",__FUNCTION__);
    return 0;
}


struct file_operations fops={
    .owner=THIS_MODULE,
    .read=my_read,
    .write=my_write
};
static int __init chardev_init(void)
{
    unsigned int counter;
    int retval;

    // dynamically allocate the device region
    if((retval = alloc_chrdev_region(&base_dev_number,MINOR_BASE,MINOR_COUNT,"chardev")))
    {
        printk(KERN_ERR "Failed to alloc the char device.\n");
        return retval;
    }
    else
    {
        printk(KERN_INFO "Device allocated succesfully with Major=%d, Minor=%d.\n",MAJOR(base_dev_number),MINOR(base_dev_number));
    }
    // creating a class for our device to add it to our sysfs
    chardev_class=class_create(THIS_MODULE, "chardev_class");

    if(chardev_class == NULL)
    {
        printk(KERN_ERR "Failed to create a class for the char device\n");
        unregister_chrdev_region(base_dev_number,MINOR_COUNT);
        return -1;
    }
    else
    {
        printk(KERN_INFO "Device class created succesfully.\n");
    }

    for (counter=MINOR_BASE; counter < MINOR_COUNT; counter++)
    {
        cdev_init(&chardev[counter],&fops);

        //ading the dvice for the system
        if((retval=cdev_add(&chardev[counter],MKDEV(MAJOR(base_dev_number),counter),1)))
        {
            unsigned int i;
            printk(KERN_ERR "Failed to add chardev%d to the system.\n", counter);
            
            //deleteing the previous added devices
            for(i = MINOR_BASE; i<counter;i++)
                cdev_del(&chardev[i]);

            return retval;
        }
        else
        {
            printk(KERN_INFO "chardev%d added to the system succesfully.\n",counter);
        }

        //creating the device and adding it to sysfs
        my_devices[counter]=device_create(chardev_class,NULL,MKDEV(MAJOR(base_dev_number),counter),NULL,"chardev%d",counter);
        
        if (my_devices[counter] == NULL)
        {
            unsigned int i;

            printk(KERN_ERR "Failed to create the device chardev%d and register it with sysfs.\n",counter);

            //deleteing the previous added and created devices
            for(i = MINOR_BASE; i<counter;i++)
            {
                device_destroy(chardev_class,MKDEV(MAJOR(base_dev_number),i));
                cdev_del(&chardev[i]);
            }
            cdev_del(&chardev[counter]);    //delete the current added device

            return -1;
        }
        else
        {
            printk(KERN_INFO "chardev%d  created and added to sysfs succesfully.\n",counter);
        }
    }
    return 0;
}

static void __exit chardev_exit(void)
{
    unsigned int counter;
    for (counter=MINOR_BASE; counter < MINOR_COUNT; counter++)
    {
        device_destroy(chardev_class,MKDEV(MAJOR(base_dev_number),counter));
        cdev_del(&chardev[counter]);
    }
    class_destroy(chardev_class);
    unregister_chrdev_region(base_dev_number,MINOR_COUNT);
}
module_init(chardev_init);
module_exit(chardev_exit);