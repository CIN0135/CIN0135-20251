#include <vector>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class Node {
    T val;
    vector<Node*> chd;
public:
    Node(const T& value) {
        val = value;
    }

    T const& Val(){
        return val;
    }
    size_t NChd() {
        return chd.size();
    }
    Node *Chd(size_t i) {
        return chd[i];
    } 
    void AddChd(Node *c) {
        chd.push_back(c);
    }
};

template <typename T>
void print(Node<T>* root) {
    if (!root) return;
    std::cout << root->val << "\n";
    for (auto c : root->chd) {
        print(c);
    }
}

Node<string> *makeExample() {
    Node<string> *a = new Node<string>("A");
    Node<string> *aa1 = new Node<string>("AA1");
    Node<string> *aa2 = new Node<string>("AA2");
    Node<string> *aa3 = new Node<string>("AA3");
    a->AddChd(aa1);
    a->AddChd(aa2);
    a->AddChd(aa3);
    Node<string> *b = new Node<string>("B");
    Node<string> *bb1 = new Node<string>("BB1");
    Node<string> *bb2 = new Node<string>("BB2");
    b->AddChd(bb1);
    b->AddChd(bb2);
    Node<string> *bbb1 = new Node<string>("BBB1");
    Node<string> *bbb2 = new Node<string>("BBB2");
    Node<string> *bbb3 = new Node<string>("BBB3");
    Node<string> *bbb4 = new Node<string>("BBB4");
    bb2->AddChd(bbb1);
    bb2->AddChd(bbb2);
    bb2->AddChd(bbb3);
    bb2->AddChd(bbb4);
    Node<string> *c = new Node<string>("C");
    Node<string> *root = new Node<string>("/");
    root->AddChd(a);
    root->AddChd(b);
    root->AddChd(c);
    return root;
}

template <typename T>
void printTree(Node<T> *root, int depth = 0) 
{
    if (root == nullptr) return;
    for (int i = 0; i < depth; i++)
        cout << "  ";
    cout << root->Val() << std::endl;
    for (int i = 0; i < root->NChd(); i++) 
    {
        auto c = root->Chd(i);
        printTree(c, depth+1);
    }


}


int main() {

    Node<string> *root = makeExample();
    printTree(root);

}
