#include "funcao.h"

int achar_usuario(cadastro *p) {
    FILE *arquivo = fopen("usuarios.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    char linhas[255];
    int posicao_struct = 0;
    while (fgets(linhas, 255, arquivo)) {   // enquanto tiver recebendo linhas vai continuar no while
        char *token = strtok(linhas, ";");   // delimitador para cortar a linha em strings ';'
        int contador = 0;  // indentificar a posição de cada string recortada no seu respectivo lugar na struct

        while (token != NULL) { // a linha precisa ter alguma informação se for vazia não vai prosseguir
            if (contador == 0) {
                strcpy(p[posicao_struct].cpf, token);  
            } else if (contador == 1) {
                strcpy(p[posicao_struct].nome, token);
            } else if (contador == 2) {
                strcpy(p[posicao_struct].senha, token);
            } else if (contador == 3) {
                strcpy(p[posicao_struct].reais, token);
            } else if (contador == 4) {
                strcpy(p[posicao_struct].bitcoin, token);
            } else if (contador == 5) {
                strcpy(p[posicao_struct].Ethereum, token);
            } else if (contador == 6) {
            	token[strcspn(token, "\n")] = '\0';    // tirar o \n do ultimo caracter para não ficar no buffer do teclado e evitar espaços indesejados 
                strcpy(p[posicao_struct].Ripple, token);  // struct

            }
            contador++;
            token = strtok(NULL, ";");  
        }
        posicao_struct++;
    }

    fclose(arquivo); // fecha arquivo
    return 0;
}

int login(cadastro *p){
    char nome[255], senha[255], cpf[12];
    int posicao_struct = -1;

    while (1) {
        printf("------------------------------\n");
        printf("| BEM-VINDO AO BANCO DE CRIPTO |\n");

        printf("| NOME: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';  // Remove o '\n' no final

        printf("| LOGIN: ");
        scanf("%s", cpf);
        getchar();  // Limpa buffer

        printf("| SENHA (max 10): ");
        scanf("%s", senha);
        getchar();  // Limpa buffer

        printf("------------------------------\n");

        int i, contador = 0;
        for (i = 0; i < 10; i++) {  // Carregar os usuários que estão cadastrados verificando se o cpf, nome e senha batem com os dados preenchidos
            if (strcmp(cpf, p[i].cpf) == 0 && strcmp(nome, p[i].nome) == 0 && strcmp(senha, p[i].senha) == 0) {
                contador++;
                posicao_struct = i;
                break; // caso achou a semelhanca não precisa continuar vendo.
            }
        }

        if(contador != 0){
            printf("BEM-VINDO AO BANCO\nUsuário: %s\n", nome);
            menu(p, posicao_struct);

            char letra;
            printf("Deseja sair (s/n)?\n");   // opcao de saida 
            scanf(" %c", &letra);
            getchar();  // Limpa buffer
            if(letra == 's'){
                return 0;
            }
        }else {
            printf("Usuário não cadastrado ou dados incorretos\n");
            printf("Tente novamente!\n");
        }
    }
}
