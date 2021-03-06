import re
from tkinter import *
from tkinter import messagebox
from calculation_module import *
import copy

list_of_points = [] # все заданные точки
list_of_min = [] # точки, образующие искорый треугольник (с наименьшей медианой)
minimum_median = [-1.0] # длина минимальной медианы
number_of_corner = [0] # номер вершины, из котрой будет проводится медиана
scaling_params = [0.0, 0.0, 0.0, 0.0, 1.0, 1.0] # параметры масштабирования: Xmax, Xmin, Ymax, Ymin, Kx, Ky

##my_objects = []
##
##for i in range(100):
##    my_objects.append(point(i, -i))
##
##for list_of_points in my_objects:
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
        points_lb.insert(END, '{:d}). ({:.3f}; {:.3f})'.format(len(list_of_points), point_x, point_y))
        list_of_points.append(point(point_x, point_y))
    entry_x.delete(0, END)
    entry_y.delete(0, END)

def paint_triangle():
    main_canvas.delete('all')
    copy_list_of_min = copy.deepcopy(list_of_min)
    scaling_params[0] = list_of_min[0].x
    scaling_params[1] = list_of_min[1].y
    scaling_params[2] = list_of_min[0].x
    scaling_params[3] = list_of_min[1].y
    for p in list_of_min:
        if (p.x > scaling_params[0]):
            scaling_params[0] = p.x
        if (p.x < scaling_params[1]):
            scaling_params[1] = p.x
        if (p.y > scaling_params[2]):
            scaling_params[2] = p.y
        if (p.y < scaling_params[3]):
            scaling_params[3] = p.y
    if (not is_equal(scaling_params[0], scaling_params[1])):
        scaling_params[4] = 600 / (scaling_params[0] - scaling_params[1])
    if (not is_equal(scaling_params[2], scaling_params[3])):
        scaling_params[5] = 600 / (scaling_params[2] - scaling_params[3])

    k_min = min(scaling_params[4], scaling_params[5])
    for p in copy_list_of_min:
        p.x = round(50 + (p.x - scaling_params[1]) * k_min)
        p.y = round(50 + (scaling_params[2] - p.y) * k_min)

    corner = int(number_of_corner[0])
    midle = point(0.0, 0.0)
    copy_middle = point(0.0, 0.0)
    if (corner == 1):
        copy_middle = calc_middle(copy_list_of_min[1], copy_list_of_min[2])
        middle = calc_middle(list_of_min[1], list_of_min[2])
    elif (corner == 2):
        copy_middle = calc_middle(copy_list_of_min[0], copy_list_of_min[2])
        middle = calc_middle(list_of_min[0], list_of_min[2])
    else:
        copy_middle = calc_middle(copy_list_of_min[0], copy_list_of_min[1])
        middle = calc_middle(list_of_min[0], list_of_min[1])

    corner = corner - 1
    pad = 10

    # рисование треугольника и медианы
    main_canvas.create_line(copy_list_of_min[0].x, copy_list_of_min[0].y, copy_list_of_min[1].x, copy_list_of_min[1].y, fill = '#494949')   
    main_canvas.create_line(copy_list_of_min[1].x, copy_list_of_min[1].y, copy_list_of_min[2].x, copy_list_of_min[2].y, fill = '#494949')
    main_canvas.create_line(copy_list_of_min[0].x, copy_list_of_min[0].y, copy_list_of_min[2].x, copy_list_of_min[2].y, fill = '#494949')
    main_canvas.create_line(copy_list_of_min[corner].x, copy_list_of_min[corner].y, copy_middle.x, copy_middle.y, fill = '#FF5D73')

    # оси
    main_canvas.create_line(10, 650, 10, 30, width = 3, arrow = LAST)
    main_canvas.create_text(20, 30, text = "Y")
    main_canvas.create_line(40, 680, 650, 680, width = 3, arrow = LAST)
    main_canvas.create_text(650, 670, text = "X")
    
    # вывод координат
    main_canvas.create_oval(copy_list_of_min[0].x, copy_list_of_min[0].y, copy_list_of_min[0].x, copy_list_of_min[0].y, width = 5, outline = '#800000')
    main_canvas.create_oval(copy_list_of_min[1].x, copy_list_of_min[1].y, copy_list_of_min[1].x, copy_list_of_min[1].y, width = 5, outline = '#800000')
    main_canvas.create_oval(copy_list_of_min[2].x, copy_list_of_min[2].y, copy_list_of_min[2].x, copy_list_of_min[2].y, width = 5, outline = '#800000')
    main_canvas.create_oval(copy_middle.x, copy_middle.y, copy_middle.x, copy_middle.y, width = 5, outline = '#800000')
    main_canvas.create_text(copy_list_of_min[0].x + pad, copy_list_of_min[0].y + pad, text = '({:.2f}; {:.2f})'.format(list_of_min[0].x, list_of_min[0].y), font = "-weight bold")#font = ("Purisa", 8))
    main_canvas.create_text(copy_list_of_min[1].x + pad, copy_list_of_min[1].y + pad, text = '({:.2f}; {:.2f})'.format(list_of_min[1].x, list_of_min[1].y), font = "-weight bold")
    main_canvas.create_text(copy_list_of_min[2].x + pad, copy_list_of_min[2].y + pad, text = '({:.2f}; {:.2f})'.format(list_of_min[2].x, list_of_min[2].y), font = "-weight bold")
    main_canvas.create_text(copy_middle.x + pad, copy_middle.y + pad, text = '({:.2f}; {:.2f})'.format(middle.x, middle.y), font = "-weight bold")

    
    
