#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "set"
using namespace std;
int a=0, b=0, c=0; 
int ra=0, rb=0, rc=0;
std::set<int> res;
void Process(){
    if()
}
//输出这么个东西
//当桶A为空的时候，倒的顺序会有不同
//明显会用到递归的方法
//但是怎样才算个头呢？池子里有这个组合说明到头了
//先c->a,b a->b,c c->a,b 这么来一共六次递归呢
//是深度搜索，就是这样，不做了
int main(){
    FILE *pFile1 = fopen("milk3.in", "r");
    FILE *pFile2 = fopen("milk3.out", "w");
    fscanf(pFile1, "%d%d%d", &a, &b, &c);
    rc = c;
    Process();
    for(auto var : res){
        cout << var;
    }




    fclose(pFile1); fclose(pFile2);
    return 0;
}