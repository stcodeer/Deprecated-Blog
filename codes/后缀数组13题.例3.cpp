#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int aaa = 1e5+1;
const int maxf = 255;
const int inf = 0x7fffffff;
int wa[aaa],wb[aaa],wv[aaa],tong[aaa],h[aaa],sa[aaa],rank[aaa],d[aaa];
int s[aaa];
int cmp(int *r,int a,int b,int l){return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(int n,int m)
{
	int i,j,p,*x=wa,*y=wb;
	for(i=0;i<m;i++)tong[i]=0;
	for(i=0;i<n;++i)tong[x[i]=s[i]]++;
	for(i=1;i<m;++i)tong[i]+=tong[i-1];
	for(i=n-1;i>=0;--i)sa[--tong[x[i]]]=i;
	for(p=1,j=1;p<n;j<<=1,m=p)
	{
		for(p=0,i=n-j;i<n;++i)y[p++]=i;
		for(i=0;i<n;++i)if(sa[i]>=j)y[p++]=sa[i]-j;
		for(i=0;i<n;++i)wv[i]=x[y[i]];
		for(i=0;i<m;i++)tong[i]=0;
		for(i=0;i<n;++i)tong[wv[i]]++;
		for(i=1;i<m;++i)tong[i]+=tong[i-1];
		for(i=n-1;i>=0;--i)sa[--tong[wv[i]]]=y[i];
		for(swap(x,y),p=1,x[sa[0]]=0,i=1;i<n;++i)
		x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
	return;
}
void getheight(int n)
{
	int i,j,k=0;
	for(i=1;i<=n;++i)rank[sa[i]]=i;
	for(i=0;i<n;h[rank[i++]]=k)
	for(k?k--:0,j=sa[rank[i]-1];s[i+k]==s[j+k];k++);
	return;
}
bool can(int k,int n)
{
	int tmp=0,maxsa=-1,minsa=inf;
	for(int i=1;i<=n;++i)
	{
		if(h[i]<k)maxsa=-1,minsa=inf;
		if(sa[i]<minsa)minsa=sa[i];
		if(sa[i]>maxsa)maxsa=sa[i];
		if(maxsa-minsa>k)return 1;
	}
	return 0;
}
int main()
{
//	freopen("theme.in","r",stdin);
//	freopen("theme.out","w",stdout);
	int n,x;
	while(scanf("%d",&n)!=EOF)
	{
		memset(h,0,sizeof(h));
		memset(sa,0,sizeof(sa));
		memset(rank,0,sizeof(rank));
		if(!n)break;
		cin>>x;
		for(int i=1;i<n;++i)scanf("%d",&s[i]);
		s[0]=s[1]-x;
		for(int i=1;i<n-1;++i)s[i]=s[i+1]-s[i];
		n--;
		for(int i=0;i<n;++i)s[i]+=150;
		da(n+1,maxf);
		getheight(n);
		int l=0,r=1e6,ans;
		int mid=0;
		while(l!=r)
		{
			ans=l+r+1>>1;
			if(can(ans,n))	l=ans;
			else			r=ans-1;
		}
		l++;
		printf("%d\n",(l)>=5?l:0);
	}
}
