#!/usr/bin/env python
num_map = { '0': '1', 
			'1': '2',
			'2': '3',
			'3': '4',
			'4': '5',
			'5': '6',
			'6': '7',
			'7': '8',
			'8': '9',
			'9': '0'}

def memoize(fn):
	cached = {}
	def wrap(number):
		if number not in cached:
			cached[number] = fn(number)
		return cached[number]
	return wrap

@memoize
def inc(n):
	carry = 1
	temp = []
	for digit in n[::-1]:
		if carry == 1:
			temp.append(num_map[digit])
			if digit == '9':
				carry = 1
			else:
				carry = 0
		else:
			temp.append(digit)

	if carry == 1:
		temp.append('1')
	
	temp.reverse()
	return "".join(temp)


def palindrome(n):
	length = len(n)
	head = n[:length/2]
	if length == 1:
		if n == '9':
			return 11
		else:
			return num_map[n] 

	if length % 2 == 0:
		if head[::-1] > n[length/2:]:
			return "%s%s" % (head, head[::-1])
		else:
			old_len = len(head)
			head = inc(head)
			new_len = len(head)
			middle = ''
			tail = ''
			if old_len < new_len:
				middle = head[-1]
				head = head[:new_len/2]
				return "%s%s%s" % (head, middle, head[::-1])
			else:
				return "%s%s" % (head, head[::-1])
					
	else:
		if head[::-1] > n[length/2+1:]:
			return "%s%s%s" % (head, n[length/2], head[::-1])
		else:
			middle = inc(n[length/2])
			if middle == '10':
				old_len = len(head)
				head = inc(head)
				middle = '0';
				new_len = len(head)
				if old_len < new_len:
					return "%s%s" % (head, head[::-1])
				else:
					return "%s%s%s" % (head, middle, head[::-1])
			else:
				return "%s%s%s" % (head, middle, head[::-1])

if __name__ == '__main__':
	testcases = int(raw_input().strip())
	while (testcases > 0):
		n = raw_input().strip()
		print (palindrome(n))
		testcases -= 1

