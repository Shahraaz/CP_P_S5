#include <algorithm>
#include <iostream>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <string>
#include <vector>
#include <tuple>
using namespace std;
typedef long long ll;

vector<int32_t> const IMPOSSIBLE={-123456789};

constexpr bool check_bounds(int32_t const x){
  return 0 <= x and x <= 1'000'000'000;
}

bool is_integer(string const &s){
  return all_of(s.begin(), s.end(), ::isdigit);
}

enum JudgeCode:int{
  judge_error=1,
  correct=42,
  wrong_answer=43,
};

vector<int32_t> read_answer(
    istream &in,
    vector<pair<int32_t,int32_t>> const &sheets,
    vector<int32_t> const &existing_pegs,
    string const &party,
    JudgeCode failure_code){

  // Get the output tokens. Just "impossible" is special-cased to a magic number.
  vector<string> buffer;
  for (string s; in>>s;){
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    buffer.emplace_back(s);
  }
  if (buffer.empty()){
    cout<<party<<" output nothing"<<endl;
    exit(failure_code);
  }
  if (buffer[0]=="impossible"){
    if (buffer.size()!=1){
      cout<<party<<" output extra tokens after "<<buffer[0]<<endl;
      exit(failure_code);
    }
    return IMPOSSIBLE;
  }

  // Get team's claimed answer (should match the number of tokens).
  int answer;
  {
    if (not (is_integer(buffer[0]) and (stringstream{buffer[0]}>>answer))){
      cout<<party<<" did not output a number of pegs"<<endl;
      exit(failure_code);
    }
    if (answer<0 or buffer.size()!=answer+1){
      cout<<party<<" output wrong number of pegs "<<answer<<" (output "<<buffer.size()-1<<" numbers)"<<endl;
      exit(failure_code);
    }
    if (answer>2*sheets.size()){
      cout<<party<<" output way too many pegs: "<<answer<<" (there are "<<sheets.size()<<" sheets)"<<endl;
      exit(failure_code);
    }
  }

  // Read the full answer in.
  vector<int32_t> res;
  for (int i=0; i<answer; i++){
    if (i+1>=buffer.size()){
      cout<<"Ran out of tokens parsing "<<party<<" output"<<endl;
      exit(failure_code);
    }
    int32_t x;
    if (not (is_integer(buffer[i+1]) and (stringstream{buffer[i+1]}>>x))){
      cout<<"Token "<<i+1<<" in "<<party<<" output ("<<buffer[i+1]<<") is not a number"<<endl;
      exit(failure_code);
    }
    if (not check_bounds(x)){
      cout<<"Output peg "<<x<<" is out of bounds"<<endl;
      exit(failure_code);
    }
    res.emplace_back(x);
  }

  // Validate the answer with a sweep-line algorithm.
  res.insert(res.end(),existing_pegs.begin(),existing_pegs.end());
  sort(res.begin(),res.end());

  // Start by checking no two pegs are excessively close to each other.
  for (int i=1; i<res.size(); i++){
    if (res[i]==res[i-1]){
      cout<<party<<" has multiple pegs at x="<<res[i]<<endl;
      exit(failure_code);
    }
  }

  // sheet_events[i] = {x, open|x|close, sheet}
  vector<tuple<int32_t,int8_t,int32_t>> sheet_events;
  for (int i=0; i<sheets.size(); i++){
    sheet_events.emplace_back(sheets[i].first,-1,i);
    sheet_events.emplace_back(sheets[i].second,+1,i);
  }
  sort(sheet_events.begin(),sheet_events.end());

  vector<int32_t> seen(sheets.size());
  for (int i=0,j=0,total=0; j<sheet_events.size();)
    if (i<res.size() and (j==sheet_events.size() or make_tuple(res[i],0,0)<=sheet_events[j])){
      ++total;
      ++i;
    }else{
      auto const evt_type=get<1>(sheet_events[j]);
      auto const evt_id=get<2>(sheet_events[j]);
      if (evt_type==-1)
        seen[evt_id]-=total;
      else if (evt_type==+1)
        if ((seen[evt_id]+=total)!=2){
          cout<<party<<" used pegs="<<seen[evt_id]<<" in sheet "<<evt_id+1<<endl;
          exit(failure_code);
        }
      ++j;
    }

  return res;
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
  vector<pair<int32_t,int32_t>> sheets;
  for (size_t i=0; i<n; i++){
    int32_t a,b; assert(canonical_input>>a>>b);
    assert(check_bounds(a) and check_bounds(b));
    assert(a<=b);
    sheets.emplace_back(a,b);
  }
  size_t p; assert(canonical_input>>p);
  vector<int32_t> pegs;
  for (size_t i=0; i<p; i++){
    int32_t x; assert(canonical_input>>x);
    assert(check_bounds(x));
    pegs.emplace_back(x);
  }

  // Read expected and team answers.
  auto const expect = read_answer(canonical_output, sheets, pegs, "Jury", judge_error);
  auto const team = read_answer(team_output, sheets, pegs, "Team", wrong_answer);

  if (expect==IMPOSSIBLE){
    if (team==IMPOSSIBLE){
      return correct;
    }else{
      cout<<"Team found a solution, but jury didn't!"<<endl;
      return judge_error;
    }
  }else if (team==IMPOSSIBLE){
    cout<<"Jury has a solution, but team didn't find it"<<endl;
    return wrong_answer;
  }else{
    if (team.size()==expect.size()){
      return correct;
    }else if (team.size()<expect.size()){
      cout<<"Jury found a solution ("<<expect.size()<<"), but team's is better ("<<team.size()<<")!"<<endl;
      return judge_error;
    }else{
      cout<<"Team found a solution ("<<team.size()<<"), but jury's is better ("<<expect.size()<<")"<<endl;
      return wrong_answer;
    }
  }
}
