vector<vector<vector<int>>> dist;
vector<vector<int>> dp;
vector<pair<int,int>> coins;
int R;
int C;
int allOnes, numCoins;
int MAXDIST = 1000 * 1000;

bool isInRange(int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

void extractCoins(vector<vector<int>> &arr) {
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            if (arr[r][c] == 2)
                coins.push_back({r,c});
}

void setDistances(vector<vector<int>> &arr, int coin) {
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            dist[r][c][coin] = MAXDIST;

    vector<vector<bool>> visited(R,vector<bool>(C,0));
    queue<pair<int,int>> q;
    pair<int,int> startPoint = coins[coin];
    q.push(startPoint);
    visited[startPoint.first][startPoint.second] = 1;
    dist[startPoint.first][startPoint.second][coin] = 0;

    vector<int> dr = {0, -1, 0, 1};
    vector<int> dc = {-1, 0, 1, 0};

    while (!q.empty()) {
        pair<int,int> point = q.front();q.pop();
        int oldR = point.first;
        int oldC = point.second;

        for (int k = 0; k < 4; k++) {
            int newR = oldR + dr[k];
            int newC = oldC + dc[k];
            if (isInRange(newR, newC) && !visited[newR][newC] && arr[newR][newC] != 1) {
                pair<int,int> newPoint = {newR, newC};
                visited[newR][newC] = true;
                dist[newR][newC][coin] = dist[oldR][oldC][coin] + 1;
                q.push(newPoint);
            }
        }
    }
}

int getMinDist(int coin, int seq, int Ra, int Ca) {
    if (seq == allOnes) return dist[Ra][Ca][coin];
    if (dp[coin][seq] != -1) return dp[coin][seq];

    int res = INT_MAX;
    for (int i = 0; i < numCoins; i++)
        if ((seq & (1 << i)) == 0) {
            int newSeq = seq | (1 << i);
            pair<int,int> pos = coins[i];
            res = min(res, getMinDist(i, newSeq, Ra, Ca) + dist[pos.first][pos.second][coin]);
        }
        return dp[coin][seq] = res;
    }

    int minMoves1(vector<vector<int>> &arr, int Ra, int Ca) {
        R = arr.size();
        C = arr[0].size();
        pair<int,int> startPoint = {0, 0};
        coins.push_back(startPoint);
        extractCoins(arr);
        numCoins = coins.size();
        allOnes = (1 << numCoins) - 1;

        int dpR = numCoins;
        int dpC = allOnes + 1;
        dp.resize(dpR,vector<int>(dpC,-1));

        dist.resize(R,vector<vector<int>>(C,vector<int>(numCoins,0)));

        for (int i = 0; i < numCoins; i++)
            setDistances(arr, i);
        int ans = getMinDist(0, 1, Ra, Ca);
        return ans >= MAXDIST ? -1 : ans;

    } 