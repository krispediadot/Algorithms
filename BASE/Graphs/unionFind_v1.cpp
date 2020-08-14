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
                if(set[setIndex]->parent == headChar)
                    cout<<set[setIndex]->origin<<" ";
            }
            cout<<"} ";
        }
    }
    cout<<endl;
}

SetItem **MAKE_SET(int index, char in, SetItem **set){
    *(set+index) = new SetItem(in, in);
    return set;
}
char FIND_SET(char target, SetItem **set){
    for(int setIndex=0; setIndex<10; setIndex++){
        if(set[setIndex]->origin == target)
            return set[setIndex]->parent;
    }
    return NULL;
}
SetItem **UNION(char e1, char e2, SetItem **set){
    for(int setIndex=0; setIndex<10; setIndex++){
        if(set[setIndex]->parent == e2) {
            set[setIndex]->parent = e1;
        }
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
