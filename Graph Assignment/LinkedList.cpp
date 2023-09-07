#include <iostream>
#include <fstream>
#include<sstream>
using namespace std;
template<typename T>
class node{
    public:
    T data;
    node*next;
    node(T val){
        data=val;
        next=NULL;  
    }
};
template<typename T>
class MyList{
    public:
    node<T> *head=NULL;
    int currentSize=0;
    int maxSize;
    int currentPosition=0;
    // public Mylist(){
    //     head=NULL;
    //     currentSize=0;
    //     currentPosition=0;
    // }
    int size(){
        return currentSize;
    }
    void push(T item){
        if(currentPosition==0){
            node<T> *mylist= new node<T>(item);
            mylist->next=head;
            head=mylist;
        }else{
            node<T> *temp2,*prev;
            int i=0;
            temp2=head;
            while(i<currentPosition){
                prev=temp2;
                temp2=temp2->next;
                i++;
            }
            node<T> *mylist=new node<T>(item);
            mylist->next=temp2;
            prev->next=mylist;
        }
        currentSize++;
    }
    void pushBack(T item){
        node<T>* mylist=new node<T>(item);
        node<T> *temp=head;
        if(head==NULL)
        {
            head=mylist; 
            temp=head;  
        }
        else
        {
           while(temp->next!=NULL){
                temp=temp->next;
           }
           temp->next=mylist ;
           temp=mylist;
        }
        //cout<<"A"<<endl;
        currentSize++;
    }
    T erase(){
        T currentElement;
        node<T> *temp;
        if(currentPosition==0){
            temp=head;
            currentElement=temp->data;
            head=head->next;
            delete temp;
        }else{
            node<T> *prev;
            temp=head;
            for(int i= 0;i<currentPosition;i++){
                prev=temp;
                temp=temp->next;
            }
            prev->next=temp->next;
            currentElement=temp->data;
            delete temp;
        }
        currentSize--;
        if(currentPosition==currentSize){
            currentPosition=currentSize-1;
        }
        return currentElement;
    }
    void setToBegin(){
        currentPosition=0;
    }
    void setToEnd(){
        currentPosition=currentSize-1;
    }
    void prev(){
        if(currentPosition!=0 && currentSize!=0){
            currentPosition--;
        }
    }
    void next(){
       if(currentPosition!=(currentSize-1) && currentSize!=0){
            currentPosition++;
        } 
    }
    int currPos(){
        return currentPosition;
    }
    void setToPos(int pos){
        if(pos>=currentSize){
            currentPosition=currentPosition;
        }else{
            currentPosition=pos;
        }
    }
    T getValue(){
         node<T> *temp4;
        if(currentSize==0){
            return NULL;
        }
        else if(currentPosition==0){
            temp4=head;
            return temp4->data;
        }
        else{
            node<T> *prev;
            temp4=head;
            for(int i= 0;i<currentPosition;i++){
                prev=temp4;
                temp4=temp4->next;
            }
            return temp4->data;
        }
    }
    int find(T item){
        node<T> *temp3;
        int i=0;
        temp3=head;
        while(temp3!=NULL){
            if(temp3->data==item){
                return i;
            }
            temp3=temp3->next;
            i++;
        }
        return -1;
    }
    int length(){
        return currentSize;
    }
    void clear(){
        head=NULL;
        currentSize=0;
        currentPosition=0;
    }
    void display(ofstream &output){
        node<T> *temp=head;
        while(temp!=NULL){
            output<<temp->data<<" ";
            temp=temp->next;
        }
        output<<endl;
    }
};

// int main(){
//     MyList<int> list;
//     cout<<list.currentSize<<endl;
//     list.pushBack(5);
//     cout<<list.currentSize<<endl;
//     list.pushBack(4);
//     list.pushBack(3);
//     list.pushBack(2);
//     cout<<list.currentSize<<endl;
//     list.pushBack(1);
//     list.pushBack(6);
//     list.pushBack(7);
//     cout<<list.currentSize<<endl;
//     list.display();
//     list.setToEnd();
//     list.push(76);
//     list.push(86);
//     list.push(76);
//     list.setToBegin();
//     list.push(36);
//     list.push(55);
//     list.next();
//     list.push(29);
//     list.push(33);
//     cout<<list.currentSize<<endl;    
//     list.display();
//     // cout<<list.currPos()<<endl;
//     // cout<<list.getValue()<<endl;
//     // cout<<list.find(3)<<endl;
//     // cout<<list.find(36)<<endl;
//     // cout<<list.find(33)<<endl;
//     // cout<<list.find(55)<<endl;
//     // cout<<list.find(25)<<endl;
//     cout<<list.erase()<<endl;
//     list.display();
//     cout<<list.erase()<<endl;
//     list.display();
//     cout<<list.erase()<<endl;
//     list.display();
//     cout<<list.erase()<<endl;
//     list.display();
//     cout<<list.erase()<<endl;
//     list.display();
//     //list.clear();
//     list.display();
//     cout<<list.getValue()<<endl;
//     list.next();
//     cout<<list.getValue()<<endl;
//     list.next();
//     cout<<list.getValue()<<endl;
// }
