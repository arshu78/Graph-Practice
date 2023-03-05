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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra=0;
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];
            
            if(ds.findUPar(u)==ds.findUPar(v)) extra++;
            else
            {
                ds.unionByRank(u,v);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
            cnt++;
        }
        if(extra>=cnt-1)return cnt-1;
        return -1;
    }
};