#include<iostream>
#include<altorighm>
#include<vector>
#define MAX 10

using namespace std;
struct Loc{
    int x;
    int y;
    Loc(int x, int y):x(x), y(y){}
    bool operator== (const Loc& a){
        return x==a.x && y==a.y;
    }
};

int maze[MAX][MAX];
vector<Loc> ones;
vector<int> eachLeft(6,5);
int ans = 26;

void getInput(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin>>maze[i][j];
            if(maze[i][j]==1)
                ones.push_back(Loc(i,j));
        }
    }
}
bool putableCover(Loc cur, int size, vector<Loc> one){
    for(int i=cur.x; i<cur.x+size; i++){
        for(int j=cur.y; j<cur.y+size; j++){
            if(find(one.begin(), one.end(), Loc(i,j))==one.end())
                return false;
        }
    }
    return true;
}
vector<Loc> attachCover(Loc cur, int size, vector<Loc> one){
    for(int i=cur.x; i<cur.x+size; i++){
        for(int j=cur.y; j<cur.y+size; j++){
            auto it = find(one.begin(), one.end(), Loc(i,j));
            one.erase(it);
        }
    }
    return one;
}
void dfs(Loc cur, int count, vector<Loc> one, vector<int> left){
    if(cur.x>=10) {
        if(one.size()==0)
            ans = count<ans?count:ans;
        return;
    }
    if(count>ans) return;

    // 0.다음 이동할 위치 계산
    int nextX = cur.x;
    int nextY = cur.y+1;
    if(nextY>=10){
        nextY=0;
        nextX++;
    }
    // 현재 위치가 1인 경우
    if(find(one.begin(), one.end(), cur)!=one.end()){
        for(int size=5; size>=1; size--){
            if(left[size]==0) continue;
            if(putableCover(cur, size, one)){
                vector<Loc> attachResult = attachCover(cur, size, one);
                left[size]--;
                dfs(Loc(nextX, nextY), count+1, attachResult, left);
                left[size]++;
            }
        }
    }
    // 현재 위치가 1이 아닌 경우
    else{
        dfs(Loc(nextX, nextY), count, one, left);
    }
}
int main(){
    getInput();
    eachLeft[0]=0;
    dfs(Loc(0,0), 0, ones, eachLeft);
    if(ans==26) ans=-1;
    cout<<ans;

    return 0;
}
