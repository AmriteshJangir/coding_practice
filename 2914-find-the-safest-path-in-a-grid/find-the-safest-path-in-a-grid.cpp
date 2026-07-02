const int N = 160000;
int Root[N], Rank[N];
static int d[5] = {0, 1, 0, -1, 0};

class UnionFind {
public:
    UnionFind(int n){
        iota(Root, Root+n, 0);
        memset(Rank, 0, n*sizeof(int));
    }

    int Find(int x) {
        return (x == Root[x]) ? x : Root[x] = Find(Root[x]);
    }

    bool Union(int x, int y) {
        x = Find(x), y = Find(y);
        if (x == y) return false;
        if (Rank[x] > Rank[y]) swap(x, y);
        Root[x] = y;
        if (Rank[x] == Rank[y]) Rank[y]++;
        return true;
    }

    bool connected(int x, int y) {
        return Find(x) == Find(y);
    }
};

int L1[N];
int nxt[N];

inline void insert(int L, int idx){
    nxt[idx] = L1[L];
    L1[L] = idx;
}

class Solution {
public:
    using int2 = pair<int, int>;

    inline static int to1d(int i, int j, int n) {
        return i * n + j;
    }

    static int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n-1][n-1]) return 0;

        queue<int2> q;

        memset(L1, -1, sizeof(L1));
        memset(nxt, -1, sizeof(nxt));

        // Step 1: Multi-source BFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    q.emplace(i, j);
                    insert(0, to1d(i, j, n)); // ✅ FIX
                } else {
                    grid[i][j] = -1;
                }
            }
        }

        int dist = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                auto [i, j] = q.front(); q.pop();

                for (int b = 0; b < 4; b++) {
                    int r = i + d[b], c = j + d[b+1];
                    if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != -1)
                        continue;

                    grid[r][c] = dist + 1;
                    q.emplace(r, c);
                    insert(dist + 1, to1d(r, c, n));
                }
            }
            dist++;
        }

        // Step 2: Union-Find
        UnionFind uf(n * n);

        for (int dd = dist - 1; dd >= 0; dd--) {
            for (int idx = L1[dd]; idx != -1; idx = nxt[idx]) {

                int i = idx / n;
                int j = idx % n;

                for (int b = 0; b < 4; b++) {
                    int r = i + d[b], c = j + d[b+1];
                    if (r < 0 || r >= n || c < 0 || c >= n)
                        continue;

                    if (grid[r][c] >= dd) {
                        uf.Union(to1d(i,j,n), to1d(r,c,n));
                    }
                }
            }

            if (uf.connected(0, n*n - 1))
                return dd;
        }

        return 0;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 'c';
}();