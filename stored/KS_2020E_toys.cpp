#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define LOCAL
// #define IO
ll INF = 1e18;

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
        int N;
        cin >> N;
        vector<ll> E(N);
        vector<ll> R(N);
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            cin >> E[i] >> R[i];
            sum += E[i];
        }
        cout << "Case #" << case_num << ": ";
        set<pair<ll, ll>> heap; // min-heap
        // start round1 without removing
        ll acc_sum = sum;
        ll removed_E = 0;
        ll num_removed = 0;
        // save answers
        ll maximum = acc_sum;
        ll num_removed_with_maximum = 0;
        for (int i = 0; i < N; i++) {
            // start round2, push toys one by one to the heap
            heap.insert({sum - E[i] - R[i], i});
            acc_sum += E[i];
            // if get stopped, keep popping the most time-consuming one
            // (the first popped is the newest pushed one)
            // condition: R[i] > sum - E[i] - \sum popped E
            while (!heap.empty() && (*heap.begin()).first < removed_E) {
                acc_sum -= 2 * E[(*heap.begin()).second]; // two round
                removed_E += E[(*heap.begin()).second];
                num_removed++;
                heap.erase(heap.begin());
            }
            if (acc_sum > maximum) {
                maximum = acc_sum;
                num_removed_with_maximum = num_removed;
            }
        }
        if (!heap.empty()) {
            // not get stopped -- can go infinitely
            cout << num_removed << " INDEFINITELY" << endl;
        } else {
            cout << num_removed_with_maximum << " " << maximum << endl;
        }
    }
    return 0;
}