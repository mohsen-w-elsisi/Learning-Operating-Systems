## 3
Yes, the order matters. after swicthing the order, the task will first issue the IO, handoing control to the other [rocess until it complete, and by that time, the IO willhave finished executing. This better utilises system resources.

## 4
Both processes finish after 11 untis of time, as control of the CPU is not handed to aother process while the first IO executing task is pending IO completion.

## 5
The same result obtained in question 3

## 6
No. The 3 IO operiations could be finished while the other processes run. Instead, they're start has been delayed until other programms have finished running to completion. This waists time. IO is sitting idle, while it could otherwise be working and finish the process earlier.

## 7 
That process has already demonstrated that it is interested in IO. This means it may be likely that it will issue another IO request. hence running that process immeadiately after its done means it may issue another IO request which will complete in the background while other processes use the CPU. This is the more time effecient way to finish all processes in the shortest ammount of time. 
