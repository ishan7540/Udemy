#include <bits/stdc++.h>
using namespace std;

void printResult(int n, vector<vector<int>> arr) {
    vector<vector<int>> rnk(3, vector<int>(n + 1));
    for (int t = 0; t < 3; ++t) {
        for (int i = 0; i < n; ++i) {
            rnk[t][arr[t][i]] = i + 1;
        }
    }

    vector<int> t_cnt(3, 0);
    vector<int> wins(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int b_t = -1, b_w = 1e9, b_l = 1e9, win_p = -1;
            
            for (int t = 0; t < 3; ++t) {
                int r1 = rnk[t][i];
                int r2 = rnk[t][j];
                int w = min(r1, r2);
                int l = max(r1, r2);
                
                if (w < b_w || (w == b_w && l < b_l)) {
                    b_w = w;
                    b_l = l;
                    b_t = t;
                    win_p = (r1 < r2) ? i : j;
                }
            }
            
            t_cnt[b_t]++;
            wins[win_p]++;
        }
    }

    cout << t_cnt[0] << " " << t_cnt[1] << " " << t_cnt[2] << "\n";
    for (int i = 1; i <= n; ++i) {
        cout << wins[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}