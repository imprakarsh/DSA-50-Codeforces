#include <bits/stdc++.h>
#define int long long 
using namespace std;
void solve() { 
	int n, p, q, r;
	cin >> n >> p >> q >> r; 
	vector<int> v(n); 
	for (auto &i : v) cin >> i ; 
	vector<vector<int>> dp(3, vector<int> (n, 0)); 
	dp[0][0] = v[0] * p; 
	dp[1][0] = dp[0][0] + v[0] * q; 
	dp[2][0] = dp[1][0] + v[0] * r; 
	for (int i = 1; i < n; i++) dp[0][i] = max(dp[0][i-1], p*v[i]);
	
	for (int i = 1; i < n; i++) { 
		for (int j = 1; j < 3; j++) { 
			int kt ; 
		    if (j == 1) kt = q; 
		    else kt = r; 
			dp[j][i] = max(dp[j][i-1], dp[j-1][i] + v[i]*kt); 
		}
	}
	cout << dp[2][n-1] << '\n'; 
	
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
