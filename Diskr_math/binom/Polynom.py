from math import pow, factorial as fact

class Polynom:
    def __init__(self, a=1, b=1, c=1, n=1):
        self.a = a
        self.b = b
        self.c = c
        self.n = n

    def show(self):
        return '(' + (str(self.a) if abs(self.a) > 1 else '') + ('-' if self.a == -1 else '') + 'x' + ('+' if self.b > 0 else '') + (str(self.b) if abs(self.b) > 1 else '') + ('-' if self.b == -1 else '') + 'y' + ('+' if self.c > 0 else '') + (str(self.c) if abs(self.c) > 1 else '') + ('-' if self.c == -1 else '')+ 'z)^' + str(self.n)

    def __elem(self, lst):
        return ( '∙' + '(' + (str(self.a) if abs(self.a) > 1 else '') + ('-' if self.a == -1 else '') + 'x)' + ('^' + str(lst[0]) if lst[0] > 1 else '') if lst[0] > 0 else '') + ( '∙' + '(' + (str(self.b) if abs(self.b) > 1 else '') + ('-' if self.b == -1 else '') + 'y)' + ('^' + str(lst[1]) if lst[1] > 1 else '') if lst[1] > 0 else '') + ( '∙' + '(' + (str(self.c) if abs(self.c) > 1 else '') + ('-' if self.c == -1 else '') + 'z)' + ('^' + str(lst[2]) if lst[2] > 1 else '') if lst[2] > 0 else '')

    def __koef(self, lst):
        return (self.a**(lst[0]))*(self.b**lst[1])*(self.c**lst[2])*int(fact(self.n)/(fact(lst[0])*fact(lst[1])*fact(lst[2])))

    def __elem2(self, lst):
        return (str(abs(self.__koef(lst))) if abs(self.__koef(lst)) > 1 else '') + ('x' + ('^' + str(lst[0]) if lst[0] > 1 else '') if lst[0] > 0 else '') + ('y' + ('^' + str(lst[1]) if lst[1] > 1 else '') if lst[1] > 0 else '') + ('z' + ('^' + str(lst[2]) if lst[2] > 1 else '') if lst[2] > 0 else '')

    def exp(self, c = False):
        e = ''
        k = create_lst(self.n)
        for index, i in enumerate(k):
            if c == False:
                e += 'P(' + str(i[0]) + ',' + str(i[1]) + ',' + str(i[2]) + ')' + self.__elem(i) + (' + ' if index != len(k)-1 else '')
            else:
                e += ('+ ' if self.__koef(i) >= 0 and index > 0 else '') + ('- ' if self.__koef(i) < 0 else '') + str(self.__elem2(i)) + ' '
        return e
    
    def find(self, k, l, p):
        if k + l + p == self.n:
            return ('P(' + str(k) + ',' + str(l) + ',' + str(p) + ')' + self.__elem([k,l,p]) + ' = ' + ('- ' if self.__koef([k,l,p]) <= 0 else '') + self.__elem2([k,l,p]))

def partition(n, d = 2, depth=0):
    if d == depth:
        return [[]]
    return [
        item + [i]
        for i in range(n+1)
        for item in partition(n-i, d, depth=depth+1)
        ]

def create_lst(n):
   return [[n-sum(p)] + p for p in partition(n)]