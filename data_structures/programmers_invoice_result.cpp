/*
테스트 1 〉	통과 (0.02ms, 4.32MB)
테스트 2 〉	통과 (0.03ms, 4.32MB)
테스트 3 〉	통과 (413.88ms, 27.3MB)
테스트 4 〉	통과 (0.05ms, 3.67MB)
테스트 5 〉	통과 (0.04ms, 4.33MB)
테스트 6 〉	통과 (0.96ms, 4.26MB)
테스트 7 〉	통과 (2.61ms, 4.33MB)
테스트 8 〉	통과 (4.99ms, 4.21MB)
테스트 9 〉	통과 (102.00ms, 15.2MB)
테스트 10 〉	통과 (99.74ms, 15MB)
테스트 11 〉	통과 (390.20ms, 27MB)
테스트 12 〉	통과 (0.23ms, 3.83MB)
테스트 13 〉	통과 (0.25ms, 4.34MB)
테스트 14 〉	통과 (224.93ms, 15.1MB)
테스트 15 〉	통과 (376.19ms, 26.7MB)
테스트 16 〉	통과 (0.26ms, 4.26MB)
테스트 17 〉	통과 (0.42ms, 3.71MB)
테스트 18 〉	통과 (0.44ms, 3.81MB)
테스트 19 〉	통과 (0.72ms, 4.32MB)
테스트 20 〉	통과 (182.43ms, 15.1MB)
테스트 21 〉	통과 (363.54ms, 26.5MB)
테스트 22 〉	통과 (0.02ms, 3.69MB)
테스트 23 〉	통과 (0.02ms, 4.2MB)
테스트 24 〉	통과 (0.02ms, 3.69MB)
*/

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    vector<vector<int>> cnts(id_list.size(), vector<int>());
    
    for (auto& r : report) {
        istringstream is(r);
        string id, pick; is >> id >> pick;
        
        int id_idx = find(id_list.begin(), id_list.end(), id) - id_list.begin();
        int pick_idx = find(id_list.begin(), id_list.end(), pick) - id_list.begin();
        
        if (find(cnts[pick_idx].begin(), cnts[pick_idx].end(), id_idx) == cnts[pick_idx].end())
            cnts[pick_idx].push_back(id_idx);
    }
    
    for (auto& cnt : cnts) {
        if (cnt.size() >= k) {
            for (auto& c : cnt) answer[c]++;
        }
    }
    
    return answer;
}

/*
테스트 1 〉	통과 (0.02ms, 4.26MB)
테스트 2 〉	통과 (0.03ms, 3.67MB)
테스트 3 〉	통과 (428.53ms, 26.6MB)
테스트 4 〉	통과 (0.04ms, 4.25MB)
테스트 5 〉	통과 (0.06ms, 4.32MB)
테스트 6 〉	통과 (0.95ms, 4.32MB)
테스트 7 〉	통과 (2.79ms, 4.32MB)
테스트 8 〉	통과 (4.71ms, 4.26MB)
테스트 9 〉	통과 (103.99ms, 14.6MB)
테스트 10 〉	통과 (100.20ms, 14.2MB)
테스트 11 〉	통과 (365.42ms, 26.2MB)
테스트 12 〉	통과 (0.36ms, 3.75MB)
테스트 13 〉	통과 (0.26ms, 4.32MB)
테스트 14 〉	통과 (184.35ms, 14.9MB)
테스트 15 〉	통과 (413.15ms, 26.3MB)
테스트 16 〉	통과 (0.15ms, 4.33MB)
테스트 17 〉	통과 (0.24ms, 4.27MB)
테스트 18 〉	통과 (0.41ms, 4.33MB)
테스트 19 〉	통과 (0.75ms, 4.33MB)
테스트 20 〉	통과 (186.26ms, 15MB)
테스트 21 〉	통과 (367.61ms, 26.2MB)
테스트 22 〉	통과 (0.02ms, 4.29MB)
테스트 23 〉	통과 (0.02ms, 3.66MB)
테스트 24 〉	통과 (0.02ms, 4.33MB)
*/

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    vector<vector<bool>> cnts(id_list.size(), vector<bool>(id_list.size(), false));
    vector<int> true_cnts(id_list.size(), 0);
    
    for (auto& r : report) {
        istringstream is(r);
        string id, pick; is >> id >> pick;
        
        int id_idx = find(id_list.begin(), id_list.end(), id) - id_list.begin();
        int pick_idx = find(id_list.begin(), id_list.end(), pick) - id_list.begin();
        
        // if (find(cnts[pick_idx].begin(), cnts[pick_idx].end(), id_idx) == cnts[pick_idx].end())
        //     cnts[pick_idx].push_back(id_idx);
        
        if (cnts[pick_idx][id_idx] == false) {
            cnts[pick_idx][id_idx] = true;
            true_cnts[pick_idx]++;
        }
    }
    
    for (int idx = 0; idx < id_list.size(); idx++) {
        // if (cnt.size() >= k) {
        //     for (auto& c : cnt) answer[c]++;
        // }
        if (true_cnts[idx] >= k) {
            for (int i = 0; i < id_list.size(); i++) {
                if (cnts[idx][i] == true) answer[i]++;
            }
        }
    }
    
    return answer;
}

