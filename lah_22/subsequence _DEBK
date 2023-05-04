#include "bits/stdc++.h"
//#include "/Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define IOS ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define foru(j, a, b) for(int j = a; j <= b; ++j)
#define ford(j ,a, b) for(int j= a; j >= b; --j)
#define forp(j, a, b) for(int j = a; j + 1 <= b; ++j)
typedef pair<ll, ll> pii;
#define ld long double
#define endl '\n'
const int maxN = 100005 ;
const int mod = 2e9;
const int inf = 330;

void open(){
    freopen("CALC.inp", "r", stdin);
    freopen("CALC.out", "w", stdout); 
}

int arr[maxN], n, k, prefix_sum[maxN], ans, cnt;
map<int, int> remain;
vector<int> substr;
signed main(){	
	open();
	IOS
	cin >> n >> k;

	foru(j, 1, n){
		cin >> arr[j];
		prefix_sum[j] = prefix_sum[j - 1] + arr[j];

	    int prefix = prefix_sum[j] % k;
		remain[prefix]++;
		if(prefix == 0) cnt++;
	}
	foru(j, 0, k - 1) cnt += (remain[j] * (remain[j] - 1)) / 2;

	
    // divide and conquor
	foru(j, 1, n){
	int start = 0, end = substr.size();
	
		while(start < end){
			int mid = (start + end)/2;
			// if mid < small find the smallest in left, else find in right		
			if(substr[mid] < arr[j]){
				end = mid;
			}
			else start = mid + 1;
		}
		// if we can't find any number that is larger than arr[j]
		if(start == substr.size()){
			substr.push_back(arr[j]);
		}
		// can find some number
		else substr[start] = arr[j];
	}
	cout << substr.size() << endl;
	cout << cnt;
}


//divide exactly by K.
