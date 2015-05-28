/*
ID: paulo.t1
LANG: C++11
TASK: combo
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#define ll unsigned long long
#define cube(n) (n*n*n)


using namespace std;

int main() {
  ofstream fout ("combo.out");
  ifstream fin ("combo.in");
  int n, ja, jb, jc, ma, mb, mc;
  fin >> n >> ja >> jb >> jc >> ma >> mb >> mc;
  int space = (n < 5) ? n : 5;
  int shared[3] = {0};
  int topshare = space - abs(min(ja,ma)+n - max(ja,ma));
  int botshare = space - abs(ja-ma);
  topshare = (topshare < 0) ? 0 : topshare;
  botshare = (botshare < 0) ? 0 : botshare;
  shared[0] = (n <= 5) ? space : botshare+topshare;

  topshare = space - abs(min(jb,mb)+n - max(jb,mb));
  botshare = space - abs(jb-mb);
  topshare = (topshare < 0) ? 0 : topshare;
  botshare = (botshare < 0) ? 0 : botshare;
  shared[1] = (n <= 5) ? space : botshare+topshare;

  topshare = space - abs(min(jc,mc)+n - max(jc,mc));
  botshare = space - abs(jc-mc);
  topshare = (topshare < 0) ? 0 : topshare;
  botshare = (botshare < 0) ? 0 : botshare;
  shared[2] = (n <= 5) ? space : botshare+topshare;

  ll nj = cube(space), nm = cube(space);
  ll num_shared = 1;
  bool has_shared = false;
  for (int i = 0; i < 3; i++)
    if (shared[i] > 0) {
      has_shared = true;
      num_shared *= shared[i];
    }
  if (has_shared)
    fout << nj + nm - num_shared << endl;
  else
    fout << nj + nm << endl;

  return 0;
}
