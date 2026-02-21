#include <iostream>
#include <vector>
using namespace std;

class Basic_DSU
{
private:
    vector<int> parent;

public:
    Basic_DSU(int size)
    {
        parent.resize(size);
        for (int i = 0; i < size; i++)
        {
            parent[i] = i;
        }
    }

    int find(int i)  //finds the representative of the set
    {
        if (parent[i] == i)
        {
            return i;
        }
        return find(parent[i]);
    }

    void union_set(int i, int j)   // finds the represetative of i and j
    {                              // make j's represetative point to i's
        int irep = find(i);
        int jrep = find(j);
        parent[jrep] = irep;
    }

    void print()
    {
        for (size_t i = 0; i < parent.size(); i++)
        {
            cout << parent[i] << " ";
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
            int i, j;
            cin >> i >> j;
            dsu.union_set(i, j);
            dsu.print();
            break;
        }

        case 3:
        {
            int x, y;
            cin >> x >> y;
            cout << dsu.find(x) << endl;
            cout << dsu.find(y) << endl;
            break;
        }

        default:
            return 0; 
        }
    }

    return 0;
}
