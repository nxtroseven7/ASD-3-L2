#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *prev;
    struct Node *next;
} Node;

Node *CreateFifoDLL(int n){
    Node *head = NULL, *tail = NULL;
    Node *p;
    int i, v;
    for(i=0;i<n;i++){
        printf("Element %d: ", i + 1);
        scanf("%d", &v);
        p = (Node *)malloc(sizeof(Node));
        p->val = v;
        p->prev = NULL;
        p->next = NULL;
        if(head == NULL){
            head = tail = p;
        }else{
            tail->next = p;
            p->prev = tail;
            tail = p;
        }
    }
    return head;
}

void DisplayDLL(Node *head){
    if(head == NULL){
        printf("(empty list)\n");
        return;
    }
    printf("NULL <-> ");
    while(head != NULL){
        printf("%d <-> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

Node *DeleteValueDLL(Node *head, int Value){
    Node *cur = head, *next;
    while(cur != NULL){
        next = cur->next;
        if(cur->val == Value){
            if(cur->prev != NULL){
                cur->prev->next = cur->next;
            }else{
                head = cur->next;
            }
            if(cur->next != NULL){
                cur->next->prev = cur->prev;
            }
            free(cur);
        }
        cur = next;
    }
    return head;
}

void RightRotation(Node *head){
    Node *last;
    int saved;
    if(head == NULL || head->next == NULL){
        return;
    }
    last = head;
    while(last->next != NULL){
        last = last->next;
    }
    saved = last->val;
    while(last != head){
        last->val = last->prev->val;
        last = last->prev;
    }
    head->val = saved;
}

int isSuffix(Node *L1, Node *L2){
    if(L1 == NULL){
        return 1;
    }
    if(L2 == NULL){
        return 0;
    }
    while(L1->next != NULL){
        L1 = L1->next;
    }
    while(L2->next != NULL){
        L2 = L2->next;
    }
    while(L1 != NULL && L2 != NULL){
        if(L1->val != L2->val){
            return 0;
        }
        L1 = L1->prev;
        L2 = L2->prev;
    }
    return L1 == NULL;
}

int main(void){
    int n, Value;
    Node *list, *L1;

    printf("Number of elements n: ");
    if(scanf("%d", &n) != 1 || n < 0){
        return 1;
    }

    list = CreateFifoDLL(n);
    printf("FIFO DLL : ");
    DisplayDLL(list);

    printf("Value to delete: ");
    scanf("%d", &Value);
    list = DeleteValueDLL(list, Value);
    printf("After deleting %d : ", Value);
    DisplayDLL(list);

    RightRotation(list);
    printf("After right rotation : ");
    DisplayDLL(list);

    printf("List L1 (to test isSuffix)\n");
    printf("Number of elements of L1: ");
    scanf("%d", &n);
    L1 = CreateFifoDLL(n);
    printf("L1 : ");
    DisplayDLL(L1);
    printf("Press Enter to check if L1 is suffix:");
    getchar();
    if(isSuffix(L1, list)){
        printf("L1 is a suffix of the list\n");
    } else{
        printf("L1 is NOT a suffix of the list\n");
    }
    return 0;
}
