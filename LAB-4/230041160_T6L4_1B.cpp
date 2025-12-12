#include<iostream>
using namespace std;

int heapArr[10000];
int heap_size = 0;



void max_heapify(int i){
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;

    if(left <= heap_size && heapArr[left] > heapArr[largest])
        largest = left;

    if(right <= heap_size && heapArr[right] > heapArr[largest])
        largest = right;

    if(largest != i){
        swap(heapArr[i], heapArr[largest]);
        max_heapify(largest);
    }
}



void build_max_heap(){
    for(int i = heap_size / 2; i >= 1; i--){
        max_heapify(i);
    }
}



void print_heap(){
    for(int i = 1; i <= heap_size; i++){
        cout << heapArr[i] << " ";
    }
    cout << endl;
}



int Heap_Maximum(){
    return heapArr[1];
}



int Heap_extract_max(){
    int maxVal = heapArr[1];
    heapArr[1] = heapArr[heap_size];
    heap_size--;
    max_heapify(1);
    return maxVal;
}



void Max_heap_insert(int value){
    heap_size++;
    heapArr[heap_size] = value;

    int i = heap_size;
    while(i > 1 && heapArr[i] > heapArr[i/2]){
        swap(heapArr[i], heapArr[i/2]);
        i = i/2;
    }
}



void Heap_decrease_key(int i, int k){
    heapArr[i] -= k;
    max_heapify(i);
}



void Heap_increase_key(int i, int k){
    heapArr[i] += k;

    while(i > 1 && heapArr[i] > heapArr[i/2]){
        swap(heapArr[i], heapArr[i/2]);
        i = i/2;
    }
}



int main(){
    int x;
    heap_size = 0;

    
    while(cin >> x && x != -1){
        heapArr[++heap_size] = x;
    }

    build_max_heap();
    cout << "Max Heap: ";
    print_heap();
    cout << endl;

    int func;
    while(cin >> func){
        if(func == 1){
            cout << Heap_Maximum() << endl;
            print_heap();
        }
        else if(func == 2){
            int val = Heap_extract_max();
            cout << val << endl;
            print_heap();
        }
        else if(func == 3){
            int v;
            cin >> v;
            Max_heap_insert(v);
            print_heap();
        }
        else if(func == 4){
            int i, k;
            cin >> i >> k;
            Heap_decrease_key(i, k);
            print_heap();
        }
        else if(func == 5){
            int i, k;
            cin >> i >> k;
            Heap_increase_key(i, k);
            print_heap();
        }
        else{
            break;
        }
    }

    return 0;
}
