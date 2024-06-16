#include <bits/stdc++.h>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

double calculateDensity(const pair<int, int> &p1, const pair<int, int> &p2, const vector<pair<int, int>> &points)
{
    int minX = min(p1.first, p2.first);
    int maxX = max(p1.first, p2.first);
    int minY = min(p1.second, p2.second);
    int maxY = max(p1.second, p2.second);

    int count = 0;
    for (const auto &point : points)
    {
        if (point.first >= minX && point.first <= maxX && point.second >= minY && point.second <= maxY)
        {
            count++;
        }
    }

    double area = (maxX - minX + 1) * (maxY - minY + 1);
    return count / area;
}

double densestRectangle(const vector<pair<int, int>> &points)
{
    int n = points.size();
    if (n < 4)
        return -1.0; // Not enough points to form a rectangle

    double maxDensity = -1.0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            maxDensity = max(maxDensity, calculateDensity(points[i], points[j], points));
        }
    }

    return maxDensity;
}

int main()
{
    vector<pair<int, int>> points = {{0, 1}, {0, 10}, {10, 1}, {10, 10}, {2, 3}};
    double density = densestRectangle(points);
    cout << "Density of the densest rectangle: " << density << endl;
    return 0;
}
