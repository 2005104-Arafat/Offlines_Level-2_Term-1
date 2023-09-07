#include<bits/stdc++.h>
using namespace std;
template<typename T>
struct node{
    T data;
    struct node *next;
};
template<typename T>
class MyList{
    public:
    struct node<T> *mylist,*head;
    int currentSize;
    int maxSize;
    int currentPosition;
    Mylist(){
        head=NULL;
        currentSize=0;
        currentPosition=0;
    }
    ~MyList(){

    }
    int size(){
        return currentSize;
    }
    void push(T item){
        struct node<T> *temp2;
        int i=0;
        temp2=head;
        while(i<currentPosition){
            temp2=temp2->next;
            i++;
        }
        mylist=new struct node<T>;
        mylist->next=temp2->next;
        temp2->next=mylist;
        mylist->data=item;
        currentSize++;
    }
    void pushBack(T item){
        mylist=new struct node<T>;
        mylist->data=item;
        mylist->next=NULL;
        struct node<T> *temp1;
        if(head==NULL)
        {
            temp1=head=mylist;   
        }
        else
        {
           temp1->next=mylist;
            temp1=mylist;
        }
        currentSize++;
    }
    T erase(){
        T currentElement;
        struct node<T> *temp,*prev;
        temp=head;
        for(int i= 0;i<currentPosition;i++){
            prev=temp;
           temp=temp->next;
        }
        prev->next=temp->next;
        currentElement=temp->data;
        delete temp;
        currentSize--;
        return currentElement;
    }
    void setToBegin(){
        currentPosition=0;
    }
    void setToEnd(){
        currentPosition=currentSize-1;
    }
    void prev(){
        if(currentPosition!=0){
            currentPosition--;
        }
    }
    void next(){
       if(currentPosition!=(currentSize-1)){
            currentPosition++;
        } 
    }
    int currPos(){
        return currentPosition;
    }
    void setToPos(int pos){
        if(pos>currentSize){
            currentPosition=currentPosition;
        }else{
            currentPosition=pos;
        }
        

    }
    T getValue(){
        struct node<T> *temp4,*prev;
        temp4=head;
        for(int i= 0;i<currentPosition;i++){
           prev=temp4;
           temp4=temp4->next;
        }
        cout<<prev->data;
        return prev->data;
    }
    int find(T item){
        struct node<T> *temp3;
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
    void clear(){
        delete mylist;
        currentSize=0;
    }
};
