#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dane;
    struct Node* nast;
};

int liczba_elementow(struct Node* head)
{
    int liczba = 0;
    struct Node* obecny = head;
    while (obecny != NULL)
    {
        liczba++;
        obecny = obecny->nast;
    }
    return liczba;
}

int main()
{

    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    if (head == NULL) {
    return 1;
    }

    head->dane = 1;
    head->nast = (node_t *) malloc(sizeof(node_t));
    head->nast->dane = 2;
    head->nast->nast = (node_t *) malloc(sizeof(node_t));
    head->nast->nast->dane = 3;
    head->nast->nast->nast = NULL;

    printf("%d",liczba_elementow(head));

    return 0;
}
