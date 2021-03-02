#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "Registrar.h"
#include "Basica.h"
#include "Constantes.h"
#include "Estudiantes.h"
#include "pTipoA.h"
#include "pTipoC.h"
#include "pTipoB.h"
#include "pTipoD.h"

int procuraTreino (registrarTreino vTreinos[], int quantTreinos, int codigo){
    int i, posicao=-1;

    for (i=0; i<quantTreinos; i++){
        if (vTreinos[i].codigo == codigo)
        {
            posicao = i;
            i=quantTreinos;
        }
    }
    return posicao;
}//procuraTreino

void LogTreinos(registrarTreino treino, int operacao){

    FILE *ficheiro;

    ficheiro = fopen("logTreino.txt","a");
    if (ficheiro == NULL)
    {
        perror("Erro na abertura do ficheiro.");
    }
    else
    {
        if (operacao == 1){
            fprintf(ficheiro, "\nCodigo do Treino: %d", treino.codigo);
                if(treino.tPrueba == 1)
                    fprintf(ficheiro, "\tTipo de prova.A");
                else{
                    if(treino.tPrueba == 2)
                        fprintf(ficheiro, "\tTipo de prova.B");
                    else{
                        if(treino.tPrueba == 3)
                            fprintf(ficheiro, "\tTipo de prova.C");
                        else
                            fprintf(ficheiro, "\tTipo de prova.D");
                    }
                }


            fprintf(ficheiro, "\nCodigo de Estudante: %d", treino.numEstudante);
            fprintf(ficheiro, "\nData Realisacao: %d-%d-%d\tHora Realisacao: %02i:%02i", treino.data.dia, treino.data.mes,
                   treino.data.ano,treino.hora.hora, treino.hora.minutos);

            if(treino.estado==2)
                fprintf(ficheiro, "\nEstado: Concluido");

                fprintf(ficheiro, "\nQuantidade de perguntas: %d", treino.cantidadP);
                fprintf(ficheiro, "\nPocentage de respostas correctas: %.2f%%", treino.porcentagem);

                fprintf(ficheiro, "\nNota do Treino: %.2f", treino.nota);
                fprintf(ficheiro, "\tTempo de Treino: %d min", treino.tempo);

            fprintf(ficheiro, "\n--------------------------------------------------------\n");
        }
        else
        {
            fprintf(ficheiro,"\n treino: %d eliminada \n ", treino.codigo);
        }
        fclose(ficheiro);
    }
}// FIM LogTreinos

registrarTreino *eliminarTreinoDin(int *totalTreinos, registrarTreino *vTreinos){
    int codigoEliminar, posicao=-1;
    registrarTreino *vTreinosBackup;
    vTreinosBackup = vTreinos;

    if (*totalTreinos==0){
        printf("\n\n ------ Nao existem Treinos ------\n\n");
    }
    else{
        printf("Qual o codigo do Treino a eliminar?\nCodigo -> ");
        scanf("%d", &codigoEliminar);
        posicao = procuraTreino(vTreinos, *totalTreinos, codigoEliminar);
        if (posicao == -1){
            printf("\n---- Nao existe treinos com o numero dado ----\n");
        }
        else
        {
            if(vTreinos[posicao].estado == 1){

                LogTreinos(vTreinos[posicao], 2);
                for (int i=posicao; i<(*totalTreinos-1); i++){
                    vTreinos[i] = vTreinos[i+1];
                }

                vTreinos = realloc(vTreinos, (*totalTreinos-1)*sizeof(registrarTreino));
                if(vTreinos == NULL && *totalTreinos!= 1){
                    printf("Erro ao alocar memoria\n");
                    vTreinos = vTreinosBackup;
                }
            else{
                (*totalTreinos)--;
            }

            }
            else{
                printf("\n---------- Nao se pode eliminar um treino concluido! ----------");
            }

        }
    }
    printf("\nTreino Eliminado!\n");
    limpaBufferStdin();

    return vTreinos;
}//FIM eliminarTreinoDin

