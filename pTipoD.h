#ifndef PTIPOD_H_INCLUDED
#define PTIPOD_H_INCLUDED

void elegirD(int posicao, registrarTreino *vTreinos, float *puntuacion, tipoEstudante vEstudante[MAX_ALUNOS], int quantidade, int nEstudante, regPreguntas *pregunta, int totalPreguntas);

void pregunta_1D(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage);
void pregunta_2D(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage);
void pregunta_3D(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage);
void pregunta_4D(int i, registrarTreino *vTreinos, float *puntuacion, float *porcentage);

#endif // PTIPOD_H_INCLUDED
