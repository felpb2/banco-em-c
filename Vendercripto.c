#include "funcao.h"

int vendercripto(cadastro *p,int numero_struct){

        moedas *valor;   // abre o struct onde vai salvar os valores das criptomoedas
		valor = malloc(sizeof(moedas) * 3); // só vai ter 3 moedas bitcoin, ethereum e ripple
	    FILE *arquivo = fopen("arquivo_cripto.txt", "r"); // abre o arquivo

	    if (arquivo == NULL) {
	        printf("Erro ao abrir o arquivo\n");
	        return 1;
	    }

	    char linhas[255];
	    int escolha, contador = 0;
	    float quantidade, venda, conversao, conversao2;
	    char confirmacao;
    	char saldo_novo[50], saldo_cripto[50];

	    // Leitura dos valores das criptomoedas
	    while (fgets(linhas, sizeof(linhas), arquivo)) {
	        int number1;
	        float number2;
	        char name[20];
			printf("%s\n", linhas);

	        int result = sscanf(linhas, "%d %s %f", &number1, name, &number2);// le o conteudo do arquivo e pegamos as partes que precisamos: numero , nome , valor
	        if (result == 3) {
	            if (contador == 0) {
	                valor[0].bitcoin = number2;
	            } else if (contador == 1) {
	                valor[0].Ethereum = number2;
	            } else {
	                valor[0].Ripple = number2;
	            }
	            contador++;
	        }
	    }
	    fclose(arquivo); // fecha o arquivo já que não é necessario

        printf("Qual moeda deseja vender?: \n");
		scanf("%d", &escolha);
		getchar(); // limpar buffer

		printf("Quantidade que deseja vender?: \n");
		scanf("%f", &quantidade);
		getchar(); // limpar buffer

		if(escolha == 1){ // tipo da moeda referente ao struct 

			venda = quantidade * (valor[0].bitcoin - valor[0].bitcoin* 0.03); // taxa de 3% para bitcoin --> venda

			if(atof(p[numero_struct].bitcoin) < quantidade){
				printf("Não possui essa quantidade de cripto !!\n");

			}else{
				conversao = atof(p[numero_struct].reais) + venda;   // Saldo Reais
				conversao2 = atof(p[numero_struct].bitcoin)	- quantidade; // Saldo cripto

				ExibirInformacoesCompra("bitcoin", 0.03, venda, conversao, conversao2); // funcao para mostrar as informacoes da compra/venda

				printf("Deseja continuar?(s/n): \n");
				scanf(" %c", &confirmacao);
				getchar(); // limpar buffer
				
				if(confirmacao == 's'){
					sprintf(saldo_novo, "%.2f", conversao); // float para string referente ao valor da venda + saldo atual
					printf("Novo Saldo: %s\n",saldo_novo);
					strcpy(p[numero_struct].reais, saldo_novo); // salvando no struct

					sprintf(saldo_cripto, "%.2f", conversao2);  // Novo saldo da cripto
					strcpy(p[numero_struct].bitcoin, saldo_cripto); // salvando no struct

					printf("Transação feita com sucesso.\n");

					salvar_extrato(p[numero_struct].cpf,  "Venda" ,"bitcoin", &conversao2, &quantidade, '-', 3); // salvando no extrato

				}else{
					printf("Transação cancelada.\n");
				}
			}
		}else if(escolha == 2){ // tipo da moeda referente ao struct 

			venda = quantidade * (valor[0].Ethereum - valor[0].Ethereum* 0.02); // Cobra uma taxa de 2% na venda de ethereum

			if(atof(p[numero_struct].Ethereum) < quantidade){
				printf("Não possui essa quantidade de cripto !!\n");

			}else{
				conversao = atof(p[numero_struct].reais) + venda; // Saldo Reais
				conversao2 = atof(p[numero_struct].Ethereum) - quantidade; // Saldo cripto

				ExibirInformacoesCompra("Ethereum", 0.02, venda, conversao, conversao2); // funcao para mostrar as informacoes da compra/venda

				printf("Deseja continuar?(s/n): \n");
				scanf(" %c", &confirmacao);
				getchar(); // limpar buffer
				
				if(confirmacao == 's'){
					sprintf(saldo_novo, "%.2f", conversao); // float para string referente ao valor da venda + saldo atual
					printf("Novo Saldo: %s\n",saldo_novo);
					strcpy(p[numero_struct].reais, saldo_novo);  // salvando no struct

					sprintf(saldo_cripto, "%.2f", conversao2); // Novo saldo da cripto
					strcpy(p[numero_struct].Ethereum, saldo_cripto); // salvando no struct

					printf("Transação feita com sucesso.\n");

					salvar_extrato(p[numero_struct].cpf,  "Venda" ,"Ethereum", &conversao2, &quantidade, '-', 2); // salvando no extrato

				}else{
					printf("Transação cancelada.\n");

				}
			}

		}else if(escolha == 3){ // tipo da moeda referente ao struct 

			venda = quantidade * (valor[0].Ripple - valor[0].Ripple* 0.01); // Cobra uma taxa de 1% na venda de ripple

			if(atof(p[numero_struct].Ripple) < quantidade){  // caso não possua 
	  			printf("Não possui essa quantidade de cripto !!\n");

			}else{
				conversao = atof(p[numero_struct].reais) + venda;  // Saldo Reais
				conversao2 = atof(p[numero_struct].Ripple)	- quantidade; // Saldo cripto

				ExibirInformacoesCompra("Ripple", 0.01, venda, conversao, conversao2); // funcao para mostrar as informacoes da compra/venda

				printf("Deseja continuar?(s/n): \n");
				scanf(" %c", &confirmacao);
				getchar(); // limpar buffer
				
				if(confirmacao == 's'){
					sprintf(saldo_novo, "%.2f", conversao); // float para string referente ao valor da venda + saldo atual
					printf("Novo saldo: %s\n",saldo_novo);
					strcpy(p[numero_struct].reais, saldo_novo); // salvando no struct

		            sprintf(saldo_cripto, "%.2f", conversao2); // Novo saldo da cripto
					strcpy(p[numero_struct].Ripple, saldo_cripto);  // salvando no struct

					printf("Transação feita com sucesso.\n");
 
					salvar_extrato(p[numero_struct].cpf, "Venda" ,"Ripple", &conversao2, &quantidade, '-', 1); // salvando no extrato

				}else{
					printf("Transação cancelada.\n"); 
				}
			}

		}else{
			printf("Escolha inválida\n");
		}
	return 0;
}



