#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv){
  ifstream in = ifstream("input");
  vector<int> l = vector<int>();
  vector<int> r = vector<int>();
  int x;
  while(in >> x){
    l.push_back(x);
    in >> x;
    r.push_back(x);
  }

  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  int result = 0;
  for(int i = 0;i < r.size(); ++i)
    result += std::abs(r[i] - l[i]);
  cout << result << endl;
  return 0;
}
