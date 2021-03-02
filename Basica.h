#ifndef BASICA_H_INCLUDED
#define BASICA_H_INCLUDED

#include "Constantes.h"
#include "Estructuras.h"

void limpaBufferStdin(void);
void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres);
tipoData lerData(int ano_min, int ano_max);
tipoHora lerHora(int hora_min, int hora_max);
void ranking(registrarTreino *vTreino, int totalTreinos);
void mostrarRankin(registrarTreino *vTreino, int totalTreinos);

int procurData(registrarTreino vTreinos[], int quantTreinos, tipoData data);
void estadisticoData(registrarTreino treinos[], int quantidade);
void porProva(registrarTreino treinos[], int quantidade);
void tiempoMedio(registrarTreino treinos[], int quantidade);

#endif // BASICA_H_INCLUDED
