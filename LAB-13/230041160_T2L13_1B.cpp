#include <iostream>
#include <vector>

using namespace std;


vector<int> arr;
vector<long long> tree; 

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


    tree[node] = tree[left_child] + tree[right_child];
}


void update(int node, int start, int end, int idx)
{
  
    if (start == end)
    {
        tree[node] = arr[start]; 
        return;
    }

    int mid = (start + end) / 2;
    int left_child = 2 * node;
    int right_child = 2 * node + 1;

    if (idx <= mid)
    {
        update(left_child, start, mid, idx); 
    }
    else
    {
        update(right_child, mid + 1, end, idx);
    }

    
    tree[node] = tree[left_child] + tree[right_child];
}


long long query(int node, int start, int end, int l, int r)
{

    if (r < start || end < l)
    {
        return 0; 
    }


    if (l <= start && end <= r)
    {
        return tree[node];
    }


    int mid = (start + end) / 2;
    int left_child = 2 * node;
    int right_child = 2 * node + 1;

    long long left_sum = query(left_child, start, mid, l, r);
    long long right_sum = query(right_child, mid + 1, end, l, r);

    return left_sum + right_sum;
}


void printArray(int N)
{
    for (int i = 1; i <= N; i++)
    {
        cout << arr[i] << (i == N ? "" : " ");
    }
}

int main()
{
    int N, Q;

   
    if (!(cin >> N >> Q))
        return 0;

    arr.resize(N + 1);
    tree.resize(4 * N + 1); 

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

   
    build(1, 1, N);

   
    for (int i = 0; i < Q; i++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
          
            int idx;
            cin >> idx;
            int money_given = arr[idx]; 

            arr[idx] = 0;        
            update(1, 1, N, idx); 

            cout << money_given << " (";
            printArray(N);
            cout << ")\n";
        }
        else if (type == 2)
        {
       
            int idx, v;
            cin >> idx >> v;

            arr[idx] += v;       
            update(1, 1, N, idx); 

            printArray(N);
            cout << "\n";
        }
        else if (type == 3)
        {
            
            int l, r;
            cin >> l >> r;

         
            cout << query(1, 1, N, l, r) << "\n";
        }
    }

    return 0;
}