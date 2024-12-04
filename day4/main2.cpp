#include <bits/stdc++.h>

using namespace std;

vector<string> matrix;

int is(char c){
  return c == 'S' || c == 'M';
}

int main(int argc, char **argv) {
  ifstream in("input");
  matrix = vector<string>();
  string line;
  vector<string> words = {"XMAS"};
  while (in >> line)
    matrix.push_back(line);

  int occurences = 0;
  for(int i = 1;i < matrix.size() - 1; ++i){
    for(int j = 1;j < matrix[i].size() - 1; ++j){
      if(matrix[i][j] == 'A'){
	char a1 = matrix[i+1][j+1];
	char a2 = matrix[i-1][j-1];
	char b1 = matrix[i+1][j-1];
	char b2 = matrix[i-1][j+1];
	if(is(a1) && is(a2) && a1 != a2)
	  if(is(b1) && is(b2) && b1 != b2)
	    occurences++;
      }
    }
  }
  cout << occurences << endl;
}
