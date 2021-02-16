#include<iostream>
#include<vector>
#include<algorithm>
#define SIZE 100
using namespace std;

struct Node{
    int y;
    bool grouped;
public:
    Node(int y, bool grouped):y(y), grouped(grouped){}
};

vector<int> arr[SIZE];
vector<Node> grouped[SIZE];
int n,m,k;
int maxCount=0;

void debugging(){
    cout<<"=== DEBUGGING ==="<<endl;
    for(int i=0; i<n; i++){
        cout<<"["<<i<<"] ";
        for(int j=0; j<arr[i].size(); j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i=0; i<n; i++){
        cout<<"["<<i<<"] ";
        for(int j=0; j<grouped[i].size(); j++){
            cout<<grouped[i][j].y<<"-"<<grouped[i][j].grouped<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void getInput(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    //memset(grouped,false, SIZE);

    for(int i=0; i<k; i++){
        int a,b;
        cin>>a>>b;
        arr[a-1].push_back(b-1);
        grouped[a-1].push_back(Node(b-1,false));
    }

    for(int i=0; i<n; i++){
        sort(arr[i].begin(), arr[i].end());
    }

}
bool isYExist(int x, int y){
    for(int j=0; j<grouped[x].size(); j++){
        if(grouped[x][j].y == y)
            return true;
    }
    return false;
}
int getYIndex(int x, int y){
    for(int j=0; j<grouped[x].size(); j++){
        if(grouped[x][j].y == y)
            return j;
    }
    return -1;
}
int DFS(int x, int y){
    //cout<<"X: "<<x<<" Y: "<<y<<endl;
    //debugging();
    if(x<0 || x>=n || y<0 || y>=m || !isYExist(x,y)|| grouped[x][getYIndex(x,y)].grouped == true)
        return 0;

    grouped[x][getYIndex(x,y)].grouped = true;

    int count=1;
    //4방향 살펴서 들어가기
    // 아래
    count+=DFS(x+1, y);
    // 위
    count+=DFS(x-1, y);
    // 왼
    count+=DFS(x,y-1);
    // 오
    count+=DFS(x, y+1);

    if(count>maxCount)
        maxCount=count;
    return count;
}

void process(){
    for(int i=0; i<n; i++){
        for(int j=0; j<arr[i].size(); j++){
            if(!grouped[i][j].grouped)
                DFS(i,arr[i][j]);
        }
    }
}

int main() {
    getInput();
    //debugging();
    process();

    cout<<maxCount<<endl;

    return 0;
}
