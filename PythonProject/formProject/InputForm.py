import tkinter as tk
from tkinter import messagebox, filedialog
import ttkbootstrap as ttk
from ttkbootstrap import DateEntry
import openpyxl

class InputForm(ttk.Frame):
    def __init__(self, parent, controller):
        super().__init__(parent)
        self.controller = controller

        self.glb_row = 0

        self.name = self.formRow("Name: ", ttk.Entry(master=self, width=30))
        self.address = self.formRow("Address: ", tk.Text(master=self, width=30, height=3))
        self.dob = self.formRow("Date of Birth: ", DateEntry(master=self, width=12))
        self.dept = self.formRow("Department: ", ttk.Combobox(master=self, values=["CSE", "IT", "AIML", "ECE"]))
        self.cls10 = self.formRow("Class 10 marks (%): ", ttk.Entry(master=self, width=30))
        self.cls12 = self.formRow("Class 12 marks (%): ", ttk.Entry(master=self, width=30))

        gender_options = ["Male", "Female", "Others"]

        self.gender_var = tk.StringVar()
        self.gender_var.set(gender_options[0])

        ttk.Label(master=self, text="Gender: ").grid(row=6, column=0)

        gender_root = tk.Frame(master=self)
        gender_root.grid(row=6, column=1)

        i = 0
        for opt in gender_options:
            ttk.Radiobutton(master=gender_root, text=opt, variable=self.gender_var, value=opt).grid(row=0, column=i, padx=5)
            i += 1

        ttk.Button(master=self, text="Submit", command=self.submitCB).grid(row=7, column=1, pady=30)
        ttk.Button(master=self, text="Back", command=lambda: controller.showFrame("MainForm")).grid(row=7, column=2, pady=30)

    def formRow(self, labelText, elem):
        tk.Label(master=self, text=labelText).grid(row=self.glb_row, column=0, pady=10)
        elem.grid(row=self.glb_row, column=1)
        self.glb_row += 1
        return elem

    def submitCB(self):
        wb = openpyxl.Workbook()
        ws = wb.active
        ws.append(["Name", "Address", "Date of Birth", "Department", "Class 10 marks (%)", "Class 12 marks (%)", "Gender"])
        ws.append([self.name.get(), self.address.get("1.0", "end-1c"), str(self.dob.get_date()), self.dept.get(), float(self.cls10.get()), float(self.cls12.get()), self.gender_var.get()])
        
        fname = filedialog.asksaveasfilename()
        if fname is None:
            messagebox.showerror(message="Error no file selected, failed to save")
            return
        
        wb.save(fname)
        messagebox.showinfo(message="User data saved successfully!", detail=f"User data saved in excel file {fname}")

