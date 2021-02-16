#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1001
#define W -1
#define M -2

using namespace std;

struct Node{
    int index;
    int gender;
    Node(int index, int gender):index(index), gender(gender){}
};
struct Edge{
    int e1;
    int e2;
    int cost;
    Edge(int e1, int e2, int cost):e1(e1), e2(e2), cost(cost){}
    void print(){
        cout<<"("<<e1<<","<<e2<<") "<<cost<<endl;
    }
};

int n,m;
Node* vertices[MAX] ={nullptr};
vector<Edge*> edge;
int p[MAX];
int size[MAX]={1};

int findSet(int x){
    if(x==p[x])
        return x;
    return p[x] = findSet(p[x]);
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
bool isMixGender(int a, int b){
    if(vertices[a]->gender != vertices[b]->gender)
        return true;
    return false;
}
bool cmp(Edge *a, Edge *b){
    return a->cost < b->cost;
}
void printP(){
    for(int i=1; i<=n; i++) cout<<p[i]<<" ";
    cout<<endl;
}
int MST_Kruskal(){
    int sum=0, nE=0;
    for(int i=1; i<=n; i++) p[i] = i;

    sort(edge.begin(), edge.end(), cmp);
    //for(int i=0; i<edge.size(); i++) edge[i]->print();
    //cout<<endl;
    for(int i=0; i<edge.size(); i++){
        if(nE==n-1)
            break;

        if(isMixGender(edge[i]->e1, edge[i]->e2) && findSet(edge[i]->e1)!=findSet(edge[i]->e2)){
            //edge[i]->print();
            Union(edge[i]->e1, edge[i]->e2);
            sum+=edge[i]->cost;
            nE++;
            //printP();
        }
    }

    if(nE==n-1) return sum;
    return -1;
}
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        char gender;
        cin>>gender;
        if(gender=='W')
            vertices[i] = new Node(i, W);
        else
            vertices[i] = new Node(i, M);
    }
    for(int i=0; i<m; i++){
        int e1, e2, cost;
        cin>>e1>>e2>>cost;
        edge.push_back(new Edge(e1, e2, cost));
    }

    cout<<MST_Kruskal()<<endl;

    return 0;
}
