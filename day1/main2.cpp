#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv){
  ifstream in = ifstream("input");
  vector<int> l = vector<int>();
  vector<int> r = vector<int>();
  const int N = 100000;
  int number[N];

  for(int i = 0;i < N; ++i)
    number[i] = 0;
  
  int x;
  while(in >> x){
    l.push_back(x);
    in >> x;
    r.push_back(x);
  }
  int result = 0;
  for(auto x : r)
    number[x]++;
  for(auto x : l){
    result += x * number[x];
  }
    
  cout << result << endl;
  return 0;
}
