/*
ID: paulo.t1
PROG: fact4
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
int n;
int table[10] = { 1,1,2,6,4,2,2,4,2,8 };

int D(int num) {
  if (num <= 9) return table[num];
  int tens = (num/10) % 10;
  int unit = num%10;
  if (tens % 2 == 1) return 4*D(num/5)*D(unit);
  return 6*D(num/5)*D(unit);
}

int main() {
#ifndef local
  ofstream fout ("fact4.out");
  ifstream fin ("fact4.in");
#endif
  fin >> n;
  ll ans = 1;

  fout << D(n)%10 << endl;

  return 0;
}
