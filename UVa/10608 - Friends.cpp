#include <bits/stdc++.h>
using namespace std;

const int N = 500005, M = 4000005;
const long long OO = 1e18;

#define neigh(u,e,v) for (int e = head[u], v; v = to[e], ~e; e = nxt[e])
int ne = 0;
int head[N], nxt[M], to[M];
void add_edge(int f, int t) {
	nxt[ne] = head[f];
	to[ne] = t;
	head[f] = ne++;
}
void add_biedge(int a, int b) { add_edge(a, b), add_edge(b, a); }

#define max(a,b) ( ((a) > (b)) ? (a) : (b) )
#define min(a,b) ( ((a) < (b)) ? (a) : (b) )
#define fori(n) for (int i = 0; i < (n); i++)
#define forirev(n) for (int i = (n-1); ~i; i--)
#define forj(n) for (int j = 0; j < (n); j++)
#define forjrev(n) for (int j = (n-1); ~j; j--)
#define fork(n) for (int k = 0; k < (n); k++)
#define FOR(a,b,c) for (int a = (b); a < (c); ++a)
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define unsync cin.sync_with_stdio(false), cin.tie(0)
#define inoutfile freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout)

typedef unsigned long long ulng;
typedef long long lng;
typedef pair<int, int> pii;
typedef pair<lng, lng> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<pii> vpii;

int n, m;

int order[500005];
int c = 0;
int visit[500005];		//-1 underprocessing, 0 unvisited, 1 visited

bool DFS(int u) {
	if (visit[u] == -1) return false;
	if (visit[u] == 1) return true;
	visit[u] = -1;
	neigh(u, e, v)
		if (!DFS(v)) return false;
	visit[u] = 1;
	order[c++] = u;
	return true;
}

void init() {
	ne = 0;
	memset(head, -1, n * sizeof head[0]);
	memset(visit, 0, n * sizeof visit[0]);
	c = 0;
}
int main() {
	unsync;
	//inoutfile;
	while (true) {
		scanf("%d %d", &n, &m);
		if (n == m && n == 0) break;
		init();
		fori(m) {
			int f, t;
			scanf("%d %d", &f, &t);
			add_edge(--f, --t);
		}
		bool succ = true;
		fori(n)
			if (!DFS(i)) { 
				succ = false;
				break;
			}

		if (!succ)
			puts("IMPOSSIBLE");
		else
			forirev(c)
				printf("%d\n", order[i] + 1);
	}
}
