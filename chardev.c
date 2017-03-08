#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/fs.h>
#include <linux/usb.h>

MODULE_LICENSE("GPL");

#define MIN(a,b) (((a) <= (b)) ? (a) : (b))
#define BULK_EP_OUT 0x01
#define BULK_EP_IN 0x82
#define MAX_PKT_SIZE 512

static struct usb_device *device;
static struct usb_class_driver class;
static unsigned char bulk_buf[MAX_PKT_SIZE];


ssize_t my_read (struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
  printk(KERN_ALERT "This is %s function\n",__FUNCTION__);
  printk(KERN_ALERT "DATA: %s",buffer);
  return 0;
}

ssize_t my_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{

  printk(KERN_ALERT "This is %s function\n",__FUNCTION__);
  printk(KERN_ALERT "DATA : %s \n",buffer);
  return length;
}

int my_open (struct inode *pinode, struct file *pfile)
{
  int minor,major;
  printk(KERN_ALERT "This is %s function\n",__FUNCTION__);
  major=MAJOR(pinode->i_rdev);
  minor=MINOR(pinode->i_rdev);
  printk(KERN_ALERT "MAJOR:%d  MINOR:%d\n",major,minor);
  return 0;
}

int my_close (struct inode *pinode, struct file *pfile)
{
  printk(KERN_ALERT "This is %s function\n",__FUNCTION__);
  return 0;
}
struct file_operations my_operations={
 		.owner=THIS_MODULE,
		.open=my_open,
		.read=my_read,
		.write=my_write,
		.release=my_close
		};

static int bt_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
	int retval;

	device = interface_to_usbdev(interface);

	class.name = "usb/";
	class.fops = &fops;
	if ((retval = usb_register_dev(interface, &class)) < 0)
	{
		/* Something prevented us from registering this driver */
		printk(KERN_ERR "Not able to get a minor for this device.");
	}
	else
	{
		printk(KERN_INFO "Minor obtained: %d\n", interface->minor);
	}

	return retval;
}
static struct usb_driver bt_driver =
{
	.name = "Bluetooth_driver",
	.probe = bt_probe,
	.disconnect = bt_disconnect,
	.id_table = bt_table,
};


		
int char_dev_init(void)
{
  int result;
  
  printk(KERN_ALERT "Hello World USB Driver.....%s\n",__FUNCTION__);

  /* Register this driver with the USB subsystem */
  if ((result = usb_register(&bt_driver)))
  {
	printk(KERN_ERR "usb_register failed. Error number %d", result);
  }
	return result

  return 0;
}

void char_dev_exit(void)
{
  printk(KERN_ALERT "Bye World.....%s\n",__FUNCTION__);

  /*unregistering the character driver*/
  unregister_chrdev(77,"MANOj's driver");
}

module_init(char_dev_init);
module_exit(char_dev_exit);
