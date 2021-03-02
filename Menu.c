#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "Estudiantes.h"
#include "Basica.h"



char menu(){
    char opcao;
    do{
        printf("P - Informacao (P)erguntas\n");
        printf("E - Dados (E)studantes\n");
        printf("T - (T)reinos\n");
        printf("V - (V)er Resultados de Treino\n");
        printf("R - (R)anking dos Treinos\n");
        printf("D - (D)ados Estadisticos\n");
        printf("G - (G)ravar Informacao (binario)\n");
        printf("L - (L)er informacao (binario)\n");
        printf("F - (F)im\n");
        printf("    OPCAO --->   ");
        scanf("%c", &opcao);

        limpaBufferStdin();
        opcao = toupper(opcao);
        if (opcao!='P' && opcao!='E' && opcao!='T' && opcao!='V' && opcao!='R' && opcao!='G' && opcao!='L' && opcao!='F' && opcao !='D')
            printf("\n\n Opcao invalida!!!!! \n");

    }while (opcao!='P' && opcao!='E' && opcao!='T' && opcao!='V' && opcao!='R' && opcao!='G' && opcao!='L' && opcao!='F' && opcao !='D');

    return opcao;
}//FIM menu()

char subPerguntas(){
    char opcao;

    do{
        printf("I - (I)nserir Informacao Perguntas\n");
        printf("L - (L)istar Informacao Perguntas\n");
        printf("C - (C)onsultar Informacao Perguntas\n");
        printf("A - (A)lterar Informacao Perguntas\n");
        printf("V - (V)olte\n");
        printf("    OPCAO --->   ");
        scanf("%c", &opcao);

        limpaBufferStdin();
        opcao = toupper(opcao);
        if (opcao!='I' && opcao!='C' && opcao!='A' && opcao!='L' && opcao!='V')
            printf("\n\n Opcao invalida!!!!! \n");

    }while (opcao!='I' && opcao!='C' && opcao!='A' && opcao!='L' && opcao!='V');

    return opcao;
}//FIM subPerguntas()

char subEstudantes(){
    char opcao;

    do{
        printf("\n-----------------------------------------------\n");
        printf("\n************** Submenu Estudantes **************\n");
        printf("\n-----------------------------------------------\n");
        printf("I - (I)nserir Informacao Estudantes\n");
        printf("L - (L)istar Informacao Estudantes\n");
        printf("C - (C)onsultar Informacao Estudantes\n");
        printf("A - (A)lterar Informacao Estudantes\n");
        printf("V - (V)olte\n");
        printf("    OPCAO --->   ");
        scanf("%c", &opcao);

        limpaBufferStdin();
        opcao = toupper(opcao);
        if (opcao!='I' && opcao!='C' && opcao!='A' && opcao!='L' && opcao!='V')
            printf("\n\n Opcao invalida!!!!! \n");

    }while (opcao!='I' && opcao!='C' && opcao!='A' && opcao!='L' && opcao!='V');

    return opcao;
}//FIM subEstudantes()

char subTreinos(){
    char opcao;

    do{
        printf("\n-----------------------------------------------\n");
        printf("\n************** Submenu Treinos **************\n");
        printf("\n-----------------------------------------------\n");
        printf("L - (L)ista de Treinos\n");
        printf("I - Consultar (I)nformacao do Treino\n");
        printf("C - (C)riar um Treino\n");
        printf("R - (R)egistrar um Treino\n");
        printf("E - (E)liminar um Treino (So Treinos criados)\n");
        printf("T - Consultar Perguntas e Respostas de um Determinado (T)reino\n");
        printf("V - (V)olte\n");
        printf("    OPCAO --->   ");
        scanf("%c", &opcao);

        limpaBufferStdin();
        opcao = toupper(opcao);
        if (opcao!='L' && opcao!='R' && opcao!='C' && opcao!='E' && opcao!='T' && opcao!='I' && opcao!='V')
            printf("\n\n Opcao invalida!!!!! \n");

    }while (opcao!='L' && opcao!='R' && opcao!='C' && opcao!='E' && opcao!='T' && opcao!='I' && opcao!='V');

    return opcao;
}//FIM subTreinos()

char subEstadisticas(){
    char opcao;

    do{
        printf("\n----------------------------------------------\n");
        printf("\n********* Submenu Dados Estadisticos *********\n");
        printf("\n----------------------------------------------\n");
        printf("T - (T)empo medio de resposta a uma pergunta\n");
        printf("Q - (Q)uantidade de treinos realizados (entre duas datas)\n");
        printf("P - (P)ercentagem de treinos efetuados por cada prova\n");
        printf("E - Pergunta com a maior quantidade de respostas (E)rradas\n");
        printf("M - Tipo de perguntas com a (M)enor percentagem de respostas corretas\n");
        printf("V - (V)olte\n");
        printf("    OPCAO --->   ");
        scanf("%c", &opcao);

        limpaBufferStdin();
        opcao = toupper(opcao);
        if (opcao!='T' && opcao!='Q' && opcao!='P' && opcao!='E' && opcao!='M' && opcao!='V')
            printf("\n\n Opcao invalida!!!!! \n");

    }while (opcao!='T' && opcao!='Q' && opcao!='P' && opcao!='E' && opcao!='M' && opcao!='V');

    return opcao;
}//FIM sub()
