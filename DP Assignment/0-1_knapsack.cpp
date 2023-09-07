#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<cstring>
using namespace std;
class Dynamic{
    public:
    int i;
    int max_weight,item_number;
    int *weight;
    int *value;
    int **table;
    Dynamic(int n,int w){
        max_weight=w;
        item_number=n;
        value=new int[n+1];
        weight=new int[n+1];
        table = new int*[n+1];
        weight[0]=0;
        value[0]=0;
        for (int i = 0; i < n+1; ++i) {
          table[i] = new int[w+1];
        }
        i=1;
        for(int j=0;j<n+1;j++){
            for(int k=0;k<w+1;k++){
                table[j][k]=0;
            }
        }
    }
    int max(int a, int b) { 
        return (a > b) ? a : b; 
    }
    void Insert(int w,int v){
        weight[i]=w;
        value[i++]=v;
    }
    int Knapsack(int n,int w){
        if(w==0){
            return 0;
        }
        if(n==0){
            return 0;
        }
        if(table[n][w]!=0){
            return table[n][w];
        }
        if(weight[n-1]>w){
            table[n][w]=Knapsack(n-1,w);
        }else{
            table[n][w]=max(Knapsack(n-1,w),Knapsack(n-1,w-weight[n])+value[n]);
        }
        return table[n][w];
    }
    void print(ofstream &output){
        int w=max_weight;
        int n=item_number;
        int optimum=Knapsack(item_number,max_weight);
        for(i=item_number;i>0&& optimum>0;i--){
            if(optimum==table[i-1][w]){
                continue;
            }else{
                output<<weight[i]<<" ";
                optimum=optimum-value[i];
                w=w-weight[i];
            }
        }
        output<<endl;
    }
};
int main(){
    ifstream myInput;
    ofstream myOutput;
    myOutput.open("dp_output.txt");
    myInput.open("dp_input.txt");
    if(!myInput){
        cout<<"File not valid"<<endl;
    }
    string line;
    getline(myInput,line);
    istringstream s(line);
    int item_number;
    s>>item_number;
    int weight[item_number];
    int value[item_number];
    for(int i=0;i<item_number;i++){
        getline(myInput,line);
        istringstream s1(line);
        s1>>weight[i];
        s1>>value[i];
    }
    int max_capacity;
    getline(myInput,line);
    istringstream s2(line);
    s2>>max_capacity;
    Dynamic bag(item_number,max_capacity);
    for(int i=0;i<item_number;i++){
        bag.Insert(weight[i],value[i]);
    }
    myOutput<<bag.Knapsack(item_number,max_capacity)<<endl;
    bag.print(myOutput);
}
