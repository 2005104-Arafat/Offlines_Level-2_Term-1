#include <iostream>
#include <fstream>
#include<sstream>
#include<cstring>
#include<string>
#include "binarySearch.cpp"
using namespace std;
int main(){
    ifstream myInput;
    ofstream myOutput;
    myOutput.open("output.txt");
    myInput.open("input.txt");
    if(!myInput){

        cout<<"File not valid"<<endl;
    }
    char options[50];
    string item[50];
    string line;
    int i=0;
    while(getline(myInput,line)){
        //getline(myInput,line);
        istringstream s(line);
        s>>options[i];
        s>>item[i];
        i++;
    }
    int count=0;
    int countTrue=0;
    // for(int j=0;j<i;j++){
    //     cout<<options[j]<<" "<<item[j]<<endl;
    // }
    Node *root=NULL;
    for(int j=0;j<i;j++){
        switch(options[j]){
            case 'I':{
                int num1=stoi(item[j]);
                root=Insert(root,num1);
                string str1;
                print(root, str1);
                cout<<str1<<endl;
                break;
            }
            case 'D':{
                int num2=stoi(item[j]);
                if(Find(root,num2)){
                    root=Delete(root,num2);
                    if(Find(root,num2)){
                        myOutput<<"Invalid Operation"<<endl;
                    }else{
                        string str1 = "";
                        print(root, str1);
                        myOutput<<str1<<endl;
                    }
                }
                else{
                    myOutput<<"Invalid Operation"<<endl;
                }
                break;
            }
            case 'F':{
                int num3=stoi(item[j]);
                if(Find(root,num3)){
                    myOutput<<"True"<<endl;
                    countTrue++;
                }else{
                    myOutput<<"False"<<endl;
                    count++;
                }
                break;
            }
            case 'T':{
                if(!(item[j].compare("In"))){
                    InOrder(root,myOutput);
                    cout<<endl;
                }
                else if(!(item[j].compare("Pre"))){
                    PreOrder(root,myOutput);
                    myOutput<<endl;
                }
                else{
                    PostOrder(root,myOutput);
                    myOutput<<endl;
                }
                break;

            }
        }
    }
   
}