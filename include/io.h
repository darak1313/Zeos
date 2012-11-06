/*
 * io.h - Definició de l'entrada/sortida per pantalla en mode sistema
 */

#ifndef __IO_H__
#define __IO_H__

#include <types.h>
#define NUM_ESPAIS_TAB 4
/** Screen functions **/
/**********************/

Byte inb (unsigned short port);
void printc(char c);
void printc_xy(Byte x, Byte y, char c);
void printk(char *string);
void printk_xy(Byte x, Byte y, char *string);
void setXY(int posX, int posY);
void cls();

#endif  /* __IO_H__ */
