#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#define MAX 51

using namespace std;

struct Loc{
    int x;
    int y;
    Loc(int x, int y):x(x),y(y){}
};
struct Operand{
    Loc loc;
    int step;
    Operand(int x, int y, int step):loc(x,y),step(step){}
    void print(){
        cout<<"[Operand]: "<<loc.x<<","<<loc.y<<"-"<<step<<endl;
    }
};
int dirX[] = {1,0,-1,0};
int dirY[] = {0,1,0,-1};

int ma[MAX][MAX]={0,};
int temp[MAX][MAX]={0,};
int n,m,k,ans=INT_MAX;
vector<Operand> op;

void getInput(){
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>ma[i][j];
        }
    }
    for(int i=0; i<k; i++){
        int r,c,s; cin>>r>>c>>s;
        op.push_back(Operand(r,c,s));
    }
}
void printM(){
    cout<<"======"<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
}
void turn(Loc loc, int step){
    //printM();
    Loc cur(loc.x-step, loc.y-step);
    int len = 2*step;
    int tmp = temp[cur.x][cur.y];

    for(int dir=0; dir<4; dir++){
        for(int i=0; i<len; i++){
            int nextX = cur.x+dirX[dir];
            int nextY = cur.y+dirY[dir];
            temp[cur.x][cur.y] = temp[nextX][nextY];
            cur.x = nextX;
            cur.y = nextY;
            //printM();
        }
    }
    temp[cur.x][cur.y+1] = tmp;
    //printM();
}
int getMinRowSum(){
    int min = 0;
    for(int j=1; j<=m; j++) min+=temp[1][j];
    for(int i=2; i<=n; i++){
        int tmp=0;
        for(int j=1; j<=m; j++){
            tmp+=temp[i][j];
        }
        min = tmp<min?tmp:min;
    }
    return min;
}
// 순서 정해지면 계산
int calc(vector<Operand> opList) {
    memset(temp, 0, sizeof(temp));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            temp[i][j] = ma[i][j];
        }
    }
    // 연산 실행
    for(int idx=0; idx<k; idx++){
        for(int step=1; step<=opList[idx].step; step++){
            //opList[idx].print();
            turn(opList[idx].loc, step);
        }
    }
    // 배열 값 구하기
    return getMinRowSum();
}

// 연산 순서 정하기
void setOperand(vector<Operand> opList, bool done[MAX]){
    // 순서 정해지면 계산
    if(opList.size()==k){
        int res = calc(opList);
        ans = res<ans?res:ans;
        return;
    }
    for(int i=0; i<k; i++){
        if(!done[i]){
            opList.push_back(op[i]);
            done[i] = true;
            setOperand(opList, done);
            done[i] = false;
            opList.pop_back();
        }
    }
}

int main(){
    // 입력
    getInput();
    vector<Operand> opList;
    bool done[MAX] = {false,};
    // 연산 순서 정하기
    setOperand(opList, done);
    cout<<ans;

    return 0;
}