#ifndef TRIE_H
#define TRIE_H
#include <stdbool.h>

typedef struct No{
    struct No* letra[26];
    bool palavra;
}No;

No* criar();
int mapearIndice(char s);
void inserir(No* raiz, char* chave);
void buscarExata(No* raiz, const char* chave);
bool buscarPrefixo(No* raiz, const char* chave);
bool removeraux(No* s, const char* chave, int nivel);
void remover(No* raiz, const char* chave);

#endif