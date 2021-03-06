// https://www.topcoder.com/community/data-science/data-science-tutorials/disjoint-set-data-structures/
// ^ Very good tutorial for Disjoint Sets Data Structure
// https://www.ics.uci.edu/~eppstein/161/960206.html
// Give it a fast read for proof of Kruskal's Algorithm
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
#define REP(i, N) for(int i=1; i<=N; i++)
#define si(n) scanf("%d",&n)
#define pin(n) printf("%d\n",n)
#define pis(n) printf("%d",n)
#define plln(n) printf("%lld\n",n)
#define plls(n) printf("%lld",n)
#define P pair<int,int>
#define PP pair<P,int>
#define F first
#define S second
typedef long long ll;
int n,m;
PP arr[100001];

bool comp(PP A, PP B){
	return (A.S<B.S);
};
int currentRank[10001];
int Parent[10001];

void initializer(){
	rep(i,10001) {
		currentRank[i]=0;
		Parent[i]=i;
	};
};

int root(int x){
	if(x!=Parent[x]) Parent[x]=root(Parent[x]);
	return Parent[x];
};

void union1(int x, int y){
	int PX=root(x);
	int PY=root(y);
	if(currentRank[PX]<currentRank[PY]) Parent[PX]=PY;
	else if(currentRank[PX]>currentRank[PY]) Parent[PY]=PX;
	else {
		currentRank[PX]=currentRank[PY]+1;
		Parent[PY]=PX;
	};
};

bool checkUnion(int i){
	int x=arr[i].F.F;
	int y=arr[i].F.S;
	if(root(x)!=root(y)){
		union1(x,y);
		return true;
	};
	return false;
};

int main()
{
    si(n); si(m);
    
    for(int i=0; i<m; i++) cin >> arr[i].F.F >> arr[i].F.S >> arr[i].S ;
    
    sort(arr, arr+m, comp);
    initializer();
    ll answer=0;
    
    for(int i=0; i<m; i++){
    	if(checkUnion(i)) {
    		answer+=arr[i].S;
    	};
    };
    cout << answer << endl;
    return 0;
}
