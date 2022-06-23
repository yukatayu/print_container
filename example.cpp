#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <tuple>

#include "print_container.hpp"

int main(){
    using namespace std;
    
    int i = 5;
    string s = "abc";
    
    vector<int> iv = {2, 3, 4};
    vector<string> sv = {"def", "ghi"};
    
    set<int> is = {2, 3, 4};
    set<string> ss = {"def", "ghi"};
    
    map<int,string> im = {{10,"ten"}, {11,"eleven"}, {12,"twelve"}};
    map<string, pair<int,int>> sm = {{"alice"s,make_pair(41,42)}, {"bob"s,make_pair(51,52)}};
    
    std::vector<std::vector<int>> ivv = {{1,2,3}, {4,5,6}, {7,8,9}};
    std::vector<std::vector<string>> svv = {{"a","b","c"}, {"d","e","f"}, {"g","h","i"}};
    
    std::tuple<std::string, int, float> t = {"abc", 5, 3.14};

    out(i);
    out(s);
    
    out(iv);
    out(sv);
    
    out(is);
    out(ss);
    
    out(im);
    out(sm);
    
    out(ivv);
    out(svv);
    
    // out(t);  tuple は未対応
}