/*
테스트 1 〉	통과 (0.02ms, 4.15MB)
테스트 2 〉	통과 (0.02ms, 4.14MB)
테스트 3 〉	통과 (99.72ms, 39MB)
테스트 4 〉	통과 (0.03ms, 4.09MB)
테스트 5 〉	통과 (0.03ms, 4.17MB)
테스트 6 〉	통과 (0.54ms, 4.15MB)
테스트 7 〉	통과 (1.01ms, 4.04MB)
테스트 8 〉	통과 (1.85ms, 4.57MB)
테스트 9 〉	통과 (36.51ms, 20.4MB)
테스트 10 〉	통과 (28.77ms, 20.3MB)
테스트 11 〉	통과 (86.97ms, 38.8MB)
테스트 12 〉	통과 (0.18ms, 4.22MB)
테스트 13 〉	통과 (0.19ms, 4.1MB)
테스트 14 〉	통과 (33.38ms, 19.4MB)
테스트 15 〉	통과 (55.92ms, 32MB)
테스트 16 〉	통과 (0.10ms, 4.16MB)
테스트 17 〉	통과 (0.17ms, 3.75MB)
테스트 18 〉	통과 (0.24ms, 4.15MB)
테스트 19 〉	통과 (0.38ms, 4.09MB)
테스트 20 〉	통과 (32.27ms, 19.3MB)
테스트 21 〉	통과 (57.19ms, 32MB)
테스트 22 〉	통과 (0.01ms, 4.01MB)
테스트 23 〉	통과 (0.01ms, 3.66MB)
테스트 24 〉	통과 (0.02ms, 4.02MB)
*/

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Person {
    string name;
    unordered_set<string> froms;

    Person (string name): name(name) {};
};

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

    unordered_map<string, int> ids;
    for (int i = 0; i < id_list.size(); i++) ids[id_list[i]] = i;

    vector<int> answer(id_list.size(), 0);

    vector<Person> people;

    for (auto& name : id_list) {
        Person p(name);
        people.push_back(p);
    }

    for (auto& r: report) {
        // 1. split from_to
        string from = r.substr(0, r.find(' '));
        string to = r.substr(r.find(' ')+1);

        // 2. add from to
        people[ids[to]].froms.insert(from);
    }  

    // 3. send mail 
    for (auto& p : people) {
        if (p.froms.size() >= k) {
            for (auto& f : p.froms) {
                answer[ids[f]]++;
            }
        }
    } 

    return answer;
}

