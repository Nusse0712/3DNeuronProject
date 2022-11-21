from gpiozero import LED
from time import sleep
from guizero import App, Text, PushButton, Picture
import matplotlib.pyplot as plt
import serial, time

USB_PORT = "/dev/ttyACM0"

period = 10

#try:
#	usb = serial.Serial(USB_PORT, 9602, timeout=2)
#except:
#	print("Error")
#	print("Exiting")
#	exit()

def graph(Time, Voltage):

	plt.plot(Time, Voltage, color='red', marker='o')
	plt.title('Voltage over time', fontsize=14)
	plt.xlabel('Time (ms)', fontsize=14)
	plt.ylabel('Voltage (mV)', fontsize=14)
	plt.grid(True)
	plt.show()

def Resting():
	print("Resting State")

	if period == 10:
		usb.write(b'B')
	elif period == 20:
		usb.write(b'C')
	elif period == 40:
		usb.write(b'D')
	elif period == 60:
		usb.write(b'E')

#	PauseButtons()

	plt.clf()
	Time = [0, 1]
	Voltage = [-70, -70]
	graph(Time, Voltage)
#	time.sleep(period)
#	ReleaseButtons()

def EarlyDepolarized():
	print("Depolarized")

	if period == 10:
		usb.write(b'F')
	elif period == 20:
		usb.write(b'G')
	elif period == 40:
		usb.write(b'H')
	elif period == 60:
		usb.write(b'I')

	Time = [0, 1, 1.5]
	Voltage = [-70, -70, -55] 
	graph(Time, Voltage)

def LateDepolarized():
	print("Late Depolarized")

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
	print("Repolarized")

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
	print("Hyperpolarized")

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
	print("Auto")
	usb.write(b'A')

def PauseButtons():
	buttonAuto.enabled = False
	button1.enabled = False
	button2.enabled = False
	button3.enabled = False
	button4.enabled = False
	button5.enabled = False
#	time.sleep(period)

def ReleaseButtons():
	buttonAuto.enabled = True
	button1.enabled = True
	button2.enabled = True
	button3.enabled = True
	button4.enabled = True
	button5.enabled = True

app = App(layout="grid", bg="#FFFFFF", height=250, width=537, title="Action Potential Control")

picture = Picture(app, image='CSDept.jpg', width=90, height=80, grid=[0,0])

buttonAuto = PushButton(app, command=Auto, text="Auto", width=57, height=0, grid=[0,3,5,1])
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

names = Text(app, text="Created by:\nAndrew DePace\nAlex Hearne\nColeNussear", color="#D3D3D3", align="right", size=6, grid=[4,4])

app.display()
