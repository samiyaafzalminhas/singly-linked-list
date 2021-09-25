#include<iostream>
#include<conio.h>
using namespace std;

struct node{
    int data;             ////structure banaya
    node *next;
};
struct node *head = NULL, *temp = NULL;        

void insertAtEnd(int value){
    node *newNode = new node;      
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL){
        head = temp = newNode;
    }else {
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        temp = newNode;
    }
}

void insertAtBeg(int value){
    node *newNode = new node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtPosition(int value, int position){
    int i=1;    
    node *newNode = new node;
    node *temp = head;

    while(i < position){   // traverse kia list ko 
        temp = temp->next;
        i++;
    }
    newNode->data = value; 

    newNode->next = temp->next;
    temp->next = newNode;


}

void display(){
    node *temp;
    temp = head;
    if(temp == NULL){
        cout << "\n\nList is Empty...!";
    }else {
        cout << "\n\nLinked List : \n";
        while(temp != NULL){
            cout << '\t' << temp->data << '\n' ;
            temp = temp->next;
        }
    }
}

void deleteNodeFromBeg(){
    if(head == NULL){
        cout << "\n\n\tList is Empty....!";
    }else {
        node *temp = head;
        head = head->next;
        cout << "\n\n\t" << temp->data << " has been removed\n\n";
        free(temp);
    }
}

void deleteNodeAtEnd(){
    node *prevNode = new node;
    temp = head;

    while(temp->next != NULL){
        prevNode = temp;
        temp = temp->next;
    }

    if(temp == head){
        head = NULL;
    }else {
        prevNode->next = NULL;
    }
    cout << "\n\n\t" << temp->data << " has been removed\n\n";
    free(temp);
}

void deleteFromPos(int pos){
    int i=1;
    node *nextNode = new node;
    temp = head;

    while( i < (pos-1) ){
        temp = temp->next;
        i++;
    }
    nextNode = temp->next;
    temp->next = nextNode->next;
    cout << "\n\n\t" << nextNode->data << " has been removed\n\n";
    free(nextNode);
}

void getLength(){
    int count = 0;
    node *temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    cout << "\n\n\tLength of Linked List : " <<  count << "\n\n" ;
}

int main(){

    int choice, num, pos;
    A:
    cout << "\n\n\t1) >> Insert At End";
    cout << "\n\t2) >> Insert At Beginning";
    cout << "\n\t3) >> Insert At Postion";
    cout << "\n\t4) >> Display";
    cout << "\n\t5) >> Delete From Begining";
    cout << "\n\t6) >> Delete At the End";
    cout << "\n\t7) >> Delete From any given Position";
    cout << "\n\t8) >> Length of linked List";
    cout << "\n\t9) >> Exit";

    cout << "\n\nEnter your choice : ";
    cin >> choice;

    switch(choice){
    case 1:
        cout << "\nEnter the Node : ";
        cin >> num;
        insertAtEnd(num);
        system("pause");
        system("cls");
        goto A;
        break;
    case 2:
        cout << "\nEnter the Node : ";
        cin >> num;
        insertAtBeg(num);
        system("pause");
        system("cls");
        goto A;
        break;
    case 3:
        cout << "\nEnter the Node : ";
        cin >> num;
        cout << "\nEnter the position : ";
        cin >> pos;
        insertAtPosition(num, pos);
        system("pause");
        system("cls");
        goto A;
        break;
    case 4:
        display();
        system("pause");
        system("cls");
        goto A;
        break;
    case 5:
        deleteNodeFromBeg();
        system("pause");
        system("cls");
        goto A;
        break;
    case 6:
        deleteNodeAtEnd();
        system("pause");
        system("cls");
        goto A;
        break;
    case 7:
        cout << "\nEnter the position : ";
        cin >> pos;
        deleteFromPos(pos);
        system("pause");
        system("cls");
        goto A;
        break;
    case 8:
        getLength();
        system("pause");
        system("cls");
        goto A;
    case 9:
        exit(0);
    default:
        cout << "\n\n\tChoose the Correct Option...!";
    }
    getch();
    return(0);
}
