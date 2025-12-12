#include<iostream>
using namespace std;

int heapArr[10000];
int heap_size = 0;


void min_heapify(int i){
    int left = 2*i;
    int right = 2*i + 1;
    int smallest = i;

    if(left <= heap_size && heapArr[left] < heapArr[smallest]){
        smallest = left;
    }

    if(right <= heap_size && heapArr[right] < heapArr[smallest]){
        smallest = right;
    }

    if(smallest != i){
        swap(heapArr[i], heapArr[smallest]);
        min_heapify(smallest);
    }
}


void build_min_heap(){
    for(int i = heap_size/2; i >= 1; i--){
        min_heapify(i);
    }
}


void print_heap(){
    for(int i = 1; i <= heap_size; i++){
        cout << heapArr[i] << " ";
    }
    cout << endl;
}


int Heap_Minimum(){
    return heapArr[1];
}


int Heap_extract_min(){
    int minVal = heapArr[1];
    heapArr[1] = heapArr[heap_size];
    heap_size--;
    min_heapify(1);
    return minVal;
}


void Min_heap_insert(int value){
    heap_size++;
    heapArr[heap_size] = value;

    int i = heap_size;
    while(i > 1 && heapArr[i] < heapArr[i/2]){
        swap(heapArr[i], heapArr[i/2]);
        i = i/2;
    }
}


void Heap_decrease_key(int i, int k, int heap[]){
    (void)heap; 
    heapArr[i] -= k;
    while(i > 1 && heapArr[i] < heapArr[i/2]){
        swap(heapArr[i], heapArr[i/2]);
        i = i/2;
    }
}


void Heap_increase_key(int i, int k, int heap[]){
    (void)heap; 
    heapArr[i] += k;
    min_heapify(i);
}

int main(){
    int x;
    heap_size = 0;

    
    while(cin >> x && x != -1){
        heapArr[++heap_size] = x;
    }

    
    build_min_heap();
    cout << "Min Heap: ";
    print_heap();
    cout << endl;

    int func;
    while(cin >> func){
        if(func == 1){ 
            cout << Heap_Minimum() << endl;
            print_heap();
        }
        else if(func == 2){ 
            int val = Heap_extract_min();
            cout << val << endl;
            print_heap();
        }
        else if(func == 3){ 
            int v;
            cin >> v;
            Min_heap_insert(v);
            print_heap();
        }
        else if(func == 4){ 
            int i, k;
            cin >> i >> k;
            Heap_decrease_key(i, k, heapArr);
            print_heap();
        }
        else if(func == 5){ 
            int i, k;
            cin >> i >> k;
            Heap_increase_key(i, k, heapArr);
            print_heap();
        }
        else{
            break; 
        }
    }

    return 0;
}
