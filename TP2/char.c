T/*
 * Includes
 */
#include <linux/kernel.h>	/* printk() */
#include <linux/module.h>	/* modules */
#include <linux/init.h>		/* module_{init,exit}() */
#include <linux/slab.h>		/* kmalloc()/kfree() */
#include <asm/uaccess.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <linux/device.h>         // Header to support the kernel Driver Model
#include <linux/uaccess.h>
#include <linux/wait.h>

#define  DEVICE_NAME "mychar"    ///< The device will appear at /dev/mychar using this value
#define  CLASS_NAME  "mychar"        ///< The device class -- this is a character device driv

static struct class*  charClass  = NULL; ///< The device-driver class struct pointer
static struct device* charDevice = NULL; ///< The device-driver device struct pointer

int major;
int err;
char* cbuf;
static int flag = 0;
static DECLARE_WAIT_QUEUE_HEAD(wq);

/*
 * File operations
 */
static ssize_t char_read(struct file *file, char *buf, size_t count,
  loff_t *ppos)
{
  printk(KERN_INFO "reading char");
  wait_event_interruptible(wq,flag);
  if((err=copy_to_user(buf,cbuf,size_t))!=0)
    printk(KERN_ALERT "char not copied from user : %d\n",err);
  printk(KERN_INFO "sent : %s",buf);
  free(buf);
  flag=0;
  return count;
}
static ssize_t char_write(struct file *file, const char *buf, size_t count,
   loff_t *ppos)
{
  printk(KERN_INFO "writing char");
  free(buf);
  buf=kmalloc(size_t*sizeof(char),GFP_KERNEL);
  if((err=copy_from_user(cbuf,buf,size_t))!=0)
    printk(KERN_ALERT "char not copied from user : %d\n",err);
  printk(KERN_INFO "buffer : %s",cbuf);
  flag=1;
  wake_up_interruptible(&wq);
  return 0;
}
static int char_open(struct inode *inode, struct file *file)
{
  printk(KERN_INFO "opening char");
  return 0;
}
static int char_release(struct inode *inode, struct file *file)
{
  printk(KERN_INFO "releasing char");
  return 0;
}
static long char_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
  printk(KERN_INFO "enabling ioctl");
  return 0;
}
static struct file_operations char_fops = {
	.owner =	THIS_MODULE,
	.read =		char_read,
	.write =	char_write,
	.unlocked_ioctl =	char_ioctl,
	.open =		char_open,
	.release =	char_release,
};
static int __init modules1_init(void)
{
  int ret;
  ret = register_chrdev(major, "mychar", &char_fops);
  if (ret<0){
    return ret;
  }
  major = ret;


  /****** Automatically creating virtual files in /dev ******/
  // Register the device class
  charClass = class_create(THIS_MODULE, CLASS_NAME);
  if (IS_ERR(charClass)){                // Check for error and clean up if there is
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_ALERT "Failed to register device class\n");
    return PTR_ERR(charClass);          // Correct way to return an error on a pointer
  }

  // Register the device driver
  charDevice = device_create(charClass, NULL, MKDEV(major, 0), NULL, DEVICE_NAME);
  if (IS_ERR(charDevice)){               // Clean up if there is an error
    class_destroy(charClass);           // Repeated code but the alternative is goto statements
    unregister_chrdev(major, DEVICE_NAME);
    return PTR_ERR(charDevice);
  }


  return 0;
}


static void __exit modules1_exit(void)
{

  device_destroy(charClass, MKDEV(major, 0));     // remove the device
  class_unregister(charClass);                          // unregister the device class
  class_destroy(charClass);                             // remove the device class

  unregister_chrdev(major, "mychar");
}
/*
 * Module entry points
 */
module_init(modules1_init);
module_exit(modules1_exit);

MODULE_LICENSE("GPL");
