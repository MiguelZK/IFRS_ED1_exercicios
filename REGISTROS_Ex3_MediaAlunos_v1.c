/*
Programa: Informa��es notas alunos
Autor: Miguel Zanona Krasner <miguelzkestudos@gmail.com>
Data Cria��o: 19/06/2021

3 - Crie uma estrutura que armazene o nome de um
aluno, numero de matricula, 4 notas e faltas.

Crie um vetor para armazenar 5 alunos.

Crie uma fun��o para ler os dados de um aluno.

Crie uma fun��o para escrever na tela os dados de
um aluno

Crie uma fun��o que retorne a m�dia do aluno

Crie uma fun��o que escreva a situa��o do aluno

As fun��es acima recebem o �ndice do aluno como
par�metro e alteram o array global que cont�m os
alunos.
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //necess�rio para usar setlocale
#include <string.h> //necess�rio para manipular strings

typedef struct{
    char nome[50];
    int matricula, faltas;
    float notas[4];
}alunos;

alunos aluno[5];

void ler(int indice){
    fflush(stdin);
    printf("Informe o nome do/a aluno/a %d: ", indice +1);
    gets(aluno[indice].nome);
    printf("Informe a matr�cula do/a aluno/a: ");
    scanf("%d", &aluno[indice].matricula);
    for(int i = 1; i<5; i++){
        printf("Informe a nota %d: ", i);
        scanf("%f", &aluno[indice].notas[i-1]);
    }
    printf("Informe o n�mero de faltas do/a aluno/a: ");
    scanf("%d", &aluno[indice].faltas);
}

float media(int indice){
    float soma = 0;
    for(int i = 0; i < 4; i++){
        soma += aluno[indice].notas[i];
    }
    return (soma / 4);
}

void situacao(int indice){
    //int med = media(indice);
    int decisao = 0;

    if(media(indice) >= 7){
        decisao += 2;
    }
    if(aluno[indice].faltas <= 5){
        decisao++;
    }
    switch(decisao){
        case 0:
            printf("\nReprovado/a por m�dia e por faltas.\n");
            break;
        case 1:
            printf("\nReprovado/a por m�dia.\n");
            break;
        case 2:
            printf("\nReprovado/a por faltas.\n");
            break;
        case 3:
            printf("\nAprovado/a! AEEEEEE\n");
            break;
    }
}

void imprime(int indice){
    float med = media(indice);
    printf("Informa��es do/a aluno/a %s:", aluno[indice].nome);
    printf("\nMatr�cula do/a aluno/a: %d", aluno[indice].matricula);
    for(int i = 1; i<5; i++){
        printf("\nNota %d: %.2f", i, aluno[indice].notas[i-1]);
    }
    printf("\nN�mero de faltas do/a aluno/a: %d", aluno[indice].faltas);
    printf("\nM�dia do/a aluno/a: %.2f", med);
    situacao(indice);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int opc;

    for(int i = 0; i < 5; i++){
        printf("LISTA DE ALUNOS - PREENCHIMENTO\n");
        printf("\nInforme os dados conforme solicitado:\n\n");
        ler(i);
        printf("\n\nVamos ao pr�ximo aluno\n");
        system("pause");
        system("cls");
    }

    do{
        opc = 0;
        printf("INFORME O N�MERO DO/A ALUNO/A QUE DESEJA VERIFICAR OS DADOS:\n");
        for(int i = 0; i < 5; i++){
            printf("%d - %s\n", i+1, aluno[i].nome);
        }
        printf("Outro n�mero: SAIR\n");
        scanf("%d", &opc);
        opc--;

        if(opc >= 0 && opc < 5){
            imprime(opc);
            system("pause");
            system("cls");
        }
        }while(opc >= 0 && opc < 5);
        printf("At� mais!");
/*    printf("\nCONFERINDO\n\n");
    for (int i = 0; i < 3; i++){
        printf("Nome: %s\n", minhaAgenda[i].nome);
        printf("Telefone fixo: %d\n", minhaAgenda[i].foneFixo);
        printf("Fone celular: %d\n", minhaAgenda[i].celular);
        printf("Endere�o: %s\n", minhaAgenda[i].endereco);
        printf("Anivers�rio: %s\n\n", minhaAgenda[i].aniver);
    }
*/
    return 0;
}
