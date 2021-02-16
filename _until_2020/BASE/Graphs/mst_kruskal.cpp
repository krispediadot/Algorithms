#include<iostream>
#define MAX 100
using namespace std;

struct Edge{
    char e1;
    char e2;
    int cost;
    Edge(char e1, char e2, int cost):e1(e1), e2(e2), cost(cost){}
    void print(){
        cout<<"("<<e1<<","<<e2<<") "<<cost<<endl;
    }
};
struct SetItem{
    char origin;
    char parent;
    SetItem(char origin, char parent): origin(origin), parent(parent){}
};

int size[10] = {1};
int n, m;

char FIND_SET(char target, SetItem **set);

////////////////// 출력용 /////////////////////////////
///
void checkSet(SetItem *set[]){
    for(int i=0; i<n; i++)
        cout<<set[i]->origin<<" ";
    cout<<endl;
    for(int i=0; i<n; i++)
        cout<<set[i]->parent<<" ";
    cout<<endl;
}
void printSet(SetItem *set[]){
    bool done[MAX] = {false};
    bool head[MAX] = {false};
    for(int setIndex=0; setIndex<n; setIndex++){
        char headChar = set[setIndex]->parent;
        for(int subIndex=0; subIndex<n; subIndex++){
            if(set[subIndex]->origin == headChar)
                head[subIndex] = true;
        }
    }
    for(int index=0; index<n; index++){
        if(head[index]){
            char headChar = set[index]->origin;
            cout<<"{ ";
            for(int setIndex=0; setIndex<n; setIndex++){
                if(FIND_SET(set[setIndex]->origin, set) == headChar)
                    cout<<set[setIndex]->origin<<" ";
            }
            cout<<"} ";
        }
    }
    cout<<endl;
}
///
////////////////////////////////////////////////////////

void MAKE_SET(int index, char in, SetItem **set){
    *(set+index) = new SetItem(in, in);
}
char FIND_SET(char target, SetItem **set){
    int targetIndex;
    for(int sIndex=0; sIndex<n; sIndex++){
        if(set[sIndex]->origin == target) {
            targetIndex = sIndex;
            break;
        }
    }
    if(set[targetIndex]->parent != set[targetIndex]->origin){
        set[targetIndex]->parent = FIND_SET(set[targetIndex]->parent, set);
    }
    return set[targetIndex]->parent;
}
void Weighted_Union(char e1, char e2, SetItem **set){
    char x = FIND_SET(e1, set);
    char y = FIND_SET(e2, set);
    int xIndex, yIndex;

    for(int sIndex=0; sIndex<n; sIndex++){
        if(set[sIndex]->origin == x)
            xIndex = sIndex;
        if(set[sIndex]->origin == y)
            yIndex = sIndex;
    }

    if(size[xIndex] < size[yIndex]) {
        set[xIndex]->parent = y;
        size[y] = size[y] + size[x];
    }
    else{
        set[yIndex]->parent = x;
        size[x] = size[x] + size[y];
    }

}
void merge(Edge *arr[], int begin, int q, int end){
    Edge *a[end];
    int i=begin, j=q+1, k=begin;

    while(i<=q && j<=end){
        if(arr[i]->cost<=arr[j]->cost)
            a[k++] = arr[i++];
        else
            a[k++] = arr[j++];
    }
    int tmp = i>q? j:i;
    while(k<=end)
        a[k++] = arr[tmp++];
    for(int i=begin; i<=end; i++)
        arr[i] = a[i];
}
void mergeSort(Edge *arr[], int begin, int end) {
    if (begin < end) {
        int q = (begin + end) / 2;
        mergeSort(arr, begin, q);
        mergeSort(arr, q + 1, end);
        merge(arr, begin, q, end);
    }
}
void MST_Kruskal(char vertex[], Edge *edge[], SetItem *set[]){
    Edge **A = nullptr;
    int selectedEdge = 0;
    int sumEdgeCost = 0;

    for(int vIndex=0; vIndex<n; vIndex++){
        MAKE_SET(vIndex, vertex[vIndex], set);
    }
    mergeSort(edge, 0, m-1);

    for(int eIndex=0; eIndex<m; eIndex++){
        if(FIND_SET(edge[eIndex]->e1, set) != FIND_SET(edge[eIndex]->e2, set)) {
            cout<<"("<<edge[eIndex]->e1<<","<<edge[eIndex]->e2<<") cost: "<<edge[eIndex]->cost<<endl;
            if(selectedEdge==0)
                A = &edge[eIndex];
            else
                *(A + selectedEdge) = edge[eIndex];
            sumEdgeCost += edge[eIndex]->cost;
            selectedEdge++;
            Weighted_Union(edge[eIndex]->e1, edge[eIndex]->e2, set);
        }
        if(selectedEdge==n-1)
            break;
    }
    cout<<"Cost Sum: "<<sumEdgeCost<<endl;
    return;
}

int main(){
    n=9;
    m=14;
    SetItem *set[n];
    char vertex[] = {'a','b','c','d','e','f','g','h','i'};
    Edge *edge[] = { new Edge('a','b', 4),
                     new Edge('a','h', 8),
                     new Edge('b','c', 8),
                     new Edge('b','h', 11),
                     new Edge('c','d', 7),
                     new Edge('c','i', 2),
                     new Edge('c','f', 4),
                     new Edge('d','e', 9),
                     new Edge('d','f', 14),
                     new Edge('e','f', 10),
                     new Edge('f','g', 2),
                     new Edge('g','i', 6),
                     new Edge('g','h', 1),
                     new Edge('h','i', 7)
    };

    MST_Kruskal(vertex, edge, set);

    return 0;
}

