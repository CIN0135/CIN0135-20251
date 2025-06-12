# Aula 12: Pilhas e Filas


## Pilhas

- Especialização de uma Lista
- Ainda uma estrutura dinâmica linear
- Porém com Inserção / Remoção / Acesso mais restrito
- Política LIFO (Last In, First Out):
    - Acesso apenas ao último elemento (topo da pilha)
    - Inserções/Remoções apenas no topo
- Operações:
    - `stack.top()`: consulta o valor do topo da pilha
    - `stack.push(v)`: empilha o valor `v`, i.e. acrescenta `v` ao final (topo) da pilha
    - `stack.pop()`: desempilha o valor do topo da pilha

### Conceitualmente

```
+-----+
|  E  |  <- Topo (último elemento empilhado)
+-----+
|  D  |
+-----+
|  C  |
+-----+
|  B  |
+-----+
|  A  |  <- Base (primeiro elemento adicionado)
+-----+
```

### Implementação com Lista Encadeada

- Uma pilha pode ser implementada internamente como uma lista encadeada


```
top     +---+---+     +---+---+     +---+---+     +---+---+     +---+---+     +---+---+     
 ------>| \ | --|---->| E | --|---->| D | --|---->| C | --|---->| B | --|---->| A | --|------+ 
        +---+---+     +---+---+     +---+---+     +---+---+     +---+---+     +---+---+      |
                                                                                            ===
```


## Filas

- Especialização de uma Lista
- Ainda uma estrutura dinâmica linear
- Porém com Inserção / Remoção / Acesso mais restrito
- Política FIFO (First In, First Out):
    - Acesso apenas ao primeiro e último elementos (cabeça e cauda)
    - Inserções apenas no final
    - Remoções apenas do topo
- Operações:
    - `queue.enqueue(v)`: enfileira o valor `v`, i.e. acrescenta `v` ao final cauda da fila
    - `queue.dequeue()`: desenfileira o valor do início da fila 

### Conceitualmente

```
               +-----+-----+-----+-----+-----+
Saida  <=====  |  A  |  B  |  C  |  D  |  E  |  <=====  Entrada
               +-----+-----+-----+-----+-----+
```

### Implementação com Lista Encadeada

- Uma pilha pode ser implementada internamente como uma lista encadeada


```
head    +---+---+     +---+---+     +---+---+     +---+---+     +---+---+     +---+---+     
 ------>| \ | --|---->| A | --|---->| B | --|---->| C | --|---->| D | --|---->| E | --|------+ 
        +---+---+     +---+---+     +---+---+     +---+---+     +---+---+     +---+---+      |
                                                                                  ^         ===
                                                                                  |
                                                                                 tail
```



___
[[Código-fonte: /src]](./src)   [[< Anterior]](../aula11/aula11.md) [[Próximo >]](../aula13/aula13.md)  [[Índice ^]](../index.md)
