#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Basica.h"
#include "Estructuras.h"
#include "Estudiantes.h"
#include "Registrar.h"

void limpaBufferStdin(void){
    char chr;
    do
    {
        chr = getchar();
    }
    while (chr != '\n' && chr != EOF);
}

void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres){
    int tamanhoString;

    do
    {
        printf("%s", mensagem);
        fgets(vetorCaracteres, maximoCaracteres, stdin);



        tamanhoString = strlen(vetorCaracteres);

        if (tamanhoString == 1)
        {
            printf("Nao foram introduzidos caracteres!!! . apenas carregou no ENTER \n\n");
        }
    }
    while (tamanhoString == 1);



    if(vetorCaracteres[tamanhoString-1] != '\n')
    {
        limpaBufferStdin();
    }
    else
    {
        vetorCaracteres[tamanhoString-1] = '\0';
    }

}

tipoData lerData(int ano_min, int ano_max){
    tipoData data;
    int max;

    data.ano = lerInteiro("Indique o ano ", ano_min, ano_max);
    data.mes = lerInteiro("Indique o mes ", 1, 12);

    switch(data.mes)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        max = 30;
        break;
    case 2:
        if ((data.ano%400==0) || (data.ano%4==0 && data.ano%100!=0)){
            max = 29;
        }
        else{
            max = 28;
        }
        break;
    default:
        max = 31;
    }//switch

    data.dia = lerInteiro("Indique o dia ", 1, max);

    return data;
}//lerData

tipoHora lerHora(int hora_min, int hora_max){
    tipoHora hora;

    hora.hora = lerInteiro("Indique a hora do Treino ", hora_min, hora_max);
    hora
    .minutos = lerInteiro("Indique os minutos ", 00, 59);

    return hora;
}//lerHora()

void ranking(registrarTreino *vTreino, int totalTreinos){
    int i, j;
    registrarTreino temp;

    for(i=0; i < totalTreinos; i++){

        for(j=0; j < totalTreinos-1; j++){
            if(vTreino[j].nota < vTreino[j+1].nota){
                temp = vTreino[j];
                vTreino[j] = vTreino[j+1];
                vTreino[j+1] = temp;
            }
        }
    }

    mostrarRankin(vTreino, totalTreinos);

}

void mostrarRankin(registrarTreino *vTreino, int totalTreinos){
    int i;
    int puesto = 1;

    if (totalTreinos==0){
        printf("\n Nao ha treinos registrados!\n");
    }
    else{
        printf("\n*************************************************************");
        printf("\n                  Ranking Notas Treinos");
        printf("\n*************************************************************\n");
        printf("\nPosto\tC.Treino\tN.Estudante\tNota\n");
        for (i=0; i<totalTreinos; i++){
            if(vTreino[i].nota != -1){
                printf("\n%d._\t%d\t\t%d\t\t%.2f\n", puesto, vTreino[i].codigo, vTreino[i].numEstudante, vTreino[i].nota);
            }
            else{
                printf("\n%d._\t%d\t\t%d\t\tTreino sim registrar!\n",puesto, vTreino[i].codigo, vTreino[i].numEstudante);
            }
            puesto++;
        }
    }
}//mostrarDados

int procurData(registrarTreino vTreinos[], int quantTreinos, tipoData data){
    int i, posicao=-1;

    for (i=0; i<quantTreinos; i++){
        if (vTreinos[i].data.dia == data.dia && vTreinos[i].data.mes == data.mes && vTreinos[i].data.ano == data.ano)
        {
            posicao = i;
            i=quantTreinos;
        }
    }


    return posicao;
}//procuraTreino

void estadisticoData(registrarTreino treinos[], int quantidade){
    int posicao1, posicao2;
    int i, f;
    tipoData data1, data2;
    int numero = 0;

    if(quantidade == 0)
        printf("\n--------------- Sim treinos registrados! ---------------");
    else{
        printf("\nInsire as duas datas a consultar: ");

        do{
            printf("\n- Data 1:\n");
            data1 = lerData(2019, 2020);
            posicao1 = procurData(treinos, quantidade, data1);
            if(posicao1 == -1)
                printf("\n------- Nao ha treinos registrados em esa data! -------");
        }while(posicao1 == -1);

        do{
            printf("\n- Data 2:\n");
            data2 = lerData(2019, 2020);
            posicao2 = procurData(treinos, quantidade, data2);
            if(posicao2 == -1)
                printf("\n------- Nao ha treinos registrados em esa data! -------");
        }while(posicao2 == -1);

        for(i=0; i<quantidade; i++){
            if(treinos[i].data.dia == data1.dia && treinos[i].data.mes == data1.mes && treinos[i].data.ano == data1.ano){
                numero++;
            }
        }
        for(f=0; f<quantidade; f++){
            if(treinos[f].data.dia == data2.dia && treinos[f].data.mes == data2.mes && treinos[f].data.ano == data2.ano){
                numero++;
            }
        }
        printf("\nQuantidad de treinos: %d", numero);
    }

}

void porProva(registrarTreino treinos[], int quantidade){
    int i;
    float porcentageA = 0, porcentageB = 0;
    float porcentageC = 0, porcentageD = 0;

    if(quantidade == 0)
        printf("\n--------------- Sim treinos registrados! ---------------");
    else{
        if(treinosRealizados(treinos, quantidade) == 0){
            printf("\n--------------- Treinos sim concluir! ---------------");
        }
        else{
            for(i=0; i<quantidade; i++){
                if(treinos[i].tPrueba == 1)
                    porcentageA++;
            }
            for(i=0; i<quantidade; i++){
                if(treinos[i].tPrueba == 2)
                    porcentageB++;
            }
            for(i=0; i<quantidade; i++){
                if(treinos[i].tPrueba == 3)
                    porcentageC++;
            }
            for(i=0; i<quantidade; i++){
                if(treinos[i].tPrueba == 4)
                    porcentageD++;
            }

            printf("\n\nPercentagem de treinos efetuados por cada prova:");
            printf("\n- Prova.A: %.2f%%\t- Prova.B: %.2f%%", (porcentageA*100)/quantidade, (porcentageB*100)/quantidade);
            printf("\n- Prova.C: %.2f%%\t- Prova.D: %.2f%%", (porcentageC*100)/quantidade, (porcentageD*100)/quantidade);
        }
    }
}

void tiempoMedio(registrarTreino treinos[], int quantidade){
    int i;
    float tiempo = 0, tiempoT = 0;
    float preguntas = 0, preguntasT = 0;
    float total = 0;

    if(quantidade == 0)
        printf("\n--------------- Sim treinos registrados! ---------------");
    else{
        if(treinosRealizados(treinos, quantidade) == 0){
            printf("\n--------------- Treinos sim concluir! ---------------");
        }
        else{
            for(i=0; i<quantidade; i++){
                tiempo = treinos[i].tempo;
                tiempoT = tiempo + tiempoT;
            }
            for(i=0; i<quantidade; i++){
                preguntas = treinos[i].cantidadP;
                preguntasT = preguntas + preguntasT;
            }

            tiempoT = tiempoT/quantidade;
            preguntasT = preguntasT/quantidade;
            total = tiempoT/preguntasT;

            printf("\nTempo medio de resposta: %.2f min", total);
        }
    }

}
