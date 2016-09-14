#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void inserirEsq(FILA f, int e){
    link aux;
    if(f->inicio == NULL) {
        f->inicio = f->fim = novoNo(e, NULL);
    } else {
        aux = novoNo(e,NULL);
        aux->next = f->inicio;
        f->fim->next = NULL;
        f->inicio = aux;
    }
}
int removerDir(FILA f){
    int x;
    link t;
    link i = f->inicio;
    if(filaVazia(f)){
        printf ("Erro, a fila esta vazia\n");
        return 0;
    }

    x = f->fim->item;
    t = f->fim;
    while(i->next != t){
        i = i ->next;
    }
    f->fim = i;
    i->next = NULL;

    if(f->inicio == NULL)
        f->fim = NULL;

    free(t);
    return x;

}

link novoNo(int item, link next) {
  link t = malloc(sizeof *t);
  if (t == NULL) {
    printf ("Erro no malloc \n");
    exit(-1);
  }
  t->item = item;
  t->next = next;
  return t;
}

FILA novaFila() {
  FILA f = malloc(sizeof *f);
  f->fim = f->inicio = NULL;
  return f;
}

void inserir(FILA f, int e) {
  if(f->inicio == NULL) {
    f->inicio = f->fim = novoNo(e, NULL);
  } else {
    f->fim->next = novoNo(e, NULL);
    f->fim = f->fim->next;
    printf("\nMais Antigo: %d\n",f->inicio->item);
    printf("Mais Novo: %d\n",f->fim->item);
  }
}

int remover(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }

  x = f->inicio->item;
  t = f->inicio;
  f->inicio = f->inicio->next;

  if(f->inicio == NULL)
    f->fim = NULL;

  free(t);
  return x;
}
int filaVazia(FILA f) {
  return ((f->fim == NULL) || (f->inicio == NULL));
}
void imprimirFila(FILA f) {
  link t;
  for(t = f->inicio; t != NULL; t = t->next)
    printf ("%d ", t->item);
  printf ("\n");
}
void destroiFila(FILA f) {
  while (!filaVazia(f))
    remover(f);
  free(f);
}

