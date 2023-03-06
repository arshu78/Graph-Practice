
class DisjointSet {
    
public:
    vector<int> rank,parent;
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int findUPar(int node)
    {
        if(node==parent[node]) return node;

        return parent[node]=findUPar(parent[node]);
    }

    void unionByRank(int u,int v)
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u] ++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail=accounts[i][j];
                
                if(mp.find(mail)==mp.end())
                {
                    mp[mail]=i;
                }
                else
                {
                    ds.unionByRank(i,mp[mail]);
                }
            }
        }
        
        //adding to separete array
        vector<string> merge[n];
        for(auto it: mp)
        {
            string mail=it.first;
            int node=ds.findUPar(it.second);
            merge[node].push_back(mail);
            
        }
        
        //merge them into ans;
        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            if(merge[i].size()==0) continue;
            
            sort(merge[i].begin(),merge[i].end());
            
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto node:merge[i])
            {
                temp.push_back(node);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};