import ttkbootstrap as ttk
from InputForm import InputForm
from MainForm import MainForm
from ViewForm import ViewForm

from tkinter import messagebox

class App:
    def __init__(self, style, root):
        self.root = root

        self.root.title("STCET student info form")

        menu = ttk.Menu(master=root)
        themes = ttk.Menu(master=menu)
        menu.add_cascade(label="Themes", menu=themes)

        for x in style.theme_names():
            themes.add_command(label=x, command=lambda t=x: style.theme_use(t))

        self.root.configure(menu=menu)

        container = ttk.Frame()
        container.pack(expand=True)

        self.frames = {}

        for F in (InputForm, MainForm, ViewForm):
            frame = F(parent=container, controller=self)
            self.frames[F.__name__] = frame
            frame.grid(row=0, column=0, sticky="nsew")

        self.showFrame("MainForm")

    def showFrame(self, page_name):
        try:
            frame = self.frames[page_name]
            frame.tkraise()
        except KeyError:
            messagebox.showerror(message=f"Error, view {page_name} could not be loaded!", detail=f"KeyError: The page {page_name} is missing from App.frames")