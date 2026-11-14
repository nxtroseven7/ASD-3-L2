#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node *CreateLifoSLL(int n){
    Node *head = NULL;
    Node *p;
    int i, v;
    for(i=0;i<n;i++){
        printf("Element %d: ", i + 1);
        scanf("%d", &v);
        p = (Node *)malloc(sizeof(Node));
        p->val = v;
        p->next = head;
        head = p;
    }
    return head;
}

Node *CreateFifoSLL(int n){
    Node *head = NULL, *tail = NULL;
    Node *p;
    int i, v;
    for(i=0;i<n;i++){
        printf("Element %d: ", i + 1);
        scanf("%d", &v);
        p = (Node *)malloc(sizeof(Node));
        p->val = v;
        p->next = NULL;
        if(head == NULL){
            head = tail = p;
        }else{
            tail->next = p;
            tail = p;
        }
    }
    return head;
}

void DisplaySLL(Node *head){
    if(head == NULL){
        printf("(empty list)\n");
        return;
    }
    while(head != NULL){
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

Node *DeleteValueSLL(Node *head, int Value){
    Node *cur = head, *prev = NULL, *temp;
    while(cur != NULL){
        if(cur->val == Value){
            temp = cur;
            if(prev == NULL){
                head = cur->next;
            }else{
                prev->next = cur->next;
            }
            cur = cur->next;
            free(temp);
        }else{
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}

void DeleteDuplicate(Node *head){
    Node *p, *q, *temp;
    for(p=head;p!=NULL;p=p->next){
        q = p;
        while(q->next != NULL){
            if(q->next->val == p->val){
                temp = q->next;
                q->next = temp->next;
                free(temp);
            } else{
                q = q->next;
            }
        }
    }
}

int isPrefix(Node *L1, Node *L2){
    while(L1 != NULL && L2 != NULL){
        if(L1->val != L2->val){
            return 0;
        }
        L1 = L1->next;
        L2 = L2->next;
    }
    return L1 == NULL;
}

int main(void){
    int n, Value;
    Node *lifo, *fifo, *L1;

    printf("Number of elements n: ");
    if(scanf("%d", &n) != 1 || n < 0){
        return 1;
    }

    printf("--- LIFO list ---\n");
    lifo = CreateLifoSLL(n);
    printf("LIFO list : ");
    DisplaySLL(lifo);

    printf("--- FIFO list ---\n");
    fifo = CreateFifoSLL(n);
    printf("FIFO list : ");
    DisplaySLL(fifo);

    printf("Value to delete from the FIFO list: ");
    scanf("%d", &Value);
    fifo = DeleteValueSLL(fifo, Value);
    printf("After deleting %d : ", Value);
    DisplaySLL(fifo);

    DeleteDuplicate(lifo);
    printf("LIFO list without duplicates : ");
    DisplaySLL(lifo);

    printf("--- List L1 (FIFO, to test isPrefix) ---\n");
    printf("Number of elements of L1: ");
    scanf("%d", &n);
    L1 = CreateFifoSLL(n);
    printf("L1 : ");
    DisplaySLL(L1);
    if(isPrefix(L1, lifo)){
        printf("L1 is a prefix of the LIFO list\n");
    }else{
        printf("L1 is NOT a prefix of the LIFO list\n");
    }
    if(isPrefix(L1, fifo)){
        printf("L1 is a prefix of the FIFO list\n");
    }else{
        printf("L1 is NOT a prefix of the FIFO list\n");
    }
    return 0;
}
