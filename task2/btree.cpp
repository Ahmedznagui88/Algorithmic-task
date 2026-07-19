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

int max(int leftHeight, int rightHeight){
    return (leftHeight > rightHeight) ? leftHeight : rightHeight;
}

int treeHeight(node* tree){
    if(tree == nullptr) return 0;
    return 1 + max(treeHeight(tree->left), treeHeight(tree->right));
}

void treeDepth(node* tree, int currentDepth){
    
}

int main(){
    return 0;
}