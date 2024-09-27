#include "funcao.h"

//char cpf[],  char tipo[] , char moeda[], float valor_mudanca, float quantidade, float taxa, char sinal

int salvar_extrato(char cpf[], char tipo[], char moeda[], float *valor_mudanca, float *quantidade, char sinal, int taxa){

	FILE *arquivo;
	arquivo = fopen("extratos.txt", "a");

	if(arquivo == NULL){
		printf("Erro ao abrir o arquivo !!\n");
		return 1;
	}

	char data[11];
	obterDataAtual(data);

	// "%s; %s; %s; %s; %f; %f; %c; %f\n", cpf, data, tipo, moeda, quantidade, valor_mudanca, sinal, taxa
	//  DATA -------- Tipo -- Moeda --- Saldo(Moeda) --- sinal -- valor_mudanca --- moeda (sinal) quantidade;
	// 12/09/2024 --> venda: bitcoin | Saldo(moeda): (+ ou -) quantidade | moeda: (+ ou -) valor-final| taxa: taxa;
	fprintf(arquivo, "%s ; %s ; %s ; %s ;%f;%f; %c ;%d \n", cpf, data, tipo, moeda, *valor_mudanca, *quantidade, sinal, taxa);

	fclose(arquivo);
	return 0;
}

int Consultarextrato(cadastro *p, int index) { //somente le o arquivo

    FILE *arquivo;

    arquivo = fopen("extratos.txt","r");

    if(arquivo == NULL){
    	printf("Erro ao abrir o arquivo !!!\n");
    	return 1;
	}

	int verificador = 0;
	char linhas[255];
	
	while(fgets(linhas, 255 ,arquivo) != NULL){
		char cpf_linhas[12], moedas[12], tipo[20], data[11], sinal;
		float valor_mudanca, quantidade;
		int taxa;


		int result = sscanf(linhas, "%s ; %s ; %s ; %s ;%f;%f; %c ;%d \n", cpf_linhas, data, tipo, moedas, &valor_mudanca, &quantidade, &sinal, &taxa); // 12345678900; venda ; bitcoin; quantidade; ;
		//printf("%s(cpf_linhas)\n", cpf_linhas);
		//printf("%s(data)\n", data);
		//printf("%s(tipo)\n", tipo);
		//printf("%s(moedas)\n", moedas);
		//printf("%f(valor_mudanca)\n", valor_mudanca);
		//printf("%f(quantidade)\n", quantidade);
		//printf("%c(sinal)\n", sinal);
		//printf("%d(taxa)\n", taxa);

		if (result == 8 && strcmp(cpf_linhas, p[index].cpf) == 0) {
            verificador++;
            printf("%s --> %s: %s | Saldo(%s): %c %.2f | %s: %.2f | Taxa: %d \n",
                   data, tipo, moedas, moedas, sinal, quantidade, moedas, valor_mudanca, taxa);

        }
	}

	if(verificador == 0){
		printf("Nenhuma transação realizada.\n");
	}
	return 0;
}
