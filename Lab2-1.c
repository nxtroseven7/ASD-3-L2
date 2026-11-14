#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int val;
    struct DNode *prev;
    struct DNode *next;
} DNode;

static int randomValue(void) {
    return rand() % 20;
}

static DNode *newNode(int v) {
    DNode *p = (DNode *)malloc(sizeof(DNode));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    p->val = v;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

/* 1- FIFO creation: insertion at the tail */
DNode *CreateFifoDLL(int n) {
    DNode *head = NULL, *tail = NULL;
    int i;
    for (i = 0; i < n; i++) {
        DNode *p = newNode(randomValue());
        if (head == NULL)
            head = tail = p;
        else {
            tail->next = p;
            p->prev = tail;
            tail = p;
        }
    }
    return head;
}

/* 2- Display */
void DisplayDLL(DNode *head) {
    if (head == NULL) {
        printf("(empty list)\n");
        return;
    }
    printf("NULL <-> ");
    while (head != NULL) {
        printf("%d <-> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

/* 3- Delete every occurrence of value V */
DNode *DeleteValueDLL(DNode *head, int V) {
    DNode *cur = head;
    while (cur != NULL) {
        DNode *next = cur->next;
        if (cur->val == V) {
            if (cur->prev != NULL)
                cur->prev->next = cur->next;
            else
                head = cur->next;
            if (cur->next != NULL)
                cur->next->prev = cur->prev;
            free(cur);
        }
        cur = next;
    }
    return head;
}

/* 4- Shift all elements one position to the right;
      the last element goes back to the top of the list */
void RightRotation(DNode **head) {
    DNode *last;
    if (*head == NULL || (*head)->next == NULL)
        return;
    last = *head;
    while (last->next != NULL)
        last = last->next;
    /* detach last */
    last->prev->next = NULL;
    /* put it at the top */
    last->prev = NULL;
    last->next = *head;
    (*head)->prev = last;
    *head = last;
}

/* 5- Returns 1 if L1 is a suffix of L2, 0 otherwise */
int isSuffix(DNode *L1, DNode *L2) {
    if (L1 == NULL)
        return 1; /* empty list is a suffix of any list */
    if (L2 == NULL)
        return 0;
    /* go to the last node of each list */
    while (L1->next != NULL)
        L1 = L1->next;
    while (L2->next != NULL)
        L2 = L2->next;
    /* compare backwards */
    while (L1 != NULL && L2 != NULL) {
        if (L1->val != L2->val)
            return 0;
        L1 = L1->prev;
        L2 = L2->prev;
    }
    return L1 == NULL;
}

void FreeDLL(DNode *head) {
    while (head != NULL) {
        DNode *tmp = head;
        head = head->next;
        free(tmp);
    }
}

/* 6- Main program using all the functions */
int main(void) {
    int n, V, k, i;
    DNode *list, *suffix = NULL, *tail = NULL, *p, *q;

    printf("Number of elements n: ");
    if (scanf("%d", &n) != 1 || n < 0)
        return 1;

    list = CreateFifoDLL(n);
    printf("FIFO DLL : ");
    DisplayDLL(list);

    printf("Value V to delete: ");
    if (scanf("%d", &V) != 1)
        return 1;
    list = DeleteValueDLL(list, V);
    printf("After deleting %d : ", V);
    DisplayDLL(list);

    RightRotation(&list);
    printf("After right rotation : ");
    DisplayDLL(list);

    /* Build L1 = the last k elements of the list, to test isSuffix */
    printf("Size k of the suffix list L1 (copied from the end of the list): ");
    if (scanf("%d", &k) != 1)
        return 1;
    p = list;
    if (p != NULL)
        while (p->next != NULL)
            p = p->next;
    for (i = 1; p != NULL && p->prev != NULL && i < k; i++)
        p = p->prev;          /* p = first node of the last k elements */
    if (k <= 0)
        p = NULL;
    for (; p != NULL; p = p->next) {
        q = newNode(p->val);
        if (suffix == NULL)
            suffix = tail = q;
        else {
            tail->next = q;
            q->prev = tail;
            tail = q;
        }
    }
    printf("L1 : ");
    DisplayDLL(suffix);
    printf("L1 is %sa suffix of the list\n", isSuffix(suffix, list) ? "" : "NOT ");

    FreeDLL(list);
    FreeDLL(suffix);
    return 0;
}
