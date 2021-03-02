#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Estudiantes.h"
#include "Constantes.h"
#include "Basica.h"

void mostrarDados(tipoEstudante vetorEstudantes[MAX_ALUNOS], int quantidadeAvaliados){
    int i;

    if (quantidadeAvaliados==0){
        printf("\n Nao ha estudantes avaliados/inscritos\n");
    }
    else{
        printf("\n*****************************************************************************************************************");
        printf("\n                                          Lista de Estudantes");
        printf("\n*****************************************************************************************************************\n");
         printf("\n Numeros\tNomes\t            Tipo\tRegime\t       Turno   Treinos   Percentagem de respostas corretas\n");
        for (i=0; i<quantidadeAvaliados; i++){
            printf("\n%-7d\t\t%-20s",vetorEstudantes[i].numero, vetorEstudantes[i].nome);
            if(vetorEstudantes[i].tipo == 1){
                printf("Normal ");
            }
            else{
                if(vetorEstudantes[i].tipo == 2){
                    printf("Trabalhador ");
                }
                else{
                    if(vetorEstudantes[i].tipo == 3){
                        printf("Extraordinario ");
                    }
                }
            }
            if(vetorEstudantes[i].regime == 1){
                printf("\tDiurno");
            }
            else{
                printf("Pos-laboral");
            }
            printf("\t\t%-7d", vetorEstudantes[i].turno);

            if (vetorEstudantes[i].treinos.cantidadT == 0){
                printf("Sem treinos    --\n");
            }
            else{
                printf("%d", vetorEstudantes[i].treinos.cantidadT);
                if(vetorEstudantes[i].porcentagem == -1){
                    printf("             Treinos sin concluir!");
                }
                else{
                    printf("             %.2f %%", vetorEstudantes[i].porcentagem);
                }
            }
        }

    }
}//mostrarDados

int procuraEstudante(int numero, tipoEstudante vEstudantes[MAX_ALUNOS], int quantidade){
    int i, posicao=-1;

    for(i=0; i<quantidade; i++){
        if (numero==vEstudantes[i].numero){
            printf("Nome do estudante: %s \n", vEstudantes[i].nome);
            posicao = i;
            i=quantidade;
        }
    }

    return posicao;
}//FIM procuraEstudante

void localEstudante(int numero, tipoEstudante vEstudantes[MAX_ALUNOS], int quantidade){
    int i, posicao=-1;

    if(quantidade != 0){
        posicao = procuraEstudante(numero, vEstudantes, quantidade);
        if(posicao == -1){
            printf("\n****** Nao existe um estudante com ese numero ******");
        }
        else{
    for(i=0; i<quantidade; i++){
        if (numero==vEstudantes[i].numero){
            printf("\n----------------- Numero de Estudante: %d -----------------", vEstudantes[i].numero);
            printf("\nNome do estudante: %s", vEstudantes[i].nome);

            if(vEstudantes[i].tipo == 1){
                printf("\nTipo: Normal");
            }
            else{
                if(vEstudantes[i].tipo == 2){
                    printf("\nTipo: Trabalhador ");
                }
                else{
                    if(vEstudantes[i].tipo == 3){
                        printf("\nTipo: Extraordinario");
                    }
                }
            }
            if(vEstudantes[i].regime == 1){
                printf("\nRegime: Diurno");
            }
            else{
                printf("\nRegime: Pos-laboral");
            }
            printf("\nTurno: %-7d", vEstudantes[i].turno);
            if (vEstudantes[i].treinos.cantidadT == 0){
                printf("\nSem treinos");
            }
            else{
                printf("\nQuantidad de treinos: %d", vEstudantes[i].treinos.cantidadT);
                if(vEstudantes[i].porcentagem == 0){
                    printf("\nPorcentagem de respostas correctas: Treinos sin concluir!");
                }
                else{
                    printf("\nPorcentagem de respostas correctas:%.2f %%", vEstudantes[i].porcentagem);
                }
            }
            printf("\n--------------------------------------------------------\n");
        }
    }
    }
    }
    else{
        printf("\n Nao ha estudantes avaliados/inscritos\n");
    }
}//FIM localEstudante

