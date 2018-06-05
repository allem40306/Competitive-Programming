#include <stdio.h>
#include <queue>

struct lor{int i, j;} l, o;

int main() {
	int N, M, n[30][30], m[30][30], i, j, x[4] = {-1, 0, 1, 0}, y[4] = {0, 1, 0, -1}, k, d; std::deque<lor> q;
	for (; ~scanf("%d%d", &M, &N); printf(m[M-1][N-1] == 2147483647 ? "NA\n" : "%d\n", m[M-1][N-1])) {
		for (i = 0; i != M; i++)
			for (j = 0; j != N; j++)
				scanf("%d", &n[i][j]), m[i][j] = 2147483647;
		for (m[0][0] = 0, l.i = l.j = 0, q.push_back(l); !q.empty(); )
			for (l = q.front(), q.pop_front(), k = 0; k != 4; k++)
				0 <= l.i+x[k] && l.i+x[k] < M && 0 <= l.j+y[k] && l.j+y[k] < N && (d = (n[l.i][l.j]-n[l.i+x[k]][l.j+y[k]] < 0 ? n[l.i+x[k]][l.j+y[k]]-n[l.i][l.j] : n[l.i][l.j]-n[l.i+x[k]][l.j+y[k]]), d <= 1 && m[l.i+x[k]][l.j+y[k]] > m[l.i][l.j]+d) && (o.i = l.i+x[k], o.j = l.j+y[k], q.push_back(o), m[l.i+x[k]][l.j+y[k]] = m[l.i][l.j]+d);
	}
}
