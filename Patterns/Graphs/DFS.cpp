// C++ program to print DFS traversal from a given source vertex.

#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int V; 
    list<int> *l; 

public:
    Graph(int v){
        this->V=v;
        l=new list<int>[V]; 
    }

    void addEdge(int u,int v){
               l[u].push_back(v); 
               l[v].push_back(u); 
        }

     void DFS(int u, vector<bool> &vis){
            cout<<u<<" ";
            vis[u]=true;

            for(int v:l[u]){
                if(!vis[v]){
                    DFS(v, vis);
                }
            }
      
     }
   void dfsHelper(){
        vector<bool> vis(V,false);
        DFS(0,vis);
        cout<<endl;
   }
    };

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

     g.dfsHelper();

     return 0;
}