#include<iostream>
#include<queue>
#define SIZE 100
#define BLANK 0
#define WALL 1
#define GRAM 2
#define VISITED -1
using namespace std;

struct Node{
    int x;
    int y;
    Node(int x, int y): x(x), y(y){}
};

struct qItem{
    Node* loc;
    int t;
    bool gram;
    qItem(int x, int y, int t, bool gram): loc(new Node(x,y)), t(t), gram(gram){}
};

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};
int arr[2][SIZE][SIZE] = {0};
int N,M,T;
bool savePrincess = false;

int letsGo(){
    queue<qItem*> q;
    arr[0][0][0] = VISITED;
    q.push(new qItem(0,0,0, false));
    while(!q.empty()){
        qItem* target = q.front();
        q.pop();

        if(target->t>T)
            break;
        if(target->loc->x==N-1 && target->loc->y==M-1){
            savePrincess=true;
            return target->t;
        }

        for(int i=0; i<4; i++){
            int newX = target->loc->x+dirX[i];
            int newY = target->loc->y+dirY[i];

            int checkOption = 0;
            if(target->gram) checkOption = 1;

            if(newX>=0 && newX<N && newY>=0 && newY<M && arr[checkOption][newX][newY]!=VISITED){
                if(arr[checkOption][newX][newY]==WALL && target->gram==true) {
                    arr[checkOption][newX][newY]=VISITED;
                    q.push(new qItem(newX, newY, target->t + 1, target->gram));
                }
                if(arr[checkOption][newX][newY]==GRAM) {
                    arr[checkOption][newX][newY]=VISITED;
                    q.push(new qItem(newX, newY, target->t + 1, true));
                }
                if(arr[checkOption][newX][newY]==BLANK) {
                    arr[checkOption][newX][newY]=VISITED;
                    q.push(new qItem(newX, newY, target->t + 1, target->gram));
                }
            }
        }
    }
    return -1;
}

int main(){
    cin>>N>>M>>T;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[0][i][j];
            arr[1][i][j] = arr[0][i][j];
        }
    }

    int result = letsGo();

    if(savePrincess) cout<<result<<endl;
    else cout<<"Fail"<<endl;
    return 0;
}
