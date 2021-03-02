#ifndef REGISTRAR_H_INCLUDED
#define REGISTRAR_H_INCLUDED

#include "Estudiantes.h"

int procuraTreino (registrarTreino vTreinos[], int quantTreinos, int codigo);
registrarTreino *crearTreinoDim(registrarTreino *vReservas, int *totalReservas, tipoEstudante vEstudante[MAX_ALUNOS], int quantidade);
void LogTreinos(registrarTreino treino, int operacao);
void mostrarTreinos(registrarTreino treinos[], int quantidade);
registrarTreino *eliminarTreinoDin(int *totalTreinos, registrarTreino *vTreinos);
void localTreino(int numero, registrarTreino vTreinos[], int quantidade);
void regTreino(int numero, registrarTreino vTreinos[], int quantidade, tipoEstudante vEstudante[MAX_ALUNOS], regPreguntas pregunta[], int totalPreguntas);
void calculoNota(int totalPreguntas, int numero, float puntaje, registrarTreino *vTreinos);
void calculoPorcentage(int totalPreguntas, int numero, float porcentage, registrarTreino *vTreinos, tipoEstudante vEstudante[MAX_ALUNOS], int quantidade, int nEstudante);
float totalPorcentage(registrarTreino *vTreinos, tipoEstudante vEstudante[MAX_ALUNOS], int quantidade, int nEstudante);

void gravaFicheiroTreinos_Binario(registrarTreino vTreinos[], int totalTreinos);
void leFicheiroTreinos_Binario(registrarTreino vTreinos[], int *totalTreinos);

void consultarResul(int numero, registrarTreino treinos[], int quantidade, regPreguntas pregunta[]);

int treinosRealizados(registrarTreino treinos[], int quantidade);
void treinosDecorrer(registrarTreino treinos[], int quantidade);

#endif // REGISTRAR_H_INCLUDED
