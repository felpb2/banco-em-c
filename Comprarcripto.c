#include "funcao.h"

int comprarcripto(cadastro *p,int numero_struct){

    moedas *valor;
	valor = malloc(sizeof(moedas) * 3);
    FILE *arquivo = fopen("arquivo_cripto.txt", "r");

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
    while (fgets(linhas, sizeof(linhas), arquivo)) {
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
    fclose(arquivo);


    	printf("Qual moeda deseja comprar?: \n");
		scanf("%d", &escolha);
		getchar();

		printf("Quantidade que deseja comprar?: \n");
		scanf("%f", &quantidade);
		getchar();

		printf("Digite sua senha: \n");
		scanf(" %s", senha);
		getchar();

		if (strcmp(senha, p[numero_struct].senha) != 0) {
	            printf("Senha incorreta!\n");
	            return 1;
	    }else{

			if(escolha == 1){

				compra = quantidade * (valor[0].bitcoin + valor[0].bitcoin* 0.02); // taxa de 2% para bitcoin

				if(atof(p[numero_struct].reais) < compra){
					printf("Não possui dinheiro suficiente !!\n");

				}else{

					conversao = atof(p[numero_struct].reais) - compra;           // modificar reais
					conversao2 = atof(p[numero_struct].bitcoin) + quantidade;   // modificar criptomoeda

					ExibirInformacoesCompra("bitcoin", 0.02, compra, conversao, conversao2);

					printf("Deseja continuar?(s/n): \n");
					scanf(" %c", &confirmacao);
					getchar();
					if(confirmacao == 's'){
						sprintf(saldo_novo, "%.2f", conversao);
						printf("Novo Saldo: %s\n",saldo_novo);
						strcpy(p[numero_struct].reais, saldo_novo);

						sprintf(saldo_cripto, "%.2f", conversao2);
						strcpy(p[numero_struct].bitcoin, saldo_cripto);

						printf("Transação feita com sucesso.\n");
						salvar_extrato(p[numero_struct].cpf, "Compra" , "bitcoin", &conversao2, &quantidade, '+', 2);

					}else{
						printf("Transação cancelada.\n");
					}

				}
			}else if(escolha == 2){

				compra = quantidade * (valor[0].Ethereum + valor[0].Ethereum* 0.01); // Cobra uma taxa de 1% na compra de ethereum

				if(atof(p[numero_struct].reais) < compra){
					printf("Não possui dinheiro suficiente !!\n");

				}else{
					conversao = atof(p[numero_struct].reais) - compra;
					conversao2 = atof(p[numero_struct].Ethereum) + quantidade;

					ExibirInformacoesCompra("Ethereum", 0.01, compra, conversao, conversao2);

					printf("Deseja continuar?(s/n): \n");
					scanf(" %c", &confirmacao);
					getchar();
					if(confirmacao == 's'){
						sprintf(saldo_novo, "%.2f", conversao);
						printf("Novo Saldo: %s\n",saldo_novo);
						strcpy(p[numero_struct].reais, saldo_novo);

						sprintf(saldo_cripto, "%.2f", conversao2);
						strcpy(p[numero_struct].Ethereum, saldo_cripto);


						printf("Transação feita com sucesso.\n");
						salvar_extrato(p[numero_struct].cpf, "Compra" , "Ethereum", &conversao2, &quantidade, '+', 1);
					}else{
						printf("Transação cancelada.\n");
					}

				}

			}else if(escolha == 3){

				compra = quantidade * (valor[0].Ripple + valor[0].Ripple* 0.01); // Cobra uma taxa de 1% na compra de ripple

				if(atof(p[numero_struct].reais) < compra){
		  			printf("Não possui dinheiro suficiente !!\n");

				}else{
					conversao = atof(p[numero_struct].reais) - compra;
					conversao2 = atof(p[numero_struct].Ripple) + quantidade;

					ExibirInformacoesCompra("Ripple", 0.01, compra, conversao, conversao2);

					printf("Deseja continuar?(s/n): \n");
					scanf(" %c", &confirmacao);
					getchar();
					if(confirmacao == 's'){
						sprintf(saldo_novo, "%.2f", conversao);
						printf("Novo saldo: %s\n",saldo_novo);
						strcpy(p[numero_struct].reais, saldo_novo);

			            sprintf(saldo_cripto, "%.2f", conversao2);
						strcpy(p[numero_struct].Ripple, saldo_cripto);

						printf("Transação feita com sucesso.\n");


						salvar_extrato(p[numero_struct].cpf, "Compra" , "Ripple", &conversao2, &quantidade, '+', 1);

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
