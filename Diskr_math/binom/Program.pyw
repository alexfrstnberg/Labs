from tkinter import *
from tkinter import scrolledtext
from tkinter.ttk import *
from Polynom import *
from Binom import *

binom = Binom()
polinom = Polynom()
root = Tk()
root.geometry('600x400+200+100')

L = Label(root, font = "Helvetica 12 bold", foreground = "VioletRed1")
L.pack(side = TOP)
T = Text(root, height = 1, width = 80, bg = "hot pink")
T.place(y=30)

E1 = Label(root, text = "Expansion 1", font = "Helvetica 10 bold")
E1.place(y = 60)
frameExp = Frame(root)
frameExp.place(y=90, relwidth = 1)
scrollExp = Scrollbar(frameExp, orient=HORIZONTAL)
Exp = Text(frameExp, wrap = NONE, height = 1, bg = "VioletRed1", xscrollcommand=scrollExp.set)
scrollExp.config(command=Exp.xview)
Exp.pack()
scrollExp.pack(fill = X)

E2 = Label(root, text = "Expansion 2", font = "Helvetica 10 bold")
E2.place(y = 140)
frameExp2 = Frame(root)
frameExp2.place(y=170, relwidth = 1)
scrollExp2 = Scrollbar(frameExp2, orient=HORIZONTAL)
Exp2 = Text(frameExp2, wrap = NONE, height = 1, bg = "deep pink", xscrollcommand=scrollExp2.set)
scrollExp2.config(command=Exp2.xview)
Exp2.pack()
scrollExp2.pack(fill = X)

F = Label(root, text = "Element", font = "Helvetica 10 bold")
F.place(y=230)
Find = Text(root, height = 1, width = 80, bg = "magenta2")
Find.place(y=260)


def newbinom():
    clear()
    top = Toplevel(root)
    top.geometry('200x150')
    top.title('Parameters')
    Label(top, text = "New binom", font='Helvetica 10 bold').grid(row = 0, column = 2, columnspan = 5, sticky = W)
    Label(top, text = "(ax+by)^n").grid(row = 1, column=2, columnspan = 5, sticky = W)
    Label(top, text = 'a = ').grid(row = 2, column = 0, pady=10, sticky = W)
    Label(top, text = 'b = ').grid(row = 2, column = 2, pady=10)
    Label(top, text = 'n = ').grid(row = 2, column = 4, pady=10)
    a, b, n = Entry(top, width = 3), Entry(top, width = 3), Entry(top, width = 3)
    a.grid(row = 2, column = 1, padx=5, pady=10, sticky = W)
    b.grid(row = 2, column = 3, padx=5, pady=10)
    n.grid(row = 2, column = 5, padx=5, pady=10)

    def create():
        global binom 
        binom = Binom(int(a.get()), int(b.get()), int(n.get()))
        top.destroy()
        L.config(text = "Binom") 
        T.insert(END, binom.show())   
    Button(top, text="Create", command = create).grid(row = 3, column=2, columnspan=5, pady=20, sticky = W)

def newpolinom():
    clear()
    top = Toplevel(root)
    top.geometry('200x180')
    top.title('Parameters')
    Label(top, text = "New polynom", font='Helvetica 10 bold').grid(row = 0, column = 2, columnspan = 5, sticky = W)
    Label(top, text = "(ax+by+cz)^n").grid(row = 1, column=2, columnspan = 5, sticky = W)
    Label(top, text = 'a = ').grid(row = 2, column = 0, pady=10, sticky = W)
    Label(top, text = 'b = ').grid(row = 2, column = 2, pady=10)
    Label(top, text = 'c = ').grid(row = 2, column = 4, pady=10, sticky = E)
    Label(top, text = 'n = ').grid(row = 3, column = 2, pady=10)
    a, b, c, n = Entry(top, width = 3), Entry(top, width = 3), Entry(top, width = 3), Entry(top, width = 3) 
    a.grid(row = 2, column = 1, padx=5, pady=10, sticky = W)
    b.grid(row = 2, column = 3, padx=5, pady=10)
    c.grid(row = 2, column = 5, pady=10, sticky = E)
    n.grid(row = 3, column = 3, padx=5, pady=10)

    def create():
        global polinom 
        polinom = Polynom(int(a.get()), int(b.get()), int(c.get()), int(n.get()))
        top.destroy()
        L.config(text = "Polynom") 
        T.insert(END, polinom.show())   
    Button(top, text="Create", command = create).grid(row = 4, column=2, columnspan=5, pady=20, sticky = W)

