from math import sqrt, fabs

EPS = 1e-10

class point():
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def print_p(self):
        print(self.x, self.y)


def calc_length(A, B):
    return sqrt((A.x - B.x) ** 2 + (A.y - B.y) ** 2)

def calc_median(side_median, side_2, side_3):
    # side_median - сторона, к которой проведена медиана
    return 0.5 * sqrt(2 * side_2 ** 2 + 2 * side_3 ** 2 - side_median ** 2)

def calc_middle(A, B):
    mx = (A.x + B.x) / 2
    my = (A.y + B.y) / 2
    return point(mx, my)

def is_equal(num_1, num_2):
    # True - если num_1 равен num_2, иначе False
    return (fabs(num_1 - num_2) <= EPS)

def on_the_same_line(A, B, C):
    # True - если лежат на одной прямой, иначе False
    return (is_equal(float((C.x - A.x) * (B.y - A.y)), float((C.y - A.y) * (B.x - A.x))))

def find_max(num_1, num_2, num_3):
    if (num_1 >= num_2):
        if (num_1 >= num_3):
            return num_1
        else:
            return num_3
    elif (num_2 >= num_3):
        return num_2
    else:
        return num_3

def calc_min_median(A, B, C):
    assert not on_the_same_line(A, B, C), "Error: all points are on the same line"
    side_A_B = calc_length(A, B)
    side_B_C = calc_length(B, C)
    side_A_C = calc_length(A, C)
    max_side = find_max(side_A_B, side_B_C, side_A_C)
    min_median = 0.0
    median_num = 0 # номер точки (1, 2, 3), из которой проводится медиана
    if (is_equal(side_A_B, max_side)):
        min_median = calc_median(side_A_B, side_B_C, side_A_C)
        median_num = 3
    elif (is_equal(side_B_C, max_side)):
        min_median = calc_median(side_B_C, side_A_C, side_A_B)
        median_num = 1
    else:
        min_median = calc_median(side_A_C, side_A_B, side_B_C)
        median_num = 2
    return min_median, median_num


##first = point(3.3, 6.38)
##second = point(-2.9, 45)
##third = point(5, 0)


#print('%.4f' % calc_min_median(first, second, third))
