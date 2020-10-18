/*
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

static int major;
static int minor;
static int err;
char* cbuf0;
char* cbuf1;
static int flag0 = 0;
static int flag1 = 0;
static DECLARE_WAIT_QUEUE_HEAD(wq0);
static DECLARE_WAIT_QUEUE_HEAD(wq1);

/*
 * File operations
 */
static ssize_t char_read(struct file *file, char *buf, size_t count,
  loff_t *ppos)
{
  printk(KERN_INFO "reading char");
  switch(minor){
    case 0:
      wait_event_interruptible(wq0,flag);
      if((err=copy_to_user(buf,cbuf0,count))!=0)
        printk(KERN_ALERT "char not copied from user : %d",err);
      printk(KERN_INFO "sent : %s",buf);
      kfree(cbuf0);
      flag0=0;
    break;
    case 1:
      wait_event_interruptible(wq1,flag);
      if((err=copy_to_user(buf,cbuf1,count))!=0)
        printk(KERN_ALERT "char not copied from user : %d",err);
      printk(KERN_INFO "sent : %s",buf);
      kfree(cbuf1);
      flag1=0;
    break;
  return count;
}
static ssize_t char_write(struct file *file, const char *buf, size_t count,
   loff_t *ppos)
{
  printk(KERN_INFO "writing char");
  switch(minor){
    case 0:
      if(flag0==1)
        kfree(cbuf0);
      cbuf=kmalloc(count,GFP_KERNEL);
      if(!cbuf0)
        return -ENOMEM;
      if((err=copy_from_user(cbuf0,buf,count))!=0)
        printk(KERN_ALERT "char not copied from user : %d",err);
      printk(KERN_INFO "buffer0 : %s",cbuf0);
      flag0=1;
      wake_up_interruptible(&wq0);
    break;
    case 1:
      if(flag1==1)
        kfree(cbuf1);
      cbuf=kmalloc(count,GFP_KERNEL);
      if(!cbuf1)
        return -ENOMEM;
      if((err=copy_from_user(cbuf1,buf,count))!=0)
        printk(KERN_ALERT "char not copied from user : %d",err);
      printk(KERN_INFO "buffer1 : %s",cbuf1);
      flag1=1;
      wake_up_interruptible(&wq1);
    break;
    }
  return 0;
}
static int char_open(struct inode *inode, struct file *file)
{
  printk(KERN_INFO "opening char");
  minor = iminor(iode);
  printk("minor : %u", minor);
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
