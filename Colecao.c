#include <stdio.h>	    /* definicao da constante NULL */
#include <stdlib.h>
#include "Colecao.h"	/* inclui a especificacao do TAD */

#define TRUE 1
#define FALSE 0

typedef struct _colecao_ {

    int numItens;
    int maxItens;
    void* *item;
} Colecao;

Colecao *colCriar(int maxItens)
{
	Colecao *c;
	if ( maxItens > 0 ) {
        c = (Colecao *)malloc(sizeof(Colecao));
        if( c != NULL ){
            c->item = (void* *)malloc(sizeof(void*)* maxItens);
            if (c->item != NULL){
                c->maxItens = maxItens;
                c->numItens = 0;
                return c;
            }
            free (c);
        }
    }
    return NULL;
}

int colInserir( Colecao *c, void* item )
{
    if (c != NULL){
        if (c->item != NULL){
            if (c->numItens < c->maxItens){
                c->item[c->numItens] = item;
                c->numItens++;
                return TRUE;
            }
        }
    }
    return FALSE;
};


void* colRetirar( Colecao *c, void *chave, int (*compar)(void *,void *))
{
    int i = 0;
    void* aux;
    if (c != NULL){
        if(c->item != NULL){
            if(c->numItens > 0){
                while(compar(c->item[i],chave) != TRUE){
                    i++;
                }
                if(compar(c->item[i],chave) == TRUE){
                    aux = c->item[i];
                    while(i < c->numItens){
                        c->item[i] = c->item[i+1];
                        i++;
                    }
                    c->numItens--;
                    return aux;
                }
            }
        }
    }
    return NULL;
};

void* colBuscar( Colecao *c, void *chave, int (*compar)(void *,void *))
{
    int i = 0;
    if (c != NULL){
        if(c->item != NULL){
            if(c->numItens > 0){
                while(compar(c->item[i],chave) != TRUE){
                    i++;
                }
                if(compar(c->item[i],chave) == TRUE){
                    return c->item[i];
                }
            }
        }
    }
    return NULL;
};

int colDestruir( Colecao *c ) 
{
    if (c != NULL){
        if (c->item != NULL){
            if (c->numItens == 0){
                free(c->item);
                free(c);
                return TRUE;
            }
        }
    }
    return FALSE;
}
