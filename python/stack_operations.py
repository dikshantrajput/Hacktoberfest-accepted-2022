n=eval(input("enter a list:"))
x=len(n)
print("length of the list is :",x)
n.insert(2,'i')
print("list after insertion is :",n)
n.append(5)
print("list after append id :",n)
n.remove('i')
print("list after removal is :",n)
p=n.pop(1)
print("popped element is:",p)
n.clear()
print("cleared list is :",n) 