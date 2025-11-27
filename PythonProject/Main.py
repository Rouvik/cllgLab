import ttkbootstrap as ttk
from App import App

style = ttk.Style("darkly")
main_root = style.master

if __name__ == "__main__":
    App(style, main_root).root.mainloop()