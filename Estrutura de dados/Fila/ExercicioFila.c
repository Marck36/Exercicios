
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int home()
{
    printf("################################################################################################################# \n");
    printf("## TELA DE MENU \n");
    printf("################################################################################################################# \n");
    printf("1. Cadastrar Campos-Guarus \n");
    printf("2. Cadastrar Guarus-Campos \n");
    printf("3. Liberar Travessia \n");
    printf("4. Sair \n");

    int menu;
    scanf("%i", &menu);
    return menu;
}

struct sfila registration(struct sfila fila){
    printf("################################################################################################################# \n");
    printf("## TELA DE CADASTRO: \n");
    printf("################################################################################################################# \n");
    int i;
    for ( i = 0; i < 3; i++)
    {
        if (qisFull(&fila))
        {
            printf("Cadastro bloqueado, limite de carros alcancado! \n");
            break;
        }

        printf("Entre com a placa do carro: \n");
        char placa;
        scanf("%s", &placa);
        enqueue(&fila, placa);

        printf("Deseja incluir novos carros: Sim(s)/Nao(n) \n");
        char isRegister;
        scanf("%s", &isRegister);

        printf("##: %s\n", isRegister);

        if (strcmp(isRegister, "n"))
        {
            break;
        }
    }
    return fila;
}

void crossing(struct sfila filaCampos, struct sfila filaGuarus){
    int i;
    for ( i = 0; i < 5; i++)
    {
        
        printf("################################################################################################################# \n");
        printf("## TRAVESSIA LIBERADA: \n");
        printf("################################################################################################################# \n");

        if (qisEmpty(&filaCampos))
        {
            printf("Sentido Campos-Guarus: \n");
            printf("Sem carros aguardando! \n");
        }
        printf("Sentido Campos-Guarus: \n");
        printf("Atravessando Carro %s: \n", dequeue(&filaCampos));
        sleep(1);
        
        if (qisEmpty(&filaGuarus))
        {
            printf("Sentido Guarus-Campos: \n");
            printf("Sem carros aguardando! \n");
        }
        printf("Sentido Guarus-Campos \n");
        printf("Atravessando Carro %s \n", dequeue(&filaGuarus));
        sleep(1);

        char done;
        printf("Deseja prosseguir(S/N)? \n");
        scanf("%s", &done);
        if (strcmp(done, "n"))
        {
            break;
        }
    }
    

}

int main(){

struct sfila filaCampos;
qinit(&filaCampos);

struct sfila filaGuarus;
qinit(&filaGuarus);

// return 0;
// #################################################################################################################
// ##    INICIANDO TELA DE MENU
// #################################################################################################################
int menu = home();

// #################################################################################################################
// ##    INICIANDO TELA DE CADASTRO
// #################################################################################################################
if (menu == 1)
{
    filaCampos = registration(filaCampos);
}

// #################################################################################################################
// ##    INICIANDO TELA DE CADASTRO
// #################################################################################################################
if (menu == 2)
{
    filaGuarus = registration(filaGuarus);
}

// #################################################################################################################
// ##    INICIANDO TELA DE EXECUCAO DA TRAVESSIA
// #################################################################################################################
if (menu == 3)
{
    crossing(filaCampos, filaGuarus);
}

// #################################################################################################################
// ##    ENCERRANDO
// #################################################################################################################
if (menu == 4)
{
    printf("Saindo!...");
    return 0;
}

}