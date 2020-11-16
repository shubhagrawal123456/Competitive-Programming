temp = 2*1000000

nump = [True for i in range(temp+1)]

def func(): 
     
    x = 2
    while (x * x <=temp): 
          
        if (nump[x] == True): 
               
            for i in range(x * x, temp+1, x): 
                nump[i] = False
        x += 1
func()
for t in range(int(input())):
    pos = 2
    temp = int(input())
    lis = list(map(int,input().split()))
    a={}
    for j in range(temp):
        if lis[j] not in a.keys():
            print(pos, end= ' ')
            a[lis[j]] = pos
            pos+=1
            while(nump[pos]!=True):
                pos+=1
        else:
            print(a[lis[j]], end=' ')
    print()
