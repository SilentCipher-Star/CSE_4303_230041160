#include <iostream>
#include <vector>
#include <climits> 

using namespace std;

vector<int> arr;
vector<int> tree;


void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return;
    }

    
    int mid = (start + end) / 2;
    int left_child = 2 * node;
    int right_child = 2 * node + 1;

    
    build(left_child, start, mid);
    build(right_child, mid + 1, end);

    
    tree[node] = min(tree[left_child], tree[right_child]);
}


int query(int node, int start, int end, int l, int r)
{
    
    if (r < start || end < l)
    {
        return INT_MAX;
    }

    
    if (l <= start && end <= r)
    {
        return tree[node];
    }


    int mid = (start + end) / 2;
    int left_child = 2 * node;
    int right_child = 2 * node + 1;

    int left_min = query(left_child, start, mid, l, r);
    int right_min = query(right_child, mid + 1, end, l, r);

    return min(left_min, right_min);
}

int main()
{
    int N, Q;

    while (cin >> N >> Q)
    {
      
        arr.resize(N + 1);

        tree.resize(4 * N + 1);

    
        for (int i = 1; i <= N; i++)
        {
            cin >> arr[i];
        }

       
        build(1, 1, N);

       
        for (int i = 0; i < Q; i++)
        {
            int l, r;
            cin >> l >> r;

         
            cout << query(1, 1, N, l, r) << "\n";
        }
    }

    return 0;
}