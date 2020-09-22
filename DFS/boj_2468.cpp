#include<iostream>
#include<vector>
#include<cstring>
#define MAX 101

using namespace std;

const int dirX[] = {0,1,0,-1};
const int dirY[] = {1,0,-1,0};

int n, maxNum=0;
int arr[MAX][MAX];
bool visited[MAX][MAX] = {false,};
int limit, ans=0;
void dfs(int x, int y){
    for(int dir=0; dir<4; dir++){
        int nx = x+dirX[dir];
        int ny = y+dirY[dir];
        if(nx>=0 && nx<n && ny>=0 && ny<n && arr[nx][ny]>limit && !visited[nx][ny]){
            visited[nx][ny] = true;
            dfs(nx,ny);
        }
    }
}
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            maxNum = maxNum>arr[i][j]?maxNum:arr[i][j];
        }
    }
    for(limit=0; limit<=maxNum; limit++){
        memset(visited,false, sizeof(visited));
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j]>limit && !visited[i][j]) {
                    count++;
                    dfs(i, j);
                }
            }
        }
        ans = ans>count?ans:count;
    }
    cout<<ans;
}