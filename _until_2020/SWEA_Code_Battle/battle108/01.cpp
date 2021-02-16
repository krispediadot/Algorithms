#include<iostream>
#define SIZE 10000
using namespace std;
 
struct Node{
    int from;
    int to;
    Node(int from, int to):from(from), to(to){}
};
 
int main(){
    int T, N;
    cin>>T;
    for(int t=1; t<=T; t++){
        Node* arr[SIZE] = {nullptr};
        int result[SIZE] = {0};
        cin>>N;
        for(int n=0; n<N; n++){
            int a,b;
            cin>>a>>b;
            arr[n] = new Node(a,b);
        }
        // 입력 끝!
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(i!=j && (arr[i]->from<arr[j]->from && arr[i]->to>arr[j]->to))
                    result[i]++;
            }
        }
 
        int count = 0;
        for(int i=0; i<N; i++)
            count+=result[i];
 
        cout<<"#"<<t<<" "<<count<<endl;
    }
    return 0;
}
