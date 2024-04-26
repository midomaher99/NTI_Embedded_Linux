#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/errno.h>

#define buff_size (128u)

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Maher");
MODULE_DESCRIPTION("Simple module creates a directory entry and a file entry under /proc and creates the basic file operations of this file");
struct proc_dir_entry * parent_dir=NULL;
struct proc_dir_entry * file_entry=NULL;
char buff[buff_size];

ssize_t	mod_read(struct file * my_file, char __user * user_buff, size_t read_size, loff_t * poffset)
{
    ssize_t bytes_read =0;
    printk("%s is called \n", __FUNCTION__);    //for debugging and tracing
   
    if (*poffset >= buff_size)
        return 0;   //EOF reached

    //calc number of bytes to read
    if (read_size <= (buff_size - *poffset))
        bytes_read =read_size;
    else 
        bytes_read =(buff_size - *poffset);

    //performing read to the shared buffer between user and kernel
    if(copy_to_user(user_buff,buff,bytes_read)) //copy_to_user returns 0 on success
        return -EFAULT;
    
    //updating offset
    *poffset += bytes_read;

    //return number of read bytes on success
    return bytes_read;

}

ssize_t	mod_write(struct file * my_file, const char __user * user_buff, size_t write_size, loff_t * poffset)
{
    ssize_t bytes_write=0;
    printk("%s is called \n", __FUNCTION__);    //for debugging and tracing

    //calc number of bytes to write
    if (write_size < (buff_size - *poffset))
        bytes_write = write_size;
    else
        bytes_write =  (buff_size - *poffset);
    //performing write to the kernel buffer
    if(copy_from_user(buff,user_buff,bytes_write))
        return -EFAULT;
    
    //updating offset
    *poffset += bytes_write;

    //return number of written bytes on success
    return bytes_write;

}

//attach my callbacks into proc_ops struct
static const struct proc_ops pops = {
    .proc_read=mod_read,
    .proc_write=mod_write
};

//init function
static int __init  my_init(void)
{
    printk("%s is called \n", __FUNCTION__);    //for debugging and tracing
    //creating a directory and file entries under /proc
    parent_dir = proc_mkdir("my_dir",NULL);
    file_entry = proc_create("my_file", 0666,parent_dir, &pops );
    return 0;
}
//exit function
static void  __exit  my_exit(void)
{
    printk("%s is called \n", __FUNCTION__);    //for debugging and tracing
    //removing the created entries from /proc
    proc_remove(parent_dir);    
}

module_init(my_init);
module_exit(my_exit);