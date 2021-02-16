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
    void print(){cout<<"("<<e1<<","<<e2<<") "<<cost<<endl;}
};

int n,m;
vector<Edge*> edge;
int vertex[MAX];
int p[MAX];
int size[MAX]={1};

int find(int x){
    if(x==p[x])
        return x;
    return p[x] = find(p[x]);
}
void Union(int e1, int e2){
    int p1 = find(e1);
    int p2 = find(e2);

    if(p1 != p2){
        if(size[p1] <= size[p2]){
            p[p1] = p2;
            size[p2]+=size[p1];
        }
        else{
            p[p2] = p1;
            size[p1]+=size[p2];
        }
    }
}
bool compare(Edge *a, Edge *b){
    return a->cost < b->cost;
}
void printP(){
    cout<<"=== parent ==="<<endl;
    for(int i=0; i<n; i++)
        cout<<p[i]<<" ";
    cout<<endl;
}
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++) vertex[i] = i;
    for(int i=0; i<m; i++){
        int e1, e2, cost;
        cin>>e1>>e2>>cost;
        edge.push_back(new Edge(e1, e2, cost));
    }
    sort(edge.begin(), edge.end(), compare);
    //for(int i=0; i<m; i++) edge[i]->print();
    //cout<<endl;

    for(int i=1; i<=n; i++){
        p[i] = i;
    }
    int sum=0;
    int max=-1;
    int nEdge=0;
    for(int i=0; i<m ;i++){
        if(nEdge==n-1)
            break;
        if(find(edge[i]->e1)!=find(edge[i]->e2)){
            //cout<<"("<<edge[i]->e1<<","<<edge[i]->e2<<") "<<edge[i]->cost<<endl;
            Union(edge[i]->e1, edge[i]->e2);
            if(sum>0 && edge[i]->cost > max)
                max = edge[i]->cost;
            if(sum==0)
                max = edge[i]->cost;
            sum+=edge[i]->cost;
            nEdge++;
            //printP();
        }
    }
    cout<<sum-max<<endl;

    return 0;
}
