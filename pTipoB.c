#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdlib.h>

#include "pTipoB.h"
#include "Basica.h"

void elegirB(int posicao, registrarTreino *vTreinos, float *puntuacion, tipoEstudante vEstudante[MAX_ALUNOS], int quantidade, int nEstudante){
    int cantidad;
    float porcentage;

    cantidad = lerInteiro("Escolha o numero de perguntas:",4,10);
    switch(cantidad){
        case 4:
            pregunta_1B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_2B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_3B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_4B(posicao, vTreinos, &(*puntuacion), &porcentage);
            calculoNota(cantidad, posicao, *puntuacion, vTreinos);
            calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
            break;
        case 5:
            pregunta_1B(posicao, vTreinos, &(*puntuacion), &porcentage);//AGREGAR A TODAS LAS DEMAS FUNCIONES
            pregunta_2B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_3B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_4B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_5B(posicao, vTreinos, &(*puntuacion), &porcentage);
            calculoNota(cantidad, posicao, *puntuacion, vTreinos);
            calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
            break;
        case 6:
            pregunta_1B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_2B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_3B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_4B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_5B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_6B(posicao, vTreinos, &(*puntuacion), &porcentage);
            calculoNota(cantidad, posicao, *puntuacion, vTreinos);
            calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
            break;
        case 7:
            pregunta_1B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_2B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_3B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_4B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_5B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_6B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_7B(posicao, vTreinos, &(*puntuacion), &porcentage);
            calculoNota(cantidad, posicao, *puntuacion, vTreinos);
            calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
            break;
        case 8:
            pregunta_1B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_2B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_3B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_4B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_5B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_6B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_7B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_8B(posicao, vTreinos, &(*puntuacion), &porcentage);
            calculoNota(cantidad, posicao, *puntuacion, vTreinos);
            calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
            break;
        case 9:
            pregunta_1B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_2B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_3B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_4B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_5B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_6B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_7B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_8B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_9B(posicao, vTreinos, &(*puntuacion), &porcentage);
            calculoNota(cantidad, posicao, *puntuacion, vTreinos);
            calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
            break;
        case 10:
            pregunta_1B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_2B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_3B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_4B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_5B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_6B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_7B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_8B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_9B(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_10B(posicao,vTreinos, &(*puntuacion), &porcentage);
            calculoNota(cantidad, posicao, *puntuacion, vTreinos);
            calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
            break;
    }

     vTreinos[posicao].cantidadP = cantidad;
}

void pregunta_1B(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage) {
    int opcion;


    printf("\n o que é um processador de intel?  \n");
    printf("(1) ryzen 5 3600        \n");
    printf("(2) athlon ii x4 640    \n");
    printf("(3) Exeon x5690         \n");
    printf("(4) amd a series a8-7680 \n");
    do{
    printf("Opcao -> ");
    scanf("\n%d",&opcion);



    if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
    printf("OPCAO INVALIDA por favor insira uma opção válida\n");
    }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);


    if (opcion==3){
    (*puntuacion)++;
    (*porcentage)++;


    }else

    *puntuacion = *puntuacion - 0.25;

        vTreinos[i].pruebaB.pregunta1 = opcion;

}//fin de primera pregunta

void pregunta_2B(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage) {
    int opcion;

    printf("\n- 0 Que é uma placa gráfica para jogos?\n");
    printf("(1) GeForce GT 1030 LP \n");
    printf("(2) Sapphire Pulse Radeon RX 560 OC\n");
    printf("(3) GeForce GTX 1070.\n");
    printf("(4) family graphic 630\n");
    do{
    printf("Opcao -> ");
    scanf("\n%d",&opcion);


 if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
    printf("OPCAO INVALIDA por favor insira uma opção válida\n");
    }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);


    if (opcion==3){
    (*puntuacion)++;
    (*porcentage)++;


    }else
    *puntuacion = *puntuacion - 0.25;

        vTreinos[i].pruebaB.pregunta2 = opcion;
}//fin de primera pregunta

void pregunta_3B(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage) {
     int opcion;

    printf("\n-Que nao é uma marca de computador \n");
    printf("(1) ASUS \n");
    printf("(2) LENOVO \n");
    printf("(3) MAC APPLE  \n");
    printf("(4) MOTOROLA \n");
    do{
    printf("Opcao -> ");
    scanf("%d",&opcion);



     if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
    printf("OPCAO INVALIDA por favor insira uma opção válida\n");
    }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);


    if (opcion==4){
       (*puntuacion)++;
        (*porcentage)++;
    }else
    *puntuacion = *puntuacion - 0.25;

        vTreinos[i].pruebaB.pregunta3 = opcion;
 }//fin de primera pregunta

