#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Point {
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {
    }

    bool operator<(const Point &other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};


bool vectorInLine(const int& dx, const int& dy, const int& ds, const Point& c) {
    return dy * c.x - dx * c.y == ds;
}

bool isOnOneLine(const vector<Point> &points) {
    set < Point > pointsSet(points.begin(), points.end());

    if (pointsSet.size() <= 2) {
        return true;
    }

    vector<Point> pointsVector(pointsSet.begin(), pointsSet.end());
    auto a = pointsVector[0];
    auto b = pointsVector[1];
    auto dx = b.x - a.x;
    auto dy = b.y - a.y;
    auto ds = a.x * b.y - b.x * a.y;
    for (int i = 2; i < pointsVector.size(); i ++) {
        if (!vectorInLine(dx, dy, ds, pointsVector[i])) {
            return false;
        }
    }


    return true;
}

int main() {
    int n;
    cin >> n;
    vector<Point> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    if (isOnOneLine(points)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
