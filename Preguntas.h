#ifndef PREGUNTAS_H_INCLUDED
#define PREGUNTAS_H_INCLUDED

#include "Estructuras.h"

int procuraPregunta(int numero, regPreguntas preguntas[], int quantidade);

regPreguntas *registrarPregunta(regPreguntas *pregunta, int *totalPreguntas);
void mostrarPreguntas(regPreguntas preguntas[], int quantidade);
void localPregunta(int numero, regPreguntas pregunta[], int quantidade);
void alterarPregunta(int numero, regPreguntas pregunta[], int quantidade);
void imprimirPregunta(int quantidad, float *puntuacion, regPreguntas *pregunta);

void gravaBinarioPreguntas(regPreguntas preguntas[], int quantidade);
void leerBinarioPreguntas(regPreguntas preguntas[], int *quantidade);

#endif // PREGUNTAS_H_INCLUDED
