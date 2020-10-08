/*
 * Includes
 */
#include <linux/kernel.h>	/* printk() */
#include <linux/module.h>	/* modules */
#include <linux/init.h>		/* module_{init,exit}() */
#include <linux/moduleparam.h> /* parameters of module */

static int param 9;

static int __init modules1_init(void)
{
	printk("parm = %d",parm);
	return 0;
}

static void __exit modules1_exit(void)
{
}

/*
 * Module entry points
 */
module_init(modules1_init);
module_exit(modules1_exit);
module_param(param, int, 0644);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Quentin Serdel");
MODULE_DESCRIPTION("Driver TP");
MODULE_PARM_DESC("param=9");
