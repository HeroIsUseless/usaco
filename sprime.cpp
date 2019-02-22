/*
ID:22920179
PROB:sprime
LANG:C++
*/
#include<algorithm>
#include<iostream>
using namespace std;
int zs(int p){ // 判断是不是质数，这里根本没有用到n
	if(p<2)return 0; // 说明他不是质数了
	for(int i=2;i*i<=p;i++) // 判断质数就这么暴力吗？
	    if(p%i==0)return 0;
	return 1;
}
int n,s,q[10001],l;
int a[10]={0,1,2,3,5,7,9}; // 在这里进行了化简操作
void dfs(int k){
	if(k>n){ // 仅仅好像在这里用到了n
		q[++l]=s;
		return;
	}
	for(int i=1;i<=6;i++){ // 不知道6是什么意思，是0-6为什么会这样
		s=s*10+a[i]; // 看来是一直添加的，是从
		if(zs(s)) dfs(k+1); // 用了递归，判断是不是质数，深搜，
		s/=10; // 然后除以10，看来是深搜了
	}
}
int main(){
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
	cin>>n;
	dfs(1); // 1是不是质数的最小值
	sort(q+1,q+l+1); // 现在就已经能够完成了。。。
	for(int i=1;i<=l;i++) // 这里是简单输出，超级简单
	    cout<<q[i]<<'\n';
	return 0;
} 
