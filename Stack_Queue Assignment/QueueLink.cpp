#include<iostream>
using namespace std;
template<class T>
class Node{
    public:
    T data;
    Node* next;
    Node(T val=0){
        data=val;
        next=NULL;
    }
};
template<class K>
class queue{
    public:
    int capacity;
    Node<K>* head;
    Node<K>* front;
    Node<K>* rear;
    queue(int x=200){
        capacity=x;
        // head=new Node<K>;
        // front=new Node<K>;
        // rear=new Node<K>;
        head=NULL;
        front=NULL;
        rear=NULL;
    }
    void clear(){
        head=NULL;
        front=NULL;
        rear=NULL;
    }
    void enqueue(K item){
        Node<K>* newNode=new Node<K>(item);
        Node<K>* temp;
        if(head==NULL){
            head=newNode;
            temp=head;
            front=rear=head;
        }
        else{
            temp->next=newNode;
            temp=newNode;
            rear=newNode;
        }
    }
    K dequeue(){
        if(front==NULL){

        }
        else{
            Node<K>* toDelete=head;
            K data= toDelete->data;
            head=head->next;
            front=head;
            delete toDelete;
            return data;
        }
    }
    int length(){
        Node<K>* temp=head;
        int l=0;
        while(temp!=NULL){
            temp=temp->next;
            l++;
        }
        return l;
    }
    K frontValue(){
        return front->data;
    }
    K rearValue(){
        return rear->data;
    }
    K leaveQueue(){
        Node<K> *temp,*prev;
        temp= head;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        Node<K> *toDelete=temp;
        prev->next=NULL;
        rear=prev;
        delete toDelete;
    }
    void display(ofstream &output){
        Node<K>* temp=head;
        output<<"<| ";
        while(temp!=NULL){
            output<<temp->data<<" ";
            temp=temp->next;
        }
        output<<">"<<endl;
    }
};
