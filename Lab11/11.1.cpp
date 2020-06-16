#include <iostream>


int func(int num) {
    if (num < 10)
        return num;
    else {

        int max = num % 10;
        int newNum = num / 10;
        if (max > func(newNum))
            return max;
        else
            return func(newNum);
    }


}

int main() {

    std::cout << func(27306);


}