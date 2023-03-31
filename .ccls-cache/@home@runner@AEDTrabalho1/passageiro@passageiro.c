#include "passageiro.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Cria uma nova lista de passageiros dada uma capacidade inicial
 * Retorna um apontador para a nova lista se tudo correr bem, ou NULL se a
 * alocação de memoria falhar
 */
listaPassageiros *criaListaPassageiros(int capacity) {
  listaPassageiros *list = (listaPassageiros *)malloc(sizeof(listaPassageiros));
  if (list == NULL) {
    return NULL;
  }
  list->passengers = (passageiro **)malloc(capacity * sizeof(passageiro *));
  if (list->passengers != NULL) {
    list->size = 0;
    list->capacity = capacity;
  } else {
    free(list);
    return NULL;
  }
  return list;
}

/**
 * Destroi a lista de passageiros libertando a memoria reservada
 * bem como a memoria de cada elemento da lista
 */
void destroiListaPassageiros(listaPassageiros *list) {
  for (int i = 0; i < list->size; i++) {
    free(list->passengers[i]->nome);
    free(list->passengers[i]->email);
    free(list->passengers[i]);
  }
  free(list->passengers);
  free(list);
}

/**
 * Adiciona um novo passageiro a lista
 * Se a lista tiver na sua capacidade maxima impede de adicionar
 */
void addPassageiro(listaPassageiros *list, passageiro *passenger) {
  int achou = 0;
  if (list->size == list->capacity) {
    printf("A lista está cheia!");
  }else{
    for (int i = 0; i < list->size; i++) {
      if(!strcmp(list->passengers[i]->nome, passenger->nome)){
        achou = 1;
        printf("Passageiro já foi registado anteriormente!\n");
        break;
      }
    }
    if(achou != 1){
      list->passengers[list->size++] = passenger;
      printf("Passageiro criado com sucesso!\n");
    }
  }
}

/**
 * Lista todos os elementos da lista
 */
void showPassageiros(listaPassageiros *list) {
  printf("/***************************************************/\n");
  if(list->size == 0){
    printf("Nao existem passageiros registados!\n");
  } else{
    printf("Passageiros List:\n");
    for (int i = 0; i < list->size; i++) {
      printf("Nome:%s    Email:%s    Pontos:%d\n", list->passengers[i]->nome, list->passengers[i]->email, list->passengers[i]->pontos);
    }
  }
}

/**
 * Registar Viagem do Passageiro 
 */
void registarViagem(listaPassageiros *list, char* email, int codigoViagemRecente, int pontos){
  for (int i = 0; i < list->size; i++) {
    if(!strcmp(list->passengers[i]->email, email)){
      list->passengers[i]->codigoViagemRecente = codigoViagemRecente;
      list->passengers[i]->pontos = pontos;
      printf("Viagem registada com sucesso!\n");
    }
  }
}

/**
 * Converter Pontos em Brindes
 */
void converterPontos(listaPassageiros *list, char* email, int codigo, int pontos){
  for (int i = 0; i < list->size; i++) {
    if(!strcmp(list->passengers[i]->email, email)){
      list->passengers[i]->pontos = list->passengers[i]->pontos - pontos;
      printf("Escolha de brindes com sucesso!\n");
    }
  }
}