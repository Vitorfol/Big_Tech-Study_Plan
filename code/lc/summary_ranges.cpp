#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <sstream>

using namespace std;

// Sua classe Solution mantida exatamente como enviada
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> responses;
        if (nums.empty()) return responses;

        if (nums.size() == 1) {
            responses.push_back(to_string(nums[0]));
            return responses;
        }

        map<int, set<int>> mapeamento;
        int count = 1;
        for (int i=0; i<nums.size()-1; i++) {
            mapeamento[count].insert(nums[i]);
            if ((long long)nums[i+1]-nums[i] != 1) count++;
	        mapeamento[count].insert(nums[i+1]);
            }

        for (const auto& [_, valores] : mapeamento) {
            int menor = *valores.begin();
            int maior = *valores.rbegin();
            if (menor == maior) {
                responses.push_back(to_string(menor));
                continue; 
            }
            string str = to_string(menor) + "->" + to_string(maior);
            responses.push_back(str);
        }

        return responses;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    string linha;

    cout << "Digite os numeros separados por espaco e aperte Enter:" << endl;
    getline(cin, linha);

    stringstream ss(linha);
    int numero;
    while (ss >> numero) {
        nums.push_back(numero);
    }

    vector<string> resultado = sol.summaryRanges(nums);

    cout << "Resultado: [ ";
    for (int i = 0; i < resultado.size(); i++) {
        cout << "\"" << resultado[i] << "\"";
        if (i < resultado.size() - 1) cout << ", ";
    }
    cout << " ]" << endl;

    return 0;
}
