#ifndef __COLECAO_H
#define __COLECAO_C

typedef struct _colecao_ Colecao;

Colecao *colCriar( int max_itens );

int colInserir( Colecao *c, void* item );

void* colRetirar( Colecao *c, void *chave, int (*compar)(void *,void *));

void *colBuscar( Colecao *c, void *chave, int (*compar)(void *, void *) );

int colDestruir( Colecao *c );

#endif
