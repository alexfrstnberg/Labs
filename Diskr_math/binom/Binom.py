from math import pow, factorial as fact

class Binom:
    def __init__(self, a=1, b=1, n=1):
        self.a = a
        self.b = b
        self.n = n
    
    def show(self):
        return '(' + (str(self.a) if abs(self.a) > 1 else '') + ('-' if self.a == -1 else '') + 'x' + ('+' if self.b > 0 else '') + (str(self.b) if abs(self.b) > 1 else '') + ('-' if self.b == -1 else '') + 'y)^' + str(self.n)
    
    def __elem(self, k):
        return ('(' + (str(self.a) if abs(self.a) > 1 else '') + ('-' if self.a == -1 else '') + 'x)' + ('^' + str(self.n-k) if k < self.n-1 else '') if k < self.n else '') + ('∙' + '(' + (str(self.b) if abs(self.b) > 1 else '') + ('-' if self.b == -1 else '') + 'y)' + ('^' + str(k) if k > 1 else '') if k > 0 else '')
    
    def __koef(self, k):
        return (self.a**(self.n-k))*(self.b**k)*(int(fact(self.n)/(fact(k)*fact(self.n-k))))

    def __elem2(self, k):
        return (str(abs(self.__koef(k))) if abs(self.__koef(k)) > 1 else '') + ('x' + ('^' + str(self.n-k) if k < self.n-1 else '') if k < self.n else '') + ('y' + ('^' + str(k) if k > 1 else '') if k > 0 else '')
    
    def exp(self, c = False):
        e = ''
        for i in range(self.n + 1):
            if c == False:
                e += 'C[' + str(i) + '][' + str(self.n) + ']' + self.__elem(i) + (' + ' if i < self.n else '')
            else:
                e += ('+ ' if self.__koef(i) >= 0 and i > 0 else '') + ('- ' if self.__koef(i) < 0 else '') + str(self.__elem2(i)) + ' '
        return e

    def find(self, k, l):
        if k + l == self.n:
            return ('C[' + str(l) + '][' + str(self.n) + ']' + self.__elem(l) + ' = ' + ('- ' if self.__koef(l) <= 0 else '') + self.__elem2(l))
 