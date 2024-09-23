#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

typedef struct cadastro{
	char cpf[12];
	char nome[100];
	char senha[10];
	char reais[20]; 
	char bitcoin[20];
	char Ethereum[20];
	char Ripple[20];
	
	
}cadastro;

typedef struct moedas{
	float bitcoin;
	float Ethereum;
	float Ripple;

}moedas;


typedef struct atualizar_cripto{
	int numero;
	char nome[50];
	float cripto;
	char moeda[3];
	char taxas[20];
	
}atualizar_cripto;


//LIMPAR STRINGS
void limparstring(char *array){
	int i;
	for(i=0; i < 255 ; i++){
		array[i] = '\0';
	}
}

void Consultarsaldo(cadastro *p, int index);
void Consultarextrato();
void Depositar(cadastro *p, int index);
void Sacar(cadastro *p, int index);
int ComprarCriptomoedas(cadastro *p,int numero_struct);
void Vendercriptomoedas();
int Atualizar();

// MENU DOS INVESTIDORES
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
                Consultarsaldo(p, index);
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
                ComprarCriptomoedas(p, index);
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
                printf("Essa opção não é valida!!\n");
        }
        if (cont == 1) {
            break;
        }
    }
}

//LOGIN DOS INVESTIDORES
void login(cadastro *p){
 	
    char nome[255], senha[255], cpf[12];
    int posicao_struct = 0;
 	
    while (1) {
    	
        printf("------------------------------\n");
        printf("|BEM-VINDO AO BANCO DE CRIPTO\n");
        printf("|NOME: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';  // Remove o '\n' no final, se presente
        printf("|LOGIN: ");
        scanf("%s", cpf);
        getchar();
        printf("|SENHA(max 10): ");
        scanf("%s", senha);
        getchar();
        printf("------------------------------\n");
		
		
		
        int i, contador = 0;
		for (i = 0; i < 2; i++) {
	        if ( strcmp(cpf,p[i].cpf) == 0 && strcmp(nome,p[i].nome) == 0 && strcmp(senha,p[i].senha) == 0) { // Verifica se o CPF foi atribuído (para evitar linhas vazias)
	            contador++;
	            posicao_struct = i;
	            break;
	        }
    	}
    	if(contador != 0){
    		printf("BEM-VINDO AO BANCO\nUsuário: %s\n", nome);
	    	menu(p, posicao_struct);
	    	getchar(); // tirar o \n vindo da função
	    	char letra;
	    	printf("Deseja sair(s/n)?\n");
			scanf(" %c", &letra);
			getchar();
	    	if(letra == 's'){
	    		break;
			}else{
				continue;
			}
	    	
		}else{
			printf("Usuário não cadastrado ou dados incorretos\n");
			printf("Tente novamente !!!\n");
		}
    }
}

//CARREGAR USUARIOS DO ARQUIVO
int achar_usuario(cadastro *p) {
    FILE *arquivo;
    arquivo = fopen("usuarios.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    int posicao_struct = 0;
    char linhas[255];

    while (fgets(linhas, 255, arquivo)) {
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
            } else if (contador == 4) {
            	strcpy(p[posicao_struct].bitcoin, token);
			} else if (contador == 5){
				strcpy(p[posicao_struct].Ethereum, token);
			} else if (contador == 6){
				strcpy(p[posicao_struct].Ripple, token);
			}
            contador++;
            token = strtok(NULL, ";");
        }
        posicao_struct++;
    }

    fclose(arquivo);
    return 0;
}

void Consultarsaldo(cadastro *p, int index) {
	printf("------------------------------\n");
    printf("Nome: %s\n", p[index].nome);
    printf("CPF: %s\n", p[index].cpf);
    printf("Reais: %s\n", p[index].reais);
	printf("Bitcoin: %s\n", p[index].bitcoin);
	printf("Ripple: %s\n", p[index].Ethereum);
	printf("Ethereum: %s\n", p[index].Ripple);
	printf("------------------------------\n");
}

void Consultarextrato() {
    printf("Hello World!! 2\n");
}


