 #include<bits/stdc++.h> 

class DSU{
private: 
    unordered_map<string, string> parent;
    unordered_map<string, int> rank;
    
public:
    DSU(vector<vector<string>>& dictionary){
        for(auto words: dictionary){
            string word1 = words[0];
            string word2 = words[1];
            if(!exists(word1)){
                parent[word1] = word1;
                rank[word1] = 1;                                
            }
            
            if(!exists(word2)){
                parent[word2] = word2;
                rank[word2] = 1;
            }            
      }            
        
        for(auto words : dictionary){
            string word1 = words[0];
            string word2 = words[1];
            unionByRank(word1, word2);
        }
    }
    
    bool exists(string word){
        if(parent.find(word) == parent.end())
            return false;
        return true;
    }
    
    string find(string word){
        if(parent[word] == word) return word;
        return parent[word] = find(parent[word]);
    } 
    
    void unionByRank(string u, string v){
        string pu = find(u);
        string pv = find(v);
        if(pu != pv){
            if(rank[pu] < rank[pv]){
                parent[pu] = pv;
            }else if(rank[pv] < rank[pu]){
                parent[pv] = pu;
            }else{
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    }
   
};

bool identicalSentences(vector<string> word1, vector<string> word2, vector<vector<string>> pairs, int n, int m, int p) {
    if(n!=m) return false;
    
    DSU dictionary(pairs);
    
    for(int i=0; i<n; i++){
        if(word1[i] == word2[i]) continue;
        if(!dictionary.exists(word1[i]) 
           || !dictionary.exists(word2[i]) 
           || dictionary.find(word1[i]) != dictionary.find(word2[i])){
            return false;
        }   
    }
    
    
    return true;
}
