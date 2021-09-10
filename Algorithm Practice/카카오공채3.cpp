#include <string>
#include <vector>
#include<iostream>
#include<string>
#include <cmath>
#include <map>
using namespace std;

int TimeToMin(string records) {


	int hour = atoi(records.substr(0, 2).c_str());
	int min = atoi(records.substr(3, 2).c_str());
	hour *= 60;
	min += hour;


	return min;
}
//1439분
vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	map <string, int> m1;
	map <string, int> m2;//주차시간 기록
	for (int i = 0; i < records.size(); i++) {
		int min = TimeToMin(records[i]);
		string carnum = records[i].substr(6, 4);
		string inout = records[i].substr(11, 4);
		if (m1.find(carnum) == m1.end()) {//들어온 경우
			m1.insert(make_pair(carnum, min));
		}
		else {//나가는경우
			int outmin = min - m1[carnum];
			if (m2.find(carnum) != m2.end()) {
				m2[carnum] += outmin;
			}
			else
				m2.insert(make_pair(carnum, outmin));
			m1.erase(carnum);
		}
	}
	//안나간 차량 check
	map <string, int>::iterator it;
	if (!m1.empty()) {
		for (it = m1.begin(); it != m1.end(); it++) {
			m2[it->first] += (1439 - it->second);
		}
	}
	//요금 계산
	for (it = m2.begin(); it != m2.end(); it++) {
		int time = it->second;
		time = time - fees[0];
		if (time < 0) {
			answer.push_back(fees[1]);
			continue;
		}
		else {
			int fee;
			if (time % fees[2] == 0)
				fee = ((time / fees[2]) * fees[3]) + fees[1];
			else
				fee = (((time / fees[2])+1) * fees[3]) + fees[1];
			answer.push_back(fee);
		}
	}
	return answer;
}
int main() {
	vector <int> fees = {
		180, 5000, 10, 600
	};
	vector <string> records = {
		"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"
	};
	vector<int> v;
	v = solution(fees, records);
}
