#include "funcao.h"

// MENU PRINCIPAL
int main() {
	setlocale(LC_ALL, "portuguese");

    cadastro *pessoas;
    pessoas = malloc(10 * sizeof(cadastro)); 
    
    achar_usuario(pessoas);
	login(pessoas);
	
	system("pause");
	return 0;
}
