import ttkbootstrap as ttk

class MainForm(ttk.Frame):
    def __init__(self, parent, controller):
        super().__init__(parent)

        self.controller = controller

        label = ttk.Label(master=self, text="Welcome to STCET student data manager", font=("Helvetica", 20))
        label.pack(pady=30)

        ttk.Button(master=self, text="Continue", command=lambda: controller.showFrame("InputForm")).pack(pady=30)
        ttk.Button(master=self, text="View", command=lambda: controller.showFrame("ViewForm")).pack(pady=30)
        ttk.Button(master=self, text="Quit", bootstyle="danger", command=quit).pack(pady=30)