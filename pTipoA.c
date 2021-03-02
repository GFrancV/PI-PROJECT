#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdlib.h>

#include "Basica.h"
#include "pTipoA.h"
#include "Estudiantes.h"
#include "Registrar.h"


void elegirA(int posicao, registrarTreino *vTreinos, float *puntuacion, tipoEstudante vEstudante[MAX_ALUNOS], int quantidade, int nEstudante){
    int cantidad;
    float porcentage;

    cantidad = lerInteiro("Escolha o numero de perguntas:",4,10);

    switch(cantidad){
        case 4:
            pregunta_1A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_2A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_3A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_4A(posicao, vTreinos, &(*puntuacion), &porcentage);
            calculoNota(cantidad, posicao, *puntuacion, vTreinos);
            calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
            break;
        case 5:
            pregunta_1A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_2A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_3A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_4A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_5A(posicao, vTreinos, &(*puntuacion), &porcentage);
            calculoNota(cantidad, posicao, *puntuacion, vTreinos);
            calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
            break;
        case 6:
            pregunta_1A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_2A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_3A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_4A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_5A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_6A(posicao, vTreinos, &(*puntuacion), &porcentage);
            calculoNota(cantidad, posicao, *puntuacion, vTreinos);
            calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
            break;
        case 7:
            pregunta_1A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_2A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_3A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_4A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_5A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_6A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_7A(posicao, vTreinos, &(*puntuacion), &porcentage);
            calculoNota(cantidad, posicao, *puntuacion, vTreinos);
            calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
            break;
        case 8:
            pregunta_1A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_2A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_3A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_4A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_5A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_6A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_7A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_8A(posicao, vTreinos, &(*puntuacion), &porcentage);
            calculoNota(cantidad, posicao, *puntuacion, vTreinos);
            calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
            break;
        case 9:
            pregunta_1A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_2A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_3A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_4A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_5A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_6A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_7A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_8A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_9A(posicao, vTreinos, &(*puntuacion), &porcentage);
            calculoNota(cantidad, posicao, *puntuacion, vTreinos);
            calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
            break;
        case 10:
            pregunta_1A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_2A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_3A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_4A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_5A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_6A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_7A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_8A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_9A(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_10A(posicao, vTreinos, &(*puntuacion), &porcentage);
            calculoNota(cantidad, posicao, *puntuacion, vTreinos);
            calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
            break;
    }

    vTreinos[posicao].cantidadP = cantidad;

}

void pregunta_1A(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
    int opcion;

    printf("\n-Quanto e a raiz de 9 \n");
    printf("(1) E igual a 1.3 \n");
    printf("(2) E igual a 5   \n");
    printf("(3) E igual a 3   \n");
    printf("(4) E igual a 6   \n");

    do{
        printf("Opcao -> ");
        scanf("%d",&opcion);

        if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
            printf("OPCAO INVALIDA por favor insira uma opçao valida\n");
        }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);

    if (opcion== 3){
        (*puntuacion)++;
        (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;

    vTreinos[i].pruebaA.pregunta1 = opcion;

}

void pregunta_2A(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
    int opcion;

    printf("\n-Quanto e a raiz de 25 \n");
    printf("(1) E igual a 5 \n");
    printf("(2) E igual a 30\n");
    printf("(3) E igual a 15\n");
    printf("(4) E igual a 10\n");

    do{
    printf("Opcao -> ");
    scanf("%d",&opcion);
    if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
    printf("OPCAO INVALIDA por favor insira uma opçao valida\n");
    }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);

    if (opcion==1){
        (*puntuacion)++;
        (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;

    vTreinos[i].pruebaA.pregunta2 = opcion;

}

void pregunta_3A(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
    int opcion;

    printf("\n-Quanto e a raiz de 64 \n");
    printf("(1) E igual a 7  \n");
    printf("(2) E igual a 39 \n");
    printf("(3) E igual a 8  \n");
    printf("(4) E igual a 10 \n");

    do{
    printf("Opcao -> ");
    scanf("%d",&opcion);
     if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
    printf("OPCAO INVALIDA por favor insira uma opçao valida\n");
    }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);



    if (opcion==3){
        (*puntuacion)++;
        (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;

    vTreinos[i].pruebaA.pregunta3 = opcion;

}

void pregunta_4A(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
     int opcion;

    printf("\n-Quanto e a raiz de 49\n");
    printf("(1) E igual a 6  \n");
    printf("(2) E igual a 7  \n");
    printf("(3) E igual a 18 \n");
    printf("(4) E igual a 39 \n");

    do{
    printf("Opcao -> ");
    scanf("%d",&opcion);
     if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
    printf("OPCAO INVALIDA por favor insira uma opçao valida\n");
    }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);



    if (opcion==2){
        (*puntuacion)++;
        (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;

    vTreinos[i].pruebaA.pregunta4 = opcion;

}

void pregunta_5A(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
    int opcion;

    printf("\n-Quanto e a raiz de 121\n");
    printf("(1) E igual a 12 \n");
    printf("(2) E igual a 10 \n");
    printf("(3) E igual a 13 \n");
    printf("(4) E igual a 11 \n");

    do{
    printf("Opcao -> ");
    scanf("%d",&opcion);
     if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
    printf("OPCAO INVALIDA por favor insira uma opçao valida\n");
    }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);

    if (opcion==4){
        (*puntuacion)++;
        (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;

    vTreinos[i].pruebaA.pregunta5 = opcion;

}

void pregunta_6A(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
    int opcion;

    printf("\n-Quanto e a raiz de 36\n");
    printf("(1) E igual a 8  \n");
    printf("(2) E igual a 4  \n");
    printf("(3) E igual a 2  \n");
    printf("(4) E igual a 6  \n");

    do{
    printf("Opcao -> ");
    scanf("\n%d",&opcion);
    if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
    printf("OPCAO INVALIDA por favor insira uma opçao valida\n");
    }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);

    if (opcion==4){
        (*puntuacion) ++;
        (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;

    vTreinos[i].pruebaA.pregunta6 = opcion;

}

void pregunta_7A(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
    int opcion;

    printf("\n-Quanto e a raiz de 225\n");
    printf("(1) E igual a 15   \n");
    printf("(2) E igual a 14.5 \n");
    printf("(3) E igual a 13   \n");
    printf("(4) E igual a 13   \n");

    do{
    printf("Opcao -> ");
    scanf("%d",&opcion);;

    if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
    printf("OPCAO INVALIDA por favor insira uma opçao valida\n");
    }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);



    if (opcion==4){
        (*puntuacion) ++;
        (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;

    vTreinos[i].pruebaA.pregunta7 = opcion;

}

void pregunta_8A(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
    int opcion;

    printf("\n-Quanto e a raiz de 900\n");
    printf("(1) E igual a 24   \n");
    printf("(2) E igual a 21.5 \n");
    printf("(3) E igual a 20   \n");
    printf("(4) E igual a 30   \n");

    do{
    printf("Opcao -> ");
    scanf("%d",&opcion);
    if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
    printf("OPCAO INVALIDA por favor insira uma opçao valida\n");
    }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);



    if (opcion==4){
        (*puntuacion) ++;
        (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;

    vTreinos[i].pruebaA.pregunta8 = opcion;

 }

void pregunta_9A(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
    int opcion;

    printf("\n-Quanto e a raiz de 400\n");
    printf("(1) E igual a 24   \n");
    printf("(2) E igual a 21.5 \n");
    printf("(3) E igual a 20   \n");
    printf("(4) E igual a 22   \n");

    do{
    printf("Opcao -> ");
    scanf("%d",&opcion);
    if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
    printf("OPCAO INVALIDA por favor insira uma opçao valida\n");
    }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);

    if (opcion==3){
        (*puntuacion) ++;
        (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;

    vTreinos[i].pruebaA.pregunta8 = opcion;

}

void pregunta_10A(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
    int opcion;

    printf("\nQuanto e a raiz de 169\n");
    printf("(1) E igual a 13 \n");
    printf("(2) E igual a 17  \n");
    printf("(3) E igual a 15  \n");
    printf("(4) E igual a 12  \n");

   do{
    printf("Opcao -> ");
    scanf("%d",&opcion);

    if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
    printf("OPCAO INVALIDA por favor insira uma opçao valida\n");
    }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);

    if (opcion==3){
        (*puntuacion) ++;
        (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;

    vTreinos[i].pruebaA.pregunta8 = opcion;

 }



