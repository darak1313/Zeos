/*
 * entry.h - Definició del punt d'entrada de les crides al sistema
 */

#ifndef __ENTRY_H__
#define __ENTRY_H__

void clock_handler();
void keyboard_handler();
void pageFault_handler();
void ret_from_clone();

#endif  /* __ENTRY_H__ */
