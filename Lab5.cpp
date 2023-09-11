#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> line1(n), line2(n);
    for (int i = 0; i < n; i++) {
        cin >> line1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> line2[i];
    }

    vector<vector<int>> dp(n, vector<int>(2));

    dp[0][0] = line1[0];
    dp[0][1] = line2[0];

    int maxTotalHeight = max(dp[0][0], dp[0][1]);

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][1] + line1[i], dp[i - 1][0]);
        dp[i][1] = max(dp[i - 1][0] + line2[i], dp[i - 1][1]);
        maxTotalHeight = max(maxTotalHeight, max(dp[i][0], dp[i][1]));
    }

    cout << maxTotalHeight << endl;

    return 0;
}
