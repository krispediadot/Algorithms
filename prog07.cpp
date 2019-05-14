#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>

#define PI acos(-1.0)

using namespace std;

class Node{
public:
    string locName;
    string longitude;
    string latitude;

    Node(string locName, string longitude, string latitude){
        this->locName = locName;
        this->longitude = longitude;
        this->latitude = latitude;
    }
    friend ostream& operator<<(ostream& os, const Node& node){
        os<<" [locName] "<<node.locName<<endl;
        os<<" [longitude] "<<node.longitude<<endl;
        os<<" [latitude] "<<node.latitude<<endl;

        return os;
    }
};
class LocArr{
public:
    vector<Node*> locArr;

    void insert(Node* newNode){
        locArr.push_back(newNode);
    }

    int getIndexFromLocName(string locName){
        for(int i=0; i<locArr.size(); i++){
            if(locArr.at(i)->locName == locName)
                return i;
        }
        return -1;
    }
};

vector<Node*> locArr;

int getIndexFromLocName(string locName){
    for(int i=0; i<locArr.size(); i++){
        if(locArr.at(i)->locName == locName)
            return i;
    }
    return -1;
}

class adjNode{
public:
    int index;
    adjNode* next;

    adjNode(int index, adjNode* next = NULL){
        this->index = index;
        this->next = next;
    }
    friend ostream& operator<<(ostream& os, const adjNode& node){
        os<<" [index] "<<node.index<<endl;

        return os;
    }
};

class listNode{
public:
    int index;
    adjNode* adj;
    listNode* next;

    listNode(int index, adjNode* adj = NULL, listNode* next = NULL){
        this->index = index;
        this->adj = adj;
        this->next = next;
    }
    friend ostream& operator<<(ostream& os, const listNode& node){
        os<<" [index] "<<node.index<<endl;

        return os;
    }
};

class adjList{
public:
    listNode* root;

    adjList(listNode* root = NULL){
        this->root = root;
    }

    listNode* getInsertLoc(int index){
        listNode* p = this->root;
        if(p == NULL){
            return NULL;
        }
        while(p->next != NULL){
            if(p->index < index && p->next->index > index)
                return p;
            p = p->next;
        }
        return p;
    }
    listNode* isThereAdjNode(int index){
        listNode* p = this->root;
        while(p != NULL){
            if(p->index == index)
                return p;
            p = p->next;
        }
        return NULL;
    }
    void insert(string from, string to){
        int fromIndex, toIndex;
        listNode* listNodeCheck;

        fromIndex = getIndexFromLocName(from);
        toIndex = getIndexFromLocName(to);

        listNodeCheck = isThereAdjNode(fromIndex);
        if(listNodeCheck != NULL){
            adjNode* newAdjNode = new adjNode(toIndex);

            newAdjNode->next = listNodeCheck->adj;
            listNodeCheck->adj = newAdjNode;
        }
        else{
            listNode* newListNode = new listNode(fromIndex);
            adjNode* newAdjNode = new adjNode(toIndex);
            newListNode->adj = newAdjNode;

            listNode* frontNode = getInsertLoc(fromIndex);
            // root == NULL
            if(frontNode == NULL)
                this->root = newListNode;
            else{
                newListNode->next = frontNode->next;
                frontNode->next = newListNode;
            }
        }
    }

};
adjList LIST = adjList();

void readLoc(string filename){
    string input;
    string locName;
    string longitude, latitude;
    ifstream fin;

    fin.open(filename);
    if(fin.is_open())
        cout<<"file open ok!"<<endl;

    while(!fin.eof()){
        // 1. Get line by line
        getline(fin, input);
        // REMOVE '\r'
        input.erase(input.size()-1);
        // 2. Pasre by substr&find
        locName = input.substr(0, input.find('\t'));
        input = input.substr(input.find('\t')+1);
        longitude = input.substr(0, input.find('\t'));
        latitude = input.substr(input.find('\t')+1);
        // 3. Make new Node
        Node *newNode = new Node(locName, longitude, latitude);
        // 4. Add to locList
        locArr.push_back(newNode);
    }
}
void readAdj(string filename){
    string input;
    string from;
    string to;
    ifstream fin;

    fin.open(filename);
    while(!fin.eof()){
        getline(fin, input);
        // REMOVE '\r'
        if (!input.empty() && input[input.size() - 1] == '\r')
            input.erase(input.size() - 1);
        //cout<<input<<endl;
        from = input.substr(0, input.find('\t'));
        to = input.substr(input.find('\t')+1);
        cout<<from<<endl;
        cout<<to<<endl;

        LIST.insert(from, to);
        LIST.insert(to, from);

    }
}
void BFS(adjList adjListIn, listNode* startNode){
    vector<int> visited(locArr.size());
    fill(visited.begin(), visited.end(), -1);

    queue<listNode*> Q;
    int hop = 0;
    visited.at(startNode->index) = hop;
    Q.push(startNode);
    while(!Q.empty()){
        listNode* checkNode = Q.front();
        Q.pop();
        adjNode* p = checkNode->adj;
        while(p!=NULL){
            int checkIndex = p->index;
            if(visited.at(checkIndex) == -1){
                hop = visited.at(checkNode->index)+1;
                if(hop > 10) return;

                visited.at(checkIndex) = hop;
                listNode* newEnqueue = LIST.isThereAdjNode(checkIndex);
                cout<<" [hop] : "<<hop<<endl;
                cout<<*locArr.at(checkIndex)<<endl;
                Q.push(newEnqueue);
            }
            p = p->next;
        }
    }
}
void underTenHop(){

    string inputLocName;

    cout<<"Enter Location Name: ";
    getline(cin,inputLocName);

    int locIndex = getIndexFromLocName(inputLocName);
    listNode* startNode = LIST.isThereAdjNode(locIndex);

    if(startNode == NULL){
        cout<<"NOT EXIST LOCATION."<<endl;
        return;
    }

    BFS(LIST, startNode);
}
int main(void) {

    readLoc("alabama.txt");
    //cout<<*locArr.at(2)<<endl;
    //cout<<locArr.size()<<endl;

    readAdj("roadList2.txt");
    //cout<<LIST.root->adj->index<<endl;

    underTenHop();

    return 0;
}
