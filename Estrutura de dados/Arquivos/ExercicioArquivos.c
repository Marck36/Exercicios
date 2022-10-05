#include <stdio.h>
#include <stdlib.h>

// Descrição do Problema
// O gerente da Locadora de Carros LOCCAR pretende adquirir um programa para fazer o
// controle das locações de carro feitas, já que até o momento este processo é feito de forma
// manual.

// A ideia do gerente é ter um programa que permita:

// ● Cadastrar marcas de carro, composta por código e descrição da marca (Polo, Gol,etc)

// ● Registrar a ficha dos carros disponíveis para locação, composta por: placa, código da
// marca do carro, (validando se a marca foi previamente cadastrada e apresentar sua
// descrição), valor da locação e status (L = locado e D = disponível).

// ● Buscar um carro pela sua placa e apresentar todos seus dados cadastrais, incluindo
// código e descrição da marca.

// ● Locação do Carro: informar a placa, validar se a mesma está cadastrada e disponível
// para locação. Se disponível, alterar o status do carro de D para L. Se o carro já
// estiver locado, informar na tela.

// ● Devolução do Carro: informar a placa, validar se o mesmo está cadastrado e com
// status de locado. Caso sim, mudar o status de L para D. Se o carro não estiver
// locado, informar na tela

// ● Listar todos os carros, com seus dados cadastrais.

// ● Listar todos os carros de uma mesma marca.
// Observações:

// ✔ O programa deve manipular 02 arquivos binários, sendo: 01 para marcas e 01 para
// carros.
// ✔ As atualizações do status do carro devem ser devidamente registradas no arquivo de
// carros
// ✔ O código fonte do programa deve ser postado no Moodle, em local indicado pela
// professora.

int home()
{
    printf("################################################################################################################# \n");
    printf("## TELA DE MENU \n");
    printf("################################################################################################################# \n");
    printf("1. Cadastrar marcas \n");
    printf("2. Cadastrar carros \n");
    printf("3.  \n");
    printf("4. Sair \n");

    int menu;
    scanf("%i", &menu);
    return menu;
}

char criarArquivoMarca(){
    FILE *file;
    file = fopen("Marcas.txt", "w");
    fclose(file);
}

char criarArquivoCarros(){
    FILE *file;
    file = fopen("Carros.txt", "w");
    fclose(file);
}

char cadastrarMarca(){
    FILE *file;
    file = fopen("Marcas.txt", "a");

    if(file == NULL){
        printf("Arquivo nao pode ser aberto ou nao existe!");
        getchar();
        exit(1);
    }

    int whileControl;
    while(whileControl != 1){

        char marca[20];
        printf("Digite a marca:");
        scanf("%s \n", &marca);
        fputs(marca, file);

        char marcaCodigo[20];
        printf("Digite a marca:");
        scanf("%s \n", &marcaCodigo);
        fputs(marcaCodigo, file);

        char marcaDescricao[100];
        printf("Digite a marca:");
        scanf("%s \n", &marcaDescricao);
        fputs(marcaDescricao, file);

        char control;
        printf("Deseja inserir outra marca: Sim(s)/Nao(n)");
        scanf("%s \n", &control);

        if(strcpy(control, "n")){
            whileControl = 1;
            break;
        }

    }

    fclose(file);
}

char cadastrarCarro(){
    FILE *file;
    file = fopen("Marcas.txt", "a");

    if(file == NULL){
        printf("Arquivo nao pode ser aberto ou nao existe!");
        getchar();
        exit(1);
    }

    int whileControl;
    while(whileControl != 1){

        char marca[20];
        printf("Digite a marca:");
        scanf("%s \n", &marca);
        fputs(marca, file);

        char anoFabricacao[4];
        printf("Digite a marca:");
        scanf("%s \n", &anoFabricacao);
        fputs(anoFabricacao, file);

        char placa[7];
        printf("Digite a marca:");
        scanf("%s \n", &placa);
        fputs(placa, file);

        char control;
        printf("Deseja inserir outro carro: Sim(s)/Nao(n)");
        scanf("%s \n", &control);

        if(strcpy(control, "n")){
            whileControl = 1;
            break;
        }

    }

    fclose(file);
}

char lerCarros(){
    FILE *file;
    file = fopen("Carros.txt", "a");

    if(file == NULL){
        printf("Arquivo nao pode ser aberto ou nao existe!");
        getchar();
        exit(1);
    }

    char carros[1000];

    while(fgets(carros, 1000, file) != NULL){
        printf("%s", carros);
    }

    fclose(file);
}


int main(){

// #################################################################################################################
// ##    INICIANDO TELA DE MENU
// #################################################################################################################
int menu;

while(menu != 4){

    menu = home();

    // #################################################################################################################
    // ##    TELA DE CADASTRO DE MARCA
    // #################################################################################################################
    if (menu == 1)
    {
        int writeControl;
        if(writeControl != 1){
            criarArquivoMarca();
            writeControl = 1;
        }
        cadastrarMarca();
    }

    // #################################################################################################################
    // ##    TELA DE CADASTRO DE CARROS
    // #################################################################################################################
    if (menu == 2)
    {
        int writeControl;
        if(writeControl != 1){
            criarArquivoCarros();
            writeControl = 1;
        }
        cadastrarCarro();
    }

    // #################################################################################################################
    // ##    TELA DE LEITURA DE CARROS
    // #################################################################################################################
    if (menu == 3)
    {
        lerCarros();
    }
}

// #################################################################################################################
// ##    ENCERRANDO
// #################################################################################################################

printf("Saindo!...");
return 0;

}