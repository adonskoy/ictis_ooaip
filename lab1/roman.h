#include <fstream>
#include <vector>


//Пара-соответствие римского и целочисленного представления
struct Pair {
    std::string name;
    int val;

    Pair(std::string n, int v);
};

//Вектор пар-соответсвий
class Name_pairs {
private:
    std::vector<Pair> arr;
public:

    friend class Iterator;

    void push_back(const Pair &p);

    int size();

    ~Name_pairs();
};

//Итератор по вектору соотвествий
class Iterator {
    const Name_pairs *np;
    int index;
public:
    explicit Iterator(const Name_pairs *p);

    void next();

    const Pair *operator->();
};

//Класс римских чисел
class Roman_int {
private:
    int val;

    //Возвращает числовое представления символа
    static int sym_to_int(char c);

    // Перевод строки в целочисленное значение.
    // Алгоритм: Идем с конца в началао. Для начала проверяем, что представления числа верное(XXXX, IIC, IXC - неверные представления)
    // Затем смотрим: если i+1 значение больше текущего, отнимаем текущее, иначе прибавляем
    static int roman_str_to_int(std::string str);

    //Заполнения вектора digits парами соответсия римское число <-> целочисленное
    void prepare_digits();

public:
    explicit Roman_int(int i = 0);

    explicit Roman_int(std::string str);

    //Представление римского чилса в целочисленном формате
    int as_int() const;

    //Представление римского чилса в виде строки
    std::string as_roman() const;

    static Name_pairs digits;

    friend std::istream &operator>>(std::istream &is, Roman_int &r);

    friend std::ostream &operator<<(std::ostream &os, const Roman_int &r);

    //Оператор прибавления для римского числа
    Roman_int &operator+=(const Roman_int &rhs);

    //Оператор вычитания для римского числа
    Roman_int &operator-=(const Roman_int &rhs);

    //Оператор умножения для римского числа
    Roman_int &operator*=(const Roman_int &rhs);

    //Оператор деления для римского числа
    Roman_int &operator/=(const Roman_int &rhs);

    //Оператор сложения римских чисел
    friend Roman_int operator+(const Roman_int &lhs, const Roman_int &rhs);

    //Оператор вычитания римских чисел
    friend Roman_int operator-(const Roman_int &lhs, const Roman_int &rhs);

    //Оператор умножения римских чисел
    friend Roman_int operator*(const Roman_int &lhs, const Roman_int &rhs);

    //Оператор деления римских чисел
    friend Roman_int operator/(const Roman_int &lhs, const Roman_int &rhs);
};

//Оператор ввода римского числа в строковом представлении
std::istream &operator>>(std::istream &is, Roman_int &r);

//Оператор вывода римского числа в строковом представлении
std::ostream &operator<<(std::ostream &os, const Roman_int &r);

//Функция вызова испключения
inline void error(const std::string &msg);