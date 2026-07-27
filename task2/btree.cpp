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


//!terzo punto O(n) 
// per definizione se un albero è bilanciato => |hd - hs| ≤ 1, vale per tutti i sottoalberi
// cercare di farlo in O(n)

//trovare il valore assoluto
int absoluteValue(int number){
    return (number < 0) ? -number : number;
}

//calcolo l'altezza e il bilanciamento
int checkBalanced(node* tree){
    // se l'albero è vuoto...
    if(tree == nullptr){
        return 0;
    }

    // l'altezza dei due sottoalberi destro e sinistro     
    int leftHeight = checkBalanced(tree->left);
    int rightHeight = checkBalanced(tree->right);

    // controllo lo sbilanciamento dei due sotto alberi immediatamente
    // se uno dei due alberi e sbilanciato non vado avanti
    if((leftHeight == -1) || (rightHeight == -1)){
        return -1;
    }
    //|hd - hs| ≤ 1
    if(absoluteValue(leftHeight - rightHeight) <= 1){
        return 1 + max(leftHeight, rightHeight);
    }else{
        return -1;
    }
}

bool isBalanced(node* tree){
    return checkBalanced(tree) != -1;
}

//* quarto punto
//completo è un albero in cui tutti i livelli eventualmente tranne l’ultimo
// sono completamente pieni e l'ultimo livello è riempito da sinistra a destra.

//si deve controllare la posizione dei nodi mancanti.
bool isComplete(node* tree){
    
}

int main(){
    return 0;
}