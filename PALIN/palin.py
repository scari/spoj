#!/usr/bin/env python
def palindrome(n):
	length = len(n)
	head = n[:length/2]
	if length == 1:
		if int(n) == 9:
			return 11
		else:
			return int(n) + 1

	if length % 2 == 0:
		if int(head[::-1]) > int(n[length/2:]):
			return "%s%s" % (head, head[::-1])
		else:
			old_len = len(head)
			head = str(int(head) + 1);
			new_len = len(head)
			middle = 0
			tail = 0
			if old_len < new_len:
				middle = head[-1]
				head = head[:new_len/2+1]
				return "%s%s%s" % (head, middle, head[::-1])
			else:
				return "%s%s" % (head, head[::-1])
					
	else:
		if int(head[::-1]) > int(n[length/2+1:]):
			return "%s%s%s" % (head, str(n)[length/2], head[::-1])
		else:
			middle = int(n[length/2]) + 1
			if middle == 10:
				head = str(int(head) + 1);
				middle = 0;
				return "%s%s" % (head, head[::-1])
			else:
				return "%s%s%s" % (head, middle, head[::-1])

if __name__ == '__main__':
    testcases = int(raw_input().strip())
    while (testcases > 0):
        n = raw_input().strip()
        print (palindrome(n))
        testcases -= 1

