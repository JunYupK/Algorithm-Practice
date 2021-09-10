#include <string>
#include <vector>
#include<iostream>
#include<string>
#include <cmath>

using namespace std;
vector<int> ChangeNum(int n, int b) {
    vector<int> v;
    vector<int> answer;
    while (1) {
        v.push_back(n % b);
        n /= b;
        if (n == 0) break;
    }
    vector<int>::reverse_iterator iter;
    for (iter = v.rbegin(); iter != v.rend(); iter++) {
        cout << *iter;
        answer.push_back(*iter);
    }
    return answer;
}
bool isPrime(int num) {
    if (num < 2) return false;
    int a = (int)sqrt(num);
    for (int i = 2; i <= a; i++) if (num % i == 0) return false;
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    vector<int> num = ChangeNum(n, k);
    vector <int> primenum;
    int tmp = 0;
    for (int i = 0; i < num.size(); i++) {
        if (i == 0 && num[i] == 0)
            continue;
        if (num[i] != 0) {
            tmp *= 10;
            tmp += num[i];
        }
        else {
            string tnum = to_string(tmp);
            tnum.reserve();
            primenum.push_back(atoi(tnum.c_str()));
            tmp = 0;
        }
        if (i == num.size() - 1) {
            string tnum = to_string(tmp);
            tnum.reserve();
            primenum.push_back(atoi(tnum.c_str()));
        }
    }

    //소수 검사
    for (int i = 0; i < primenum.size(); i++) {
        if(isPrime(primenum[i]))
            answer++;
    }
    return answer;
}

int main() {
    int n= 1000000, k = 8;
    cout <<" "<<solution(n, k);
}