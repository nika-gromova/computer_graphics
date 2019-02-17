import re
from tkinter import *
from calculation_module import *

##my_objects = []
##
##for i in range(100):
##    my_objects.append(point(i, -i))
##
##for obj in my_objects:
##    print(obj.x, obj.y)

def check_is_num(number):
    return (re.fullmatch(r'[+-]?(?:\d+(?:\.\d*)?|\.\d+)', number))   # [-+]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)?

def add_point():
    point_x = entry_x.get()
    point_y = entry_y.get()
    if (not check_is_num(point_x) or not check_is_num(point_y)):
        messagebox.showinfo('Ошибка: некорректный ввод', 'Пожалуйста, вводите координаты точек только в вещественном виде.')
    else:
        point_x = float(point_x)
        point_y = float(point_y)
        points_lb.insert(END, '({:.3f}; {:.3f})'.format(point_x, point_y))
        list_of_points.append(point(point_x, point_y))
    entry_x.delete(0, END)
    entry_y.delete(0, END)


def clear_all():
    entry_x.delete(0, END)
    entry_y.delete(0, END)
    points_lb.delete(0, END)
    list_of_points.clear()


list_of_points = []

root = Tk()
root.title('Lab_01.MG') 
root.minsize(1000, 800)
#-------------холст-------------
main_canvas = Canvas(width = 700, height = 700, bg = 'white')
main_canvas.grid(row = 1, rowspan = 30, column = 0, columnspan = 30, sticky = W + E + N + S)

#-------------текст-------------
label_input = Label(root, text = 'Введите координаты точки:')
label_input.grid(row = 1, column = 30, columnspan = 4)
label_x = Label(root, text = 'x:')
label_x.grid(row = 2, column = 30)
label_y = Label(root, text = 'y:')
label_y.grid(row = 2, column = 32)

#----------список точек---------
points_lb = Listbox(root, height = 10, width = 20, bg = '#FFFAF0', selectbackground = '#800000')
points_lb.grid(row = 3, column = 30, columnspan = 4, rowspan = 7, sticky = W)
scroll = Scrollbar(points_lb, orient = 'vertical')
scroll.config(command = points_lb.yview)
scroll.place(relx = 0.87, rely = 0, height = 160)
points_lb.config(yscrollcommand = scroll.set)

#-----------поля ввода----------
entry_x = Entry(root, width = '10', bd = 2)
entry_x.grid(row = 2, column = 31, sticky = W)
entry_y = Entry(root, width = '10', bd = 2)
entry_y.grid(row = 2, column = 33, sticky = W)

#-------------кнопки-------------
add_button = Button(root, text = 'Добавить', command = add_point)
add_button.grid(row = 2, column = 34, columnspan = 2, padx = 5)
clear_button = Button(root, text = 'Очистить', command = clear_all)
clear_button.grid(row = 3, column = 34, columnspan = 2, padx = 5)

root.mainloop()

