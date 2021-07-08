#include <bits/stdc++.h>
#define int long long 
using namespace std;
void solve() { 
	int n, k; cin >> n >> k; 
	vector<int> a(n), v(n + 1), t(n); 
	for (auto &i : a) cin >> i; 
	for (auto &i : t) cin >> i; 
	int sm = 0; 
	for (int i = 0; i < n; i++) {
		if (t[i] == 1) { 
			sm += a[i]; 
		}
	}
	v[0] = 0; 
	for (int i = 1; i <= n; i++) { 
		v[i] = v[i-1] + (t[i-1] == 0 ? a[i-1] : 0) ; 
	}	
	int mx = -1; 
	for (int i = 0; i <= n; i++) {
		mx = max(mx, (v[min(i + k , n)] - v[i])); 
	}
	
	cout << sm + mx << '\n';  
}
int32_t main(){
	iostream::sync_with_stdio(false); 
	cin.tie(0); 
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int tc = 1; 
    //~ cin >> tc; 
	while (tc--) 
	solve(); 			
	return 0; 
	
}
