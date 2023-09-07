#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
using namespace std;
#include "QueueArray.cpp";
#include "stackArray.cpp";

class Customer{
    public:
    int enterTime;
    int duration;
    int leaveTime;
    int key;
};
int main (){
    ifstream myInput;
    ofstream myOutput;
    myOutput.open("gameOutput.txt");
    myInput.open("gameInput.txt");
    if(!myInput){
        cout<<"File not valid"<<endl;
    }
    string line;
    getline(myInput,line);
    istringstream s(line);
    int number,totalTime;
    s>>number;
    s>>totalTime;
    Customer customer[number];
    for(int i=0;i<number;i++){
        getline(myInput,line);
        istringstream s3(line);
        s3>>customer[i].enterTime;
        s3>>customer[i].duration;
        customer[i].key=i+1;
    }
    int timeStamp1=0,timeStamp2=0;
    int capacity1=3;
    queue<Customer> counter1(capacity1);
    stack<Customer> counter2;
    for(int i=0;i<number;i++){
        if(counter1.length()==0){
            if(customer[i].enterTime>timeStamp1){
                timeStamp1=customer[i].enterTime+customer[i].duration;
                if(timeStamp1>totalTime){
                    timeStamp1=totalTime;
                }
                customer[i].leaveTime=timeStamp1;
            }
            else{
                counter1.enqueue(customer[i]);
            }
        }
        else if(customer[i].enterTime<=timeStamp1 && counter1.length()<3 && counter1.length()!=0){
            counter1.enqueue(customer[i]);
        }
        else if(customer[i].enterTime>timeStamp1 && counter1.length()<=3 && counter1.length()!=0){
            Customer temp=counter1.dequeue();
            timeStamp1+=temp.duration;
            if(timeStamp1>totalTime){
                timeStamp1=totalTime;
            }
            customer[temp.key-1].leaveTime=timeStamp1;
            counter1.enqueue(customer[i]);
        }
        else if(counter1.length()==3 && counter2.length()==0 && customer[i].enterTime<=timeStamp1){

            if(customer[i].enterTime>timeStamp2){
                timeStamp2=customer[i].enterTime+customer[i].duration;
                if(timeStamp2>totalTime){
                    timeStamp2=totalTime;
                }
                customer[i].leaveTime=timeStamp2;
            }
            else{
                counter2.push(customer[i]);
            }
        }
        else if(counter1.length()==3 && counter2.length()!=0 && customer[i].enterTime<=timeStamp2){
            counter2.push(customer[i]);
        }
        else if(counter1.length()==3 && counter2.length()!=0 && customer[i].enterTime>timeStamp2){
            Customer temp1=counter2.pop();
            timeStamp2+=temp1.duration;
            if(timeStamp2>totalTime){
                timeStamp2=totalTime;
            }
            customer[temp1.key-1].leaveTime=timeStamp2;
            counter2.push(customer[i]);
        }

    }
    while(counter1.length()>0){
    Customer temp3=counter1.dequeue();
        timeStamp1+=temp3.duration;
        if(timeStamp1>totalTime){
            timeStamp1=totalTime;
        }
        customer[temp3.key-1].leaveTime=timeStamp1;
    }
    while(counter2.length()>0){
    Customer temp4=counter2.pop();
        timeStamp2+=temp4.duration;
        if(timeStamp2>totalTime){
            timeStamp2=totalTime;
        }
        customer[temp4.key-1].leaveTime=timeStamp2;
    }

    for(int i=0;i<number;i++){
        myOutput<<customer[i].key<<">"<<customer[i].leaveTime<<endl;
    }
}

