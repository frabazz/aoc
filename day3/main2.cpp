#include <cctype>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main(int argc, char **argv) {
  ifstream in("input");
  std::string s;
  char c;
  while (in >> c)
    s += c;
  std::regex expr("(mul\\(([0-9]{1,3},[0-9]{1,3})\\))|(do(n't)?\\(\\))",
                  std::regex_constants::ECMAScript);
  int sum = 0;
  auto begin = sregex_iterator(s.begin(), s.end(), expr);
  auto end = sregex_iterator();
  int enable = 1;
  for (auto it = begin; it != end; ++it) {
    string m = it->str();
    if (m == "do()")
      enable = 1;
    else if (m == "don't()")
      enable = 0;
    else {
      m.erase(remove_if(m.begin(), m.end(),
                        [](char x) { return x != ',' && !isdigit(x); }),
              m.end());
      auto comma = m.find(',');
      int a = stoi(m.substr(0, comma));
      int b = stoi(m.substr(comma + 1, m.npos));
      sum += a * b * enable;
    }
  }

  cout << sum << endl;
  return 0;
}
