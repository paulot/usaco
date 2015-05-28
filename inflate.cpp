/*
ID: paulo.t1
PROG: inflate
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#define ll long long
#ifdef local
#define fin cin
#define fout cout
#endif

using namespace std;

int nmins, n;
int mins[10001], points[10001];
unsigned int dp[10001];


int main() {
#ifndef local
  ofstream fout ("inflate.out");
  ifstream fin ("inflate.in");
#endif
  fin >> nmins >> n;
  for (int i = 0; i < n; i++) {
    fin >> points[i] >> mins[i];
  }

  for (int i = 0; i < n; i++)
    for (int j = mins[i]; j <= nmins; j++)
      dp[j] = max(dp[j], dp[j-mins[i]] + points[i]);

  fout << dp[nmins] << endl;

  return 0;
}
