#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100001

using namespace std;

struct Edge{
    int e1;
    int e2;
    int cost;
    Edge(int e1, int e2, int cost):e1(e1), e2(e2), cost(cost){}
    void print() {
        cout<<"("<<e1<<","<<e2<<") "<<cost<<endl;
    }
};

vector<Edge*> edge;
int p[MAX];
int size[MAX]={1};
int n,m,s,e;

int findSet(int x){
    if(x==p[x])
        return x;
    return p[x]=findSet(p[x]);
}
void Union(int e1, int e2){
    int p1 = findSet(e1);
    int p2 = findSet(e2);
    if(p1!=p2){
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
bool cmp(Edge *a, Edge *b){
    return a->cost > b->cost;
}
void printP(){
    for(int i=1; i<=n; i++) {
        cout << p[i] << " ";
    }
    cout<<endl;
}
int MST_Kruskal(){
    int nE=0, minWeight=0;
    for(int i=1; i<=n; i++) p[i]=i;

    sort(edge.begin(), edge.end(), cmp);
    //for(int i=0; i<m; i++) edge[i]->print();

    minWeight=edge[0]->cost;

    for(int i=0; i<edge.size(); i++){
        if(nE==n-1 || findSet(s)==findSet(e))
            break;

        if(findSet(edge[i]->e1)!= findSet(edge[i]->e2)){
            //cout<<"("<<edge[i]->e1<<","<<edge[i]->e2<<") "<<edge[i]->cost<<endl;
            Union(edge[i]->e1, edge[i]->e2);
            nE++;
            minWeight=edge[i]->cost;
            //printP();
        }
    }
    if(findSet(s)==findSet(e)) return minWeight;
    return 0;
}
int main(){
    cin>>n>>m;
    cin>>s>>e;
    for(int i=0; i<m; i++){
        int e1, e2, cost;
        cin>>e1>>e2>>cost;
        edge.push_back(new Edge(e1, e2, cost));
    }

    cout<<MST_Kruskal()<<endl;

    return 0;
}
