#include <iostream>
#include <cassert>


struct Node {
	int val;
	Node* next;
};


Node* newNode(int v) {
	Node* ret = new Node;
	(*ret).val = v;
	ret->next = nullptr;
	return ret;
}

Node *initEmptyList() {
	return newNode(-1);
}



Node* listNodeAt(Node *head, size_t pos) {
	Node *cur = head;
	size_t i = 0;
	while( cur->next != nullptr && i < pos ) {
		cur = cur->next;
		i++;
	}
	return cur;
} 


Node* listFind(Node *head, int value) {
	Node *cur = head;
	while( cur->next != nullptr && cur->next->val != value ) {
		cur = cur->next;
	}
	return cur;
} 


void listInsert(Node *cur, int value) {
	assert(cur!=nullptr);
	Node *nn = newNode(value);
	nn->next = cur->next;
	cur->next = nn;
}


void listInsertAt(Node *head, size_t pos, int value) {
	listInsert(listNodeAt(head, pos), value);
}


void listDelete(Node* cur) {
	assert(cur->next != nullptr);
	Node *toDie = cur->next;
	cur->next = toDie->next;
	delete toDie;
}

void listDeleteAt(Node *head, size_t pos) {
	listDelete(listNodeAt(head, pos));
}



class LinkedList {
public:
	LinkedList();
	size_t size() {
		return sz;
	};
	void append(int value);
	//void insert(size_t pos, int value);
	//int  remove(size_t pos);
	//int  at(size_t pos);
private:
	Node *head;
	size_t sz;
};

LinkedList::LinkedList() {
	head = newNode(-1);
	sz = 0;
}

void LinkedList::append(int val) {
	Node *nn = newNode(val);
	Node *cur = head;
	while (cur->next != nullptr) {
		cur = cur->next;
	}
	cur->next = nn;
	sz++;
}

int main() {
	LinkedList list;
	for (int val = 10; val < 100; val+=10) {
		list.append(val);
		std::cout << "size = " << list.size() << std::endl;
	}	

}