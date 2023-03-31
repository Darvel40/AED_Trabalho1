#include "passageiro/passageiro.h"
#include "estacao/estacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  //Criar variavel para guardar o comando
  char comando[2];
  //Criar Lista de Passageiros
  listaPassageiros *listaPassageiros = criaListaPassageiros(100);
  //Criar Lista de Estações
  listaEstacoes *listaEstacoes = criaListaEstacoes(100);
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
    printf("Introduza a opção: ");

    //Obter o Comando
    scanf("%s", comando);

    if (!strcmp(comando, "RP")) { //Registo de Passageiro
      //Criar um objeto passageiro
      passageiro *passanger = (passageiro*) malloc(sizeof(passageiro));

      printf("/***************************************************/\n");
      printf("Introduza o Nome do Passageiro:");
      scanf("%ms", &(passanger->nome));
      printf("Introduza o Email do Passageiro:");
      scanf("%ms", &(passanger->email));

      //Adicionar Passageiro
      addPassageiro(listaPassageiros, passanger);
    } else if (!strcmp(comando, "RE")) { //Regista Estação
      //Criar um objeto estação
      estacao *station = (estacao*) malloc(sizeof(estacao));

      printf("/***************************************************/\n");
      printf("Introduza o Codigo da Estação:");
      scanf("%d", &(station->codigo));
      printf("Introduza o Nome da Estação:");
      scanf("%ms", &(station->nome));
      printf("Introduza a Localidade da Estação:");
      scanf("%ms", &(station->localidade));
      printf("Introduza o Numero de Brindes da Estação:");
      scanf("%d", &(station->stockDeBrindes));

      //Adicionar Estação
      addEstacao(listaEstacoes, station);
    } else if (!strcmp(comando, "IB")) { //Incrementa Brindes
      //Variavel para guardar o codigo
      int codigo;
      //Variavel para guardar os brindes
      int brindes;
      printf("/***************************************************/\n");
      printf("Introduza o Codigo da Estação:");
      scanf("%d", &(codigo));
      do{
        printf("Introduza o Numero de Brindes:");
        scanf("%d", &(brindes));
      } while(brindes < 0);

      //Adicionar brindes à estação
      addBrindesEstacao(listaEstacoes, codigo, brindes);
    } else if (!strcmp(comando, "RV")) { //Regista Viagem
      char* email;
      int codigo;
      int pontos;
      int achouPassageiro = 0;
      int achouEstacao = 0;

      printf("/***************************************************/\n");
      do{
        printf("Introduza o Email do Passageiro:");
        scanf("%ms", &(email));
        for (int i = 0; i < listaPassageiros->size; i++) {
          if(!strcmp(listaPassageiros->passengers[i]->email, email)){
            achouPassageiro = 1;
            break;
          }
        }
      } while(achouPassageiro == 0);
      
      do{
        printf("Introduza o Codigo da Estação:");
        scanf("%d", &(codigo));
        for (int i = 0; i < listaEstacoes->size; i++) {
          if(listaEstacoes->estacoes[i]->codigo == codigo){
            achouEstacao = 1;
            break;
          }
        }
      } while(achouEstacao == 0);
      
      do{
        printf("Introduza o Numero de Pontos:");
        scanf("%d", &(pontos));
      } while(pontos < 0);

      //Registar Viagem do Passageiro
      registarViagem(listaPassageiros, email, codigo, pontos);
    } else if (!strcmp(comando, "EB")) { //Escolha Brindes
      char* email;
      int codigo;
      int pontos;
      int brindesDaEstacao;
      int pontosDoPassageiro;
      int achouPassageiro = 0;
      int achouEstacao = 0;
      
      do{
        printf("Introduza o Email do Passageiro:");
        scanf("%ms", &(email));
        for (int i = 0; i < listaPassageiros->size; i++) {
          if(!strcmp(listaPassageiros->passengers[i]->email, email)){
            listaPassageiros->passengers[i]->pontos = pontosDoPassageiro;
            achouPassageiro = 1;
            break;
          }
        }
      } while(achouPassageiro == 0);
      
      do{
        printf("Introduza o Codigo da Estação:");
        scanf("%d", &(codigo));
        for (int i = 0; i < listaEstacoes->size; i++) {
          if(listaEstacoes->estacoes[i]->codigo == codigo){
            listaEstacoes->estacoes[i]->stockDeBrindes = brindesDaEstacao;
            achouEstacao = 1;
            break;
          }
        }
      } while(achouEstacao == 0);
      
      do{
        printf("Introduza o numero de pontos que desejas converter:");
        scanf("%d", &(pontos));
      } while(pontos > brindesDaEstacao);

      if(pontosDoPassageiro >= pontos){
        converterPontos(listaPassageiros, email, codigo, pontos);
      } else{
        printf("Quantidade insuficiente de pontos no cartão!\n");
      }
      
    } else if (!strcmp(comando, "CE")) { //Consulta Estação
      //Variavel para guardar o codigo
      int codigo;
      printf("Introduza o Codigo da Estação:");
      scanf("%d", &(codigo));
      showEstacao(listaEstacoes, codigo);
    } else if (!strcmp(comando, "LP")) { //Lista Passageiros
      showPassageiros(listaPassageiros);
    } else if (!strcmp(comando, "TB")) { //Top Brindes
      topBrindes(listaEstacoes);
    } else if (!strcmp(comando, "A")) { //Ajuda

    } else if (!strcmp(comando, "S")) { //Sair do Programa
      printf("/***************************************************/\n");
      printf("A Sair........");
      return 0;
    } else { //Opção Inválida
      printf("/***************************************************/\n");
      printf("Opção Inválida!\n");
    }
  }
  return 0;
}