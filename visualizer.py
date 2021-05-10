# from tkinter import *
from tkinter import ttk
import tkinter as tk

# root = tk.Tk()
# root.title("Push-Swap Visualizer")
# root.geometry("540x380")
# root.resizable(False, False)
# root.mainloop()


# window = tk.Tk()
# window.geometry("540x380")
# window.resizable(False, False)
# frame = tk.Frame(master=window, width=150, height=150)
# frame.pack()
# label1 = tk.Label(master=frame, text="I'm at (0, 0)", bg="red")
# label1.place(x=0, y=0)

# label2 = tk.Label(master=frame, text="I'm at (45, 45)", bg="yellow")
# label2.place(x=45, y=45)
# window.mainloop()

root = tk.Tk()
main_frame = tk.Frame(master=root)
main_frame.pack(fill="both")

canvas = tk.Canvas(main_frame, width=600, height=600, bg="black")
canvas.pack(side="left")

tool_frame = tk.Frame(main_frame)
tool_frame.pack(side="right", fill="both")



root.mainloop()
