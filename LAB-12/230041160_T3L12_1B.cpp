#include <iostream>
#include <vector>
using namespace std;

class Fenwick
{

public:
    int n;
    vector<long long> tree;

    Fenwick(int n)
    {
        this->n = n;
        tree.assign(n + 1, 0);
    }

    void Print_Ranges()
    {

        cout << "Ranges to be stored in the Fenwick Table:" << endl;
        for (int i = 1; i <= n; i++)
        {

            int lsb = i & -i;
            int start = i - lsb + 1;

            cout << i << " :(" << start << ',' << i << ") ";
            if (i % 4 == 0)
            {
                cout << "\n";
            }
        }
    }

    void build(vector<long long> &arr)
    {

        for (int i = 1; i <= n; i++)
        {
            tree[i] += arr[i];
            int parent = i + (i & -i);
            if (parent <= n)
            {
                tree[parent] += tree[i];
            }
        }
    }

    void print_tree()
    {
        cout << "Status of Fenwick Tree (idx: value):\n";
        for (int i = 1; i <= n; i++)
        {
            cout << i << " : " << tree[i] << " ";
        }
    }

    long long prefix(int i, vector<long long> &used_idx)
    {
        long long sum = 0;
        while (i > 0)
        {
            used_idx.push_back(i);
            sum += tree[i];
            i -= (i & -i);
        }
        return sum;
    }

    long long rangeSum(int l, int r, vector<long long> &right, vector<long long> &left)
    {

        long long right_sum = prefix(r, right);
        long long left_sum = prefix(l - 1, left);
        return right_sum - left_sum;
    }
};
int main()
{

    int n;
    cin >> n;

    vector<long long> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    Fenwick fen(n);
    fen.Print_Ranges();
    fen.build(arr);
    fen.print_tree();

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;

        vector<long long> right, left;
        long long ans = fen.rangeSum(l, r, right, left);

        cout << "Query-" << i << ": Sum=" << ans << " [Tree idx: ";
        cout << "sum(";

        for (int i = 0; i < right.size(); i++)
        {
            cout << right[i];

            if (i != right.size() - 1)
            {
                cout << ",";
            }
        }

        cout << ")";

        if (!left.empty())
        {
            cout << " - sum(";
            for (int i = 0; i < left.size(); i++)
            {
                cout << left[i];

                if (i != left.size() - 1)
                {
                    cout << ",";
                }
            }
            cout << ")";
        }
        cout << "]\n";
    }
    return 0;
}