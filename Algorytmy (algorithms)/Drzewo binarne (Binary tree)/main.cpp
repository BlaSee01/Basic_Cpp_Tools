#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

struct Tree{
    int key;

    struct Tree *parent;
    struct Tree *left;
    struct Tree *right;
};

struct Tree *root = NULL;

void add_node(int x){

    struct Tree *now = root;
    struct Tree *tmp = new Tree;

    tmp->key = x;
    tmp->left = NULL;
    tmp->right = NULL;

    if (root == NULL){
        tmp->parent = NULL;
        root = tmp;
        return;
    }else{
        while (now != NULL){
            if (now->key <= tmp->key){
                if (now->right == NULL){
                    tmp->parent = now;
                    now->right = tmp;
                    return;
                }else{
                    now = now->right;
                }
            }
            // WARUNEK 2
            if (now->key > tmp->key){
                if (now->left == NULL){
                    tmp->parent = now;
                    now->left = tmp;
                    return;
                }else{
                    now = now->left;
                }
            }
        }
    }
}

Tree* min_val(Tree* root) {
    Tree* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

Tree* rem(Tree* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = rem(root->left, key);
    } else if (key > root->key) {
        root->right = rem(root->right, key);
    } else {
        if (root->left == NULL) {
            Tree* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Tree* temp = root->left;
            delete root;
            return temp;
        }
        Tree* temp = min_val(root->right);
        root->key = temp->key;
        root->right = rem(root->right, temp->key);
    }
    return root;
}

/*struct Tree* del_node(struct Tree* node, int x){

    if (node == NULL)   return node;

    if (x < node->key){
        return node->left = del_node(node->left, x);
    }else if(x > node->key){
        return node->right = del_node(node->right, x);
    }

    if (x == node->key){
        if (root->left == NULL && root->right == NULL) {
            delete(root);
            root = NULL;
            return NULL;
        }

        if (node->left == NULL){
            struct Tree *tmp = node->right;
            delete(node);
            return tmp;
        }else if (node->right == NULL){
            struct Tree *tmp = node->left;
            delete(node);
            return tmp;
        }

        struct Tree* tmp = node->right;

        node->key = tmp->key;

        while (tmp->left != NULL){
            tmp = tmp->left;
        }
        node->right = del_node(node->right, tmp->key);
    }
    return node;
}*/

int height(Tree* root){
    if (root == NULL){
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

int getBalance(Tree* root){
    if (root == NULL){
        return 0;
    }
    return height(root->left) - height(root->right);
}

Tree* rightRotate(Tree* root){
    Tree* x = root->left;
    Tree* y = x->right;
    x->right = root;
    root->left = y;

    return x;
}

Tree* leftRotate(Tree* root){
    Tree* y = root->right;
    Tree* x = y->left;
    y->left = root;
    root->right = x;

    return y;
}

Tree* balance(Tree* root){
    int balance = getBalance(root);
    if (balance > 1) {
        if (getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
        }
        return rightRotate(root);
    }
    if (balance < -1) {
        if (getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
        }
        return leftRotate(root);
    }
    return root;
}

void show_branch(Tree *root, int l){
    if (!root) return;
    show_branch(root->right, l+1);
    for (int i = 0 ; i < l ; i++) printf("   ");
    cout << root->key << endl;
    show_branch(root->left, l+1);
}

void show(Tree *root){
    if (root == NULL) {
        return;
    }
    show_branch(root, 0);
}

int main(){

    add_node(6);
    add_node(5);
    add_node(8);
    add_node(2);
    add_node(3);

    show(root);

    for(int i = 0 ; i < 20 ; i++)  cout << "-";
    cout << endl;

    rem(root,2);
    show(root);

    for(int i = 0 ; i < 20 ; i++)  cout << "-";
    cout << endl;

    root = balance(root);
    show(root);

return 0;
}

