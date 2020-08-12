#include<iostream>
#define MAX 15
#define DOMAX 100
using namespace std;

struct Node{
    char toDo[MAX];
    int inDegree;
    int outDegree;
    bool sorted;
    Node(char *toDoIn): sorted(false), inDegree(0), outDegree(0){
        strcpy(toDo, toDoIn);
    }
    void print(){
        cout<<"== Node Info =="<<endl;
        cout<<"Task: "<<toDo<<endl;
        cout<<"Indegree: "<<inDegree<<endl;
        cout<<"Outdegree: "<<outDegree<<endl;
        cout<<"Sorted: "<<sorted<<endl;
    }
};
struct Edge{
    char preDo[MAX];
    char nextDo[MAX];
    bool useful;
    Edge(char *preDo, char *nextDo): useful(true){
        strcpy(this->preDo,preDo);
        strcpy(this->nextDo,nextDo);
    }
    void print(){
        cout<<"== Edge Info =="<<endl;
        cout<<preDo<<" -> "<<nextDo<<endl;
    }
};
template <typename T>
void printStruct(T **list, int nList){
    for(int index=0; index<nList; index++)
        list[index]->print();
}

void topologicalSort(int nTodoList, Node *todoList[DOMAX], int nEdge, Edge *adjacentMatrix[DOMAX]){
    /* 
     * 위상정렬 방법 1
     * 
     * topologicalSort(G){
     *     for 1->n{
     *         진입 간선 없는 임의의 점 u 선택
     *         A[i] => u
     *         정점 u와 u의 진출 간선 제거
     *     }
     *     위상 정렬 완료
     * }
     */
    
    int done = 0;
    while(done<nTodoList){
        int target=-1;
        // 진입 간선 없는 임의의 점 u 선택
        for(int todoListIndex=0; todoListIndex<nTodoList; todoListIndex++){
            if(todoList[todoListIndex]->sorted==false && todoList[todoListIndex]->inDegree == 0){
                target = todoListIndex;
                break;
            }
        }
        // 정점 u와 u의 진출 간선 제거 
        if(target!=-1){
            cout<<todoList[target]->toDo;
            char targetDo[MAX];
            strcpy(targetDo, todoList[target]->toDo);
            // 정점 제거 
            todoList[target]->sorted=true;
            //delete todoList[nTodoList-1];
            done++;
            // 해당 진출 간선 제거
            for(int edgeIndex=0; edgeIndex<nEdge; edgeIndex++){
                if(adjacentMatrix[edgeIndex]->useful==true && strcmp(adjacentMatrix[edgeIndex]->preDo,targetDo)==0){
                    for(int index=0; index<nTodoList; index++){
                        if(strcmp(todoList[index]->toDo,adjacentMatrix[edgeIndex]->nextDo)==0)
                            todoList[index]->inDegree--;
                    }
                    adjacentMatrix[edgeIndex]->useful = false;
                }
            }
            if(done<nTodoList)
                cout<<" - ";
        }
        // 진입 간선이 없는 점이 없는 경우 오류 
        else{
            cout<<"ERROR"<<endl;
            return;
        }
    }
}

int main(){
    Node *todoList[DOMAX]={nullptr};
    Edge *adjacentMatrix[DOMAX]={nullptr};
    int nTodoList=0, nEdge=0;
    cin>>nTodoList;
    cin.ignore();

    for(int todoListIndex=0; todoListIndex<nTodoList; todoListIndex++) {
        char toDo[MAX];
        cin.getline(toDo, MAX);
        todoList[todoListIndex] = new Node(toDo);
    }
    cin>>nEdge;
    cin.ignore();
    for(int edgeIndex=0; edgeIndex<nEdge; edgeIndex++){
        char preDo[MAX], nextDo[MAX];
        cin>>preDo>>nextDo;
        adjacentMatrix[edgeIndex] = new Edge(preDo, nextDo);
        for(int todoListIndex=0; todoListIndex<nTodoList; todoListIndex++){
            if(strcmp(todoList[todoListIndex]->toDo,preDo)==0)
                todoList[todoListIndex]->outDegree++;
            if(strcmp(todoList[todoListIndex]->toDo,nextDo)==0)
                todoList[todoListIndex]->inDegree++;
        }
    }
    // 입력 끝!
    //printStruct<Node>(todoList, nTodoList);
    //printStruct<Edge>(adjacentMatrix, nEdge);

    topologicalSort(nTodoList,todoList, nEdge, adjacentMatrix);
    
    return 0;
}
