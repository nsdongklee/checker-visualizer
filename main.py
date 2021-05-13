import os
# import numpy as np
from matplotlib import pyplot as plt, animation

#######################################################
# Get stack value from $(ARG) env                     #
#######################################################
args = list(map(int, os.environ["ARG"].split()))

#######################################################
# Get operations outputs from push_swap executable    #
#######################################################
operations_list = []
while True:
	try: 
		operations_list.append(input())
	except:
		break

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
	anime_running = True
	xlim = len(stack_a)
	y_max = max(stack_a)
	y_min = min(stack_a)
	figure, axes = plt.subplots(nrows=2, ncols=1, sharex=True, sharey=True, constrained_layout=True) #, figsize=(10, 7))
	figure.suptitle("Check push_swap program", fontsize=16, fontweight="bold")
	draw_bar_a = axes[0].bar(range(len(stack_a)), stack_a, align="center", linewidth=0.5, color="green")
	draw_bar_b = axes[1].bar(range(len(stack_b)), stack_b, align="center", linewidth=0.5, color="green")
	props = dict(boxstyle='round', facecolor='wheat', alpha=0.5)
	iteration = [0]
	text = axes[0].text(0.98, 1.017, f"# of operations: {iteration[0]}", fontsize=10, horizontalalignment='right', verticalalignment='bottom', transform=axes[0].transAxes, bbox=props)

	def on_click(event):
		nonlocal anime_running
		if anime_running:
			anime.event_source.stop()
			anime_running = False
		else:
			anime.event_source.start()
			anime_running = True
	
	def is_sorted_all(stack_a, stack_b):
		for i in range(len(stack_a) - 1):
			if stack_a[i] > stack_a[i + 1]:
				return 0
		if len(stack_b) > 0:
			return (0)
		return 1

	def update(frame, draw_bar_a, draw_bar_b, iteration):
		stack_a = frame[0]
		stack_b = frame[1]
		ops_cmd = frame[2]
		axes[0].clear()
		axes[1].clear()
		draw_bar_a = axes[0].bar(range(len(stack_a)), stack_a, align="center", linewidth=0.5, color="green")
		draw_bar_b = axes[1].bar(range(len(stack_b)), stack_b, align="center", linewidth=0.5, color="green")
		axes[0].set_title("Stack A", fontstyle="italic", va="center_baseline")
		axes[1].set_title("Stack B", fontstyle="italic", va="center_baseline")
		axes[0].set_ylabel("Value")
		axes[1].set_ylabel("Value")
		axes[0].axhline(0, color="grey", linewidth=0.8)
		axes[1].axhline(0, color="grey", linewidth=0.8)
		axes[0].set_xlim(0, xlim - 0.5)
		axes[0].set_ylim((y_min - 1), (y_max + 1))
		if is_sorted_all(stack_a, stack_b):
			iteration[0] = len(ops_list)
			ops_cmd = "(done)"
		elif ops_cmd == "(null)" and iteration[0] < 3:
			iteration[0] = 0
		elif ops_cmd in ops_list and iteration[0] <= len(ops_list):
			iteration[0] += 1
		axes[0].text(0.98, 1.017, f"# of operations: {iteration[0]}, {ops_cmd}", fontsize=10, horizontalalignment='right', verticalalignment='bottom', transform=axes[0].transAxes, bbox=props)

	figure.canvas.mpl_connect("button_press_event", on_click)
	anime = animation.FuncAnimation(
		fig=figure,
		func=update,
		fargs=(draw_bar_a, draw_bar_b, iteration),
		frames=generator,
		repeat=True,
		blit=False,
		interval=15
	)
	plt.show()
	plt.close()

#######################################################
# Execute Checker-Visualizer                          #
#######################################################
if __name__ == "__main__":
    visualize(stack_a, stack_b, operations_list)
