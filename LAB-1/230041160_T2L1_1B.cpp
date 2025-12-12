#include<iostream>
using namespace std;

int Factorial_using_iteration(long long n){
    long long factorial = 1;
    for(int i=1; i<=n; i++){
        factorial *= i;
    }
    return factorial;
}

int Factorial_using_recursion (long long n){
    if(n == 0 || n == 1) return 1;
    return n* Factorial_using_recursion(n-1);
}

int main(){
    long long n;
    cin >> n;

    long long iteration = Factorial_using_iteration(n);
    long long recursion = Factorial_using_recursion(n);
    cout << iteration << " " << "(using iteration)" << endl;
    cout << recursion << " " << "(using recursion)" << endl;
    return 0;
}