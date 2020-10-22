#include<iostream>
#define MAX 17
#define WALL 1
using namespace std;

struct Loc{
    int x;
    int y;
    Loc(int x, int y):x(x), y(y){}
};

int dirX[] = {0,1,1};
int dirY[] = {1,1,0};
int home[MAX][MAX] = {0,};
int n, ans = 0;

void getInput(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            cin>>home[i][j];
    }
}
bool check(int newx, int newy){
    if (newx > 0 && newx <= n && newy > 0 && newy <= n && home[newx][newy] != WALL)
        return true;
    return false;
}
void dfs(Loc p, int d){
    if(p.x==n && p.y==n) {
        ans++;
        return;
    }
    for(int dir=0; dir<3; dir++){
        if(d==0&&dir==2)continue;
        if(d==2&&dir==0)continue;
        int newx = p.x + dirX[dir];
        int newy = p.y + dirY[dir];
        if(dir==1){
            if (check(newx, newy) && check(newx-1, newy) && check(newx, newy-1)) {
                Loc newp(newx, newy);
                dfs(newp, dir);
            }
        }
        else {
            if (check(newx,newy)) {
                Loc newp(newx, newy);
                dfs(newp, dir);
            }
        }
    }
}

int main(){
    getInput();
    Loc cur(1,2);
    dfs(cur, 0);
    cout<<ans;

    return 0;
}