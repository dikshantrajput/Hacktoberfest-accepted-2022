pos = -1
def search(li,n):
    l = 0
    h = len(li) - 1
    while l<=h:
        mid = int((l+h) / 2)  
        print('mid = ',mid)
        if li[mid] == n:
            globals()['pos'] = mid
            return True
        else:
            if n >li[mid]:
                l = mid+1
                print('Low = ',l)
            else:
                h = mid-1  
                print('High = ',h)
                

li = [3,40,21,34,1,24,875,256,98864,86]
n = int(input('Enter The Number that You want to search : ')) 

if search(li,n):
    print('Number is found at position : ',pos+1)
else:
    print(f'! The {n} is not present in the list')