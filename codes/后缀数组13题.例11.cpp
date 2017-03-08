#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int aaa = 2e5+1;
const int inf =0x7fffffff;
const int maxf = 255;
bool cmp(int *r,int a,int b,int l){return r[a]==r[b]&&r[a+l]==r[b+l];}
int sa[aaa],wa[aaa],wb[aaa],wv[aaa],rank[aaa],h[aaa],tong[aaa];
char ss[111][10001],s[aaa];
int nn[111],tt;
bool inq[111];
int ll[aaa];
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
		for(i=0;i<m;++i)tong[i]=0;
		for(i=0;i<n;++i)tong[wv[i]=x[y[i]]]++;
		for(i=1;i<m;++i)tong[i]+=tong[i-1];
		for(i=n-1;i>=0;--i)sa[--tong[wv[i]]]=y[i];
		for(i=1,p=1,swap(x,y),x[sa[0]]=0;i<n;++i)
		x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
	return;
}
void geth(int n)
{
	int i,j,k=0;
	for(i=1;i<=n;++i)rank[sa[i]]=i;
	for(i=0;i<n;h[rank[i++]]=k)
	for(j=sa[rank[i]-1],k?k--:0;s[j+k]==s[i+k];k++);
}
int k;
int ansg;
bool can(int ans,int n,int flag)
{
	if(!flag)
	{
		int tot1=0;
		memset(inq,0,sizeof(inq));
		for(int i=1;i<=n;++i)
		{
			if(h[i]<ans)
			{
				memset(inq,0,sizeof(inq));	tot1=0;
			}
			else
			{
				int nowq,nowt;
				for(int t=1;t<=tt;++t)if(nn[t-1]<sa[i-1]&&sa[i-1]<nn[t])nowt=t;
				for(int t=1;t<=tt;++t)if(nn[t-1]<sa[i]&&sa[i]<nn[t])nowq=t;
				if(!inq[nowq])tot1++,inq[nowq]=true;
				if(!inq[nowt])tot1++,inq[nowt]=true;
				if(tot1>=k)return 1;
			}
		}
		return 0;
	}
	if(flag)
	{
		int lll=inf,rrr=-1;
		int tot1=0;
		memset(inq,0,sizeof(inq));
		for(int i=1;i<=n;++i)
		{
			if(h[i]<ans)
			{
				memset(inq,0,sizeof(inq));	tot1=0;
				lll=inf;rrr=-1;
			}
			else
			{
				int nowq,nowt;
				if(sa[i-1]<lll)lll=sa[i-1];if(sa[i-1]>rrr)rrr=sa[i-1];
				if(sa[i]<lll)lll=sa[i];if(sa[i]>rrr)rrr=sa[i];
				for(int t=1;t<=tt;++t)if(nn[t-1]<sa[i-1]&&sa[i-1]<nn[t])nowt=t;
				for(int t=1;t<=tt;++t)if(nn[t-1]<sa[i]&&sa[i]<nn[t])nowq=t;
				if(!inq[nowq])tot1++,inq[nowq]=true;
				if(!inq[nowt])tot1++,inq[nowt]=true;
				if(tot1==k)ll[++ansg]=lll;
			}
		}
	}
}
int main()
{
//	freopen("Lifeforms.in","r",stdin);
//	freopen("Lifeforms.out","w",stdout);
	while(scanf("%d",&tt)!=EOF)
	{
		if(!tt)return 0;
		memset(wa,0,sizeof(wa));
		memset(wb,0,sizeof(wb));
		memset(wv,0,sizeof(wv));
		memset(rank,0,sizeof(rank));
		memset(sa,0,sizeof(sa));
		memset(h,0,sizeof(h));
		memset(nn,0,sizeof(nn));
		memset(s,0,sizeof(s));
		int tot=0;
		int tmp=2;
		ansg=0;
		for(int i=1;i<=tt;++i)
		{
			scanf("%s",ss[i]);
			nn[i]=strlen(ss[i]);
			nn[0]=-1;
			for(int t=0;t<nn[i];++t)s[tot++]=ss[i][t];
			nn[i]+=nn[i-1]+(i==tt?0:1);
			if(i!=tt)s[tot++]=tmp++;
		}
		nn[tt]++;
		int n=strlen(s);
		da(n+1,maxf);
		geth(n);
		k=(tt)/2+1;
		int l=0,r=n+1,mid;
		while(l!=r)
		{
			mid=(l+r+1)>>1;
			if(can(mid,n,0))	l=mid;
			else			r=mid-1;
		}
		if(l==0){printf("?");goto dd;}
		can(l,n,1);
		for(int i=1;i<=ansg;++i)
		{
			if(i!=1)
			{
			bool flag=0;
			for(int t=0;t<l;++t)if(s[ll[i]+t]!=s[ll[i-1]+t]){flag=1;break;}
			if(!flag)continue;
			}
			for(int t=ll[i];t<=ll[i]+l-1;++t)putchar(s[t]);
			printf("\n");
		}
		dd:;
	}
}
