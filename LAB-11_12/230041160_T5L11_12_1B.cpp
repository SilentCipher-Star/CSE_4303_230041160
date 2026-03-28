#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

int main(){

    int V,E,Q;
    while(!(cin >> V >> E >> Q)) return 0;

    vector<string>cities(V);
    for(int i=0; i<V; i++){
        cin >> cities[i];
    }

    map<string,vector<string>>Graph; //map stores which cities r directly connected to each other
    for(int i=0; i<E; i++){
        string city1, city2;
        cin >> city1 >> city2;

        Graph[city1].push_back(city2);  //since undirected add the cities both ways
        Graph[city2].push_back(city1);
    }

    for(int i=0; i<Q; i++){
        string src,des;
        int k;
        cin >> src >> des >>k;

        map<string,string>parent;  //to remember from where we came from
        map<string,bool>visited;   //cities we already visited
        queue<string>q;          //cities waiting in line

        q.push(src);
        visited[src] = true;
        bool found = false;

        while(!q.empty()){
            string current = q.front();
            q.pop();

            if(current == des){
                found = true;
                break;
            }

            for(string neighbour : Graph[current]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    parent[neighbour] = current;
                    q.push(neighbour);
                }
            }
        }
        if(!found){
            cout << "NO\n";
        }
        else{
            vector<string>path;
            string curr = des;
            while(curr != src){
                path.push_back(curr);
                curr = parent[curr];
            }
            path.push_back(src);
            reverse(path.begin(),path.end());
            int distance = path.size()-1;
            if(distance % k != 0){
                cout << "NO\n";
            }
            else{
                for(int j=0; j<path.size(); j+=k){
                    cout << path[j] << (j + k < path.size() ? " " : "");    
                }
                cout <<"\n";
            }
        }
    }

    return 0;
}