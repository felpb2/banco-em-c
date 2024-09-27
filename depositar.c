#include "funcao.h"

void Depositar(cadastro *p, int index) {
    float valor, saldoAtual;
    printf("Qual o valor que vai ser depositado: ");
    scanf("%f", &valor);
    getchar();

    saldoAtual = atof(p[index].reais);
    saldoAtual += valor;

    sprintf(p[index].reais, "%.2f", saldoAtual);
    printf("Depósito Bem-Sucedido! Novo saldo: %.2f\n", saldoAtual);

    salvar_extrato(p[index].cpf, "Depositar" , "Reais", &saldoAtual, &valor, '+', 0);

}
