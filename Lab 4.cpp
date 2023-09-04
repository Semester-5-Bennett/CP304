#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long factorial(int n)
{
    long long result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

long long nChoosep(int n, int p)
{
    return factorial(n) / (factorial(p) * factorial(n - p));
}

int main()
{
    int n, p;
    cin >> n >> p;

    vector<long long> votes(n);
    for (int i = 0; i < n; i++)
    {
        cin >> votes[i];
    }

    // Sort in descending order
    sort(votes.begin(), votes.end(), greater<long long>());

    // If all votes are the same, it's a special case
    if (votes[0] == votes[n - 1])
    {
        cout << nChoosep(n, p) << endl;
        return 0;
    }

    // Vote count of the pth manager in the sorted list
    long long pthVoteCount = votes[p - 1];

    // Count managers having votes equal to pthVoteCount
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (votes[i] == pthVoteCount)
        {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
