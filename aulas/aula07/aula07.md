# Aula 07: Listas Encadeadas I

## Definição

* ED linear homogênea dinâmica
    - "linear": elementos em sequência, identificados por posição
    - "homogêna": elementos do mesmo tipo
    - "dinâmica": quantidade variável de elementos e memória

## Representação

* Cada elemento armazenado num "**Nó**"
* Além do valor do elemento (`val`), cada nó possui uma *referência* (ponteiro) para o próximo nó (`next`)

```
Linked List Node

+-------+--------+
|  val  |  next -|--->
+-------+--------+

```
Em C++

```cpp
struct Node {
    int val;
    Node *next;
};
```


* Guardamos uma referência especial para o primeiro Nó da lista, chamado **cabeça** (*head*).
* Além disso, usamos a representação de [[1]](#referencias) em que sempre temos um nó inicial chamado **sentinela**, cujo valor não faz parte **logicamente** da lista. O nó sentinela serve apenas para demarcar **fisicamente** o início da lista.

## Exemplos

A) Lista Vazia

```
          +---+---+  
head ---->| \ |  -|---+
          +---+---+   |
                      | 
                     ===
```

Repare que a lista vazia tem pelo menos o nó sentinela, ou seja `head` é sempre um ponteiro para um nó válido.


B) Lista com os 4 primeiros primos

```
Índices "lógicos" 
dos elementos:            [0]          [1]          [2]          [3]

          +---+---+    +---+---+    +---+---+    +---+---+    +---+---+   
head ---->| \ |  -|--->| 2 |  -|--->| 3 |  -|--->| 5 |  -|--->| 7 |  -|---+
          +---+---+    +---+---+    +---+---+    +---+---+    +---+---+   |
                                                                          | 
                                                                         ===
```

## Operações básicas

0) Inicialização de uma Lista vazia
1) Acesso por posição
2) Busca por valor
3) Inserção
4) Remoção


### Inicialização de uma Lista vazia

1. Aloca memória para um novo nó
2. Inicializa valor e next


### Acesso por posição

1. Cria um cursor `cur` indicador da posição corrente apontando para o nó sentinela
2. Inicializa o índice de posição corrente `i=0`
3. Enquanto a posição corrente for menor do que a posição desejada `pos`:

    3.1. Avança o cursor para o próximo elemento
    3.2. Incrementa o índice da posição corrente
4. Retorna o cursor na posição atual

**IMPORTANTE:**
* Nesta representação, uma referência "**lógica**" para um elemento/nó é dada por um ponteiro "**físico**" para o nó imediatamente anterior.
* Desta forma, o primeiro elemento, de índice `[0]`) é representado por um ponteiro para o nó sentinela (i.e. com o mesmo valor de `head`).
* Sabemos que uma referência `cur` é válida, i.e. se referencia um elemento dentro dos limites do tamanho da lista, se `cur->next != NULL`.


### Busca por valor 

Ideia semelhante à busca por posição, varrendo a lista um Nó de cada vez até encontrar o valor procurado ou atingir o último elemento da lista (**cauda**).

1. Cria um cursor `cur` indicador da posição corrente apontando para o nó sentinela
2. Enquanto o valor do elemento corrente (que é o do nó seguinte ao cursor) for diferente do valor procurado, ou chegou à cauda da lista:
    2.1. Avança o cursor para o próximo elemento
    2.2. Incrementa o índice da posição corrente
4. Retorna o cursor na posição atual

**IMPORTANTE**: 
* Localizar um elemento, seja por posição, seja por valor, requer percorrer a lista desde o início, um elemento de cada vez, até alcançar a posição pretendida.
* No pior caso, isso pode exigir visitar todos os elementos da lista.

### Inserção

Para inserir um novo nó na posição dada por um cursor `cur`:

```
Passo 1) cria novo nó com valor desejado

          +---+---+                      +---+---+    
 ...  --->| X |  -|--------------------->| Z |  -|--- ...
          +---+---+                      +---+---+  
            ^  
            |            +---+---+
           cur           |val|   |
                         +---+---+
                           ^
                           |
                     (1) new_node


Passo 2) ajusta o sucessor (next) do novo nó

          +---+---+                      +---+---+    
 ...  --->| X |  -|--------------------->| Z |  -|--- ...
          +---+---+                  +-->+---+---+  
            ^                        |
            |            +---+---+   |
           cur           |val|  -|---+ (2)
                         +---+---+
                           ^
                           |
                        new_node

Passo 3) ajusta o sucessor do cursor

          +---+---+                      +---+---+    
 ...  --->| X |  -|--+  \  ---       +-->| Z |  -|--- ...
          +---+---+  |               |   +---+---+  
            ^        |               |
            |    (3) |   +---+---+   |
           cur       +-->|val|  -|---+ 
                         +---+---+
                           ^
                           |
                        new_node
```

**NOTA:** O cursor agora representa uma referência lógica para o novo nó que foi inserido.

- Podemos combinar essa função com a localização por posição para inserir um nó numa dada posição `pos` da lista.

**NOTA**: Se a lista tem tamanho (lógico) `n` (`n+1` nós, incluindo o sentinela):
* Inserir no final da lista: `insert_at(head, n, val) == append(head, val)`
* Inserir no início da lista: `insert_cur(head, val) == insert_at(head, 0, val) == prepend(head, val)`

**IMPORTANTE**: 
* Uma vez obtida a referência para a posição corrente, inserir um novo elemento nesse posição requer apenas uma quantidade fixa (constante) de operações.
* Porém, para chegar à posição desejada, precisamos percorrer a lista como explicado acima.

### Remoção

Para remover um nó válido da posição corrente referenciado por um cursor `cur` (pré-condição: `cur->next != NULL`)

```
Passo 1) cria ponteiro para nó a ser removido 

          +---+---+       +---+---+        +---+---+    
 ...  --->| X |  -|------>| Y |  -|------->| Z |  -|--- ...
          +---+---+       +---+---+        +---+---+  
            ^               ^ 
            |               |
           cur         (1) to_die
                       

Passo 2) ajusta o sucessor do cursor  (bypass)

                        (2)
                     +----------------+
                     |                |
          +---+---+  |    +---+---+   +--->+---+---+    
 ...  --->| X |  -|--+ /  | Y |  -|------->| Z |  -|--- ...
          +---+---+       +---+---+        +---+---+  
            ^               ^ 
            |               |
           cur             to_die
                       

Passo 3) apaga o nó pretendido da memória
                        

                     +-----------------+
                     |                 |
          +---+---+  |    /////////    |    +---+---+    
 ...  --->| X |  -|--+    /////////    +--->| Z |  -|--- ...
          +---+---+       /////////         +---+---+  
            ^               ^ 
            |               |
           cur             to_die (3)
                       

```
**NOTA:** O cursor agora representa uma referência lógica para o nó seguinte ao nó removido, e que passa a ocupar aquela posição corrente.

**IMPORTANTE**: 
* Uma vez obtida a referência para a posição a ser removida, a remoção em si requer apenas uma quantidade fixa (constante) de operações.
* Porém, para chegar à posição desejada, precisamos percorrer a lista como explicado acima.


<a name="referencias"></a>
## Referências

[1] [Clifford Shaffer. Data structures and algorithm analysis in C++, Cap 4](http://people.cs.vt.edu/~shaffer/Book/)



___
[[Código-fonte: /src]](./src)   [[< Anterior]](../aula06/aula06.md) [[Próximo >]](../aula08/aula08.md)  [[Índice ^]](../index.md)


