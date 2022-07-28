#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> ar_id;
vector<vector<int>> segment_tree;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        segment_tree[v].push_back(ar_id[tl].second);
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    segment_tree[v].resize(tr - tl + 1);
    merge(segment_tree[v * 2].begin(), segment_tree[v * 2].end(), 
            segment_tree[v * 2 + 1].begin(), segment_tree[v * 2 + 1].end(), segment_tree[v].begin());
}

int Median(int v, int tl, int tr, int L, int R, int pos){
    if (tl == tr) {
        return segment_tree[v].back();
    }
    int tm = (tl + tr) / 2;
    int cnt = upper_bound(segment_tree[v * 2].begin(), segment_tree[v * 2].end(), R) - 
                lower_bound(segment_tree[v * 2].begin(), segment_tree[v * 2].end(), L);
    if (cnt >= pos) {
        return Median(v * 2, tl, tm, L, R, pos);
    }
    return Median(v * 2 + 1, tm + 1, tr, L, R, pos - cnt);
}

int main() {
    // INPUT
    int N, Q;
    vector<int> ar;
    cin >> N;
    ar.resize(N);
    segment_tree.resize(N * 4);
    for (int i = 0; i < N; i++){
        cin >> ar[i];
        ar_id.push_back(make_pair(ar[i], i));
    }
    sort(ar_id.begin(), ar_id.end());
    build(1, 0, N - 1);
    cin >> Q;
    int* result = new int[Q];
    int idx = 0;
    while (Q--){
        int L, R;
        cin >> L >> R;
        result[idx] = ar[Median(1, 0, N - 1, --L, --R, (R - L) / 2 + 1)];
        idx++;
    }

    // OUTPUT
    for (int i = 0; i < idx; i++) {
        cout << result[i] << endl;
    }
}