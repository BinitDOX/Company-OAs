struct Point {
    int x, y;
    Point(int x, int y): x(x), y(y) {}
};

int orientation(Point p, Point q, Point r){
    // Let Q be in middle of P and R (Q is base)
    // Then orientation of R can be found by comparing M1=Slope(P, Q) and M2=Slope(Q, R)
    // M1 = (Q.y - P.y) / (Q.x - P.x)
    // M2 = (R.y - Q.y) / (R.x - Q.x)
    // Take LCM, ignore denominator:
    int ori = (q.y - p.y)*(r.x - q.x) - (r.y - q.y)*(q.x - p.x);
    if(ori > 0) // M1 > M2, Clockwise
        return 1;
    else if(ori < 0) // M1 < M2, Counter-Clockwise
        return 2;
    else    // M1 == M2, Collinear
        return 0;
}

int distance(Point p, Point q, Point r){
    int d1 = (q.x-p.x)*(q.x-p.x) + (q.y-p.y)*(q.y-p.y);
    int d2 = (r.x-p.x)*(r.x-p.x) + (r.y-p.y)*(r.y-p.y);
    return d1-d2;
}

vector<vector<int>>FindConvexHull(vector<vector<int>> points){
    int n = points.size();
    if(n < 3)
        return {};

    vector<vector<int>> chull;
    int left = 0;

    // Find leftmost point index
    for(int i=0; i<n; i++)
        if(points[i][0] < points[left][0])// || (points[i][0] == points[left][0] && points[i][1] > points[left][1]))
            left = i;

    int curr = left;
    int next = -1; // Query

    do {
        chull.push_back(points[curr]);

        next = (curr+1)%n;
        for(int i=0; i<n; i++){
            if(orientation(Point(points[curr][0], points[curr][1]), Point(points[i][0], points[i][1]), Point(points[next][0], points[next][1])) == 2)
                next = i;
            // else if(orientation(Point(points[curr][0], points[curr][1]), Point(points[i][0], points[i][1]), Point(points[next][0], points[next][1])) == 1
            //         && distance(Point(points[curr][0], points[curr][1]), Point(points[i][0], points[i][1]), Point(points[next][0], points[next][1])) > 0) // Optional for collinear
            //     next = i;
        }

        curr = next;

    } while(curr != left);

    sort(chull.begin(), chull.end());
    return chull;
}