void Depositar(cadastro *p, int index) {
    float valor;

	printf("------------------------------\n");
   	printf("Qual o valor que vai ser depositado: ");
   	scanf("%f", &valor);
   	float saldoAtual = atof(p[index].reais);
	saldoAtual += valor;
	sprintf(p[index].reais, "%.2f", saldoAtual);
	printf("Transação Bem-Sucedida! Novo valor: %.2f\n", saldoAtual);
	printf("%s\n", p[index].reais);
	printf("------------------------------\n");

}

void Sacar(cadastro *p, int index) {
    float valor;
	char senha[10];
	
	printf("Digite sua senha: \n");
	scanf(" %s", senha);
	
	
	if(strcmp(senha, p[index].senha) == 0){
		printf("------------------------------\n");
   		printf("Qual o valor que vai ser sacado: ");
   		scanf("%f", &valor);
   		float saldoAtual = atof(p[index].reais);
   		if (valor > saldoAtual){
   			printf("Não é possível realizar essa operação\n");
   		    printf("------------------------------\n");
	  	}else {
		   	saldoAtual -= valor;
		   	sprintf(p[index].reais, "%.2f", saldoAtual);
			printf("Transação Bem-Sucedida! Novo valor: %.2f\n", saldoAtual);
			printf("%s\n", p[index].reais);
			printf("------------------------------\n");
			}
	}else{
		printf("Senha incorreta !!!\n");
	}
}

int ComprarCriptomoedas(cadastro *p,int numero_struct){

	moedas *valor;
	valor = malloc(sizeof(moedas) * 3);

	FILE *arquivo;

	arquivo = fopen("arquivo_cripto.txt", "r");

	if(arquivo == NULL){
		printf("Erro em abrir o arquivo\n");
		return 1;
	}


	char linhas[255], saldo_novo[50], saldo_cripto[10];
	int escolha, contador = 0;
	float quantidade, compra, conversao;

	printf("------------------------------------------\n");
	while(fgets(linhas, 255, arquivo)){
		
		printf("%s\n", linhas);
  		char copia[strlen(linhas)];
		strcpy(copia, linhas);
		char *input = copia;
		
		int number1;
		float number2;
   		char name[20], sinal[2], final[100], lixo[3];

   	    int result = sscanf(input, "%d %s %f %s %s", &number1, name, &number2, lixo, final);
		
		if(contador == 0){
            valor[0].bitcoin = number2;
            contador++;
		}else if(contador == 1){
            valor[0].Ethereum = number2;
            contador++;
		}else{
            valor[0].Ripple = number2;
            contador = 0;
		}
		limparstring(input);

	}
	printf("------------------------------------------\n");

	char senha[10];
	
	printf("Qual moeda deseja comprar?: \n");
	scanf("%d", &escolha);
	printf("Quantidade que deseja comprar?: \n");
	scanf("%f", &quantidade);
	printf("Digite sua senha: \n");
	scanf(" %s", senha);
	
	if(strcmp(senha, p[numero_struct].senha) != 0){
		printf("Senha incorreta !!!\n");
		
	}else{
		if(escolha == 1){

			compra = quantidade * (valor[0].bitcoin + valor[0].bitcoin* 0.02); // taxa de 2% para bitcoin
	
			if(atof(p[numero_struct].reais) < compra){
				printf("Não possui dinheiro suficiente !!\n");
	
			}else{
				conversao = atof(p[numero_struct].reais) - compra;
				sprintf(saldo_novo, "%.2f", conversao);
				printf("Novo Saldo: %s\n",saldo_novo);
				strcpy(p[numero_struct].reais, saldo_novo);
				
				sprintf(saldo_cripto, "%f", quantidade);
				strcpy(p[numero_struct].bitcoin, saldo_cripto);
			}
		}else if(escolha == 2){
	
			compra = quantidade * (valor[0].Ethereum + valor[0].Ethereum* 0.01); // Cobra uma taxa de 1% na compra de ethereum
	
			if(atof(p[numero_struct].reais) < compra){
				printf("Não possui dinheiro suficiente !!\n");
	
			}else{
				conversao = atof(p[numero_struct].reais) - compra;
				sprintf(saldo_novo, "%.2f", conversao);
				printf("Novo Saldo: %s\n",saldo_novo);
				strcpy(p[numero_struct].reais, saldo_novo);
	
				sprintf(saldo_cripto, "%f", quantidade);
				strcpy(p[numero_struct].Ethereum, saldo_cripto);
			}
	
		}else if(escolha == 3){
	
			compra = quantidade * (valor[0].Ripple + valor[0].Ripple* 0.01); // Cobra uma taxa de 1% na compra de ripple
	
			if(atof(p[numero_struct].reais) < compra){
	  			printf("Não possui dinheiro suficiente !!\n");
	
			}else{
				conversao = atof(p[numero_struct].reais) - compra;
				sprintf(saldo_novo, "%.2f", conversao);
				printf("Novo saldo: %s\n",saldo_novo);
				strcpy(p[numero_struct].reais, saldo_novo);
	
	            sprintf(saldo_cripto, "%f", quantidade);
				strcpy(p[numero_struct].Ripple, saldo_cripto);
	
			}
	
		}else{
			printf("Escolha inválida\n");
		}		
	}

	fclose(arquivo);
	return 0;
}