int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo){
    int numero, controlo;
    do
    {
        printf("%s (%d a %d): ", mensagem, minimo, maximo);
        controlo = scanf ("%d", &numero);
        limpaBufferStdin();

        if (controlo == 0)
        {
            printf("Devera inserir um numero inteiro \n");
        }
        else
        {
            if(numero<minimo || numero>maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }
        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

tipoEstudante leerDatosEstudiantes(int quantidade){
    tipoEstudante aluno;

    aluno.numero = quantidade+1;
    printf("\nNumero de Estudante: %d", aluno.numero);
    lerString("\nNome do estudante: ",aluno.nome, MAX_STRING);

    return aluno;

}//leerDatosEstudantes

void agregarEstudiantes(tipoEstudante vEstudantes[MAX_ALUNOS], int *quantidade){

    int indice;
    tipoEstudante aluno;

    if (*quantidade == MAX_ALUNOS){
        printf("Limite de alunos atingido. Nao é possivel inscrever mais estudantes!\n");
    }
    else{
        aluno = leerDatosEstudiantes(*quantidade);
        indice = procuraEstudante(aluno.numero, vEstudantes, *quantidade);
        if (indice!=-1){
            printf("Ja existe um estudante com esse numero!!!\n");
        }
        else{
            vEstudantes[*quantidade] = aluno;
            vEstudantes[*quantidade].treinos.cantidadT = 0;
            vEstudantes[*quantidade].porcentagem = -1;
            vEstudantes[*quantidade].tipo = lerInteiro("Normal (1),trabalhador (2) ou extraordinario (3)?\n ",1,3);
            vEstudantes[*quantidade].regime = lerInteiro("Regime: Diurno (1) ou Pos-laboral(2)?\n",1,2);
            vEstudantes[*quantidade].turno = lerInteiro("Indique seu turno:",1,20);
            (*quantidade)++;
            printf("\n\n");
            mostrarDados(vEstudantes, *quantidade);
        }
    }
}//FIM agregarEstudiantes()

void alterarEstudante(int numero, tipoEstudante vEstudantes[MAX_ALUNOS], int quantidade){
    int posicao;
    int i;

    if(quantidade != 0){
        posicao = procuraEstudante(numero, vEstudantes, quantidade);
        if(posicao == -1){
            printf("\n****** Nao existe um estudante com ese numero ******");
        }
        else{
            for(i=0; i<quantidade; i++){
                if(vEstudantes[i].numero == numero){
                    printf("\nAltere informacao Estudante: ");
                    limpaBufferStdin();
                    lerString("\n- Insire o novo nome do Estudante: ", vEstudantes[i].nome, MAX_STRING);
                    vEstudantes[i].regime = lerInteiro("\n- Indique o novo regime: Diurno (1) ou Pos-laboral(2)?\n",1,2);
                    vEstudantes[i].tipo = lerInteiro("- Normal (1),trabalhador (2) ou extraordinario (3)?\n ",1,3);
                    vEstudantes[i].turno = lerInteiro("- Indique o novo turno:",1,20);
                    printf("\nAlteracao feita! (Pulsa enter)");
                }
            }
        }
    }
    else{
        printf("\n Nao ha estudantes avaliados/inscritos\n");
    }
}//alterarEstudante

void gravaFicheiroBinario(tipoEstudante vEstudante[MAX_ALUNOS], int quantidade){

    FILE *ficheiro;
    int escrito;
    int i;

    ficheiro =fopen("estudantes.dat","wb");

    if (ficheiro == NULL){
        printf("Erro ao abrir o ficheiro\n");
    }
    else{//abriu ficheiro com sucesso
        for(i=0; i < quantidade; i++){
            escrito = fwrite(&vEstudante[i], sizeof(tipoEstudante),1,ficheiro);
        }
        if (escrito!=1){
            printf("Erro ao escrever quantidade\n");
        }
        else{
            escrito = fwrite(vEstudante, sizeof(tipoEstudante),quantidade, ficheiro);
            if (escrito!=quantidade){
                printf("Erro ao escrever info dos estudantes\n");
            }
        }
        fflush(ficheiro);
        fclose(ficheiro);
    }

}

void leFicheiroBinario(tipoEstudante vEstudante[MAX_ALUNOS], int *quantidade){

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
            lido = fread(&vEstudante[i], sizeof(tipoEstudante),1,ficheiro);

        if (lido!=1){
            printf("Erro ao ler quantidade\n");
            *quantidade = 0;
        }
        else{
            lido = fread(vEstudante, sizeof(tipoEstudante),*quantidade, ficheiro);
            if (lido!=(*quantidade)){
                printf("Erro ao ler a info dos estudantes\n");
                *quantidade = 0;
            }
        }
        fclose(ficheiro);
    }
}

