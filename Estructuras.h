#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

#include "Constantes.h"

typedef struct{
    int dia, mes, ano;
}tipoData;

typedef struct{
    int pregunta1;
    int pregunta2;
    int pregunta3;
    int pregunta4;
    int pregunta5;
    int pregunta6;
    int pregunta7;
    int pregunta8;
    int pregunta9;
    int pregunta10;
}tipoPreguntas;

typedef struct{
    int hora, minutos;
}tipoHora;

typedef struct{
    int codigo;
    int numEstudante;
    float nota;
    tipoData data;
    tipoHora hora;
    int cantidadT;
    int tempo;
    int estado;
    int tPrueba;
    int cantidadP;
    tipoPreguntas pruebaA;
    tipoPreguntas pruebaB;
    tipoPreguntas pruebaC;
    tipoPreguntas pruebaD;
    float porcentagem;
}registrarTreino;

typedef struct{
    int numero;
    char nome[MAX_STRING];
    int tipo;
    int regime;
    int turno;
    registrarTreino treinos;
    float porcentagem;
}tipoEstudante;

typedef struct{
    int codigo;
    int tipoPrueba;
    char enunciado[MAX_STRING];
    char opcao1[MAX_STRING];
    char opcao2[MAX_STRING];
    char opcao3[MAX_STRING];
    char opcao4[MAX_STRING];
    int correcta;
    int cantidad;
    int respuestas;
    float porcentage;
}regPreguntas;

#endif // ESTRUCTURAS_H_INCLUDED
