#include "calendario_relogio.h"
#include "variaveis_globais.h"

void iniciar(Data_hora *dh)
{
    dh->ano=dh->mes=dh->dia=1;
    dh->hora=dh->minuto=dh->segundo=0;
    
}
void verifica_bissexto(int ano)
{    
    if(ano%4==0 && ((ano%400==0) || (ano%100!=0))){
        quant_mes[1]=29;
    } 
    else {
        quant_mes[1]=28;
    }
   
}

void tratar_relogio(Data_hora *dh)
{
    dh->segundo++;
    if(dh->segundo>59){
        dh->minuto++;
        dh->segundo=0;
    }
    if(dh->segundo<0){
        dh->minuto--;
        dh->segundo=59;
    }
    if(dh->minuto>59){
        dh->hora++;
        dh->minuto=0;
    }
    if(dh->minuto<0){
        dh->hora--;
        dh->minuto=59;
    }
    if(dh->hora>23){
        dh->dia++;
        dh->hora=0;
    }
    if(dh->hora<0){
        dh->dia--;
        dh->hora=23;
    }
    if(dh->dia>quant_mes[dh->mes-1]){
        dh->mes++;
        dh->dia=1;
    }
    if(dh->dia<1){
        dh->mes--;
        dh->dia=quant_mes[dh->mes-1];
    }
    if(dh->mes>12){
        dh->ano++;
        dh->mes=1;
        verifica_bissexto(dh->ano);
    }
    if(dh->mes<1){
        dh->ano--;
        dh->mes=12;
        verifica_bissexto(dh->ano);
    }
}

void incrementar_D1(Data_hora *dh){
        if(cursor==0) dh->hora=dh->hora+10;//hora dezena 
        if(cursor==1) dh->hora=dh->hora+1;//hora unidade
        if(cursor==2) dh->minuto=dh->minuto+10;//minuto dezena
        if(cursor==3) dh->minuto=dh->minuto+1;//minuto unidade
        if(cursor==4)dh->segundo=dh->segundo+10;//segundo dezena
        if(cursor==5) dh->segundo=dh->segundo+1;//segundo unidade
        if(cursor==6) dh->dia=dh->dia+10;//dia dezena
        if(cursor==7) dh->dia=dh->dia+1;//dia unidade
        if(cursor==8) dh->mes=dh->mes+10;// mês dezena
        if(cursor==9) dh->mes=dh->mes+1;//mês unidade
        if(cursor==10) dh->ano=dh->ano+1000;//ano milhar
        if(cursor==11) dh->ano=dh->ano+100;//ano centena
        if(cursor==12) dh->ano=dh->ano+10;//ano dezena
        if(cursor==13) dh->ano=dh->ano+1;//ano unidade
}

void decrementar_D1(Data_hora *dh){
        if(cursor==0) dh->hora=dh->hora-10; //hora dezena  
        if(cursor==1) dh->hora=dh->hora-1; //hora unidade
        if(cursor==2) dh->minuto=dh->minuto-10; //minuto dezena
        if(cursor==3) dh->minuto=dh->minuto-1;///minuto unidade
        if(cursor==4)dh->segundo=dh->segundo-10;//segundo dezena
        if(cursor==5) dh->segundo=dh->segundo-1; //segundo unidade
        if(cursor==6) dh->dia=dh->dia-10; //dia dezena
        if(cursor==7) dh->dia=dh->dia-1; //dia unidade
        if(cursor==8) dh->mes=dh->mes-10; // mês dezena
        if(cursor==9) dh->mes=dh->mes-1; //mês unidade
        if(cursor==10) dh->ano=dh->ano-1000; //ano milhar
        if(cursor==11) dh->ano=dh->ano-100;//ano centena
        if(cursor==12) dh->ano=dh->ano-10;//ano dezena
        if(cursor==13) dh->ano=dh->ano-1;//ano unidade
}

