#include <stdio.h>
#include <stdlib.h>

//DODAWANIE NA POCZATEK

struct Node {
    int dane;
    struct Node* nast;
};

void printList(struct Node* n)
{
    while (n != NULL) {
        printf(" %d ", n->dane);
        n = n->nast;
    }
}

struct Node* push_front(struct Node** head_ref, int nowe_dane)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->dane  = nowe_dane;
    new_node->nast = (*head_ref);
    (*head_ref)    = new_node;
    return *head_ref;
}


int main()
{

    struct Node* head = NULL;
    struct Node* drugi = NULL;
    struct Node* trzeci = NULL;


    head = (struct Node*)malloc(sizeof(struct Node));
    drugi = (struct Node*)malloc(sizeof(struct Node));
    trzeci = (struct Node*)malloc(sizeof(struct Node));

    head->dane = 1;
    head->nast = drugi;
    drugi->dane=2;
    drugi->nast = trzeci;
    trzeci->dane=3;
    trzeci->nast=NULL;

    printList(head);
    printf("\n");

    push_front(&head,8);

    printList(head);


    return 0;
}
