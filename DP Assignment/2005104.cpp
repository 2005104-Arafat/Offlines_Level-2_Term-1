#include<iostream>
#include<algorithm>
using namespace std;
int list(int array[],int length){
    int LIS[length];
    LIS[0]=1;
    for(int i=1;i<length;i++){
        LIS[i]=1;
        for(int j=0;j<i;j++){
            if(array[i]>array[j] && LIS[i]<LIS[j]+1){
                LIS[i]=LIS[j]+1;
            }
        }
    }
    return *max_element(LIS,LIS+length);
}
int main(){
    int array[]={10,22,9,33,21,50,41,60,80};
    int length=9;
    cout<<list(array,length)<<endl;
}