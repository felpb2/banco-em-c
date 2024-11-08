#include "funcao.h"

int achar_usuario(cadastro *p) {
  FILE *arquivo = fopen("usuarios.txt", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return 1;
  }

  char linhas[255];
  int posicao_struct = 0;
  while (fgets(linhas, 255, arquivo)) { // enquanto tiver recebendo linhas vai continuar no while
    char *token = strtok(linhas, ";"); // delimitador para cortar a linha em strings ';'
    int contador = 0; // indentificar a posicao de cada string recortada no seu
                      // respectivo lugar na struct

    while (token != NULL) { // a linha precisa ter alguma informacao se for
                            // vazia nao vai prosseguir
      if (contador == 0) {
        strcpy(p[posicao_struct].cpf, token);
      } else if (contador == 1) {
        strcpy(p[posicao_struct].nome, token);
      } else if (contador == 2) {
        strcpy(p[posicao_struct].senha, token);
      } else if (contador == 3) {
        strcpy(p[posicao_struct].reais, token);
      } else if (contador == 4) {
        strcpy(p[posicao_struct].bitcoin, token);
      } else if (contador == 5) {
        strcpy(p[posicao_struct].Ethereum, token);
      } else if (contador == 6) {
        token[strcspn(token, "\n")] =
            '\0'; // tirar o \n do ultimo caracter para nao ficar no buffer do
                  // teclado e evitar espaços indesejados
        strcpy(p[posicao_struct].Ripple, token); // struct
      }
      contador++;
      token = strtok(NULL, ";");
    }
    posicao_struct++;
  }

  fclose(arquivo); // fecha arquivo
  return 0;
}

int login(cadastro *p, int tamanho_info) {
  char nome[255], senha[255], cpf[12];
  int posicao_struct = -1;

  while (1) {
    printf("------------------------------\n");
    printf("| BEM-VINDO AO BANCO DE CRIPTO |\n");

    printf("| NOME: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remove o '\n' no final

    printf("| LOGIN: ");
    scanf("%s", cpf);
    getchar(); // Limpa buffer

    printf("| SENHA (max 10): ");
    scanf("%s", senha);
    getchar(); // Limpa buffer

    printf("------------------------------\n");

    int i, contador = 0;
    for (i = 0; i < 10;i++) { // Carregar os usu�rios que est�o cadastrados verificando se o
                               // cpf, nome e senha batem com os dados preenchidos
      if (strcmp(cpf, p[i].cpf) == 0 && strcmp(nome, p[i].nome) == 0 && strcmp(senha, p[i].senha) == 0) {
        contador++;
        posicao_struct = i;
        break; // caso achou a semelhanca n�o precisa continuar vendo.
      }
    }

    if (contador != 0) {
      printf("BEM-VINDO AO BANCO\nUsuario: %s\n", nome);
      menu(p, posicao_struct);

      char letra;
      printf("Deseja sair (s/n)?\n"); // opcao de saida
      scanf(" %c", &letra);
      getchar(); // Limpa buffer
      if (letra == 's') {
        return 0;
      }
    } else {
      printf("Usuario nao cadastrado ou dados incorretos\n");
      printf("Tente novamente!\n");
    }
  }
}
// --- ACHAR ADMIN ---
int achar_admin(admin *tam){

  FILE *arquivo = fopen("administradores.txt", "r");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return 1;
  }

  char linhas[255];
  int posicao_struct = 0;
  while (fgets(linhas, 255, arquivo)) {   // enquanto tiver recebendo linhas vai continuar no while
    char *token = strtok(linhas, " ; ");   // delimitador para cortar a linha em strings ';'
    int contador = 0;  

    while (token != NULL) { 
      if (contador == 0) {

        strcpy(tam[posicao_struct].cpf, token);  

      } else if (contador == 1){
        strcpy(tam[posicao_struct].nome, token);

      } else {
        token[strcspn(token, "\n")] = '\0';
        strcpy(tam[posicao_struct].senha, token);
      }
      contador++;
      token = strtok(NULL, " ; ");  
    }
    posicao_struct++;
  }

  fclose(arquivo); // fecha arquivo
  return posicao_struct;
}
//  ----- LOGIN ADM -------
int login_adm(admin *tam, int tamanho_adm, int tamanho_usuario) {
    char nome[255], senha[255], cpf[12];
    int posicao_struct = -1;
    int i;

    while (1) {
        printf("------------------------------\n");

        printf("| CPF: ");
        scanf(" %s", cpf);
        getchar();  // Limpa buffer

        printf("| Nome: ");
        scanf(" %s", nome);
        getchar();  // Limpa buffer

        printf("| SENHA (max 10): ");
        scanf(" %s", senha);
        getchar();  // Limpa buffer

        printf("------------------------------\n");

        for(i = 0; i < tamanho_adm; i++){
            if (strcmp(cpf, tam[i].cpf) == 0  && strcmp(senha, tam[i].senha) == 0 && strcmp(nome, tam[i].nome) == 0) {
                posicao_struct = i;
                break;
            }
        }
      
        if (posicao_struct != -1) {
              printf("BEM-VINDO ADMINISTRADOR\n");
              menu_admin(); 
              char letra;
              printf("Deseja sair (s/n)?\n");
              scanf(" %c", &letra);
              getchar();  // Limpa buffer
              if (letra == 's') {
                  printf("Ficando off...\n");
                  return 0;
              }
               
        }else {
          printf("Administrador não cadastrado ou dados incorretos\n");
          printf("Tente novamente!\n");
          return 0;
        }
    }
}
