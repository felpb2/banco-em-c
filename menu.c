#include "funcao.h"

int salvar_dados(cadastro *p){
    FILE *arquivo = fopen("usuarios.txt", "w");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

	int i;
    for(i = 0; i < 10; i++){   // Salvar os dados atualizados no arquivo
        fprintf(arquivo, "%s;%s;%s;%s;%s;%s;%s\n", p[i].cpf, p[i].nome, p[i].senha, p[i].reais, p[i].bitcoin, p[i].Ethereum, p[i].Ripple);
        //printf("%s;%s;%s;%s;%s;%s;%s\n", p[i].cpf, p[i].nome, p[i].senha, p[i].reais, p[i].bitcoin, p[i].Ethereum, p[i].Ripple); -- teste
    }

    fclose(arquivo);
    return 0;
}

int menu(cadastro *p, int index) {
    int resposta;
    while (1) {
        printf("----------------------------\n");
        printf("| 1. Consultar saldo       |\n");
        printf("| 2. Consultar extrato     |\n");
        printf("| 3. Depositar             |\n");
        printf("| 4. Sacar                 |\n");
        printf("| 5. Comprar criptomoeda   |\n");
        printf("| 6. Vender criptomoedas   |\n");
        printf("| 7. Atualizar cripto      |\n");
        printf("| 8. Sair                  |\n");
        printf("----------------------------\n");
        scanf("%d", &resposta);
        getchar();

        switch (resposta) {
            case 1:
                Consultarsaldo(p, index);
                break;
            case 2:
                Consultarextrato(p, index);
                break;
            case 3:
                Depositar(p, index);
                salvar_dados(p);
                break;
            case 4:
                Sacar(p, index);
                salvar_dados(p);
                break;
            case 5:
                comprarcripto(p, index);
                salvar_dados(p);
                break;
            case 6:
                vendercripto(p, index);
                salvar_dados(p);
                break;
            case 7:
                Atualizar(); // atualizar os valores das criptomoedas
                break;
            case 8:
                return 0;  // Sair do menu
            default:
                printf("Essa opção não é válida!\n");
        }
    }
}
