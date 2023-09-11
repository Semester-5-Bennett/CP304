#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    // defining the two vector
    // line1 & line2
    vector<int> line1(n), line2(n);
    for (int i = 0; i < n; i++) {
        cin >> line1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> line2[i];
    }

    // defining the 2D dynamic vector
    vector<vector<int>> dp(n, vector<int>(2));

    // for searching in the line 1 & line 2
    dp[0][0] = line1[0];
    dp[0][1] = line2[0];

    // defining the function
    int maxTotalHeight = max(dp[0][0], dp[0][1]);

    // finding the maximum height
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][1] + line1[i], dp[i - 1][0]);
        dp[i][1] = max(dp[i - 1][0] + line2[i], dp[i - 1][1]);
        maxTotalHeight = max(maxTotalHeight, max(dp[i][0], dp[i][1]));
    }

    cout << maxTotalHeight << endl;

    return 0;
}
