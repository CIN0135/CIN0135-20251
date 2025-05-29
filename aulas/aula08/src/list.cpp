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

int main() {
	Node *head = initEmptyList(); 
	for (int i = 1; i < 5; i++) {
		listAppend(head, i);
	}	
}