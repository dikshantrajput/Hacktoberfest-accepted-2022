n=int(input('enter n:'))
l=[]
for i in range(n):
    m=int(input('enter scores:'))
    l.append(m)
print(l)
lar=0
for j in range(1,len(l):
if l[j]>lar:
        lar=l[j]
print('largest:',lar)
sec_lar=l[0]
for k in range(0,len(l)-1):
    if l[k]>l[k+1] and l[k]<lar:
        sec_lar=l[k]                
print(sec_lar)
for b in l:
    print(b,'',end='')
