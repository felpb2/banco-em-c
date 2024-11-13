#ifndef funcao_h
#define funcao_h

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

typedef struct cadastro{
    char cpf[12];
    char nome[100];
    char senha[10];
    char reais[20];
    char bitcoin[20];
    char Ethereum[20];
    char Ripple[20];
} cadastro;

typedef struct moedas{
    float bitcoin;
    float Ethereum;
    float Ripple;
} moedas;

typedef struct atualizar_cripto{
    int numero;
    char nome[50];
    float cripto;
    char moeda[3];
    char taxas[20];
} atualizar_cripto;

typedef struct admin{
    char cpf[12];
    char nome[50];
    char senha[10];
}admin;


int salvar_dados(cadastro *p);
int achar_usuario(cadastro *p);
int login(cadastro *p, int tamanho_info);
int menu(cadastro *p, int index);
void Consultarsaldo(cadastro *p, int index);
int Consultarextrato(cadastro *p, int index);
int salvar_extrato(char cpf[], char tipo[], char moeda[], float *valor_mudanca, float *quantidade, char sinal, int taxa);
void Depositar(cadastro *p, int index);
void Sacar(cadastro *p, int index);
int comprarcripto(cadastro *p,int numero_struct);
int vendercripto(cadastro *p,int numero_struct);
void limparstring(char *array);
void obterDataAtual(char *data);
void ExibirInformacoesCompra(const char* nomeMoeda, float taxa, float valorCompra, float saldoNovo, float saldoCripto);
int Atualizar();

int login_adm(admin *tam, int tamanho_adm, int tamanho_usuario, cadastro *pessoas);
int achar_admin(admin *tam);
int menu_admin(admin *tam, int quant_usuarios, cadastro *pessoas);
void cadastrar_investidor();
void excluir_investidor();
void consultar_saldo_de_um_Investidor();
void Consultar_Extrato_adm();



#endif
