// 6087
#include<iostream>
#include<queue>
#define MIN(X,Y)(((X)<(Y))?(X):(Y))
#define SIZE 100

using namespace std;

struct Node{
    int x;
    int y;
    Node(int x, int y): x(x), y(y){}
};
struct qItem{
    Node* loc;
    int nLine;
    qItem(int x, int y, int nLine): loc(new Node(x,y)), nLine(nLine){}
};

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

char arr[SIZE][SIZE];
int lineCount[SIZE][SIZE]={0};
int w,h;
Node* from= nullptr;
Node* to= nullptr;

void bfs(){
    bool reachTo = false;
    queue<qItem*> q;
    lineCount[from->x][from->y] = 1;
    q.push(new qItem(from->x, from->y,1));

    while(!q.empty()){
        Node* target = q.front()->loc;
        int targetnLine = q.front()->nLine;
        q.pop();
        for(int i=0; i<4; i++){
            int newX = target->x+dirX[i];
            int newY = target->y+dirY[i];
            if(newX>=0 && newX<h && newY>=0 && newY<w && arr[newX][newY]!='*'){
                while(newX>=0 && newX<h && newY>=0 && newY<w && arr[newX][newY]!='*'){
                    if(newX==to->x && newY==to->y)
                        reachTo=true;
                    if(lineCount[newX][newY]!=0)
                        MIN(lineCount[newX][newY], targetnLine+1);
                    else {
                        if(!reachTo)
                            q.push(new qItem(newX, newY, targetnLine+1));
                        lineCount[newX][newY] = targetnLine + 1;
                    }
                    newX = newX+dirX[i];
                    newY = newY+dirY[i];
                }
            }
        }
    }
    return;
}

int main(){
    cin>>w>>h;
    cin.ignore();
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>arr[i][j];
            if(arr[i][j]=='*') lineCount[i][j] = -1;
            if(arr[i][j]=='C') {
                if(from== nullptr) from = new Node(i,j);
                else to = new Node(i,j);
            }
        }
    }
    // 입력 끝!
    bfs();

    cout<<lineCount[to->x][to->y]-2<<endl;
    return 0;

}
