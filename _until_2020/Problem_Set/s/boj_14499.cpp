#include<iostream>
#include<vector>

using namespace std;
int n,m;

pair<int,int> loc;
vector<vector<int>> arr;
vector<int> row = {0,0,0};
vector<int> col = {0,0,0,0};

bool move(int cmd){
    if(cmd==1){
        if(loc.second+1<m){
            loc.second+=1;
            int tail = row.back();
            row.pop_back();
            row.insert(row.begin(), 1, col[3]);
            col[3] = tail;
            col[1] = row[1];
        }else
            return false;
    }
    else if(cmd==2){
        if(loc.second-1>=0){
            loc.second-=1;
            int tail = row.front();
            row.erase(row.begin());
            row.push_back(col[3]);
            col[3] = tail;
            col[1] = row[1];
        } else
            return false;
    }
    else if(cmd==3){
        if(loc.first-1>=0){
            loc.first-=1;
            int tail = col.front();
            col.erase(col.begin());
            col.push_back(tail);
            row[1] = col[1];
        } else
            return false;
    }
    else if(cmd==4){
        if(loc.first+1<n){
            loc.first+=1;
            int tail = col.back();
            col.pop_back();
            col.insert(col.begin(), 1, tail);
            row[1] = col[1];
        } else
            return false;
    }
    return true;
}

int main(){
    cin>>n>>m;
    cin>>loc.first>>loc.second;

    int k;cin>>k;
    for(int i=0; i<n; i++){
        vector<int> tmp;
        for(int j=0; j<m; j++){
            int num;cin>>num;
            tmp.push_back(num);
        }
        arr.push_back(tmp);
    }
    for(int i=0; i<k; i++){
        int cmd; cin>>cmd;
        //bool movable = move(cmd);
        if(move(cmd)){
            //cout<<"[LOC]"<<loc.first<<","<<loc.second<<endl;
            if(arr[loc.first][loc.second]==0)
                arr[loc.first][loc.second] = col[3];
            else {
                col[3] = arr[loc.first][loc.second];
                arr[loc.first][loc.second] = 0;
            }
            cout<<row[1]<<endl;
        }
    }

}