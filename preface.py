'''
ID: 22920179
TASK: preface
LANG: PYTHON3
'''
import collections
v = []
v.append(['','I','II','III','IV','V','VI','VII', 'VIII','IX']) # (0)1~9
v.append(['','X','XX','XXX','XL','L','LX','LXX','LXXX','XC']) # (0)10~90
v.append(['','C','CC','CCC','CD','D','DC','DCC','DCCC','CM']) # (0)100~900
v.append(['','M','MM','MMM','','','','','','']) # (0)-1000~3000
str = ''
file1 = open('preface.in','r')
file2 = open('preface.out','w')
n = file1.read()
for k in range(1, int(n)+1):
    i = 0
    while k != 0:
        t = k%10
        str += v[i][t]
        i += 1
        k /= 10
result = collections.Counter(str)
for i in range(0,4):
    for j in range(1, 10):
        if result[v[i][j]] != 0:
            file2.write("%s %d\n" % (v[i][j], result[v[i][j]]))
file1.close()
file2.close()