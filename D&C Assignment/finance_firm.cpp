#include <iostream>
#include <fstream>
#include<sstream>
#include<cstring>
using namespace std;
int merge(int a[],int start,int mid,int end){
    int invertedpair=0;
    int n1=mid-start+1;
    int n2=end-mid;
    int a1[n1];
    int a2[n2];
    for(int i=0;i<n1;i++){
        a1[i]=a[start+i];
    }
    for(int i=0;i<n2;i++){
        a2[i]=a[mid+1+i];
    }
    int i=0,j=0,k=start;
    while(i<n1 && j<n2){
        if(a1[i]<a2[j]){
            a[k++]=a1[i++];
        }else{
            a[k++]=a2[j++];
            invertedpair+=n1-i;
        }
    }
    while(i<n1){
        a[k++]=a1[i++];
    }
    while(j<n2){
        a[k++]=a2[j++];
    }
    return invertedpair;
}
int mergeSort(int a[],int start,int end){
    int inverteNUmber=0;
    if(start<end){
        int mid =(start+end)/2;
        inverteNUmber+=mergeSort(a,start,mid);
        inverteNUmber+=mergeSort(a,mid+1,end);
        inverteNUmber+=merge(a,start,mid,end);
    }
    return inverteNUmber;
}
void printInvertedPair(int array[],int length,int count,ofstream &output){
    if(count!=0){
        output<<"The inverted pairs are ";
    }
    int k=0;
    for(int i=0;i<length;i++){
        for(int j=i+1;j<length;j++){
            if(array[i]>array[j]){
                output<<"("<<array[i]<<","<<array[j]<<")";
                k++;
                if(k<count){
                    output<<",";
                }
            }
        }
    }
    output<<endl;
}
int main(){
    ifstream myInput;
    ofstream myOutput;
    myInput.open("DAC_input.txt");
    myOutput.open("DAC_output.txt");
    
    if(!myInput){
        cout<<"File not valid"<<endl;
    }
    string line;
    getline(myInput,line);
    istringstream s(line);
    int length;
    s>>length;
    int array[length];
    int array2[length];
    getline(myInput,line);
    istringstream s3(line);
    for(int i=0;i<length;i++){
        s3>>array[i];
        array2[i]=array[i];
    }
    int count=mergeSort(array,0,length-1);
    myOutput<<count<<endl;
    printInvertedPair(array2,length,count,myOutput);
}
