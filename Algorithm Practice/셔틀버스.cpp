#pragma warning(disable: 4996)
#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
#include <time.h>

/*
1. ������ ��Ʋ���� <<����
*/
using namespace std;
int index = 0; //���� �ε����� üŷ�ϱ� ���� ��������

int TimeToInt(string timetable) {//HH:MM �� int �� �ٲٱ�
	int h, m;
	string tmp = timetable.substr(0, 2);
	h = stoi(tmp.c_str()) * 60;
	tmp = timetable.substr(3, 2);
	m = stoi(tmp.c_str());
	return h + m;
}
string IntToTime(int time) {//int�� ���� int ���� HH:MM string���� �ٲٱ�
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
	sort(timetable.begin(), timetable.end(), less<string>());//timetable sort greater?? �������� ����
	vector<int> Mtimetable;//�� ������ �ٲ� Ÿ�����̺� ����
	int Ptime = 540;//���� ���۽ð�
	for (int i = 0; i < timetable.size(); i++) {
		Mtimetable.push_back(TimeToInt(timetable[i]));
	}

	for (int i = 0; i < n; i++) {
		if (i == n - 1) {//�����϶�
			int lastindex = 0;
			int check = 0;//������ ������ Ż ���ִ� ũ�� ���� ���Ѵ�.
			for (int j = index; j < Mtimetable.size(); j++) {
				if (Mtimetable[j] <= Ptime)
					check++;
				
				if (Mtimetable[j] > Ptime) {//�������� �̹Ƿ� ��Ʋ�������� �����ð��̸� �ٷ� ������ index�� ����� �� �ݺ��� ����.
					lastindex = j - 1;
					break;
				}		
				else if (j == Mtimetable.size() - 1)
				{
					lastindex = j;
				}
			}

			if (check < m) {//������ ������ �����ڸ��� �γ��ҋ�
				answer = IntToTime(Ptime);//�����ð��� ����ȴ�.
				return answer;
			}
			else if (check == m) {//�� ������ ������ ������� ������ ����ȴ�.
				answer = IntToTime(Mtimetable[lastindex] - 1);
				return answer;
			}
			else {//�ڸ��� �����ҋ�
				//(m-1)+index ������ ���� m��° ������� ����;� Ż���ִ�.
				answer = IntToTime(Mtimetable[index+m-1]-1);
				return answer;
			}
		}
		else {//������ �ƴҶ�.
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
* ���� ������ index�� ������� �ʰ� �ƿ� timetable �� erase �ϸ鼭 �� ����ϰ� ¥�¹���� �����Ͱ���
*/