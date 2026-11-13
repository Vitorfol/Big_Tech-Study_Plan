class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        memory[key].push_back({timestamp, value});
    }


    string get_value_with_bs(const vector<pair<int, string>>& vec, int timestamp_target) {
        /*

        I have a vector of pairs, that are sorted by timestamp (pair.first)
        So it would be something like
        {{1, oi}, {2, tchau}, {3, ola}, {4, goodbye}, ..., {n, hello_again}}
        */

        int l = 0;
        int r = static_cast<int>(vec.size()-1);
        string response = "";

        while (l<=r) {
            int mid = l + (r-l) / 2;
            int mid_timestamp = vec[mid].first;
            if (mid_timestamp == timestamp_target) {
                response = vec[mid].second;
                return response;
            }
            else if (mid_timestamp > timestamp_target) r = mid-1;
            else {
                l=mid+1;
                response = vec[mid].second;
            }
        }

        return response; 
    }
    
    string get(string key, int timestamp) {
        if (!memory.contains(key)) return "";
        return get_value_with_bs(memory[key], timestamp);
    }

private: 
    unordered_map<string, vector<pair<int, string>>> memory;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
