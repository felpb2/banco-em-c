#include "funcao.h"

int salvar_dados(cadastro *p) {
  FILE *arquivo = fopen("usuarios.txt", "w");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return 1;
  }

  int i;
  for (i = 0; i < 10; i++) { // Salvar os dados atualizados no arquivo
    fprintf(arquivo, "%s;%s;%s;%s;%s;%s;%s\n", p[i].cpf, p[i].nome, p[i].senha,
            p[i].reais, p[i].bitcoin, p[i].Ethereum, p[i].Ripple);
  }

  fclose(arquivo);
  return 0;
}

int menu(cadastro *p, int index) {
  int resposta;
  while (1) {
    printf("----------------------------\n");
    printf("| 1. Consultar saldo       |\n");
    printf("| 2. Consultar extrato     |\n");
    printf("| 3. Depositar             |\n");
    printf("| 4. Sacar                 |\n");
    printf("| 5. Comprar criptomoeda   |\n");
    printf("| 6. Vender criptomoedas   |\n");
    printf("| 7. Atualizar cripto      |\n");
    printf("| 8. Sair                  |\n");
    printf("----------------------------\n");
    scanf("%d", &resposta);
    getchar();

    switch (resposta) {
    case 1:
      Consultarsaldo(p, index);
      break;
    case 2:
      Consultarextrato(p, index);
      break;
    case 3:
      Depositar(p, index);
      salvar_dados(p);
      break;
    case 4:
      Sacar(p, index);
      salvar_dados(p);
      break;
    case 5:
      comprarcripto(p, index);
      salvar_dados(p);
      break;
    case 6:
      vendercripto(p, index);
      salvar_dados(p);
      break;
    case 7:
      Atualizar(); // atualizar os valores das criptomoedas
      break;
    case 8:
      return 0; // Sair do menu
    default:
      printf("Essa opcao nao e valida!\n");
    }
  }
}
  int menu_admin(admin *tam, int quant_usuarios, cadastro *pessoas){
    int resposta;
    while (1) {
      printf("|======================================|\n");
      printf("|1. Cadastrar Novo Investidor          |\n");
      printf("|2. Excluir Investidor                 |\n");
      printf("|3. Cadastrar de Criptomoeda           |\n");
      printf("|4. Excluir Criptomoeda                |\n");
      printf("|5. Consultar Saldo de um Investidor   |\n");
      printf("|6. Consultar Extrato de um Investidor |\n");
      printf("|7. Atualizar cotação de criptomoedas  |\n");
      printf("|8. Sair                               |\n");
      printf("|======================================|\n");
      scanf("%d", &resposta);
      getchar();

      switch (resposta) {
        case 1:
          cadastrar_investidor();
          break;
        case 2:
          excluir_investidor();
          break;
        case 3:
          printf("Cadastrar de Criptomoeda\n");
          break;
        case 4:
          printf("Excluir Criptomoeda\n");
          break;
        case 5:
          consultar_saldo_de_um_Investidor();
          break;
        case 6:
          printf("Consultar Extrato de um Investidor\n");
          break;
        case 7:
          Atualizar(); // atualizar os valores das criptomoedas
          break;
        case 8:
          break;
        default:
          printf("| Opção Inválida!!! |\n");
      }
      if (resposta == 8){
        return 0;
      }
    }
}  
  
