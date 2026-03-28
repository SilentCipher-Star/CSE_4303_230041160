#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int N, Q, treeSize;
vector<int> arr;
vector<int> tree;
vector<int> lazy;


void initTreeSize()
{
    int p = 1;
    while (p < N)
        p *= 2;
    treeSize = 2 * p - 1;


    tree.assign(treeSize + 1, 0);
    lazy.assign(treeSize + 1, 0);
}


void printState()
{
    for (int i = 1; i <= treeSize; i++)
    {
        cout << tree[i] << (i == treeSize ? "" : " ");
    }
    cout << "\n";
    for (int i = 1; i <= treeSize; i++)
    {
        cout << lazy[i] << (i == treeSize ? "" : " ");
    }
    cout << "\n\n"; 
}

void build(int node, int start, int end)
{
    if (start == end)
    {
       
        if (start <= N)
            tree[node] = arr[start];
        else
            tree[node] = INT_MAX; 
        return;
    }

    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

void push(int node, int start, int end)
{
    if (lazy[node] != 0)
    {
        tree[node] += lazy[node]; 

        if (start != end)
        {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }

        lazy[node] = 0; 
    }
}


void updateRange(int node, int start, int end, int l, int r, int val)
{
    push(node, start, end);

    if (r < start || end < l)
        return;

    if (l <= start && end <= r)
    {
        lazy[node] += val;
        push(node, start, end);
        return;
    }

    int mid = (start + end) / 2;
    updateRange(2 * node, start, mid, l, r, val);
    updateRange(2 * node + 1, mid + 1, end, l, r, val);

    
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int queryRange(int node, int start, int end, int l, int r)
{
    push(node, start, end);

    if (r < start || end < l)
        return INT_MAX;

    
    if (l <= start && end <= r)
        return tree[node];

    int mid = (start + end) / 2;
    int left_min = queryRange(2 * node, start, mid, l, r);
    int right_min = queryRange(2 * node + 1, mid + 1, end, l, r);

    return min(left_min, right_min);
}

int main()
{
    if (!(cin >> N >> Q))
        return 0;

    arr.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    initTreeSize();
    build(1, 1, treeSize / 2 + 1); 

    printState();

    for (int i = 0; i < Q; i++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
         
            int l, r;
            cin >> l >> r;
            cout << queryRange(1, 1, treeSize / 2 + 1, l, r) << "\n";
            printState();
        }
        else if (type == 2)
        {
           
            int l, r, val;
            cin >> l >> r >> val;
            updateRange(1, 1, treeSize / 2 + 1, l, r, val);
            printState();
        }
    }

    return 0;
}