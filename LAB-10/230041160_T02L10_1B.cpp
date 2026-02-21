#include <iostream>
#include <vector>
using namespace std;

class Basic_DSU
{
private:
    vector<int> parent;
    vector<int>rank;

public:
    Basic_DSU(int size)
    {
        parent.resize(size);
        rank.resize(size,0);
        for (int i = 0; i < size; i++)
        {
            parent[i] = i;
        }
    }

    int find(int i)
    {
        if (parent[i] == i)
        {
            return i;
        }
        return find(parent[i]);
    }

    void union_set(int i, int j)
    {
        int irep = find(i);
        int jrep = find(j);
        if(rank[irep] > rank[jrep]){
            parent[jrep] = irep; // Attach shorter tree under taller tree

        }else if(rank[irep] < rank[jrep]){
            parent[irep] = jrep;

        }else{ // Attaching one under another increases height by 1
            parent[irep] = jrep;
            rank[jrep] ++;
        }
    }

    void print()
    {
        for (size_t i = 0; i < parent.size(); i++)
        {
            cout << parent[i] << '(' << rank[i] << ')' << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;

    Basic_DSU dsu(n);

    dsu.print();

    int type;
    while (cin >> type)
    {

        switch (type)
        {

        case 1:
        {
            dsu.print();
            break;
        }

        case 2:
        {
            int x;
            cin >> x;
            cout << dsu.find(x) << endl;
            break;
        }

        case 3:{
            int i, j;
            cin >> i >> j;
            dsu.union_set(i, j);
            dsu.print();
            break;
        }

        case 4:
        {
            dsu.print();
            break;
        }
        default:
        {
            return 0;
        }

        }
    }

    return 0;
}
