#ifndef FILA_H
#define FILA_H

typedef struct node * link;
struct node {
  int item;
  link next;
};

typedef struct {
  link inicio;
  link fim;
} * FILA;

link novoNo(int item, link next);
FILA novaFila();
void inserir(FILA f, int e);
void inserirEsq(FILA f, int e);
int remover(FILA f);
int removerDir(FILA f);
void imprimirFila(FILA f);
void destroiFila(FILA f);
int filaVazia(FILA f);

#endif
