# Aula 13: Arrays Dinâmicos

Os mecanismos de abstração/encapsulamento permitem esconder os detalhes de implementação de uma classe, expondo para o utilizador apenas uma interface para utilização de objetos da classe que respeita a semântica, ou contrato pré-estabelecido. No caso de uma lista, enquanto coleção linear dinâmica e homogênea, podemos prover uma implementação baseada num array.

**Problema 1**: Array é uma estrutura estática. Podemos pré-alocar uma capacidade inicial`cap`, mas quando essa capacidade se esgotar, não necessariamente poderemos aumentá-la.

**Solução 1**: Criar um novo array, com o dobro da capacidade inicial, e copiar os valores para o novo array. 

**Problema 2**: Uma única operação de inserção pode resultar na necessidade de copiar todos os elementos do array.

**Atenuante 2**: Isso não é tão problemático assim. Considere uma sequência de inserções sucessivas ao final da lista

```
Array dinâmico
Início: cap=1, sz=0            operação  #inserções(+) #cópias(=) 
                                            
_       
                            
0                                   1)        1          0
+

0 1                                 2)        1          1
= +     cap=2

0 1 2 _                             3)        1          2 = . + 1         => 1
= = +   cap=4                                                |  
                                                             |
0 1 2 3                             4)        1          0   1             => 1
      +

0 1 2 3 4 _ _ _                     5)        1          4 = . + . + . + 1 => 1 
= = = = +     cap=8                                          |   |   |  
                                                             |   |   |
0 1 2 3 4 5 _ _                     6)        1          0   1   |   |     => 1 
          +                                                      |   | 
                                                                 |   |
0 1 2 3 4 5 6 _                     7)        1          0       1   |     => 1
            +                                                        |
                                                                     |
0 1 2 3 4 5 6 7                     8)        1          0           1     => 1
              +

0 1 2 3 4 5 6 7 8 _ _ _ _ _ _ _     9)        1          8 = . + . + . + ... + . + 1  => 1  
= = = = = = = = +        cap=16                              |   |   |   ...   |
                                                             |   |   |   ...   |
0 1 2 3 4 5 6 7 8 9 _ _ _ _ _ _    10)        1          0   1   |   |   ...   |      => 1
                  +                                              |   |   ...   |
                                                                 |   |   ...   |
0 1 2 3 4 5 6 7 8 9 A _ _ _ _ _    11)        1          0       1   |   ...   |      => 1
                    +                                                |   ...   |
                                                                     |   ...   |
0 1 2 3 4 5 6 7 8 9 A B _ _ _ _    12)        1          0           1   ...   |      => 1
                   .                          .                                .
                   .                          .                                .
                   .                          .                                .
                                                                               |
0 1 2 3 4 5 6 7 8 9 A B C D E F    16)        1          0                     1      => 1
                              +
                   .                          .
                   .                          .
                   .                          .
       
                                          ---------------------------------------------------
                                             
                     (!) MÉDIA AGREGADA  ≃  1 ins    +   1 cópia   por operação

```

O código [arraylist.cpp](./src/arraylist.cpp) contém um protótipo de implementação de uma array dinâmico (a.k.a. array list, vector) de ints. Repare em particular no método privado que verifica e dobra o tamanho do array, se necessário, i.e. assim que `sz==cap`. Repare nos operadores `new[]` e `delete[]` para alocar/liberar arrays na heap. 

```cpp
void ArrayList::check_and_double() {
    if (sz < cap) return;
    //cout << "Doubling" << endl;
    size_t new_cap = 2 * cap;
    int *new_arr = new int[new_cap];
    for (size_t i = 0; i < sz; i++) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    cap = new_cap;
}
```


<a name="referencias"></a>
### Referências

[1] [Clifford Shaffer. Data structures and algorithm analysis in C++, Cap 4](http://people.cs.vt.edu/~shaffer/Book/)


___
[[Código-fonte: /src]](./src)   [[< Anterior]](../aula12/aula12.md) [[Próximo >]](../aula14/aula14.md)  [[Índice ^]](../index.md)


