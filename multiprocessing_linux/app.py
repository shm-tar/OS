import threading
import random
import mmap
import os

sorted = []


def shellSort1(arr):
    global sorted

    n = len(arr)
    gap = n // 2
# Do a gapped insertion sort for this gap size.
# The first gap elements a[0..gap-1] are already in gapped
# order keep adding one more element until the entire array
# is gap sorted
    while gap > 0:

        for i in range(gap, n):

        # add a[i] to the elements that have been gap sorted
        # save a[i] in temp and make a hole at position i
            temp = arr[i]

        # shift earlier gap-sorted elements up until the correct
        # location for a[i] is found
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap

        # put temp (the original a[i]) in its correct location
            arr[j] = temp
        gap //= 2
    print(arr)

def shellSort2(arr):
    global sorted



    n = len(arr)
    gap = n // 2
# Do a gapped insertion sort for this gap size.
# The first gap elements a[0..gap-1] are already in gapped
# order keep adding one more element until the entire array
# is gap sorted
    while gap > 0:

        for i in range(gap, n):

        # add a[i] to the elements that have been gap sorted
        # save a[i] in temp and make a hole at position i
            temp = arr[i]

        # shift earlier gap-sorted elements up until the correct
        # location for a[i] is found
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap

        # put temp (the original a[i]) in its correct location
            arr[j] = temp
        gap //= 2
    print(arr)
print("Enter a size,and number of threads ")
size, count_threads = map(int, raw_input().split())

array = [round(random.random() * size) for i in range(size)]

print("array")
print(array)

array1 = array[0:size//2]

array2 = array[size//2:size]

threads = []

semaphore = threading.Semaphore()
if(count_threads == 1):
    thread1 = threading.Thread(target=shellSort1,
                              args=(array,))
    thread1.start()
    thread1.join()
    threads.append(thread1)

if(count_threads == 2):
    thread1 = threading.Thread(target=shellSort1,
                              args=(array1,))
    thread2 = threading.Thread(target=shellSort2,
                              args=(array2,))
    thread1.start()
    thread2.start()
    thread1.join()
    thread2.join()
    threads.append(thread1)
    threads.append(thread2)

#print("sorted= {0}".format(sorted))
