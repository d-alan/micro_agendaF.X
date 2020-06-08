/*
 * File:   principal.c
 * Author: Carolina
 *
 * Created on 21 de Maio de 2019, 11:40
 */


#include <xc.h>
#include <pic18f4550.h>
#include <stdio.h>
#include <stdlib.h>
#include <xlcd.h>
#include "alarme.h"
#include "calendario_relogio.h"
#include "variaveis_globais.h"
#include "display.h"

#define POLY 0x8408
#define _XTAL_FREQ 20750000

#pragma CONFIG WTG=OFF
#pragma config PBADEN = OFF

void main(void) {
    
    iniciar(&dh);//inicia os valores de calendario_relogio
    iniciar_alarme(&alm);//inicia os valores de alarme
    
    int op=0;
        
    RCSTA=0b10010000;
    TXSTA=0b00100000;
                
    ADCON1= 0x0F;
    TRISB=0x00;
    TRISC=0b101111;
    TRISD=0x00;
        
    T0CONbits.TMR0ON=1; // HABILITA O TIMER 0;
    
    INTCONbits.TMR0IE=1; // HABILITA A FLAG DE INTERRUPÇÃO.
    INTCONbits.TMR0IF=0; // LIMPA A FLAG.
    
    T0CONbits.T08BIT=0;
    T0CONbits.PSA=0;
    T0CONbits.T0PS0=0;
    T0CONbits.T0PS1=1;
    T0CONbits.T0PS2=0;
    T0CONbits.T0CS=0; // UTILIZAR CLOCK INTERNO.
    
    TMR0=0; // ISSO É O CONTADOR DE ONDE INICIA. 
    
    T0CONbits.TMR0ON=1;
    
    // HABILITA PRA USAR INTERRUPÇÃO HIGH OU LOW. 
    INTCONbits.GIEH=1; 
    INTCONbits.GIEL=1;
    
    init_XLCD();
    
    while(1){

        PORTDbits.RD1=0;//led apagado
        
        // Botão troca de tela
        if(PORTCbits.RC0){
            __delay_ms(150);
            if(op<1){
                op++;
                cursor=-1;
            }else{
                op=0;
                cursor=-1;
            }
            while(PORTCbits.RC0){}
        }
        
        //ligar cursor na tela atual e modificar valores
        switch (op){
            //liga cursor na tela calendario_relogio
            case 0: 
                
                WriteCmdXLCD(0x0C);//desliga cursor
                exibir_display1(&dh);// mostra a tela 1
                WriteCmdXLCD(0x0F);//liga cursor
                posicionar_cursorD1();//liga cursor na posição 
                
                //botao para caminhar com o cursor na tela 1 
                if(PORTCbits.RC1==1){
                    __delay_ms (70);
                    //coloca o cursor em posição aceitável
                    if(cursor<14){
                    cursor++;
                    }else{
                        cursor=0;
                    }
                    while(PORTCbits.RC1==1){}    
                }
                //botao incrementar o valor da posicao atual do cursor
                if(PORTCbits.RC2==1){
                    __delay_ms (70);
                    incrementar_D1(&dh);
                    while(PORTCbits.RC2==1){}
                }
                //botao decrementar o valor da posicao atual
                if(PORTCbits.RC4==1){
                    __delay_ms (70);
                    decrementar_D1(&dh);
                    while(PORTCbits.RC4==1){}
                }
            break;
            
            //liga cursor na tela alarme
            case 1:
                
                WriteCmdXLCD(0x0C);//desliga cursor
                exibir_display2(&alm);//mostra a tela de alarme
                WriteCmdXLCD(0x0F);//liga cursor
                posicionar_cursorD2();//liga o cursor na posição
                
                //botao para andar com o cursor na tela de alarme
                if(PORTCbits.RC1==1){
                    __delay_ms(70);
                    if(cursor<6){
                        cursor++;
                    }else{
                        cursor=0;
                    }
                    while(PORTCbits.RC1==1){}  
                }
                //botao incrementar valor da posicao atual
                if(PORTCbits.RC2==1){
                    __delay_ms (70);
                    incrementar_D2(&alm);
                    tratar_alarme(&alm);
                    while(PORTCbits.RC2==1){}
                }
                //botao decrementar valor da posicao atual
                if(PORTCbits.RC4==1){
                    __delay_ms (70);
                    decrementar_D2(&alm);
                    tratar_alarme(&alm);
                    while(PORTCbits.RC4==1){}
                }
            break;
        }
    }
    
    return;
}

void __interrupt () pic_isr(void){
    
    if(TMR0IF){  
        TMR0=0;
        INTCONbits.TMR0IF=0;
        contador++;
    }
    if(contador>9){
        contador=0;
        tratar_relogio(&dh);
        verificar_alarme();
        
        if(ver_alm==1){
            if(cont_alarme%2!=0){
                PORTDbits.RD1=1;
            }
            if(cont_alarme%2==0){
                PORTDbits.RD1=0;
            }
            if(cont_alarme>10){
                cont_alarme=0;
                ver_alm=0;
            }
            cont_alarme++;
        }
    }
}
