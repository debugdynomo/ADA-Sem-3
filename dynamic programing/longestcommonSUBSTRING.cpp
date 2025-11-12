#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cout << "Enter the first string: ";
    cin >> a;
    cout << "Enter the second string: ";
    cin >> b;

    int n = a.length();
    int m = b.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxV = 0;
    int end_i = 0; 

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxV) {
                    maxV = dp[i][j];
                    end_i = i;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nLCS LENGTH : " << maxV << "\n";

    string subseq = a.substr(end_i - maxV, maxV);
    cout << "Longest Common Substring: " << subseq << "\n";

    return 0;
}
