#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int isdig(char c) { return c >= '0' && c <= '9'; }

int main(int argc, char **argv) {
  ifstream in("input");
  char c;
  string pattern = "mul(*,*)";
  string curr = "";

  int res = 0;
  int pair_index = 0;
  int pair[2] = {0, 0};
  bool already_read = false;
  while (already_read || in >> c) {
    if (already_read)
      already_read = false;
    if (pattern[curr.size()] == '*') {
      string digits = "";
      if (isdig(c)) {
        digits += c;
        while (in >> c && isdig(c))
	  digits += c;
        already_read = true;
        if (digits.size() == 0 || digits.size() > 3) {
	  pair_index = 0;
          curr = "";
        } else{
          curr += '*';
	  pair[pair_index] = stoi(digits);
	  pair_index++;
	  
	}
      } else {
	pair_index = 0;
        curr = "";
      }

    } else if (c == pattern[curr.size()]) {
      curr += c;
      if (curr.size() == pattern.size()){
        res+= pair[0] * pair[1];
	curr = "";
	pair_index = 0;
      }

    } else{
      pair_index = 0;
      curr = "";
    }
  }

  cout << res << endl;
  return 0;
}
