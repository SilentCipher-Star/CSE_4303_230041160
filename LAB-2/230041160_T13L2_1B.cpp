#include<iostream>
#include<string>

using namespace std;
int main(){

    string str;
    cin >> str;

    int open = 0;
    int pair = 0;

    for(char c: str){
        if(c == '('){
            open++;
        }else{
            if(open > 0){
                pair++;
                open--;
            }
        }
    }
    cout << pair*2 << endl;
    return 0;
}