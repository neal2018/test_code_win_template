#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LOCAL
// #define IO

int main(int, char**) {
#ifdef IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
#ifdef LOCAL
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif
    int total_cases_number;
    cin >> total_cases_number;
    for (int case_num = 1; case_num <= total_cases_number; case_num++) {
        ll L, R;
        cin >> L >> R;
        cout << "Case #" << case_num << ": ";
        cout << L + R << endl;
    }
    return 0;
}
