#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char** argv){
  ifstream in("input");
  string line;

  int safe = 0;
  while(getline(in, line)){
    std::istringstream iss(line);
    int prev, next;
    iss >> prev;
    iss >> next;
    bool increasing = next > prev;
    int diff = abs(next-prev);
    if(diff < 1 || diff > 3)
      continue;
    prev = next;
    int line_safe = 1;
    while(iss >> next){
      //printf("prev : %d, next : %d\n", prev, next);
      diff = abs(next - prev);
      if(diff < 1 || diff > 3 || next > prev != increasing){
	line_safe = 0;
	break;
      }
      prev = next;
    }

    safe += line_safe;
  }

  cout << safe << endl;
}
