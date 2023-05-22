#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(a,b,i)    for(int i = a; i < b; i ++)
pair<int, int> p[3];
int res = INT_MAX;
int n, m, x, y;
int a[1005][1005];
int _x[] = {1, 0, -1, 0};
int _y[] = {0, 1, 0, -1};
int check[1005][1005] = {};
void DFS(int x, int y, int point){
	if(x == p[2].first && y == p[2].second)
	{
		res = min(res, point); 
		return ;
	}
// 	if(point >= res)    return ;
	FOR(0,4,i){
		if(x + _x[i] >= 1 && x + _x[i] <= n && y + _y[i] >= 1 && y + _y[i] <= m && !a[x + _x[i]][y + _y[i]] && check[x + _x[i]][y + _y[i]] == 0){
		    check[x][y] = 1;
			DFS(x + _x[i], y + _y[i], point + 1);
			check[x][y] = 0;
		}
	}
}
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
	cin >> n >> m;
	FOR(1,n+1,i)
		FOR(1,m+1,j)
			cin >> a[i][j];
	FOR(1,3,i)
	{
		cin >> x >> y;
		p[i] = make_pair(x, y);
	}
	DFS(p[1].first, p[1].second, 0);
	if(res == INT_MAX)	cout << -1;
	else	cout << res;
}
