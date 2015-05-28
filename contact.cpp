/*
ID: paulo.t1
PROG: contact
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#define ll long long
#ifdef local
#define fin cin
#define fout cout
#endif

using namespace std;

#ifndef local
  ofstream fout ("contact.out");
  ifstream fin ("contact.in");
#endif

class pmap {
  private:
    map<int, vector<string> > strings;
    int capacity;
    int min_so_far = 0;
    int find_min();
  public:
    void add(int, string);
    void print();
    pmap(int);
};

pmap::pmap(int c) {
  this->capacity = c;
}

void pmap::add(int n, string pattern) {
  if (strings.size() >= capacity) {
    if (n < min_so_far) return;
    strings.erase(min_so_far);
  }
  strings[n].push_back(pattern);
  min_so_far = strings.begin()->first;
}

void pmap::print() {
  if (strings.size() == capacity and strings.size() > 1)
    strings.erase(min_so_far);
  for (auto it = strings.rbegin(); it != strings.rend(); ++it) {
    fout << it->first;
    for (int i = 0; i < it->second.size(); i++) {
      if (i % 6 == 0) fout << '\n';
      fout << it->second[i];
      if (i < it->second.size()-1 and (i+1) % 6 != 0) fout << ' ';
    }
    fout << '\n';
  }
}

int a, b, n;
string seq;

int main() {
  fin >> a >> b >> n;
  string line;
  while (fin >> line) seq += line;
  pmap ans(n+1);

  // For each pattern size we find all patterns of the size
  for (int s = a; s <= b; s++) {
    map<string, int> patterns;
    for (int i = 0; i <= (int) seq.size() - s; i++) {
      // cout << i << ' ' << s << ' ' << seq.size()-s << endl;
      patterns[seq.substr(i, s)]++;
    }
    // Update the ans map
    for (auto &it : patterns) {
      // cout << it.first << ' ' << it.second << endl;
      ans.add(it.second, it.first);
    }
  }

  ans.print();

  return 0;
}
