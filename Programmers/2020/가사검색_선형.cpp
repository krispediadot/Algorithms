#include <string>
#include <vector>
#include <iostream>
#include <regex>
#include <cstring>

using namespace std;

struct Trie{
    Trie* next[26];
    bool finish;
    int cnt;
    Trie(): finish(false), cnt(1){
        memset(next, 0, sizeof(next));
    }
    ~Trie(){
        for(int i=0; i<26; i++){
            if(next[i]) delete next[i];
        }
    }
    void insert(const char* key){
        if(*key=='\0')
            finish = true;
        else{
            int curr = *key -'a';
            if(next[curr] == NULL)
                next[curr] = new Trie();
            else
                next[curr]->cnt++;
            next[curr]->insert(key+1);
        }
    }
    int find(const char* key){
        int curr = *key -'a';
        if(*key == '?'){
            int tmp = 0;
            for(int i=0; i<26; i++){
                if(next[i] != NULL) tmp += next[i]->cnt;
            }
            return tmp;
        }
        if(next[curr] == NULL) return 0;
        if(*(key+1) == '?') return next[curr]->cnt;
        return next[curr]->find(key+1);
    }
};

Trie *root[100001];
Trie *reroot[100001];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    // 0. queries for 0->queries.size()-1
    for(int i=0; i<queries.size(); i++) {
        int count=0;
        // 1. queries[i] 글자에 ? 를 .으로 변경
        string target = queries[i];
        for(char &c:target) c = c=='?'?'.':c;
        // 2. regex re( "(quereis[i])" )
        regex re(target);
        // 3. words 돌면서 regex_math() 이면 count++
        for(int j=0; j<words.size(); j++){
            if(regex_match(words[j], re))
                count++;
        }
        answer.push_back(count);
    }
    return answer;
}

int main(){
    vector<string> words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> queries = {"fro??", "????o", "fr???", "fro???", "pro?"};
    vector<int> answer = solution(words, queries);

    for(int i=0; i<answer.size(); i++)
        cout<<answer[i]<<" ";
}