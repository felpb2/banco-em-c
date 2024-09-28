#include "funcao.h"

int comprarcripto(cadastro *p,int numero_struct){

    moedas *valor;  // abre o struct onde vai salvar os valores das criptomoedas
	valor = malloc(sizeof(moedas) * 3); // só vai ter 3 moedas bitcoin, ethereum e ripple
    FILE *arquivo = fopen("arquivo_cripto.txt", "r"); // abre o arquivo

    if (arquivo == NULL) { 
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    char linhas[255];
    int escolha, contador = 0;
    float quantidade, compra, venda, conversao, conversao2;

    char confirmacao, senha[11];
    char saldo_novo[50], saldo_cripto[50];

    // Leitura dos valores das criptomoedas
    while (fgets(linhas, sizeof(linhas), arquivo)) {   // le o conteudo do arquivo e pegamos as partes que precisamos: numero , nome , valor
        int number1;
        float number2;
        char name[20];
		printf("%s\n", linhas);

        int result = sscanf(linhas, "%d %s %f", &number1, name, &number2);
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


    	printf("Qual moeda deseja comprar?: \n");
		scanf("%d", &escolha); 
		getchar(); // limpar buffer

		printf("Quantidade que deseja comprar?: \n");
		scanf("%f", &quantidade);
		getchar(); // limpar buffer

		printf("Digite sua senha: \n");
		scanf(" %s", senha);
		getchar(); // limpar buffer

		if (strcmp(senha, p[numero_struct].senha) != 0) { // ve se a senha está correta
	            printf("Senha incorreta!\n");
	            return 1;
	    }else{

			if(escolha == 1){ // tipo da moeda referente ao struct 

				compra = quantidade * (valor[0].bitcoin + valor[0].bitcoin* 0.02); // taxa de 2% para bitcoin

				if(atof(p[numero_struct].reais) < compra){ // caso não possua dinheiro suficiente
					printf("Não possui dinheiro suficiente !!\n");

				}else{

					conversao = atof(p[numero_struct].reais) - compra;         // Reais depois da compra
					conversao2 = atof(p[numero_struct].bitcoin) + quantidade;   // criptomoeda atualizada

					ExibirInformacoesCompra("bitcoin", 0.02, compra, conversao, conversao2); // funcao para mostrar as informacoes da compra/venda

					printf("Deseja continuar?(s/n): \n");
					scanf(" %c", &confirmacao); //confirmacao
					getchar(); // limpar buffer
					if(confirmacao == 's'){
						sprintf(saldo_novo, "%.2f", conversao); //float para string referente aos reais
						printf("Novo Saldo: %s\n",saldo_novo);
						strcpy(p[numero_struct].reais, saldo_novo); // salvando no struct

						sprintf(saldo_cripto, "%.2f", conversao2); //float para string referente aos reais
						strcpy(p[numero_struct].bitcoin, saldo_cripto); // salvando no struct 

						printf("Transação feita com sucesso.\n");
						salvar_extrato(p[numero_struct].cpf, "Compra" , "bitcoin", &conversao2, &quantidade, '+', 2); // salvando no extrato

					}else{
						printf("Transação cancelada.\n");
					}

				}
			}else if(escolha == 2){ // tipo da moeda referente ao struct 

				compra = quantidade * (valor[0].Ethereum + valor[0].Ethereum* 0.01); // Cobra uma taxa de 1% na compra de ethereum

				if(atof(p[numero_struct].reais) < compra){ // caso não possua dinheiro suficiente
					printf("Não possui dinheiro suficiente !!\n");

				}else{
					conversao = atof(p[numero_struct].reais) - compra;
					conversao2 = atof(p[numero_struct].Ethereum) + quantidade;

					ExibirInformacoesCompra("Ethereum", 0.01, compra, conversao, conversao2); // funcao para mostrar as informacoes da compra/venda

					printf("Deseja continuar?(s/n): \n");
					scanf(" %c", &confirmacao); //confirmacao
					getchar(); // limpar buffer
					if(confirmacao == 's'){
						sprintf(saldo_novo, "%.2f", conversao); //float para string referente aos reais
						printf("Novo Saldo: %s\n",saldo_novo);
						strcpy(p[numero_struct].reais, saldo_novo); // salvando no struct

						sprintf(saldo_cripto, "%.2f", conversao2); //float para string referente aos reais
						strcpy(p[numero_struct].Ethereum, saldo_cripto); // salvando no struct


						printf("Transação feita com sucesso.\n");
						salvar_extrato(p[numero_struct].cpf, "Compra" , "Ethereum", &conversao2, &quantidade, '+', 1); // salvando no extrato
					}else{
						printf("Transação cancelada.\n");
					}

				}

			}else if(escolha == 3){ // tipo da moeda referente ao struct 

				compra = quantidade * (valor[0].Ripple + valor[0].Ripple* 0.01); // Cobra uma taxa de 1% na compra de ripple

				if(atof(p[numero_struct].reais) < compra){ // caso não possua dinheiro suficiente
		  			printf("Não possui dinheiro suficiente !!\n");

				}else{
					conversao = atof(p[numero_struct].reais) - compra;
					conversao2 = atof(p[numero_struct].Ripple) + quantidade;

					ExibirInformacoesCompra("Ripple", 0.01, compra, conversao, conversao2); // funcao para mostrar as informacoes da compra/venda

					printf("Deseja continuar?(s/n): \n");
					scanf(" %c", &confirmacao); //confirmacao
					getchar(); // limpar buffer
					if(confirmacao == 's'){
						sprintf(saldo_novo, "%.2f", conversao); //float para string referente aos reais
						printf("Novo saldo: %s\n",saldo_novo);  
						strcpy(p[numero_struct].reais, saldo_novo); // salvando no struct

			            sprintf(saldo_cripto, "%.2f", conversao2);     //float para string referente aos reais
						strcpy(p[numero_struct].Ripple, saldo_cripto);  // salvando no struct
 
						printf("Transação feita com sucesso.\n");


						salvar_extrato(p[numero_struct].cpf, "Compra" , "Ripple", &conversao2, &quantidade, '+', 1); // salvando no extrato

					}else{
						printf("Transação cancelada.\n");
					}
				}

		}else{
			printf("Escolha inválida\n");
		}
	}

    return 0;
}
