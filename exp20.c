#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
// node insertion at tail

typedef struct Node{
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

void reverse(){
    node* current,* next,* prev;
    current=head;
    prev=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}


void main(){
     
head=NULL;
insert(2);print();
insert(3);print();
insert(4);print();
insert(9);print();
insert(10);print();
reverse();print();






    
}