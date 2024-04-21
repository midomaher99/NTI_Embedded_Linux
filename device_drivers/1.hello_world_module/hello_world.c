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