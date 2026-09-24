// implementation of graph using adjacency list
// idea is to store the neighbors of each vertex in a list
#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V; // number of vertices
    list<int> *l; // pointer to an array of lists

public:
    Graph(int v){
        this->V=v;
        l=new list<int>[V]; // create an dynamic array of lists of size V
    }

    void addEdge(int u,int v){
               l[u].push_back(v); // add v to u's list
               l[v].push_back(u); // add u to v's list (for undirected graph)
        }

    void printAdjList(){
        for(int i=0;i<V;i++){
            cout<<i<<":";
            for(int neigh:l[i]){
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }
    };

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    g.printAdjList();
}