#include <stdio.h>
#include <stdlib.h>

//ODWRACANIE LISTY
struct Node {
    int dane;
    struct Node* nast;
};

struct Node* obroc(struct Node** head_ref)
{
    struct Node* poprz = NULL;
    struct Node* obecny = *head_ref;
    struct Node* nast = NULL;
    while (obecny != NULL) {
        nast = obecny->nast;
        obecny->nast = poprz;
        poprz = obecny;
        obecny = nast;
    }
    *head_ref = poprz;
    return *head_ref;
}

void printList(struct Node* n)
{
    while (n != NULL) {
        printf(" %d ", n->dane);
        n = n->nast;
    }
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
    obroc(&head);
    printList(head);

    return 0;
}
