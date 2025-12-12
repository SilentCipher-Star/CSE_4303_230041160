#include<iostream>
#include<string>
#include<stack>
using namespace std;

string extract_tag(string tag){

    if(tag[1] == '/'){
        return (tag.substr(2,tag.size() - 3));
    }else{
        return (tag.substr(1,tag.size()- 2));
    }
}
int main(){

    int n;
    cin >> n;
    cin.ignore();
    
    stack<string>st;
    bool error_found = false;
    int error_line = -1;

    for(int l=1; l <=n; l++){
        string text;
        getline(cin, text);

        for(int i=0; i < text.size(); i++){

            if(text[i] == '<'){
                int j = i;
    
                while(j < text.size() && text[j] != '>'){
                    j++;
                }

                if(j == text.size()) continue;

                string tag = text.substr(i, j-i+1);
                string name = extract_tag(tag);

                if(tag[1] == '/'){
                    if(st.empty()){
                        error_found  = true;
                        error_line = l;
                        break; 
                    }
                    if(st.top() != name){
                        error_found  = true;
                        error_line = l;
                        break; 
                    }
                    st.pop();
                }else{
                    st.push(name);
                }
                i =j;
            }
        }

        if(error_found){
            break;
        }   
        
    }

    if(!error_found && !st.empty()){
        error_found = true;
        error_line = n;
    }

    if(!error_found){
        cout << "No error" << endl;
    }else{
        cout << "Error at Line" <<" "<<error_line << endl;
    }
    return 0;
}