#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int> > P = {{1,0}, {0,-1}, {-1,0}, {0,1}};

pair<int,int> P0 = {1,0};
pair<int,int> P1 = {0,-1};
pair<int,int> P2 = {-1,0};
pair<int,int> P3 = {0,1};

pair<int,int> point;

vector<pair<int,int> > Loc;
vector<pair<int,int> > DragonCurve;
int N, squareCount=0;

void printLoc(){
    cout<<"[Loc]"<<'\n';
    for(auto it = Loc.begin(); it!=Loc.end(); ++it){
        cout<<"("<<it->first<<","<<it->second<<") ";
    }
    cout<<'\n';
}
void printCurve(){
    cout<<"[DragonCurve]"<<'\n';
    for(auto it = DragonCurve.begin(); it!=DragonCurve.end(); ++it){
        cout<<"("<<it->first<<","<<it->second<<") ";
    }
    cout<<'\n';
}
void generateCurve(vector<pair<int, int> > arr, int gen){
    int pIndex = 1;
    point = Loc.at(pIndex);
    int checkPoint = pIndex-1;
    int newPoint = pIndex;
    for(int i=0; i<gen; i++){
        checkPoint = newPoint-1;

        while(checkPoint >= 0){
            int checkX = Loc.at(checkPoint).first - Loc.at(checkPoint+1).first;
            int checkY = Loc.at(checkPoint).second - Loc.at(checkPoint+1).second;
            pair<int,int> check = make_pair(checkX, checkY);

            // 0
            if(check == P0) {
                //cout<<"check = 0"<<'\n';
                int newX = Loc.at(newPoint).first + P3.first;
                int newY = Loc.at(newPoint).second + P3.second;
                Loc.push_back(make_pair(newX, newY));
            }
            // 1
            else if(check == P1){
                //cout<<"check = 1"<<'\n';
                int newX = Loc.at(newPoint).first + P0.first;
                int newY = Loc.at(newPoint).second + P0.second;
                Loc.push_back(make_pair(newX, newY));
            }
            // 2
            else if(check == P2){
                //cout<<"check = 2"<<'\n';
                int newX = Loc.at(newPoint).first + P1.first;
                int newY = Loc.at(newPoint).second + P1.second;
                Loc.push_back(make_pair(newX, newY));
            }
            // 3
            else if(check == P3){
                //cout<<"check = 3"<<'\n';
                int newX = Loc.at(newPoint).first + P2.first;
                int newY = Loc.at(newPoint).second + P2.second;
                Loc.push_back(make_pair(newX, newY));
            }

            checkPoint = checkPoint-1;
            newPoint = newPoint+1;
        }

    }
}
void check4point(){
    //cout<<"\ncheck4point start"<<'\n';
    int checkX, checkY;
    pair<int,int> point;

    for(auto it = DragonCurve.begin(); it != DragonCurve.end(); ++it){
        pair<int,int> checkPoint = *it;

        // 4방향
        // 0
        checkX = checkPoint.first + P0.first;
        checkY = checkPoint.second + P0.second;
        point = make_pair(checkX, checkY);
        //cout<<"\ncheckPoint:"<<"("<<checkPoint.first<<","<<checkPoint.second<<")"<<'\n';
        //cout<<"compaPoint:"<<"("<<point.first<<","<<point.second<<")"<<'\n';

        auto result = find(DragonCurve.begin(), DragonCurve.end(), point);
        if(*result != point)
            continue;
        //cout<<"RIGHT OK"<<'\n';
        // 3
        checkX = checkPoint.first + P3.first;
        checkY = checkPoint.second + P3.second;
        point = make_pair(checkX, checkY);
        //cout<<"checkPoint:"<<"("<<checkPoint.first<<","<<checkPoint.second<<")"<<'\n';
        //cout<<"compaPoint:"<<"("<<point.first<<","<<point.second<<")"<<'\n';

        result = find(DragonCurve.begin(), DragonCurve.end(), point);
        if(*result != point)
            continue;
        //cout<<"BOTTOM OK"<<'\n';
        // 0 + 3
        checkX = checkPoint.first + P0.first + P3.first;
        checkY = checkPoint.second + P0.second + P3.second;
        point = make_pair(checkX, checkY);
        //cout<<"checkPoint:"<<"("<<checkPoint.first<<","<<checkPoint.second<<")"<<'\n';
        //cout<<"compaPoint:"<<"("<<point.first<<","<<point.second<<")"<<'\n';

        result = find(DragonCurve.begin(), DragonCurve.end(), point);
        if(*result != point)
            continue;
        //cout<<"CROSS OK"<<'\n';

        squareCount++;
        //cout<<"squareCount+"<<'\n';

    }

    //cout<<"\ncount: "<<squareCount<<'\n';
}
void readInput() {
    pair<int, int> start;
    int dir, gen;

    ios_base::sync_with_stdio(false);
    cin>>N;

    for(int i=0; i<N; i++) {
        Loc.clear();
        cin >> start.first >> start.second >> dir >> gen;
        // start 위치 넣어주기
        Loc.push_back(start);

        //printLoc();
        //printCurve();
        // 처음 시작 방향에 따라 위치 넣어주기
        if(dir == 0)
            Loc.push_back(make_pair(start.first + P0.first, start.second + P0.second));
        else if(dir == 1)
            Loc.push_back(make_pair(start.first + P1.first, start.second + P1.second));
        else if(dir == 2)
            Loc.push_back(make_pair(start.first + P2.first, start.second + P2.second));
        else
            Loc.push_back(make_pair(start.first + P3.first, start.second + P3.second));

        //printLoc();
        //printCurve();

        generateCurve(Loc, gen);

        for(auto it = Loc.begin(); it!=Loc.end(); ++it){
            DragonCurve.push_back(*it);
        }

        //printLoc();
        //printCurve();
    }
    sort(DragonCurve.begin(), DragonCurve.end());
    DragonCurve.erase(unique(DragonCurve.begin(), DragonCurve.end()), DragonCurve.end());

    //printCurve();

    check4point();

    cout<<squareCount<<'\n';

}


int main(void){

    readInput();

    return 0;
}
