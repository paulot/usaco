/*
ID: paulo.t1
PROG: kimbits
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#define ll long long
#define uint unsigned int
#ifdef local
#define fin cin
#define fout cout
#endif

using namespace std;

ll dp[32][32];

int main() {
#ifndef local
  ofstream fout ("kimbits.out");
  ifstream fin ("kimbits.in");
#endif
  for (int i = 0; i < 32; i++)
    dp[0][i] = 1, dp[1][i] = 1, dp[i][0] = 1;

  for (int n = 2; n < 32; n++)
    for (int k = 1; k < 32; k++)
      dp[n][k] = dp[n-1][k-1] + dp[n-1][k];

  /*
  for (int n = 1; n < 32; n++) {
    for (int k = 1; k < 32; k++) {
      cout << dp[n][k] << ' ';
    }
    cout << endl;
  }*/

  uint n, l, i;
  fin >> n >> l >> i;

  string ans(n, ' ');
  for (int ni = n; ni >= 0; ni--) {
    if (dp[ni][l] < i) {
      i -= dp[ni][l];
      l--;
      ans[n-ni] = '1';
    } else {
      ans[n-ni] = '0';
    }
  }
  fout << ans << endl;

  return 0;
}
