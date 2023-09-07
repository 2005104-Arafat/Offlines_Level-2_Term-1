#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
class Heap{
    public:
    int *array;
    int *newArray;
    int length=0;
    Heap(){
        array=new int[100];
        newArray=new int [100];
    }

    void Insert(int value){
        array[length++]=value;
        int i=length-1;
        while(i>0){
            int parent=floor((i-1)/2);
            if(array[i]<array[parent]){
                swap(i,parent);
                i=parent;
            }
            else{
                return;
            }
        }
    }
    void InsertMaxHeap(int value){
        array[length++]=value;
        int i=length-1;
        while(i>0){
            int parent=floor((i-1)/2);
            if(array[i]>array[parent]){
                swap(i,parent);
                i=parent;
            }
            else{
                return;
            }
        }
    }
    int FindMin(){
        return array[0];
    }
    int ExtractMin(){
        int v=array[0];
        array[0]=array[length-1];
        length--;
        int i=0;
        while(i<length){
            int left=2*i+1;
            int right=2*i+2;
            if(array[i]>array[left] && array[i]>array[right] && left<=(length-1) && right<=(length-1) ){
                if(array[left]<array[right]){
                    swap(i,left);
                    i=left;
                }else{
                    swap(i,right);
                    i=right;
                }
            }
            else if(array[i]>array[left] && array[i]<=array[right] && left<=(length-1)){
                swap(i,left);
                i=left;
            }
            else if(array[i]>array[right] && array[i]<=array[left] && right<=(length-1)){
                swap(i,right);
                i=right;
            }
            else{
                break;
            }
        }
        return v;
    }
    void DecreaseKey(int prevKey,int newKey){
        int i;
        for(i=0;i<length;i++){
            if(array[i]==prevKey){
                array[i]=newKey;
                break;
            }
        }
        while(i>0){
            int parent=floor((i-1)/2);
            if(array[i]<array[parent]){
                swap(i,parent);
                i=parent;
            }
            else{
                return;
            }
        }
    }
    int height(int i){
        if(i>=length || length==0)return 0;
        else{
            int lheight=height(2*i+1);
            int rheight=height(2*i+2);
            if(lheight>rheight){
                return lheight+1;
            }
            else{
                return rheight+1;
            }
        }
    }
    void buildHeap(){
        for(int i=0;i<length;i++){
            newArray[i]=array[i];
        }
        int temp1=length;
        for(int i=0;i<temp1;i++){
            ExtractMin();
        }

        for(int i=0;i<temp1;i++){
            InsertMaxHeap(newArray[i]);
        }
    }
    string Print(){
        string str="\0";
        str=str+"Printing the binary heap ...";
        str=str+"\n";
        str=str+"- - - - - - - - - - - - - - - - - - - -";
        str=str+"\n";
        int element=0;
        int n=1;
        if(length!=0){
            for(int i=0;i<height(0);i++){
                str=str+"Level "+to_string(i)+": ";
                for(int k=0;k<n && element<length;k++){
                    str=str+to_string(array[element])+" ";
                    element++;
                }
                str=str+"\n";
                n*=2;
            }
        }
        str=str+"\n";
        str=str+"- - - - - - - - - - - - - - - - - - - -";
        return str;
    }
    void heapify(){
        int i=0;
        while(i<length){
            int left=2*i+1;
            int right=2*i+2;
            if(array[i]<array[left] && array[i]<array[right] && left<=(length-1) && right<=(length-1) ){
                if(array[left]>array[right]){
                    swap(i,left);
                    i=left;
                }else{
                    swap(i,right);
                    i=right;
                }
            }
            else if(array[i]<array[left] && array[i]>=array[right] && left<=(length-1)){
                swap(i,left);
                i=left;
            }
            else if(array[i]<array[right] && array[i]>=array[left] && right<=(length-1)){
                swap(i,right);
                i=right;
            }
            else{
                break;
            }
        }
    }
    void sort(){
        int temp=length;
        for(int i=0;i<temp;i++){
            int v=array[0];
            array[0]=array[length-1];
            length--;
            heapify();
            array[temp-(i+1)]=v;
        }
        length=temp;
    }
    void swap(int n1,int n2){
        int temp=array[n1];
        array[n1]=array[n2];
        array[n2]=temp;
    }
};
