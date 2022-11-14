def bubbleSort(arr, n):
    flag = True
    for i in range(0, n):
        for j in range(0, n - i -1):
            if arr[j] > arr[j + 1]:
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp
                flag = False
        if flag:
            break


li = [100, 60, 55, 90, 80, 20]
n = len(li)
bubbleSort(li, n)
print(*li)
