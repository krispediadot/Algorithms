#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#define MAX 17
#define ENEMY 1

using namespace std;

struct Loc{
    int x;
    int y;
    Loc(int x, int y):x(x),y(y){}
    void print(){cout<<"[LOC] "<<x<<","<<y<<endl;}
    bool operator== (const Loc& a){
        return x==a.x && y==a.y;
    }
};

int dirX[] = {0,-1,0,1};
int dirY[] = {-1,0,1,0};

int n,m,d, ans=0;
int maze[MAX][MAX];
vector<Loc> enemies;
vector<Loc> tempEnemies;

void printMaze(){
    int ma[MAX][MAX] = {0,};
    for(int idx=0; idx<tempEnemies.size(); idx++){
        ma[tempEnemies[idx].x][tempEnemies[idx].y] = 1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<ma[i][j]<<" ";
        }
        cout<<endl;
    }
}
int calcDist(Loc l1, Loc l2){
    int res1 = l1.x-l2.x;
    if(res1<0) res1*=-1;
    int res2 = l1.y-l2.y;
    if(res2<0) res2*=-1;
    return res1+res2;
}
void getInput(){
    cin>>n>>m>>d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>maze[i][j];
            if(maze[i][j]==ENEMY)
                enemies.push_back(Loc(i,j));
        }
    }
}
int findNearestIndex(Loc killer){
    struct qItem{
        Loc loc;
        int step;
        qItem(int x, int y, int step):loc(x,y),step(step){}
    };
    queue<qItem> q;
    q.push(qItem(killer.x, killer.y, 0));
    while(!q.empty()){
        qItem target = q.front();
        q.pop();
        if(target.step > d)
            break;
        for(int dir=0; dir<4; dir++){
            int nextx = target.loc.x+dirX[dir];
            int nexty = target.loc.y+dirY[dir];
            auto it = find(tempEnemies.begin(), tempEnemies.end(), Loc(nextx,nexty));
            if(target.step < d && it!=tempEnemies.end())
                return  it-tempEnemies.begin();
            if(nextx>=0 && nextx<n && nexty>=0 && nexty<m)
                q.push(qItem(nextx,nexty,target.step+1));
        }
    }
    return -1;
}
void moveEnemies(){
    for(int idx=tempEnemies.size()-1; idx>=0; idx--){
        tempEnemies[idx].x++;
        if(tempEnemies[idx].x>=n)
            tempEnemies.erase(tempEnemies.begin()+idx);
    }
}
int simulation(vector<Loc> killers){
    // 1. 기본 세팅(죽일 수 있는 적, 적의 위치)
    int totalKill = 0;
    tempEnemies.clear();
    for(int idx=0; idx<enemies.size(); idx++){
        tempEnemies.push_back(enemies[idx]);
    }
    // 2. 시간제한(행의 길이) 동안 죽이기
    int timeLimit = n;
    while(timeLimit>0 && tempEnemies.size()>0){
        // 2-1. 각 궁수들의 타겟 확인(중복으로 죽일 수 있으니 set)
        set<int, greater<int>> target;
        for(int idx=0; idx<3; idx++){
            int eachTargetIndex = findNearestIndex(killers[idx]);
            if(eachTargetIndex!=-1)
                target.insert(eachTargetIndex);
        }
        // 2-2. 각 시간마다 죽일 수 있는 적의 수 계산
        totalKill+=target.size();
        // 2-3. 죽이기
        for(auto i=target.begin(); i!=target.end(); i++){
            int targetIdx = *i;
            tempEnemies.erase(tempEnemies.begin()+targetIdx);
        }
//        cout<<"== AFTER KILL == "<<endl;
//        printMaze();
        // 2-4. 적 이동
        moveEnemies();
        // 2-5. 시간 줄어듬
        timeLimit--;
//        cout<<"== MOVE =="<<endl;
//        printMaze();
    }
    // 3. 전체 죽인 수 리턴
    return totalKill;
}
void setKiller(int y, vector<Loc> killers){
    if(killers.size()==3){
        int res = simulation(killers);
        ans = res>ans?res:ans;
        return;
    }
    for(int j=y; j<m; j++){
        Loc newKiller(n,j);
        killers.push_back(newKiller);
        setKiller(j+1,killers);
        killers.pop_back();
    }
}
int main(){
    getInput();
    vector<Loc> killers;
    setKiller(0,killers);
    cout<<ans;
    return 0;
}