/*
 * =====================================================================================
 *
 *       Filename:  joy.c
 *
 *    Description:  Source file of joy
 *
 *        Version:  1.0
 *        Created:  04/02/2013 09:23:37 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */
 
 
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kthread.h>
#include "joy.h"
 
void get_random_bytes(void *buf, int nbytes);
void print_joy(void){
    unsigned int number = 0;
    get_random_bytes(&number, sizeof(unsigned int));
    number = number % 10; 
    printk("JOY:  %s\n",*array+number);    
}
 
void run(void *data){
    while (!kthread_should_stop()) {
        SLEEP_MILLI_SEC(1000);
        print_joy();
    }   
}
static int __init init_joy(void) {
    printk("start joy!\n");
    MY_THREAD = kthread_run(run, NULL,"joy");
    return 0;
 
}
 
static void __exit exit_joy (void) {
    if (MY_THREAD) {
        printk("Stop joy!\n");
        kthread_stop(MY_THREAD);
    }
}
 
MODULE_LICENSE("Dual BSD/GPL");
module_init(init_joy);
module_exit(exit_joy);
