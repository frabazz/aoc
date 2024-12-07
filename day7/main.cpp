#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int combinations(vector<ll>* v, ll i, ll res, ll target){
  if(i == v->size())
    return res == target;
  else{
    if(res > target)
      return 0;
    return
      combinations(v, i+1, res, target) > 0 ? 1 : 
      combinations(v, i+1, res + v->at(i), target) > 0 ? 1 : 
      combinations(v, i+1, res * v->at(i), target);
  }
}

int main(int argc, char** argv){
  ifstream in("input");
  long long out = 0;
  string line;
  while(getline(in, line)){
    istringstream ss = istringstream(line);
    ll target;
    char colon;
    vector<ll> terms = vector<ll>();
    ss >> target;
    ss >> colon;
    ll t;
    while(ss >> t)
      terms.push_back(t);
    ll combs = 0;
    for(int i = 0;i < terms.size(); ++i)
      combs += combinations(&terms, i+1, terms[i], target);
    out += (combs > 0) * target;    
  }

  cout << out << endl;
  return 0;
}
