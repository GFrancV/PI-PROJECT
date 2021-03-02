#include <stdio.h>
#include <stdlib.h>

#include "Estructuras.h"
#include "Menu.h"
#include "Estudiantes.h"
#include "Basica.h"
#include "Registrar.h"
#include "pTipoC.h"
#include "Preguntas.h"

int main(){
    tipoEstudante estudantes[MAX_ALUNOS];
    regPreguntas *crearPregunta;
    registrarTreino *crearTreino;

    crearTreino = 0;
    crearPregunta = 0;

    int nEstudante,cTreino, cPregunta;
    int totalEstudantes=0, totalTreinos=0, totalPreguntas=0;

    char escolha;

    do
    {
        printf("\n\n********** MENU **********\n");
        printf("Total de estudantes: %d\n", totalEstudantes);
        printf("Quantidad de preguntas: %d\n", MAX_PREGUNTASA+MAX_PREGUNTASB+MAX_PREGUNTASC+totalPreguntas);//Agregar funcion (punto 9)
        treinosRealizados(crearTreino, totalTreinos);
        treinosDecorrer(crearTreino, totalTreinos);
        printf("--------------------------------------\n");

        escolha = menu();

        switch(escolha){
        case 'P':
            //subPerguntas();
            do{
                printf("\n-----------------------------------------------\n");
                printf("\n************** Submenu Perguntas **************\n");
                printf("Porcentagem Respostas Correctas: \n");
                printf("\n- Preguntas A: %d", MAX_PREGUNTASA);
                printf("\t- Preguntas B: %d", MAX_PREGUNTASB);
                printf("\n- Preguntas C: %d", MAX_PREGUNTASC);
                printf("\t- Preguntas D: %d", MAX_PREGUNTASD+totalPreguntas);
                printf("\n-----------------------------------------------\n");
                escolha = subPerguntas();

                switch(escolha){
                    case 'I':
                        crearPregunta = registrarPregunta(crearPregunta, &totalPreguntas);
                        break;
                    case 'C':
                        printf("\nIndique o codigo da pergunta a consultar: ");
                        scanf("%d", &cPregunta);
                        printf("\n");
                        localPregunta(cPregunta, crearPregunta,totalPreguntas);
                        break;
                    case 'A':
                        printf("\nIndique o codigo da pergunta para alterar: ");
                        scanf("%d", &cPregunta);
                        printf("\n");
                        alterarPregunta(cPregunta, crearPregunta,totalPreguntas);
                        break;
                    case 'L':
                        mostrarPreguntas(crearPregunta, totalPreguntas);
                        break;
                    case 'V':
                        printf("\nVolta Menu principal\n");
                }
            }while(escolha != 'V');
            break;
        case 'E':
//           subEstudantes();
            do{
                escolha = subEstudantes();

                switch(escolha){
                    case 'I':
                        agregarEstudiantes(estudantes, &totalEstudantes);
                        printf("\n\n Total de estudantes: %d\n", totalEstudantes);
                        break;
                    case 'C':
                        printf("\nIndique o numero do estudante (1 o 9999): ");
                        scanf("%d", &nEstudante);
                        printf("\n");
                        localEstudante(nEstudante, estudantes,totalEstudantes);
                        limpaBufferStdin();
                        break;
                    case 'A':
                        printf("\nIndique o numero do estudante para Alterar (1 o 9999): ");
                        scanf("%d", &nEstudante);
                        printf("\n");
                        alterarEstudante(nEstudante, estudantes, totalEstudantes);
                        limpaBufferStdin();
                        break;
                    case 'L':
                        mostrarDados(estudantes, totalEstudantes);
                        printf("\n\n Total de estudantes: %d\n", totalEstudantes);
                        break;
                    case 'V':
                        printf("\nVolta Menu principal\n");
                }
            }while(escolha != 'V');
            break;
        case 'T':
            //subTreinos
            do{
                escolha = subTreinos();

                switch(escolha){
                    case 'L':
                        if(MEMORIA_DIN)
                        mostrarTreinos(crearTreino, totalTreinos);
                        break;
                    case 'I':
                        printf("\n\nIndique o codigo do Estudante (1 a 9999): ");
                        scanf("%d", &nEstudante);
                        printf("\n");
                        if(totalTreinos != 0){
                            localTreino(nEstudante, crearTreino,totalTreinos);
                        }
                        else{
                            printf("Nao ha treinos registrados!");
                        }
                        limpaBufferStdin();
                        break;
                    case 'R':
                        printf("\nIndique o codigo do treino a registrar: ");
                        scanf("%d", &cTreino);
                        printf("\n");
                        regTreino(cTreino, crearTreino, totalTreinos, estudantes, crearPregunta, totalPreguntas);
                        limpaBufferStdin();
                        break;
                    case 'C':
                        if(MEMORIA_DIN)
                        crearTreino = crearTreinoDim(crearTreino,&totalTreinos, estudantes, totalEstudantes);
                        break;
                    case 'E':
                        if(MEMORIA_DIN)
                        crearTreino = eliminarTreinoDin(&totalTreinos, crearTreino);
                        break;
                    case 'T':
                        printf("\nIndique o codigo do Treino: ");
                        scanf("%d", &cTreino);
                        if(totalTreinos == 0)
                            printf("\n************* Nao ha treinos registrados! *************\n");
                        else
                            consultarResul(cTreino, crearTreino, totalTreinos, crearPregunta);
                        printf("\n\nPulsa Enter para continuar!");
                        limpaBufferStdin();
                        break;
                    case 'V':
                        printf("\nVolta Menu principal\n");
                }
            }while(escolha != 'V');
            break;
        case 'G':
            gravaFicheiroBinario(estudantes, totalEstudantes);
            gravaFicheiroTreinos_Binario(crearTreino, totalTreinos);
            gravaBinarioPreguntas(crearPregunta, totalPreguntas);
            break;
        case 'R':
            ranking(crearTreino, totalTreinos);
            break;
        case 'L':
            gravaFicheiroBinario(estudantes, totalEstudantes);
            leFicheiroTreinos_Binario(crearTreino, &totalTreinos);
            leerBinarioPreguntas(crearPregunta, &totalPreguntas);
            break;
        case 'D':
            //subEstadisticas
            do{
                escolha = subEstadisticas();
                switch(escolha){
                case 'T':
                    tiempoMedio(crearTreino, totalTreinos);
                    break;
                case 'Q':
                    estadisticoData(crearTreino, totalTreinos);
                    break;
                case 'P':
                    porProva(crearTreino, totalTreinos);
                    break;
                case 'E':

                    break;
                case 'M':

                    break;
                case 'V':
                    printf("\nVolta a menu principal!");
                }
            }while(escolha !='V');
            break;
        case 'F':
            printf("\n\nFim do programa\n\n");
        }//switch
    }
    while(escolha!='F');

    free(crearTreino);

    return 0;
}
