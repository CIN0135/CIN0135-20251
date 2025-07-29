# Resolução de Colisões

## I. Open hashing

- Várias chaves na mesma posição (por ex., em uma lista encadeada)

**Exemplo:**                            

- `h(k) = k mod 10`

```
   +---+
0  |   |
     .
     .
     .
4  |   |
   +---+
5  | ----→ 195 → 1215 → 75 → ⊥ 
   +---+
6  |   |
     .
     .
     .
9  |   |
   +---+
```

### Análise

#### Pior caso: todas as chaves na mesma posição
  ⟹ acesso, ins, del precisa comparar com todas as `n` chaves na coleção 

#### Melhor caso: sem colisões
  ⟹ acesso, ins, del realiza no máximo uma comparação 

#### Caso médio: 

- Hipótese da **dispersão uniforme simples**: A probabilidade de uma chave cair em qualquer posição é a mesma das demais 

$$
\mathbb{P}[h(k) = i] = \frac{1}{m} \quad \forall i, \text{ independente das outras chaves}
$$

- Número esperado de chaves por posição da tabela:
$$
\mathbb{E}[\text{chaves na posição } i] = \frac{n}{m} \quad \forall i, \text{ independente das outras chaves}
$$

- Número de comparações na busca falhada (= inserção): compara com todas as `n/m` chaves da posição

- Número de comparações na busca bem-sucedida (= remoção): na média compara com metade das chaves da posição


#### Definição: Fator de carga

- `α = n/m`, onde
    - `n` = número de elementos na coleção
    - `m` = número de posições da tabela
- O fator de carga dá uma ideia da ocupação média da tabela


```

↑ Tempo
|
Tins
|
\|&#x20;
\| &#x20;
\|   \      Tdel
\|    \     /
\|     \   /
\|      \ /
\|       \*
+----------------→ α (fator de carga)
(α = 1)
```
