#include "estacao.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Cria a lista de estações
 */
listaEstacoes *criaListaEstacoes(int capacity) {
  listaEstacoes *list = (listaEstacoes *)malloc(sizeof(listaEstacoes));
  if (list == NULL) {
    return NULL;
  }
  list->estacoes = (estacao **)malloc(capacity * sizeof(estacao *));
  if (list->estacoes != NULL) {
    list->size = 0;
    list->capacity = capacity;
  } else {
    free(list);
    return NULL;
  }
  return list;
}

/**
 * Destroi a lista de estações libertando a memoria reservada
 * bem como a memoria de cada elemento da lista
 */
void destroiListaEstacoes(listaEstacoes *list) {
  for (int i = 0; i < list->size; i++) {
    free(list->estacoes[i]->nome);
    free(list->estacoes[i]->localidade);
    free(list->estacoes[i]);
  }
  free(list->estacoes);
  free(list);
}

/**
 * Adiciona um nova estação a lista
 * Se a lista tiver na sua capacidade maxima impede de adicionar
 */
void addEstacao(listaEstacoes *list, estacao *estacao) {
  int achou = 0;
  if (list->size == list->capacity) {
    printf("A lista está cheia!");
  }else{
    for (int i = 0; i < list->size; i++) {
      if(list->estacoes[i]->codigo == estacao->codigo){
        achou = 1;
        printf("Estacão já foi registada anteriormente!\n");
        break;
      }
    }
    if(achou != 1){
      list->estacoes[list->size++] = estacao;
      printf("Estação criada com sucesso!\n");
    }
  }
}

/**
 * Adiciona Brindes à estação pretendida
 */
void addBrindesEstacao(listaEstacoes *list, int codigo, int numeroBrindes){
  int achou = 0;
  for (int i = 0; i < list->size; i++) {
    if(codigo == list->estacoes[i]->codigo){
      list->estacoes[i]->stockDeBrindes = list->estacoes[i]->stockDeBrindes + numeroBrindes;
      achou = 1;
      printf("Brindes adicionados à Estação!\n");
      break;
    }
  }
  if(achou != 1){
    printf("Estação desconhecida!\n");
  }
}

/**
 * Lista o elementos da lista pelo codigo
 */
void showEstacao(listaEstacoes *list, int codigo) {
  int achou = 0;
  printf("/***************************************************/\n");
  if(list->size == 0){
    printf("Nao existem estações registadas!\n");
  } else{
    for (int i = 0; i < list->size; i++) {
      if(codigo == list->estacoes[i]->codigo){
        printf("%d: %s (%s) - Brindes: %d\n", list->estacoes[i]->codigo, list->estacoes[i]->nome, list->estacoes[i]->localidade, list->estacoes[i]->stockDeBrindes);
        achou = 1;
        break;
      }
    }
    if(achou != 1){
      printf("Estação desconhecida!\n");
    }
  }
}

/**
 * Lista os elementos da lista pela ordem de brindes
 */
void topBrindes(listaEstacoes *list) {
  printf("/***************************************************/\n");
  if(list->size == 0){
    printf("Nao existem estações registadas!\n");
  } else{
    estacao *station = (estacao*) malloc(sizeof(estacao));
    printf("Top Brindes:\n");
    for (int i=0; i<list->size; ++i){
      for (int j=i+1; j<list->size; ++j){
        if (list->estacoes[i]->stockDeBrindes < list->estacoes[j]->stockDeBrindes){
           station = list->estacoes[i];
           list->estacoes[i] = list->estacoes[j];
           list->estacoes[j] = station;
        }
      }
    }

    for (int i = 0; i < list->size; i++) {
      printf("%d: %s (%s) - Brindes: %d\n", list->estacoes[i]->codigo, list->estacoes[i]->nome, list->estacoes[i]->localidade, list->estacoes[i]->stockDeBrindes);
    }
  }
}