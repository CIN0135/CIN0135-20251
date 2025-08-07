#include <string>
#include <iostream>

#include "narytree.hpp"


using namespace std;


void addWord(Node<char> *root, const string& word) {
    cout << "Palavra " << word << " adicionada" << std::endl;    
}

int main() {

    Node<char> *root;

    while (true) {
        string s;
        cout << "Digite uma palavra: ";
        getline(cin, s);
        if (s=="") break;
        addWord(root, s);
    }

}