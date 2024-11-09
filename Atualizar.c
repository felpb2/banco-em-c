#include "funcao.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>  // Para a função rand()

int Atualizar() {
    atualizar_cripto *criptos = malloc(sizeof(atualizar_cripto) * 10); // Aloca memória para 10 criptomoedas inicialmente
    if (criptos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    FILE *arquivo = fopen("arquivo_cripto.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        free(criptos);
        return 1;
    }

    // Buffer para armazenar as linhas do arquivo
    char linhas[255];
    int contador = 0;

    printf("Lendo o conteudo do arquivo...\n");

    // Leitura e processamento do arquivo
    while (fgets(linhas, sizeof(linhas), arquivo)) {

        // Se necessário, realoca mais memória para armazenar mais criptomoedas
        if (contador % 10 == 0 && contador != 0) {
            atualizar_cripto *temp = realloc(criptos, sizeof(atualizar_cripto) * (contador + 10));
            if (temp == NULL) {
                printf("Erro ao realocar memoria.\n");
                free(criptos);
                fclose(arquivo);
                return 1;
            }
            criptos = temp;
        }

        // Variáveis para capturar os dados da linha
        char nome[50], moeda[3], taxas[20];
        float valor_cripto;
        int numero1;

        float randomNumber = ((rand() / (float)RAND_MAX) * 10 - 5) / 100.0; // Gera variação entre -5% e +5%

        // Extração dos dados da linha
        int result = sscanf(linhas, "%d %s %f %s %s", &numero1, nome, &valor_cripto, moeda, taxas);

        if (result == 5) {
            // Armazena os dados na struct, aplicando a variação aleatória
            criptos[contador].numero = numero1;
            strcpy(criptos[contador].nome, nome);
            criptos[contador].cripto = valor_cripto * (1 + randomNumber); // Aplica a variação
            strcpy(criptos[contador].moeda, moeda);
            strcpy(criptos[contador].taxas, taxas);
            contador++;
        }
    }

    fclose(arquivo); // Fecha o arquivo após a leitura

    // Segunda etapa: abrir o arquivo em modo "w" para sobrescrever
    arquivo = fopen("arquivo_cripto.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        free(criptos);
        return 1;
    }

    // Escrita dos valores atualizados no arquivo
    for (int i = 0; i < contador; i++) {
        fprintf(arquivo, "%d %s %.2f %s %s\n", criptos[i].numero, criptos[i].nome,
                criptos[i].cripto, criptos[i].moeda, criptos[i].taxas);
    }

    fclose(arquivo); // Fecha o arquivo após a escrita
    free(criptos);   // Libera a memória alocada

    printf("Atualizacao feita com sucesso !!!\n");

    return 0;
}