int Atualizar(){
	
	 atualizar_cripto *criptos;
    criptos = malloc(sizeof(atualizar_cripto) * 3);
    
    FILE *arquivo;
    
    // Primeira etapa: abrir o arquivo em modo "r" para leitura
    arquivo = fopen("arquivo_cripto.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }

    // Buffer para armazenar linhas do arquivo
    char linhas[255];
    int contador = 0;

    // Leitura e processamento do arquivo
    printf("Lendo o conteúdo do arquivo...\n");
    while (fgets(linhas, sizeof(linhas), arquivo)) {
        printf("%s\n", linhas);  // Exibe a linha lida

        // Processa a linha lida
        char nome[50], moeda[3], taxas[20]; 
        float valor_cripto;
        int numero1;
        
        
        float randomNumber = (rand() / (float)RAND_MAX) * 10 - 5; //gerar numeros entra 5 e -5

        // Extração dos dados da linha
        int result = sscanf(linhas, "%d %s %f %s %s", &numero1, nome, &valor_cripto, moeda, taxas); //formatação do arquivo, mais eficiente do que usar indice
        
        if (result == 5) {
            // Armazena os dados na struct
            criptos[contador].numero = numero1;
            strcpy(criptos[contador].nome, nome);
            criptos[contador].cripto = valor_cripto + (randomNumber/100.00) * valor_cripto;
            strcpy(criptos[contador].moeda, moeda);
            strcpy(criptos[contador].taxas, taxas);
            contador++;
        }

        if (contador == 3) {
            contador = 0;  // Reinicia o contador se atingir 3 elementos
        }
    }
		
    fclose(arquivo);  // Fecha o arquivo após a leitura

	
    // Segunda etapa: abrir o arquivo em modo "w" para sobrescrever
    arquivo = fopen("arquivo_cripto.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }
	
    int i;
    for(i = 0;i < 3; i++){
    	char numero1[2];
    	itoa(criptos[i].numero, numero1, 10); // transformação de int para string
    	
    	char valor_crip[20];
    	sprintf(valor_crip, "%.2f", criptos[i].cripto); //transformação de float para string
    	
    	fprintf(arquivo, "%s %s %s %s %s\n", numero1, criptos[i].nome, valor_crip, criptos[i].moeda, criptos[i].taxas); //copiando no arquivo 
	}

    fclose(arquivo);  // Fecha o arquivo após a escrita

    // Libera a memória alocada
    free(criptos);

    printf("Atualização feita com sucesso !!! .\n");
    
    return 0;
}


void Vendercriptomoedas(){
	printf(" hello World!!\n"); //mesmo do comprar
}

// MENU PRINCIPAL
int main() {
	setlocale(LC_ALL, "portuguese");

    cadastro *pessoas;
    pessoas = malloc(2 * sizeof(pessoas)); //mudar para 10
    
    achar_usuario(pessoas);
	login(pessoas);
	
	system("pause");
	return 0;
}
