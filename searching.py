class Searching:
def __init__(self):
self.__listLength = 0
self.__SearchList = []
def acceptList(self):
self.__listLength = int(input(&quot;Enter the number elements in the list &quot;))
for i in range(self.__listLength):
temp = int(input(f&quot;Enter the element at {i} position &quot;))
self.__SearchList.append(temp)
def LinearSearch(self, key):
for i in range(self.__listLength):
if self.__SearchList[i] == key:
return i
return -1
def SentinelSearch(self, key):
last = self.__SearchList[self.__listLength - 1]
# make a copy of the last element
self.__SearchList[self.__listLength - 1] = key
# set last element to be key
i = 0
while self.__SearchList[i] != key:
# As last element is key it will end for sure
i += 1
self.__SearchList[self.__listLength - 1] = last
if ((i &lt; self.__listLength - 1) or (self.__SearchList[self.__listLength - 1] == key)):
return i
else:
return -1
def BinarySearch(self, key):
print(&quot;List must be sorted in order for binary search\nSo we will sort it&quot;)
print(&quot;New list is &quot;)

sortedList = self.__SearchList.copy()
sortedList.sort()
print(sortedList)
first = 0
last = self.__listLength - 1
while first &lt;= last:
mid = first + (last - first) // 2
if sortedList[mid] == key:
return mid
elif key &gt; sortedList[mid]:
first = mid + 1
else:
last = mid - 1
return -1
def FibonacciSearch(self, key):
print(&quot;List must be sorted in order for fibonacci search\nSo we will sort it&quot;)
print(&quot;New list is &quot;)
sortedList = self.__SearchList.copy()
sortedList.sort()
print(sortedList)
memset(-1, self.__listLength + 2)
fibonacci(self.__listLength + 1)
m = 0
while FibonacciList[m] &lt; self.__listLength:
m += 1
offset = -1
while FibonacciList[m] &gt; 1:
i = min(offset + FibonacciList[m - 2], len(sortedList) - 1)
if key &gt; sortedList[i]:
m = m - 1
offset = i
elif key &lt; sortedList[i]:
m -= 2
else:
return i
# check for the last element
if fibonacci(m - 1) and sortedList[offset + 1] == key:
return offset + 1
return -1

def printList(self):
print(self.__SearchList)

FibonacciList = []

def memset(value, length):
for i in range(length):
FibonacciList.append(value)
# print(FibonacciList[i])

def fibonacci(n):
if FibonacciList[n] == -1:
if n &lt;= 1:
FibonacciList[n] = n
else:
FibonacciList[n] = fibonacci(n - 1) + fibonacci(n - 2)
return FibonacciList[n]

obj = Searching()
obj.acceptList()
while True:
print()
print(&quot;*&quot; * 10 + &quot;Menu&quot; + &quot;*&quot; * 10)
print(&quot;&quot;&quot;1 . Linear Search
2. Binary Search
3. Sentinel Search
4. Fibonacci Search
5. EXIT &quot;&quot;&quot;)
print(&quot;*&quot; * 24)
choice = int(input(&quot;Enter your choice for the following operations:&quot;))
if choice == 1:
obj.printList()
key = int(input(&quot;Enter the key to be found &quot;))
print(&quot;*&quot; * 10)
print(&quot;Linear Search&quot;)
position = obj.LinearSearch(key)
if position == -1:
print(&quot;Element not found&quot;)
else:
print(&quot;Element found at position &quot;, position)
elif choice == 2:

obj.printList()
key = int(input(&quot;Enter the key to be found &quot;))
print(&quot;*&quot; * 10)
print(&quot;Binary Search&quot;)
position = obj.BinarySearch(key)
if position != -1:
print(&quot;Element found at position &quot;, position)
else:
print(&quot;Element not found&quot;)
elif choice == 3:
obj.printList()
key = int(input(&quot;Enter the key to be found &quot;))
print(&quot;*&quot; * 10)
print(&quot;Sentinel Search&quot;)
position = obj.SentinelSearch(key)
if position == -1:
print(&quot;Element not found&quot;)
else:
print(&quot;Element found at position &quot;, position)
elif choice == 4:
obj.printList()
key = int(input(&quot;Enter the key to be found &quot;))
print(&quot;*&quot; * 10)
print(&quot;Fibonacci Search&quot;)
position = obj.FibonacciSearch(key)
if position == -1:
print(&quot;Element not found&quot;)
else:
print(&quot;Element found at position &quot;, position)
print(&quot;*&quot; * 10)
elif choice == 5:
print(&quot;EXIT&quot;)
break
else:
print(&quot;Enter valid input&quot;)