#include <iostream>
using namespace std;

int x;
int sorted[10000];
int arr[100000];
int n = 0;

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] < arr[smallest])
        smallest = left;
    if (right <= n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void Build_min_heap(int arr[], int n) {
    for (int i = n / 2; i >= 1; i--)
        heapify(arr, n, i);
}

void Heap_sort(int arr[], int n, int sorted[]) {
    Build_min_heap(arr, n);
    int size = n;
    int index = 0;

    while (size >= 1) {
        sorted[index++] = arr[1];
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}

int main() {
    while (true) {
        cin >> x;
        if (x == -1) break;

        n = 0;
        while (x != -1) {
            arr[++n] = x;
            cin >> x;
        }

        Build_min_heap(arr, n);
        cout << "Min Heap:";
        for (int i = 1; i <= n; i++)
            cout << " " << arr[i];
        cout << endl;

        Heap_sort(arr, n, sorted);
        cout << "Sorted:";
        for (int i = 0; i < n; i++)
            cout << " " << sorted[i];
        cout << endl << endl;
    }
}
