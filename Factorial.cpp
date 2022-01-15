#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int MXN = 505;
int fact[MXN];

void factorial(int n){
	for(int i=0; i<MXN; i++) 
		fact[i] = 0;

	int len = 1;
	fact[0] = 1;
	for(int i=1; i<=n; i++){
		for(int j=0; j<len; j++){
			fact[j] *= i;
		}

		for(int j=0; j<len; j++){
			fact[j+1] += fact[j]/10;
			fact[j] %= 10;
		}

		while(fact[len]){
			fact[len+1] += fact[len]/10;
			fact[len] %= 10;
			len++;
		}
	}
}


void solve(){
	int n;
	cin >> n;

	factorial(n);

	int i = MXN-1;
	while(fact[i] == 0) i--;

	while(i>=0) {cout << fact[i]; i--;}
	cout << endl;

}

int32_t main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;	cin >> t;	while(t--)
	solve();

	return 0;
}