def print_text():
    label_result.configure(text = 'Результат вычислений:\nНайден треугольник с минимальной медианой, координаты его вершин:\n({:.3f}; {:.3f}),\n({:.3f}; {:.3f}),\n({:.3f}; {:.3f}).\n'
                           'Медиана проводится из вершины\n({:.3f}; {:.3f}).'.format(list_of_min[0].x, list_of_min[0].y, list_of_min[1].x, list_of_min[1].y, list_of_min[2].x, list_of_min[2].y,
                                                                                    list_of_min[int(number_of_corner[0] - 1)].x, list_of_min[int(number_of_corner[0] - 1)].y,))
    
def calculate():
    main_canvas.delete('all')
    size = len(list_of_points)
    if (size < 3):
        messagebox.showerror('Ошибка: невозможно построить треугольник', 'Недостаточно точек для построения треугольника.')
    else:
        for i in range(0, size - 2):
            for j in range(i + 1, size - 1):
                for k in range(j + 1, size):
                    if (not on_the_same_line(list_of_points[i], list_of_points[j], list_of_points[k])):                        
                        cur_min, med_n = calc_min_median(list_of_points[i], list_of_points[j], list_of_points[k])
                        if (med_n == -1):
                            messagebox.showerror('Ошибка: вырожденный треугольник', 'Сумма двух сторон меньше третьей,  треугольник построить нельзя.')
                        else:
                            if (minimum_median[0] < 0 or cur_min < minimum_median[0]):
                                minimum_median[0] = cur_min
                                list_of_min.clear()
                                list_of_min.append(list_of_points[i])
                                list_of_min.append(list_of_points[j])
                                list_of_min.append(list_of_points[k])
                                number_of_corner[0] = med_n
                        
                        
                    #print(list_of_points[i].x, list_of_points[i].y, list_of_points[j].x, list_of_points[j].y, list_of_points[k].x, list_of_points[k].y)

        if (minimum_median[0] < 0):
            messagebox.showerror('Ошибка: вырожденный треугольник', 'Все введенные точки лежат на одной прямой,  треугольник построить нельзя.')
        else:
            print_text()
            paint_triangle()


def check_index(index_str):
    if (len(list_of_points) == 0):
        messagebox.showerror('Ошибка: нет точек', 'Множество точек пусто.')
    else:
        if (not re.fullmatch(r'[+]?(?:\d+)', index_str)):
            messagebox.showerror('Ошибка: некорректный индекс', 'Вводите только положительные целые числа или ноль.')
        else:
            if (int(index_str) >= len(list_of_points)):
                messagebox.showerror('Ошибка: некорректный индекс', 'Вводите только индексы в диапазоне от 0 до {:d} включительно.'.format(len(list_of_points) - 1))
            else:
                return True
    return False

def reset_lb():
    points_lb.delete(0, END)
    for i in range(len(list_of_points)):
        points_lb.insert(END, '{:d}). ({:.3f}; {:.3f})'.format(i, list_of_points[i].x, list_of_points[i].y))

def clear():
    index_str = entry_index.get()
    if (check_index(index_str)):
        index = int(index_str)
        list_of_points.pop(index)
        reset_lb()
        for i in range(0, 4):
            scaling_params[i] = 0.0
        scaling_params[4] = 1.0
        scaling_params[5] = 1.0
        minimum_median[0] = -1
    entry_index.delete(0, END)


def clear_all():
    entry_x.delete(0, END)
    entry_y.delete(0, END)
    points_lb.delete(0, END)
    list_of_points.clear()
    list_of_min.clear()
    for i in range(0, 4):
        scaling_params[i] = 0.0
    scaling_params[4] = 1.0
    scaling_params[5] = 1.0
    minimum_median[0] = -1
    number_of_corner[0] = 0
    main_canvas.delete('all')
    label_result.configure(text = 'Результат вычислений:')
    
    
