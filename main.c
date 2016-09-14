#include <stdio.h>
#include "fila.c"

int main () {
  FILA alunos = novaFila();
  inserir(alunos, 9);
  inserir(alunos, 8);
  inserir(alunos, 3);
  inserir(alunos, 10);

  imprimirFila(alunos);

  while(!filaVazia(alunos))
    printf ("removido: %d \n", remover(alunos));

  inserirEsq(alunos, 7);
  inserir(alunos, 8);
  inserir(alunos, 10);
  inserirEsq(alunos, 3);
  inserir(alunos, 32);
  inserirEsq(alunos, 9);

  printf("removendo ultimo\n", removerDir(alunos));

  imprimirFila(alunos);

  destroiFila(alunos);
  return 0;
}
