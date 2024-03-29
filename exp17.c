#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
// node insertion,deletion at end

typedef struct Node{a
    int data;
    struct Node* next;
}node;
node* head;

void insert(int x){
    node* temp1=(node*)malloc(sizeof(node));
    temp1->data=x;
    temp1->next=NULL;
    if(head==NULL){
        head=temp1;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=temp1;


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
void position(int n){
    node* temp=head;
    for(int i=1;i<=n-1;i++){
        temp=temp->next;
    }
    printf("%dnd value is:%d\n",n,temp->data);
}


void main(){
     
head=NULL;
insert(2);print();
insert(3);print();
delete(1);print();
insert(4);print();
insert(5);print();
position(2);
insert(2);print();






    
}