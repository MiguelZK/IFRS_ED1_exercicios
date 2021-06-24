/*
Programa: Agenda de 3 contatos
Autor: Miguel Zanona Krasner <miguelzkestudos@gmail.com>
Data Criação: 20/06/2021

4 - Sua empresa o contratou para desenvolver uma agenda
para uma pessoa solitária que tem apenas o telefone da
mãe e um amigo.

Esta agenda deve ter capacidade para armazenar o
nome, telefone, celular, endereço e aniversário.

A agenda deve ser capaz de inserir os dados de todos os
contatos (máx 3: A mãe, o amigo e ele mesmo)

Após a inserção de todos os contatos deve perguntar ao
usuário o número do contato que ele quer visualizar,
caso o número esteja fora do intervalo (1 a 3), o
programa termina, caso contrário o programa escreve
na tela os dados e pergunta novamente.

Este programa nao precisa ter funções além da principal
Seria com ponteiros... mas não precisou e foi aceito pelo professor.
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //necessário para usar setlocale
#include <string.h> //necessário para manipular strings

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

    strcpy(minhaAgenda[0].nome, "Mãe");
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
        printf("Endereço: ");
        gets(minhaAgenda[i].endereco);
        printf("Aniversário (DD/MM): ");
        gets(minhaAgenda[i].aniver);
    }
    printf("\n");
    system("pause");
    system("cls");


    do{
        opc = 0;
        printf("INFORME O NÚMERO DO CONTATO QUE DESEJA VERIFICAR OS DADOS:\n");
        printf("1 - Mãe\n");
        printf("2 - Amigo\n");
        printf("3 - %s\n", minhaAgenda[2].nome);
        printf("Outro número: SAIR\n");
        scanf("%d", &opc);
        opc -= 1;

        if(opc >= 0 && opc < 4){
            printf("\nNome: %s", minhaAgenda[opc].nome);
            printf("\nFone fixo: %s", minhaAgenda[opc].foneFixo);
            printf("\nCelular: %s", minhaAgenda[opc].celular);
            printf("\nEndereço: %s", minhaAgenda[opc].endereco);
            printf("\nAniversário: %s\n\n", minhaAgenda[opc].aniver);

            system("pause");
            system("cls");

        }else{printf("\nAté mais\n");}

        }while(opc >= 0 && opc < 4);
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
