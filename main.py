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
	_to.insert(0, top)

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
	yield stack_a, stack_b, "(null)"
	for cmd in ops_list:
		operations(stack_a, stack_b, cmd)
		yield stack_a, stack_b, cmd


def push_swap_generator(stack_a, stack_b, ops_list):
	generator = push_swap(stack_a, stack_b, operations_list)
	return generator

def visualize(stack_a, stack_b, ops_list):
	generator = push_swap_generator(stack_a, stack_b, operations_list)
	
	xlim = len(stack_a)
	y_max = max(stack_a)
	y_min = min(stack_a)
	
	figure, axes = plt.subplots(nrows=2, ncols=1, sharex=True, sharey=True)
	
	figure.suptitle("PUSH-SWAP", fontsize=16)
	
	
	
	draw_bar_a = axes[0].bar(range(len(stack_a)), stack_a, align="center", linewidth=0.5)
	draw_bar_b = axes[1].bar(range(len(stack_b)), stack_b, align="center", linewidth=0.5)
	
	iteration = [0]
	
	def update(frame, draw_bar_a, draw_bar_b, iteration):
		stack_a = frame[0]
		stack_b = frame[1]
		print(stack_a, stack_b, frame[2])
		axes[0].clear()
		axes[1].clear()
		draw_bar_a = axes[0].bar(range(len(stack_a)), stack_a, align="center", linewidth=0.5)
		draw_bar_b = axes[1].bar(range(len(stack_b)), stack_b, align="center", linewidth=0.5)
		axes[0].set_title("Stack A")
		axes[1].set_title("Stack B")
	
		axes[0].set_ylabel("Value")
		axes[1].set_ylabel("Value")
	
		axes[0].axhline(0, color="grey", linewidth=0.8)
		axes[1].axhline(0, color="grey", linewidth=0.8)
	
		axes[0].set_xlim(0, xlim - 0.5)
		axes[0].set_ylim((y_min - 1), (y_max + 1))
		
		iteration[0] += 1
	
	anime = animation.FuncAnimation(
		fig=figure,
		func=update,
		fargs=(draw_bar_a, draw_bar_b, iteration),
		frames=generator,
		repeat=True,
		blit=False,
		interval=15,
	)
	
	plt.show()
	plt.close()

#######################################################
# Execute Visualizer                                  #
#######################################################
if __name__ == "__main__":
    visualize(stack_a, stack_b, operations_list)