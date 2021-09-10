#include <string>
#include <vector>
#include <iostream>

using namespace std;
//string 단위가 거슬리면 항상 때는 연습을 하자 substr은 뒤인자가 overflow여도 오류가 안뜬다!
int TimeSub(string lines) {
	string h, m, s, ms;
	int hour, min, sec, msec;
	lines.pop_back();
	h = lines.substr(11, 2);
	m = lines.substr(14, 2);
	s = lines.substr(17, 2);
	ms = lines.substr(20, 3);
	hour = stoi(h) * 3600 * 1000;
	min = stoi(m) * 60 * 1000;
	sec = stoi(s) * 1000 + stoi(ms);
	return hour + min + sec;
}
int ProcessToNum(string lines) {
	int time;
	time = stof(lines.substr(24, 5)) * 1000;
	return time;
}

int solution(vector<string> lines) {
	int answer = 0;
	int  sec, de;
	vector<int>  start_point , end_point;
	
	for (int i = 0; i < lines.size(); i++) {
		int start = TimeSub(lines[i]);
		int end = ProcessToNum(lines[i]);
		start_point.push_back(start - end + 1);
		end_point.push_back(start);
	}

	for (int i = 0; i < lines.size(); i++) {
		int cnt = 1;
		int end = end_point[i] + 1000;
		for (int j = i+1; j < lines.size(); j++) {
			if (start_point[j] < end)
				cnt++;
		}
		if (answer < cnt)
			answer = cnt;
	}
	return answer;
}
int main() {
	//11~22 24~27;
	vector <string> lines = {
		"2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s"
	};
	vector <int> v;
	 cout << solution(lines);
	return 0;
}
/*초당 처리시간에 들어가는 경우는
* 1. line의 처리시간의 시작시간이 end보다 작을경우
* 2. 처리시간의 시작시간
*/