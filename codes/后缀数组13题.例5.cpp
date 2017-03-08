#include<iostream> 
#include<cstring>
#include<cstdio>
const int aaa =1e4+5;       
using namespace std;       
char s[aaa];   
int sa[aaa],wa[aaa],wb[aaa],tong[aaa],wv[aaa];      
int rank[aaa],height[aaa];      
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
void calheight(int n)
{
	int i,j,k=0;
	for(i=1;i<=n;i++) rank[sa[i]]=i;
	for(i=0;i<n;height[rank[i++]]=k)
	for(k?k--:0,j=sa[rank[i]-1];s[i+k]==s[j+k];k++);
	return;
}
int main()  
{  
    int t;  
    scanf("%d",&t);  
    while(t--)  
    {  
    	int i;  
        scanf("%s",s);  
        int n=strlen(s);   
    	da(n+1,128);  
        calheight(n);  
        long long ans=n*(n+1)/2;  
        for(i=1;i<=n;i++)  
		ans-=height[i];  
        printf("%lld\n",ans);  
    }  
}  
