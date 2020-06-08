/* 
 * File:   display.h
 * Author: Carolina
 *
 * Created on 21 de Maio de 2019, 13:23
 */

#ifndef DISPLAY_H
#define	DISPLAY_H

#include <xc.h> 

void DelayFor18TCY(void);
void DelayPORXLCD(void);
void DelayXLCD(void);
void init_XLCD(VOID);
void exibir_display1(Data_hora *dh);
void exibir_display2(Alarme *alm);
void posicionar_cursorD1();
void posicionar_cursorD2();

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* DISPLAY_H */

