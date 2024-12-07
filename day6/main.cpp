#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  enum cell {
    empty,
    obst,
  };

  ifstream in("input");
  string line;
  auto matrix = vector<vector<cell>>();
  pair<int, int> pos;
  int i = 0;
  while (in >> line) {
    vector<cell> v = vector<cell>();
    for (auto c = line.begin(); c != line.end(); ++c) {
      if (*c == '.')
        v.push_back(empty);
      else if (*c == '#')
        v.push_back(obst);
      else {
        v.push_back(empty);
        pos = {i, c - line.begin()};
      }
    }
    matrix.push_back(v);
    ++i;
  }

  bool exit = false;
  int cycle[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  int dir = 0;

  /*
    [-1 0] -> [0, 1] -> [1, 0] -> [0, -1]

   */

  int res = 0;
  auto not_visited = vector<vector<bool>>();
  for(auto r : matrix)
    not_visited.push_back(vector<bool>(r.size(), 1));
  
  while (!exit) {
    int i = pos.first + cycle[dir][0];
    int j = pos.second + cycle[dir][1];

    if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size())
      exit = true;
    else if (matrix[i][j] == empty) {
      pos = {i, j};
      res += not_visited[i][j];
      if (not_visited[i][j] == 1)
        not_visited[i][j] = 0;
    } else{
      dir = (dir + 1) % 4;
      cout << "new dir: " << dir << endl;
    }
  }
 
  cout << res << endl;
  return 0;
}
