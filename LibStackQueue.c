
#include <stdlib.h>
#include <stdbool.h>

///declaration of TypeElement
typedef int TypeElm;
//typedef char TypeElm;

///declaration of a Stack
typedef struct Estack* Stack;
typedef struct Estack { TypeElm Data; Stack Next; } SNode;

///declaration of a Queue
typedef struct Element* EQueue;
typedef struct Element { TypeElm Data; EQueue Next; } QNode;
typedef struct { EQueue Head, Tail; } Queue;

///Stacks operations
///procedure InitStack
void InitStack(Stack *P)
{*P=NULL;}

///procedure Push
void Push(Stack *S, TypeElm x)
{Stack V;
 V=malloc(sizeof(SNode));
 V->Data=x;
 V->Next=*S;
 *S=V;
}

///procedure Pop
void Pop(Stack *S, TypeElm *x)
{Stack V;
 *x=(*S)->Data;
 V=*S;
 *S=(*S)->Next;
 free(V);
}

///Function isSEmpty
int isSEmpty(Stack S)
{if (S==NULL) return 1;
 else return 0;
}

///Function Top
TypeElm Top(Stack S)
{return S->Data;}


///Queues operations
///procedure InitQueue
void InitQueue(Queue *Q)
{(*Q).Head=NULL; (*Q).Tail=NULL;}

///procedure Enqueue
void Enqueue(Queue *Q, TypeElm x)
{EQueue V;
 V=malloc(sizeof(QNode));
 V->Data=x;
 V->Next=NULL;
 if ((*Q).Head==NULL) (*Q).Head=V; //the Queue is empty
 else (*Q).Tail->Next=V;
 (*Q).Tail=V;
}

///procedure Dequeue
void Dequeue(Queue *Q, TypeElm *x)
{EQueue V;
 V=(*Q).Head;
 *x=V->Data; //ou  *x=(*Q).Head->Data;

 if ((*Q).Head==(*Q).Tail) {(*Q).Head=NULL; (*Q).Tail=NULL;}
 else (*Q).Head=(*Q).Head->Next; // ou  (*Q).Head=V->Next;
 free(V);
}

int isQEmpty(Queue Q)
{if (Q.Head==NULL) return 1;
 else return 0;
}

///Function Head
TypeElm Head(Queue Q)
{return Q.Head->Data;}
