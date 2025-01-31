#include<iostream>
using namespace std;

int n;
int dp[15];

int main(int argc, char** argv)
{
    cin >> n;
    dp[0] = 2;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i - 1] + (dp[i - 1] - 1);
    }
    cout << dp[n] * dp[n];
    return 0;
}
