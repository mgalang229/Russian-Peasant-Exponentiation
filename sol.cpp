#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll m;

ll mod(ll n) {
	return (n-(n/m)*m);
}

pair<ll, ll> mul(pair<ll, ll> p1, pair<ll, ll> p2) {
	ll ans1=mod(p1.first*p2.first-p1.second*p2.second);
	ll ans2=mod(p1.second*p2.first+p1.first*p2.second);
	return make_pair(ans1, ans2);
}

pair<ll, ll> binExpo(pair<ll, ll> inp, ll kk) {
	pair<ll, ll> ans=make_pair(1, 0);
	while(kk>0) {
		if(kk&1)
			ans=mul(ans, inp);
		inp=mul(inp, inp);
		kk/=2;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		ll a, b, k;
		cin >> a >> b >> k >> m;
		pair<ll, ll> p;
		p=make_pair(a, b);
		pair<ll, ll> ans=binExpo(p, k);
		cout << (ans.first+m)%m << " " << (ans.second+m)%m << "\n";
	}
}
