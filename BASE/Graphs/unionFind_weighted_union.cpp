#include<iostream>

using namespace std;

struct Edge{
    char e1;
    char e2;
    Edge(char e1, char e2):e1(e1), e2(e2){}
};
struct SetItem{
    char origin;
    char parent;
    SetItem(char origin, char parent): origin(origin), parent(parent){}
};

int size[10] = {1};

char FIND_SET(char target, SetItem **set);

////////////////// 출력용 /////////////////////////////
///
void checkSet(SetItem *set[]){
    for(int i=0; i<10; i++)
        cout<<set[i]->origin<<" ";
    cout<<endl;
    for(int i=0; i<10; i++)
        cout<<set[i]->parent<<" ";
    cout<<endl;
}
void printSet(SetItem *set[]){
    bool done[10] = {false};
    bool head[10] = {false};
    for(int setIndex=0; setIndex<10; setIndex++){
        char headChar = set[setIndex]->parent;
        for(int subIndex=0; subIndex<10; subIndex++){
            if(set[subIndex]->origin == headChar)
                head[subIndex] = true;
        }
    }
    for(int index=0; index<10; index++){
        if(head[index]){
            char headChar = set[index]->origin;
            cout<<"{ ";
            for(int setIndex=0; setIndex<10; setIndex++){
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

SetItem **MAKE_SET(int index, char in, SetItem **set){
    *(set+index) = new SetItem(in, in);
    return set;
}
char FIND_SET(char target, SetItem **set){
    int targetIndex;
    for(int sIndex=0; sIndex<10; sIndex++){
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
SetItem **UNION(char e1, char e2, SetItem **set){
    char x = FIND_SET(e1, set);
    char y = FIND_SET(e2, set);
    int xIndex, yIndex;

    for(int sIndex=0; sIndex<10; sIndex++){
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

    return set;
}

void CONNECTED_COMPONENTS(char vertex[], Edge *edge[], SetItem *set[]){
    for(int vIndex=0; vIndex<10; vIndex++){
        set = MAKE_SET(vIndex, vertex[vIndex], set);
    }
    cout<<" INIT ";
    printSet(set);
    for(int eIndex=0; eIndex<7; eIndex++){
        if(FIND_SET(edge[eIndex]->e1, set) != FIND_SET(edge[eIndex]->e2, set))
            set = UNION(edge[eIndex]->e1,edge[eIndex]->e2, set);
        cout<<"("<<edge[eIndex]->e1<<'-'<<edge[eIndex]->e2<<") ";
        printSet(set);
        //checkSet(set);
    }
    return;
}

int main(){

    SetItem *set[10];
    char vertex[] = {'a','b','c','d','e','f','g','h','i','j'};
    Edge *edge[] = { new Edge('b','d'),
                     new Edge('e','g'),
                     new Edge('a','c'),
                     new Edge('h','i'),
                     new Edge('a','b'),
                     new Edge('e','f'),
                     new Edge('b','c')
                     };

    CONNECTED_COMPONENTS(vertex, edge, set);

    return 0;
}
