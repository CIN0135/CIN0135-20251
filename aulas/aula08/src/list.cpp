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

void listAppend(Node *head, int v) {
	Node *nn = newNode(v);
	Node *cur = head;
	while (cur->next != nullptr) {
		cur = cur->next;
	}
	cur->next = nn;
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


int main() {
	Node *head = initEmptyList(); 
	for (int val = 10; val < 100; val+=10) {
		listAppend(head, val);
	}	

	for (size_t pos = 0; pos < 7; pos++) {
		Node* node = listNodeAt(head, pos);
		if (node->next!=nullptr) {
			std::cout << "list[" << pos << "] = " << node->next->val << std::endl; 
		} else {
			std::cerr << "Posicao [" << pos << "] invalida" << std::endl;
			break;
		}
	}

	for (int value = 0; value < 100; value += 6 ) {
		Node *node = listFind(head, value);
		if (node->next != nullptr) {
			std::cout << "value " << value << " encontrado" << std::endl; 
		} else {
			std::cout << "value " << value << " NAO encontrado" << std::endl; 
		}
	}

	for (int value = 5, i = 0; value < 100; value += 10, i+=2) {
		listInsertAt(head, i, value); 
	}

	
	for (size_t i = 0; i < 12; i +=3) {
		listDeleteAt(head, i); 
	}



}