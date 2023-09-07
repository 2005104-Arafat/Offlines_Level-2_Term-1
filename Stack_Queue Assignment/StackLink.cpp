#include<iostream>
using namespace std;
template<typename T>
class Node1{
    public:
    T data;
    Node1* next;
    Node1(T val){
        data=val;
        next=NULL;
    }
};
template<typename T>
class stack{
    public:
    int capacity;
    Node1<T>* top;
    Node1<T>* head;
    stack(int capacity=200){
        capacity=capacity;
        head=NULL;
        top=head;
    }
    void clear(){
        head=top=NULL;
    }
    void push(T x){
        Node1<T>* newNode=new Node1<T>(x);
        if(head==NULL){
            head=newNode;
            top=head;
        }
        else{
            top->next=newNode;
            top=newNode;
        }
    }
    T pop(){
        if(head==NULL){
            
        }
        else if(head->next==NULL){
            Node1<T>* toDelete=head;
            head=NULL;
            top=NULL;
            T temp1=toDelete->data;
            delete toDelete;
            return temp1;
        }else{
            Node1<T> *temp,*prev;
            temp= head;
            while(temp->next!=NULL){
                prev=temp;
                temp=temp->next; 
            }
            Node1<T> *toDelete=temp;
            prev->next=NULL;
            T temp2=toDelete->data;
            top=prev;
            delete toDelete;
            return temp2;
        }
    }
    int length(){
        Node1<T>* temp=head;
        int l=0;
        while(temp!=NULL){
            temp=temp->next;
            l++;
        }
        return l;
    }
    T topValue(){
        if(top==NULL){
            
        }
        return top->data;
    }
    void display(ofstream &output){
        Node1<T>* temp=head;
        output<<"< ";
        while(temp!=NULL){
            if(temp->next==NULL){
                output<<"| ";
            }
            output<<temp->data<<" ";
            temp=temp->next;
        }
        output<<">"<<endl;
    }
};
