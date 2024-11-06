//Author: Kevin5307
#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
#define longer __int128_t
void die(string S){puts(S.c_str());exit(0);}
const long long mod=998244353;
struct mint
{
	long long value;
	mint(long long x):value(x%mod){}
	mint():value(0){}
	mint operator =(long long b){this->value=b%mod;return *this;}
	long long fixed(){return value;}
	friend mint operator +(const mint &x,const mint &y){mint ans((x.value+y.value)%mod);return ans;}
	friend void operator +=(mint &x,const mint &y){x=x+y;}
	friend mint operator -(const mint &x,const mint &y){mint ans((x.value-y.value+mod)%mod);return ans;}
	friend void operator -=(mint &x,const mint &y){x=x-y;}
	friend mint operator *(const mint &x,const mint &y){mint ans(x.value*y.value%mod);return ans;}
	friend void operator *=(mint &x,const mint &y){x=x*y;}
	friend mint operator ^(const mint &x,const long long &y)
	{
		if(!y)
			return mint(1);
		if(y%2)
			return ((x*x)^(y/2))*x;
		return ((x*x)^(y/2));
	}
	friend void operator ^=(mint &x,const long long &y){x=x^y;}
	friend mint operator /(const mint &x,const mint &y){return x*(y^(mod-2));}
	friend void operator /=(mint &x,const mint &y){x=x/y;}
	friend bool operator <(const mint &x,const mint &y){return x.value<y.value;}
	friend bool operator ==(const mint &x,const mint &y){return x.value==y.value;}
};
struct polynomial
{
	vector<mint> f;
	polynomial(int x){f.clear();f.resize(x+1);}
	polynomial(int x,mint y){f.clear();f.resize(x+1);f[x]=y;}
	int degree(){return (int)(f.size())-1;}
	polynomial(vector<mint> vec):f(vec){}
	friend polynomial operator +(polynomial a,polynomial b)
	{
		polynomial ans(max(a.degree(),b.degree()));
		for(int i=0;i<=ans.degree();i++)
		{
			if(i<=a.degree())
				ans.f[i]+=a.f[i];
			if(i<=b.degree())
				ans.f[i]+=b.f[i];
		}
		return ans;
	}
	friend void operator +=(polynomial &x,const polynomial &y){x=x+y;}
	friend polynomial operator -(polynomial a,polynomial b)
	{
		polynomial ans(max(a.degree(),b.degree()));
		for(int i=0;i<=ans.degree();i++)
		{
			if(i<=a.degree())
				ans.f[i]+=a.f[i];
			if(i<=b.degree())
				ans.f[i]-=b.f[i];
		}
		return ans;
	}
	friend void operator -=(polynomial &x,const polynomial &y){x=x-y;}
	friend polynomial operator %(const polynomial &p,const int &m)
	{
		polynomial ans=p;
		ans.f.resize(m);
		return ans;
	}
	friend void operator %=(polynomial &x,const int &y){x=x%y;}
	friend polynomial operator *(polynomial a,polynomial b)
	{
		const mint g=3;
		int deg=a.degree()+b.degree();
		int len=2,l=1;
		while(len<=deg) len*=2,l++;
		vector<int> rev(len);
		for(int i=0;i<len;i++)
			rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
		a.f.resize(len);
		b.f.resize(len);
		for(int i=0;i<len;i++)
			if(i<rev[i])
			{
				swap(a.f[i],a.f[rev[i]]);
				swap(b.f[i],b.f[rev[i]]);
			}
		for(int i=1;i<len;i*=2)
		{
			mint gn=g^((mod-1)/i/2);
			for(int j=0;j<len;j+=i+i)
			{
				mint g0=1;
				for(int k=0;k<i;k++,g0=g0*gn)
				{
					{
						mint x=a.f[j+k],y=g0*a.f[i+j+k];
						a.f[j+k]=x+y;
						a.f[i+j+k]=x-y;
					}
					{
						mint x=b.f[j+k],y=g0*b.f[i+j+k];
						b.f[j+k]=x+y;
						b.f[i+j+k]=x-y;
					}
				}
			}
		}
		polynomial c(len);
		for(int i=0;i<len;i++)
			c.f[i]=a.f[i]*b.f[i];
		for(int i=0;i<len;i++)
			if(i<rev[i])
				swap(c.f[i],c.f[rev[i]]);
		for(int i=1;i<len;i*=2)
		{
			mint gn=g^((mod-1)/i/2);
			gn=gn^(mod-2);
			for(int j=0;j<len;j+=i+i)
			{
				mint g0=1;
				for(int k=0;k<i;k++,g0=g0*gn)
				{
					mint x=c.f[j+k],y=g0*c.f[i+j+k];
					c.f[j+k]=x+y;
					c.f[i+j+k]=x-y;
				}
			}
		}
		for(int i=0;i<len;i++)
			c.f[i]*=(mint(len)^(mod-2));
		while(!c.f.empty()&&c.f.back()==0)
			c.f.pop_back();
		return c;
	}
	friend void operator *=(polynomial &x,const polynomial &y){x=x*y;}
};
polynomial inversion(polynomial p,int deg,bool f=1)
{
	if(f)
		deg*=2;
	p.f.resize(deg+1);
	if(deg==0)
		return polynomial(0,p.f[0]^(mod-2));
	polynomial w=inversion(p,deg/2,0);
	polynomial g=w+w-p*w*w;
	g%=(deg+1);
	return g;
}
polynomial derivative(polynomial p)
{
	for(int i=0;i<=p.degree();i++)
		p.f[i]*=mint(i);
	p.f.erase(p.f.begin());
	return p;
}
polynomial intergral(polynomial p)
{
	p.f.insert(p.f.begin(),0);
	for(int i=0;i<=p.degree();i++)
		p.f[i]/=mint(i);
	return p;
}
polynomial ln(polynomial p)
{
	return intergral(derivative(p)*inversion(p,p.degree()+1));
}
polynomial exp(polynomial p,int deg)
{
	p%=(deg+1);
	if(!deg)
		return polynomial(0,1);
	polynomial g=exp(p,deg/2);
	return g*(polynomial(0,1)-ln(g)+p)%(deg+1);
}
polynomial ksm(polynomial a,int b)
{
	if(b==1) return a;
	if(b%2) return ksm(a*a,b/2)*a;
	return ksm(a*a,b/2);
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	polynomial p(1000);
	mt19937 rnd(114514);
	while(n--)
	{
		int x;
		scanf("%d",&x);
		p.f[x]=rnd();
	}
	p=ksm(p,k);
	for(int i=0;i<=p.degree();i++)
		if(p.f[i].fixed())
			printf("%d ",i);
	return 0;
}