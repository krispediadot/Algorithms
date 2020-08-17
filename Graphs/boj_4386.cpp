#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define MAX 101

using namespace std;

struct Node{
    double x;
    double y;
    Node(double x, double y):x(x), y(y){}
};
struct Edge{
    int e1;
    int e2;
    double cost;
    Edge(int e1, int e2, double cost):e1(e1), e2(e2), cost(cost){}
};

int n,m;
Node *stars[MAX];
vector<Edge*>edge;
int p[MAX];
int size[MAX]={1};

void getInput(){
    cin>>n;
    for(int i=0; i<n; i++){
        float x,y;
        cin>>x>>y;
        stars[i] = new Node(x,y);
    }
}
double calcDist(int e1, int e2){
    return sqrt(pow(stars[e1]->x - stars[e2]->x,2) + pow(stars[e1]->y - stars[e2]->y,2));
}
bool compare(Edge *a, Edge *b){
    return a->cost < b->cost;
}
void updateEdge(){
    int nEdge=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            edge.push_back(new Edge(i,j,calcDist(i,j)));
        }
    }
    sort(edge.begin(), edge.end(), compare);
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
void printP(){
    for(int i=0; i<n; i++)
        cout<<p[i]<<" ";
    cout<<endl;
}
double kruskal(){
    double sum = 0;

    int nEdge=0;
    for(int i=0; i<(n*(n-1))/2; i++){
        //printP();
        if(nEdge==n-1)
            break;
        if(findSet(edge[i]->e1) != findSet(edge[i]->e2)){
            Union(edge[i]->e1, edge[i]->e2);
            sum += edge[i]->cost;
        }
    }
    return sum;
}
int main(){
    getInput();
    updateEdge();
    updateParent();

    cout.precision(2);
    cout<<fixed;
    cout<<kruskal()<<endl;

    return 0;
}
