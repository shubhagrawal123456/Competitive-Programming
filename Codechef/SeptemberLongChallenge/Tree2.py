t=int(input())
while(t>0):
    t=t-1
    x=int(input())
    y=[int(p) for p in input().split()]
    if 0 in y:
        print(len(set(y))-1)
    else:
       print(len(set(y)))    
