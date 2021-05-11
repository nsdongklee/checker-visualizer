# from tkinter import *
# from tkinter import ttk
import tkinter as tk

# root = tk.Tk()
# root.title("Push swap Visualizer")
# root.geometry("400x400")

# print(tk.Tcl().eval('info patchlevel'))

# window = tk.Tk()
# greeting = tk.Label(text="Hello, Tkinter")
# greeting.pack()


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


a = [3,2,1,4,5]
b = [6,7,8,9,0]


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

print("a: ", a)
print("b: ", b)

operations(a, b, "sa")
print("a: ", a)
print("b: ", b)

operations(a, b, "sb")
print("a: ", a)
print("b: ", b)

operations(a, b, "pa")
print("a: ", a)
print("b: ", b)

operations(a, b, "pb")
print("a: ", a)
print("b: ", b)

operations(a, b, "ra")
print("a: ", a)
print("b: ", b)

operations(a, b, "rra")
print("a: ", a)
print("b: ", b)