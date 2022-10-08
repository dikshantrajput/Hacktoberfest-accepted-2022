def lcm(a,b):
    
    for i in range(2,a+1):
        if (a%i==0 and b%i==0):
            print("lcm of the given no.s are :",i)
            break
    return lcm


x=int(input("enter a no.:"))
y=int(input("enter a no.:"))
if x>y:
    lcm(x,y)
    
else:
    lcm(y,x) 
