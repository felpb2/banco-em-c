#include "funcao.h"

void Consultarsaldo(cadastro *p, int index) {
    printf("------------------------------\n");
    printf("Nome: %s\n", p[index].nome);
    printf("CPF: %s\n", p[index].cpf);
    printf("Reais: %s\n", p[index].reais);
    printf("Bitcoin: %s\n", p[index].bitcoin);
    printf("Ethereum: %s\n", p[index].Ethereum);
    printf("Ripple: %s\n", p[index].Ripple);
    printf("------------------------------\n");
}
