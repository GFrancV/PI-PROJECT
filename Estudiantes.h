#ifndef ESTUDIANTES_H_INCLUDED
#define ESTUDIANTES_H_INCLUDED

#include "Estructuras.h"

tipoEstudante leerDatosEstudiantes(int quantidade);

void agregarEstudiantes(tipoEstudante vEstudantes[MAX_ALUNOS], int *quantidade);
void mostrarDados(tipoEstudante vetorEstudantes[MAX_ALUNOS], int quantidadeAvaliados);

int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo);

int procuraEstudante(int numero, tipoEstudante vEstudantes[MAX_ALUNOS], int quantidade);
void localEstudante(int numero, tipoEstudante vEstudantes[MAX_ALUNOS], int quantidade);
void alterarEstudante(int numero, tipoEstudante vEstudantes[MAX_ALUNOS], int quantidade);

void gravaFicheiroBinario(tipoEstudante vEstudante[MAX_ALUNOS], int quantidade);
void leFicheiroBinario(tipoEstudante vEstudante[MAX_ALUNOS], int *quantidade);

#endif // ESTUDIANTES_H_INCLUDED
