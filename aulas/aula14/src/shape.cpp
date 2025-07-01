#include <iostream>

// Abstract base class
class Shape
{
public:
	virtual ~Shape()
	{
		std::cout << "Destructing Shape\n";
	} // Virtual destructor

	virtual double area() = 0;

	virtual const char* name() 
	{
		return myname;
	}
private:
	const char *myname = "Shape";
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

	const char* name() override 
	{
		return "Circle";
	}

	double Radius () {return radius;}
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

	double Width() {return width;}
	double Height() { return height;}
private:
	double width{0.0};
	double height{0.0};
};


void printArea(Shape *s) {
	std::cout << "Area da figura \"" << s->name() <<  "\"\n" << s->area() << std::endl;
}



struct Point {
	int x;
	int y;
};

void draw(Circle c, Point center)
{
	std::cout << "Drawing a circle of radius " << c.Radius() << " centered at (" <<
	          center.x << ", " << center.y << ").\n";

}

void draw(Rectangle r, Point topLeft)
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



int amain() {
	Circle c(1);
	Rectangle r(2,2);


	printArea(&c);

	printArea(&r);

}
