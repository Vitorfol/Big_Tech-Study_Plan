#include <bits/stdc++.h>
using namespace std;
/*
 * Complete the 'getRemovableIndices' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING str1
 *  2. STRING str2
    
                
    3, 4, 5
    3, 4
    
    str1 = abdgggda
    str2 = abdggda
    response = {3, 4, 5}
                
    str1 = mmgghh
    str2 = mfggh


    1, 2, 4, 5
    1, 3, 4
    str1= abbabb
    str2= ababb
    
    aba
    ab
 
 */

vector<int> getRemovableIndices(string str1, string str2) {
    int miss_occour = 0;
    int miss_position = -1;
    char miss;
    for (int i=0, j=0; i<static_cast<int>(str1.size()); ++i, ++j) {
        if (str1[i] == str2[j]) continue;
        
        miss_occour++;
        miss_position = i;
        miss = str1[i];
        if (miss_occour > 1) return {-1};
        --j;
    }
    
    if (miss_occour == 0) {
        miss = str1[str1.size()-1];
        miss_position = str1.size()-1;
    }
    
    // now we know what is the character missing
    
    vector<int> solution;
    
     for (int i=miss_position-1; i>=0; --i)  {
        if (str1[i] == miss) solution.push_back(i);
        else break;
     }
     
     reverse(solution.begin(), solution.end());
     solution.push_back(miss_position);
     
     for (int i=miss_position+1; i < static_cast<int>(i<str1.size()); ++i) {
        if (str1[i] == miss) solution.push_back(i);
        else break;
     }
     
     return solution;
     
}

int main()
{
    string str1;
    getline(cin, str1);

    string str2;
    getline(cin, str2);

    vector<int> result = getRemovableIndices(str1, str2);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}
