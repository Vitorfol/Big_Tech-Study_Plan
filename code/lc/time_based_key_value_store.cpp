class TimeMap {
public:

    TimeMap(){}

    pair<int, string> binarySearch(vector<pair<int, string>>& vec, int timestamp_target) {
        int l = 0;
        int r = vec.size()-1;
        pair<int, string> best_match = make_pair(0, "");


        while (l<=r) {
            int mid_index = l + (r-l) / 2;
            pair<int, string> mid = vec[mid_index];
            int curr_timestamp = mid.first;

            if (curr_timestamp < timestamp_target) {
                best_match = mid;
                l = mid_index+1;
            }
            else if (curr_timestamp > timestamp_target) r = mid_index-1;
            else return mid;
        }

        return best_match;
    }

    void set(string key, string value, int timestamp) {
        mapeamento[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int count = mapeamento.count(key);
        if (count == 0) return "";

        pair<int, string> result = binarySearch(mapeamento[key], timestamp);
        return result.second;
    }

private: 
    unordered_map<string, vector<pair<int, string>>> mapeamento;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */