#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){

    int n,m;

    if(!(cin >> n >> m)) return 0;
    vector<vector<int>>graph(n+1);

    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >>v;
        graph[u].push_back(v);
    }

    int src, des;
    cin >> src>> des;

    vector<bool>visited(n+1,false);
    queue<int>q;

    q.push(src);
    visited[src] = true;
    bool found = false;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        if(curr == des){

            found = true;
            break;
        }

        for(int neighbour : graph[curr]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    if(found){
        cout <<"Yes\n";
    }
    else{
        cout << "No\n";
    }
    return 0;
}