#include<iostream>
#include<stack>
#include<string>
using namespace std;


int main(){

    string s;
    string t;

    cin >> s >> t;

    int m = s.size();
    int n = t.size();

    if(n != m){
        cout << "No"<<endl;
        return 0;
    }
    string rotated = s;
    
    for(int i=0; i<m; i++){
        if(rotated == t){
            if(i == 0){
                cout << "Yes. Rotation not needed."<< endl;
                
            }
            else{
                cout << "Yes. After" << i <<"clockwise rotations" ;
            }
            return 0;
        }
        rotated = rotated[n-1] + rotated.substr(0,n-1);
    }
    cout << "No"<<endl;
    return 0;
}