#include<iostream>
#include<vector>
#include<stack>
#define VISITED -1
using namespace std;

const int dirX[] = {0,1,0,-1};
const int dirY[] = {1,0,-1,0};

vector<vector<int>> arr;
int m,n;

void dfs(int i,int j){
    stack<pair<int,int>> st;
    st.push(make_pair(i,j));
    while(!st.empty()){
        pair<int, int> target = st.top();
        st.pop();
        for(int dir=0; dir<4; dir++){
            int nx = target.first+dirX[dir];
            int ny = target.second+dirY[dir];
            if(nx>=0 && nx<n && ny>=0 && ny<m && arr[nx][ny]==1){
                st.push(make_pair(nx,ny));
                arr[nx][ny] = VISITED;
            }
        }
    }
}

int main(){
    int t; cin>>t;
    for(int tt=0; tt<t; tt++) {
        for(int i=0; i<arr.size(); i++) arr[i].clear();
        arr.clear();
        int k;
        cin >> m >> n >> k;
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            for (int j = 0; j < m; j++) tmp.push_back(0);
            arr.push_back(tmp);
        }
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]==1){
                    dfs(i,j);
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}