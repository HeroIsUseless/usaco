/*
ID:22920179
LANG:C++
TASK:airprog
*/
#include "iostream"
#include "cstdio"
#include "cstdlib"
using namespace std;
//就是先输入一个n，表示要组成的长度
//然后输入一个m，表示两个数字都在1~m之间找
//p和q没有大小关系，但是输出有问题
//应该用q来排序，然后再用p来排序
//用暴力破解法，p从1开始，q也从1开始，看它们的乘积
//有没有越界，如果没有越界，就是了，是刚好为n的，
//那么就唯一了
int main(){
    FILE *pFile1 = fopen("airprog.in", "r");
    FILE *pFile2 = fopen("airprog.out", "w");
    int n, m;//p, q都选自m
    fscanf(pFile1, "%d %d", &n, &m);
    return 0;
}