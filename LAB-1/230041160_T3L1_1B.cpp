#include<iostream>
#include<vector>
using namespace std;

int Iterative_binary_search(int x, int arr[],int n){
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low+high)/2;

        if(arr[mid] == x){
            return mid;
        }
        else if(arr[mid] < x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

int Recursive_binary_search(int x, int arr[], int low, int high){
   
    if(low > high) return -1;
    int mid = (low+high)/2;
    if(arr[mid] == x){
        return mid;
    }
    else if(arr[mid] < x){
        return Recursive_binary_search(x,arr,mid+1,high);
    }
    else{
        return Recursive_binary_search(x,arr,low,mid-1);
    }
    
}
int main(){

    int num,n=0,arr[100];

    while(true){
        cin >> num;
        if(num < 0) break;
        arr[n++] = num;
    }
    int target;
    cin >> target;
    
    int binary = Iterative_binary_search(target, arr, n);
    int recursion = Recursive_binary_search(target,arr,0,n);

    cout << binary << " " << "(using iteration)" << endl;
    cout << recursion << " " << "(using recursion)" << endl;

    return 0;
}