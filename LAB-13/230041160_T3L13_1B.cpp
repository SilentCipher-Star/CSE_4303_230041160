#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> tree;


int LSB(int x)
{
    return x & (-x);
}


void update(int idx, int val)
{
    
    while (idx <= N)
    {
        tree[idx] += val; 
        idx += LSB(idx); 
    }
}


int queryPrefix(int idx)
{
    int sum = 0;
   
    while (idx > 0)
    {
        sum += tree[idx]; 
        idx -= LSB(idx);  
    }
    return sum;
}


int queryRange(int L, int R)
{
    

    return queryPrefix(R) - queryPrefix(L - 1);
}


void printTree()
{
    for (int i = 1; i <= N; i++)
    {
        cout << i << ":" << tree[i] << (i == N ? "" : " ");
    }
    cout << "\n";
}

int main()
{
    
    if (!(cin >> N))
        return 0;

   

    tree.assign(N + 1, 0);


    for (int i = 1; i <= N; i++)
    {
        cin >> tree[i]; 
    }

   
    for (int i = 1; i <= N; i++)
    {
        int parent = i + LSB(i); 
        if (parent <= N)
        {
            tree[parent] += tree[i]; 
        }
    }

    
    cout << "Status of Fenwick Tree (idx: value):\n";
    printTree();


    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
           
            int L, R;
            cin >> L >> R;
            cout << "Query: Sum=" << queryRange(L, R) << "\n";
        }
        else if (type == 2)
        {
           
            int idx, val;
            cin >> idx >> val;
            update(idx, val); 
            cout << "Updated tree:\n";
            printTree();
        }
    }

    return 0;
}