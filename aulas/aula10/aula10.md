# Aula 10: Orientação a Objetos

Programação Orientada a Objetos (Object-oriented Programming --- OOP) é um paradigma de programação que consiste em organizar o código em torno de tipos abstratos de dados, ou **classes**, que podem ser definidos pelo programador, e que são constituídos de maneira conjunta pelos dados da informação, ou **atributos**, e pelas operações associadas ao tipo atuando sobre esses dados, ou **métodos**. Um **objeto** é uma *instância* ou *realização* de uma classe. Classes podem representar conceitos ou entidades concretas do domínio de aplicação (como contas bancárias, funcionários, documentos, personagem de um jogo, etc.) como também abstrações como relacionamentos entre as entidades, funções matemáticas ou até construtos da própria linguagem de programação.

A OOP baseia-se em quatro conceitos centrais:
* Abstração
* Encapsulamento
* Herança 
* Polimorfismo

Nesta aula vamos nos centrar sobre os dois primeiros. É importante antes destacar que, apesar da OOP ser reconhecida hoje em dia como um paradigma dos mais importantes e populares, ela não foi concebida de maneira acabada e de uma só vez como tal. Ao contrário, os seus princípios básicos e definidores emergiram e foram se sedimentando aos poucos, ao longo da história, com a evolução das técnicas e linguagens de programação. Essas linguagens foram introduzindo os conceitos acima e outros relacionados em diferentes variações, umas mais e outras menos, e com o tempo algumas foram se tornando mais populares, enquanto outros foram sendo abandonados. A palestra a seguir contém uma boa discussão sobre os conceitos básicos e evolução das Linguagens OO.

