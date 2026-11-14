#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char letter;
    struct Node *next;
} Node;

void DisplayCLL(Node *head){
    Node *p;
    if(head == NULL){
        printf("(empty list)\n");
        return;
    }
    p = head;
    do{
        printf("%c", p->letter);
        p = p->next;
    }while(p != head);

}

Node *Evolve(Node *head){
    Node *newHead = NULL, *newTail = NULL;
    Node *current, *last, *p, *temp;
    char *String;
    int i;
    last = head;
    while(last->next != head){
        last = last->next;
    }
    last->next = NULL;
    current = head;
    while(current != NULL){
        if(current->letter == 'A'){
            String = "BAC";
        }else if(current->letter == 'B'){
            String = "CAB";
        } else{
            String = "";
        }
        for(i=0;String[i]!='\0';i++){
            p = (Node *)malloc(sizeof(Node));
            p->letter = String[i];
            p->next = NULL;
            if(newHead == NULL){
                newHead = newTail = p;
            }else{
                newTail->next = p;
                newTail = p;
            }
        }
        temp = current;
        current = current->next;
        free(temp);
    }
    newTail->next = newHead;
    return newHead;
}

int main(){
    int n, i;
    Node *head;

    printf("Number of steps n: ");
    scanf("%d", &n);
    if(n != 1 || n < 0){
        return 1;
    }

    head = (Node *)malloc(sizeof(Node));
    head->letter = 'A';
    head->next = head;

    for(i=0;i<=n;i++){
        printf("Step %d : ", i);
        DisplayCLL(head);
        if(i < n){
            head = Evolve(head);
        }
    }
    return 0;
}
