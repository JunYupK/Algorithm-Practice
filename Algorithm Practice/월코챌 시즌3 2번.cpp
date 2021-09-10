#include <string>
#include <vector>
#include <iostream>
using namespace std;
// L�� ���� ���� +�̸� ���� + ���� - �̸� ���� -
// R�� �ݴ�
//S�� ���� ���� �ٲ�� �״�� �� ���� �ٲ�� �״�� ��
// ���̵� = +�� 0 ���̵� -�� 1  ���̵� + �� 2 ���̵� -�� 3
int rightmove(vector<string> grid,int prev,int firstmove) {
	int i = 0, j = 0;
	int cnt = 0;
	for (;; cnt++) {
		if (cnt != 0 && firstmove == prev && grid[i][j] == 'S')
			break;
		if (grid[i][j] == 'S') {
			if (prev == 0) {//��+�̵�
				if (grid.size() - 1 == i) {
					i = 0;
				}
				else {
					i++;
				}
				prev = 0;
			}
			else if (prev == 1) {//�� - �̵�
				if (i == 0) {
					i = grid.size() - 1;
				}
				else {
					i--;
				}
				prev = 1;
			}
			else if (prev == 2) {//���̵� +
				if (grid[i].size() - 1 == j) {
					j = 0;
				}
				else {
					j++;
				}
				prev = 2;
			}
			else if (prev == 3) {//���̵� -
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
			if (prev == 0) {//���̵� +�� ������ ���̵�  +
				if (grid[i].size() - 1 == j) {
					j = 0;
				}
				else {
					j++;
				}
				prev = 2;
			}
			else if (prev == 1) {//���̵� -�� ������ ���̵� -
				if (j == 0) {
					j = grid[i].size() - 1;
				}
				else {
					j--;
				}
				prev = 3;
			}
			else if (prev == 2) {//���̵� +�� ������ �� �̵� -

				if (i == 0) {
					i = grid.size() - 1;
				}
				else {
					i--;
				}
				prev = 1;
			}
			else if (prev == 3) {//���̵� - �� �̵� +
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
			if (prev == 0) {//���̵� +�� ������ ���̵� -
				if (j == 0) {
					j = grid[i].size() - 1;
				}
				else {
					j--;
				}
				prev = 3;
			}
			else if (prev == 1) {//�� - �� +             
				if (grid[i].size() - 1 == j) {
					j = 0;
				}
				else {
					j++;
				}
				prev = 2;
			}
			else if (prev == 2) {//���̵� + �� +
				if (grid.size() - 1 == i) {
					i = 0;
				}
				else {
					i++;
				}
				prev = 0;
			}
			else if (prev == 3) {//���̵� - �� -
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