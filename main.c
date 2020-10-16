#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Colecao.h"
#include "Colecao.c"

#define TRUE 1
#define FALSE 0


int compar(void* elm, void* key)
{
    int *pelm = (int*) elm;
    int *pkey = (int*) key;
    if (*pelm == *pkey){
        return TRUE;
    }else{
        return FALSE;
    }
}

void main(void){
    int *pi;
    int a;
    Colecao *c;
    c = colCriar(10);
    if (c != NULL){
        for (int i=0; i<3; i++){
            printf("Digite um inteiro:");
            scanf("%d", &a);
            pi = (int *)malloc(sizeof(int));
            if(pi != NULL){
                *pi = a;
                colInserir(c, (void*)pi);
            }
        }
        for(int j=0; j<3; j++){
            printf("Digite um inteiro:");
            scanf("%d", &a);
            pi = colBuscar(c,(void*)&a,compar);
        }
    }

}
