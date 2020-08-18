#include <bits/stdc++.h>
using namespace std;

struct Solution{
  bool solved;
  optional<int64_t> res;
};

template <int N>
constexpr array<int64_t,N> const_sort(array<int64_t,N> a){
  for (int i=0; i<N; i++)
    for (int j=1; j<N; j++)
      if (a[j]<a[j-1])
        swap(a[j],a[j-1]);
  return a;
}

constexpr Solution solve(array<int64_t,4> v,int64_t const n){
  auto const [a,b,c,d] = const_sort<4>(v); // std::sort not allowed until C++20
  if (b+c+d <= 3*n) return {true,nullopt};
  if (a+b+c >  3*n) return {false,nullopt};
  return {true,n*3-b-c};
}

template <int N>
auto read_fixeds(){
  array<int64_t,N> res;
  for (int i = 0; i < N; i++) {
    int64_t a,b; char c; assert(cin>>a>>c>>b);
    res[i] = a*100 + b;
  }
  return res;
}

int main(){
  auto const [a,b,c,d] = read_fixeds<4>();
  auto const [n] = read_fixeds<1>();
  auto const [solved, solution] = solve({a,b,c,d}, n);
  if (solution){
    printf("%.2Lf\n",solution.value() / 100.L);
  }else{
    puts(solved? "infinite": "impossible");
  }
}
