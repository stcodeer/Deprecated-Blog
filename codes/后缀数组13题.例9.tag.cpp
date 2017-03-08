#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int aaa = 3e5+1;
const int maxf = 255;
const int inf =0x7fffffff;
int sa[aaa],wa[aaa],wb[aaa],wv[aaa],tong[maxf+1],rank[aaa],h[aaa];
char s[aaa],ss[aaa];
bool cmp(int *r,int a,int b,int l){return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(int n,int m)
{
	int i,j,p,*x=wa,*y=wb;
	for(i=0;i<m;++i)tong[i]=0;
	for(i=0;i<n;++i)tong[x[i]=s[i]]++;
	for(i=1;i<m;++i)tong[i]+=tong[i-1];
	for(i=n-1;i>=0;--i)sa[--tong[x[i]]]=i;
	for(j=1,p=1;p<n;m=p,j<<=1)
	{
		for(p=0,i=n-j;i<n;++i)y[p++]=i;
		for(i=0;i<n;++i)if(sa[i]>=j)y[p++]=sa[i]-j;
		for(i=0;i<n;++i)wv[i]=x[y[i]];
		for(i=0;i<m;++i)tong[i]=0;
		for(i=0;i<n;++i)tong[wv[i]]++;
		for(i=1;i<m;++i)tong[i]+=tong[i-1];
		for(i=n-1;i>=0;--i)sa[--tong[wv[i]]]=y[i];
		for(swap(x,y),p=1,i=1,x[sa[0]]=0;i<n;++i)
		x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
	return;
}
void geth(int n)
{
	int i,j,k=0;
	for(i=1;i<=n;++i)rank[sa[i]]=i;
	for(i=0;i<n;h[rank[i++]]=k)
	for(k?k--:0,j=sa[rank[i]-1];s[i+k]==s[j+k];k++);
}
int main()
{
	freopen("longlongmessage.in","r",stdin);
	freopen("longlongmessage.out","w",stdout);
	scanf("%s",s);
	scanf("%s",ss);
	int n=strlen(s),m=strlen(ss);
	s[n]='*';
	for(int i=n+1;i<=n+m;++i)s[i]=ss[i-n-1];
	int l=n+m+1;
	da(l+1,maxf);
	geth(l);
	int maxx=0;
	for(int i=2;i<=l;++i)
	{
		if(h[i]>maxx&&((sa[i]<n&&sa[i-1]>n)||(sa[i]>n&&sa[i-1]<n)))
		maxx=h[i];
	}
	cout<<maxx;
}
