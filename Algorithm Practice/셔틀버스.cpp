#pragma warning(disable: 4996)
#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
#include <time.h>

/*
1. 마지막 셔틀버스 <<강조
*/
using namespace std;
int index = 0; //현재 인덱스를 체킹하기 위한 전역변수

int TimeToInt(string timetable) {//HH:MM 을 int 로 바꾸기
	int h, m;
	string tmp = timetable.substr(0, 2);
	h = stoi(tmp.c_str()) * 60;
	tmp = timetable.substr(3, 2);
	m = stoi(tmp.c_str());
	return h + m;
}
string IntToTime(int time) {//int로 받은 int 값을 HH:MM string으로 바꾸기
	int Manswer = time;
	int Hanswer = Manswer / 60;
	string min, hour;
	Manswer = Manswer % 60;
	if (Manswer < 10) {
		min = "0";
		min = min + to_string(Manswer);
	}
	else {
		min = to_string(Manswer);
	}

	if (Hanswer < 10) {
		hour = "0";
		hour = hour + to_string(Hanswer);
	}
	else {
		hour = to_string(Hanswer);
	}
	string answer = hour;
	answer += ":";
	answer += min;
	return answer;
}
string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	sort(timetable.begin(), timetable.end(), less<string>());//timetable sort greater?? 오름차순 정렬
	vector<int> Mtimetable;//분 단위로 바꾼 타임테이블 벡터
	int Ptime = 540;//버스 시작시간
	for (int i = 0; i < timetable.size(); i++) {
		Mtimetable.push_back(TimeToInt(timetable[i]));
	}

	for (int i = 0; i < n; i++) {
		if (i == n - 1) {//막차일때
			int lastindex = 0;
			int check = 0;//마지막 버스에 탈 수있는 크루 수를 구한다.
			for (int j = index; j < Mtimetable.size(); j++) {
				if (Mtimetable[j] <= Ptime)
					check++;
				
				if (Mtimetable[j] > Ptime) {//오름차순 이므로 셔틀버스보다 늦은시간이면 바로 마지막 index를 기억한 후 반복문 나감.
					lastindex = j - 1;
					break;
				}		
				else if (j == Mtimetable.size() - 1)
				{
					lastindex = j;
				}
			}

			if (check < m) {//마지막 버스에 남은자리가 널널할떄
				answer = IntToTime(Ptime);//버스시간에 오면된다.
				return answer;
			}
			else if (check == m) {//딱 맞을때 마지막 사람보다 빠르게 오면된다.
				answer = IntToTime(Mtimetable[lastindex] - 1);
				return answer;
			}
			else {//자리가 부족할떄
				//(m-1)+index 마지막 남은 m번째 사람보다 일찍와야 탈수있다.
				answer = IntToTime(Mtimetable[index+m-1]-1);
				return answer;
			}
		}
		else {//막차가 아닐때.
			int cnt = 0;
			for (int j = index; j < Mtimetable.size(); j++) {
				if (cnt == m) {
					index = j;
					break;
				}
				int min = Mtimetable[j];
				if (min <= Ptime) {
					cnt++;
					continue;
				}
				else if (min > Ptime) {
					index = j;
					break;
				}
				if(j == Mtimetable.size() - 1)
					index = Mtimetable.size() - 1;
			}
		}
		Ptime += t;
	}

	return answer;
}

int main() {
	vector<string> v = { "00:01", "00:01", "00:02", "00:03", "00:04" };

	cout<< solution(1,1,6, v);
	return 0;
}
/*
* 굳이 마지막 index를 기억하지 않고 아예 timetable 을 erase 하면서 더 깔끔하게 짜는방법도 있을것같다
*/