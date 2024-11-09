#include "funcao.h"

// MENU PRINCIPAL
int main(){
	setlocale(LC_ALL, "portuguese");

	while (1){

		int res, tamanho_usuario = 0, tamanho_adm = 0;

		printf("+--------------------------+\n");
		printf("|BEM-VINDO AO BANCO CRIPTO |\n");	
		printf("|Qual menu deseja acessar ?|\n");
		printf("+--------------------------+\n");
		printf("|1. Investirdor            |\n");
		printf("|2. Administrador          |\n");
		printf("|3. Sair                   |\n");
		printf("|--------------------------|\n");
		scanf("%d", &res);
		getchar();
		
		cadastro *pessoas;
		if (res == 1){
			
			pessoas = malloc(10 * sizeof(cadastro)); // max 10 usuarios

			tamanho_usuario = achar_usuario(pessoas);
			login(pessoas, tamanho_usuario);

		} else if(res == 2){
			
			admin *tam;
			tam = malloc(6 * sizeof(admin)); // maximo de 6 administradores

			tamanho_adm = achar_admin(tam);
			printf("tamanho dos adm lidos: %d\n", tamanho_adm);
			login_adm(tam, tamanho_adm, tamanho_usuario);

		}else{
			break;
		}
	}	
	system("pause");
	return 0;
}

