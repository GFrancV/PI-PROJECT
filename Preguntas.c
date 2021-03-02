#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "Registrar.h"
#include "Basica.h"
#include "Constantes.h"
#include "Estudiantes.h"

int procuraPregunta(int numero, regPreguntas preguntas[], int quantidade){
    int i, posicao=-1;

    for(i=0; i<quantidade; i++){
        if (numero==preguntas[i].codigo){
            posicao = i;
            i=quantidade;
        }
    }
    return posicao;
}

regPreguntas *registrarPregunta(regPreguntas *pregunta, int *totalPreguntas){
    regPreguntas *preguntaBackup;
    preguntaBackup = pregunta;

    if(*totalPreguntas >= MAX_REGPREGUNTAS){
        printf("\n********** Peguntas maximas registradas! **********\n");
    }
    else{
        printf("\n------ Registrar Pergunta -------\n");

        pregunta = realloc(pregunta,(*totalPreguntas+1)*sizeof(regPreguntas));
        if(pregunta == NULL){
            printf("Erro ao alocar memoria\n");
            pregunta = preguntaBackup;
        }
        else{
            if (*totalPreguntas==0)
                pregunta[*totalPreguntas].codigo = 1;
            else
                pregunta[*totalPreguntas].codigo = pregunta[*totalPreguntas-1].codigo+1;
            pregunta[*totalPreguntas].cantidad = 0;
            pregunta[*totalPreguntas].porcentage = 0;
            pregunta[*totalPreguntas].respuestas = -1;
            pregunta[*totalPreguntas].tipoPrueba = 4;
            lerString("Indique o enunciado da pergunta: \n", pregunta[*totalPreguntas].enunciado, MAX_STRING);
            lerString("Indique a primera opcao de resposta (1):\n", pregunta[*totalPreguntas].opcao1, MAX_STRING);
            lerString("\nIndique a segunda opcao de resposta (2):\n", pregunta[*totalPreguntas].opcao2, MAX_STRING);
            lerString("\nIndique a tercera opcao de resposta (3):\n", pregunta[*totalPreguntas].opcao3, MAX_STRING);
            lerString("\nIndique a quarta opcao de resposta (4):\n", pregunta[*totalPreguntas].opcao4, MAX_STRING);
            pregunta[*totalPreguntas].correcta = lerInteiro("\nIndique a opcao correcta: ", 1, 4);

            (*totalPreguntas)++;
        }
    }

    return pregunta;
}

void localPregunta(int numero, regPreguntas pregunta[], int quantidade){
    int i, posicao = -1;

    if(quantidade != 0){
        posicao = procuraPregunta(numero, pregunta, quantidade);
        if(posicao == -1)
            printf("\n****** Nao existe uma pergunta com ese codigo ******");
        else{
            for(i=0; i<quantidade; i++){
                if (numero==pregunta[i].codigo){
                    printf("\n----------------- Codigo da Pergunta: %d -----------------\n", pregunta[i].codigo);
                    printf("Tipo de Prova D\n");
                    printf("\nNumero de vezes que a pergunta foi usada: %d", pregunta[i].cantidad);
                    printf("\nPorcentagem respostas correctas: %.2f%%", (pregunta[i].porcentage*100)/pregunta[i].cantidad);
                    printf("\n- %s", pregunta[i].enunciado);
                    printf("\n(1) %s", pregunta[i].opcao1);
                    printf("\n(2) %s", pregunta[i].opcao2);
                    printf("\n(3) %s", pregunta[i].opcao3);
                    printf("\n(4) %s", pregunta[i].opcao4);
                    printf("\t\tOpcao correcta -> %d", pregunta[i].correcta);

                    printf("\n--------------------------------------------------------\n");
                }
            }
        }
    }
    else
        printf("\n----------- Nao ha preguntas inseridas pelo utilizador! -----------\n");

    limpaBufferStdin();
}

void mostrarPreguntas(regPreguntas pregunta[], int quantidade){
    int i;

    if (quantidade == 0){
        printf("\n\n ------ Nao existem perguntas inseridas! ------\n\n");
    }
    else
    {
        printf("\n*************************************************************");
        printf("\n                    Lista de Perguntas");
        printf("\n*************************************************************\n");
        for (i=0; i<quantidade; i++){
            printf("\n--------------------------------------------------------");
            printf("\nCodigo da pergunta: %d", pregunta[i].codigo);
            printf("\tTipo de Prova D\n");
            printf("\nNumero de vezes que a pergunta foi usada: %d", pregunta[i].cantidad);
            printf("\nPorcentagem respostas correctas: %.2f%%", (pregunta[i].porcentage*100)/quantidade);
            printf("\n\n%s", pregunta[i].enunciado);
            printf("\n(1) %s", pregunta[i].opcao1);
            printf("\n(2) %s", pregunta[i].opcao2);
            printf("\n(3) %s", pregunta[i].opcao3);
            printf("\n(4) %s", pregunta[i].opcao4);
            printf("\t\tOpcao correcta -> %d", pregunta[i].correcta);
            printf("\n--------------------------------------------------------\n");
        }
    }
}