void pregunta_4B(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage) {
     int opcion;

    printf("\n-Qual desses nomes e uma marca de ssd?\n");
    printf("(1) ASUS       \n");
    printf("(2) MAC .IOS   \n");
    printf("(3) W.D(BLACK) \n");
    printf("(4) DELL(BLUE) \n");
    do{
    printf("Opcao -> ");
    scanf("\n%d",&opcion);


     if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
    printf("OPCAO INVALIDA por favor insira uma opção válida\n");
    }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);


    if (opcion==3){
       (*puntuacion)++;
        (*porcentage)++;
    }else
    *puntuacion = *puntuacion - 0.25;

        vTreinos[i].pruebaB.pregunta4 = opcion;

 }//fin de primera pregunta

void pregunta_5B(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage) {
    int opcion;

    printf("\n-Qual desses nomes nao e uma marca de celulares \n");
    printf("(1)  Iphone     \n");
    printf("(2)  Asus phone \n");
    printf("(3)  Rayzen      \n");
    printf("(4)  kingston    \n");
    do{
    printf("Opcao -> ");
    scanf("\n%d",&opcion);



     if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
    printf("OPCAO INVALIDA por favor insira uma opção válida\n");
    }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);


    if (opcion==4){
        (*puntuacion)++;
        (*porcentage)++;
    }else
    *puntuacion = *puntuacion - 0.25;

        vTreinos[i].pruebaB.pregunta5 = opcion;

 }//fin de primera pregunta

void pregunta_6B(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
    int opcion;

    printf("\n-o que é um processador de AMD?\n");
    printf("(1) A9 .MAC                   \n");
    printf("(2) CORE I7                   \n");
    printf("(3) athlon ii x4 640          \n");
    printf("(4)  Pulse Radeon RX 1284 MHz \n");
    printf("insira la respuesta\n");
    do{
    scanf("\n%d",&opcion);


    if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
    printf("OPCAO INVALIDA por favor insira uma opção válida\n");
    }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);


    if (opcion==4){
    (*puntuacion)++;
    (*porcentage)++;


    }else
        *puntuacion = *puntuacion - 0.25;

        vTreinos[i].pruebaB.pregunta6 = opcion;
 }//fin de primera pregunta

void pregunta_7B(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
    int opcion;

    printf("\n-Como também e chamado de memória de vídeo/\n");
    printf("(1) 8 GB GDDR5   \n");
    printf("(2) 8 GB DDD4    \n");
    printf("(3) 8 GB DDR3    \n");
    printf("(4) 8 GB VRRG4    \n");
    do{
    printf("Opcao -> ");
    scanf("\n%d",&opcion);;


    if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
    printf("OPCAO INVALIDA por favor insira uma opção válida\n");
    }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);


    if (opcion==1){
    (*puntuacion)++;
    (*porcentage)++;

    }else
        *puntuacion = *puntuacion - 0.25;

        vTreinos[i].pruebaB.pregunta7 = opcion;
 }//fin de primera pregunta

void pregunta_8B(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
    int opcion;

    printf("\n-Qual dessas placas gráficas e  da AMD?\n");
    printf("(1) Sapphire Pulse  RX 580    \n");
    printf("(2) Gigabyte GTX 1660 OC      \n");
    printf("(3) MSI GTX 1660 Ti Ventus XS \n");
    printf("(4) Gigabyte TX 2060 OC       \n");
    do{
    printf("Opcao -> ");
    scanf("\n%d",&opcion);



    if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
    printf("OPCAO INVALIDA por favor insira uma opção válida\n");
    }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);


    if (opcion==1){
    (*puntuacion)++;
    (*porcentage)++;

    }else
     *puntuacion = *puntuacion - 0.25;

        vTreinos[i].pruebaB.pregunta8 = opcion;
 }//fin de primera pregunta

void pregunta_9B(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
    int opcion;

    printf("\n-como também é chamado de unidade de estado solido\n");
    printf("(1) HDD \n");
    printf("(2) DDH \n");
    printf("(3) SSD \n");
    printf("(4) SSR \n");
    do{
    printf("Opcao -> ");
    scanf("\n%d",&opcion);



    if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
    printf("OPCAO INVALIDA por favor insira uma opção válida\n");
    }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);


    if (opcion==3){
    (*puntuacion)++;
    (*porcentage)++;

    }else
    *puntuacion = *puntuacion - 0.25;

    vTreinos[i].pruebaB.pregunta9 = opcion;
 }//fin de primera pregunta

void pregunta_10B(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
    int opcion;

    printf("\n-quais desses nomes sao marcas de pendrives\n");
    printf("(1) kingston \n");
    printf("(2) lenovo  \n");
    printf("(3) Asus    \n");
    printf("(4) MAC    \n");
   do{
    printf("Opcao -> ");
    scanf("%d",&opcion);



    if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
    printf("OPCAO INVALIDA por favor insira uma opção válida\n");
    }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);


    if (opcion==1){
    (*puntuacion)++;
    (*porcentage)++;

    }else
    *puntuacion = *puntuacion - 0.25;

    vTreinos[i].pruebaB.pregunta10 = opcion;
 }//fin de primera pregunta
