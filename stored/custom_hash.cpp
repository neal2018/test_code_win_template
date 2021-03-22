#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define LOCAL
// #define IO
struct container_hash {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for (auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

unordered_map<vector<int>, double, container_hash> dp;

// map<vector<int>, double> dp;
vector<int> A;
ll N, M, K;

double solve(vector<int> &v) {
    auto it = dp.find(v);
    if (it != dp.end()) {
        return it->second;
    }
    int cnt = 0;
    int possible_move_cnt = 0;
    double total_expectations = 0;
    for (int i = 0; i < M; i++) {
        if (i == 0 || v[i] != v[i - 1]) {
            cnt = 1;
        } else {
            cnt++;
        }
        if ((i == M - 1 || v[i] != v[i + 1]) && v[i] < A[i]) {
            possible_move_cnt += cnt;
            v[i]++;
            total_expectations += solve(v) * cnt;
            v[i]--;
        }
    }
    dp[v] =
        1.0 * M / possible_move_cnt + total_expectations / possible_move_cnt;
    return dp[v];
}

int main(int, char **) {
#ifdef IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
#ifdef LOCAL
    ifstream cin(
        "C:/Users/neal/Projects/workshop/cpp_ws/test_code_win/input.txt");
    ofstream cout(
        "C:/Users/neal/Projects/workshop/cpp_ws/test_code_win/output.txt");
#endif
    int total_cases_number;
    cin >> total_cases_number;
    for (int case_num = 1; case_num <= total_cases_number; case_num++) {
        cin >> N >> M >> K;
        dp.clear();
        A.clear();
        A = vector<int>(M);
        for (int i = M - K; i < M; i++) {
            cin >> A[i];
        }
        vector<int> v(M);
        dp[A] = 0;
        cout << "Case #" << case_num << ": ";
        cout << setprecision(10) << solve(v) << endl;
    }
    return 0;
}