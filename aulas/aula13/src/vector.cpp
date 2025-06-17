#include <cstddef>
#include <iostream>
#include <cassert>

class Vector {
public:
	Vector();
	~Vector();
	size_t size() { return sz;};
	size_t capacity() { return cap;};
	void append(int val);
	void insert(size_t pos, int val);
	int operator[](size_t pos);
private:
	int *arr = nullptr;
	size_t sz;
	size_t cap;
	void checkAndDouble();
};


Vector::Vector()
{
	sz = 0;
	cap = 1;
	arr = new int[cap];
}

Vector::~Vector()
{
	delete arr;
}

void Vector::checkAndDouble() {
	if (sz == cap) {
		size_t newcap = 2 * cap;
		int *newarr = new int[newcap];
		for (size_t i = 0; i < cap; i++) {
			newarr[i] = arr[i];
		}
		delete arr;
		arr = newarr;
		cap = newcap;
	}
}

void Vector::append(int val)
{
	checkAndDouble();
	arr[sz++] = val;
}

void Vector::insert(size_t pos, int val) 
{
	assert(pos <= this->size());
	checkAndDouble();
	for (int i = sz; i > pos; i--) {
		arr[i] = arr[i-1];
	}
	arr[pos] = val;
	sz++;
}


int Vector::operator[](size_t pos)
{
	return arr[pos];
}


int main(int argc, char **argv) {

	int n = std::stoi(argv[1]);

	Vector v;


	for (int i = 0; i < n; i++) {
		int pos = rand() % (v.size()+1);
		v.insert(pos, i);
	} 

	//for (int i = 0; i < v.size(); i++) {
	//	std::cout << "v[" << i << "] = " << v[i] << std::endl;
	//} 
	std::cout << "size = " << v.size() << "\n";
	std::cout << "cap = " << v.capacity() << "\n";
	
}