void mostrarTreinos(registrarTreino treinos[], int quantidade){
    int i;

    if (quantidade == 0){
        printf("\n\n ------ Nao existem treinos ------\n\n");
    }
    else
    {
        printf("\n*************************************************************");
        printf("\n                    Lista de Treinos");
        printf("\n*************************************************************\n");
        for (i=0; i<quantidade; i++){
            printf("\n--------------------------------------------------------");
            printf("\nCodigo do Treino: %d", treinos[i].codigo);
            if(treinos[i].tPrueba == -1){
                //VOID
            }
            else{
                if(treinos[i].tPrueba == 1)
                    printf("\tTipo de prova.A");
                else{
                    if(treinos[i].tPrueba == 2)
                        printf("\tTipo de prova.B");
                    else{
                        if(treinos[i].tPrueba == 3)
                            printf("\tTipo de prova.C");
                        else
                            printf("\tTipo de prova.D");
                    }
                }

            }

            printf("\nCodigo de Estudante: %d", treinos[i].numEstudante);
            printf("\nData Realisacao: %d-%d-%d\tHora Realisacao: %02i:%02i", treinos[i].data.dia, treinos[i].data.mes,
                   treinos[i].data.ano,treinos[i].hora.hora, treinos[i].hora.minutos);

            if(treinos[i].estado==1)
                printf("\nEstado: Criado");
            else
                printf("\nEstado: Concluido");

            if(treinos[i].cantidadP==-1)
                printf("\nQuantidade de perguntas: *Treino sim Registrar*");
            else{
                printf("\nQuantidade de perguntas: %d", treinos[i].cantidadP);
                printf("\nPocentage de respostas correctas: %.2f%%", treinos[i].porcentagem);
            }

            if(treinos[i].nota==-1)
                printf("\nNota do Treino: *Treino sim Registrar*");
            else{
                printf("\nNota do Treino: %.2f", treinos[i].nota);
                printf("\tTempo de Treino: %d min", treinos[i].tempo);
            }
            printf("\n--------------------------------------------------------\n");
        }
    }

}//mostrarTreinos

registrarTreino *crearTreinoDim(registrarTreino *vTreinos, int *totalTreinos, tipoEstudante vEstudante[MAX_ALUNOS], int quantidade){
    int numero, posicao, i;
    registrarTreino *vTreinosBackup;
    vTreinosBackup = vTreinos;

    if (quantidade == 0){
        printf("Nao existem estudantes, logo nao podemos fazer Treinos\n");
    }
    else{
            printf("\n------ Criar treino -------\n");
            printf("Numero de registro %d \n", *totalTreinos+1);
            numero = lerInteiro("Indique o numero do estudante ", NUM_MIN_ALUNO, NUM_MAX_ALUNO);
            posicao = procuraEstudante(numero,vEstudante,quantidade);
            if(posicao==-1){
                printf("Nao existe estudante com o numero em causa\n");
            }
            else{
                vTreinos = realloc(vTreinos,(*totalTreinos+1)*sizeof(registrarTreino));
                if(vTreinos == NULL){
                    printf("Erro ao alocar memoria\n");
                    vTreinos = vTreinosBackup;
                }
                else{
                    vTreinos[*totalTreinos].numEstudante = numero;
                    if (*totalTreinos==0)
                    vTreinos[*totalTreinos].codigo = 1;
                    else
                    vTreinos[*totalTreinos].codigo = vTreinos[*totalTreinos-1].codigo+1;
                    vTreinos[*totalTreinos].nota = -1;
                    vTreinos[*totalTreinos].cantidadP = -1;
                    vTreinos[*totalTreinos].estado = 1;
                    vTreinos[*totalTreinos].tPrueba = -1;
                    printf("Data do Treino -> ");
                    vTreinos[*totalTreinos].porcentagem = 0;
                    vTreinos[*totalTreinos].data = lerData(2019,2020);
                    vTreinos[*totalTreinos].hora = lerHora(00, 23);

                    for (i=0; i<*totalTreinos+1; i++){
                        if(vEstudante[i].numero == vTreinos[*totalTreinos].numEstudante){
                            vEstudante[i].treinos.cantidadT++;
                        }
                    }

                    (*totalTreinos)++;
                }
            }

    }

    return vTreinos;
}//FIM criarTreinoDim()

void localTreino(int numero, registrarTreino treinos[], int quantidade){
    int i, posicao=-1;

    if(quantidade != 0){
        posicao = procuraTreino(treinos, quantidade, numero);
        if(posicao == -1){
            printf("\n****** Este aluno noa ha feito nenhum treino! ******");
        }
        else{
            for(i=0; i<quantidade; i++){
                if (numero==treinos[i].numEstudante){
                printf("\n----------------- Codigo do Treino: %d -----------------\n", treinos[i].codigo);

                printf("\nCodigo de Estudante: %d", treinos[i].numEstudante);
                printf("\nData Realisacao: %d-%d-%d\tHora Realisacao: %02i:%02i", treinos[i].data.dia, treinos[i].data.mes,
                   treinos[i].data.ano,treinos[i].hora.hora, treinos[i].hora.minutos);

                if(treinos[i].estado==1)
                    printf("\nEstado: Criado");
                else
                    printf("\nEstado: Concluido");

                if(treinos[i].cantidadP==-1)
                    printf("\nQuantidade de perguntas: *Treino sim Registrar*");
                else{
                    printf("\nQuantidade de perguntas: %d", treinos[i].cantidadP);
                    printf("\nPocentage de respostas correctas: %.2f%%", treinos[i].porcentagem);
                }

                if(treinos[i].nota==-1)
                    printf("\nNota do Treino: *Treino sim Registrar*");
                else{
                    printf("\nNota do Treino: %.2f", treinos[i].nota);
                    printf("\tTempo de Treino: %d min", treinos[i].tempo);
                }
                printf("\n--------------------------------------------------------\n");
                }
            }
        }
    }
}//FIM localTreino()

