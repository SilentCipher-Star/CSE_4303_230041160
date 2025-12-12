#include<iostream>
#include<string>
using namespace std;

struct wizard{
    string name;
    int age;
    string house;
    int order;
};

wizard heap[10000];
int heap_size = 0;

void heapify(int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= heap_size){
        if(heap[left].age > heap[largest].age  || (heap[left].age == heap[largest].age && heap[left].order < heap[largest].order) ){
            largest = left;
        }
    }

    if(right <= heap_size){
        if(heap[right].age > heap[largest].age  || (heap[right].age == heap[largest].age && heap[right].order < heap[largest].order) ){
            largest = right;
        }
    }

    if(largest != i){
        swap(heap[i],heap[largest]);
        heapify(largest);
    }
}

void insertwizard(wizard w){
    heap_size++;
    heap[heap_size] = w;
    int i = heap_size;

    while(i > 1){
        if((heap[i].age > heap[i/2].age) || (heap[i].age == heap[i/2].age && heap[i].order < heap[i/2].order)){
            swap(heap[i], heap[i/2]);
            i = i/2;
        }
        else{
            break;
        }
    }
}

wizard extract(){
    wizard max_val = heap[1];
    heap[1] = heap[heap_size];
    heap_size--;

    heapify(1);
    return max_val;
}

int main(){

    char option;
    int count = 0;

    while(cin >> option){
        if(option == 'I'){
            wizard w;
            cin.ignore();
            getline(cin,w.name, ' ');
            string lastname;
            cin >> lastname;

            w.name += " " + lastname;
            cin >> w.age >> w.house;
            w.order = count++;
            insertwizard(w);
        }
        else if(option == 'S'){
            if(heap_size > 0){
                wizard serve = extract();
                cout << "Name:" << serve.name << ", Age:" << serve.age << ", House:" << serve.house << endl;
            }
        }
        else if(option == 'X'){
            break;
        }
    }
    return 0;
}