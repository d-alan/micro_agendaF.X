#include "alarme.h"
#include "variaveis_globais.h"
#include "calendario_relogio.h"

void iniciar_alarme(Alarme *alm){
     alm->seg=0;
     alm->min=0;
     alm->hor=15;
}

void tratar_alarme(Alarme *alm){
     if(alm->seg>59){
        alm->min++;
        alm->seg=0;
    }
    if(alm->seg<0){
        alm->min--;
        alm->seg=59;
    }
    if(alm->min>59){
        alm->hor++;
        alm->min=0;
    }
    if(alm->min<0){
        alm->hor--;
        alm->min=59;
    }
    if(alm->hor>23){
        alm->hor=0;
    }
    if(alm->hor<0){
        alm->hor=23;
    }
}

void incrementar_D2(Alarme *alm){
        if(cursor==0) alm->hor=alm->hor+10;// hora dezena
        if(cursor==1) alm->hor=alm->hor+1; // hora unidade
        if(cursor==2) alm->min=alm->min+10; // minuto dezena
        if(cursor==3) alm->min=alm->min+1; // minuto unidade
        if(cursor==4) alm->seg=alm->seg+10; //segundo dezena
        if(cursor==5) alm->seg=alm->seg+1; // segundo unidade
}

void decrementar_D2(Alarme *alm){
        if(cursor==0) alm->hor=alm->hor-10; // hora dezena
        if(cursor==1) alm->hor=alm->hor-1; // hora unidade
        if(cursor==2) alm->min=alm->min-10; //  minuto dezena
        if(cursor==3) alm->min=alm->min-1; // minuto unidade
        if(cursor==4) alm->seg=alm->seg-10; // segundo dezena
        if(cursor==5) alm->seg=alm->seg-1; // segundo unidade
}

/*
void verificar_alarme(){
    int aux=0;
    if(dh.hora==alm.hor && dh.minuto==alm.min && dh.segundo==alm.seg){
        while(aux<2){
        PORTDbits.RD1=1;
        __delay_ms(2000);
        PORTDbits.RD1=0;
        __delay_ms(2000);
        aux++;
       }
        dh.segundo=dh.segundo+8;
    }
}
*/ 

void verificar_alarme(){
    if(dh.hora==alm.hor && dh.minuto==alm.min && dh.segundo==alm.seg) {
        ver_alm = 1;
        cont_alarme = 1;
    }
}