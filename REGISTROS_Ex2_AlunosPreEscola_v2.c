/*
Programa: Informa��es 5 alunos
Autor: Miguel Zanona Krasner <miguelzkestudos@gmail.com>
Data Cria��o: 19/06/2021

2 - Uma pr� escola tem 5 alunos, crie uma estrutura
que armazene nome, telefone de emergencia, idade,
contato de emergencia;

Crie um vetor com 5 dessas estruturas

Crie uma fun��o para ler as informa��es de UM
aluno; chame a fun��o 5 vezes.

Crie uma fun��o que recebe como par�metro o
�ndice do aluno e escreva todos os dados na tela de
maneira organizada.

As fun��es acima recebem o �ndice do aluno como
par�metro e alteram o array global que cont�m os
alunos.
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //necess�rio para usar setlocale
#include <string.h> //necess�rio para manipular strings

#define MAX 5

typedef struct{
    char nome[50], fone[15], contato[50];
    int idade;
}alunos;

alunos aluno[MAX];

void ler(int indice){
    printf("Informe o nome do aluno %d: ", indice +1);
    gets(aluno[indice].nome);
    printf("Informe a idade do aluno: ");
    scanf("%d", &aluno[indice].idade);
    getchar();
    printf("Informe seu telefone de emerg�ncia: ");
    gets(aluno[indice].fone);
    printf("Informe o contato de emerg�ncia: ");
    gets(aluno[indice].contato);
}

void imprime(int indice){
    printf("INFORMA��ES DO ALUNO %s:", aluno[indice].nome);
    printf("\nIdade: %d", aluno[indice].idade);
    printf("\nFone de emerg�ncia: %s", aluno[indice].fone);
    printf("\nContato de emerg�ncia: %s\n", aluno[indice].contato);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int opc;
    //char textoTmp[70];
    //int numTmp;

    for(int i = 0; i < MAX; i++){
        printf("LISTA DE ALUNOS - PREENCHIMENTO\n");
        printf("\nInforme os contatos conforme solicitado:\n");
        ler(i);
        if(i < MAX-1){printf("\nVamos ao pr�ximo aluno\n\n");}
        else{printf("\n");}
        system("pause");
        system("cls");
    }

    do{
        opc = 0;
        printf("INFORME O N�MERO DO ALUNO QUE DESEJA VERIFICAR OS DADOS:\n");
        for(int i = 0; i < MAX; i++){
            printf("%d - %s\n", i+1, aluno[i].nome);
        }
        printf("Outro n�mero: SAIR\n");
        scanf("%d", &opc);
        opc--;

        if(opc >= 0 && opc < MAX){
            imprime(opc);
            system("pause");
            system("cls");
        }
        }while(opc >= 0 && opc < MAX);
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
