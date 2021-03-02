#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Estudiantes.h"
#include "Constantes.h"
#include "Basica.h"
#include "Preguntas.h"
#include "pTipoD.h"
#include "Registrar.h"

void elegirD(int posicao, registrarTreino *vTreinos, float *puntuacion, tipoEstudante vEstudante[MAX_ALUNOS], int quantidade, int nEstudante, regPreguntas *pregunta, int totalPreguntas){
    int cantidad;
    float porcentage;

    cantidad = lerInteiro("Escolha o numero de perguntas:",4,4+totalPreguntas);

    if(cantidad == 4){
        pregunta_1D(posicao, vTreinos, &(*puntuacion), &porcentage);
        pregunta_2D(posicao, vTreinos, &(*puntuacion), &porcentage);
        pregunta_3D(posicao, vTreinos, &(*puntuacion), &porcentage);
        pregunta_4D(posicao, vTreinos, &(*puntuacion), &porcentage);
        calculoNota(cantidad, posicao, *puntuacion, vTreinos);
        calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
    }
    else{
        pregunta_1D(posicao, vTreinos, &(*puntuacion), &porcentage);
        pregunta_2D(posicao, vTreinos, &(*puntuacion), &porcentage);
        pregunta_3D(posicao, vTreinos, &(*puntuacion), &porcentage);
        pregunta_4D(posicao, vTreinos, &(*puntuacion), &porcentage);
        imprimirPregunta(cantidad, &(*puntuacion), pregunta);
        calculoNota(cantidad, posicao, *puntuacion, vTreinos);
        calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
    }

    vTreinos[posicao].cantidadP = cantidad;

}

void pregunta_1D(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
    int opcion;

    printf("\n- Quantos lados tem um octagono: \n");
    printf("(1) Tem 3 lados \n");
    printf("(2) Tem 4 lados \n");
    printf("(3) Tem 6 lados \n");
    printf("(4) Tem 8 lados \n");

    do{
        printf("Opcao -> ");
        scanf("%d",&opcion);

        if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
            printf("OPCAO INVALIDA por favor insira uma opção válida\n");
        }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);

    if (opcion== 4){
        (*puntuacion)++;
        (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;

    vTreinos[i].pruebaD.pregunta1 = opcion;

}

void pregunta_2D(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
    int opcion;

    printf("\n- Quantos lados tem um quadrado: \n");
    printf("(1) Tem 5 lados\n");
    printf("(2) Tem 6 lados\n");
    printf("(3) Tem 4 lados\n");
    printf("(4) Tem 8 lados\n");

    do{
    printf("Opcao -> ");
    scanf("%d",&opcion);
    if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
    printf("OPCAO INVALIDA por favor insira uma opção válida\n");
    }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);

    if (opcion==3){
        (*puntuacion)++;
        (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;

    vTreinos[i].pruebaD.pregunta2 = opcion;

}//fin de primera pregunta

void pregunta_3D(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
    int opcion;

    printf("\n- Quantos lados tem um triangulo: \n");
    printf("(1) Tem 3 lados \n");
    printf("(2) Tem 4 lados \n");
    printf("(3) Tem 6 lados \n");
    printf("(4) Tem 2 lados \n");

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

    vTreinos[i].pruebaD.pregunta3 = opcion;

}

void pregunta_4D(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
     int opcion;

    printf("\n-Quantos lados tem um hexagono\n");
    printf("(1) Tem 3 lados \n");
    printf("(2) Tem 4 lados \n");
    printf("(3) Tem 6 lados \n");
    printf("(4) Tem 2 lados \n");

    do{
    printf("Opcao -> ");
    scanf("%d",&opcion);
     if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4){
    printf("OPCAO INVALIDA por favor insira uma opção válida\n");
    }
    }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);

    if (opcion==3){
        (*puntuacion)++;
        (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;

    vTreinos[i].pruebaD.pregunta4 = opcion;

}
