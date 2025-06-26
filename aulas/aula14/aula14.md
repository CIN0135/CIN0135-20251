# Aula 14: Herança e Polimorfismo na Programação Orientada a Objetos (POO)  

Além da abstração e encapsulamento (vistos [anteriormente](../aula10/aula10.md)), a POO se baseia em outros dois conceitos-chave: herança e polimorfismo.


## Herança  

A **herança** é um mecanismo da POO que permite a crição de subtipos de um certo TAD. Através dela, uma **classe derivada**, ou **subclasse**, "herda" atributos e métodos de outra **classe base**, ou **superclasse**. Isso promove a **reutilização de código** e facilita a manutenção.  


### Exemplo de Herança em C++

```cpp
// Abstract base class
class Shape
{
public:
	virtual ~Shape()
	{
		std::cout << "Destructing Shape\n";
	} // Virtual destructor
	virtual double area() = 0;
};


static const double PI = 3.1415;

// Concrete subclass: Circle
class Circle : public Shape
{
public:
	explicit Circle(double radius): radius{radius} {};
	double area() override
	{
		std::cout << "Computing the area of a Circle of radius " << radius << "\n";
		return radius * radius * PI;
	}
private:
	double radius{0.0};
};

// Concrete subclass: Rectangle
class Rectangle : public Shape
{
public:
	Rectangle (double width, double height): width{width}, height{height} {}
	double area() override
	{
		std::cout << "Computing the area of a " << width << " by " << height <<
		          " Rectangle.\n";
		return width * height;
	}
private:
	double width{0.0};
	double height{0.0};
};
```

A herança permite descrever uma **Interface**, ou seja, um contrato ou comportamento básico esperado para vários tipos. Em C++ isso é feito através de funções virtuais (`virtual`) que permitem definir **(super)classes abstratas**.


## Polimorfismo  

O **polimorfismo** permite que uma mesma interface ou método tenha diferentes implementações. Isso melhora a **extensibilidade** e a **flexibilidade** do código.  

### Tipos de Polimorfismo

1. Polimorfismo de Sobrecarga (Compile-time)
   - Mesma função com diferentes assinaturas.
   
2. Polimorfismo de Sobrescrita (Runtime)
   - Métodos da classe derivada substituem os da classe base.


#### Polimorfismo por Sobrecarga

A **sobrecarga** ocorre quando definimos várias funções com o mesmo nome, mas com parâmetros diferentes.

```cpp
struct Point {
	int x;
	int y;
};

void draw(Circle &c, Point center)
{
	std::cout << "Drawing a circle of radius " << c.Radius() << " centered at (" <<
	          center.x << ", " << center.y << ").\n";

}

void draw(Rectangle &r, Point topLeft)
{
	std::cout << "Drawing a " << r.Width() << " by " << r.Height() <<
	          " rectangle " << " with top-left corner at (" <<
	          topLeft.x << ", " << topLeft.y << ").\n";
}


int main () {
	Circle cobj{2};
	Rectangle robj{3, 4};
	draw(cobj, Point{0, 0});
	draw(robj, Point{0, 0});
}


// Outputs:
// Drawing a circle of radius 2 centered at (0, 0).
// Drawing a 3 by 4 rectangle  with top-left corner at (0, 0).

```

#### Polimorfismo por Sobrescrita com Métodos Virtuais

A **sobrescrita** permite que uma classe filha forneça sua própria implementação para um método da classe pai.  

```cpp
int main() {
    Shape *c = new Circle(2);
    Shape *r = new Rectangle(3,4);
    double area = c->area();
    std::cout << "Area = " << area << std::endl;
    area = r->area();
    std::cout << "Area = " << area << std::endl;
    delete c;
    delete r;
}
```

## Material Adicional

[Herança em C++](../../cpp/1_19_inheritance_idx.md)

___
[[Código-fonte: /src]](./src)   [[< Anterior]](../aula13/aula13.md) [[Próximo >]](../aula15/aula15.md)  [[Índice ^]](../index.md)


