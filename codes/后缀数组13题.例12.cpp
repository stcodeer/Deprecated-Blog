#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int aaa = 2e5+500;
const int maxf = 255;
int sa[aaa],rank[aaa],wa[aaa],wb[aaa],wv[aaa],h[aaa],tong[aaa],nn[aaa];
char s[aaa],ss[13][15031];
int inq[13],maxq[13],minq[13];
int tt,num;
bool use[13];
bool cmp(int *r,int a,int b,int l){return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(int n,int m)
{
	int i,j,p,*x=wa,*y=wb;
	for(i=0;i<m;++i)tong[i]=0;
	for(i=0;i<n;++i)tong[x[i]=s[i]]++;
	for(i=1;i<m;++i)tong[i]+=tong[i-1];
	for(i=n-1;i>=0;i--)sa[--tong[x[i]]]=i;
	for(j=1,p=1;p<n;j<<=1,m=p)
	{
		for(p=0,i=n-j;i<n;++i)y[p++]=i;
		for(i=0;i<n;++i)if(sa[i]>=j)y[p++]=sa[i]-j;
		for(i=0;i<m;++i)tong[i]=0;
		for(i=0;i<n;++i)tong[wv[i]=x[y[i]]]++;
		for(i=1;i<m;++i)tong[i]+=tong[i-1];
		for(i=n-1;i>=0;--i)sa[--tong[wv[i]]]=y[i];
		for(swap(x,y),x[sa[0]]=0,i=1,p=1;i<n;++i)
		x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
}
void geth(int n)
{
	int i,j,k=0;
	for(i=1;i<=n;++i)rank[sa[i]]=i;
	for(i=0;i<n;h[rank[i++]]=k)
	for(k?k--:0,j=sa[rank[i]-1];s[i+k]==s[j+k];k++);
}
bool can(int ans,int n)
{
	int tot=0;
	for(int i=1;i<=n;++i)
	{
		if(h[i]<ans)
		{
			tot=0;
			memset(inq,0,sizeof(inq));
			memset(maxq,0,sizeof(maxq));
			memset(minq,0x3f,sizeof(minq));
			memset(use,0,sizeof(use));
		}
		else
		{
			for(int t=1;t<=num;++t)if(nn[t-1]<sa[i]&&sa[i]<=nn[t])
			{
				inq[t]++;
				minq[t]=min(minq[t],sa[i]);
				maxq[t]=max(maxq[t],sa[i]);
				if(maxq[t]-minq[t]>=ans&&!use[t])tot++,use[t]=true;
				if(tot==num)return 1;
			}
			for(int t=1;t<=num;++t)if(nn[t-1]<sa[i-1]&&sa[i-1]<nn[t])
			{
				inq[t]++;
				minq[t]=min(minq[t],sa[i-1]);
				maxq[t]=max(maxq[t],sa[i-1]);
				if(maxq[t]-minq[t]>=ans&&!use[t])tot++,use[t]=true;
				if(tot==num)return 1;
			}
		}	
	}
	return 0;
}
int main()
{
//	freopen("RelevantPhrasesofAnnihil.in","r",stdin);
//	freopen("RelevantPhrasesofAnnihil.out","w",stdout);
	nn[0]=-1;
	scanf("%d",&tt);
	while(tt--)
	{
		memset(inq,0,sizeof(inq));
		memset(wa,0,sizeof(wa));
		memset(wb,0,sizeof(wb));
		memset(wv,0,sizeof(wv));
		memset(sa,0,sizeof(sa));
		memset(rank,0,sizeof(rank));
		memset(h,0,sizeof(h));
		scanf("%d",&num);
		int tot=0,qiguaizifu=2;
		for(int i=1;i<=num;++i)
		{
			scanf("%s",ss[i]);
			nn[i]=strlen(ss[i]);
		}
		for(int i=1;i<=num;++i)
		{
			for(int t=0;t<nn[i];++t)
			s[tot++]=ss[i][t];
			s[tot++]=qiguaizifu++;
		}
		for(int i=1;i<=num;++i)nn[i]+=(nn[i-1]+1);
		int n=strlen(s);
		da(n+1,maxf);
		geth(n);
		int l=0,r=(n+1)/2;
		while(l!=r)
		{
			int mid=l+r+1>>1;
			if(can(mid,n))	l=mid;
			else			r=mid-1;
		}
		printf("%d\n",l);
	}
}
