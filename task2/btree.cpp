#include <iostream>

struct node{
    int data;
    node* right;
    node* left;
};

//! primo punto 
// flip tra nodi fratelli
void flip(node* &tree) {
    //var temporanea
    node* tem;

    // soluzione ricorsiva
    if(tree == nullptr) {
        //caso base
        return;
    }else {
        //al passo induttivo...
        // salvo il nodo destro per non perderlo
        tem = tree->right;

        //flip dei nodi
        tree->right = tree->left;
        tree->left = tem;
        flip(tree->left);
        flip(tree->right);
    }
}

//* secondo punto

int max(int leftHeight, int rightHeight) {
    return (leftHeight > rightHeight) ? leftHeight : rightHeight;
}

int treeHeight(node* tree) {
    if(tree == nullptr) return 0;
    // l'altezza del nodo è 1 (l'arco verso il figlio), più l'altezza del sottoalbero più profondo tra sinistro e destro
    return 1 + max(treeHeight(tree->left), treeHeight(tree->right));
}

// currentDepth = profondità del nodo padre; ogni chiamata ricorsiva
// la incrementa di 1 per l'arco percorso verso il figlio.

void treeDepth(node* tree, int currentDepth) {
    // Caso base: nodo nullo → nessun arco da contare, ci si ferma.
    if(tree == nullptr) {
        return;
    }else {
        // Stampa la profondità di ogni nodo (visita pre-order, top-down).
        std::cout<<tree->data << " " << currentDepth<<std::endl;
        treeDepth(tree->left, currentDepth + 1);
        treeDepth(tree->right, currentDepth + 1);
    }    
}

//!terzo punto 

bool isBalanced(node* tree){
    
}

int main(){
    return 0;
}