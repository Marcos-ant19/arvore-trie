#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "trie.h"

No* criar(){
    No* novo = malloc(sizeof(No));

    if(novo == NULL){
        return NULL;
    }

    novo->palavra = false;

    for(int i = 0;i < 26;i++){
        novo->letra[i] = NULL;
    }

    return novo;
}

int mapearIndice(char s){
    return s - 'a';
}

void inserir(No* raiz, const char* chave){
    int frase = strlen(chave);
    No* s = raiz;

    for(int nivel = 0;nivel < frase;nivel++){
        int i = mapearIndice(chave[nivel]);

        if(!s->letra[i]){
            s->letra[i] = criar();
        }

        s = s->letra[i];
    }

    s->palavra = true;
}

bool buscarExata(No* raiz, const char* chave){
    int frase = strlen(chave);
    No* s = raiz;

    for(int nivel = 0;nivel < frase;nivel++){
        int i = mapearIndice(chave[nivel]);

        if(!s->letra[i]){
            return false;
        }
        s = s->letra[i];
    }

    return s->palavra;
}

bool buscarPrefixo(No* raiz, const char* chave){
    int frase = strlen(chave);
    No* s = raiz;

    for(int nivel = 0;nivel < frase;nivel++){
        int i = mapearIndice(chave[nivel]);

        if(!s->letra[i]){
            return false;
        }
        s = s->letra[i];
    }

    return true;
}

bool removeraux(No* s, const char* chave, size_t nivel){
    if(nivel == strlen(chave)){

         if(s->palavra){
            s->palavra = false;
        }

        for(int i = 0;i < 26;i++){
            if(s->letra[i] != NULL){
                return false;
            }
        }
        return true;
    }

    int i = mapearIndice(chave[nivel]);

    if(!s->letra[i]){
        return false;
    }

    bool remover = removeraux(s->letra[i], chave, nivel + 1);

    if(remover){
        free(s->letra[i]);
        s->letra[i] = NULL;

        if(!s->palavra){
            for(int j = 0;j < 26;j++){
                if(s->letra[j] != NULL){
                    return false;
                }
            }
            return true;
        }
    }

    return false;
}

void remover(No* raiz, const char* chave){
    if(raiz == NULL || chave == NULL) return;
    removeraux(raiz, chave, 0);
}