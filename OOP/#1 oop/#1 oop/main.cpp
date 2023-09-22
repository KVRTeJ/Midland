#include <iostream>

#include "Fraction.h"

/*
 Необходимые методы класса:
 - конструктор (по умолчанию + как минимум один конструктор с параметрами);
 - установление/получение числителя/знаменателя дроби;
 - арифметические операции между дробями (+, -, *, /). Могут быть реализованы в виде перегрузок [+5 баллов] или обычных методов;
 - операции сравнения (>, <, ==, !=). Могут быть реализованы в виде перегрузок [+5 баллов] или обычных методов;
 - приведение дроби к несократимой (допускается как в виде публичного, так и закрытого метода, при условии, что закрытый метод вызывается при операциях, результатом которых может быть сократимая дробь);
 - ввод/вывод дроби в консоль;
 - как минимум два уникальных собственных метода на ваше усмотрение (пример: конвертация из double в обыкновенную дробь (с указанием точности (количества значащих знаков после запятой))).
*/

int main() {
    
    Fraction a(2, 1), b(1,2);
    a.print();
    a.reduce();
    a.print();

    if(a < b) {
        
        std::cout << "true " << std::endl;
        
    }
    
    if(a > b) {
        
        std::cout << "false " << std::endl;
        
    }
    
    a = a * b;
    a.print();
    
    return 0;
}