def change():
    index_str = entry_index.get()
    if (check_index(index_str)):
        index = int(index_str)
        label_x_change.grid(row = 4, column = 34)
        entry_x_change.grid(row = 4, column = 35, columnspan = 2)
        label_y_change.grid(row = 4, column = 37)
        entry_y_change.grid(row = 4, column = 38, columnspan = 2)
        add_button_change.grid(row = 4, column = 40, columnspan = 3, padx = 5, sticky = W)
        


def change_point():
    index = int(entry_index.get())
    point_x = entry_x_change.get()
    point_y = entry_y_change.get()
    if (not check_is_num(point_x) or not check_is_num(point_y)):
        messagebox.showinfo('Ошибка: некорректный ввод', 'Пожалуйста, вводите координаты точек только в вещественном виде.')
    else:
        list_of_points[index].x = int(point_x)
        list_of_points[index].y = int(point_y)
        reset_lb()
        entry_index.delete(0, END)
        label_x_change.grid_forget()
        entry_x_change.grid_forget()
        label_y_change.grid_forget()
        entry_y_change.grid_forget()
        add_button_change.grid_forget()
    entry_x_change.delete(0, END)
    entry_y_change.delete(0, END)
    
        

root = Tk()
root.title('Lab_01.MG') 
root.minsize(1050, 800)
root.configure(background = '#EEE4E1')
#-------------холст-------------
main_canvas = Canvas(width = 700, height = 700, bg = 'white')
main_canvas.grid(row = 1, rowspan = 30, column = 0, columnspan = 30, sticky = W + E + N + S)

#-------------текст-------------
label_input = Label(root, text = 'Введите координаты точки:', relief = GROOVE)
label_input.grid(row = 1, column = 30, columnspan = 10)
label_x = Label(root, text = 'x:', relief = GROOVE)
label_x.grid(row = 2, column = 30)
label_y = Label(root, text = 'y:', relief = GROOVE)
label_y.grid(row = 2, column = 33)
label_result = Label(root, text = 'Результат вычислений:', bg = '#E6BEAE', width = 60, relief = GROOVE)
label_result.grid(row = 11, column = 30, rowspan = 7, columnspan = 20, sticky = W + E + N)
label_index = Label(root, text = 'Точку с индексом', relief = GROOVE)
label_index.grid(row = 3, column = 34, columnspan = 5)

label_x_change = Label(root, text = 'x:', relief = GROOVE)
label_y_change = Label(root, text = 'y:', relief = GROOVE)

#----------список точек---------
points_lb = Listbox(root, height = 10, width = 20, bg = '#E7D8C9', selectbackground = '#B2967D')
points_lb.grid(row = 3, column = 30, columnspan = 4, rowspan = 7, sticky = W)
scroll = Scrollbar(points_lb, orient = 'vertical')
scroll.config(command = points_lb.yview)
scroll.place(relx = 0.87, rely = 0, height = 140)
points_lb.config(yscrollcommand = scroll.set)

#-----------поля ввода----------
entry_x = Entry(root, width = 10, bd = 2)
entry_x.grid(row = 2, column = 31, sticky = W, columnspan = 2)
entry_y = Entry(root, width = 10, bd = 2)
entry_y.grid(row = 2, column = 34, sticky = W, columnspan = 2)
entry_index = Entry(root, width = 5, bd = 2)
entry_index.grid(row = 3, column = 39)

# grid сделать в функции change()
entry_x_change = Entry(root, width = 10, bd = 2)
entry_y_change = Entry(root, width = 10, bd = 2)

#-------------кнопки-------------
add_button = Button(root, text = 'Добавить', command = add_point, relief = RIDGE, width = 10)
add_button.grid(row = 2, column = 36, columnspan = 4, padx = 5, sticky = W)

clear_button = Button(root, text = 'Удалить', command = clear, relief = RIDGE)
clear_button.grid(row = 3, column = 40, columnspan = 4, padx = 5, sticky = W)

change_button = Button(root, text = 'Изменить', command = change, relief = RIDGE)
change_button.grid(row = 3, column = 44, columnspan = 4, padx = 5, sticky = W)

clear_all_button = Button(root, text = 'Очистить все', command = clear_all, relief = RIDGE)
clear_all_button.grid(row = 10, column = 32, columnspan = 4, padx = 5, sticky = W)

calculate_button = Button(root, text = 'Рассчитать', command = calculate, relief = RIDGE)
calculate_button.grid(row = 10, column = 30, columnspan = 2, padx = 5)

add_button_change = Button(root, text = 'Сохранить', command = change_point, relief = RIDGE, width = 8)


root.mainloop()

for obj in list_of_points:
    print(obj.x, obj.y)
