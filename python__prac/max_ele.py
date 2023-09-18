def maxEle(numbers):
    maxi = numbers[0]
    for ele in numbers:
        if maxi < ele:
            maxi = ele
    
    return maxi