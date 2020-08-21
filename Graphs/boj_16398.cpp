#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1001

using namespace std;

struct Edge{
    int e1;
    int e2;
    long long cost;
    Edge(int e1, int e2, long long cost):e1(e1), e2(e2), cost(cost){}
};

vector<Edge*> edge;
int p[MAX];
int size[MAX]={1};
int n;

void getInput(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            long long num;
            cin>>num;
            if(i<j){
                edge.push_back(new Edge(i,j,num));
            }
        }
    }
}
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
    return a->cost < b->cost;
}
long long MST_Kruskal(){
    long long sum=0;
    int nE=0;
    for(int i=0; i<n; i++) p[i] = i;

    sort(edge.begin(), edge.end(), cmp);

    for(int i=0; i<edge.size(); i++){
        if(nE==n-1)
            break;

        if(findSet(edge[i]->e1) != findSet(edge[i]->e2)){
            Union(edge[i]->e1, edge[i]->e2);
            sum+=edge[i]->cost;
            nE++;
        }
    }
    if(nE==n-1)return sum;
    return NULL;
}
int main(){
    cin>>n;
    getInput();

    cout<<MST_Kruskal()<<endl;

    return 0;
}
