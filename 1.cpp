// company queries
#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int NMAX = 101; 

vector<vector<int>>dp(3, vector<int>(NMAX, 100001)); 
void solve() { 
	int n; cin >> n; 
	vector<int>v(n); 
	for (auto &i : v) cin >> i; 
	dp[0][0] = 1; 
	if ((v[0] == 1) || (v[0] == 3)) dp[1][0] = 0;
	if (v[0] == 2 || v[0] == 3) dp[2][0] = 0;  

	for (int i = 1; i < n; i++) { 
		dp[0][i] = min({dp[0][i-1], dp[1][i-1], dp[2][i-1]}) + 1; 
		if (v[i] == 1 || v[i] == 3) { 
			dp[1][i] = min(dp[0][i-1], dp[2][i-1]); 
		}
		if (v[i] == 2 || v[i] == 3) { 
			dp[2][i] = min(dp[0][i-1], dp[1][i-1]);
		}
	}
	
	cout << min({dp[0][n-1], dp[1][n-1], dp[2][n-1]});
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
