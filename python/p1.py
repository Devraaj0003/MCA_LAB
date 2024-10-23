a = input("Enter a String: ")
print(a[0] + a[1:].replace(a[0].lower(),'$'))

b = a[-1] + a[1:-1]+ a[0]
print(b)

