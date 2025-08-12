#include <string>
#include <iostream>

#include "narytree.hpp"


using namespace std;

// Procura se parent node tem algum filho com rotulo c
// Se não tem, retorna nullptr
Node<char> *findChild(Node<char>*parent, char c) 
{
    for (int j = 0; j < parent->NChd(); j++) {
        Node<char> *chd = parent->Chd(j);
        if (c == chd->Val()) {
            return chd;
        }
    }
    return nullptr;
}

void addWord(Node<char> *root, const string& word) {
    Node<char> *cur = root;
    int i = 0;
    for (i = 0; i < word.size(); i++ ) {
        Node<char> *chd = findChild(cur, word[i]);
        if (chd) {
            cur = chd;
            continue;
        }
        break;
    }
    for (; i < word.size(); i++) {
        Node<char>* newChd = new Node<char>(word[i]);
        cur->AddChd(newChd);
        cur = newChd;
    }
    if (!findChild(cur, '$')) {
        cur->AddChd(new Node<char>('$'));
    } 
    cout << "Palavra " << word << " adicionada" << std::endl;    
}


int countLeaves(Node<char> *root)
{

}


int prefixCount(Node<char> *root, const string& prefix) {
    Node<char> *cur = root;
    int i = 0;
    for (i = 0; i < prefix.size(); i++ ) {
        Node<char> *chd = findChild(cur, prefix[i]);
        if (chd) {
            cur = chd;
            continue;
        }
        break;
    }
    if (i < prefix.size()) {
        return 0;
    } else {
        return countLeaves(cur);
    }
}


int main() {
    Node<char> *root = new Node<char>('\0');

    while (true) {
        string s;
        cout << "Digite uma palavra: ";
        getline(cin, s);
        if (s=="") break;
        addWord(root, s);
        printTree(root);
        cout << "-----------------" << std::endl;
    }

}