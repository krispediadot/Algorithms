#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define SIZE 10001
#define DEFAULT 0
using namespace std;

vector<int> result;
vector<int> arr[SIZE];
int computer[SIZE]={DEFAULT};
bool visited[SIZE];
int n, m;

void getInput(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        arr[b].push_back(a);
    }
}
int DFS(int index){
    visited[index] = true;
    int count=1;
    for(int i=0; i<arr[index].size(); i++){
        if(!visited[arr[index][i]])
            count+=DFS(arr[index][i]);
    }
    computer[index] = count;
    return computer[index];
}
void process(){
    int max = 0;
    for(int i=1; i<=n; i++) {
        memset(visited,false, SIZE);
        int res = DFS(i);
        if(res>max) {
            max = res;
            result.clear();
            result.push_back(i);
        }
        else if(res==max)
            result.push_back(i);
    }
}
void printResult(){
    sort(result.begin(), result.end());
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
}
int main(){
    getInput();
    process();
    printResult();

    return 0;
}
