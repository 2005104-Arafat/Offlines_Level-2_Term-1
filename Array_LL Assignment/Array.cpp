#include<bits/stdc++.h>
using namespace std;
template<typename T>
class MyList {
    private:
    T* mylist;
    int currentSize;
    int maxSize;
    int currentPosition;

    public:
    MyList(int X = 6){
        mylist= new T[X];
        maxSize=X;
        currentSize=0;
        currentPosition=0;
    }
    MyList(int X, int K, T* list ){
        maxSize=X;
        mylist=new T[maxSize];
        currentPosition=0;
        currentSize=K;
        mylist=list;
    }
    // ~MyList(){
    //     delete mylist;
    // }
    int size(){
        return currentSize;
    }
    void push(T item){
        if(currentSize==maxSize){
            maxSize*=2;
            T *tempList=new T[maxSize];
            for(int i=0;i<currentSize;i++)
            {
                tempList[i]=mylist[i];
            }
            mylist=tempList;
        }
        for(int i= currentSize-1; i>=currentPosition;i--){
            mylist[i+1]=mylist[i];
        }
        mylist[currentPosition]=item;
        currentSize++;
    }
    void pushBack(T item){
        if(currentSize==maxSize){
            maxSize*=2;
            T *tempList=new T[maxSize];
            for(int i=0;i<currentSize;i++)
            {
                tempList[i]=mylist[i];
            }
            mylist=tempList;
        }
        mylist[currentSize++]=item;

    }
    T erase(){
        T currentElement;
        currentElement=mylist[currentPosition];
        for(int i= currentPosition;i<currentSize;i++){
            mylist[i]=mylist[i+1];
        }
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
        currentPosition=pos;
    }
    T getValue(){
        return mylist[currentPosition];
    }
    int find(T item){
        for(int i=0;i<currentSize;i++){
            if(mylist[i]==item) return i;
        }
        return -1;
    }
    void clear(){
        delete mylist;
        currentSize=0;
    }
};
// int main()
// {
//     int k=4;
//     MyList<int> l;
//     for(int i=0;i<k;i++)
//     {
//         l.pushBack(i+1);
//     }
//     cout<<l.find(3);
// }