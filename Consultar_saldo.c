#include "funcao.h"

void Consultarsaldo(cadastro *p, int index) {
    printf("------------------------------\n");
    printf("Nome: %s\n", p[index].nome); 
    printf("CPF: %s\n", p[index].cpf);
    printf("Reais: %s\n", p[index].reais);
    printf("Bitcoin: %s\n", p[index].bitcoin);
    printf("Ethereum: %s\n", p[index].Ethereum);
    printf("Ripple: %s\n", p[index].Ripple);
    printf("------------------------------\n");
}

void consultar_saldo_de_um_Investidor() {
    char cpf[12];
    FILE *arquivo;
    char linha[256];
    int encontrado = 0;

    // Abrir o arquivo para leitura
    arquivo = fopen("usuarios.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Pedir o CPF do investidor
    printf("Digite o CPF do investidor: ");
    scanf("%s", cpf);

    // Ler cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo)) {
        char cpf_arquivo[12], nome[100], senha[10], reais[20], bitcoin[20], ethereum[20], ripple[20];

        // Dividir a linha nos campos
        sscanf(linha, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;\n]",
               cpf_arquivo, nome, senha, reais, bitcoin, ethereum, ripple);

        // Verificar se o CPF corresponde
        if (strcmp(cpf_arquivo, cpf) == 0) {
            encontrado = 1;

            // Exibir o saldo do investidor
            printf("===============================\n");
            printf("Nome: %s\n", nome);
            printf("Saldo em Reais: %s\n", reais);
            printf("Saldo em Bitcoin: %s\n", bitcoin);
            printf("Saldo em Ethereum: %s\n", ethereum);
            printf("Saldo em Ripple: %s\n", ripple);
            printf("===============================\n");
            break;
        }
    }

    fclose(arquivo);

    if (!encontrado) {
        printf("Investidor com CPF %s não encontrado!\n", cpf);
    }
}
