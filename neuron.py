from gpiozero import LED
from time import sleep
from guizero import App, Text, PushButton, Picture, ButtonGroup
import matplotlib.pyplot as plt
import serial, time

USB_PORT = "/dev/ttyACM0"

period = 10

try:
	usb = serial.Serial(USB_PORT, 9602, timeout=2)
except:
	print("Error")
	print("Exiting")
	exit()


def update_value():
	global period
	if choices.value == "10":
		period = 10
	elif choices.value == "20":
		period = 20
	elif choices.value == "40":
		period = 40
	elif choices.value == "60":
		period = 60

def graph(Time, Voltage):

	plt.plot(Time, Voltage, color='red', marker='o')
	plt.axis([-0.25, 5.25, -95, 45])
	plt.title('Voltage over time', fontsize=14)
	plt.xlabel('Time (ms)', fontsize=14)
	plt.ylabel('Voltage (mV)', fontsize=14)
	plt.grid(True)
	plt.show()

def Resting():
	global period

	if period == 10:
		usb.write(b'B')
	elif period == 20:
		usb.write(b'C')
	elif period == 40:
		usb.write(b'D')
	elif period == 60:
		usb.write(b'E')

	plt.clf()
	Time = [0, 1]
	Voltage = [-70, -70]
	graph(Time, Voltage)

def EarlyDepolarized():
	global period

	if period == 10:
		usb.write(b'F')
	elif period == 20:
		usb.write(b'G')
	elif period == 40:
		usb.write(b'H')
	elif period == 60:
		usb.write(b'I')

	plt.clf()
	Time = [0, 1, 1.5]
	Voltage = [-70, -70, -55] 
	graph(Time, Voltage)

def LateDepolarized():
	global period

	if period == 10:
		usb.write(b'J')
	elif period == 20:
		usb.write(b'K')
	elif period == 40:
		usb.write(b'L')
	elif period == 60:
		usb.write(b'M')

	plt.clf()
	Time = [0, 1, 1.5, 2]
	Voltage = [-70, -70, -55, 40]
	graph(Time, Voltage)

def Repolarized():
	global period

	if period == 10:
		usb.write(b'N')
	elif period == 20:
		usb.write(b'O')
	elif period == 40:
		usb.write(b'P')
	elif period == 60:
		usb.write(b'Q')

	plt.clf()
	Time = [0, 1, 1.5, 2, 3]
	Voltage = [-70, -70, -55, 40, -90]
	graph(Time, Voltage)

def Hyperpolarized():
	global period

	if period == 10:
		usb.write(b'R')
	elif period == 20:
		usb.write(b'S')
	elif period == 40:
		usb.write(b'T')
	elif period == 60:
		usb.write(b'U')

	plt.clf()
	Time = [0, 1, 1.5, 2, 3, 4, 5]
	Voltage = [-70, -70, -55, 40, -90, -70, -70]
	graph(Time, Voltage)

def Auto():
	usb.write(b'A')

app = App(layout="grid", bg="#FFFFFF", height=275, width=537, title="Action Potential Control")

picture = Picture(app, image='CSDept.jpg', width=90, height=80, grid=[0,0])

buttonAuto = PushButton(app, command=Auto, text="Auto", width=57, height=0, grid=[0,4,5,1])
buttonAuto.bg="#62C62D"
button1 = PushButton(app, command=Resting, text="Resting", width=9, height=3, grid=[0,1])
button1.bg="#fff2ce"
button2 = PushButton(app, command=EarlyDepolarized, text="Early\nDepolarized", width=9, height=3, grid=[1,1])
button2.bg="#ffe59d"
button3 = PushButton(app, command=LateDepolarized, text="Late\nDepolarized", width=9, height=3, grid=[2,1])
button3.bg="#ffd96e"
button4 = PushButton(app, command=Repolarized, text="Repolarized", width=9, height=3, grid=[3,1])
button4.bg="#ffd151"
button5 = PushButton(app, command=Hyperpolarized, text="Hyperpolarized", width=9, height=3, grid=[4,1])
button5.bg="#ffc420"

selectionText = Text(app, text="Select Time:", size=11, grid=[0,3])
choices = ButtonGroup(app, horizontal=True, options=[
			   ["10 seconds", "10"],
			   ["20 seconds", "20"],
			   ["40 seconds", "40"],
		           ["60 seconds", "60"]
			],
			selected="10", command=update_value, grid=[1,3,4,1])


names = Text(app, text="Created by:\nAndrew DePace\nAlex Hearne\nColeNussear", color="#D5D5D5", align="right", size=6, grid=[4,5])

app.display()
