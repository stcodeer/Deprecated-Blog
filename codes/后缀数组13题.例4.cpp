#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxf = 255;
const int inf = 0x7fffffff;
const int aaa = 1e5+5;
int sa[aaa],tong[aaa],wa[aaa],wb[aaa],wv[aaa],rank[aaa],height[aaa];
int s[aaa],k;
int cmp(int*r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(int n,int m)
{
	int i,j,p,*x=wa,*y=wb;
	for(i=0;i<m;++i)tong[i]=0;
	for(i=0;i<n;++i)tong[x[i]=s[i]]++;
	for(i=1;i<m;++i)tong[i]+=tong[i-1];
	for(i=n-1;i>=0;--i)sa[--tong[x[i]]]=i;
	for(j=1,p=1;p<n;j<<=1,m=p)
	{
		for(p=0,i=n-j;i<n;++i)y[p++]=i;
		for(i=0;i<n;++i)if(sa[i]>=j)y[p++]=sa[i]-j;
		for(i=0;i<n;++i)wv[i]=x[y[i]];
		for(i=0;i<m;i++)tong[i]=0;
		for(i=0;i<n;i++)tong[wv[i]]++;
		for(i=1;i<m;i++)tong[i]+=tong[i-1];
		for(i=n-1;i>=0;i--)sa[--tong[wv[i]]]=y[i];
		for(swap(x,y),p=1,x[sa[0]]=0,i=1;i<n;i++)
		x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
	return;
}
void getheight(int n)
{
	int i,j,k=0;
	for(i=1;i<=n;++i)rank[sa[i]]=i;
	for(i=0;i<n;height[rank[i++]]=k)
	for(k?k--:0,j=sa[rank[i]-1];s[i+k]==s[j+k];k++);
	return;
}
bool can(int ans,int n)
{
	int tot=0;
	for(int i=1;i<=n;++i)
	{
		if(height[i]<ans)tot=0;
		tot++;
		if(tot==k)return 1;
	}
	return 0;
}
int main()
{
	int n;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i)scanf("%d",s+i);
	da(n+1,maxf);
	getheight(n);
	int l=1,r=n+1,ans,mid;
	while(l!=r)
	{
		int mid=(l+r>>1)+1;
		if(can(mid,n))ans=l=mid;
		else		r=mid-1;
	}
	printf("%d\n",ans);
}

