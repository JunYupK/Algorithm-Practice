#include <string>
#include <vector>
#include <iostream>
using namespace std;
// L는 전에 행이 +이면 렬이 + 행이 - 이면 렬이 -
// R는 반대
//S는 전에 행이 바뀌면 그대로 행 렬이 바뀌면 그대로 렬
// 행이동 = +를 0 행이동 -를 1  렬이동 + 를 2 렬이동 -를 3
int rightmove(vector<string> grid,int prev,int firstmove) {
	int i = 0, j = 0;
	int cnt = 0;
	for (;; cnt++) {
		if (cnt != 0 && firstmove == prev && grid[i][j] == 'S')
			break;
		if (grid[i][j] == 'S') {
			if (prev == 0) {//행+이동
				if (grid.size() - 1 == i) {
					i = 0;
				}
				else {
					i++;
				}
				prev = 0;
			}
			else if (prev == 1) {//행 - 이동
				if (i == 0) {
					i = grid.size() - 1;
				}
				else {
					i--;
				}
				prev = 1;
			}
			else if (prev == 2) {//렬이동 +
				if (grid[i].size() - 1 == j) {
					j = 0;
				}
				else {
					j++;
				}
				prev = 2;
			}
			else if (prev == 3) {//렬이동 -
				if (j == 0) {
					j = grid[i].size() - 1;
				}
				else {
					j--;
				}
				prev = 3;
			}
		}
		else if (grid[i][j] == 'L') {
			if (prev == 0) {//행이동 +가 왔으면 렬이동  +
				if (grid[i].size() - 1 == j) {
					j = 0;
				}
				else {
					j++;
				}
				prev = 2;
			}
			else if (prev == 1) {//행이동 -가 왔으면 렬이동 -
				if (j == 0) {
					j = grid[i].size() - 1;
				}
				else {
					j--;
				}
				prev = 3;
			}
			else if (prev == 2) {//렬이동 +가 왔으면 행 이동 -

				if (i == 0) {
					i = grid.size() - 1;
				}
				else {
					i--;
				}
				prev = 1;
			}
			else if (prev == 3) {//렬이동 - 행 이동 +
				if (grid.size() - 1 == i) {
					i = 0;
				}
				else {
					i++;
				}
				prev = 0;
			}
		}
		else if (grid[i][j] == 'R') {
			if (prev == 0) {//행이동 +가 왔으면 렬이동 -
				if (j == 0) {
					j = grid[i].size() - 1;
				}
				else {
					j--;
				}
				prev = 3;
			}
			else if (prev == 1) {//행 - 렬 +             
				if (grid[i].size() - 1 == j) {
					j = 0;
				}
				else {
					j++;
				}
				prev = 2;
			}
			else if (prev == 2) {//렬이동 + 행 +
				if (grid.size() - 1 == i) {
					i = 0;
				}
				else {
					i++;
				}
				prev = 0;
			}
			else if (prev == 3) {//렬이동 - 행 -
				if (i == 0) {
					i = grid.size() - 1;
				}
				else {
					i--;
				}
				prev = 1;
			}
		}
	}
	return cnt;
}
vector<int> solution(vector<string> grid) {
	vector<int> answer;
	int firstmove = 0;
	for (int i = 0; i < 4; i++) {
		answer.push_back(rightmove(grid, i, i));
	}
	return answer;
}
int main() {
	vector<string> grid = { "SL","LR" };
	vector <int> v = solution(grid);
	cout << v[0];
	return 0;
}