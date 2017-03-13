#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const int N =2e5+7;
struct build{int sum,in,out;}tr[8*N];
int n,q,k,a[N],tot;
int find(int x,int pot)
{
	if(pot>=tr[x].in)			return 0;
	if(!pot)					return tr[x].sum;
	if(pot<=tr[x*2+1].in)
	return tr[x].sum-tr[x*2+1].sum+find(x*2+1,pot);
	return find(x*2,pot-tr[x*2+1].in+tr[x*2+1].out);
}
void update(int x)
{
	tr[x].in=tr[x*2+1].in+max(0,tr[x*2].in-tr[x*2+1].out);
	tr[x].out=tr[x*2].out+max(0,tr[x*2+1].out-tr[x*2].in);
	tr[x].sum=tr[x*2+1].sum+find(x*2,tr[x*2+1].out);
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		if(a[l]<0)	tr[x].out=-a[l];
		else		tr[x].in=1,tr[x].sum=a[l];
	}
	else
	{
		int mid=l+r>>1;
		build(x*2,l,mid);
		build(x*2+1,mid+1,r);
		update(x);
	}
}
void change(int x,int pot,int w,int l,int r)
{
	if(l==r)
	{
		memset(&tr[x],0,sizeof(tr[x]));
		if(w<0)		tr[x].out=-w;
		else		tr[x].in=1,tr[x].sum=w;
	}
	else
	{
		int mid=l+r>>1;
		if(pot>mid)	change(x*2+1,pot,w,mid+1,r);
		else		change(x*2,pot,w,l,mid);
		update(x);
	}
}
int main()
{
	freopen("weed.in", "r", stdin);
	freopen("weed.out", "w", stdout);
	read(n),read(q);
	for(int i=1;i<=n;++i)
	{
		read(k),read(a[i]);
		if(k)a[i]*=-1;
	}
	build(1,1,n);
	while(q--)
	{
		int x,w;
		read(x);read(k);read(w);
		if(k)w*=-1;
		change(1,x,w,1,n);
		printf("%d\n",tr[1].sum);
	}
}
