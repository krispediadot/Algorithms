#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define MAX 200001
using namespace std;
struct Edge{
    int e1;
    int e2;
    int dist;
    Edge(int e1, int e2, int dist):e1(e1), e2(e2), dist(dist){}
};

int n,m, totalDist = 0;
vector<Edge*> edge;
int p[MAX];
int size[MAX] = {1};
bool compare(Edge *a, Edge *b){
    return a->dist < b->dist;
}
bool getInput(){
    cin >> n >> m;
    if(n==0 && m==0)
        return true;

    for (int i = 0; i < m; i++) {
        int e1, e2, dist;
        cin >> e1 >> e2 >> dist;
        edge.push_back(new Edge(e1, e2, dist));
        totalDist += dist;
    }
    sort(edge.begin(), edge.end(), compare);

    return false;
}
void updateParent(){
    for(int i=0; i<n; i++)
        p[i] = i;
}
int findSet(int x){
    if(x==p[x])
        return x;
    return p[x] = findSet(p[x]);
}
void Union(int e1, int e2){
    int p1 = findSet(e1);
    int p2 = findSet(e2);

    if(p1 != p2){
        if(size[p1]<size[p2]){
            p[p1] = p2;
            size[p2]+=size[p1];
        }
        else{
            p[p2] = p1;
            size[p1]+=size[p2];
        }
    }
}
int kruskal(){
    int sum=0;
    for(int i=0; i<m; i++){
        if(findSet(edge[i]->e1)!=findSet(edge[i]->e2)){
            Union(edge[i]->e1, edge[i]->e2);
            sum+=edge[i]->dist;
        }
    }
    return sum;
}
int main(){
    bool done = false;
    while(true) {
        edge.clear();
        memset(p, 0, sizeof(int)*MAX);
        memset(size, 1, sizeof(int)*MAX);
        totalDist = 0;

        done = getInput();
        if(done) break;
        updateParent();

        cout << totalDist - kruskal() << endl;
    }

    return 0;
}
