#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  ifstream in("input");
  vector<string> matrix = vector<string>();
  string line;
  string word = "XMAS";
  while (in >> line)
    matrix.push_back(line);

  int occurences = 0;
  vector<vector<int>> moves = vector<vector<int>>();
    
  for (int i = -1; i <= 1; ++i)
    for (int j = -1; j <= 1; j++)
      if (i != 0 || j != 0)
	moves.push_back({i, j});

  for (int i = 0; i < matrix.size(); ++i)
    for (int j = 0; j < matrix[i].size(); ++j)      
        if (matrix[i][j] == word[0]) {
          for (auto move : moves) {
            int k;
            for (k = 1;k < word.size(); ++k){
	      int x = i + k*move[0];
	      int y = j + k *move[1];
	      if(y < 0 || y >= matrix[i].size() || x < 0 || x >= matrix.size() || word[k] != matrix[x][y])
	      break;
	    }
	    if(k == word.size())
	      occurences++;
          }
        }
   
  cout << occurences << endl;
}
