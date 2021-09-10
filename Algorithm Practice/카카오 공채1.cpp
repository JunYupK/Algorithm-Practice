#include <iostream>
#include<algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map <string, int> m1;
    map <string, int> m2;//신고당한 횟수
    map <string, int> m3;//신고당한 횟수
    vector<vector<string>> v(id_list.size());
    map <string, string> mreport;//신고 중복 제거를 위한 map 이거의 결과값의 count가 답이다.

    for (int i = 0; i < id_list.size(); i++) {
        m1.insert(make_pair(id_list[i], i));
        m2.insert(make_pair(id_list[i], 0));
        m3.insert(make_pair(id_list[i], 0));
    }
    for (int i = 0; i < report.size(); i++) {
        string h1, h2;
        for (int j = 0; j < report[i].size(); j++) {
            if (report[i][j] == ' ') {
                h1 = report[i].substr(0, j);
                h2 = report[i].substr(j + 1, report[i].length() - j + 2);
                break;
            }
        }
        v[m1[h1]].push_back(h2);
    }
    //vector 중복제거
    for (int i = 0; i < id_list.size(); i++) {
        sort(v[i].begin(), v[i].end());
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
    }
    for (int i = 0; i < id_list.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            m2[v[i][j]]++;        
        }
    }


    for (int i = 0; i < id_list.size(); i++) {
        if (m2[id_list[i]] >= k) {
            for (int s = 0; s < id_list.size(); s++) {
                for (int j = 0; j < v[i].size(); j++) {
                    if (v[s][j] == id_list[i]) {
                        m3[id_list[s]]++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < id_list.size(); i++) {
        answer.push_back(m3[id_list[i]]);
    }
    return answer;
}
int main() {
    vector<string> id_list = {
       "muzi", "frodo", "apeach", "neo"
    };
    vector<string> report = {
        "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"
    };
    solution(id_list, report, 3);
	return 0;
}