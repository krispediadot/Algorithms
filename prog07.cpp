#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<vector>

#define PI acos(-1.0)

using namespace std;

class Node{
    private:
        string locName;
        double longitude;
        double latitude;
    public:
        Node(string locName, double longitude, double latitude){
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
/*
class AdjList{
    

}
*/
vector<Node*> locList;

void readLoc(string filename){
    string input;
    string locName;
    double longitude, latitude;
    ifstream fin;

    fin.open(filename);
    while(!fin.eof()){
        // 1. Get line by line
        getline(fin, input);
        // 2. Pasre by substr&find
        locName = input.substr(0, input.find('\t'));
        input = input.substr(input.find('\t')+1);
        longitude = stod(input.substr(0, input.find('\t')));
        latitude = stod(input.substr(input.find('\t')+1));
        // 3. Make new Node
        Node *newNode = new Node(locName, longitude, latitude);
        // 4. Add to locList
        locList.push_back(newNode);
    }
}

int main(void) {

    readLoc("test.txt");
    cout<<*locList.at(3)<<endl;

    return 0;
}
