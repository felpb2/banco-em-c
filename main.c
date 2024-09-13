#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Funções do menu
void login();
void menu();
void Consultarsaldo();
void Consultarextrato();
void Depositar();
void Sacar();
void ComprarCriptomoedas();
void Vendercriptomoedas();
void Atualizar();

int main() {
    setlocale(LC_ALL, "portuguese");

    login();

    return 0;
}

void login(){
    int resposta;
    char nome[255];
    char senha[255];
    char cpf[12];
    char certo_nome[] = "Gustavo";
    char senha_correta[] = "123456";
    char cpf_certo[] = "12345678912";

    while (1) {
        printf("----------------------------\n");
        printf("|BEM-VINDO AO BANCO DE CRIPTO|\n");
        printf("|NOME: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';  // Remove o '\n' no final, se presente
        printf("|LOGIN: ");
        scanf("%s", cpf);
        getchar();
        printf("|SENHA: ");
        scanf("%s", senha);
        getchar();
        printf("----------------------------\n");

        if (strcmp(nome, certo_nome) == 0 && strcmp(cpf, cpf_certo) == 0 && strcmp(senha, senha_correta) == 0) {
            menu();
        } else {
            printf("Erro ao logar!!\n");
        }
    }
}
void menu() {
    int resposta;

    while (1) {
        printf("            MENU            \n");
        printf("----------------------------\n");
        printf("| 1 .Consultar saldo       |\n");
        printf("| 2 .Consultar extrato     |\n");
        printf("| 3 .Depositar             |\n");
        printf("| 4 .Sacar                 |\n");
        printf("| 5 .Comprar criptomoeda   |\n");
        printf("| 6 .Vender criptomoedas   |\n");
        printf("| 7 .Atualizar cripto      |\n");
        printf("| 8 .Sair                  |\n");
        printf("----------------------------\n");
        scanf("%d", &resposta);
        getchar();  

        switch (resposta) {
            case 1:
                Consultarsaldo();
                break;
            case 2:
                Consultarextrato();
                break;
            case 3:
                Depositar();
                break;
            case 4:
                Sacar();
                break;
            case 5:
                ComprarCriptomoedas();
                break;
            case 6:
                Vendercriptomoedas();
                break;
            case 7:
                Atualizar();
                break;
            case 8:
                return; 
            default:
                printf("Essa opção não é valida!!\n");
        }
    }
}

void Consultarsaldo() {
    printf("Hello World!! 1\n");
}

void Consultarextrato() {
    printf("Hello World!! 2\n");
}

void Depositar() {
    printf("Hello World!! 3\n");
}

void Sacar() {
    printf("Hello World!! 4\n");
}

void ComprarCriptomoedas() {
    printf("Hello World!! 5\n");
}

void Vendercriptomoedas() {
    printf("Hello World!! 6\n");
}

void Atualizar() {
    printf("Hello World!! 7\n");
}
