#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<char>> arr;
    for(int i=0; i<n; i++){
        vector<char> tmp;
        string s; cin>>s;
        for(auto c:s){tmp.push_back(c);}
        arr.push_back(tmp);
    }
    int max = 0;
    for(int i=0; i<n; i++){
        stack<int> st;
        bool conn[51] = {false,};
        int count = 0;

        conn[i] = true;
        for(int j=0; j<n; j++){
            if(arr[i][j]=='Y') {
                st.push(j);
                count++;
                conn[j] = true;
            }
        }
        while(!st.empty()){
            int target = st.top();
            st.pop();
            for(int j=0; j<n; j++){
                if(arr[target][j]=='Y' && !conn[j]) {
                    count++;
                    conn[j] = true;
                }
            }
        }
        max = max>count?max:count;
    }
    cout<<max;
}