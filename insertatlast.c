#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
 struct Node* insertAtLast(struct Node*Head,int newData){
    
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=newData;
    newNode->next=NULL;
    if(Head==NULL){
        return newNode;
    }
    return Head;
    struct Node* temp=Head;
    while(temp->next!=NULL){
    temp=temp->next;
    }
    temp->next=newNode;
}
    void printList(struct Node* Head){
    while(Head!=NULL){
        printf("%d->",Head->data);
        Head=Head->next;
    }
    printf("NULL\n");
    }
    int main(){
        struct Node* Head=NULL;
        Head=insertAtLast(Head,10);
        printList(Head);
    }
  
 
