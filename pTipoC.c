#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdlib.h>

#include "Basica.h"
#include "pTipoC.h"
#include "Estudiantes.h"
#include "Estructuras.h"
#include "Registrar.h"

void elegirC(int posicao, registrarTreino *vTreinos, float *puntuacion, tipoEstudante vEstudante[MAX_ALUNOS], int quantidade, int nEstudante){
    int cantidad;
    float porcentage;

    cantidad = lerInteiro("Escolha o numero de perguntas:",4,10);
    switch(cantidad){
        case 4:
            pregunta_1C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_2C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_3C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_4C(posicao, vTreinos, &(*puntuacion), &porcentage);
            calculoNota(cantidad, posicao, *puntuacion, vTreinos);
            calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
            break;
        case 5:
            pregunta_1C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_2C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_3C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_4C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_5C(posicao, vTreinos, &(*puntuacion), &porcentage);
            calculoNota(cantidad, posicao, *puntuacion, vTreinos);
            calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
            break;
        case 6:
            pregunta_1C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_2C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_3C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_4C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_5C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_6C(posicao, vTreinos, &(*puntuacion), &porcentage);
            calculoNota(cantidad, posicao, *puntuacion, vTreinos);
            calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
            break;
        case 7:
            pregunta_1C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_2C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_3C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_4C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_5C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_6C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_7C(posicao, vTreinos, &(*puntuacion), &porcentage);
            calculoNota(cantidad, posicao, *puntuacion, vTreinos);
            calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
            break;
        case 8:
            pregunta_1C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_2C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_3C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_4C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_5C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_6C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_7C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_8C(posicao, vTreinos, &(*puntuacion), &porcentage);
            calculoNota(cantidad, posicao, *puntuacion, vTreinos);
            calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
            break;
        case 9:
            pregunta_1C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_2C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_3C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_4C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_5C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_6C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_7C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_8C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_9C(posicao, vTreinos, &(*puntuacion), &porcentage);
            calculoNota(cantidad, posicao, *puntuacion, vTreinos);
            calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
            break;
        case 10:
            pregunta_1C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_2C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_3C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_4C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_5C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_6C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_7C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_8C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_9C(posicao, vTreinos, &(*puntuacion), &porcentage);
            pregunta_10C(posicao,vTreinos, &(*puntuacion), &porcentage);
            calculoNota(cantidad, posicao, *puntuacion, vTreinos);
            calculoPorcentage(cantidad, posicao, porcentage, vTreinos, vEstudante, quantidade, nEstudante);
            break;
    }

     vTreinos[posicao].cantidadP = cantidad;
}

void pregunta_1C(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage) {
    int opcion;

    printf("\n- Qual destas opcaos nao e uma marca de automovil: \n");
    printf("(1) - Audi\n");
    printf("(2) - Ferrari\n");
    printf("(3) - Chevrolet\n");
    printf("(4) - Cherry\n");
    do{
    printf("Opcao -> ");
    scanf("%d",&opcion);

    if(opcion!= 1 && opcion!= 2 && opcion!= 3 && opcion!= 4){
           printf("OPCAO INVALIDA! \nPor favor insira uma opcao valida!\n\n");
    }
    } while(opcion!= 1 && opcion!= 2 && opcion!= 3 && opcion!= 4);

    if(opcion==4){
         (*puntuacion)++;
         (*porcentage)++;
    }
    else
      *puntuacion = *puntuacion - 0.25;

        vTreinos[i].pruebaC.pregunta1 = opcion;
}//fin de primera pregunta

