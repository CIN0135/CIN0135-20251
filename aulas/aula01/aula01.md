# Aula 01 

## Apresentação 

## Liguagens Interpretadas vs. Compiladas

Numa linguagem de programação interpretada, o código fonte de um programa é lido e excecutado por um outro programa chamado de *interpretador*. Tecnicamente, o programa realmente excecutado é sempre o interpretador, que recebe como entrada o código fonte do programa pretendido e simula a sua execução linha por linha, dando a impressão que este último é que está sendo executado. 

Python é um exemplo de linguagem interpretada. Considere o código fonte `hello.py` abaixo.

```Python
# hello.py
print("Hello, world!")
```

Para executar este programa, usamos um comando como 

```bash
$ python3 hello.py
```

O que estamos fazendo é executando o programa `python3`, que é um interpretador da linguagem, dando como entrada o código fonte `hello.py`.


### Exercício

No Linux, é bem possível que o comando `python3` na verdade seja um *link simbólico*, uma espécie de *atalho* para o arquivo executável do interpretador. Utilize o comando `which` para descobrir o verdadeiro arquivo excecutável.

```bash
$ which python3
```

Um resultado possível seria `/usr/bin/python3`. Você pode tentar inspecionar o tipo desse arquivo através do comando `file`.

```bash
$ file -L /usr/bin/pyhton3
```

Você poderá obter uma resposta como 

```
/usr/bin/python3: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=947
293c63a6947244e5917909de136125fe62b01, for GNU/Linux 3.2.0, stripped
```

A parte importante é você obervar que este é um arquivo executável (`ELF 64-bit executable`).

Já se você tentar usar o comando `file` no seu arquivo `hello.py`

```bash
$ file hello.py
```

você vai obter como resposta algo como 

```
hello.py: ASCII text
``` 

ou seja, o seu "programa" `hello.py` na verdade é apenas um arquivo texto em código ASCII, ou um "*script*", a ser reproduzido pelo programa interpretador.

----


Já numa linguagem *compilada*, um arquivo executável deve ser produzido a partir do código-fonte para ser executado diretamente. O processo que converte o código-fonte em um arquivo executável é chamado de *compilação*. Tecnicamente, o processo de compilação normalmente é composto várias etapas e realizado por vários programas, dentre os quais destacam-se o [*compilador*](https://pt.wikipedia.org/wiki/Compilador) e o [*ligador*](https://pt.wikipedia.org/wiki/Ligador). Grosso modo, o compilador produz o chamado *código-objeto*, que é uma versão do programa em linguagem de máquina que, entretanto, ainda não está pronta para execução. O que ocorre é que o programa pode ser composto de vários códigos-objetos que precisam ser combinados, e/ou o(s) código(s)-objeto(s) também podem depender de bibliotecas do sistema. O papel do ligador é combinar os códigos-objetos e resolver as referências às bibliotecas do sistema, produzindo um programa executável. 

Um exemplo linguagem compilada é a Linguagem C. Considere código fonte `hello.c` abaixo, equivalente ao `hello.py` acima.

```C
/* hello.c */
#include <stdio.h>

int main() {
    printf("Hello, world!");
}
``` 

Para compilar esse programa no Linux, podemos usar o comando 

```bash
$ cc hello.c
```

Esse comando usa o programa `cc` que já combina o compilador e o ligador numa única chamada, produzindo o arquivo executável `a.out`. Se este programa for executado

```bash
$ ./a.out
```

obteremos o mesmo resultado acima, com a mensagem "Hello, world!" sendo impressa no terminal.

### Exercício

Para dividir o processo de compilação em duas etapas, vamos primeiro executar

```bash
$ cc -c hello.c
```

O código-objeto `hello.o` será criado. Inspecione o tipo desse arquivo como o comando `file` e tente executá-lo diretamente. O que acontece?

Apesar deste programa simples ser composto de apenas um código-objeto, este possui uma chamada a uma função `printf` que é uma função da biblioteca do sistema declarada no cabeçalho `stdio.h`. Para usar o ligador e produzir o arquivo executável:

```bash
$ cc hello.o
```
Novamente, o arquivo executável `a.out` será recriado.



___
[[Código-fonte: /src]](./src)   [[< Anterior]](../../README.md) [[Próximo >]](../aula02/aula02.md)  [[Índice ^]](../../README.md)





