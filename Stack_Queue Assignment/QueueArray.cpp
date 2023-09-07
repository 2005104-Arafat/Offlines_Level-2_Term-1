#include<iostream>
using namespace std;
template<typename T>
class queue{
    public:
    int capacity;
    int front;
    int rear;
    T* array;
    queue(int x=200){
        capacity=x;
        array=new T[capacity];
        front=-1;
        rear=-1;
    }
    void clear(){
        for(int i=front;i<length();i++){
            dequeue();
        }

        front=-1;
        rear=-1;
    }
    void enqueue(T item){
        if(rear==capacity-1){
            T* temp;
            int i;
            for(i=0;i<length();i++){
                temp[i]=array[i];
            }
            array=new T[2*capacity];
            for(int j=0;j<i;j++){
                array[j]=temp[j];
            }
        }
        if(front==-1){
            front++;
        }
        rear++;
        array[rear]=item;
    }
    T dequeue(){
        if(front==-1 ){
            //return -1;
        }
        else{
            T currentElement;
            currentElement=array[front];
            for(int i=front;i<=rear;i++){
                array[i]=array[i+1];
            }
            rear--;
            return currentElement;
        }
    }
    int length(){
        int i=rear+1;
        return i;
    }
    T frontValue(){
        return array[front];
    }
    T rearValue(){
        return array[rear];
    }
    T leaveQueue(){
        T value=rearValue();
        rear--;
        return value;
    }
    void display(ofstream &output){
        output<<"<| ";
        int i=front;
        while(i<length()&& i>=0){
            output<<array[i]<<" ";
            i++;
        }
        output<<">"<<endl;
    }
};
// int main(){
//     queue<int> queue1(100);
//     queue1.enqueue(3);
//     queue1.enqueue(7);
//     queue1.enqueue(11);
//     queue1.enqueue(9);
//     queue1.enqueue(1);
//     queue1.enqueue(4);
//     queue1.display();
//     cout<<queue1.length()<<endl;
//     queue1.clear();
//     queue1.display();
//     queue1.dequeue();
//     queue1.display();
//     cout<<queue1.length()<<endl;
//     queue1.dequeue();
//     queue1.display();
//     cout<<queue1.length()<<endl;
//     queue1.dequeue();
//     queue1.display();
//     cout<<queue1.length()<<endl;
//     // queue1.leaveQueue();
//     // queue1.leaveQueue();
//     // cout<<queue1.length()<<endl;
//     // queue1.leaveQueue();
//     // cout<<queue1.length()<<endl;
//     // queue1.display();
//     // queue1.clear();
// }
