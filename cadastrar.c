#include "funcao.h"


// falta as moedas fazer funcao
void cadastrar_investidor() {
    cadastro novo;
    FILE *arquivo;

    // Abrir o arquivo em modo de adicionar
    arquivo = fopen("usuarios.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Coletar dados do novo investidor
    printf("Digite o CPF: ");
    scanf("%s", novo.cpf);
    printf("Digite o nome: ");
    scanf(" %[^\n]", novo.nome);
    printf("Digite a senha: ");
    scanf("%s", novo.senha);
    printf("Digite o saldo inicial em reais: ");
    scanf("%s", novo.reais);

    // Inicializar saldos de criptomoedas com zero
    strcpy(novo.bitcoin, "0.00");
    strcpy(novo.Ethereum, "0.00");
    strcpy(novo.Ripple, "0.00");

    // Escrever os dados no arquivo no formato correto
    fprintf(arquivo, "%s;%s;%s;%s;%s;%s;%s\n", novo.cpf, novo.nome, novo.senha, novo.reais, novo.bitcoin, novo.Ethereum, novo.Ripple);

    // Fechar o arquivo
    fclose(arquivo);

    printf("Investidor cadastrado com sucesso!\n");
}

void excluir_investidor() {
    char cpf[12];
    FILE *arquivo, *temp;
    char linha[256];
    int encontrado = 0;

    // Abrir o arquivo original para leitura e um arquivo temporário para escrita
    arquivo = fopen("usuarios.txt", "r");
    temp = fopen("temp.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Pedir o CPF do investidor a ser excluído
    printf("Digite o CPF do investidor a ser excluído: ");
    scanf("%s", cpf);

    // Ler cada linha do arquivo e copiar para o arquivo temporário, exceto a linha do CPF a ser excluído
    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strncmp(linha, cpf, 11) != 0) {  // Comparar os primeiros 11 dígitos para verificar o CPF
            fputs(linha, temp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivo);
    fclose(temp);

    // Substituir o arquivo original pelo temporário
    remove("usuarios.txt");
    rename("temp.txt", "usuarios.txt");

    if (encontrado) {
        printf("Investidor excluído com sucesso!\n");
    } else {
        printf("Investidor não encontrado!\n");
    }
}