def bin_exp1():
    Exp.insert(END, binom.exp())

def bin_exp2():
    Exp2.insert(END, binom.exp(True))

def pol_exp1():
    Exp.insert(END, polinom.exp())

def pol_exp2():
    Exp2.insert(END, polinom.exp(True))

def bin_find():
    Find.delete('1.0', END)
    top = Toplevel(root)
    top.geometry('200x150')
    top.title('Parameters')
    Label(top, text = "Find element", font='Helvetica 10 bold').grid(row = 0, column = 1, columnspan = 5, sticky = W)
    Label(top, text = "(ax)^k  (by)^l").grid(row = 1, column=1, columnspan = 5, sticky = W)
    Label(top, text = 'k = ').grid(row = 2, column = 0, pady = 5, sticky = W)
    Label(top, text = 'l = ').grid(row = 3, column = 0, sticky = W)
    k, l = Entry(top), Entry(top)
    k.grid(row = 2, column = 1, pady = 5, sticky = W)
    l.grid(row = 3, column = 1, sticky = W)

    def findb():
        global binom 
        Find.insert(END, binom.find(int(k.get()), int(l.get())))    
        top.destroy()
    Button(top, text="Find", command = findb).grid(row = 4, column = 1, pady = 20)

def pol_find():
    Find.delete('1.0', END)
    top = Toplevel(root)
    top.title('Parameters')
    top.geometry('200x180')
    Label(top, text = "Find element", font='Helvetica 10 bold').grid(row = 0, column = 1, columnspan = 5, sticky = W)
    Label(top, text = "(ax)^k   (by)^l   (cz)^p").grid(row = 1, column=1, columnspan = 5, sticky = W)
    Label(top, text = 'k = ').grid(row = 2, column = 0, pady = 5, sticky = W)
    Label(top, text = 'l = ').grid(row = 3, column = 0, sticky = W)
    Label(top, text = 'p = ').grid(row = 4, column = 0, pady = 5, sticky = W)
    k, l, p  = Entry(top), Entry(top), Entry(top)
    k.grid(row = 2, column = 1, pady = 5, sticky = W)
    l.grid(row = 3, column = 1, sticky = W)
    p.grid(row = 4, column = 1, pady = 5, sticky = W)

    def findp():
        global polinom
        Find.insert(END, polinom.find(int(k.get()), int(l.get()), int(p.get()))) 
        top.destroy()
    Button(top, text="Find", command = findp).grid(row = 5, column = 1, pady = 20)

def clear():
    T.delete('1.0', END)
    Exp.delete('1.0', END)
    Exp2.delete('1.0', END)
    Find.delete('1.0', END)
     

root.title("Calculator")
#ent = Entry(root, width=20)
menubar = Menu(root)

binmenu = Menu(menubar, tearoff = 0)
menubar.add_cascade(label = "Binom", menu = binmenu)
binmenu.add_command(label="New", command = newbinom)
binmenu.add_separator()
binmenu.add_command(label = "Expansion 1", command = bin_exp1)
binmenu.add_command(label = "Expansion 2", command = bin_exp2)
binmenu.add_command(label = "Find", command = bin_find)

polimenu = Menu(menubar, tearoff=0)
menubar.add_cascade(label = "Polinom", menu = polimenu)
polimenu.add_command(label = "New", command = newpolinom)
polimenu.add_separator()
polimenu.add_command(label = "Expansion 1", command = pol_exp1)
polimenu.add_command(label = "Expansion 2", command = pol_exp2)
polimenu.add_command(label = "Find", command = pol_find)

Button(root, text="clear", command = clear).pack(side = BOTTOM)

root.config(menu = menubar)
root.mainloop()