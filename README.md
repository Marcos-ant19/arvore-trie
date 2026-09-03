# Árvore Trie - Sistema de Gerenciamento de Estudantes

## 📋 Descrição

Implementação de uma estrutura de dados **Árvore Trie** (Prefix Tree) em linguagem C para gerenciar um banco de dados de estudantes. Este projeto foi desenvolvido para o curso de Ciência da Computação do IF Goiano - Iporá.

A Trie é uma estrutura de dados eficiente para:
- ✅ Inserção rápida de palavras/nomes
- ✅ Busca exata em O(m), onde m é o comprimento da palavra
- ✅ Busca por prefixo em O(m)
- ✅ Remoção eficiente com limpeza de memória

---

## 🏗️ Estrutura do Projeto

```
arvore-trie/
├── main.c       # Programa principal com testes
├── trie.h       # Declarações das funções e estruturas
├── trie.c       # Implementação da Trie
└── README.md    # Este arquivo
```

---

## 📦 Estruturas de Dados

### Nó da Trie
```c
typedef struct No {
    struct No* letra[26];  // Ponteiros para os 26 caracteres do alfabeto
    bool palavra;          // Indica se o nó marca o fim de uma palavra válida
} No;
```

---

## 🔧 Funções Implementadas

### `No* criar()`
**Descrição:** Aloca e inicializa um novo nó da Trie.

**Retorno:** 
- Ponteiro para o novo nó alocado
- `NULL` se falhar na alocação

**Complexidade:** O(1)

---

### `int mapearIndice(char s)`
**Descrição:** Converte um caractere minúsculo para seu índice correspondente (0-25).

**Parâmetros:**
- `char s`: Caractere minúsculo ('a' a 'z')

**Retorno:** Índice de 0 a 25

**Exemplo:**
```c
mapearIndice('a'); // Retorna 0
mapearIndice('z'); // Retorna 25
```

**Complexidade:** O(1)

---

### `void inserir(No* raiz, const char* chave)`
**Descrição:** Insere uma nova palavra (nome de estudante) na Trie.

**Parâmetros:**
- `No* raiz`: Ponteiro para o nó raiz da Trie
- `const char* chave`: Nome/palavra a ser inserida

**Funcionamento:**
1. Percorre cada caractere da palavra
2. Cria novos nós conforme necessário
3. Marca o nó final como fim de palavra válida

**Exemplo:**
```c
No* raiz = criar();
inserir(raiz, "gabriel");
inserir(raiz, "marcos");
```

**Complexidade:** O(m), onde m é o comprimento da palavra

---

### `bool buscarExata(No* raiz, const char* chave)`
**Descrição:** Busca se uma palavra exata existe na Trie.

**Parâmetros:**
- `No* raiz`: Ponteiro para o nó raiz da Trie
- `const char* chave`: Palavra a ser buscada

**Retorno:**
- `true`: Se a palavra existe exatamente
- `false`: Se a palavra não existe

**Exemplo:**
```c
if (buscarExata(raiz, "gabriel")) {
    printf("Estudante encontrado!\n");
}
```

**Complexidade:** O(m), onde m é o comprimento da palavra

---

### `bool buscarPrefixo(No* raiz, const char* chave)`
**Descrição:** Busca se existe alguma palavra que comece com o prefixo fornecido.

**Parâmetros:**
- `No* raiz`: Ponteiro para o nó raiz da Trie
- `const char* chave`: Prefixo a ser buscado

**Retorno:**
- `true`: Se existe pelo menos uma palavra com esse prefixo
- `false`: Se nenhuma palavra começa com esse prefixo

**Exemplo:**
```c
// Se "gabriel" está inserido:
if (buscarPrefixo(raiz, "gab")) {
    printf("Existe alguém cujo nome começa com 'gab'!\n");
}
```

**Complexidade:** O(m), onde m é o comprimento do prefixo

---

### `bool removeraux(No* s, const char* chave, int nivel)`
**Descrição:** Função auxiliar recursiva para remover uma palavra da Trie.

**Parâmetros:**
- `No* s`: Nó atual
- `const char* chave`: Palavra a ser removida
- `int nivel`: Nível atual na recursão

**Retorno:**
- `true`: Se o nó pode ser removido
- `false`: Caso contrário

**Funcionamento:**
1. Percorre recursivamente até o fim da palavra
2. Remove a marcação de palavra válida
3. Libera nós que não são mais necessários
4. Limpa memória adequadamente

**Complexidade:** O(m), onde m é o comprimento da palavra

---

### `void remover(No* raiz, const char* chave)`
**Descrição:** Remove uma palavra da Trie (função pública).

**Parâmetros:**
- `No* raiz`: Ponteiro para o nó raiz da Trie
- `const char* chave`: Palavra a ser removida

**Exemplo:**
```c
remover(raiz, "marcos");  // Remove o estudante "marcos"
```

**Complexidade:** O(m), onde m é o comprimento da palavra

---

## 📝 Exemplo de Uso (main.c)

O programa principal implementa um sistema de gerenciamento de estudantes:

### Funcionalidades Demonstradas:

1. **Criação da Trie**
   ```c
   No* raiz = criar();
   ```

2. **Inserção de Estudantes**
   ```c
   const char* BCC[] = {
       "marcos", "gustavo", "kaik", "gabriel", "joel", "bruno"
   };
   for (int i = 0; i < total; i++) {
       inserir(raiz, BCC[i]);
   }
   ```

3. **Busca Exata**
   ```c
   if (buscarExata(raiz, "gabriel")) {
       printf("Estudante encontrado!\n");
   }
   ```

4. **Busca por Prefixo** (Autocompletar)
   ```c
   if (buscarPrefixo(raiz, "ka")) {
       printf("Existe alguém com nome começando em 'ka'\n");
   }
   ```

5. **Remoção de Estudante**
   ```c
   remover(raiz, "marcos");
   ```

---

## 🚀 Como Compilar e Executar

### Compilação
```bash
gcc -c trie.c -o trie.o
gcc -c main.c -o main.o
gcc trie.o main.o -o programa
```

**Ou de uma vez:**
```bash
gcc main.c trie.c -o programa
```

### Execução
```bash
./programa
```

---

## 💾 Gerenciamento de Memória

- ✅ Cada nó é alocado dinamicamente com `malloc()`
- ✅ Nós não utilizados são liberados com `free()` durante a remoção
- ✅ A memória é gerenciada eficientemente sem vazamentos

---

## 📊 Complexidade de Tempo

| Operação | Complexidade | Observação |
|----------|--------------|-----------|
| Inserção | O(m) | m = comprimento da palavra |
| Busca Exata | O(m) | m = comprimento da palavra |
| Busca por Prefixo | O(m) | m = comprimento do prefixo |
| Remoção | O(m) | m = comprimento da palavra |

---

## 💾 Complexidade de Espaço

**O(ALPHABET_SIZE × N × M)**
- ALPHABET_SIZE = 26 (letras minúsculas)
- N = número de palavras
- M = comprimento médio das palavras

---

## 🎓 Aplicações Práticas

- 📱 Autocompletar em buscadores
- 📚 Verificação de ortografia
- 🔤 Análise de DNA (com um alfabeto diferente)
- 📋 Sistemas de cadastro e busca rápida
- 🌐 Roteadores de rede (IP lookup)

---

## 👨‍💻 Autor

Desenvolvido como projeto educacional para o curso de Ciência da Computação - IF Goiano (Iporá).

---

## 📄 Licença

Este projeto é de código aberto para fins educacionais.