void regTreino(int numero, registrarTreino vTreinos[], int quantidade, tipoEstudante vEstudante[MAX_ALUNOS], regPreguntas pregunta[], int totalPreguntas){
    int posicao;
    int i, nEstudante;
    float puntuacion = 0;

    if(quantidade != 0){
        posicao = procuraTreino(vTreinos, quantidade, numero);
        if(posicao == -1){
            printf("\n****** Nao existe um treino com ese codigo ******");
        }
        else{
            for(i=0; i<quantidade; i++){
                if(vTreinos[i].codigo == numero){
                    if(vTreinos[i].estado == 1){
                        nEstudante = vTreinos[i].numEstudante;
                        vTreinos[i].tPrueba = lerInteiro("Indique tipo de prova: \nProva.A (1), Prova.B (2), Prova.C (3) ou Prova.D (4): ", 1, 4);

                        switch(vTreinos[i].tPrueba){
                            case 1:
                                elegirA(i, vTreinos, &puntuacion, vEstudante, quantidade, nEstudante);
                                break;
                            case 2:
                                elegirB(i, vTreinos, &puntuacion, vEstudante, quantidade, nEstudante);
                                break;
                            case 3:
                                elegirC(i, vTreinos, &puntuacion, vEstudante, quantidade, nEstudante);
                                break;
                            case 4:
                                elegirD(i, vTreinos, &puntuacion, vEstudante, quantidade, nEstudante, pregunta, totalPreguntas);
                                break;
                        }

                        printf("\nNumero de perguntas escolhidas: %d", vTreinos[i].cantidadP);
                        printf("\nNota de test: %.2f", vTreinos[i].nota);

                        vTreinos[i].tempo = lerInteiro("\n\nIndicar o tempo que levou para fazer o Treino:", 01, 60);
                        vTreinos[i].estado = 2;

                        LogTreinos(vTreinos[i], 1);

                        printf("\nTreino registrado!! (Pulsa Enter)");
                    }
                    else{
                    printf("\nO Treino indicado ja esta conlcuido!!\n");
                    }
                }
            }
        }
    }
    else{
        printf("\n Nao ha treinos criados!!!\n");
    }
}

void calculoNota(int totalPreguntas, int numero, float puntaje, registrarTreino *vTreinos){
    float total = 0;

    total = (puntaje*20)/totalPreguntas;
    if(total < 0){
        vTreinos[numero].nota = 0;
    }
    else{
        vTreinos[numero].nota = total;
    }
}

void calculoPorcentage(int totalPreguntas, int numero, float porcentage, registrarTreino *vTreinos, tipoEstudante vEstudante[MAX_ALUNOS], int quantidade, int nEstudante){
    float total = 0, parcial = 0;
    int i;

    parcial = (porcentage*100)/totalPreguntas;

    for(i=0; i<quantidade; i++){
        if(vTreinos[numero].codigo == vTreinos[i].codigo){
            vTreinos[i].porcentagem = parcial;
        }
    }
    total = totalPorcentage(vTreinos, vEstudante, quantidade, nEstudante);
    vEstudante[nEstudante-1].porcentagem = total;
}

float totalPorcentage(registrarTreino *vTreinos, tipoEstudante vEstudante[MAX_ALUNOS], int quantidade, int nEstudante){
    float porcentageTotal = 0, porcentageParcial = 0, porcentage = 0;
    int i;

    for(i=0; i<quantidade; i++){
            if(nEstudante == vTreinos[i].numEstudante){
                porcentage = vTreinos[i].porcentagem;
                porcentageParcial = porcentageParcial + porcentage;
            }
    }
    porcentageTotal = porcentageParcial/vEstudante[nEstudante-1].treinos.cantidadT;

    return porcentageTotal;
}