/*
테스트 1 〉	통과 (0.02ms, 4.18MB)
테스트 2 〉	통과 (0.02ms, 4.17MB)
테스트 3 〉	통과 (100.44ms, 39.1MB)
테스트 4 〉	통과 (0.03ms, 4.07MB)
테스트 5 〉	통과 (0.03ms, 4.09MB)
테스트 6 〉	통과 (0.53ms, 4.17MB)
테스트 7 〉	통과 (1.00ms, 4.18MB)
테스트 8 〉	통과 (1.78ms, 4.61MB)
테스트 9 〉	통과 (34.39ms, 20.2MB)
테스트 10 〉	통과 (28.35ms, 20.2MB)
테스트 11 〉	통과 (77.98ms, 38.8MB)
테스트 12 〉	통과 (0.17ms, 4.16MB)
테스트 13 〉	통과 (0.16ms, 4.15MB)
테스트 14 〉	통과 (32.57ms, 19.4MB)
테스트 15 〉	통과 (56.72ms, 32.1MB)
테스트 16 〉	통과 (0.10ms, 3.71MB)
테스트 17 〉	통과 (0.16ms, 4.17MB)
테스트 18 〉	통과 (0.23ms, 4.18MB)
테스트 19 〉	통과 (0.36ms, 3.89MB)
테스트 20 〉	통과 (39.32ms, 19.5MB)
테스트 21 〉	통과 (56.63ms, 32.1MB)
테스트 22 〉	통과 (0.01ms, 4.18MB)
테스트 23 〉	통과 (0.01ms, 3.61MB)
테스트 24 〉	통과 (0.01ms, 4.19MB)
*/
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

    unordered_map<string, int> ids;
    vector<int> answer(id_list.size(), 0);
    vector<unordered_set<string>> invoice(id_list.size());

    for (int i = 0; i < id_list.size(); i++) ids[id_list[i]] = i;

    for (auto& r: report) {
        // 1. split from_to
        string from = r.substr(0, r.find(' '));
        string to = r.substr(r.find(' ')+1);

        // 2. add from to
        invoice[ids[to]].insert(from);
    }  

    // 3. send mail 
    for (auto& p : invoice) {
        if (p.size() >= k) {
            for (auto& f : p) {
                answer[ids[f]]++;
            }
        }
    } 

    return answer;
}

/*
테스트 1 〉	통과 (0.02ms, 4.16MB)
테스트 2 〉	통과 (0.04ms, 4.16MB)
테스트 3 〉	통과 (145.51ms, 39MB)
테스트 4 〉	통과 (0.05ms, 4.18MB)
테스트 5 〉	통과 (0.06ms, 4.14MB)
테스트 6 〉	통과 (1.16ms, 3.85MB)
테스트 7 〉	통과 (2.57ms, 4.16MB)
테스트 8 〉	통과 (4.96ms, 4.64MB)
테스트 9 〉	통과 (65.71ms, 20.3MB)
테스트 10 〉	통과 (70.77ms, 20.3MB)
테스트 11 〉	통과 (145.11ms, 38.8MB)
테스트 12 〉	통과 (0.25ms, 3.71MB)
테스트 13 〉	통과 (0.24ms, 4.09MB)
테스트 14 〉	통과 (63.95ms, 19.5MB)
테스트 15 〉	통과 (122.42ms, 32.1MB)
테스트 16 〉	통과 (0.20ms, 4.16MB)
테스트 17 〉	통과 (0.27ms, 4.17MB)
테스트 18 〉	통과 (0.40ms, 4.16MB)
테스트 19 〉	통과 (0.72ms, 4.14MB)
테스트 20 〉	통과 (64.69ms, 19.5MB)
테스트 21 〉	통과 (159.95ms, 32.1MB)
테스트 22 〉	통과 (0.03ms, 4.16MB)
테스트 23 〉	통과 (0.02ms, 4.16MB)
테스트 24 〉	통과 (0.02ms, 4.16MB)
*/
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

    unordered_map<string, int> ids;
    vector<int> answer(id_list.size(), 0);
    vector<unordered_set<string>> invoice(id_list.size());

    for (int i = 0; i < id_list.size(); i++) ids[id_list[i]] = i;

    for (auto& r: report) {
        // 1. split from_to
        istringstream is(r);
        string from, to; is >> from >> to;

        // 2. add from to
        invoice[ids[to]].insert(from);
    }  

    // 3. send mail 
    for (auto& p : invoice) {
        if (p.size() >= k) {
            for (auto& f : p) {
                answer[ids[f]]++;
            }
        }
    } 

    return answer;
}
