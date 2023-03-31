#ifndef H_ESTACAO
#define H_ESTACAO

//Struct Localidade
typedef struct _estacao{
  int codigo;
  char* nome;
  char* localidade;
  int stockDeBrindes;
} estacao;

typedef struct _listaEstacoes {
  estacao **estacoes;
  int size;
  int capacity;
} listaEstacoes;

// Prototipos
listaEstacoes *criaListaEstacoes(int capacity);
void addEstacao(listaEstacoes *list, estacao *estacao);
void addBrindesEstacao(listaEstacoes *list, int codigo, int numeroBrindes);
void destroiListaEstacoes(listaEstacoes *list);
void showEstacao(listaEstacoes *list, int codigo);
void topBrindes(listaEstacoes *list);

#endif