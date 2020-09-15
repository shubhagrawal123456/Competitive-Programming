t= int(input())
while(t>0):
    t=t-1
    x= int(input())
    c=0
    a=[]
    for i in range(x): 
     a.append([int(d) for d in input().split()])
    for j in range(x-1,0,-1):
        p=a[j][j-1]+1
        if p!=a[j][j]:
            c=c+1
            q=j+1
            for i in range(q):
                for k in range(i,q):
                    temp=a[i][k]
                    a[i][k]=a[k][i]
                    a[k][i]=temp
    print(c)                
