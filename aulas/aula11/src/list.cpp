#include <iostream>
#include <cassert>

class LinkedList {

private:
	struct Node {
		int val;
		Node* next;
		
		Node(int v) {
			val = v;
			next = nullptr;
		};
	};

	Node* locateCursor(size_t pos) {
		Node *cur = head;
		size_t i = 0;
		while( cur->next != nullptr && i < pos ) {
			cur = cur->next;
			i++;
		}
		return cur;
	} 

public:
	LinkedList();
	~LinkedList();
	size_t size() {
		return sz;
	};
	void append(int value);
	void insert(size_t pos, int value);
	int  remove(size_t pos);
	int  at(size_t pos);
private:
	Node *head;
	size_t sz;
};

LinkedList::LinkedList() {
	head = new Node(-1);
	sz = 0;
}

LinkedList::~LinkedList() {
	std::cout << "Destroying " << this << std::endl;
}


void LinkedList::append(int val) {
	insert(size(), val);
}
	
void LinkedList::insert(size_t pos, int value) {
	Node *cur = locateCursor(pos);
	Node *nn = new Node(value);
	nn->next = cur->next;
	cur->next = nn;
	sz++;
}
	
int LinkedList::remove(size_t pos) {
	Node *cur = locateCursor(pos);
	assert(cur->next != nullptr);
	Node *toDie = cur->next;
	cur->next = toDie->next;
	int ret = toDie->val;
	delete toDie;
	sz--;
	return ret;
}

int LinkedList::at(size_t pos) {
	Node *cur = locateCursor(pos);
	assert(cur->next != nullptr);
	return cur->next->val;
} 


void func() {
	LinkedList list;

	LinkedList *anotherList  = new LinkedList();

	for (int i = 0; i < 5; i++) {
		list.append((i+1)*20);
		anotherList->append((i+1)*20);
	}	
	for (int i = 0; i < list.size(); i++ ) {
		std::cout << "list[" << i << "] = " << list.at(i) << std::endl;
	}

	for (int i = 0; i < 5; i++) {
		list.insert( 2*i , 10+(20*i));
	}	
	for (int i = 0; i < list.size(); i++ ) {
		std::cout << "list[" << i << "] = " << list.at(i) << std::endl;
	}
	
	int deleted = list.remove(9);
	std::cout << "removed " << deleted << std::endl;
	deleted = list.remove(4);
	std::cout << "removed " << deleted << std::endl;
	deleted = list.remove(0);
	std::cout << "removed " << deleted << std::endl;
	for (int i = 0; i < list.size(); i++ ) {
		std::cout << "list[" << i << "] = " << list.at(i) << std::endl;
	}

	delete anotherList;
}


int main() {
	std::cout << "Antes\n";
	func();
	std::cout << "Depois" << std::endl;
}