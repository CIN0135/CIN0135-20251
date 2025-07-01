# Aula 14: C++: Ponteiros vs Referências

Ponteiros e referências são formas de acessar e manipular variáveis indiretamente, mas diferem em como funcionam e são usados.

## Ponteiros (`*`)

Um **ponteiro** é uma variável que **armazena o endereço de memória** de outra variável.

- **Declaração:** Usa o símbolo `*`.
  ```cpp
  int a = 10;
  int* p = &a;  // p é um ponteiro que armazena o endereço de 'a'
  ```
- **Acesso ao valor:** Para acessar ou modificar o valor apontado, usa-se o operador de **desreferenciação (`*`)**:
  ```cpp
  *p = 20;  // altera o valor de 'a' para 20
  ```
- **Reatribuição:** Ponteiros podem ser **mudados** para apontar para diferentes variáveis:
  ```cpp
  int b = 30;
  p = &b;  // agora p aponta para 'b'
  ```
- **Podem ser nulos:** Um ponteiro pode não apontar para nada:
  ```cpp
  int* p = nullptr;
  ```
- **Aritmética de ponteiros:** É possível realizar operações como incrementar (`p++`) para percorrer arrays.


## Referências (`&`)

Uma **referência** é um **apelido** para uma variável existente. Ela não armazena o endereço, mas age como um alias direto da variável.

- **Declaração:** Usa o símbolo `&` (na declaração, não na atribuição).
  ```cpp
  int a = 10;
  int& r = a;  // 'r' é uma referência para 'a'
  ```
- **Acesso ao valor:** Operações em `r` afetam diretamente `a`, sem necessidade de desreferenciação:
  ```cpp
  r = 20;  // altera o valor de 'a' para 20
  ```
- **Não podem ser reatribuídas:** Após serem inicializadas, referências **não podem apontar para outra variável**.
- **Nunca são nulas:** Uma referência sempre está vinculada a uma variável válida.
- **Uso comum:** Muito usadas para **passagem de parâmetros** em funções, evitando cópias desnecessárias.

## Comparação Rápida

| **Aspecto**          | **Ponteiro (`*`)**                                | **Referência (`&`)**                            |
|----------------------|--------------------------------------------------|------------------------------------------------|
| **Declaração**       | `int* p = &a;`                                   | `int& r = a;`                                  |
| **Acesso ao valor**  | `*p = 20;`                                       | `r = 20;`                                      |
| **Reatribuição**     | Pode apontar para diferentes variáveis.           | Não pode ser reatribuída após inicialização.   |
| **Valor nulo**       | Pode ser `nullptr`.                              | Nunca é nula.                                  |
| **Aritmética**       | Suporta (ex.: `p++`).                            | Não suporta aritmética.                        |
| **Uso típico**       | Estruturas dinâmicas (listas, árvores), arrays.   | Passagem eficiente de argumentos em funções.   |


- **Use referências** quando quiser passar variáveis para funções de forma eficiente e segura, sem risco de `nullptr`.
- **Use ponteiros** quando precisar de mais flexibilidade, como apontar para diferentes objetos, trabalhar com estruturas dinâmicas, ou quando o valor pode ser opcional (`nullptr`).


## Templates e Programação Genérica

- **Ideia Básica**: Criar código "parametrizado" com diferentes tipos de dados sem duplicar código.
- Dois tipos básicos:
    1. Function Templates
    2. Class Templates


### Function Templates (Templates de Função)  


Permitem criar **funções genéricas** que funcionam com diferentes tipos de dados.

```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

- Pode ser usado com `int`, `double`, `char`, etc.  
  ```cpp
  max(3, 7);       // int
  max(4.5, 2.3);   // double
  ```

### Class Templates (Templates de Classe)

Permitem criar **classes genéricas**, especialmente containers

#### **Exemplo:**
```cpp
template <typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    T getValue() { return value; }
};
```

- Pode instanciar com diferentes tipos:
  ```cpp
  Box<int> intBox(10);
  Box<std::string> strBox("Hello");
  ```

## Material adicional

- [Referências](../../cpp/1_15_references_idx.md)
- [Templates](../../cpp/1_20_templates_idx.md)

___
[[Código-fonte: /src]](./src)   [[< Anterior]](../aula14/aula14.md) [[Próximo >]](../aula16/aula16.md) [[Índice ^]](../index.md)

