#include<iostream>
using namespace std;
template<typename T>
class stack{
    public:
    int capacity;
    int top;
    T *array;
    stack(int capacity=200){
        this->capacity=capacity;
        array=new T[capacity];
        top=-1;
    }
    void clear(){
        int l=top;
        for(int i=0;i<=l;i++){
            pop();
        }
    }
    void push(T x){
        if(top==capacity-1){
            cout<<"wrong"<<endl;
            return;
        }
        top++;
        array[top]=x;
    }
    T pop(){
        if(top==-1){
            cout<<"Wrong"<<endl;
            //return -1;

        }
        else
        {
            T temp=array[top];
            top--;
            return temp;
        }
    }
    int length(){
        return (top+1);
    }
    T topValue(){
        if(top==-1){
            cout<<"No elements"<<endl;
            return -1;
        }
        return array[top];
    }
    void display(ofstream &output){
        output<<"< ";
        int i=0;
        while(i<length()){
            if(i==(length()-1)){
                output<<"| ";
            }
            output<<array[i]<<" ";
            i++;
        }
        output<<">"<<endl;
    }

};