[**Vídeo:** The Return of Procedural Programming - Richard Feldman](https://youtu.be/vQPHtAxOZZw?si=5ucZjHMC_AmVIsH8)

### Abstração e Encapsulamento [[2]](#aula10ref2)

#### Abstração

Na Programação Orientada a Objetos (OOP), **abstração** é uma técnica que permite identificar quais detalhes de um objeto ou classe são relevantes para o sistema e devem ser expostos, enquanto os detalhes desnecessários ou complexos são ignorados. Em outras palavras, a abstração foca nos **aspectos essenciais** que definem o comportamento ou as características de um objeto, ocultando a complexidade subjacente.  

**Exemplo:** Em um sistema bancário, uma classe **ContaBancária** pode expor métodos como `sacar()` e `depositar()`, mas os cálculos internos e os processos detalhados (como taxas ou atualizações no banco de dados) permanecem ocultos para o usuário.


#### Encapsulamento

No contexto de OOP, **encapsulamento** é a técnica de **empacotar dados** (atributos) e os métodos que operam sobre esses dados em uma única unidade (a classe) e restringir o acesso direto a certos elementos internos. Através do encapsulamento, pode-se controlar quais partes da classe são **visíveis** (públicas) e quais são **ocultas** (privadas), garantindo maior segurança e integridade dos dados.

**Exemplo:** Em uma classe `ContaBancária`, os atributos como `saldo` podem ser privados e acessíveis apenas por meio de métodos públicos como `getSaldo()` ou `depositar()`, impedindo que o valor do saldo seja modificado diretamente de fora da classe.


**Resumo:**  

- **Abstração**: Foca em **"o que"** um objeto faz, destacando suas características essenciais e omitindo detalhes internos.  
- **Encapsulamento**: Foca em **"como"** os dados e métodos estão organizados e protegidos dentro da classe, escondendo detalhes de implementação.


### Ilustração: Lista Encadeada

Nas aulas anteriores nós concluímos o código C++ para uma lista simplesmente encadeada [list.cpp](../aula08/src/list.cpp) com as operações de leitura, inserção e remoção. Embora conceitualmente pudéssemos estar pensando na lista como um tipo abstrato de dados com essas operações, na prática o código estava organizado de forma que tínhamos apenas os dados declarados numa `struct Node`, e as operações separadas, em diversas funções, que recebiam referências (ponteiros) para o nó cabeça (sentinela) da lista. Essa forma de organizar o código torna necessário um maior cuidado e disciplina do programador, e exige um pouco mais de conhecimento sobre a estrutura interna da lista. 

O código [list.cpp](src/list.cpp) corresponde a uma "tradução" desse TAD para OOP em C++.


#### Classes

Em OOP, chama-se **classe** a definição do TAD, a partir das quais serão criadas as instâncias ou **objetos**. Uma classe define um molde para criar objetos. Objetos encapsulam dados (*atributos*) e operações (*métodos*) relacionados, promovendo a modularidade e reutilização de código.

##### Sintaxe C++

```cpp
class LinkedList
{
public:
	LinkedList()
	{
		head = new Node();
		sz = 0;
	};
	~LinkedList();
	int size()
	{
		return sz;
	}
	int operator[](int pos);
	void insert(int pos, int val);
	void append(int val);
	void prepend(int val);
	int remove(int pos);
private:
	Node *locate(int pos);
	Node *head;
	int sz;
};


```

**Explicação:**
1. **Definição de classe**: É feita com a palavra-chave `class`. No exemplo, `LinkedList` é a classe.
2. **Atributos**: São variáveis que armazenam os dados do objeto (e.g., `head`, `sz`).
3. **Métodos**: São funções que definem os comportamentos do objeto (e.g., `size()`, `insert()`, etc.).
4. **Modificadores de acesso**: 
   - `private`: Somente acessível dentro da classe.
   - `public`: Acessível fora da classe.
5. **Construtor**: Método especial para inicializar objetos da classe, alocando os recursos necessário, como memória, manipuladores de arquivos, conexões de rede, etc. No exemplo `LinkedList()`
6. **Destrutor**: Método especial para liberar recursos alocados e destruir o objeto.

Repare que a declaração da classe pode conter já a definição de alguns métodos, por exemplo, `size()`, que apenas retorna o valor do atributo `sz` correspondente ao tamanho da lista, ou pode conter apenas a declaração do método, por exemplo o destrutor `~LinkedList()` e o método `append()`, sendo que sua definição deve ser fornecida separadamente.

#### Alocando recursos no construtor 


```cpp
	LinkedList()
	{
		head = new Node();
		sz = 0;
	};
```

O construtor é responsável pela aquisição dos recursos iniciais, e inicialização dos atributos do objeto. No exemplo, uma instância da `LinkedList` possui um atributo que é um ponteiro para o Nó cabeça (sentinela) da lista, que é alocado na *heap*. A alocação de um objeto na *heap* é feito através do operador `new`.


#### Liberando recursos no destrutor 

Ao longo do ciclo de vida do objeto, ele pode adquirir mais recursos, além daqueles obtidos no construtor. No exemplo, a lista pode alocar muitos nós para elementos adicionados dinamicamente. No destrutor, esses recursos devem ser liberados. No exemplo, caso apenas os atributos da `LinkedList` fossem liberados, apenas a memória do ponteiro `head` seria devolvida ao sistema, mas os nós em si, alocados dinamicamente, permaneceriam ocupando memória e, pior, sem qualquer meio de serem acessados. Essa situação chama-se **vazamento de memória** (*memory leak*). Para evitar isso, precisamos percorrer os nós da lista e apagá-los individualmente, um por um. O operador `delete` chama o destrutor e desaloca a memória de um objeto criado na heap com o operador `new`.

```cpp
LinkedList::~LinkedList()
{
	Node *cur = head;
	while (cur != nullptr) {
		Node *next = cur->next;
		delete cur;
		cur = next;
	}
}

```

#### Sobrecarga de operadores

C++ permite ao programador (re)definir o significado de operadores da linguagem sobre uma classe. Por exemplo, podemos definir o operador de indexação `[]` para que funcione numa lista encadeada de forma análoga a um array, permitindo que um elemento seja acessado de forma conveniente na forma `list[pos]`.

```cpp
int LinkedList::operator[](int pos)
{
	assert(pos < sz);
	return locate(pos)->next->val;
}
```

Repare que, nesta versão, usamos o método privado `LinkedList::locate(int pos)` para obter uma referência interna (ponteiro) para a posição desejada. Esta mesma função é usada nos demais métodos de inserção e remoção.




### Referências

<a id="aula10ref1"></a>[1] [Richard Feldman. The Return of Procedural Programming](https://youtu.be/vQPHtAxOZZw?si=5ucZjHMC_AmVIsH8)

<a id="aula10ref2"></a>[2] [Edward V. Berard. Abstraction, Encapsulation, and Information Hiding](https://www.tonymarston.co.uk/php-mysql/abstraction.txt)

[3] [B.Stroustroup. A Tour of C++.](https://www.stroustrup.com/Tour.html)


___
[[Código-fonte: /src]](./src)   [[< Anterior]](../aula08/aula08.md) [[Próximo >]](../aula11/aula11.md)  [[Índice ^]](../index.md)


