#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAX 8
#define VIRUS 2

using namespace std;

const int dirX[] = {0,1,0,-1};
const int dirY[] = {1,0,-1,0};

int arr[MAX][MAX] = {0,};
int sub[MAX][MAX] = {0,};
int n,m, ans=0;

vector<pair<int,int>> v;

void printSub(int a[MAX][MAX]){
    cout<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void getInput(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j]==VIRUS) v.push_back(make_pair(i,j));
        }
    }
}
void bfs(int i, int j){
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    while(!q.empty()){
        pair<int,int> target = q.front();
        q.pop();

        for(int dir=0; dir<4; dir++){
            int nx = target.first+dirX[dir];
            int ny = target.second+dirY[dir];
            if(nx>=0 && nx<n && ny>=0 && ny<m && sub[nx][ny]==0){
                sub[nx][ny] = VIRUS;
                q.push(make_pair(nx,ny));
            }
        }
    }
}
void spreadVirus(){
    memset(sub, 0, sizeof(sub));
    for(int i=0 ;i<n; i++){
        for(int j=0; j<m; j++)
            sub[i][j] = arr[i][j];
    }

    for(int idx=0; idx<v.size(); idx++){
        bfs(v[idx].first, v[idx].second);
    }

    // 안전한 영역 세기
    int count=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(sub[i][j]==0) count++;
        }
    }
    ans = ans>count?ans:count;
}
void buildWall(int initI, int initJ, int cnt){
    if(cnt==3){
        spreadVirus();
        return;
    }
    for(int i=initI; i<n; i++){
        int j = i==initI?initJ+1:0;
        if(initI==0 && initJ==0) j=0;
        for(; j<m; j++){
            if(arr[i][j]==0) {
                arr[i][j] = 1;
                buildWall(i, j, cnt + 1);
                arr[i][j] = 0;
            }
        }
    }
}
int main(){
    getInput();
    //spreadVirus();
    buildWall(0,0,0);

    cout<<ans;

}