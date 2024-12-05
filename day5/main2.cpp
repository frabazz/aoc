#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int main(int argc, char **argv) {
  ifstream in("input");
  string line;

  map<int, vector<int>> before = map<int, vector<int>>();
  int out = 0;
  while (in >> line) {
    auto occ = line.find('|');
    if (line.find('|') != line.npos) {
      int a = stoi(line.substr(0, occ));
      int b = stoi(line.substr(occ + 1, line.npos));

      before[b].push_back(a);
    } else if (line.find(',')) {
      istringstream iss(line);
      int x;
      char comma;
      vector<int> v = vector<int>();
      while (iss >> x) {
        v.push_back(x);
        iss >> comma;
      }

      int i;
      int ris = 1;
      for (i = 0; ris && i < v.size() - 1; ++i)
        for (int j = i + 1; ris && j < v.size(); ++j) {
          auto found = find(before[v[i]].begin(), before[v[i]].end(), v[j]);
          if (found != before[v[i]].end())
            ris = 0;
        }

      if (!ris) {
        sort(v.begin(), v.end(), [&before](int a, int b) {
          return find(before[b].begin(), before[b].end(), a) != before[b].end();
        });

        out += v[v.size() / 2 + v.size() % 2 - 1];
      }
    }
  }
  cout << out << endl;
}
