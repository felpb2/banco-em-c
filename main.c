#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX 256

typedef struct cadastro {
    char cpf[12];
    char nome[100];
    char senha[10];
    char reais[20]; 
} cadastro;

void Consultarsaldo();
void Consultarextrato();
void Sacar();
void ComprarCriptomoedas();
void Vendercriptomoedas();
void Atualizar();


void limparstring(char *array) {
    int i;
    for (i = 0; i < MAX; i++) {
        array[i] = '\0';
    }
}

void menu(cadastro *p, int index) {
    int resposta;
    while (1) {
        int cont = 0;

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

        switch (resposta) {
            case 1:
                Consultarsaldo();
                break;
            case 2:
                Consultarextrato();
                break;
            case 3:
                Depositar(p, index);
                break;
            case 4:
                Sacar(p, index);
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
                cont++;
                break;
            default:
                printf("Essa op��o n�o � valida!!\n");
        }
        if (cont == 1) {
            break;
        }
    }
}

void login(cadastro *p) {
    achar_usuario(p);

    char nome[255];
    char senha[255];
    char cpf[12];
    int index = 0;

    while (1) {
        printf("------------------------------\n");
        printf("| BEM-VINDO AO BANCO DE CRIPTO |\n");
        printf("| NOME: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';  // Remove o '\n' no final, se presente
        printf("| LOGIN: ");
        scanf("%s", cpf);
        getchar();
        printf("| SENHA: ");
        scanf("%s", senha);
        getchar();
        printf("------------------------------\n");

        int i, contador = 0;
        for (i = 0; i < 2; i++) {
            if (strcmp(cpf, p[i].cpf) == 0 && strcmp(nome, p[i].nome) == 0 && strcmp(senha, p[i].senha) == 0) {
                contador++;
                index = i;
                break;
            }
        }

        if (contador != 0) {
            printf("BEM-VINDO AO BANCO\nUsu�rio: %s\n", nome);
            menu(p, index);
            getchar(); // tirar o \n vindo da fun��o
            char letra;
            printf("Deseja sair(s/n)?\n");
            scanf(" %c", &letra);
            getchar();
            if (letra == 's') {
                break;
            } else {
                continue;
            }
        } else {
            printf("Usu�rio n�o cadastrado ou dados incorretos\n");
            printf("Tente novamente !!!\n");
        }
    }
}

int achar_usuario(cadastro *p) {
    FILE *arquivo;
    arquivo = fopen("usuarios.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    int posicao_struct = 0;
    char linhas[MAX];
    
    while (fgets(linhas, MAX, arquivo)) {
        char *token = strtok(linhas, ";");
        int contador = 0;

        while (token != NULL) {
            if (contador == 0) {
                strcpy(p[posicao_struct].cpf, token);
            } else if (contador == 1) {
                strcpy(p[posicao_struct].nome, token);
            } else if (contador == 2) {
                strcpy(p[posicao_struct].senha, token);
            } else if (contador == 3) {
                strcpy(p[posicao_struct].reais, token);
            }
            contador++;
            token = strtok(NULL, ";");
        }
        posicao_struct++;
    }
    
    fclose(arquivo);
    return 0;
}

void Consultarsaldo() {
    printf("Hello World!! 1\n");
}

void Consultarextrato() {
    printf("Hello World!! 2\n");
}

void Depositar(cadastro *p, int index) {
    float valor;
	   
   	printf("Qual o valor que vai ser depositado: ");
   	scanf("%f", &valor);
   	float saldoAtual = atof(p[index].reais);
	saldoAtual += valor;
	sprintf(p[index].reais, "%.2f", saldoAtual);
	printf("Transa��o Bem-Sucedida! Novo valor: %.2f\n", saldoAtual);
	printf("%s\n", p[index].reais);
	

}

void Sacar(cadastro *p, int index) {
    float valor;
	   
   	printf("Qual o valor que vai ser sacado: ");
   	scanf("%f", &valor);
   	float saldoAtual = atof(p[index].reais);
   	if (valor > saldoAtual){
   		printf("N�o � poss�vel realizar essa opera��o\n");
	   } else {
		   	saldoAtual -= valor;
		   	sprintf(p[index].reais, "%.2f", saldoAtual);
			printf("Transa��o Bem-Sucedida! Novo valor: %.2f\n", saldoAtual);
			printf("%s\n", p[index].reais);
		
		}
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



int main() {
    setlocale(LC_ALL, "portuguese");

    cadastro *pessoas;
    pessoas = malloc(2 * sizeof(cadastro));

    achar_usuario(pessoas);
    login(pessoas);

    free(pessoas);
    system("pause");
    return 0;
}

