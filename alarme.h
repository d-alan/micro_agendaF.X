/* 
 * File:   alarme.h
 * Author: Carolina
 *
 * Created on 21 de Maio de 2019, 11:43
 */

#ifndef ALARME_H
#define	ALARME_H

#include <xc.h>
#define _XTAL_FREQ 20750000

typedef struct
{
    int seg;
    int min;
    int hor;
} Alarme;

void iniciar_alarme(Alarme *alm);
void tratar_alarme(Alarme *alm);
void incrementar_D2(Alarme *alm);
void decrementar_D2(Alarme *alm);
void verificar_alarme();

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* ALARME_H */

