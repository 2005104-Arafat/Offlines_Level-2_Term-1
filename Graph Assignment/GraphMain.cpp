#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
#include "Graph.cpp";
using namespace std;
int main(){
    ifstream myInput;
    ofstream myOutput;
    myOutput.open("graph_output.txt");
    myInput.open("graph_input.txt");
    if(!myInput){
        cout<<"File not valid"<<endl;
    }
    string line;
    getline(myInput,line);
    istringstream s(line);
    int n,m;
    s>>n;
    s>>m;
    int a1[m+1],item[m+1];
    for(int i=0;i<m;i++){
        getline(myInput,line);
        istringstream s3(line);
        s3>>a1[i];
        s3>>item[i];
    }
    getline(myInput,line);
    istringstream s2(line);
    int s1;
    s2>>s1;
    Graph newGraph(n,m,s1);
    for(int i=0;i<m;i++){
        newGraph.graphInsert(a1[i],item[i]);
    }
    for(int i=0;i<m;i++){
        cout<<a1[i]<<" "<<item[i]<<endl;
    }
    newGraph.BFS(myOutput);
    newGraph.DFS(myOutput);
}