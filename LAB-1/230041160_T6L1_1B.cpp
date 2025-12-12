#include<iostream>
using namespace std;

long long fibonacci_iteration(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;

    int a = 0, b = 1;
    for(int i=2; i<=n; i++){
        int c = a+b;
        a =b;
        b = c;
    }
    return b;
}

long long fibonacci_resursion(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;

    return fibonacci_resursion(n-1)+ fibonacci_resursion(n-2);
}
int main(){

    int n;
    cin >> n;

    cout << fibonacci_iteration(n-1)<< endl;
    cout << fibonacci_resursion(n-1) << endl;
    return 0;
}