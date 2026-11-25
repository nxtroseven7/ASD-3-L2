#include "libStackQueue.c"

void ReverseFK(Queue *Q, int k){
    Stack S;
    Queue R;
    TypeElm x;
    int i;

    InitStack(&S);
    for(i = 0;i<k;i++){
        Dequeue(&R,&x);
        Push(&S,x);
    }

    while(!isSEmpty(S)){
        Pop(&S,&x);
        Enqueue(&R,x);
    }

    while(!isQEmpty(*Q)){
        Dequeue(Q,&x);
        Enqueue(&R,x);
    }
    while(!isQEmpty(R)){
        Dequeue(&R,&x);
        Enqueue(Q,x);
    }
}
