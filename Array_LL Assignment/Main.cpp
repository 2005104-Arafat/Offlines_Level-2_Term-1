#include <iostream>
#include <fstream>
#include<sstream>
#include<cstring>
//#include "Array.cpp";
#include "LinkedList.cpp";

using namespace std;
void print(MyList<int> l,ofstream &output){
    cout<<"<";
    
    int temp=l.currPos();
    l.setToBegin();
    for(int i=0;i<l.size();i++){
        
        if(i==temp){
            cout<<"| ";
        }
        cout<<"A";
        cout <<l.getValue()<<" ";
        
        l.next();
    }
    cout<<">"<<endl;
    l.setToPos(temp);
}
int main(){
    ifstream myInput;
    ofstream myOutput;
    myOutput.open("list_output.txt");
    myInput.open("list_input.txt");
    if(!myInput){

        cout<<"File not valid"<<endl;
    }
    string line;
    getline(myInput,line);
    istringstream s(line);
    int K,X;
    s>>K;
    s>>X;
    cout<<K<<" "<<X<<endl;
    getline(myInput,line);
    
    istringstream s1(line);
    int m,i=0;
    int a[K];
    while(s1>>m)
    {
        a[i]=m;
        i++;
    }
    
    //MyList<int> l(X);
    MyList<int> l;
    l.setToBegin();
    for(int i=0;i<K;i++){
        l.pushBack(a[i]);
    }
    for(int i=0;i<K;i++){
        cout<<a[i]<<" ";
    }
    print(l,myOutput);
    cout<<endl;
    getline(myInput,line);
    istringstream s2(line);
    int choice;
    s2>>choice;
    cout<<choice<<endl;
    int a1[choice],item[choice];
    for(int i=0;i<choice;i++){
        getline(myInput,line);
        istringstream s3(line);
        s3>>a1[i];
        s3>>item[i];
    }
    for(int i=0;i<choice;i++){
        
        cout<<a1[i]<<" "<<item[i]<<endl;
    }
    for(int i=0;i<choice;i++)
    {
        switch(a1[i]){
            case 1:{
                int size=l.size();
                print(l, myOutput);
                cout<<size<<endl;
                break;}
            case 2:{
                l.push(item[i]);
                print(l, myOutput);
                cout<<"-1"<<endl;
                break;}
            case 3:{
                l.pushBack(item[i]);
                print(l, myOutput);
                cout<<"-1"<<endl;
                break;}
            case 4:{
                int returned=l.erase();
                print(l, myOutput);
                cout<<returned<<endl;
                break;}
            case 5:{
                l.setToBegin();
                print(l, myOutput);
                cout<<"-1"<<endl;
                break;}
            case 6 :{
                l.setToEnd();
                print(l, myOutput);
                cout<<"-1"<<endl;
                break;}
            case 7:{
                l.prev();
                print(l, myOutput);
                cout<<"-1"<<endl;
                break;}
            case 8:{
                l.next();
                print(l, myOutput);
                cout<<"-1"<<endl;
                break;}
            case 9:{
                int position=l.currPos();
                print(l, myOutput);
                cout<<position<<endl;
                break;}
            case 10:{
                l.setToPos(item[i]);
                print(l, myOutput);
                cout<<"-1"<<endl;
                break;}
            case 11:{
                int value=l.getValue();
                print(l, myOutput);
                cout<<"-1"<<endl;
                break;}
            case 12:{
                int find=l.find(item[i]);
                print(l, myOutput);
                cout<<find<<endl;
                break;}
            case 13:{
                l.clear();
                break;}
            default:
                cout<<"Enter a valid option";
                break;
        }
    }
}