#include <vector>

using namespace std;

class Solution {
    struct Node {
        int prod;
        long long cnt[5];
        
        Node() {
            prod = 1;
            for(int i = 0; i < 5; ++i) {
                cnt[i] = 0;
            }
        }
    };
    
    int k_mod;
    vector<Node> tree;
    Node mergeNodes(const Node& a, const Node& b) {
        Node res{};
        res.prod = (a.prod * b.prod) % k_mod;
    
        for (int r = 0; r < k_mod; r++) {
            res.cnt[r] += a.cnt[r];
        }
        
        for (int r = 0; r < k_mod; r++) {
            int nr = (a.prod * r) % k_mod;
            res.cnt[nr] += b.cnt[r];
        }
        return res;
    }

    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node].prod = nums[start] % k_mod;
            tree[node].cnt[tree[node].prod] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(nums, 2 * node + 1, start, mid);
        build(nums, 2 * node + 2, mid + 1, end);
        tree[node] = mergeNodes(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = Node(); 
            tree[node].prod = val % k_mod;
            tree[node].cnt[tree[node].prod] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node + 1, start, mid, idx, val);
        } else {
            update(2 * node + 2, mid + 1, end, idx, val);
        }
        tree[node] = mergeNodes(tree[2 * node + 1], tree[2 * node + 2]);
    }

    Node query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return Node(); 
        
        if (l <= start && end <= r) return tree[node];
        
        int mid = start + (end - start) / 2;
        return mergeNodes(
            query(2 * node + 1, start, mid, l, r),
            query(2 * node + 2, mid + 1, end, l, r)
        );
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        k_mod = k;
        
        tree.assign(4 * n, Node());
        build(nums, 0, 0, n - 1);
        
        vector<int> result;
        result.reserve(queries.size());
        
        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start_i = q[2];
            int x_i = q[3];
            
            update(0, 0, n - 1, idx, val);
            Node res = query(0, 0, n - 1, start_i, n - 1);
            
            result.push_back(res.cnt[x_i]);
        }
        return result;
    }
};