#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector <vector<int>> TimeSub(vector<string> lines) {
	int hour, min, sec, de;
	int Tsec, Tde;
	vector <vector<int>> Vsec;
	for (int i = 0; i < lines.size(); i++) {
		int check = 0;
		vector <int> sol;
		hour = stoi(lines[i].substr(11, 2));
		min = stoi(lines[i].substr(14, 2));
		sec = stoi(lines[i].substr(17, 2));
		hour *= 3600;
		min *= 60;
		sec += hour + min;
		de = stoi(lines[i].substr(20, 3));
		Tsec = stoi(lines[i].substr(24, 1));
		int start;
		for (int j=lines[i].length() - 1;;j--) {
			if (lines[i][j] == '.') {
				start = j + 1;
				break;
			}
			else if (lines[i][j] == ' ') {
				start = 0;
				break;
			}
		}
		if (start == 0)
			Tde = 0;
		else {
			Tde = stoi(lines[i].substr(start, lines[i].length() - (start+1)));
		}

		sec -= Tsec;
		de -= Tde;
		if (de < 0) {
			sec--;
			de = de + 1000;
			de++;
			if (de > 1000) {
				sec++;
				de -= 1000;
			}
			sol.push_back(sec);
			sol.push_back(de);
		}
		else
		{
			de++;
			if (de > 1000) {
				sec++;
				de -= 1000;
			}
			sol.push_back(sec);
			sol.push_back(de);
		}
		Vsec.push_back(sol);
	}
	return Vsec;
}
int solution(vector<string> lines) {
	int answer = 0;
	int  sec, de;
	vector <vector<int>> Vsec;//시작 시간을 sec단위로 바꾼 vector
	Vsec = TimeSub(lines);
	for (int i = 0; i < lines.size(); i++) {
		cout << Vsec[i][0] << " " << Vsec[i][1] << endl;
	}
	for (int i = 0; i < lines.size(); i++) {
		int cnt = 1;
		int end = Vsec[i][0] + 1;
		int endT = Vsec[i][1];
		for (int j = i; j < lines.size(); j++) {
			if (Vsec[j][0] < end) { //초가 end보다 작으면 구간 1초 구간 안
				cnt++;
			}
			else if (Vsec[j][0] == end && Vsec[j][1] <= endT) {
				cnt++;
			}
		}
		if (answer < cnt)
			answer = cnt;
	}

	return answer;
}
int main() {
	//11~22 24~27;
	vector <string> lines = {
		"2016-09-15 00:00:00.000 2.3s", "2016-09-15 23:59:59.999 0.1s"
	};
	vector <int> v;
	 cout << solution(lines);
	return 0;
}
/*초당 처리시간에 들어가는 경우는
* 1. line의 처리시간의 시작시간이 end보다 작을경우
* 2. 처리시간의 시작시간
*/