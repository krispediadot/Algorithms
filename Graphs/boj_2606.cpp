#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<bool> nodes;
vector<vector<int> > adj;
int node_n, adj_n;

void checkInfection(){
    int count = 0;
    for(int i=0; i<node_n+1; i++){
        if(nodes[i] == true)
            count++;
    }
    cout<<count-1<<'\n';
}
void spread(int n){
    queue<int> q;
    nodes[n] = true;
    q.push(n);
    while(!q.empty()){
        int check = q.front();
        q.pop();
        for(auto it = adj[check].begin(); it!=adj[check].end(); ++it){
            if(nodes[*it] == false) {
                nodes[*it] = true;
                q.push(*it);
            }
        }
    }
}
void readData(){
    ios_base::sync_with_stdio(false);
    cin>>node_n;
    nodes.resize(node_n+1, false);
    adj.resize(node_n+1);
    cin>>adj_n;
    for(int i=0; i<adj_n; i++){
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int main(void) {

    readData();
    spread(1);
    checkInfection();

    return 0;
}
