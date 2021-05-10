import os
import sys

args = list(os.environ["ARG"].split())
print("args are... ", args)

get_opts = []
while True:
	try: 
		get_opts.append(input())
	except:
		break
print(get_opts)


stack_a = args
stack_b = []


def swap(stack):
	stack[0], stack[1] = stack[1], stack[0]

def push(_from, _to):
	top = _from.pop(0)
	_to.append(top)

def rotate(stack):
	first = stack.pop(0)
	stack.append(first)

def reverse_rotate(stack):
	last = stack.pop()
	stack.insert(0, last)


def operations(a, b, cmd):
	if cmd == "sa" and len(a) >= 2:
		swap(a)
	if cmd == "sb" and len(b) >= 2:
		swap(b)
	if cmd == "ss":
		if len(a) >= 2:
			swap(a)
		if len(b) >= 2:
			swap(b)
	if cmd == "pa" and len(b) >= 1:
		push(b, a)
	if cmd == "pb" and len(a) >= 1:
		push(a, b)
	if cmd == "ra" and len(a) >= 2:
		rotate(a)
	if cmd == "rb" and len(b) >= 2:
		rotate(b)
	if cmd == "rr":
		if len(a) >= 2:
			rotate(a)
		if len(b) >= 2:
			rotate(b)
	if cmd == "rra" and len(a) >= 2:
		reverse_rotate(a)
	if cmd == "rrb" and len(b) >= 2:
		reverse_rotate(b)
	if cmd == "rrr":
		if len(a) >= 2:
			reverse_rotate(a)
		if len(b) >= 2:
			reverse_rotate(b)


for cmd in get_opts:
	# print(cmd)
	operations(stack_a, stack_b, cmd)
	# print(stack_a, stack_b)