void gravaFicheiroTreinos_Binario(registrarTreino vTreinos[], int totalTreinos){
    FILE *ficheiro;
    int escrito;

    ficheiro =fopen("Treinos.dat","wb");

    if (ficheiro == NULL){
        printf("\nErro ao abrir o ficheiro\n");
    }
    else
    {
        escrito = fwrite(&totalTreinos, sizeof(int),1,ficheiro);
        if (escrito!=1)
        {
            printf("Erro ao escrever a quantidade de reservas\n");
        }
        else
        {
            escrito = fwrite(&vTreinos, sizeof(registrarTreino), totalTreinos, ficheiro);
            if (escrito!=totalTreinos)
            {
                printf("Erro ao escrever info das reservas\n");
            }
            else
                printf("\nGravado com sucesso\n");
        }
        fflush(ficheiro);
        fclose(ficheiro);
    }

}

void leFicheiroTreinos_Binario(registrarTreino vTreinos[], int *totalTreinos){
    FILE *ficheiro;
    int lido;

    *totalTreinos = 0;

    ficheiro =fopen("Treinos.dat","rb");

    if (ficheiro == NULL){
        printf("Erro ao abrir o ficheiro\n");

    }
    else{//abriu ficheiro com sucesso
        lido = fread(totalTreinos, sizeof(int),1,ficheiro);
        if (lido!=1){
            printf("Erro ao ler a quantidade de reservas\n");
            *totalTreinos = 0;
        }
        else{
            lido = fread(&vTreinos, sizeof(registrarTreino),*totalTreinos, ficheiro);
            if (lido!=(*totalTreinos)){
                printf("\nErro ao ler a info das reservas\n");
                *totalTreinos = 0;
            }
        }
        fclose(ficheiro);
    }
}

