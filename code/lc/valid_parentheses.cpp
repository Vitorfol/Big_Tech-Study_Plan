class Solution {
public:
    bool charachters_correspond (char c1, char c2) { // O(1) also for time and memory complexity
        if ((c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}') || (c1 == '(' && c2 == ')')) return true;
        return false;
    }

    bool is_opening(char character) { // O(1) also for time and memory complexity
    if (character == '[' || character == '{' || character == '(') return true;
    return false; 
    }

    bool isValid(string str) {
    // Input: [ { } ]				                  

        stack<char> stack_of_symbols;
        
        for (size_t i=0; i<str.size(); ++i) { // O(n) for time complexity and memory complexity
            if (is_opening(str[i])) {
                stack_of_symbols.push(str[i]);
    }
    else {
    char current = str[i]; 
    if (stack_of_symbols.empty()) return false;
    char top = stack_of_symbols.top(); 
    if (!charachters_correspond(top, current)) return false; 
    else stack_of_symbols.pop();
    }	
    }

    if (stack_of_symbols.empty()) return true;
    return false; 
    }

};
