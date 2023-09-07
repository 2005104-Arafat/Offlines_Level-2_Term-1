#include <iostream>
#include <fstream>
#include<sstream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
bool sortDeparture(const vector<int> &v1,const vector<int> &v2){
    return v1[1]<v2[1];
}
int main(){
    ifstream myInput;
    ofstream myOutput;
    myOutput.open("greedy_output.txt");
    myInput.open("greedy_input.txt");
    if(!myInput){
        cout<<"File not valid"<<endl;
    }
    string line;
    getline(myInput,line);
    istringstream s(line);
    int length;
    s>>length;
    //cout<<length<<endl;
    vector<vector<int>> customer(length,vector<int>(2));
    int arrival[length],departure[length];
    for(int i=0;i<length;i++){
        getline(myInput,line);
        istringstream s3(line);
        s3>>customer[i][0];
        s3>>customer[i][1];
    }
    sort(customer.begin(),customer.end(),sortDeparture);
    // for(int i=0;i<length;i++){
    //     for(int j=0;j<2;j++){
    //         cout<<customer[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    arrival[0]=customer[0][0];
    departure[0]=customer[0][1];
    int count=1;
    int prevDeparture=customer[0][1];
    for(int i=1;i<length;i++){
        if(customer[i][0]<prevDeparture){
            continue;
        }else{
            prevDeparture=customer[i][1];
            arrival[count]=customer[i][0];
            departure[count]=customer[i][1];
            count++;
        }
    }
    myOutput<<count<<endl;
    for(int i=0;i<count;i++){
        myOutput<<arrival[i]<<" ";
        myOutput<<departure[i]<<endl;
    }
}