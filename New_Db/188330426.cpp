#include <bits/stdc++.h>

#define int long long

using namespace std;

struct point{
    int x,y;
};
struct line{
    point p1,p2;
}a[4];

int len_line_pow(line a){//求线段长度的平方
    return (a.p1.x-a.p2.x)*(a.p1.x-a.p2.x)+(a.p1.y-a.p2.y)*(a.p1.y-a.p2.y);
}

bool check_same_point(point p1,point p2){//判断两点是否相同
    return p1.x==p2.x&&p1.y==p2.y;
}

bool check_one_line(line a,point p){//判断三点共线
    return (a.p1.y-p.y)*(a.p2.x-p.x)==(a.p2.y-p.y)*(a.p1.x-p.x);
}

bool check_5_point(line a,point p){//判断p是不是在a的1/5点和4/5线之间
    a.p1.x*=5,a.p2.x*=5,a.p1.y*=5,a.p2.y*=5;
    p.x*=5,p.y*=5;
    point p1={a.p1.x+(a.p2.x-a.p1.x)/5,a.p1.y+(a.p2.y-a.p1.y)/5};
    point p4={a.p1.x+(a.p2.x-a.p1.x)/5*4,a.p1.y+(a.p2.y-a.p1.y)/5*4};
    double d=sqrt((double)len_line_pow({p1,p4}));
    double d1=sqrt((double)len_line_pow({p,p1}));
    double d4=sqrt((double)len_line_pow({p,p4}));
    return fabs(d-d1-d4)<1e-7;
}

bool check(line l,line r,line m){
    //条件1：两线有唯一共同端点
    int x=check_same_point(l.p1,r.p1);
    if(check_same_point(l.p1,r.p2)){
        x++;
        swap(r.p1,r.p2);
    }
    if(check_same_point(l.p2,r.p1)){
        x++;
        swap(l.p1,l.p2);
    }
    if(check_same_point(l.p2,r.p2)){
        x++;
        swap(l.p1,l.p2);
        swap(r.p1,r.p2);
    }
    if(x!=1){
        return false;
    }
    // cout<<"T1:OK"<<"\n";
    //条件2：夹角不是钝角,可以是直角
    if(len_line_pow(l)+len_line_pow(r)<len_line_pow({l.p2,r.p2})){
        // cout<<"T2:FALSE"<<"\n";
        // cout<<len_line_pow(l)<<"+"<<len_line_pow(r)<<">"<<len_line_pow({l.p2,r.p2})<<"\n";
        return false;
    }
    // cout<<"T2:OK"<<"\n";
    //条件3：第3线两端点与前两线共线
    if(check_one_line(l,m.p1)&&check_one_line(r,m.p2)){
        ;
    }else if(check_one_line(l,m.p2)&&check_one_line(r,m.p1)){
        swap(m.p1,m.p2);
    }else{
        return false;
    }
    // cout<<"T3:OK"<<"\n";
    //条件4：第3线两端点必须在两线分别的1/5点和4/5线之间
    if(check_5_point(l,m.p1)&&check_5_point(r,m.p2)){
        // cout<<"T4:OK"<<"\n";
        return true;
    }else{
        return false;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin>>T;
    while(T--){
        for(int i=1;i<=3;i++){
            cin>>a[i].p1.x>>a[i].p1.y>>a[i].p2.x>>a[i].p2.y;
        }
        bool flag=false;
        for(int i=1;i<=3&&!flag;i++){
            for(int j=1;j<=3&&!flag;j++){
                if(i==j){
                    continue;
                }
                for(int k=1;k<=3&&!flag;k++){
                    if(k==j||k==i){
                        continue;
                    }
                    // cout<<i<<" "<<j<<" :"<<k<<"\n";
                    flag|=check(a[i],a[j],a[k]);
                }
            }
        }
        cout<<(flag?"YES":"NO")<<"\n";
    }
	return 0;
}