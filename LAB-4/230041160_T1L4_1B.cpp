#include<iostream>
using namespace std;

int sorted[10000];
int arr[100000];
int x;
int n = 0;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = i*2;
    int right = 2*i + 1;

    if(left<= n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right <= n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr,n,largest);
    }
}

void build_max_heap(int arr[], int n){
    for(int i= n/2; i>= 1; i--){
        heapify(arr, n, i);
    }
}

void Heap_sort(int arr[], int n, int sorted[]){
    build_max_heap(arr,n);
    int size = n;
    int index = 0;

    while(size >= 1){
        sorted[index++] = arr[1];
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}
int main(){

    while(true){
        cin >> x;
        if(x == -1) break;

        while(cin >> x && x != -1){
            arr[++n] = x;
        }

        int heap[10000];
        for(int i=1; i<=n; i++){
            heap[i] = arr[i];
        }

        build_max_heap(heap, n);
        cout << "Max Heap:";

        for(int i = 1; i<= n; i++){
            cout << " " << heap[i];
        }
        cout << endl;

        Heap_sort(arr, n, sorted);
        cout << "Sorted:";

        for(int i=0; i<n; i++){
            cout << " " << sorted[i];
        }
        cout << endl << endl;
    }

    return 0;
}