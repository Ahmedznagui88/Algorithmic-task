#include <iostream>

struct node{
    int data;
    node* right;
    node* left;
};

void flip(node* &tree) {
    node* tem;

    if(tree == nullptr) {
        return;
    }else {
        tem = tree->right;
        tree->right = tree->left;
        tree->left = tem;

        flip(tree->left);
        flip(tree->right);
    }
}


int main(){
    return 0;
}