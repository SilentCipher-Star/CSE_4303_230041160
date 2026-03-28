#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<string>
using namespace std;

int main(){

    int V,E,Q;
    while(!(cin >> V >> E >> Q)) return 0;

    vector<string>students(V);
    map<string, vector<string>>adj;
    map<string, int>in_degree;

    for(int i=0; i<V; i++){
        cin >> students[i];
        in_degree[students[i]] = 0;
    }

    for(int i=0; i<E; i++){
        string student1, student2;
        cin >> student1 >> student2;

        adj[student1].push_back(student2);
        in_degree[student2]++;
    }

    queue<string>q;
    vector<string>topo_order;

    for(int i=0; i<V; i++){
        if(in_degree[students[i]] == 0){
            q.push(students[i]);
        }
    }

    while(!q.empty()){
        string curr = q.front();
        q.pop();
        topo_order.push_back(curr);

        for(string neighbour : adj[curr]){
            in_degree[neighbour]--;

            if(in_degree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    if(topo_order.size() != V){
        cout <<"IMPOSSIBLE\n";
        return 0;
    } 

    for(int i=0; i<V; i++){
        cout << topo_order[i] << (i == V-1 ? "" : " ");
    }
    cout << endl;

    for(int i=0; i<Q; i++){
        string bully, victim;
        cin >> bully >> victim;

        queue<string>search_q;
        map<string,bool>visited;
        bool found = false;

        search_q.push(victim);
        visited[victim] = true;

        while(!search_q.empty()){
            string curr = search_q.front();
            search_q.pop();

            if(curr == bully){
                found = true;
                break;
            }

            for(string neighbour : adj[curr]){
                if(!visited[neighbour]){

                    visited[neighbour] = true;
                    search_q.push(neighbour);
                }
            }
        }

        if(found){
            cout <<"Yes\n";
        }else{
            cout <<"No\n";
        }

    }
    return 0;
}
