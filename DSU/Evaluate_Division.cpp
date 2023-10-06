#include<bits/stdc++.h>
class DSU{
private:
    
    vector<int> root;
    vector<int> rank;
    vector<double> mult;
    
public:
    
    DSU(int _size){
        for(int i = 0; i < _size; i++){
            root.push_back(i);
            rank.push_back(1);
            mult.push_back(1);
        }
    }
    
    // customized find to update mult[x] when we update root[x]
    pair<int, double> find(int x){
        if(x == root[x]) return {x , 1};
        int rootX;
        double multX;
        tie(rootX, multX) = find(root[x]);
        
        return {root[x] = rootX, mult[x] *= multX};
    }
    
    //customized union
    void unionSet(int x, int y, double div){
        int rootX = find(x).first;
        int rootY = find(y).first;
        
        if(rootX == rootY) return;
        
        if(rank[rootX] < rank[rootY]){
            root[rootX] = rootY;
            mult[rootX] = (mult[y] / mult[x]) * div;
        }
        else if(rank[rootX] > rank[rootY]){
            root[rootY] = rootX;
            mult[rootY] = mult[x] / (mult[y] * div);
        }
        else{
            root[rootX] = rootY;
            mult[rootX] = (mult[y] / mult[x]) * div;
            rank[rootY]++;
        }
    }
    
    bool isConnected(int x, int y){
        return find(x).first == find(y).first;   
    }
};

vector<double> evaluateEquations(vector<pair<string, string>> &equations, vector<pair<string, string>> &queries, vector<double> &values) {
    // Write your code here.
    int id = 0;
        vector<double> answers;
        // creating an id for each variable:
        unordered_map<string, int> ids;
        for(auto& equation : equations){
            if(ids.find(equation.first) == ids.end()) ids[equation.first] = id++;
            if(ids.find(equation.second) == ids.end()) ids[equation.second] = id++;
        }
        
        DSU dsu = *new DSU(id);
        
        // connecting components
        for(int i = 0; i < equations.size(); i++){
            dsu.unionSet(ids[equations[i].first], ids[equations[i].second], values[i]);
        }
        
        // inserting  -1 when some variable does not exist in our DSU or when both variables are not connected
        // Otherwise we insert the result of the division of the multipliers.
        for(auto& query : queries){
            if(ids.find(query.first) == ids.end() || ids.find(query.second) == ids.end()){
                answers.push_back(-1);
            }
            else{
                int x = ids[query.first];
                int y = ids[query.second];
                if(!dsu.isConnected(x, y)) answers.push_back(-1);
                else answers.push_back(dsu.find(x).second / dsu.find(y).second);
            }
        }
        
        return answers;
        
}
