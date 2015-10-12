#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

struct castle {
	bool visited;
	int num;
	int wall;
	int color;
};
int m, n, Max;
int counter, color;
int nmax, ni, nj, nk;
map<int, int> mark;
castle cnt[51][51];
void wall(int wall , bool iswall[]) {
	if (wall & 1)
		iswall[0] = false;
	if (wall & 2)
		iswall[1] = false;
	if (wall & 4)
		iswall[2] = false;
	if (wall & 8)
		iswall[3] = false;
}
void dfs(int i, int j) {
	counter++;
	bool iswall[4] = { true, true, true, true };
	cnt[i][j].visited = true;
	cnt[i][j].color = color;
	wall(cnt[i][j].wall , iswall);
	for (int k = 0; k < 4; k++) {
		if (iswall[k]) {
			if (k == 0  && !cnt[i][j - 1].visited)
				dfs(i, j - 1);
			if (k == 1  && !cnt[i - 1][j].visited)
				dfs(i - 1, j);
			if (k == 2  && !cnt[i][j + 1].visited)
				dfs(i, j + 1);
			if (k == 3  && !cnt[i + 1][j].visited)
				dfs(i + 1, j);
		}
	}
}
int main() {
	ofstream fout ("castle.out");
	ifstream fin ("castle.in");
	fin >> n >> m;
	color = 0;
	Max = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			fin >> cnt[i][j].wall;
			cnt[i][j].visited = false;
			cnt[i][j].num = 0;
		}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			counter = 0;
			if (!cnt[i][j].visited) {
				dfs(i, j);
				mark[color] = counter;
				if (Max < counter)
					Max = counter;
				color++;
			}

		}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cnt[i][j].num = mark[cnt[i][j].color];
	nmax = 0;
	int temp;
	for (int j = 0; j < n; j++)
        for (int i = m - 1; i >= 0; i--)
        {
		bool iswall[4] = { true, true, true, true };
		wall(cnt[i][j].wall , iswall);
		for (int k = 0; k < 4; k++) {
			if (!iswall[k]) {
				if (k == 0  && j - 1 >= 0 &&cnt[i][j - 1].color != cnt[i][j].color) {
					temp = cnt[i][j].num + cnt[i][j - 1].num;
					if (temp > nmax) {
						nmax = temp;
						ni = i + 1;
						nj = j + 1;
						nk = k;
					}
				}
				if (k == 1 && i - 1 >= 0 && cnt[i - 1][j].color != cnt[i][j].color) {
					temp = cnt[i][j].num + cnt[i - 1][j].num;
					if (temp > nmax) {
						nmax = temp;
						ni = i + 1;
						nj = j + 1;
						nk = k;
					}
				}
				if (k == 2 && j + 1 < n && cnt[i][j + 1].color != cnt[i][j].color) {
					temp = cnt[i][j].num + cnt[i][j + 1].num;
					if (temp > nmax) {
						nmax = temp;
						ni = i + 1;
						nj = j + 1;
						nk = k;
					}
				}
				if (k == 3 && i + 1 < m &&cnt[i + 1][j].color != cnt[i][j].color) {
					temp = cnt[i][j].num + cnt[i + 1][j].num;
					if (temp > nmax) {
						nmax = temp;
						ni = i + 1;
						nj = j + 1;
						nk = k;
					}
				}
			}
		}
	}
	fout<<color<<endl<<Max<<endl<<nmax<<endl<<ni<<" "<<nj<<" ";
	if(nk == 0)
	    fout<<"W"<<endl;
	else if(nk == 1)
	    fout<<"N"<<endl;
	else if(nk == 2)
            fout<<"E"<<endl;
	else
	    fout<<"S"<<endl;
	return 0;
}
