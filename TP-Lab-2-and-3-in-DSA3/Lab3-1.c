#include <stdbool.h>
#include <stdio.h>
#include "LibStackQueue.c"

void CreateStack(Stack *S){
    TypeElm x;
    int i;
    int n;

    printf("Enter the number of element you want to push in the stack :");
    do{
        scanf("%d",&n);
    } while(n<=0);
    InitStack(S);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        Push(S,x);
    }
}


void DisplayStack(Stack *S){
    Stack R;
    TypeElm x;
    if (isSEmpty(*S)){
        printf("\nEmpty Stack...\n");
    } else{
        InitStack(&R);
        while (!isSEmpty(*S)){
            Pop(S,&x);
            Push(&R,x);
            printf("%d ",x);
        }
        while(!isSEmpty(R)){
            Pop(&R,&x);
            Push(S,x);
        }
    }
}


int Occurrence(Stack *S,TypeElm val){
    Stack R;
    TypeElm x;
    int counter=0;
    if (isSEmpty(*S)){
        printf("\nEmpty Stack...\n");
    } else{
        InitStack(&R);
        while (!isSEmpty(*S)){
            Pop(S,&x);
            if(x == val){
                counter++;
            }
            Push(&R,x);
        }
        while(!isSEmpty(R)){
            Pop(&R,&x);
            Push(S,x);
        }
    }
    return counter;
}

void DeleteMul(Stack *S,TypeElm val){
    Stack R;
    TypeElm x;
    InitStack(&R);
    while (!isSEmpty(*S)){
        Pop(S,&x);
        if (x % val != 0){
            Push(&R,x);
        }
    }
    while (!isSEmpty(R)){
        Pop(&R,&x);
        Push(S,x);
    }
}

void ReverseLK(Stack *S, int k){
    Stack R,T;
    TypeElm x;
    int counter=0;
    if (isSEmpty(*S)){
        printf("\nEmpty Stack...\n");
    } else{
        InitStack(&R);
        while (!isSEmpty(*S)){
            Pop(S,&x);
            Push(&R,x);
            counter++;
        }

        if(k > counter){
            k = counter;
        }

        InitStack(&T);
        for(int i=0;i<k;i++){
            Pop(&R,&x);
            Push(&T,x);
        }

        while(!isSEmpty(T)){
            Pop(&T, &x);
            Push(S, x);
        }

        while(!isSEmpty(R)){
            Pop(&R, &x);
            Push(S, x);
        }
    }
}

bool isPrefix(Stack *S1, Stack *S2){
    Stack Temp1,Temp2;
    TypeElm x1,x2;
    bool Prefix = true;
    InitStack(&Temp1);
    InitStack(&Temp2);
    if(Top(*S1) != Top(*S2)){
        return false;
    } else {
        while(!isSEmpty(*S1) && !isSEmpty(*S2) && Prefix){
            if(x1 != x2){
                Prefix = false;
            }
            Push(&Temp1,x1);
            Push(&Temp2,x2);
        }

        if(!isSEmpty(*S1)){
            Prefix = false;
        }
        while(!isSEmpty(Temp1)){
            Pop(&Temp1,&x1);
            Pop(&Temp2,&x2);
            Push(S1,x1);
            Push(S2,x2);
        }
        return Prefix;
    }
}




int main(){
    int i,x;
      int result;
      TypeElm value_Occ;
      int m,k;
      TypeElm val;
      Queue Q;
      Stack S,S2;

      CreateStack(&S);
      printf("\nThe elements of the Stack :\n");
      DisplayStack(&S);

      printf("Enter a value that you want to check it's occurences in the Stack :");
      scanf("%d",&value_Occ);
      result = Occurrence(&S, value_Occ);
      printf("There are %d occurences\n", result);


      printf("\nEnter a value (not 0) to delete its multiples from the Stack :");
      scanf("%d",&val);
      DeleteMul(&S, val);
      printf("The Stack after DeleteMul :\n");
      DisplayStack(&S);


      printf("\nEnter k to reverse the last k elements of the Stack :");
      scanf("%d",&k);
      ReverseLK(&S, k);
      printf("The Stack after ReverseLK :\n");
      DisplayStack(&S);


      printf("\nInput the size of the second Stack :");
      scanf("%d",&m);
      printf("Input the %d elements of the second Stack :\n",m);
      CreateStack(&S2);
      if(isPrefix(&S,&S2)){
        printf("\nThe shorter Stack is a prefix of the other\n");
      }else{
          printf("\nNo prefix relation between the two Stacks\n");
      }
      return 0;
  }