void consultarResul(int numero, registrarTreino treinos[], int quantidade, regPreguntas pregunta[]){
    int i, posicao=-1, t;
    int puntero = 5;

    if(quantidade != 0){
        posicao = procuraTreino(treinos, quantidade, numero);
        if(posicao == -1){
            printf("\n****** Nao ha nengum treino com ese codigo! ******");
        }
        else{
            for(i=0; i<quantidade; i++){
                if (numero==treinos[i].codigo){
                    if(treinos[i].estado == 2){
                        printf("\n----------------- Codigo do Treino: %d -----------------\n", treinos[i].codigo);
                        printf("\nCodigo de Estudante: %d", treinos[i].numEstudante);
                        if(treinos[i].tPrueba == 1)
                            printf("\nTipo de Prova A");
                        else{
                            if(treinos[i].tPrueba == 2)
                                printf("\nTipo de Prova B");
                            else
                                printf("\nTipo de Prova C");
                        }
                        printf("\nQuantidad de preguntas do treino: %d\n", treinos[i].cantidadP);

                        if(treinos[i].tPrueba == 1){
                            switch(treinos[i].cantidadP){
                                case 4:
                                    printf("\n Resposta pergunta 1: %d (Resposta correcta: 3)", treinos[i].pruebaA.pregunta1);
                                    printf("\n Resposta pergunta 2: %d (Resposta correcta: 1)", treinos[i].pruebaA.pregunta2);
                                    printf("\n Resposta pergunta 3: %d (Resposta correcta: 3)", treinos[i].pruebaA.pregunta3);
                                    printf("\n Resposta pergunta 4: %d (Resposta correcta: 2)", treinos[i].pruebaA.pregunta4);
                                    break;
                                case 5:
                                    printf("\n Resposta pergunta 1: %d (Resposta correcta: 3)", treinos[i].pruebaA.pregunta1);
                                    printf("\n Resposta pergunta 2: %d (Resposta correcta: 1)", treinos[i].pruebaA.pregunta2);
                                    printf("\n Resposta pergunta 3: %d (Resposta correcta: 3)", treinos[i].pruebaA.pregunta3);
                                    printf("\n Resposta pergunta 4: %d (Resposta correcta: 2)", treinos[i].pruebaA.pregunta4);
                                    printf("\n Resposta pergunta 5: %d (Resposta correcta: 4)", treinos[i].pruebaA.pregunta5);
                                    break;
                                case 6:
                                    printf("\n Resposta pergunta 1: %d (Resposta correcta: 3)", treinos[i].pruebaA.pregunta1);
                                    printf("\n Resposta pergunta 2: %d (Resposta correcta: 1)", treinos[i].pruebaA.pregunta2);
                                    printf("\n Resposta pergunta 3: %d (Resposta correcta: 3)", treinos[i].pruebaA.pregunta3);
                                    printf("\n Resposta pergunta 4: %d (Resposta correcta: 2)", treinos[i].pruebaA.pregunta4);
                                    printf("\n Resposta pergunta 5: %d (Resposta correcta: 4)", treinos[i].pruebaA.pregunta5);
                                    printf("\n Resposta pergunta 6: %d (Resposta correcta: 4)", treinos[i].pruebaA.pregunta6);
                                    break;
                                case 7:
                                    printf("\n Resposta pergunta 1: %d (Resposta correcta: 3)", treinos[i].pruebaA.pregunta1);
                                    printf("\n Resposta pergunta 2: %d (Resposta correcta: 1)", treinos[i].pruebaA.pregunta2);
                                    printf("\n Resposta pergunta 3: %d (Resposta correcta: 3)", treinos[i].pruebaA.pregunta3);
                                    printf("\n Resposta pergunta 4: %d (Resposta correcta: 2)", treinos[i].pruebaA.pregunta4);
                                    printf("\n Resposta pergunta 5: %d (Resposta correcta: 4)", treinos[i].pruebaA.pregunta5);
                                    printf("\n Resposta pergunta 6: %d (Resposta correcta: 4)", treinos[i].pruebaA.pregunta6);
                                    printf("\n Resposta pergunta 7: %d (Resposta correcta: 4)", treinos[i].pruebaA.pregunta7);
                                    break;
                                case 8:
                                    printf("\n Resposta pergunta 1: %d (Resposta correcta: 3)", treinos[i].pruebaA.pregunta1);
                                    printf("\n Resposta pergunta 2: %d (Resposta correcta: 1)", treinos[i].pruebaA.pregunta2);
                                    printf("\n Resposta pergunta 3: %d (Resposta correcta: 3)", treinos[i].pruebaA.pregunta3);
                                    printf("\n Resposta pergunta 4: %d (Resposta correcta: 2)", treinos[i].pruebaA.pregunta4);
                                    printf("\n Resposta pergunta 5: %d (Resposta correcta: 4)", treinos[i].pruebaA.pregunta5);
                                    printf("\n Resposta pergunta 1: %d (Resposta correcta: 4)", treinos[i].pruebaA.pregunta6);
                                    printf("\n Resposta pergunta 2: %d (Resposta correcta: 4)", treinos[i].pruebaA.pregunta7);
                                    printf("\n Resposta pergunta 3: %d (Resposta correcta: 3)", treinos[i].pruebaA.pregunta8);
                                    break;
                                case 9:
                                    printf("\n Resposta pergunta 1: %d (Resposta correcta: 3)", treinos[i].pruebaA.pregunta1);
                                    printf("\n Resposta pergunta 2: %d (Resposta correcta: 1)", treinos[i].pruebaA.pregunta2);
                                    printf("\n Resposta pergunta 3: %d (Resposta correcta: 3)", treinos[i].pruebaA.pregunta3);
                                    printf("\n Resposta pergunta 4: %d (Resposta correcta: 2)", treinos[i].pruebaA.pregunta4);
                                    printf("\n Resposta pergunta 5: %d (Resposta correcta: 4)", treinos[i].pruebaA.pregunta5);
                                    printf("\n Resposta pergunta 6: %d (Resposta correcta: 4)", treinos[i].pruebaA.pregunta6);
                                    printf("\n Resposta pergunta 7: %d (Resposta correcta: 4)", treinos[i].pruebaA.pregunta7);
                                    printf("\n Resposta pergunta 8: %d (Resposta correcta: 3)", treinos[i].pruebaA.pregunta8);
                                    printf("\n Resposta pergunta 9: %d (Resposta correcta: 3)", treinos[i].pruebaA.pregunta9);
                                    break;
                                case 10:
                                    printf("\n Resposta pergunta 1: %d (Resposta correcta: 3)", treinos[i].pruebaA.pregunta1);
                                    printf("\n Resposta pergunta 2: %d (Resposta correcta: 1)", treinos[i].pruebaA.pregunta2);
                                    printf("\n Resposta pergunta 3: %d (Resposta correcta: 3)", treinos[i].pruebaA.pregunta3);
                                    printf("\n Resposta pergunta 4: %d (Resposta correcta: 2)", treinos[i].pruebaA.pregunta4);
                                    printf("\n Resposta pergunta 5: %d (Resposta correcta: 4)", treinos[i].pruebaA.pregunta5);
                                    printf("\n Resposta pergunta 6: %d (Resposta correcta: 4)", treinos[i].pruebaA.pregunta6);
                                    printf("\n Resposta pergunta 7: %d (Resposta correcta: 4)", treinos[i].pruebaA.pregunta7);
                                    printf("\n Resposta pergunta 8: %d (Resposta correcta: 3)", treinos[i].pruebaA.pregunta8);
                                    printf("\n Resposta pergunta 9: %d (Resposta correcta: 3)", treinos[i].pruebaA.pregunta9);
                                    printf("\n Resposta pergunta 10: %d (Resposta correcta: 3)", treinos[i].pruebaA.pregunta10);
                                    break;
                            }
                        }
                        else{
                            if(treinos[i].tPrueba == 2){
                                switch(treinos[i].cantidadP){
                                case 4:
                                    printf("\n Resposta pergunta 2: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta2);
                                    printf("\n Resposta pergunta 3: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta3);
                                    printf("\n Resposta pergunta 1: %d (Resposta correcta: 4)", treinos[i].pruebaB.pregunta1);
                                    printf("\n Resposta pergunta 4: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta4);
                                    break;
                                case 5:
                                    printf("\n Resposta pergunta 1: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta1);
                                    printf("\n Resposta pergunta 2: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta2);
                                    printf("\n Resposta pergunta 3: %d (Resposta correcta: 4)", treinos[i].pruebaB.pregunta3);
                                    printf("\n Resposta pergunta 4: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta4);
                                    printf("\n Resposta pergunta 5: %d (Resposta correcta: 4)", treinos[i].pruebaB.pregunta5);
                                    break;
                                case 6:
                                    printf("\n Resposta pergunta 1: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta1);
                                    printf("\n Resposta pergunta 2: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta2);
                                    printf("\n Resposta pergunta 3: %d (Resposta correcta: 4)", treinos[i].pruebaB.pregunta3);
                                    printf("\n Resposta pergunta 4: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta4);
                                    printf("\n Resposta pergunta 5: %d (Resposta correcta: 4)", treinos[i].pruebaB.pregunta5);
                                    printf("\n Resposta pergunta 6: %d (Resposta correcta: 4)", treinos[i].pruebaB.pregunta6);
                                    break;
                                case 7:
                                    printf("\n Resposta pergunta 1: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta1);
                                    printf("\n Resposta pergunta 2: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta2);
                                    printf("\n Resposta pergunta 3: %d (Resposta correcta: 4)", treinos[i].pruebaB.pregunta3);
                                    printf("\n Resposta pergunta 4: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta4);
                                    printf("\n Resposta pergunta 5: %d (Resposta correcta: 4)", treinos[i].pruebaB.pregunta5);
                                    printf("\n Resposta pergunta 6: %d (Resposta correcta: 4)", treinos[i].pruebaB.pregunta6);
                                    printf("\n Resposta pergunta 7: %d (Resposta correcta: 1)", treinos[i].pruebaB.pregunta7);
                                    break;
                                case 8:
                                    printf("\n Resposta pergunta 1: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta1);
                                    printf("\n Resposta pergunta 2: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta2);
                                    printf("\n Resposta pergunta 3: %d (Resposta correcta: 4)", treinos[i].pruebaB.pregunta3);
                                    printf("\n Resposta pergunta 4: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta4);
                                    printf("\n Resposta pergunta 5: %d (Resposta correcta: 4)", treinos[i].pruebaB.pregunta5);
                                    printf("\n Resposta pergunta 1: %d (Resposta correcta: 4)", treinos[i].pruebaB.pregunta6);
                                    printf("\n Resposta pergunta 2: %d (Resposta correcta: 1)", treinos[i].pruebaB.pregunta7);
                                    printf("\n Resposta pergunta 3: %d (Resposta correcta: 1)", treinos[i].pruebaB.pregunta8);
                                    break;
                                case 9:
                                    printf("\n Resposta pergunta 1: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta1);
                                    printf("\n Resposta pergunta 2: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta2);
                                    printf("\n Resposta pergunta 3: %d (Resposta correcta: 4)", treinos[i].pruebaB.pregunta3);
                                    printf("\n Resposta pergunta 4: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta4);
                                    printf("\n Resposta pergunta 5: %d (Resposta correcta: 4)", treinos[i].pruebaB.pregunta5);
                                    printf("\n Resposta pergunta 1: %d (Resposta correcta: 4)", treinos[i].pruebaB.pregunta6);
                                    printf("\n Resposta pergunta 2: %d (Resposta correcta: 1)", treinos[i].pruebaB.pregunta7);
                                    printf("\n Resposta pergunta 3: %d (Resposta correcta: 1)", treinos[i].pruebaB.pregunta8);
                                    printf("\n Resposta pergunta 4: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta9);
                                    break;
                                case 10:
                                    printf("\n Resposta pergunta 1: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta1);
                                    printf("\n Resposta pergunta 2: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta2);
                                    printf("\n Resposta pergunta 3: %d (Resposta correcta: 4)", treinos[i].pruebaB.pregunta3);
                                    printf("\n Resposta pergunta 4: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta4);
                                    printf("\n Resposta pergunta 5: %d (Resposta correcta: 4)", treinos[i].pruebaB.pregunta5);
                                    printf("\n Resposta pergunta 6: %d (Resposta correcta: 4)", treinos[i].pruebaB.pregunta6);
                                    printf("\n Resposta pergunta 7: %d (Resposta correcta: 1)", treinos[i].pruebaB.pregunta7);
                                    printf("\n Resposta pergunta 8: %d (Resposta correcta: 1)", treinos[i].pruebaB.pregunta8);
                                    printf("\n Resposta pergunta 9: %d (Resposta correcta: 3)", treinos[i].pruebaB.pregunta9);
                                    printf("\n Resposta pergunta 10: %d (Resposta correcta: 1)", treinos[i].pruebaB.pregunta10);
                                    break;
                                }
                            }
                            else{
                                if(treinos[i].tPrueba == 3)
                                    switch(treinos[i].cantidadP){
                                    case 4:
                                        printf("\n Resposta pergunta 2: %d (Resposta correcta: 4)", treinos[i].pruebaC.pregunta2);
                                        printf("\n Resposta pergunta 3: %d (Resposta correcta: 3)", treinos[i].pruebaC.pregunta3);
                                        printf("\n Resposta pergunta 1: %d (Resposta correcta: 2)", treinos[i].pruebaC.pregunta1);
                                        printf("\n Resposta pergunta 4: %d (Resposta correcta: 1)", treinos[i].pruebaC.pregunta4);
                                        break;
                                    case 5:
                                        printf("\n Resposta pergunta 1: %d (Resposta correcta: 4)", treinos[i].pruebaC.pregunta1);
                                        printf("\n Resposta pergunta 2: %d (Resposta correcta: 3)", treinos[i].pruebaC.pregunta2);
                                        printf("\n Resposta pergunta 3: %d (Resposta correcta: 2)", treinos[i].pruebaC.pregunta3);
                                        printf("\n Resposta pergunta 4: %d (Resposta correcta: 1)", treinos[i].pruebaC.pregunta4);
                                        printf("\n Resposta pergunta 5: %d (Resposta correcta: 4)", treinos[i].pruebaC.pregunta5);
                                        break;
                                    case 6:
                                        printf("\n Resposta pergunta 1: %d (Resposta correcta: 4)", treinos[i].pruebaC.pregunta1);
                                        printf("\n Resposta pergunta 2: %d (Resposta correcta: 3)", treinos[i].pruebaC.pregunta2);
                                        printf("\n Resposta pergunta 3: %d (Resposta correcta: 2)", treinos[i].pruebaC.pregunta3);
                                        printf("\n Resposta pergunta 4: %d (Resposta correcta: 1)", treinos[i].pruebaC.pregunta4);
                                        printf("\n Resposta pergunta 5: %d (Resposta correcta: 4)", treinos[i].pruebaC.pregunta5);
                                        printf("\n Resposta pergunta 6: %d (Resposta correcta: 3)", treinos[i].pruebaC.pregunta6);
                                        break;
                                    case 7:
                                        printf("\n Resposta pergunta 1: %d (Resposta correcta: 4)", treinos[i].pruebaC.pregunta1);
                                        printf("\n Resposta pergunta 2: %d (Resposta correcta: 3)", treinos[i].pruebaC.pregunta2);
                                        printf("\n Resposta pergunta 3: %d (Resposta correcta: 2)", treinos[i].pruebaC.pregunta3);
                                        printf("\n Resposta pergunta 4: %d (Resposta correcta: 1)", treinos[i].pruebaC.pregunta4);
                                        printf("\n Resposta pergunta 5: %d (Resposta correcta: 4)", treinos[i].pruebaC.pregunta5);
                                        printf("\n Resposta pergunta 6: %d (Resposta correcta: 3)", treinos[i].pruebaC.pregunta6);
                                        printf("\n Resposta pergunta 7: %d (Resposta correcta: 1)", treinos[i].pruebaC.pregunta7);
                                        break;
                                    case 8:
                                        printf("\n Resposta pergunta 1: %d (Resposta correcta: 4)", treinos[i].pruebaC.pregunta1);
                                        printf("\n Resposta pergunta 2: %d (Resposta correcta: 3)", treinos[i].pruebaC.pregunta2);
                                        printf("\n Resposta pergunta 3: %d (Resposta correcta: 2)", treinos[i].pruebaC.pregunta3);
                                        printf("\n Resposta pergunta 4: %d (Resposta correcta: 1)", treinos[i].pruebaC.pregunta4);
                                        printf("\n Resposta pergunta 5: %d (Resposta correcta: 4)", treinos[i].pruebaC.pregunta5);
                                        printf("\n Resposta pergunta 1: %d (Resposta correcta: 3)", treinos[i].pruebaC.pregunta6);
                                        printf("\n Resposta pergunta 2: %d (Resposta correcta: 1)", treinos[i].pruebaC.pregunta7);
                                        printf("\n Resposta pergunta 3: %d (Resposta correcta: 2)", treinos[i].pruebaC.pregunta8);
                                        break;
                                    case 9:
                                        printf("\n Resposta pergunta 1: %d (Resposta correcta: 4)", treinos[i].pruebaC.pregunta1);
                                        printf("\n Resposta pergunta 2: %d (Resposta correcta: 3)", treinos[i].pruebaC.pregunta2);
                                        printf("\n Resposta pergunta 3: %d (Resposta correcta: 2)", treinos[i].pruebaC.pregunta3);
                                        printf("\n Resposta pergunta 4: %d (Resposta correcta: 1)", treinos[i].pruebaC.pregunta4);
                                        printf("\n Resposta pergunta 5: %d (Resposta correcta: 4)", treinos[i].pruebaC.pregunta5);
                                        printf("\n Resposta pergunta 1: %d (Resposta correcta: 3)", treinos[i].pruebaC.pregunta6);
                                        printf("\n Resposta pergunta 2: %d (Resposta correcta: 1)", treinos[i].pruebaC.pregunta7);
                                        printf("\n Resposta pergunta 3: %d (Resposta correcta: 2)", treinos[i].pruebaC.pregunta8);
                                        printf("\n Resposta pergunta 4: %d (Resposta correcta: 4)", treinos[i].pruebaC.pregunta9);
                                        break;
                                    case 10:
                                        printf("\n Resposta pergunta 1: %d (Resposta correcta: 4)", treinos[i].pruebaC.pregunta1);
                                        printf("\n Resposta pergunta 2: %d (Resposta correcta: 3)", treinos[i].pruebaC.pregunta2);
                                        printf("\n Resposta pergunta 3: %d (Resposta correcta: 2)", treinos[i].pruebaC.pregunta3);
                                        printf("\n Resposta pergunta 4: %d (Resposta correcta: 1)", treinos[i].pruebaC.pregunta4);
                                        printf("\n Resposta pergunta 5: %d (Resposta correcta: 4)", treinos[i].pruebaC.pregunta5);
                                        printf("\n Resposta pergunta 6: %d (Resposta correcta: 3)", treinos[i].pruebaC.pregunta6);
                                        printf("\n Resposta pergunta 7: %d (Resposta correcta: 1)", treinos[i].pruebaC.pregunta7);
                                        printf("\n Resposta pergunta 8: %d (Resposta correcta: 2)", treinos[i].pruebaC.pregunta8);
                                        printf("\n Resposta pergunta 9: %d (Resposta correcta: 4)", treinos[i].pruebaC.pregunta9);
                                        printf("\n Resposta pergunta 10: %d (Resposta correcta: 1)", treinos[i].pruebaC.pregunta10);
                                        break;
                                }
                                else{
                                    printf("\n Resposta pergunta 1: %d", treinos[i].pruebaD.pregunta1);
                                    printf("\n Resposta pergunta 2: %d", treinos[i].pruebaD.pregunta2);
                                    printf("\n Resposta pergunta 3: %d", treinos[i].pruebaD.pregunta3);
                                    printf("\n Resposta pergunta 4: %d", treinos[i].pruebaD.pregunta4);
                                    for(t=0; t<treinos[i].cantidadP; t++){
                                        if(pregunta[t].respuestas > 0 && pregunta[t].respuestas <= 4){
                                            printf("\n Resposta pergunta %d: %d", puntero, pregunta[t].respuestas);
                                            puntero++;
                                        }
                                    }
                                }
                        }
                    }
                    }
                    else{
                        printf("\n********* Treino nao concluido! *********");
                    }
                }
            }
        }
    }

}

int treinosRealizados(registrarTreino treinos[], int quantidade){
    int i;
    int total = 0;

    for(i=0; i<quantidade; i++){
        if(treinos[i].estado == 2){
            total++;
        }
    }

   printf("Treinos realizados: %d\n", total);

   return total;
}

void treinosDecorrer(registrarTreino treinos[], int quantidade){
    int i, f;
    int criado = 0, concluidos = 0;

    for(i=0; i<quantidade; i++){
        if(treinos[i].estado == 1){
            criado++;
        }
    }

    for(f=0; f<quantidade; f++){
        if(treinos[f].estado == 2){
            concluidos++;
        }
    }

    if(criado - concluidos < 0)
        printf("Quantidade de treinos a decorrer: 0\n");
    else
        printf("Quantidade de treinos a decorrer: %d\n", criado - concluidos);
}
