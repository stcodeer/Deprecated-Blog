#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int aaa = 1e5+1;
const int maxf = 255;
int sa[aaa],h[aaa],wa[aaa],wb[aaa],wv[aaa],tong[aaa],pre[aaa],rank[aaa];
int k,now,jj,maxr,cnt;
int d[aaa][21],ans[aaa];
char s[aaa*2];
bool cmp(int *r,int a,int b,int l){return r[a]==r[b]&&r[a+l]==r[b+l];}

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
		for(i=0;i<n;++i)wv[i]=x[y[i]];
		for(i=0;i<n;++i)tong[wv[i]]++;
		for(i=1;i<m;++i)tong[i]+=tong[i-1];
		for(i=n-1;i>=0;--i)sa[--tong[wv[i]]]=y[i];
		for(swap(x,y),p=1,x[sa[0]]=0,i=1;i<n;++i)
		x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
}
void getheight(int n)
{
	int i,j,k=0;
	for(i=1;i<=n;++i)rank[sa[i]]=i;
	for(i=0;i<n;h[rank[i++]]=k)
	for(k?k--:0,j=sa[rank[i]-1];s[i+k]==s[j+k];k++);
}
int prermq(int*a,int n)
{
	for(int i=0;i<n;++i)d[i][0]=a[i];
	for(int j=1;(1<<j)<=n;++j)
	for(int i=0;i+(1<<j)-1<n;++i)
	d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}
int askrmq(int l,int r)
{
	l=rank[l],r=rank[r];
	if(l>r)swap(l,r);
	l++;
	int k=0;
	while((1<<(k+1))<=r-l+1)k++;
	return min(d[l][k],d[r-(1<<k)+1][k]);
}
int main()
{
	int ccase=0;
	while(1)
	{
	memset(h,0,sizeof(h));
	memset(d,0,sizeof(d));
	memset(tong,0,sizeof(tong));
	memset(rank,0,sizeof(rank));
	memset(ans,0,sizeof(ans));
	ccase++;
	
	k=now=jj=maxr=cnt=0;
	scanf("%s",s);
	if(s[0]=='#')return 0;
	int n=strlen(s);
	da(n+1,maxf);
	getheight(n);
	prermq(h,n+1);
	for(int i=1;i<n;++i) 
	for(int j=0;j+i<n;j+=i) 
	{
        k=askrmq(j,j+i);
        now=k/i+1;
        jj=j-(i-k%i);
        if (jj>=0&&askrmq(jj,jj+i)>=(i-k%i))++now;
        if(now>maxr)		{cnt=0;maxr=now;ans[cnt++]=i;}
		else if(now==maxr)	ans[cnt++]=i;
	}
        for(int i=1;i<=n;++i) 
        for(int j=0;j<cnt;++j)
        if(askrmq(sa[i],sa[i]+ans[j])>=(maxr-1)*ans[j])
		{
            jj=sa[i],k=ans[j];
            goto dd;
        }
        dd:;
		printf("Case %d: ",ccase);
        for (int i=0;i<maxr*k;++i)putchar(s[jj++]);
        printf("\n");
	}
}
