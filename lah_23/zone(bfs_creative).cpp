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
const int maxN = 50 ;
const int mod = 2e9;
const int inf = 400;

void open(){
    freopen("ZONE.inp", "r", stdin);
    freopen("ZONE.out", "w", stdout); 
}

int x, y, n, l, num, cnt, previous_value, not_sastify, new_value, a, b;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int grid[105][105];
bool visited[105][105];
void floodfill(int x, int y){
	if(x < 1 || y < 1 || x > new_value || y > new_value  || visited[x][y] || grid[x][y] > 0) return;

    if(x % 2 == 0 && y % 2 == 0) {
		not_sastify++;
	}
	visited[x][y] = true;

	foru(j, 0, 3){
		floodfill(x + dx[j], y + dy[j]);
	}
}
signed main(){	
	//open();
	IOS
	cnt = 1;
	cin >> x >> y >> n >> l;
	new_value = n * 2 + 1; // new value of board 
	x = x * 2 + 1;
	y = y * 2 + 1;
	grid[x][y] = 1;
	while(l--){
		cin >> num;
		previous_value = grid[x][y];
		if(num == 1){
			x --;
			grid[x][y] = cnt;
			x--;
		}
		else if(num == 2){
			y ++;
		   	grid[x][y] = cnt;
			y ++;
		}
		else if(num == 3) {
			x++;
			grid[x][y] = cnt;
			x++;
		}
		else{
			 y--;
			 grid[x][y] = cnt;
			 y--;
		}
		if(grid[x][y] > 0){
			cout << previous_value - grid[x][y] + 1 << endl;
		}
		
		cnt++;
		grid[x][y] = cnt;
	}
	
    foru(j, 1, new_value) floodfill(1, j);
	foru(j, 1, new_value) floodfill(j, 1);
	foru(j, 1, new_value) floodfill(j, new_value);
	foru(j, 1, new_value) floodfill(new_value, j);
	
	cout << n * n - not_sastify;
}
