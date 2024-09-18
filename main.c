#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct cadastro{
	char cpf[12];
	char nome[100];
	char senha[10];
	char reais[20]; 

}cadastro;


void Consultarsaldo();
void Consultarextrato();
void Depositar();
void Sacar();
void ComprarCriptomoedas();
void Vendercriptomoedas();
void Atualizar();


void limparstring(char *array){
	int i;
	for(i=0; i < 255 ; i++){
		array[i] = '\0';
	}
}


void menu(cadastro *p){
	int resposta;

	while (1){
		int cont = 0;

		printf("----------------------------\n");
	    printf("| 1 .Consultar saldo       |\n");
	    printf("| 2 .Consultar extrato     |\n");
	    printf("| 3 .Deposita              |\n");
	    printf("| 4 .Sacar                 |\n");
	    printf("| 5 .Comprar criptomoeda   |\n");
	    printf("| 6 .Vender criptomoedas   |\n");
	    printf("| 7 .Atualizar cripto      |\n");
	    printf("| 8 .Sair                  |\n");
	    printf("----------------------------\n");
	    scanf("%d", &resposta);



		switch (resposta){
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
				cont++;
				break;
			default:
				printf("Essa opção não é valida!!\n");
		}
		if (cont == 1){
			break;
		}
	}
}



void login(cadastro *p){
 	
	achar_usuario(p);
 	
    char nome[255];
    char senha[255];
    char cpf[12];
 	
    while (1) {
    	
        printf("------------------------------\n");
        printf("|BEM-VINDO AO BANCO DE CRIPTO\n");
        printf("|NOME: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';  // Remove o '\n' no final, se presente
        printf("|LOGIN: ");
        scanf("%s", cpf);
        getchar();
        printf("|SENHA: ");
        scanf("%s", senha);
        getchar();
        printf("------------------------------\n");
		
		
		printf("%s\n", p[0].cpf);
		printf("%s\n", p[0].nome);
		printf("%s\n", p[0].senha);
		printf("%s\n", p[0].reais);
		
		printf("%s\n", p[1].cpf);
		printf("%s\n", p[1].nome);
		printf("%s\n", p[1].senha);
		printf("%s\n", p[1].reais);
	
		
        int i, contador = 0;
		for (i = 0; i < 2; i++) {
	        if ( strcmp(cpf,p[i].cpf) == 0 && strcmp(nome,p[i].nome) == 0 && strcmp(senha,p[i].senha) == 0) { // Verifica se o CPF foi atribuído (para evitar linhas vazias)
	            contador++;
	        }
    	}
    	if(contador != 0){
    		printf("BEM-VINDO AO BANCO\nUsuário: %s\n", nome);
	    	menu(p);
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

int achar_usuario(cadastro *p){
	
	FILE *arquivo;
	
	arquivo = fopen("usuarios.txt","r");
	
	if(arquivo == NULL){ // erro ao abrir o código
		printf("Erro em abrir o arquivo\n");
		return 1;
	}

	int  posicao_struct = 0;
    char linhas[255];
	
	while(fgets(linhas, 255, arquivo)){ //ler as linha até o fim do arquivo
		
		char sequencia_palavra[255];
		char divisao_sequencia[255];
		
		int index_divisao = 0, contador = 0;
		int i;
		for(i=0; i < strlen(linhas); i++){
			if(linhas[i] != ';'){
				divisao_sequencia[index_divisao] = linhas[i];
				index_divisao++;
				if(i == strlen(linhas) - 1){
					
					strcpy(p[posicao_struct].reais, divisao_sequencia);
					
					contador = 0;
					limparstring(divisao_sequencia);
					index_divisao = 0;	
				}
			}else if(linhas[i] == ';'){
				
				if(contador == 0){
					strcpy(p[posicao_struct].cpf, divisao_sequencia);
					contador++;
				}else if(contador == 1){
					strcpy(p[posicao_struct].nome, divisao_sequencia);
					contador++;
				}else if(contador == 2){
					strcpy(p[posicao_struct].senha, divisao_sequencia);
					contador++;
				}
				limparstring(divisao_sequencia);
				index_divisao = 0;	
			}
		}
		posicao_struct++;
	
		
	
		/* -- Outra opção usando strtok -- 
		char *token;
        int contador = 0;

        // Primeira divisão da string pelos pontos-e-vírgula 
        token = strtok(linhas, ";");
        while (token != NULL) {
            if (contador == 0) {
                strcpy(p[posicao].cpf, token); // CPF
            } else if (contador == 1) {
                strcpy(p[posicao].nome, token); // Nome
            } else if (contador == 2) {
                strcpy(p[posicao].senha, token); // Senha
            } else if (contador == 3) {
                strcpy(p[posicao].reais, token); // Saldo
            }
            contador++;
            token = strtok(NULL, ";"); // A cada chamada de strtok, ele retorna a próxima parte da string, ou seja, o próximo token
            // continua de onde parou, se não tiver nada --> retorna NULL, por isso o (token != NULL);								
        }
        posicao++;
        */
	}
	fclose(arquivo);
	return 0;
}



int main() {
	setlocale(LC_ALL, "portuguese");

    cadastro *pessoas;
    pessoas = malloc(2 * sizeof(pessoas));
    
	login(pessoas);
	
	system("pause");
	return 0;
}


void Consultarsaldo(){
	printf("Hello World!! 1\n");
}

void Consultarextrato(){
	printf("Hello World!! 2\n");
}

void Depositar(){
	printf("Hello World!! 3\n");
}

void Sacar(){
	printf("Hello World!! 4\n");
}

void ComprarCriptomoedas(){
	printf("Hello World!! 5\n");
}

void Vendercriptomoedas(){
	printf("Hello World!! 6\n");
}

void Atualizar(){
	printf("Hello World!! 7\n");
}


