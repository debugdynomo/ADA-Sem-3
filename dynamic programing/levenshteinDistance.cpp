#include <bits/stdc++.h>
using namespace std;

int main() {
    string a,b;
    cout << "Enter string a: ";
    cin >> a;
    cout << "Enter string b: ";
    cin >> b;

    int n = (int)a.length();
    int m = (int)b.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }for(int i=0;i<=m;i++){
        dp[0][i] = i;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int t1 = dp[i][j+1] + 1;
            int t2 = dp[i+1][j] + 1;
            int t3 = dp[i][j] + (a[i] != b[j]);
            int Min = min(t1,t2);
            dp[i+1][j+1] = min(Min,t3);
        }
    }

    cout << "DP table: " << "\n";

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout << dp[i][j];
        }
        cout << "\n";
    }

    cout << "Minimum edit distance: " << dp[n][m] << "\n";


    cout << "They are namely: " << "\n";

    int i = n , j = m;

    while(i != 0 && j != 0){
        int diagonal_part = dp[i-1][j-1];
        int left_part = dp[i][j-1];
        int top_part = dp[i-1][j];

        int Min = min(diagonal_part,left_part);
        int min_dir = min(Min,top_part);

        if(min_dir == diagonal_part){
            if(a[i-1] != b[j-1]){
                cout << "Edit: " << b[j-1] << " -> " << a[i-1]  << " in string b , at index " << j-1 << "\n";
            }
            i--;j--;
        }else if(min_dir == left_part) {
            cout << "Delete: " << b[j-1] << " from string b , at index " << j-1 << "\n";
            j--;
        }else{
            cout << "Delete: " << a[i-1] << " from string a , at index " << i-1 << "\n";
            i--;
        }
    }

    return 0;
}