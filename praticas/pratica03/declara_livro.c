#include <stdio.h>

int main() {

  long int isbn = 4002892212345L;
  short int numero_paginas = 199;
  float preco_livro = 89.00f;
  int ano_lancamento = 2005;
  printf("ISBN: %li\n", isbn);
  printf("Num. Paginas: %i\n", numero_paginas);
  printf("Preco: R$ %.2f\n", preco_livro);
  printf("Publicado em: %i\n", ano_lancamento);
  return 0;
}