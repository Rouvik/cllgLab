import tkinter as tk
import ttkbootstrap as ttk
from tkinter import messagebox
from PrattParser import PrattParser, Lexer

parser = PrattParser()

style = ttk.Style("darkly")
style.configure(".", font=("Helvetica", 16))
root = style.master

toolbar_menu = ttk.Menu(master=root)
themeMenu = ttk.Menu(master=toolbar_menu)
toolbar_menu.add_cascade(label="Themes", menu=themeMenu)
for theme in style.theme_names():
    themeMenu.add_command(label=theme, command=lambda t=theme: style.theme_use(t))

root.configure(menu=toolbar_menu) # type: ignore

container = ttk.Frame(master=root)
container.pack(expand=True)

mathText = ttk.Entry(master=container, width=30, font=("Helvetica", 16))
mathText.pack()

buttonContainer = ttk.Frame(master=container)
buttonContainer.pack()

buttonMap = {}

rowPos = 0
for row in (
    ("1", "2", "3", "+"),
    ("4", "5", "6", "-"),
    ("7", "8", "9", "*"),
    ("0", ".", "=", "/"),
    ("(", ")", "X", "C")
):
    colPos = 0
    for but in row:
        buttonMap[but] = ttk.Button(master=buttonContainer, text=but, command=lambda b=but: mathText.insert(tk.END, b))
        buttonMap[but].grid(row=rowPos, column=colPos, padx=10, pady=10)
        colPos += 1
    rowPos += 1

def clearMath():
    mathText.delete("0", tk.END)

def delMath():
    text = mathText.get()
    if text:
        mathText.delete(len(text)-1, tk.END)

def calculate():
    text = mathText.get()
    if len(text) == 0:
        messagebox.showerror(message="Error empty expression")
    
    lexer = Lexer(text)

    try:
        expr = parser.parseExpression(lexer, 0)
        expr = parser.solveExpresssion(expr)
        mathText.delete("0", tk.END)
        mathText.insert("0", expr.op)
    except Exception as e:
        messagebox.showerror(message="Error failed to evaluate expression", detail=str(e))

buttonMap["C"].config(command=clearMath)
buttonMap["X"].config(command=delMath)
buttonMap["="].config(command=calculate)

# Key binds
# root.bind("<BackSpace>", lambda e: delMath())
root.bind("<Return>", lambda e: calculate())

root.mainloop()