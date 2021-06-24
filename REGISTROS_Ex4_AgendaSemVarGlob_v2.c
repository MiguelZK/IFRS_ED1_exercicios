/*
Programa: Agenda de 3 contatos
Autor: Miguel Zanona Krasner <miguelzkestudos@gmail.com>
Data Cria��o: 20/06/2021

4 - Sua empresa o contratou para desenvolver uma agenda
para uma pessoa solit�ria que tem apenas o telefone da
m�e e um amigo.

Esta agenda deve ter capacidade para armazenar o
nome, telefone, celular, endere�o e anivers�rio.

A agenda deve ser capaz de inserir os dados de todos os
contatos (m�x 3: A m�e, o amigo e ele mesmo)

Ap�s a inser��o de todos os contatos deve perguntar ao
usu�rio o n�mero do contato que ele quer visualizar,
caso o n�mero esteja fora do intervalo (1 a 3), o
programa termina, caso contr�rio o programa escreve
na tela os dados e pergunta novamente.

Este programa nao precisa ter fun��es al�m da principal
Seria com ponteiros... mas n�o precisou e foi aceito pelo professor.
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //necess�rio para usar setlocale
#include <string.h> //necess�rio para manipular strings

#define MAX 5


int main()
{
    setlocale(LC_ALL, "Portuguese");

    typedef struct{
        char nome[50];
        char foneFixo[15];
        char celular[15];
        char endereco[100];
        char aniver[6];
    }agenda;

    agenda minhaAgenda[3];
    int opc;
    //char textoTmp[70];
    //int numTmp;

    strcpy(minhaAgenda[0].nome, "M�e");
    strcpy(minhaAgenda[1].nome, "Amigo");
    //strcpy(minhaAgenda[2].nome, "Eu Mesmo");

    printf("AGENDA DE CONTATOS\n\n");
    printf("Informe seu nome: ");
    gets(minhaAgenda[2].nome);

    printf("\nInforme os contatos conforme solicitado:\n");
    for(int i = 0; i < 3; i++){
        printf("\nContato %d: %s\n", i+1, minhaAgenda[i].nome);
        printf("Telefone fixo: ");
        gets(minhaAgenda[i].foneFixo);
        printf("Telefone celular: ");
        gets(minhaAgenda[i].celular);
        printf("Endere�o: ");
        gets(minhaAgenda[i].endereco);
        printf("Anivers�rio (DD/MM): ");
        gets(minhaAgenda[i].aniver);
    }
    printf("\n");
    system("pause");
    system("cls");


    do{
        opc = 0;
        printf("INFORME O N�MERO DO CONTATO QUE DESEJA VERIFICAR OS DADOS:\n");
        printf("1 - M�e\n");
        printf("2 - Amigo\n");
        printf("3 - %s\n", minhaAgenda[2].nome);
        printf("Outro n�mero: SAIR\n");
        scanf("%d", &opc);
        opc -= 1;

        if(opc >= 0 && opc < 4){
            printf("\nNome: %s", minhaAgenda[opc].nome);
            printf("\nFone fixo: %s", minhaAgenda[opc].foneFixo);
            printf("\nCelular: %s", minhaAgenda[opc].celular);
            printf("\nEndere�o: %s", minhaAgenda[opc].endereco);
            printf("\nAnivers�rio: %s\n\n", minhaAgenda[opc].aniver);

            system("pause");
            system("cls");

        }else{printf("\nAt� mais\n");}

        }while(opc >= 0 && opc < 4);
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
