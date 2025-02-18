//Insert at begining 
//Insert at position 
//Insert at end
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head = NULL;
void InsertAtBegining(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
void InsertAtEnd(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL)
    {
        head = newNode;
    }
    Node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void InsertAtPosition(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void print(){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data;
        temp= temp->next;
    }
}
int main(){

}
