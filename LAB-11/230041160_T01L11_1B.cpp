#include<iostream>
#include<vector>
using namespace std;

class DSU{

private:
    vector<int>parent;
    vector<int>size;

public:
    int component;
    int maxsize;

    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);
        component = n;
        maxsize = 1;

        for(int i=1; i<= n; i++){
            parent[i] = i;
            size[i] = i;
        }
    }

    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unit(int a, int b){
        int rootA = find(a);
        int rootB = find(b);

        if(rootA != rootB){   // if they r diff, we merge them in the same component
            if(size[rootA] < size[rootB]){
                swap(rootA, rootB);   //attaching smaller tree under bigger tree
            }

            parent[rootB] = rootA;  //smaller component root points to bigger component root
            size[rootA] += size[rootB];  //total size

            component--;  //since after merging 2 components becomes one hence the number of components will decrese
            maxsize = max(maxsize, size[rootA]);  //if the new component bigger then the previous one then will update
        }
    }
};

int main(){

    int n,m;
    cin >> n >> m;

    DSU dsu(n);
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        dsu.unit(a,b);

        cout << dsu.component << " " << dsu.maxsize << endl;
    }
    return 0;
}