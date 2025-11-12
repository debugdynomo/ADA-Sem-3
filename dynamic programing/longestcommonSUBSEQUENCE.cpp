//LCS problem using DP memoization
#include <bits/stdc++.h>
using namespace std;

int main() {
    string a,b;
    cout << "Enter the first string: ";
    cin >> a;
    cout << "Enter the second string: ";
    cin >> b;
    int n = a.length();
    int m = b.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i] == b[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            }else{
                dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }

    cout << "''" << " ";
    for(char c : b) {
        cout << c << " ";
    }
    cout << "\n";
    for(int i=0;i<n+1;i++){
        if(i == 0) cout << "''" << " ";
        else cout << a[i] << " ";
        for(int j=0;j<m+1;j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "LCS LENGTH : " << dp[n][m] << "\n";
    string subseq = "";
    int i = n;int j = m;
    while(i != 0 && j != 0){
        if(a[i-1] == b[j-1]){
            subseq += a[i-1];
            i--;
            j--;
        }else{
            if(dp[i][j-1] > dp[i-1][j]){
                j--;
            }else{
                i--;
            }
        }
    }
    reverse(subseq.begin(),subseq.end());
    cout << subseq << "\n";
    return 0;
}