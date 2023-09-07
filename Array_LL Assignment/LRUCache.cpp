#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "Array.cpp"

using namespace std;

class LRUCache{
    public:
    int capacity;
    int length;
    LRUCache(int capacity) {
        this->capacity=capacity;
        length=0;
    }
    MyList<int> valueList;
    MyList<int> keyList;
    int put(int key, int value){
        int position = keyList.find(key);
          if(position!= -1)
          {
            valueList.setToPos(position);
            int erased=valueList.erase();
            valueList.push(value);
            valueList.setToPos(position);
            keyList.setToPos(position);
            int recentvalue = valueList.erase();
            int recentkey = keyList.erase();
            valueList.pushBack(recentvalue);
            keyList.pushBack(recentkey);
          }else{
            if(length == capacity)
            {
                valueList.setToBegin();
                keyList.setToBegin();
                int valueErased = valueList.erase();
                int keyErased = keyList.erase();
                valueList.pushBack(value);
                keyList.pushBack(key);
            } 
            else
            { 
                length++;
                valueList.pushBack(value);
                keyList.pushBack(key);
            }
          }
        }
      int get(int key) {
        int position=keyList.find(key);
        if(position!=-1){
          valueList.setToPos(position);
          int getValue=valueList.getValue();
          keyList.setToPos(position);
          int recentvalue = valueList.erase();
          int recentkey = keyList.erase();
          valueList.pushBack(recentvalue);
          keyList.pushBack(recentkey);
          return getValue;
        }else{
            return -1;
          }
    }
  };
int main(){
  int capacity;
  int choices;
  ifstream myInput;
  ofstream myOutput;
  LRUCache lruCache(capacity);
  myOutput.open("lru_output.txt");
    myInput.open("lru_input.txt");
    if(!myInput){

        cout<<"File not valid"<<endl;
    }
    string line;
    getline(myInput,line);
    istringstream s(line);
    s>>capacity;
    getline(myInput,line);
    istringstream s1(line);
    s1>>choices;
    int options[choices],key[choices],value[choices];
    for(int i=0;i<choices;i++){
      getline(myInput,line);
      istringstream s2(line);
      s2>>options[i];
      s2>>key[i];
      if(options[i]==2){
        s2>>value[i];
      }
    }
    for(int i=0;i<choices;i++){
      if(options[i]==1){
        cout<<lruCache.get(key[i])<<endl;
      }
      else{
        lruCache.put(key[i],value[i]);
      }
    }
}