import max_ele

n = int(input("Enter the size of the arr : "))

print("\nEnter the numbers : \n")

numbers = []

for i in range(n):
    ele = int(input())
    numbers.append(ele)



maxi = max_ele.maxEle(numbers)

print(f"Maxi Ele is : {maxi}")




