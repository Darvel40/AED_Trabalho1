#ifndef H_PASSAGEIRO
#define H_PASSAGEIRO

//Struct Localidade
typedef struct _passageiro{
  char* nome;
  char* email;
} passageiroInfo, *passageiro;

//Inicializar Objeto
passageiro create(passageiro p);

//Destroir Objeto
void destroy(passageiro p);

#endif