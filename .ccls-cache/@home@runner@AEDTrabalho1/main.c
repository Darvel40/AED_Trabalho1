#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "passageiro/passageiro.h"

int main(void) {
  char comando[2];
  struct passageiro *listPassageiro;
  while (1) {
    printf("/***************************************************/\n");
    printf("Bem vindo ao sistema de cartões online!\n");
    printf("O que deseja fazer: \n");
    printf("RP - Registo de Passageiro\n");
    printf("RE - Regista Estação\n");
    printf("IB - Incrementa Brindes\n");
    printf("RV - Regista Viagem\n");
    printf("EB - Escolha Brindes\n");
    printf("CE - Consulta Estação\n");
    printf("LP - Lista Passageiros\n");
    printf("TB - Top Brindes\n");
    printf("A  - Ajuda\n");
    printf("S  - Sair do Programa\n");
    printf("/***************************************************/\n");

    scanf("%s", comando);

    if (!strcmp(comando, "RP")) {
      passageiro passageiro = create(passageiro);
      
      printf("/***************************************************/\n");
      printf("Introduza o Nome do Passageiro:\n");
      scanf("%s", passageiro->nome);
      printf("Introduza o Email do Passageiro:\n");
      scanf("%s", passageiro->email);

      
    } else if(!strcmp(comando, "RE")) {
      
    } else if(!strcmp(comando, "IB")) {
      
    } else if(!strcmp(comando, "RV")) {
      
    } else if(!strcmp(comando, "EB")) {
      
    } else if(!strcmp(comando, "CE")) {
      
    } else if(!strcmp(comando, "LP")) {
      
    } else if(!strcmp(comando, "TB")) {
      
    } else if(!strcmp(comando, "A")) {
      
    } else if(!strcmp(comando, "S")) {
      printf("/***************************************************/\n");
      printf("A Sair........");
      return 0;
    } else{
      printf("/***************************************************/\n");
      printf("Opção Inválida!\n");
    }
  }
  return 0;
}