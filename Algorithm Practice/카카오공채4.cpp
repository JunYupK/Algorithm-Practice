#include <string>
#include <vector>
#include<iostream>
#include<string>
#include <cmath>
#include <map>
using namespace std;
int DFS(vector<int>info, vector<vector<int>> matrix, vector<vector<int>> edges, int index, int Ycnt, int Xcnt,int max) {
    if (info[index] == 0)
        Ycnt++;
    if (info[index] == 1)
        Xcnt++;
    if (Ycnt <= Xcnt)
        return Ycnt;
    if (Ycnt > max)
        max = Ycnt;
        for (int j = 0; j < info.size(); j++) {
            if (matrix[index][j] != 0)
                max=DFS(info, matrix, edges, j, Ycnt, Xcnt, max);
            Ycnt = max;
        }

    return max;
}
int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    vector <vector<int>> matrix(info.size(),vector<int>(info.size(),0));
    for (int i = 0; i < edges.size(); i++) {
        int index1 = edges[i][0];
        int index2 = edges[i][1];
        matrix[index1][index2] = 1;
    }
    //for (int i = 0; i < matrix.size(); i++) {
    //    for (int j = 0; j < matrix.size(); j++) {
    //        cout << matrix[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    answer = DFS(info, matrix,edges, 0, 0, 0, 0);
    return answer;
}
int main() {
    vector<int> info = { 0,1,0,1,1,0,1,0,0,1,0 };
    vector <vector<int>> edges = { {0,1 }, { 0,2 }, { 1,3 }, { 1,4 }, { 2,5 }, { 2,6 }, { 3,7 }, { 4,8 }, { 6,9 }, { 9,10 }
    };
    cout << solution(info, edges);
}