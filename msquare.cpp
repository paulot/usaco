/*
ID: paulo.t1
PROG: msquare
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <algorithm>
#include <array>
#define ll long long
#ifdef local
#define fin cin
#define fout cout
#endif
using namespace std;
string finstr;


#ifndef local
  ofstream fout ("msquare.out");
  ifstream fin ("msquare.in");
#endif

struct tup {
  string steps;
  string seq;
};

void ctup(tup &t1, tup &t2) {
  t2.steps = t1.steps;
  t2.seq = t1.seq;
}

void A(string &str) {
  for (int i = 0; i < 4; i++) {
    swap(str[i], str[7-i]);
  }
}

void B(string &arr) {
  char t = arr[3];
  for (int i = 2; i >= 0; i--)
    arr[i+1] = arr[i];
  arr[0] = t;

  t = arr[4];
  for (int i = 4; i < 7; i++)
    arr[i] = arr[i+1];
  arr[7] = t;
}

void C(string &arr) {
  swap(arr[1], arr[2]);
  swap(arr[5], arr[6]);
  swap(arr[1], arr[5]);
}

void print(string &arr) {
  for (int i = 0; i < 4; i++)
    cout << arr[i] << ' ';
  cout << endl;
  for (int i = 7; i >= 4; i--)
    cout << arr[i] << ' ';
  cout << endl; 
}


void bfs() {
  queue<tup> Q;
  set<string> visited;
  tup s;
  s.seq="12345678";
  Q.push(s);
  visited.insert(s.seq);

  while (true) {
    tup cur = Q.front();
    Q.pop();

    if (cur.seq == finstr) {
      fout << cur.steps.size() << '\n';
      for (int i = 0; i < cur.steps.size(); i++) {
        fout << cur.steps[i];
        if (i%60 == 0 and i > 0) fout << '\n';
      }
      fout << '\n';
      return;
    }

    // Do other permutations
    tup a;
    ctup(cur, a);
    A(a.seq);
    if (visited.find(a.seq) == visited.end()) {
      visited.insert(a.seq);
      a.steps += 'A';
      Q.push(a);
    }

    tup b;
    ctup(cur, b);
    B(b.seq);
    if (visited.find(b.seq) == visited.end()) {
      visited.insert(b.seq);
      b.steps += 'B';
      Q.push(b);
    }

    tup c;
    ctup(cur, c);
    C(c.seq);
    if (visited.find(c.seq) == visited.end()) {
      visited.insert(c.seq);
      c.steps += 'C';
      Q.push(c);
    }
  }
}


int main() {
  char c;
  for (int i = 0; i < 8; i++) {
    fin >> c;
    finstr += c;
  }

  bfs();

  return 0;
}
