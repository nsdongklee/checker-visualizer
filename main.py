import os
import sys
from matplotlib import pyplot as plt, animation

#######################################################
# Get stack value from $(ARG) env                     #
#######################################################
args = list(map(int, os.environ["ARG"].split()))
print("args: ", args)

#######################################################
# Get operations outputs from push_swap executable    #
#######################################################
operations_list = []
while True:
	try: 
		operations_list.append(input())
	except:
		break
print("operations_list: ", operations_list)

#######################################################
# Generate two stacks                                 #
#######################################################
stack_a = args
stack_b = []

#######################################################
# Definitions for push_swap visualizer                #
#######################################################
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

def push_swap(stack_a, stack_b, ops_list):
	for cmd in ops_list:
		operations(stack_a, stack_b, cmd)
		print("===========start========")
		yield stack_a, stack_b, cmd
		print("============end=========\n")

def push_swap_generator(stack_a, stack_b, ops_list):
	generator = push_swap(stack_a, stack_b, operations_list)
	return generator

def visualize(stack_a, stack_b, ops_list):
	gen = push_swap_generator(stack_a, stack_b, operations_list)

	for data in gen:
		print(data[0], " type: ", type(data[0]))
		print(data[1], " type: ", type(data[1]))
		print(data[2], " type: ", type(data[2]))
	fig, ax = plt.subplots()
	ax.set_title("test")
	


#######################################################
# Execute Visualizer                                  #
#######################################################
# if __name__ == "__main__":
    # visualize()
	# push_swap(stack_a, stack_b, operations_list)