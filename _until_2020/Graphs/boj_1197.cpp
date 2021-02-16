#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100000

using namespace std;

struct Edge{
    int e1;
    int e2;
    int cost;
    Edge(int e1, int e2, int cost):e1(e1), e2(e2), cost(cost){}
    void print(){cout<<"("<<e1<<","<<e2<<") "<<cost<<endl;}
};

int n,m;
int p[MAX];
int size[MAX]={1};
vector<Edge*> edge;
int vertex[MAX];

bool compare(Edge* a, Edge* b){
    return a->cost < b->cost;
}
int findIndex(int e){
    for(int i=0; i<n; i++){
        if(vertex[i]==e)
            return i;
    }
    return NULL;
}
int find(int x){
    if(x==p[findIndex(x)])
        return x;
    return p[findIndex(x)] = find(p[findIndex(x)]);
}
void Union(int e1, int e2){
    int p1 = find(e1);
    int p2 = find(e2);

    if(p1!=p2){
        if(size[findIndex(p1)]<size[findIndex(p2)]) {
            p[findIndex(p1)] = p[findIndex(p2)];
            size[findIndex(p2)]+=size[findIndex(p1)];
        }
        else{
            p[findIndex(p2)] = p[findIndex(p1)];
            size[findIndex(p1)]+=size[findIndex(p2)];
        }
    }
}
void printP(){
    cout<<"=== PARENT =="<<endl;
    for(int i=0; i<n; i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
}
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++)
        vertex[i] = i+1;

    for(int i=0; i<m; i++){
        int e1, e2, cost;
        cin>>e1>>e2>>cost;
        edge.push_back(new Edge(e1, e2, cost));
    }
    sort(edge.begin(), edge.end(), compare);

    //for(auto it: edge) it->print();
    // parent 초기화
    for(int i=0; i<n; i++){
        p[i] = vertex[i];
    }
    int sum=0;
    for(int i=0; i<m; i++){
        if(find(edge[i]->e1) != find(edge[i]->e2)){
            //cout<<"("<<edge[i]->e1<<","<<edge[i]->e2<<") "<<edge[i]->cost<<endl;
            Union(edge[i]->e1, edge[i]->e2);
            sum+=edge[i]->cost;
            //printP();
        }
    }
    cout<<sum<<endl;

    return 0;
}
