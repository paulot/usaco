/*
ID: paulo.t1
PROG: humble
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <limits.h>
#define ll long long
#ifdef local
#define fin cin
#define fout cout
#endif

using namespace std;

int k, n;
int nums[101], indexes[101] = {0}, dp[100001] = {0};

int main() {
#ifndef local
  ofstream fout ("humble.out");
  ifstream fin ("humble.in");
#endif
  fin >> k >> n;
  for (int i = 1; i <= k; i++)
    fin >> nums[i];

  sort(nums+1, nums+k+1);

  dp[0] = 1;

  for (int i = 1; i <= n; i++) {
    int candidate = INT_MAX;
    for (int j = 1; j <= k; j++) {
      while (dp[indexes[j]]*nums[j] <= dp[i-1]) indexes[j]++;
      if (nums[j]*dp[indexes[j]] < candidate) {
        candidate = nums[j] * dp[indexes[j]];
      }
    }
    dp[i] = candidate;
  }
  fout << dp[n] << '\n';

  return 0;
}
