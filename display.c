#include <xlcd.h>
#include <delays.h>
#include <stdio.h>
#include <string.h>
#include "variaveis_globais.h"
#include "calendario_relogio.h"
#include "alarme.h"


void DelayFor18TCY(void){
    Delay10TCYx(120);
}
 
void DelayPORXLCD(void){
    Delay1KTCYx(180);
    return;
}
 
void DelayXLCD(void){
    Delay1KTCYx(60);
    return;

}

void init_XLCD(VOID){
    OpenXLCD(FOUR_BIT&LINES_5X7);
    while (BusyXLCD());
    WriteCmdXLCD(0x06);
    WriteCmdXLCD(0x0C);
}

void exibir_display1(Data_hora *dh){
       
    char seg[2], min[2], hor[2], hora[16];
    char dia[2], mes[2], ano[4], data[16];
    
    if(dh->segundo<10){
        sprintf(seg, "0%d", dh->segundo);
    }else{
        sprintf(seg, "%d", dh->segundo);
    }
    if(dh->minuto<10){
        sprintf(min, "0%d", dh->minuto);
    }else{
        sprintf(min, "%d", dh->minuto);
    }
    if(dh->hora<10){
        sprintf(hor, "0%d", dh->hora);
    }else{
        sprintf(hor, "%d", dh->hora);
    }
    sprintf(hora, "HORA: %c%c:%c%c:%c%c", hor[0],hor[1],min[0],min[1],seg[0],seg[1]);
   
    if(dh->dia<10){
        sprintf(dia, "0%d", dh->dia);
    }else{
        sprintf(dia, "%d", dh->dia);
    }
    if(dh->mes<10){
        sprintf(mes, "0%d", dh->mes);
    }else{
        sprintf(mes, "%d", dh->mes);
    }
    if(dh->ano<10){
        sprintf(ano, "000%d", dh->ano);
    }else{
        if(dh->ano<100){
            sprintf(ano, "00%d", dh->ano);
        }else{
            if(dh->ano<1000){
                sprintf(ano, "0%d", dh->ano);
            } else{
                sprintf(ano, "%d", dh->ano);
            }   
        }
    }
    
    sprintf(data, "DATA: %c%c/%c%c/%c%c%c%c", dia[0],dia[1],mes[0],mes[1],ano[0],ano[1],ano[2], ano[3]);
          
    SetDDRamAddr(0x00);
    putrsXLCD(hora);
    SetDDRamAddr(0x40);
    putrsXLCD(data);
}

void exibir_display2(Alarme *alm){
       
    char seg[2], min[2], hor[2], alarme[16];
        
    if(alm->seg<10){
        sprintf(seg, "0%d", alm->seg);
    }else{
        sprintf(seg, "%d",alm->seg);
    }
    if(alm->min<10){
        sprintf(min, "0%d", alm->min);
    }else{
        sprintf(min, "%d", alm->min);
    }
    if(alm->hor<10){
        sprintf(hor, "0%d", alm->hor);
    }else{
        sprintf(hor, "%d", alm->hor);
    }
    sprintf(alarme, "    %c%c:%c%c:%c%c    ", hor[0],hor[1],min[0],min[1],seg[0],seg[1]);
    
    SetDDRamAddr(0x00);
    putrsXLCD("     ALARME     ");
    SetDDRamAddr(0x40);
    putrsXLCD(alarme);
   
}

void posicionar_cursorD1(){
    
        if(cursor==0) SetDDRamAddr(0x06); //hora dezena 
        if(cursor==1) SetDDRamAddr(0x07); //hora unidade
        if(cursor==2) SetDDRamAddr(0x09); //minuto dezena
        if(cursor==3) SetDDRamAddr(0x0A); //minuto unidade
        if(cursor==4) SetDDRamAddr(0x0C); //segundo dezena
        if(cursor==5) SetDDRamAddr(0x0D); //segundo unidade
        if(cursor==6) SetDDRamAddr(0x46); // dia dezena
        if(cursor==7) SetDDRamAddr(0x47); //dia unidade
        if(cursor==8) SetDDRamAddr(0x49); //mês dezena
        if(cursor==9) SetDDRamAddr(0x4A); //mês unidade
        if(cursor==10) SetDDRamAddr(0x4C); //ano milhar
        if(cursor==11) SetDDRamAddr(0x4D); //ano centena
        if(cursor==12) SetDDRamAddr(0x4E); //ano dezena
        if(cursor==13) SetDDRamAddr(0x4F); //ano unidade
}

void posicionar_cursorD2(){
    
        if(cursor==0) SetDDRamAddr(0x44);  //hora dezena
        if(cursor==1) SetDDRamAddr(0x45); //hora unidade
        if(cursor==2) SetDDRamAddr(0x47); //minuto dezena
        if(cursor==3) SetDDRamAddr(0x48); //minuto unidade
        if(cursor==4) SetDDRamAddr(0x4A); //segundo dezena
        if(cursor==5) SetDDRamAddr(0x4B); //segundo unidade
}
