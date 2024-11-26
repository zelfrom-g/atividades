#include "liord.h"

void inicializarLista(LISTA* l) {
  l->nroElem = 0;
  l->capacidade = MAX;
  l->A = (REGISTRO*)malloc(l->capacidade * sizeof(REGISTRO));
}

void redimensionarLista(LISTA* l, int novaCapacidade) {
  l->A = (REGISTRO*)realloc(l->A, novaCapacidade * sizeof(REGISTRO));
  l->capacidade = novaCapacidade;
}

void exibirLista(LISTA* l) {
  printf("Lista: \" ");
  for (int i = 0; i < l->nroElem; i++) {
    printf("%i ", l->A[i].chave);
  }
  printf("\"\n");
}

int tamanho(LISTA* l) {
  return l->nroElem;
}

int tamanhoEmBytes(LISTA* l) {
  return l->capacidade * sizeof(REGISTRO) + sizeof(LISTA);
}

TIPOCHAVE primeiroElem(LISTA* l) {
  return (l->nroElem > 0) ? l->A[0].chave : ERRO;
}

TIPOCHAVE ultimoElem(LISTA* l) {
  return (l->nroElem > 0) ? l->A[l->nroElem - 1].chave : ERRO;
}

TIPOCHAVE enesimoElem(LISTA* l, int n) {
  return (n >= 0 && n < l->nroElem) ? l->A[n].chave : ERRO;
}

void reinicializarLista(LISTA* l) {
  l->nroElem = 0;
  redimensionarLista(l, MAX);
}

void liberarLista(LISTA* l) {
  free(l->A);
  l->A = NULL;
  l->nroElem = 0;
  l->capacidade = 0;
}

int buscaSequencial(LISTA* l, TIPOCHAVE ch) {
  for (int i = 0; i < l->nroElem; i++) {
    if (l->A[i].chave == ch) return i;
  }
  return ERRO;
}

int buscaBinaria(LISTA* l, TIPOCHAVE ch) {
  int esq = 0, dir = l->nroElem - 1;
  while (esq <= dir) {
    int meio = (esq + dir) / 2;
    if (l->A[meio].chave == ch) return meio;
    if (l->A[meio].chave < ch) esq = meio + 1;
    else dir = meio - 1;
  }
  return ERRO;
}

bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
  if (l->nroElem == l->capacidade) {
    redimensionarLista(l, l->capacidade * 2);
  }
  int pos = l->nroElem;
  while (pos > 0 && l->A[pos - 1].chave > reg.chave) {
    l->A[pos] = l->A[pos - 1];
    pos--;
  }
  l->A[pos] = reg;
  l->nroElem++;
  return true;
}

bool excluirElemListaOrd(LISTA* l, TIPOCHAVE ch) {
  int pos = buscaBinaria(l, ch);
  if (pos == ERRO) return false;
  for (int i = pos; i < l->nroElem - 1; i++) {
    l->A[i] = l->A[i + 1];
  }
  l->nroElem--;
  if (l->nroElem > 0 && l->nroElem <= l->capacidade / 4) {
    redimensionarLista(l, l->capacidade / 2);
  }
  return true;
}
