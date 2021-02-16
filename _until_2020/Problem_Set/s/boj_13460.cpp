#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Loc{
    int x;
    int y;
    Loc(int x, int y):x(x), y(y){}
};

int dirX[] = {0,1,0,-1};
int dirY[] = {1,0,-1,0};

vector<vector<char>> arr;
int n,m;
Loc red(0,0);
Loc blue(0,0);
int res = 0;

Loc move(Loc r, Loc b, int dir){
    Loc cur = r;
    while(arr[cur.x][cur.y]!='#' && !(arr[b.x][b.y]!='O' && cur.x==b.x && cur.y==b.y)){
        r = cur;
        if(arr[r.x][r.y]=='O')
            break;
        cur.x = r.x+dirX[dir];
        cur.y = r.y+dirY[dir];
    }
    return r;
}
void play(Loc r, Loc b, int count){
    if(count>=10)
        return;
    count++;
    for(int dir=0; dir<4; dir++){
        Loc newr = r;
        Loc newb = b;
        // r,y가 이동하려는 방향으로 같은 줄에 있는 경우
        // 좌우 같은줄
        if(dir%2==0 && r.x==b.x){
            // 우
            if(dir==0){
                // BR->
                if(r.y>b.y){
                    newr = move(r,b,dir);
                    newb = move(b,newr,dir);
                }
                // RB->
                else{
                    newb = move(b,r,dir);
                    newr = move(r,newb,dir);
                }
            }
            // 좌
            else{
                // <-BR
                if(r.y>b.y){
                    newb = move(b,r,dir);
                    newr = move(r,newb,dir);
                }
                // <-RB
                else{
                    newr = move(r,b,dir);
                    newb = move(b,newr,dir);
                }
            }
        }
        // 위아래 같은줄
        else if(dir%2==1 && r.y==b.y){
            // 아래
            if(dir==1){
                // BR->
                if(r.x>b.x){
                    newr = move(r,b,dir);
                    newb = move(b,newr,dir);
                }
                // RB->
                else{
                    newb = move(b,r,dir);
                    newr = move(r,newb,dir);
                }
            }
            // 위
            else{
                // <-BR
                if(r.x>b.x){
                    newb = move(b,r,dir);
                    newr = move(r,newb,dir);
                }
                // <-RB
                else{
                    newr = move(r,b,dir);
                    newb = move(b,newr,dir);
                }
            }
        }
        // r,y가 다른 줄에 있는 경우
        else{
            newr = move(r,b,dir);
            newb = move(b,newr,dir);
        }

        if(newr.x==r.x && newr.y==r.y && newb.x==b.x && newb.y==b.y)
            continue;

        // red hole에 들어갔을때
        if(arr[newr.x][newr.y]=='O'){
            // blue도 hole에 들어가면 다른 방법 찾기
            if(arr[newb.x][newb.y]=='O')
                continue;
            // red만 hole에 들어가면 결과 값 작은거
            if(res==0) res = count;
            else res = count<res?count:res;
            return;
        }
        if(arr[newb.x][newb.y]=='O')
            continue;
        play(newr,newb,count);
    }
}
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        vector<char> tmp;
        string s; cin>>s;
        for(int j=0; j<m; j++){
            if(s[j]=='R'){
                red.x = i;
                red.y = j;
                tmp.push_back('.');
            }
            else if(s[j]=='B'){
                blue.x = i;
                blue.y = j;
                tmp.push_back('.');
            }
            else {
                tmp.push_back(s[j]);
            }
        }
        arr.push_back(tmp);
    }
    play(red,blue,0);

    if(res==0 || res>10) cout<<-1;
    else cout<<res;
}