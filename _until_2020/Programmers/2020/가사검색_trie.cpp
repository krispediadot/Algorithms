#include <string>
#include <vector>
#include <iostream>
#include <regex>
#include <cstring>
#include <algorithm>

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
    int wSize = words.size();
    int qSize = queries.size();
    vector<int> answer(qSize, 0);

    // 1. trie 초기화
    for(auto &w:words){
        int size = w.size();

        const char *c = w.c_str();
        if(root[size]==NULL) root[size] = new Trie();
        root[size]->insert(c);

        string reversed = w;
        reverse(reversed.begin(), reversed.end());
        const char *r = reversed.c_str();
        if(reroot[size]==NULL) reroot[size] = new Trie();
        reroot[size]->insert(r);
    }

    // 2.쿼리 확인
    int idx = 0;// 쿼리 인덱스
    for(auto &q:queries){
        int size = q.size();
        // 뒤에 ? 있는 경우 root로 확인
        if(q[size-1]=='?'){
            const char *c = q.c_str();
            if(root[size]==NULL){ idx++; continue;}
            else answer[idx] = root[size]->find(c);
        }
        // 앞에 ? 있는 경우 reroot로 확인
        else{
            string re = q;
            reverse(re.begin(), re.end());
            const char *r = re.c_str();
            if(reroot[size]==NULL) {idx++; continue;}
            else answer[idx] = reroot[size]->find(r);
        }
        idx++;
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