#include<iostream>
#include<cmath>
#include<cstring>
#include <fstream>
#include<sstream>
#include<cstring>
#include "heap.cpp";
using namespace std;
int main(){
    ifstream myInput;
    ofstream myOutput;
    myOutput.open("heap_output.txt");
    myInput.open("heap_input.txt");
    if(!myInput){

        cout<<"File not valid"<<endl;
    }
    string options[100];
    int item1[100];
    int item2[100];
    string line;
    Heap newHeap;
    int count=0;
    while(getline(myInput,line)){
        istringstream s(line);
        s>>options[count];
        if(options[count]=="INS"){
            s>>item1[count];
            item2[count]=0;
        }
        else if(options[count]=="DEC"){
           s>>item1[count];
           s>>item2[count]; 
        }else{
            item1[count]=0;
            item2[count]=0;
        }
        count++;
    }
    for(int j=0;j<count;j++){
       //cout<<options[j]<<endl;
       if(options[j]=="INS"){
            newHeap.Insert(item1[j]);
            myOutput<<"INSERTED "<<item1[j]<<endl;
       }
       else if(options[j]=="EXT"){
            int v=newHeap.ExtractMin();
            myOutput<<"ExtractMin returned "<<v<<endl;
       } 
       else if(options[j]=="DEC"){
            newHeap.DecreaseKey(item1[j],item2[j]);
            myOutput<<item1[j]<<" decreased to "<<item2[j]<<endl;
       }
       else if(options[j]=="FIN"){
            int x=newHeap.FindMin();
            myOutput<<"FindMin returned "<<x<<endl;
       }
       else if(options[j]=="PRI"){
            string str=newHeap.Print();
            myOutput<<str<<endl;
       }
       else{
            cout<<"No such output found"<<endl;
       }
    }
    newHeap.buildHeap();
    myOutput<<"Max Heap:"<<endl; 
    myOutput<<newHeap.Print()<<endl;
    newHeap.sort();
    myOutput<<"After sorting : "<<endl;
    myOutput<<newHeap.Print()<<endl;
    myOutput<<"Sorted Array : "<<endl;
    for(int i=0;i<newHeap.length;i++){
        myOutput<<newHeap.array[i]<<" ";
    }     
}