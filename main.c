#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void Consultarsaldo();
void Consultarextrato();
void Depositar();
void Sacar();
void ComprarCriptomoedas();
void Vendercriptomoedas();
void Atualizar();


int main() {
	setlocale(LC_ALL, "portuguese");
	
	int resposta;
	
	while (1){
		int cont = 0;

		printf("            MENU            \n");
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


aaa


