#include<iostream>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

typedef set<int> Set;
map<Set, int> IDcache; // 把集合映射成ID
vector<Set> Setcache; // 根据ID取集合

// 查找给定集合x的ID。如果找不到，分配一个新ID
int ID(Set x) {
	if (IDcache.count(x)) return IDcache[x];
	Setcache.push_back(x); // 添加新集合
	return IDcache[x] = Setcache.size() - 1;
}

int main() {
	int t, n, ti = 0;
	string com;
	for (cin >> t; ti < t; ti++){
		stack<int>st;
		for (cin >> n; n; n--){
			cin >> com;
			if (com[0] == 'P')st.push(ID(Set()));
			else if (com[0] == 'D')st.push(st.top());
			else{
				Set x1 = Setcache[st.top()]; st.pop();
				Set x2 = Setcache[st.top()]; st.pop();
				Set x;
				if (com[0] == 'U') set_union (ALL(x1), ALL(x2), INS(x));
				if (com[0] == 'I') set_intersection (ALL(x1), ALL(x2), INS(x));
				if (com[0] == 'A'){ x = x2; x.insert(ID(x1)); }
				st.push(ID(x));
			}
			cout << Setcache[st.top()].size() << endl;
		}
		printf("***\n");
	}
}