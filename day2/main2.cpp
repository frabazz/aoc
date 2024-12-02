#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>


using namespace std;

int issafe(vector<int> v){
  vector<int> v1;
  for(int j = 0;j < v.size(); ++j){
    v1 = vector<int>();
    for(auto x : v)
      v1.push_back(x);
     v1.erase(v1.begin() + j);
    int prev = v1[0];
    int next = v1[1];
    bool increasing = next > prev;
    int diff = abs(next -prev);
    if(diff < 1 || diff > 3)
      continue;
    int line_safe = 1;
    prev = next;
    int i = 2;
    while(i < v1.size()){
      next = v1[i];
      diff = abs(next - prev);
      if(diff < 1 || diff > 3 || next > prev != increasing){
	line_safe = 0;
	break;
      }
      prev = next;
      ++i;
    }

    if(line_safe)
      return 1;
  }
  

  return 0;
}

int main(int argc, char** argv){
  ifstream in("input");
  string line;

  int safe = 0;
  while(getline(in, line)){
    std::istringstream iss(line);
    int i;
    vector<int> v = vector<int>();
    while(iss >> i){
      v.push_back(i);
    }
    safe += issafe(v);
  }

  cout << safe << endl;
}