void alterarPregunta(int numero, regPreguntas pregunta[], int quantidade){
    int posicao;
    int i;

    if(quantidade != 0){
        posicao = procuraPregunta(numero, pregunta, quantidade);
        if(posicao == -1){
            printf("\n****** Nao existe uma pergunta com ese codigo ******");
        }
        else{
            for(i=0; i<quantidade; i++){
                if(pregunta[i].codigo == numero){
                    printf("\nAltere informacao da Pergunta: ");
                    limpaBufferStdin();
                    lerString("Indique o novo enunciado da pergunta: \n", pregunta[i].enunciado, MAX_STRING);
                    lerString("Indique a nova primera opcao de resposta (1):\n", pregunta[i].opcao1, MAX_STRING);
                    lerString("\nIndique a nova segunda opcao de resposta (2):\n", pregunta[i].opcao2, MAX_STRING);
                    lerString("\nIndique a nova tercera opcao de resposta (3):\n", pregunta[i].opcao3, MAX_STRING);
                    lerString("\nIndique a nova quarta opcao de resposta (4):\n", pregunta[i].opcao4, MAX_STRING);
                    pregunta[i].correcta = lerInteiro("\nIndique a opcao correcta: ", 1, 4);

                    printf("\nAlteracao feita! (Pulsa enter)");
                }
            }
        }
    }
    else{
        printf("\n Nao ha perguntas registradas!\n");
    }

    limpaBufferStdin();
}

void imprimirPregunta(int quantidad, float *puntuacion, regPreguntas *pregunta){
    int i;

    for(i=0; i<(quantidad-4); i++){
        printf("\n- %s", pregunta[i].enunciado);
        printf("\n(1) %s", pregunta[i].opcao1);
        printf("\n(2) %s", pregunta[i].opcao2);
        printf("\n(3) %s", pregunta[i].opcao3);
        printf("\n(4) %s", pregunta[i].opcao4);
        pregunta[i].respuestas = lerInteiro("\nOpcao -> ", 1, 4);

        if(pregunta[i].respuestas == pregunta[i].correcta){
            (*puntuacion)++;
            pregunta[i].porcentage++;
        }
        else
            *puntuacion = *puntuacion - 0.25;

        pregunta[i].cantidad++;

    }
}

void gravaBinarioPreguntas(regPreguntas preguntas[], int quantidade){
    FILE *ficheiro;
    int escrito;
    int i;

    ficheiro =fopen("perguntas.dat","wb");

    if (ficheiro == NULL){
        printf("Erro ao abrir o ficheiro\n");
    }
    else{
        for(i=0; i < quantidade; i++){
            escrito = fwrite(&preguntas[i], sizeof(regPreguntas),1,ficheiro);
        }
        if (escrito!=1){
            printf("Erro ao escrever quantidade\n");
        }
        else{
            escrito = fwrite(preguntas, sizeof(regPreguntas),quantidade, ficheiro);
            if (escrito!=quantidade){
                printf("Erro ao escrever info dos estudantes\n");
            }
        }
        fflush(ficheiro);
        fclose(ficheiro);
    }

}

void leerBinarioPreguntas(regPreguntas preguntas[], int *quantidade){
    FILE *ficheiro;
    int lido;
    int i;

    *quantidade = 0;

    ficheiro =fopen("estudantes.dat","rb");

    if (ficheiro == NULL){
        printf("Erro ao abrir o ficheiro\n");

    }
    else{
        for(i=0; i<*quantidade; i++)
            lido = fread(&preguntas[i], sizeof(regPreguntas),1,ficheiro);

        if (lido!=1){
            printf("Erro ao ler quantidade\n");
            *quantidade = 0;
        }
        else{
            lido = fread(preguntas, sizeof(regPreguntas),*quantidade, ficheiro);
            if (lido!=(*quantidade)){
                printf("Erro ao ler a info dos estudantes\n");
                *quantidade = 0;
            }
        }
        fclose(ficheiro);
    }
}

