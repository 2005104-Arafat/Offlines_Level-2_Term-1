#include<iostream>
#include <fstream>
#include<sstream>
#include "LinkedList.cpp";
#include "QueueArray.cpp";
using namespace std;

class Graph{
    public:
    int vertices;
    int edges;
    int source;
    MyList<int> *vertex;
    MyList<int> dfsValue;
    MyList<int> dfsSource;
    MyList<int> dfsDestination;
    int *is_visited;
    Graph(int n,int m, int s ){
        vertices=n;
        edges=m;
        source=s;
        vertex=new MyList<int> [vertices+1];
        is_visited=new int[vertices+1];
    }
    void graphInsert(int m , int n){
        vertex[m].pushBack(n);
        //is_visited[m]=false;
    }
    void BFS(ofstream &output){
        output<<"Breadth-First Search:"<<endl;
        output<<endl;
        Queue<int> newQueue(edges+1);
        for(int i=0;i<=edges;i++)
        {
            is_visited[i]=0;
        }
        newQueue.enqueue(source);
        is_visited[source]=1;
        MyList<int> sources;
        MyList<int> destinations;
        output<<"Set of vertices: ";
        int j=1;
        while(newQueue.length()!=0){ 
            int current=newQueue.dequeue();
            output<<current<<" ";
            vertex[current].setToBegin();
            for(int i=0;i<vertex[current].length();i++){
                int next=vertex[current].getValue();
                vertex[current].next();
                if(is_visited[next]==0){
                    is_visited[next]=1;
                    newQueue.enqueue(next);
                    sources.pushBack(current);
                    destinations.pushBack(next);
                }
            } 
        }
        output<<endl;
        int i=0;
        output<<endl;
        output<<"Set of Edges : "<<endl;
        while(i<sources.length()){
            int sourceValue=sources.getValue();
            int destinationValue=destinations.getValue();
            sources.next();
            destinations.next();
            output<<"("<<sourceValue<<","<<destinationValue<<")"<<endl;
            i++;
        }
        output<<endl;
        output<<endl;
        output<<endl;
    }
    
    void DFS(ofstream &output){
        output<<"Depth-First Search:"<<endl;
        output<<endl;
        for(int i=0;i<=vertices;i++)
        {
            is_visited[i]=0;
        }
        dfsRecursion(source);
        output<<"Set of vertices: ";
        dfsValue.display(output);
        output<<endl;
        output<<"Set of edges:"<<endl;
        int i=0;
        while(i<dfsSource.length()){
            int sourceValue=dfsSource.getValue();
            int destinationValue=dfsDestination.getValue();
            dfsSource.next();
            dfsDestination.next();
            output<<"("<<sourceValue<<","<<destinationValue<<")"<<endl;
            i++;
        }
        output<<endl;
        output<<endl;
        output<<endl;
    }
    
    void dfsRecursion(int vertex1){
        
        is_visited[vertex1]=1;
        vertex[vertex1].setToBegin();
        dfsValue.pushBack(vertex1);
        for(int i=0;i<vertex[vertex1].length();i++){
            int next=vertex[vertex1].getValue();
            vertex[vertex1].next();
            if(is_visited[next]==0){
                dfsSource.pushBack(vertex1);
                dfsDestination.pushBack(next);
                dfsRecursion(next);
            }
        }
    }

};
// int main(){
//     Graph newGraph(9,8,1);
//     newGraph.graphInsert(1,2);
//     newGraph.graphInsert(1,3);
//     newGraph.graphInsert(2,4);
//     newGraph.graphInsert(2,5);
//     newGraph.graphInsert(3,6);
//     newGraph.graphInsert(4,9);
//     newGraph.graphInsert(4,8);
//     newGraph.graphInsert(3,7);
//     newGraph.BFS();
//     newGraph.DFS();
// }