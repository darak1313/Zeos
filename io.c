/*
 * io.c - 
 */

#include <io.h>
#include <devices.h>
#include <types.h>

#include "sched.h"

/**************/
/** Screen  ***/
/**************/

#define NUM_COLUMNS 80
#define NUM_ROWS    25

Byte x, y=15;

int llegintDeTeclat() {
    return !llistaTeclatBuida();
}

void llegeixChar(){
    readChar();
}

/*struct readStruct* list_head_to_lectura(struct list_head* l){
    return (struct readStruct*)list_head_to_task_struct(l);
}*/

/* Read a byte from 'port' */
Byte inb (unsigned short port)
{
  Byte v;

  __asm__ __volatile__ ("inb %w1,%0":"=a" (v):"Nd" (port));
  return v;
}

void printc(char c)
{
  if (c=='\n')
  {
    x = 0;
    y=(y+1)%NUM_ROWS;
  }else if(c=='\t'){
      int i;
      for(i=0;i<NUM_ESPAIS_TAB;i++){
          printc(' ');
      }
  }
  else
  {
    Word ch = (Word) (c & 0x00FF) | 0x0200;
    DWord screen = 0xb8000 + (y * NUM_COLUMNS + x) * 2;
     __asm__ __volatile__ ( "movb %0, %%al; outb $0xe9" ::"a"(c));
    if (++x >= NUM_COLUMNS)
    {
      x = 0;
      y=(y+1)%NUM_ROWS;
    }
    asm("movw %0, (%1)" : : "g"(ch), "g"(screen));
  }
}

void printc_xy(Byte mx, Byte my, char c)
{
  Byte cx, cy;
  cx=x;
  cy=y;
  x=mx;
  y=my;
  printc(c);
  x=cx;
  y=cy;
}

void printk(char *string)
{
  int i;
  for (i = 0; string[i]; i++)
    printc(string[i]);
}

void printk_xy(Byte mx, Byte my, char *string)
{
  Byte cx, cy;
  cx=x;
  cy=y;
  x=mx;
  y=my;
  printk(string);
  x=cx;
  y=cy;
}

void cls(){
    int i;
    for(i=0;i<(NUM_COLUMNS*NUM_ROWS);i++){
        printc(' ');
    }
    x=0;
    y=1;
}
