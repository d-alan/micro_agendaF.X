/* 
 * File:   calendario_relogio.h
 * Author: Carolina
 *
 * Created on 21 de Maio de 2019, 11:43
 */

#ifndef CALENDARIO_RELOGIO_H
#define	CALENDARIO_RELOGIO_H
#include<xc.h>

int quant_mes[]={31,28,31,30,31,30,31,31,30,31,30,31};

typedef struct 
{ 
    int dia, mes, ano;
    int segundo, minuto, hora;
    
}Data_hora;

void iniciar(Data_hora *dh);
void verifica_bissexto(int ano);
void tratar_relogio(Data_hora *dh);
void incrementar_D1(Data_hora *dh);
void decrementar_D1(Data_hora *dh);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* CALENDARIO_RELOGIO_H */

