#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
// node insertion at beginning

typedef struct Node{
    int data;
    struct Node* next;
}node;
node* head;

void insert(int x){
    node* temp=(node*)malloc(sizeof(node));
    temp->data=x;
    temp->next=head;
    head=temp;

}

void print(){
    node* temp=head;
    printf("list is:");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void delete(int n){
    node*temp1=head;
    if(n==1){
        head=temp1->next;
        free(temp1);
        return;
    }
    for(int i=0;i<=n-1;i++){
        temp1=temp1->next;
        
    }
    node* temp2=temp1->next;
    temp1->next=temp2->next;
    free(temp2);
}


void main(){
     
head=NULL;
printf("how many nos:");
int n,i,x;
scanf("%d",&n);
for(int i=1;i<=n;i++){
    printf("enter the no:");
    scanf("%d",&x);
    insert(x);
    print();
}






    
}