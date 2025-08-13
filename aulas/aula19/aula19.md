# Aplicações de HashTables 

## Dicionário

Um **Dicionário**, também chamado **mapa** ou **array associativo**, é uma ED que associa **chaves** a **valores**, ou seja, conceitualmente é um conjunto de pares do tipo

```
+--------+-----------+
|  key   |   value   |
+--------+-----------+
```

com operações

- `dict.insert(key, value)`: insere o par `(key, value)`
- `dict.contains(key)`: consulta se o dicionário contem algum valor  associado à chave `key`
- `dict.get(key)`: consulta o valor associado à chave `key`


### Implementação 

- Um dicionário **não ordenado** é tipicamente implementado com uma hashtable
- A ideia é armazenar na tabela um conjunto de entradas `(key, value)`, usando apenas a `key` para o cálculo da posição 
- A princípio, um objeto qualquer pode ser usado como `key` desde que obedeça algumas condições:
    - `key` precisa ser mapeável em um valor numério correspondente `k=hashcode(key)` 
    - `key` precisa ser comparável por equivalência ('==')
    - Se `key1 == key2` então devemos ter `hashcode(key1) == hashcode(key2)`
- A posição do par `(key, value)` na tabela será dada por `h(k=hashcode(key))` onde `h` é a função de dispersão da tabela


#### Teste de pertinência

```
Dictionary::contains(key)
    k = hashcode(key)
    for i = 0, 1, ....
       pos = h(k, i)            // considerando a sondagem
       if T[pos] is empty
            return false
       if T[pos].key == key     // necessário comparar devido a colisões
            return true
```



## Conjunto (Hashset)

- Um conjunto não ordenado é uma coleção com as operações
    - `set.insert(elem)`: insere o elemento `elem` se não estiver contido 
    - `set.contains(elem)`: consulta se o conjunto contém `elem`
- Hashtables também podem ser usadas para representar conjuntos 
- Para ser adicionado, os elementos precisam obedecer os critérios de chave descritos acima
    - `elem` precisa ser mapeável em um valor numério correspondente `k=hashcode(elem)` 
    - `elem` precisa ser comparável por equivalência ('==')
    - Se `elem1 == elem2` então devemos ter `hashcode(elem1) == hashcode(elem2)`
- Dessa forma o Hashset pode ser implementado de forma análoga a um dicionário, apenas ignorando o `value`