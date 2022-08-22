#!/usr/bin/python3

from gi.repository import Gtk
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider, Button
from matplotlib.figure import Figure
from numpy import arange, pi, random, linspace
import matplotlib.cm as cm
#Possibly this rendering backend is broken currently
#from matplotlib.backends.backend_gtk3agg import FigureCanvasGTK3Agg as FigureCanvas
from matplotlib.backends.backend_gtk3cairo import FigureCanvasGTK3Cairo as FigureCanvas
from matplotlib.backends.backend_gtk3 import NavigationToolbar2GTK3 as NavigationToolbar

class Signals:
    def on_window1_destroy(self, widget):
        Gtk.main_quit()

builder = Gtk.Builder()
builder.add_objects_from_file('bifurcation.glade', ('window1', '') )
builder.connect_signals(Signals())

myfirstwindow = builder.get_object('window1')
sw = builder.get_object('scrolledwindow1')
sw2 = builder.get_object('scrolledwindow2')
sw3 = builder.get_object('scrolledwindow3')
sw4 = builder.get_object('scrolledwindow4')
sw5 = builder.get_object('scrolledwindow5')
sw6 = builder.get_object('scrolledwindow6')


''' PAGE 1 '''

# bifurcation logistic equation
def logistic(r, x):
    return r * x * (1 - x)

fig, ax = plt.subplots()
plt.subplots_adjust(left=0.25, bottom=0.25)

x = np.linspace(0, 1)


l, = plt.plot(x, logistic(2,x),lw=2)
ax.plot(x, logistic(100, x), 'red')
ax.set_title("Logistic")

axcolor = 'lightgoldenrodyellow'
axr = plt.axes([0.25, 0.1, 0.65, 0.03], facecolor=axcolor)
sr = Slider(axr, 'Growth Rate', 1.0, 500.0, valinit=2)
    
def update(val):
    r = sr.val
    l.set_ydata(logistic(r,x))
    fig.canvas.draw_idle()
    
sr.on_changed(update)
resetax = plt.axes([0.8, 0.025, 0.1, 0.04])
button = Button(resetax, 'Reset', color=axcolor, hovercolor='0.975')

def reset(event):
    sr.reset()

button.on_clicked(reset)


canvas = FigureCanvas(fig)
sw.add_with_viewport(canvas)

toolbar = NavigationToolbar(canvas, myfirstwindow)
sw4.add_with_viewport(toolbar)

''' PAGE 2 '''

def lyapunov():
    n = 10000
    # Simulate this system for n values of r linearly spaced between 2.5 and 4
    iterations = 1000
    r = np.linspace(2.5, 4.0, n)
    x = 1e-5 * np.ones(n)
    lyapunov = np.zeros(n)
    fig2, ax2 = plt.subplots(1, 1)
    for i in range(iterations):
        x = logistic(r, x)
        # Compute the partial sum of the Lyapunov exponent.
        lyapunov += np.log(abs(r - 2 * r * x))
    # Display the Lyapunov exponent.
    # Horizontal line.
    ax2.axhline(0, color='blue', lw=.5, alpha=.5)
    # Negative Lyapunov exponent.
    ax2.plot(r[lyapunov < 0],
         lyapunov[lyapunov < 0] / iterations,
         'blue', alpha=.5, ms=.5)
    # Positive Lyapunov exponent.
    ax2.plot(r[lyapunov >= 0],
         lyapunov[lyapunov >= 0] / iterations,
         'red', alpha=.5, ms=.5)
    ax2.set_xlim(2.5, 4)
    ax2.set_ylim(-2, 1)
    ax2.set_title("Lyapunov Exponent")
    plt.tight_layout()
    return fig2

fig2 = lyapunov()
canvas = FigureCanvas(fig2)
sw2.add_with_viewport(canvas)

toolbar = NavigationToolbar(canvas, myfirstwindow)
sw5.add_with_viewport(toolbar)

''' PAGE 3 '''

def bifurcation_diagram():
    n = 400
    # Simulate this system for n values of r linearly spaced between 2.5 and 4
    r = np.linspace(2.5, 4.0, n)
    iterations = 1000
    last = 100
    x = 1e-5 * np.ones(n)
    lyapunov = np.zeros(n)
    fig3, ax1 = plt.subplots(1, 1)
    for i in range(iterations):
        x = logistic(r, x)
        # Compute the partial sum of the
        # Lyapunov exponent.
        lyapunov += np.log(abs(r - 2 * r * x))
        # Display the bifurcation diagram
        if i >= (iterations - last):
           ax1.scatter(r,x, s=0.5, c='black')
    ax1.set_xlim(2.5, 4)
    ax1.set_title("Bifurcation Diagram")
    return fig3
    
fig3 = bifurcation_diagram()
canvas = FigureCanvas(fig3)
sw3.add_with_viewport(canvas)

toolbar = NavigationToolbar(canvas, myfirstwindow)
sw6.add_with_viewport(toolbar)   

myfirstwindow.show_all()
Gtk.main()
