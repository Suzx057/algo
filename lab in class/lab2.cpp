#include <iostream>
#include <vector>
#define INF 1000000

using namespace std;



int main() {
    int V, E;
    cin >> V >> E;
    
    
    vector<vector<int> > graph(V, vector<int>(V, INF));
    for (int i = 0; i < V; i++) {
        graph[i][i] = 0;
    }
    
    
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; 
    }
    
    for(int  i =0 ;i<V;i++){
        for(int j = 0 ;j<V;j++){
            if(graph[i][j] == INF){
                cout<<"."<<" ";
            }else{
                cout<<graph[i][j]<<" ";
            }
        }
        cout<<endl;
    }
 
 
    
    return 0;
}
