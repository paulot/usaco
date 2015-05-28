/*
ID: paulo.t1
PROG: test
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#define ll long long
#define local
#ifdef local
#define fin cin
#define fout cout
#endif

using namespace std;

int main() {
#ifndef local
  ofstream fout ("test.out");
  ifstream fin ("test.in");
#endif
  int a, b;
  fin >> a >> b;
  fout << a+b << endl;
  return 0;
}
