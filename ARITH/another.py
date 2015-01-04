#!/usr/bin/env python

if __name__ == '__main__':
	for i in range(input()):
		l = raw_input()
		p = map(l.find, ['+', '-', '*'])
		flag = 0
		for i in range(len(p)):
			if p[i] == -1:
				continue

			u = l[0:p[i]]
			sign = l[p[i]:p[i] + 1]
			b = l[p[i] + 1:]

			if i == 0:
				ans = int(u) + int(b)
			elif i == 1:
				ans = int(u) - int(b)
			else:
				ans = int(u) * int(b)
				if len(u) != 1 and len(b) != 1:
					flag = 1

		if len(u) <= len(b):
			lger = b + sign
		else: 
			lger = u

		if flag == 1:
			space = len(str(ans))
			print u.rjust(space)
			print (sign + b).rjust(space)
			print ('-' * len(lger)).rjust(space)
			lb = len(b)
			for i in range(1, lb + 1):
				print (str(int(u) * int(b[lb - i:lb - i + 1])) + (' ' * (i - 1))).rjust(space)
			print ('-' * space)
			print str(ans).rjust(space) + '\n'
		else:
			if len(str(ans)) > len(u) and len(str(ans)) > len(b):
				lger = str(ans)
			space = len(lger)
			print u.rjust(space)
			print (sign + b).rjust(space)
			print ('-' * space)
			print str(ans).rjust(space) + '\n'
