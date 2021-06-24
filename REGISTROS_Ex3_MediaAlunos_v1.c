/*
Programa: Informações notas alunos
Autor: Miguel Zanona Krasner <miguelzkestudos@gmail.com>
Data Criação: 19/06/2021

3 - Crie uma estrutura que armazene o nome de um
aluno, numero de matricula, 4 notas e faltas.

Crie um vetor para armazenar 5 alunos.

Crie uma função para ler os dados de um aluno.

Crie uma função para escrever na tela os dados de
um aluno

Crie uma função que retorne a média do aluno

Crie uma função que escreva a situação do aluno

As funções acima recebem o índice do aluno como
parâmetro e alteram o array global que contém os
alunos.
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //necessário para usar setlocale
#include <string.h> //necessário para manipular strings

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
    printf("Informe a matrícula do/a aluno/a: ");
    scanf("%d", &aluno[indice].matricula);
    for(int i = 1; i<5; i++){
        printf("Informe a nota %d: ", i);
        scanf("%f", &aluno[indice].notas[i-1]);
    }
    printf("Informe o número de faltas do/a aluno/a: ");
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
            printf("\nReprovado/a por média e por faltas.\n");
            break;
        case 1:
            printf("\nReprovado/a por média.\n");
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
    printf("Informações do/a aluno/a %s:", aluno[indice].nome);
    printf("\nMatrícula do/a aluno/a: %d", aluno[indice].matricula);
    for(int i = 1; i<5; i++){
        printf("\nNota %d: %.2f", i, aluno[indice].notas[i-1]);
    }
    printf("\nNúmero de faltas do/a aluno/a: %d", aluno[indice].faltas);
    printf("\nMédia do/a aluno/a: %.2f", med);
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
        printf("\n\nVamos ao próximo aluno\n");
        system("pause");
        system("cls");
    }

    do{
        opc = 0;
        printf("INFORME O NÚMERO DO/A ALUNO/A QUE DESEJA VERIFICAR OS DADOS:\n");
        for(int i = 0; i < 5; i++){
            printf("%d - %s\n", i+1, aluno[i].nome);
        }
        printf("Outro número: SAIR\n");
        scanf("%d", &opc);
        opc--;

        if(opc >= 0 && opc < 5){
            imprime(opc);
            system("pause");
            system("cls");
        }
        }while(opc >= 0 && opc < 5);
        printf("Até mais!");
/*    printf("\nCONFERINDO\n\n");
    for (int i = 0; i < 3; i++){
        printf("Nome: %s\n", minhaAgenda[i].nome);
        printf("Telefone fixo: %d\n", minhaAgenda[i].foneFixo);
        printf("Fone celular: %d\n", minhaAgenda[i].celular);
        printf("Endereço: %s\n", minhaAgenda[i].endereco);
        printf("Aniversário: %s\n\n", minhaAgenda[i].aniver);
    }
*/
    return 0;
}
