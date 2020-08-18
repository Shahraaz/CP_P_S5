#include <unordered_map>/*{{{*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;/*}}}*/

using namespace std;
typedef long long ll;

enum JudgeCode:int{
  judge_error=1,
  correct=42,
  wrong_answer=43,
};

enum Answer{
  valid,
  invalid,
  impossible,
};

bool is_integer(string const &s){
  return all_of(s.begin(), s.end(), ::isdigit);
}

Answer validate(istream &in, vector<int> const &values){
  vector<string> buffer;
  for (string s; in>>s;){
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    buffer.emplace_back(s);
  }

  bool trailing_output=false;
  switch (buffer.size()){
    case 0:{
      cout<<"Team did not output any tokens"<<endl;
      return invalid;
    }
    case 1:{
      if (buffer[0]=="impossible"){
        return impossible;
      }else{
        cout<<"Output one token, but token was not 'impossible'"<<endl;
        return invalid;
      }
    }
    case 2:{
      break;
    }
    default:{
      cout<<"Team output "<<buffer.size()<<" tokens instead of 2."<<endl;
      trailing_output=true;
      break;
    }
  }


  int a,b;
  if (not (is_integer(buffer[0]) and (stringstream{buffer[0]}>>a))
      or not (is_integer(buffer[1]) and (stringstream{buffer[1]}>>b))){
    cout<<"Indices are not integers: "<<buffer[0]<<" "<<buffer[1]<<endl;
    return invalid;
  }
  if (not (a<=b)){
    cout<<"Indices are not in order: "<<a<<" "<<b<<endl;
    return invalid;
  }
  if (not (1<=a and a<=values.size())){
    cout<<"First index is out of bounds [1..."<<values.size()<<"]: "<<a<<endl;
    return invalid;
  }
  if (not (1<=b and b<=values.size())){
    cout<<"Second index is out of bounds [1..."<<values.size()<<"]: "<<b<<endl;
    return invalid;
  }

  vector<int> intent=values;
  sort(intent.begin(),intent.end());

  vector<int> result=values;
  reverse(result.begin()+a-1,result.begin()+b);

  if (intent==result){
    if (trailing_output){
      cout<<"Solution is correct but has trailing output."<<endl;
      return invalid;
    }
    return valid;
  }else{
    cout<<"Array is not sorted after reversing ["<<a<<"..."<<b<<"]"<<endl;
    cout<<"Original: "; for (int i: values) cout<<" "<<i; cout<<endl;
    cout<<"Result:   "; for (int i: result) cout<<" "<<i; cout<<endl;
    return invalid;
  }
}

int main(int argc,char **argv){
  if (argc<3){
    cerr<<"usage: "<<argv[0]<<" testcase.in testcase.ans [feedback]< team.out"<<endl;
    return judge_error;
  }
  else if (argc>3){
    assert(freopen((string(argv[3])+"/judgemessage.txt").c_str(),"w",stdout));
  }
  else if (argc>4){
    cerr<<"warning: ignoring "<<argc-4<<" extra arguments"<<endl;
  }
  ifstream canonical_input(argv[1]);
  ifstream canonical_output(argv[2]);
  auto &team_output = cin;

  // Read input.
  size_t n; assert(canonical_input>>n);
  assert(1<=n and n<=1000000);

  vector<int> values(n);
  for (int i=0; i<n; i++){
    assert(canonical_input>>values[i]);
    assert(1<=values[i] and values[i]<=1'000'000'000);
  }

  auto const expect=validate(canonical_output,values);
  if (expect==invalid) return judge_error;

  auto const team=validate(team_output,values);
  if (team==invalid) return wrong_answer;

  if (team==expect){
    return correct;
  }else if (team==valid){
    cout<<"Team found a solution, but we didn't!"<<endl;
    return judge_error;
  }else{
    cout<<"Team did not find the solution"<<endl;
    return wrong_answer;
  }
}
