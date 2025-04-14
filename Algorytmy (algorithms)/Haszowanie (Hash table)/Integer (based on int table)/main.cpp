#include <iostream>
#include <string>

using namespace std;

const int s = 100;

struct Node{
    string key;
    Node* next;
};

struct HashTable{
    Node* table[s];

    HashTable(){
        for (int i = 0; i < s; i++){
            table[i] = nullptr;
        }
    }

    int hashFunction(string key){
        int sum = 0;
        for (int i = 0; i < key.length(); i++) {
            sum += key[i];  //  SUMA WARTOSCI LITER W ASCII
        }
        return sum % s;
    }

    void add(string key){
        int index = hashFunction(key);
        Node* newNode = new Node;
        newNode->key = key;
        newNode->next = table[index];
        table[index] = newNode;
    }

    void rem(string key){
        int index = hashFunction(key);
        Node* current = table[index];
        Node* previous = nullptr;
        while (current != nullptr){
            if (current->key == key){
                if (previous == nullptr){
                    table[index] = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
    }

    bool search_in_tab(string key){
        int index = hashFunction(key);
        Node* current = table[index];
        while (current != nullptr){
            if (current->key == key){
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void show(){
        for (int i = 0; i < s; i++){
            cout << "TAB HASH[" << i << "]: ";
            Node* current = table[i];
            while (current != nullptr){
                cout << current->key << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {

    HashTable h;

    h.add("one");
    h.add("two");
    h.add("three");
    h.add("four");

    if (h.search_in_tab("two")){
        cout << "'two' znaleziono." << endl;
    }else{
        cout << "'two' nie znaleziono" << endl;
    }

    h.rem("two");

    if (h.search_in_tab("two")){
        cout << "'two' znaleziono." << endl;
    }else{
        cout << "'two' nie znaleziono" << endl;
    }

    cout << endl;

    h.show();

    return 0;
}
