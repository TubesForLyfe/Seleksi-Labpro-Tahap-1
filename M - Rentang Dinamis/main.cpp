#include <iostream>
#include <vector>
using namespace std;

void buildTree(vector<pair<long long, long long>>& tree, vector<long long>& array, long long b, long long e, long long node)
{
    if(b == e){
        tree[node].first = array[b];
        tree[node].second = 0;
        return;
    }
    long long left = node << 1;
    long long right = left + 1;
    long long mid = (b + e) >> 1;
    buildTree(tree, array, b, mid, left);
    buildTree(tree, array, mid + 1, e, right);
    tree[node].first = tree[left].first + tree[right].first;
}

void updateTree(vector<pair<long long,long long>>& array, long long b, long long e, long long node, long long i, long long j, long long  u) {
    if (b > j || e < i) {
        return;
    }
    if (b >= i && e <= j) {
        array[node].first += ((e - b + 1) * u);
        array[node].second += u;
        return;
    }
    long long left = node << 1;
    long long right = left + 1;
    long long mid = (b + e) >> 1;
    updateTree(array, b, mid, left, i, j, u);
    updateTree(array, mid + 1, e, right, i, j, u);
    array[node].first = array[left].first + array[right].first + array[node].second * (e - b + 1);
}
 
long long getTreeElmt(vector<pair<long long,long long>>& array, long long b, long long e, long long node, long long i, long long carry)
{
    if(b > i || e < i){
        return 0LL;
    }
    if(b >= i && e <= i){
        return array[node].first + (carry * (e - b + 1));
    }
    long long left = node << 1;
    long long right = left+1;
    long long mid = (b+e) >> 1; 
    long long x = getTreeElmt(array, b, mid, left, i, carry + array[node].second);
    long long y = getTreeElmt(array, mid + 1, e, right, i, carry+array[node].second);
    return (x + y);
}

int main() {
    // Get All 10^5 Primes
    long long primeList[100000];
    int prime[1299710];
    prime[0] = 1;
    for (int i = 3; i * i <= 1299709; i += 2) {
        if (prime[i / 2] == 0) {
            for (int j = 3 * i; j <= 1299709; j += 2 * i)
                prime[j / 2] = 1;
        }
    }
    long long idx = 0;
    for (int i = 1; i <= 1299709; i++) {
        if (i == 2){
            primeList[idx] = i;
            idx++;
        }
        else if (i % 2 == 1 && prime[i / 2] == 0) {
            primeList[idx] = i;
            idx++;
        }
    }

    // INPUT
    long long N, Q, operation, K, A, B, X;
    cin >> N >> Q;
    vector<long long> array(N + 1);
    vector<pair<long long,long long> > tree(4 * N);
    for(int i = 1; i <= N; i++) {
        cin >> array[i];
    }
    buildTree(tree, array, 1, N, 1);
    long long *result = new long long[Q];
    long long idx_result = 0;
    while (Q--) {
        cin >> operation;
        if (operation == 1) {
            cin >> K;
            result[idx_result] =  getTreeElmt(tree, 1, N, 1, K, 0LL);
            idx_result++;
        } else if (operation == 2) {
            cin >> A >> B >> X;
            updateTree(tree, 1, N, 1, A, B, primeList[X - 1]);
        }
    }

    // OUTPUT
    for (long long i = 0; i < idx_result; i++) {
        cout << result[i] << endl;
    }
}