#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const int aaa = 1e4+1;
int tong[aaa],wv[aaa],wa[aaa],wb[aaa];
int rank1[aaa],height[aaa],sa[aaa];
char s[aaa];
int a[aaa],n;
int dp[aaa][30];
int cmp(int *r,int a,int b,int l){return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(int n,int m)
{
	int i,j,p,*x=wa,*y=wb;
	for(i=0;i<m;++i)tong[i]=0;
	for(i=0;i<n;++i)tong[x[i]=a[i]]++;
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

void calheight(int n)
{
	int i,j,k=0;
	for(i=1;i<=n;i++)rank1[sa[i]]=i;
	for(i=0;i<n;height[rank1[i++]]=k)
	for(k?k--:0,j=sa[rank1[i]-1];a[i+k]==a[j+k];k++);
	return;
}

void preRMQ()
{
    int i,j;
    memset(dp,127,sizeof(dp));
    for(i=1;i<=n*2+1;i++)dp[i][0]=height[i];
    for(j=1;(1<<j)<=2*n+1;j++)
    for(i=1;i+(1<<j)-1<=2*n+1;i++)
    dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int lcp(int l,int r)
{
    int a=rank1[l],b=rank1[r];
    if(a>b)
        swap(a,b);
    a++;
    int t=(int)(log(double(b-a+1))/log(2.00));
    return min(dp[a][t],dp[b-(1<<t)+1][t]);
}

int main()
{
    int i,res,flag,max;
    while(scanf("%s",s)!=EOF)
    {
        max=0;
        n=strlen(s);
        for(i=0;i<n;i++)a[i]=(int)s[i];
        a[n]=1;
        for(i=0;i<n;i++)a[i+n+1]=int(s[n-i-1]);
        a[2*n+1]=0;
        da(2*n+2,123);
        calheight(2*n+1);
        preRMQ();
        for(i=0;i<n;i++)
        {
            res=lcp(i,2*n-i)*2-1;
            if(max<res)		max=res,flag=i;
            if(i>0)
            {
                res=lcp(i,2*n-i+1)*2;
                if(max<res)	max=res,flag=i;
            }
        }
        if(max%2==1)for(i=flag-max/2;i<=flag+max/2;i++)		printf("%c",s[i]);
        else		for(i=flag-max/2;i<=flag+max/2-1;i++)	printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}
