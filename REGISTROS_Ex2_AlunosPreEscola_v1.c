/*
Programa: Informações 5 alunos
Autor: Miguel Zanona Krasner <miguelzkestudos@gmail.com>
Data Criação: 19/06/2021

2 - Uma pré escola tem 5 alunos, crie uma estrutura
que armazene nome, telefone de emergencia, idade,
contato de emergencia;

Crie um vetor com 5 dessas estruturas

Crie uma função para ler as informações de UM
aluno; chame a função 5 vezes.

Crie uma função que recebe como parâmetro o
índice do aluno e escreva todos os dados na tela de
maneira organizada.

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
    char nome[50], contato[50];
    int fone, idade;
}alunos;

alunos aluno[5];

void ler(int indice){
    printf("Informe o nome do aluno %d: ", indice +1);
    gets(aluno[indice].nome);
    printf("Informe a idade do aluno: ");
    scanf("%d", &aluno[indice].idade);
    printf("Informe seu telefone de emergência: ");
    scanf("%d", &aluno[indice].fone);
    getchar();
    printf("Informe o contato de emergência: ");
    gets(aluno[indice].contato);
}

void imprime(int indice){
    printf("INFORMAÇÕES DO ALUNO %s:", aluno[indice].nome);
    printf("\nIdade: %d", aluno[indice].idade);
    printf("\nFone de emergência: %d", aluno[indice].fone);
    printf("\nContato de emergência: %s\n", aluno[indice].contato);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int opc;
    //char textoTmp[70];
    //int numTmp;

    for(int i = 0; i < 5; i++){
        printf("LISTA DE ALUNOS - PREENCHIMENTO\n");
        printf("\nInforme os contatos conforme solicitado:\n");
        ler(i);
        printf("\n\nVamos ao próximo aluno\n");
        system("pause");
        system("cls");
    }

    do{
        opc = 0;
        printf("INFORME O NÚMERO DO ALUNO QUE DESEJA VERIFICAR OS DADOS:\n");
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
