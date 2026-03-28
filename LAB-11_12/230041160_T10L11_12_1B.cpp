#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){

    int V;
    if(!(cin >> V)) return 0;

    vector<vector<int>>graph(V);
    for(int i=0; i<V; i++){
        int n;
        cin >> n;

        for(int j=0; j<n;j++){
            int neighbour;
            cin >> neighbour;

            graph[i].push_back(neighbour);
        }
    }
    vector<int>color(V,-1);  // -1 ->unpainted, 0->red, 1->blue
    bool isBipartite = true;

    for(int start = 0; start < V; start++){
        if(color[start] == -1){
            queue<int>q;
            q.push(start);
            color[start] = 0;

            while(!q.empty()){
                int curr = q.front();
                q.pop();

                for(int neighbour : graph[curr]){
                    if(color[neighbour] == -1){ //neighbour unpainted
                        color[neighbour] = 1-color[curr];  //paint it in opp color
                        q.push(neighbour);
                    }
                    else if(color[neighbour] == color[curr]){
                        isBipartite = false;
                        break;
                    }
                }

                if(!isBipartite){
                    break;
                }
            }
        }
        if(!isBipartite){
            break;
        }
    }

    if(isBipartite){
        cout <<"Yes\n";
    }
    else{
        cout <<"No\n";
    }
    return 0;
}