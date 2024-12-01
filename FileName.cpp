#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    int k, n;
    fin >> k >> n;
    long long total = 0;

    std::vector<long long> dp(n);
    dp[0] = k;
    dp[1] = k * k;
    for (int i = 2; i < n; ++i) {
        dp[i] = k * (dp[i - 1] + dp[i - 2]);
    }
    for (int i = 0; i < n; ++i) {
        total += dp[i];
    }

    fout << total << std::endl;
    return 0;
}