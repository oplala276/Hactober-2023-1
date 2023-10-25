class DisjointSet{
    vector<int>parent, size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i<=n; ++i){
            parent[i] = i;
        }
    }
    int findUpr(int x){
        if(parent[x]!=x){
            parent[x] = findUpr(parent[x]);
        }
        return parent[x];
    }
    void UnionBySize(int u, int v){
        int pu = findUpr(u);
        int pv = findUpr(v);
        if(pv==pu)return ;
        if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv]+=size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        vector<int>ansr;
           for(auto it: edges){
               int u = it[0];
               int v = it[1];
               if(ds.findUpr(u)!=ds.findUpr(v)){
                   ds.UnionBySize(u, v);
               }else{
                   ansr = it;
               }
           }
           return ansr;
    }
};
