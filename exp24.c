#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
// node insertion,deletion at nth position

typedef struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
}node;
node* head;

node* getnewnode(){
    node newnode;
    newnode.next=NULL;
    newnode.prev=NULL;

    return &newnode;
}

void insertathead(int x){
    node* newnode=getnewnode();
    newnode->data=x;
    if(head==NULL){
        head=newnode;
        return;
    }
    head->prev=newnode;
    newnode->next=head;
    head=newnode; 

}

void printF(){
    node* temp=head;
    printf("list is:");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void printR(){
    node* temp=head;
    if(temp==NULL) return;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    printf("list is:");

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
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
insertathead(2);printF();printR();
insertathead(3);printF();printR();
insertathead(5);printF();printR();
insertathead(7);printF();printR();






    
}