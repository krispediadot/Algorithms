#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<vector>

#define PI acos(-1.0)

using namespace std;

typedef struct node{
    string locName;
    double longitude;
    double latitude;
}Node;

vector<Node> locList;

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
        Node newNode;
        newNode.locName = locName;
        newNode.longitude = longitude;
        newNode.latitude = latitude;
        // 4. Add to locList
        locList.push_back(newNode);
    }
}

int main(void) {

    readLoc("test.txt");
    cout<<locList.at(1).locName<<endl;
    cout<<locList.at(1).longitude<<endl;
    cout<<locList.at(1).latitude<<endl;

    /*
    string input;
    string locName;
    double longitude, latitude;
    ifstream fin;
    
    fin.open("test.txt");
    
    getline(fin, input);

    cout<<input<<endl;
    
    cout<<input.find('\t')<<endl;
    locName = input.substr(0, input.find('\t'));
    cout<<locName<<endl;
    input = input.substr(input.find('\t')+1);
    cout<<input<<endl;
    longitude = stod(input.substr(0, input.find('\t')));
    latitude = stod(input.substr(input.find('\t')+1));

    cout<<longitude<<endl;
    cout<<latitude<<endl;
    */


    return 0;
}
