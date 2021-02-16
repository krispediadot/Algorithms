#include<iostream>
#define SIZE 1001
#define MAX 100000
using namespace std;
int n,m;

using namespace std;

struct Edge{
    int e1;
    int e2;
    int cost;
    Edge(int e1, int e2, int cost):e1(e1), e2(e2), cost(cost){}
    void print() {
        cout<<"("<<e1<<"-"<<e2<<") "<<cost<<endl;
    }
};
void merge(Edge **edge, int begin, int end){
    Edge *sub[MAX];

    int q = (begin+end)/2;
    int i=begin;
    int j=q+1;
    int k=begin;
    while(i<=q && j<=end){
        if(edge[i]->cost<edge[j]->cost)
            sub[k++] = edge[i++];
        else
            sub[k++] = edge[j++];
    }
    int tmp = i>q?j:i;

    while(k<=end){
        sub[k++] = edge[tmp++];
    }
    for(int i=begin; i<=end; i++)
        edge[i] = sub[i];
}
void mergeSort(Edge **edge, int begin, int end){
    if(begin<end){
        int q=(begin+end)/2;
        mergeSort(edge, begin, q);
        mergeSort(edge, q+1, end);
        merge(edge, begin, end);
    }
}
int find(int *p, int x){
    if(x==p[x])
        return x;
    return p[x] = find(p, p[x]);
}
int main(){
    int p[SIZE];
    Edge *edge[MAX];
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        p[i] = i;
    for(int i=0; i<m; i++){
        int e1, e2, cost;
        cin>>e1>>e2>>cost;
        edge[i] = new Edge(e1, e2, cost);
    }
    mergeSort(edge, 0, m-1);
    //for(int i=0; i<m; i++) edge[i]->print();

    int sumCost=0;
    for(int i=0; i<m; i++){
        int p1 = find(p, edge[i]->e1);
        int p2 = find(p, edge[i]->e2);

        if(p1==p2)
            continue;
        if(p1<p2) p[p1] = p2;
        else p[p2] = p1;
        sumCost+=edge[i]->cost;
    }
    cout<<sumCost<<endl;

    return 0;
}
