#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "trie.h"

int main(){

    No* raiz = criar();


    const char* BCC[] = {
        "marcos", "gustavo", "kaik", "gabriel", "joel", "bruno"
    };

    int total = sizeof(BCC)/sizeof(BCC[0]);

   printf("--- INSERINDO ESTUDANTES DE CC (IF GOIANO - IPORÁ) ---\n");
    for (int i = 0; i < total; i++) {
        inserir(raiz, BCC[i]);
        printf("Inserido: %s\n", BCC[i]);
    }

    // 4. Testando Busca Exata
    printf("\n--- TESTES DE BUSCA EXATA ---\n");
    const char* busca1 = "gabriel";
    printf("Estudante '%s' esta matriculado? %s\n", 
           busca1, buscarExata(raiz, busca1) ? "Sim (Encontrado)" : "Nao");

    const char* busca2 = "bruno";
    printf("Estudante '%s' esta matriculado? %s\n", 
           busca2, buscarExata(raiz, busca2) ? "Sim (Encontrado)" : "Nao");

    // 5. Testando Busca por Prefixo (Ex: Autocompletar na secretaria)
    printf("\n--- TESTES DE BUSCA POR PREFIXO ---\n");
    const char* prefixo = "ka";
    printf("Existe algum estudante cujo nome comeca com '%s'? %s\n", 
           prefixo, buscarPrefixo(raiz, prefixo) ? "Sim" : "Nao");

    // 6. Testando Remoção (Ex: Aluno trancou o curso ou concluiu)
    printf("\n--- TESTES DE REMOCAO ---\n");
    printf("Removendo o estudante 'marcos'...\n");
    remover(raiz, "marcos");

    printf("Buscar 'davi' apos remocao: %s\n", 
           buscaExata(raiz, "marcos") ? "Encontrado" : "Removido com sucesso");

    return 0;
}
