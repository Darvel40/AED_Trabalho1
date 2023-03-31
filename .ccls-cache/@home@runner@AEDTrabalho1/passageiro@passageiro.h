#ifndef H_PASSAGEIRO
#define H_PASSAGEIRO

//Struct Localidade
typedef struct _passageiro{
  char* nome;
  char* email;
  int pontos;
  int codigoViagemRecente;
} passageiro;

typedef struct _listaPassageiro {
  passageiro **passengers;
  int size;
  int capacity;
} listaPassageiros;

listaPassageiros *criaListaPassageiros(int capacity);
void addPassageiro(listaPassageiros *list, passageiro *passenger);
void destroiListaPassageiros(listaPassageiros *list);
void showPassageiros(listaPassageiros *list);
void registarViagem(listaPassageiros *list, char* email, int codigoViagemRecente, int pontos);
void converterPontos(listaPassageiros *list, char* email, int codigo, int pontos);

#endif