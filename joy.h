/*
 * =====================================================================================
 *
 *       Filename:  joy.h
 *
 *    Description:  Head file of joy
 *
 *        Version:  1.0
 *        Created:  04/01/2013 04:02:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */
 
#include <linux/list.h>
 
#define WORD_LEN 100
#define WORD_ARRAY_LEN 10
 
#ifndef SLEEP_MILLI_SEC 
#define SLEEP_MILLI_SEC(nMilliSec)      \
    do{         \
        long timeout = (nMilliSec) * HZ / 1000;     \
        while (timeout > 0){    \
            timeout = schedule_timeout(timeout);    \
        }       \
    } while (0);        
#endif  
 
static struct task_struct *MY_THREAD = NULL;
 
static char *array[] = {"Aha! Happy foolish day!",
    "Are you crazy? Do you want to kill me?",
    "You are so gentle! I'm really apreciate that!",
    "Do you hungry?",
    "I want to tell you a story!",
    "Long long ago....",
    "~~~(*^__^*)~~~~",
    "You want to turn off the computer?",
    "If I were you, I won't do that",
    "I'm so Happy to have fun with you!"
    };
 
struct my_struct{
    char words[WORD_LEN];
    struct list_head head;
};
 
 
void print_joy(void);
 
void run(void *data);
