For this problem, consider it like a game with no relation of reality. This is just to practice some problem solving strategies.

X-Kingdom has trapped n number of soldiers of their opponent. They want to execute them.

They found out a strategy so that the prisoners will kill each other. At the end, one prisoner
will be alive and he will be released. As part of the process, they labeled each trapped soldier a
sequence number starting from 1 and ending at n. 

So, all the n number of prisoners standing in a
circle waiting to be executed. However, one soldier was distracting the sequence and it was
found out that they were standing in reverse order instead of proper order like the following
picture (let’s say n = 7):

7-> 6 -> 5 -> 4 -> 3 -> 2 -> 1

After realizing the wrong order of sequence, they reversed the circle to the correct order (note
that they have not just changed their labels, they have physically changed their order):

1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7

Now they will start the executing process. The counting out begins at some point in the circle
and proceeds around the circle in a fixed direction. In each step, a certain number of people are
skipped and the next person is executed. The elimination proceeds around the circle (which is
becoming smaller and smaller as the executed people are removed), until only the last person
remains, who is spared.

Given the total number of persons n (>=2) and a number k (>0) which indicates that k-1 persons
are skipped and kth person is killed in circle. The task is to choose the place in the initial circle
so that you are the last one remaining and so survive.

For example, if n = 5 and k = 2, then the safe position is 3. Firstly, the person at position 2 is
killed, then person at position 4 is killed, then person at position 1 is killed. Finally, the person at
position 5 is killed. So, the person at position 3 survives.

If n = 7 and k = 3, then the safe position is 4. The persons at positions 3, 6, 2, 7, 5, 1 are killed in
order, and person at position 4 survives.

