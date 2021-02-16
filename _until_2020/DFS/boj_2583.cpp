#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 101

using namespace std;

const int dirX[] = {0,1,0,-1};
const int dirY[] = {1,0,-1,0};

int arr[MAX][MAX] ={0,};
bool visited[MAX][MAX]={false,};
int n,m,k;
vector<int> ans;

void dfs(int i,int j){
    visited[i][j] = true;
    ans.back()++;
    for(int dir=0; dir<4; dir++){
        int nx = i+dirX[dir];
        int ny = j+dirY[dir];
        if(nx>=0 && nx<n && ny>=0 && ny<m && arr[nx][ny]==0 && !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main(){
    cin>>n>>m>>k;
    int basex = n-1;
    int basey = 0;
    for(int i=0; i<k; i++){
        int lbx, lby, rux, ruy; cin>>lby>>lbx>>ruy>>rux;
        int w = rux-lbx;
        int h = ruy-lby;
        for(int x=0; x<w; x++){
            for(int y=0; y<h; y++){
                arr[basex-lbx-x][basey+lby+y] = 1;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            if(arr[i][j]==0 && !visited[i][j]) {
                ans.push_back(0);
                dfs(i, j);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<endl;

    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}