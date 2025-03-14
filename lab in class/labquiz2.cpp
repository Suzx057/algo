#include <iostream>
#include <vector>




using namespace std;


void DFS(vector<vector<int>> graph, int startvertex, vector<bool> & visited){
    cout<<startvertex<<" ";
    visited[startvertex] = true ;

    for(int i = 0; i < graph.size();i++){
        if(graph[startvertex][i] & !visited[i]){
            DFS(graph, i ,visited);
        }
    }
}


int main() {
    int V, E;
    cin >> V >> E;
    
    
    vector<vector<int> > graph(V, vector<int>(V, 0));

    for (int i = 0; i < E; i++) {
        int u , l ;
        cin>>u>>l;
        vector<bool> visited(V,false);
        DFS(graph,E,visited);
    }

    
    //DFS(graph,startvertex,visited)
    

 
 
    
    return 0;
}
