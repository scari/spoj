#!/usr/bin/env python
import sys

def print_bar(len, spaces):
	for i in xrange(len):
		if i < spaces:
			sys.stdout.write(' ')
		else:
			sys.stdout.write('-')

	sys.stdout.write('\n')

def pop(operand, index):
	if index < 0:
		return None
	if index > len(operand)-1:
		return None

	return operand[index]


def minus(lop, rop, len):
	borrow = 0
	temp = 0
	result = []
	for i in xrange(len-1, 0, -1):
		l = pop(lop, i)
		r = pop(rop, i)
		if l == None: l = 0
		if r == None: r = 0
		temp = int(l)-int(r)-borrow
		if temp < 0:
			borrow = 1;
			temp = 10 - temp;
		else:
			borrow = 0;
			result.append(str(temp))

	if borrow == 1:
		result.append('-')

	result.reverse()
	return "".join(result)

def plus(lop, rop, len):
	carry = 0
	result = []
	temp = 0
	for i in xrange(len-1, 0, -1):
		l = pop(lop, i)
		r = pop(rop, i)
		if l == None: l = 0
		if r == None: r = 0
		temp = int(l) + int(r) + carry
		if temp > 10:
			result.append(str(temp%10))
			carry = 1;
		else:
			result.append(str(temp))
			carry = 0;

	result.reverse()
	return "".join(result)
		
def multiply(lop, rop, len):
	carry = 0
	result = []
	temp = 0
	for i in xrange(len-1, 0, -1):
		l = pop(lop, i)
		r = pop(rop, i)
		temp = int(l) * int(r) + carry
		if temp > 10:
			result.append(str(temp%10))
			carry = temp / 10;
		else:
			result.append(str(temp))
			carry = 0;

	result.reverse()
	return "".join(result)

ops = ['*', '-', '+']
def show_form(s):
	for op in ops:
		try:
			lop, rop = s.split(op)
			break;
		except:
			continue;

	print " %s" % lop
	print "%s%s" % (op, rop)
	lop_len = len(lop)
	rop_len = len(rop)
	l = lop_len
	if lop_len < rop_len: l = rop_len

	res = ''
	if op != '*':
		if op == '-':
			res = minus(lop, rop, l)
		else:
			res = plus(lop, rop, l)

		spaces = len(res) - l
		if (lop_len < rop_len):
			print_bar(l, spaces)
		else:
			print_bar(l, spaces)

	else:
		res = multiply(lop, rop, l)
		print_bar(len(res), 0)

	print res

if __name__ == '__main__':
	testcases = int(raw_input().strip())
	while (testcases > 0):
		n = raw_input().strip()
		show_form(n)
		testcases -= 1

