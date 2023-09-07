#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
#include "QueueArray.cpp";
#include "stackArray.cpp";
//#include "QueueLink.cpp";
//#include "stackLink.cpp";
using namespace std;
int main(){
    ifstream myInput;
    ofstream myOutput;
    myOutput.open("output.txt");
    myInput.open("input.txt");
    if(!myInput){

        cout<<"File not valid"<<endl;
    }
    string line;
    getline(myInput,line);
    istringstream s(line);
    int K,X;
    s>>K;
    s>>X;
    //cout<<K<<" "<<X<<endl;
    queue<int> QueueList(X);
    getline(myInput,line);
    istringstream s2(line);
    int array1[K];
    for(int i=0;i<K;i++){
        s2>>array1[i];
    }
    for(int i=0;i<K;i++){
        QueueList.enqueue(array1[i]);
    }
    getline(myInput,line);
    istringstream s1(line);
    int M,Y;
    s1>>M;
    s1>>Y;
    //cout<<M<<" "<<Y<<endl;
    stack<int> StackList(Y);
    getline(myInput,line);
    istringstream s3(line);
    int array2[M];
    for(int i=0;i<M;i++){
        s3>>array2[i];
    }
    for(int i=0;i<M;i++){
        StackList.push(array2[i]);
    }
    getline(myInput,line);
    istringstream s4(line);
    int choice;
    s4>>choice;
    int options[choice];
    int item[choice];
    for(int i=0;i<choice;i++){
        getline(myInput,line);
        istringstream s5(line);
        s5>>options[i];
        s5>>item[i];
    }
    for(int i=0;i<choice;i++){
        switch (options[i])
        {
        case 1:{
            QueueList.clear();
            QueueList.display(myOutput);
            myOutput<<"-1"<<endl;
            break;
        }
        case 2:{
            QueueList.enqueue(item[i]);
            QueueList.display(myOutput);
            myOutput<<"-1"<<endl;
            break;
        }
        case 3:{
            int l=QueueList.dequeue();
            QueueList.display(myOutput);
            myOutput<<l<<endl;
            break;
        }
        case 4:{
            int x=QueueList.length();
            QueueList.display(myOutput);
            myOutput<<x<<endl;
            break;
        }
        case 5:{
            int y=QueueList.frontValue();
            QueueList.display(myOutput);
            myOutput<<y<<endl;
            break;
        }
        case 6:{
            int z=QueueList.rearValue();
            QueueList.display(myOutput);
            myOutput<<z<<endl;
            break;
        }
        case 7:{
            int u=QueueList.leaveQueue();
            QueueList.display(myOutput);
            myOutput<<u<<endl;
            break;
        }
        case 8:{
            StackList.clear();
            StackList.display(myOutput);
            myOutput<<"-1"<<endl;
            break;
        }
        case 9:{
            StackList.push(item[i]);
            StackList.display(myOutput);
            myOutput<<"-1"<<endl;
            break;
        }
        case 10:{
            int v=StackList.pop();
            StackList.display(myOutput);
            myOutput<<v<<endl;
            break;
        }
        case 11:{
            int w=StackList.length();
            StackList.display(myOutput);
            myOutput<<w<<endl;
            break;
        }
        case 12:{
            int g=StackList.topValue();
            StackList.display(myOutput);
            myOutput<<g<<endl;
            break;
        }
        default:
            break;
        }
    }


}
