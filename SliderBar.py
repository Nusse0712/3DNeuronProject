import tkinter as tk

value = 10
class Slider(tk.Scale):

    def __init__(self, master=None, **kwargs):
        self.increment = kwargs.pop('increment',1)
        tk.Scale.__init__(self, master, **kwargs)
        self.bind('<Button-1>', self.jump)

    def jump(self, event):
        global value
        clicked = self.identify(event.x, event.y)
        if clicked == 'trough1':
            self.set(self.get() - self.increment)
        elif clicked == 'trough2':
            self.set(self.get() + self.increment)
        else:
            return None
        value=w.get()
        #Andrew here we will need to usb write
        #pretty sure it is usb.write() then just plug in "value"
        #It should constantly usb.write() the updated value to the arduino
        print(value)
        return 'break'

# example useage:
master = tk.Tk() 
#create horizontal slider bar from 10 to 60 seconds, increments of 10
w = Slider(master, from_=10, to=60, increment=10, tickinterval = 10, length=400, orient=tk.HORIZONTAL)
w.pack()
print(value)
#We will need a usb.write() here as well because this covers the initial start value of 10 seconds.
master.mainloop()