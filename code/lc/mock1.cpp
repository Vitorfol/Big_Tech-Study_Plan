/*

My main task: find how many groups there are in my string of symbols

There anot uper case char.
Equal symbols are always grouped together

input: aaabccccccdd
output: 4 

input: ""

*/

#include <bits/stdc++.h>
#include <cassert>
using namespace std;

int size_of_set(const unordered_set<char>& structure) {
    return static_cast<int>(structure.size());
}


int number_of_groups(string str) {
    
    unordered_set<char> structure;
    for (char character : str) structure.insert(character);
    return size_of_set(structure);
}

int main() {
    assert(number_of_groups("aaabccccccdd") == 4);
    assert(number_of_groups("o") == 1);
    assert(number_of_groups("aabb") == 2);
    assert(number_of_groups("") == -1);
}
