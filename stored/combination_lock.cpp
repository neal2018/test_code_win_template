#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define LOCAL
// #define IO

int main(int, char**) {
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
        ll W, N;
        cin >> W >> N;
        vector<int> X(W);
        for (ll i = 0; i < W; i++) {
            cin >> X[i];
            X[i]--;
        }
        sort(X.begin(), X.end());
        vector<ll> pre(W + 1);  // sum(X[:i])
        for (ll i = 0; i < W; i++) {
            pre[i + 1] = X[i] + pre[i];
        }
        auto get = [&](ll i, ll j) { return pre[i] - pre[j]; };

        ll res = 1e18;
        ll p = 0;
        ll b = 0;
        for (ll i = 0; i < W; i++) {
            while ((N / 2 < X[i] - X[p]) && (p < i)) {
                p++;
            }
            while (((N + 1) / 2 > X[b] - X[i]) && (b < W)) {
                b++;
            }
            ll temp = 0;
            temp += (N - X[i]) * (p) + get(p, 0) + (i - p) * X[i] - get(i, p);
            temp +=
                -(b - i) * X[i] + get(b, i) + (W - b) * (N + X[i]) - get(W, b);
            res = min(res, temp);
        }
        // \sum_j min(abs(X[i] - X[j]), N - abs(X[i] - X[j]))
        // = \sum_j<i min(X[i] - X[j], N - X[i] + X[j]) + \sum_j>=i min(X[j] -
        // X[i], N - X[j] + X[i])

        // left_part = \sum_j<p (N - X[i] + X[j]) + \sum_p<=j<i (X[i] - X[j])
        // = (N-X[i])*(p) + \sum_j<p X[j] + (i-p)*X[i] - \sum_p<=j<i X[j]

        // p: the min index s.t. N / 2 >= X[i] - X[p]

        // right_part = \sum_b>j>=i (X[j] - X[i]) + \sum_i>=b (N - X[j] + X[i])
        // = -(b-i)*X[i] + \sum_b>j>=i X[j] + (W-b)*(N+X[i]) - \sum_j>=b (X[j])

        // b: the min index s.t. X[b] - X[i] >= N / 2

        cout << "Case #" << case_num << ": ";
        cout << res << endl;
    }
    return 0;
}
