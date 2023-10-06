/*
    Your Timebased object will be instantiated and called as such:

    Timebased* obj = new Timebased();
    obj->setKey(key,value,timestamp);
    string ans = obj->getValue(targetKey,targetTimestamp);
*/
#include <bits/stdc++.h>
class Timebased {
    public:
        map<string,map<int,string,greater<int>>> mp;
        Timebased() {
            // Intialise your data structure here.
            string Key,Value;
            int Timestamp;
        }

    void setKey(string key, string val, int timestamp) {
        // Write your code here.
        mp[key][timestamp] = val;
    }

    string getValue(string targetKey, int targetTimestamp) {

        if(mp.count(targetKey)==0) return "-1";

        auto it = mp[targetKey].lower_bound(targetTimestamp);

        if(it == mp[targetKey].end()) return "-1";

        return it -> second;
    }
};
