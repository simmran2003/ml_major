#include<iostream>

int main(){
int n;std::cin>>n;n/=3;
int cs[8]={0};for(int x;std::cin>>x;)++cs[x];
if(cs[1]==n&&cs[2]+cs[3]==n&&cs[2]>=cs[4]&&cs[4]+cs[6]==n&&cs[6]>=cs[3]){
while(cs[4]--)--cs[2],std::cout<<"1 2 4\n";
while(cs[2]--)std::cout<<"1 2 6\n";
while(cs[3]--)std::cout<<"1 3 6\n";
}else std::cout<<"-1\n";
}