void pregunta_2C(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage) {
    int opcion;


    printf("\n- Qual dessas e uma marca de refrigerante: \n");
    printf("(1) - Continente\n");
    printf("(2) - Imperial\n");
    printf("(3) - Coca-Cola\n");
    printf("(4) - IceTea\n");
    do{
    printf("Opcao -> ");
    scanf("%d",&opcion);

    //prueba.PruebaC = lerInteiro("Opcao -> ",1,4);
    if(opcion!= 1 && opcion!= 2 && opcion!= 3 && opcion!= 4){
           printf("OPCAO INVALIDA! \nPor favor insira uma opcao valida!\n\n");
    }
    } while(opcion!= 1 && opcion!= 2 && opcion!= 3 && opcion!= 4);

    if(opcion== 3){
        (*puntuacion)++;
        (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;
        //opcion =

    vTreinos[i].pruebaC.pregunta2 = opcion;
}//fin de segunda pregunta

void pregunta_3C(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage) {
    int opcion;

    printf("\n- Qual dessas e uma marca de telemovel: \n");
    printf("(1) - Honda\n");
    printf("(2) - Xiaomi\n");
    printf("(3) - Audi\n");
    printf("(4) - Imperial\n");
    printf("Opcao -> ");
    scanf("%d",&opcion);

    //prueba.PruebaC = lerInteiro("Opcao -> ",1,4);
    if(opcion!= 1 && opcion!= 2 && opcion!= 3 && opcion!= 4){
           printf("OPCAO INVALIDA! \nPor favor insira uma opcao valida!\n\n");
    }
     while(opcion!= 1 && opcion!= 2 && opcion!= 3 && opcion!= 4);

    if(opcion==2){
       (*puntuacion)++;
        (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;
        vTreinos[i].pruebaC.pregunta3 = opcion;
}//fin de tercera pregunta

void pregunta_4C(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage) {
    int opcion;


    printf("\n- Qual destes tem quatro rodas: \n");
    printf("(1) - Carro\n");
    printf("(2) - Motocicletas\n");
    printf("(3) - Aviao\n");
    printf("(4) - Bicicleta\n");
    do{
    printf("Opcao -> ");
    scanf("%d",&opcion);

    //prueba.PruebaC = lerInteiro("Opcao -> ",1,4);
    if(opcion!= 1 && opcion!= 2 && opcion!= 3 && opcion!= 4){
           printf("OPCAO INVALIDA! \nPor favor insira uma opcao valida!\n\n");
           }
    } while(opcion!= 1 && opcion!= 2 && opcion!= 3 && opcion!= 4);

    if(opcion==1){
        (*puntuacion)++;
        (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;
        //opcion =

    vTreinos[i].pruebaC.pregunta4 = opcion;
}//fin de cuarta pregunta

void pregunta_5C(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage) {
    int opcion;


    printf("\n- Qual classe nao tem numeros: \n");
    printf("(1) - Matematicas\n");
    printf("(2) - Fisica\n");
    printf("(3) - Algebra\n");
    printf("(4) - Historia\n");
    do{
    printf("Opcao -> ");
    scanf("%d",&opcion);

    //prueba.PruebaC = lerInteiro("Opcao -> ",1,4);
    if(opcion!= 1 && opcion!= 2 && opcion!= 3 && opcion!= 4){
           printf("OPCAO INVALIDA! \nPor favor insira uma opcao valida!\n\n");
    }
    } while(opcion!= 1 && opcion!= 2 && opcion!= 3 && opcion!= 4);

    if(opcion== 4){
          (*puntuacion)++;
        (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;
        //opcion =

    vTreinos[i].pruebaC.pregunta5 = opcion;
}//fin de quinta pregunta

void pregunta_6C(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage) {
    int opcion;

    printf("\n- Qual e uma cidade de Portugal: \n");
    printf("(1) - Madrid\n");
    printf("(2) - Londres\n");
    printf("(3) - Lisboa\n");
    printf("(4) - Paris\n");
    do{
    printf("Opcao -> ");
    scanf("%d",&opcion);

    //prueba.PruebaC = lerInteiro("Opcao -> ",1,4);
    if(opcion!= 1 && opcion!= 2 && opcion!= 3 && opcion!= 4){
           printf("OPCAO INVALIDA! \nPor favor insira uma opcao valida!\n\n");
    }
    } while(opcion!= 1 && opcion!= 2 && opcion!= 3 && opcion!= 4);

    if(opcion== 3){
           (*puntuacion)++;
           (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;
        //opcion =

    vTreinos[i].pruebaC.pregunta6 = opcion;
}//fin de sexta pregunta

void pregunta_7C(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
    int opcion;

    printf("\n- Qual nao e uma rede social: \n");
    printf("(1) - Youtube\n");
    printf("(2) - Facebook\n");
    printf("(3) - Instagram\n");
    printf("(4) - Twitter\n");
    do{
    printf("Opcao -> ");
    scanf("%d",&opcion);

    //prueba.PruebaC = lerInteiro("Opcao -> ",1,4);
    if(opcion!= 1 && opcion!= 2 && opcion!= 3 && opcion!= 4){
           printf("OPCAO INVALIDA! \nPor favor insira uma opcao valida!\n\n");
    }
    } while(opcion!= 1 && opcion!= 2 && opcion!= 3 && opcion!= 4);

    if(opcion== 1){
          (*puntuacion)++;
           (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;
        //opcion =

    vTreinos[i].pruebaC.pregunta7 = opcion;
}//fin de sexta pregunta

void pregunta_8C(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
    int opcion;


    printf("\n- Que nao e um videogame: \n");
    printf("(1) - League of Legends\n");
    printf("(2) - Windows\n");
    printf("(3) - Fruit Ninja\n");
    printf("(4) - Dota 2\n");
    do{
    printf("Opcao -> ");
    scanf("%d",&opcion);

    //prueba.PruebaC = lerInteiro("Opcao -> ",1,4);
    if(opcion!= 1 && opcion!= 2 && opcion!= 3 && opcion!= 4){
           printf("OPCAO INVALIDA! \nPor favor insira uma opcao valida!\n\n");
    }
    } while(opcion!= 1 && opcion!= 2 && opcion!= 3 && opcion!= 4);

    if(opcion==2){
            (*puntuacion)++;
           (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;
        //opcion =

    vTreinos[i].pruebaC.pregunta8 = opcion;
}//fin de sexta pregunta

void pregunta_9C(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
    int opcion;


    printf("\n- Que e uma marca de roupa: \n");
    printf("(1) - Coca-Cola\n");
    printf("(2) - Guinness\n");
    printf("(3) - IceTea\n");
    printf("(4) - Pull & Bear\n");
    do{
    printf("Opcao -> ");
    scanf("%d",&opcion);

    //prueba.PruebaC = lerInteiro("Opcao -> ",1,4);
    if(opcion!= 1 && opcion!= 2 && opcion!= 3 && opcion!= 4){
           printf("OPCAO INVALIDA! \nPor favor insira uma opcao valida!\n\n");
    }
    } while(opcion!= 1 && opcion!= 2 && opcion!= 3 && opcion!= 4);

    if(opcion== 4){
         (*puntuacion)++;
         (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;
        //opcion =

    vTreinos[i].pruebaC.pregunta9 = opcion;
}//fin de sexta pregunta

void pregunta_10C(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage){
    int opcion;

    printf("\n- Qual nao e um servico de telefono:\n");
    printf("(1) - Claro\n");
    printf("(2) - Vodafone\n");
    printf("(3) - WTF\n");
    printf("(4) - Meo\n");
    do{
    printf("Opcao -> ");
    scanf("%d",&opcion);
    if(opcion!= 1 && opcion!= 2 && opcion!= 3 && opcion!= 4){
           printf("OPCAO INVALIDA! \nPor favor insira uma opcao valida!\n\n");
    }
    } while(opcion!= 1 && opcion!= 2 && opcion!= 3 && opcion!= 4);

    if(opcion== 1){
          (*puntuacion)++;
          (*porcentage)++;
    }else
        *puntuacion = *puntuacion - 0.25;
        //opcion =

    vTreinos[i].pruebaC.pregunta10 = opcion;
//fin de sexta pregunta
}
