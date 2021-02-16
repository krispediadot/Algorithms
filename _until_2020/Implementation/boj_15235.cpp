#include<iostream>
#define MAX 1000

using namespace std;

class Queue{
    struct Data{
        int index;
        Data* next;

        Data(int index, Data* next):index(index), next(next){}
    };
    Data* front;
    Data* rear;

public:
    Queue(){
        front = nullptr;
        rear = nullptr;
    }
    void enqueue(int index){
        Data* newData = new Data(index, nullptr);
        if(front == nullptr){
            front = newData;
            rear = front;
        }
        else{
            rear->next = newData;
            rear = newData;
        }
    }
    int dequeue(){
       int target = front->index;
       front = front->next;

       if(front==nullptr) rear = nullptr;

       return target;
    }
    bool is_empty(){
        if(front == nullptr) return true;
        return false;
    }
};

int main(){
    Queue* q = new Queue();
    int n;
    int times[MAX]={0};
    int result[MAX]={0};
    cin>>n;
    for(int i=0; i<n; i++) {
        cin >> times[i];
        q->enqueue(i);
    }

    int time = 0;
    while(!q->is_empty()) {
        time++;
        int turn = q->dequeue();
        times[turn]--;
        if(times[turn]!=0)
            q->enqueue(turn);
        else
            result[turn] = time;
    }

    for(int i=0; i<n ;i++)
        cout<<result[i]<<" ";

    return 0;
}
