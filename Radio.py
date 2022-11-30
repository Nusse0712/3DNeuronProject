import tkinter as tk
from tkinter import ttk
global value

root = tk.Tk()
root.geometry('500x200')
root.resizable(False, False)
root.title('Seconds for display')


def pass_selected_time():
    value=selected_time.get()
    print(value)
    #usb write function would go here. Pass "value" to arduino.


selected_time = tk.IntVar()
times = (('10 Seconds', 10),
         ('20 Seconds', 20),
         ('40 Seconds', 40),
         ('60 Seconds', 60))

# label
label = ttk.Label(text="Select display time")
label.pack(fill='x', padx=5, pady=5)

# radio buttons
for time in times:
    r = ttk.Radiobutton(
        root,
        text=time[0],
        value=time[1],
        variable=selected_time
    )
    r.pack(fill='x', padx=5, pady=5)

# button
button = ttk.Button(root,text="Confirm",command=pass_selected_time)

button.pack(fill='x', padx=5, pady=5)


root.mainloop()