#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of the node structure for a doubly linked list
struct lista {
    int info;             // Data stored in the node
    struct lista *prox;   // Pointer to the next node in the list
    struct lista *ant;    // Pointer to the previous node in the list
};

typedef struct lista Lista;

// Function that initializes the list, returning an empty list (NULL)
Lista* inicializaLista(){
    return NULL;
}

// Function that checks if the list is empty
// Returns true if the pointer is NULL, false otherwise
bool vazia(Lista *pL){
    if(pL == NULL)
        return true;             
    else
        return false;
}

// Function that inserts a new node at the beginning of the list
Lista* inserir(Lista *pL, int valor){
    // Allocate memory for a new node
    Lista *novo = (Lista *) malloc(sizeof(Lista));
    if(novo != NULL){
        novo->info = valor;      // Assign the value to the info field
        novo->prox = pL;         // The next node will be the old first node
        novo->ant = NULL;        // Since it's inserted at the beginning, there is no previous node
        
        // If the list is not empty, update the "ant" pointer of the old first node
        if(pL != NULL){
            pL->ant = novo;
        }
        printf("Inserted: %d\n", novo->info);
        return novo;             // Return the new node, which becomes the head of the list       
    }
    // If memory allocation fails, return the original list unchanged
    return pL;
}

// Function that prints the elements of the list from beginning to end
void imprimir(Lista *pL){
    while(pL != NULL){
        printf(" %d ", pL->info); // Print the value stored in the current node
        pL = pL->prox;           // Move to the next node
    }     
    printf("\n\nEnd of the Linked List!\n\n");
}

// Function that searches for a node with a specific value in the list
Lista* buscar(Lista *pL, int valor){
    while(pL != NULL){
        if(pL->info == valor)
            return pL;  // If found, return the pointer to that node
        else
            pL = pL->prox; // Continue searching
    }    
    return pL;  // Returns NULL if the element is not found
}

// Function that removes a node with the specified value from the list
Lista* remover(Lista *pL, int valor) {
    Lista *p = pL; // Auxiliary pointer to traverse the list
    
    // Search for the node that contains the desired value
    while(p != NULL && p->info != valor) {
        p = p->prox;
    }
    
    // If the node is not found, return the list unchanged
    if(p == NULL)
        return pL;
    
    // Adjust the pointers of the neighboring nodes of the node to be removed:
    // If there is a previous node, update its 'prox' pointer
    if(p->ant != NULL) {
        p->ant->prox = p->prox;
    } else {
        // If there is no previous node, the removed node is the first one, update the head of the list
        pL = p->prox;
    }
    
    // If there is a next node, update its 'ant' pointer
    if(p->prox != NULL) {
        p->prox->ant = p->ant;
    }
    
    // Free the memory of the removed node
    free(p);
    return pL;
}

// Function that frees all memory allocated for the list
void libera(Lista *pL){
    Lista *p = pL;
    Lista *t;
    
    // Traverse the list, freeing each node
    while(p != NULL){
        t = p->prox; // Save the address of the next node
        free(p);     // Free the current node
        p = t;       // Move to the next node
    }
}

// Helper function to display, for each node, its value and the values of its previous and next nodes
void mostrarAnteriorProximo(Lista *pL) {
    Lista *temp = pL;
    // Traverse the entire list
    while (temp != NULL) {
        printf("Node: %d, ", temp->info);
        
        // Check and display the value of the previous node, if it exists
        if (temp->ant != NULL)
            printf("Previous: %d, ", temp->ant->info);
        else
            printf("Previous: NULL, ");
        
        // Check and display the value of the next node, if it exists
        if (temp->prox != NULL)
            printf("Next: %d", temp->prox->info);
        else
            printf("Next: NULL");
        
        printf("\n");
        temp = temp->prox; // Move to the next node
    }
}

int main() {
    // Initialize the list as empty
    Lista *L = inicializaLista();
    Lista *Q;
    
    // Insert elements into the list (each insertion is at the beginning)
    L = inserir(L, 1000);
    L = inserir(L, 100);
    L = inserir(L, 10);
    L = inserir(L, 1);
    
    // Print the list linearly
    printf("Printing the List:\n");
    imprimir(L);
    
    // Display, for each node, its value, the value of its previous node, and the value of its next node
    printf("\nDisplaying each node with its previous and next pointers:\n");
    mostrarAnteriorProximo(L);

    // Remove the node that contains the value 10 from the list
    printf("Removing the value 10 from the List!\n");
    L = remover(L, 10);

    // Display the list again with the nodes and their respective pointers
    printf("\nDisplaying each node with its previous and next pointers:\n");
    mostrarAnteriorProximo(L);
    
    // Free the memory allocated for the list
    libera(L);
    
    system("PAUSE");
    return 0;
}
