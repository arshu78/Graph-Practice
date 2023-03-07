class DisjointSet {

public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        
        DisjointSet ds(n*n);
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(grid[row][col]==0) continue;
                
                int dr[]={-1,0,+1,0};
                int dc[]={0,+1,0,-1};
                
                for(int i=0;i<4;i++)
                {
                    int nrow=row +dr[i];
                    int ncol=col + dc[i];
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1)
                    {
                        int node=row * n+col;
                        int newnode=nrow * n +ncol;
                        ds.unionBySize(node,newnode);
                    }
                }
            }
        }
        
        
        //step 2 for 0's 
        int mx=0;
        
         for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(grid[row][col]==1) continue;
                
                int dr[]={-1,0,+1,0};
                int dc[]={0,+1,0,-1};
                
                set<int> components;
                for(int i=0;i<4;i++)
                {
                    int nrow=row +dr[i];
                    int ncol=col + dc[i];
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1)
                    {
                        components.insert(ds.findUPar(nrow * n +ncol));
                    }
                }
                
                int sizeNo=1;
                for(auto it:components)
                {
                    sizeNo+=ds.size[it];
                }
                mx=max(mx,sizeNo);
            }
        }
        
        for(int i=0;i<n*n;i++)
        {
            mx=max(mx,ds.size[ds.findUPar(i)]);
        }
        
        return mx; 
    }
};