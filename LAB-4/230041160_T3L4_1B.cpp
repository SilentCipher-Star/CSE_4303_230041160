#include<iostream>
using namespace std;

int heap_arr[10000];
int heap_size = 0;

void heapify(int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i +1;

    if(left <= heap_size && heap_arr[left] > heap_arr[largest]){
        largest = left;
    }

    if(right <= heap_size && heap_arr[right] > heap_arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(heap_arr[i], heap_arr[largest]);
        heapify(largest);
    }
}

void build_heap(){
    for(int i= heap_size/2; i >= 1; i--){
        heapify(i);
    }
}

void insert(int x){
    heap_size++;
    heap_arr[heap_size] = x;

    int i= heap_size;
    while(i > 1 && heap_arr[i] > heap_arr[i/2]){
        swap(heap_arr[i], heap_arr[i/2]);
        i = i/2;
    }
}

int extractMax(){
    int maxVal = heap_arr[1];
    heap_arr[1] = heap_arr[heap_size];
    heap_size--;

    heapify(1);
    return maxVal;
}
int main(){

    int x;
    // heap_size = 0;
    while(cin >> x && x != -1){
        insert(x);
    }

    while(heap_size > 1){
        int y = extractMax();
        int x = extractMax();

        if(y != x){
            insert(y-x);
        }
    }

    if(heap_size == 1){
        cout << heap_arr[1] << endl;
    }else{
        cout << 0 << endl;
    }

    return 0;
}