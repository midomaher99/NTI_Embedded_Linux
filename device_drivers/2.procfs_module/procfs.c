#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
//#include <asm/uacces.h>
MODULE_LICENSE("GPL");

struct proc_dir_entry * parent_dir=NULL;
struct proc_dir_entry * file_entry=NULL;
ssize_t	mod_read(struct file * file1, char __user * user1, size_t size1, loff_t * loff1)
{
    printk("my read\n");
    return 0;
}

ssize_t	mod_write(struct file * file1, const char __user * user1, size_t size1, loff_t * loff1)
{
    printk("my write\n");
    return size1;
}

static const struct proc_ops pops = {
    .proc_read=mod_read,
    .proc_write=mod_write
};

static int __init  my_init(void)
{
    printk("insmod\n");
    
    parent_dir = proc_mkdir("myDir",NULL);
    file_entry = proc_create("myFile", 0666,parent_dir, &pops );
    return 0;
}

static void  __exit  my_deinit(void)
{
    printk("rmmod\n");
    proc_remove(parent_dir);    
}


module_init(my_init);
module_exit(my_deinit);