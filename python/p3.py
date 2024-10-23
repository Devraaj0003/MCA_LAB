a = input("Enter a String 1 : ")
b = input("Enter a String 2 : ") 
a = a.split()
b = b.split()
print(set(a)-set(b))

a = input("Enter a String: ")
a=a.split()
print(set(a))


a=[]
print("Empty : ",not bool(len(a)))
