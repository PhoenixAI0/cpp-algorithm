#include <bits/stdc++.h>
using namespace std;

long double curX;

struct Segment {
    int id;
    long long x1, y1, x2, y2;
};

vector<Segment> segs;

long double getY(const Segment &s, long double x) {
    if(s.x1 == s.x2) return s.y1;
    long double t = (x - s.x1) / ((long double)s.x2 - s.x1);
    return s.y1 + t * (s.y2 - s.y1);
}

struct ActiveComparator {
    bool operator()(int a, int b) const {
        const Segment &s1 = segs[a], &s2 = segs[b];
        long double y1 = getY(s1, curX);
        long double y2 = getY(s2, curX);
        if(fabsl(y1 - y2) > 1e-12) return y1 < y2;
        return a < b;
    }
};

set<int, ActiveComparator> activeSet;

int orientation(long long ax, long long ay, long long bx, long long by, long long cx, long long cy) {
    __int128 dx1 = bx - ax, dy1 = by - ay;
    __int128 dx2 = cx - ax, dy2 = cy - ay;
    __int128 cross = dx1 * dy2 - dy1 * dx2;
    if(cross > 0) return 1;
    if(cross < 0) return -1;
    return 0;
}

bool onSegment(long long ax, long long ay, long long bx, long long by, long long cx, long long cy) {
    return bx >= min(ax, cx) && bx <= max(ax, cx) && by >= min(ay, cy) && by <= max(ay, cy);
}

bool segmentsIntersect(const Segment &s1, const Segment &s2) {
    long long x1 = s1.x1, y1 = s1.y1, x2 = s1.x2, y2 = s1.y2;
    long long x3 = s2.x1, y3 = s2.y1, x4 = s2.x2, y4 = s2.y2;
    int o1 = orientation(x1, y1, x2, y2, x3, y3);
    int o2 = orientation(x1, y1, x2, y2, x4, y4);
    int o3 = orientation(x3, y3, x4, y4, x1, y1);
    int o4 = orientation(x3, y3, x4, y4, x2, y2);
    if(o1 != o2 && o3 != o4) return true;
    if(o1 == 0 && onSegment(x1, y1, x3, y3, x2, y2)) return true;
    if(o2 == 0 && onSegment(x1, y1, x4, y4, x2, y2)) return true;
    if(o3 == 0 && onSegment(x3, y3, x1, y1, x4, y4)) return true;
    if(o4 == 0 && onSegment(x3, y3, x2, y2, x4, y4)) return true;
    return false;
}

struct Event {
    long double x, y;
    int type;
    int segId, segId2;
};

struct EventCompare {
    bool operator()(const Event &a, const Event &b) const {
        if(fabsl(a.x - b.x) > 1e-12) return a.x > b.x;
        if(a.type != b.type) return a.type > b.type;
        return a.y > b.y;
    }
};

bool getIntersectionEvent(int id1, int id2, long double curPos, Event &ev) {
    const Segment &s1 = segs[id1], &s2 = segs[id2];
    if(!segmentsIntersect(s1, s2)) return false;
    long double A1 = s1.y2 - s1.y1, B1 = s1.x1 - s1.x2, C1 = A1 * s1.x1 + B1 * s1.y1;
    long double A2 = s2.y2 - s2.y1, B2 = s2.x1 - s2.x2, C2 = A2 * s2.x1 + B2 * s2.y1;
    long double det = A1 * B2 - A2 * B1;
    if(fabsl(det) < 1e-12) return false;
    long double ix = (B2 * C1 - B1 * C2) / det, iy = (A1 * C2 - A2 * C1) / det;
    if(ix < curPos - 1e-12) return false;
    ev = {ix, iy, 2, id1, id2};
    return true;
}

bool sweepLineCheck(int skip, pair<int, int> &interPair) {
    priority_queue<Event, vector<Event>, EventCompare> eq;
    activeSet.clear();
    int n = segs.size();
    for (int i = 0; i < n; i++) {
        if(i == skip) continue;
        eq.push({segs[i].x1, segs[i].y1, 0, i, -1});
        eq.push({segs[i].x2, segs[i].y2, 1, i, -1});
    }
    while(!eq.empty()) {
        Event ev = eq.top();
        eq.pop();
        curX = ev.x;
        if(ev.type == 0) {
            int id = ev.segId;
            auto it = activeSet.insert(id).first;
            if(next(it) != activeSet.end()) {
                int idAbove = *next(it);
                Event newEv;
                if(getIntersectionEvent(id, idAbove, curX, newEv)) eq.push(newEv);
            }
            if(it != activeSet.begin()) {
                int idBelow = *prev(it);
                Event newEv;
                if(getIntersectionEvent(idBelow, id, curX, newEv)) eq.push(newEv);
            }
        } else if(ev.type == 1) {
            int id = ev.segId;
            auto it = activeSet.find(id);
            if(it != activeSet.end()) {
                auto itAbove = next(it);
                auto itBelow = (it == activeSet.begin() ? activeSet.end() : prev(it));
                activeSet.erase(it);
                if(itAbove != activeSet.end() && itBelow != activeSet.end()) {
                    int idAbove = *itAbove, idBelow = *itBelow;
                    Event newEv;
                    if(getIntersectionEvent(idBelow, idAbove, curX, newEv)) eq.push(newEv);
                }
            }
        } else {
            int id1 = ev.segId, id2 = ev.segId2;
            if(activeSet.find(id1) == activeSet.end() || activeSet.find(id2) == activeSet.end()) continue;
            interPair = {id1, id2};
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowjump.in", "r", stdin);
    freopen("cowjump.out", "w", stdout);
    int N;
    cin >> N;
    segs.resize(N);
    for (int i = 0; i < N; i++) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        segs[i].id = i;
        if(a < c || (a == c && b < d)) {
            segs[i] = {i, a, b, c, d};
        } else {
            segs[i] = {i, c, d, a, b};
        }
    }

    pair<int, int> interPair;
    bool found = sweepLineCheck(-1, interPair);
    if(!found) {
        cout << -1 << "\n";
        return 0;
    }

    int cand1 = interPair.first, cand2 = interPair.second;
    pair<int, int> dummy;
    bool works1 = !sweepLineCheck(cand1, dummy);
    bool works2 = !sweepLineCheck(cand2, dummy);

    int ans = (works1 && works2) ? min(cand1, cand2) : (works1 ? cand1 : cand2);
    cout << ans + 1 << "\n";
}