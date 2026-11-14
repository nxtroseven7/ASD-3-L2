#include <stdbool.h>
#include <stdio.h>
#include "LibStackQueue.c"


void CreateQueue(Queue *Q){
    TypeElm x;
    int i;
    int n;

    printf("Enter the number of element you want to enqueue in the queue :");
    do{
        scanf("%d",&n);
    } while(n<=0);
    InitQueue(Q);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        Enqueue(Q,x);
    }
}

void DisplayQueue(Queue *Q){
    Queue R;
    TypeElm x;
    if (isQEmpty(*Q)){
        printf("\nEmpty Queue...\n");
    } else{
        InitQueue(&R);
        while (!isQEmpty(*Q)){
            Dequeue(Q,&x);
            Enqueue(&R,x);
            printf("%d ",x);
        }
        while(!isQEmpty(R)){
            Dequeue(&R,&x);
            Enqueue(Q,x);
        }
    }
}


int Occurrence(Queue *Q,TypeElm val){
    Queue R;
    TypeElm x;
    int counter=0;
    if (isQEmpty(*Q)){
        printf("\nEmpty Queue...\n");
    } else{
        InitQueue(&R);
        while (!isQEmpty(*Q)){
            Dequeue(Q,&x);
            if(x == val){
                counter++;
            }
            Enqueue(&R,x);
        }
        while(!isQEmpty(R)){
            Dequeue(&R,&x);
            Enqueue(Q,x);
        }
    }
    return counter;
}

void DeleteMul(Queue *Q,TypeElm val){
    Queue R;
    TypeElm x;
    InitQueue(&R);
    while (!isQEmpty(*Q)){
        Dequeue(Q,&x);
        if (x % val != 0){
            Enqueue(&R,x);
        }
    }
    while (!isQEmpty(R)){
        Dequeue(&R,&x);
        Enqueue(Q,x);
    }
}

void ReverseLK(Queue *Q, int k){
    Queue R;
    Stack P;
    TypeElm x;
    int counter=0;
    if (isQEmpty(*Q)){
        printf("\nEmpty Queue...\n");
    } else{
        InitQueue(&R);
        InitStack(&P);
        while (!isQEmpty(*Q)){
            Dequeue(Q,&x);
            Enqueue(&R,x);
            counter++;
        }

        if(k > counter){
            k = counter;
        }

        if(k < 0){
            k = 0;
        }


        for(int i=0;i<counter-k;i++){
            Dequeue(&R,&x);
            Enqueue(Q,x);
        }

        while(!isQEmpty(R)){
            Dequeue(&R,&x);
            Push(&P,x);
        }

        while(!isSEmpty(P)){
            Pop(&P,&x);
            Enqueue(Q,x);
        }
    }
}

bool isPrefix(Queue *Q1, Queue *Q2){
    Queue Temp1,Temp2;
    TypeElm x1,x2;
    bool Prefix = true;
    InitQueue(&Temp1);
    InitQueue(&Temp2);

    while(!isQEmpty(*Q1) && !isQEmpty(*Q2) && Prefix){
        Dequeue(Q1,&x1);
        Dequeue(Q2,&x2);
        if(x1 != x2){
            Prefix = false;
        }
        Enqueue(&Temp1,x1);
        Enqueue(&Temp2,x2);
    }

    while(!isQEmpty(*Q1)){
        Dequeue(Q1,&x1);
        Enqueue(&Temp1,x1);
    }
    while(!isQEmpty(Temp1)){
        Dequeue(&Temp1,&x1);
        Enqueue(Q1,x1);
    }

    while(!isQEmpty(*Q2)){
        Dequeue(Q2,&x2);
        Enqueue(&Temp2,x2);
    }
    while(!isQEmpty(Temp2)){
        Dequeue(&Temp2,&x2);
        Enqueue(Q2,x2);
    }

    return Prefix;
}





int main(){
    int result,k;
    TypeElm value_Occ,val;
    Queue Q,Q2;

    CreateQueue(&Q);
    printf("\nThe elements of the Queue :\n");
    DisplayQueue(&Q);

    printf("\nEnter a value that you want to check it's occurences in the Queue :");
    scanf("%d",&value_Occ);
    result = Occurrence(&Q, value_Occ);
    printf("There are %d occurences\n", result);

    printf("\nEnter a value (not 0) to delete its multiples from the Queue :");
    scanf("%d",&val);
    DeleteMul(&Q, val);
    printf("The Queue after DeleteMul :\n");
    DisplayQueue(&Q);

    printf("\nEnter k to reverse the last k elements of the Queue :");
    scanf("%d",&k);
    ReverseLK(&Q, k);
    printf("The Queue after ReverseLK :\n");
    DisplayQueue(&Q);

    printf("\nCreate the second Queue :\n");
    CreateQueue(&Q2);
    if(isPrefix(&Q,&Q2)) printf("\nThe shorter Queue is a prefix of the other\n");
    else printf("\nNo prefix relation between the two Queues\n");

    return 0;
}
