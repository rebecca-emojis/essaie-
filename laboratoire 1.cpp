#include <iostream>
#include <bitset>
#include <cstring> 

using namespace std;

// Объявление функций //
void показатьРазмеры();
void показатьБинарныйInt(int n);
void показатьБинарныйFloat(float f);
void показатьБинарныйDouble(double d);
int изменитьБит(int n, int позиция, int значение);
int инвертироватьЗнак(int n);

int main() {
    cout << "=== ПРАКТИЧЕСКАЯ РАБОТА №1 ===" << endl << endl;
    
    // 1. Размеры памяти //
    показатьРазмеры();
    
    // 2. Пример с целым числом //
    int моеЦелое = -42;
    cout << "ПРИМЕР С ЦЕЛЫМ ЧИСЛОМ:" << endl;
    показатьБинарныйInt(моеЦелое);
    
    // 3. Пример с float //
    float моеFloat = 3.14f;
    cout << "ПРИМЕР С FLOAT:" << endl;
    показатьБинарныйFloat(моеFloat);
    
    // 4. Пример с double //
    double моеDouble = 2.71828;
    cout << "ПРИМЕР С DOUBLE:" << endl;
    показатьБинарныйDouble(моеDouble);
    
    // 5. Изменить бит //
    cout << "ИЗМЕНЕНИЕ БИТА:" << endl;
    int до = 10;  // 1010 в двоичном //
    int после = изменитьБит(до, 1, 0);  // Меняет 2-й бит на 0
    cout << "До: " << до << " = ";
    показатьБинарныйInt(до);
    cout << "После изменения бита 1→0: " << после << " = ";
    показатьБинарныйInt(после);
    
    // 6. ЗАДАЧА 21: Инверсия знака //
    cout << "=== ЗАДАЧА 21: ИНВЕРСИЯ ЗНАКА ===" << endl;
    int тест = 7;
    int инвертированный = инвертироватьЗнак(тест);
    cout << "Число: " << тест << endl;
    cout << "После инверсии: " << инвертированный << endl;
    cout << "Проверка (-7): " << -тест << endl;
    
    return 0;
}

// ============ ОПРЕДЕЛЕНИЯ ФУНКЦИЙ ============ //

// 1. Функция для отображения размеров //
void показатьРазмеры() {
    cout << "РАЗМЕРЫ ТИПОВ (в байтах):" << endl;
    cout << "================================" << endl;
    cout << "bool: " << sizeof(bool) << endl;
    cout << "char: " << sizeof(char) << endl;
    cout << "short: " << sizeof(short) << endl;
    cout << "int: " << sizeof(int) << endl;
    cout << "long: " << sizeof(long) << endl;
    cout << "float: " << sizeof(float) << endl;
    cout << "double: " << sizeof(double) << endl;
    cout << "long double: " << sizeof(long double) << endl;
    cout << "================================" << endl << endl;
}

// 2. Функция для отображения двоичного представления int
void показатьБинарныйInt(int число) {
    bitset<32> биты(число);  // 32 бита для int
    
    cout << "Число: " << число << endl;
    cout << "Двоичное (32 бита): " << endl;
    
    // Бит знака (первый бит)
    cout << "Знак: ";
    if (биты[31] == 0) 
        cout << "ПОЛОЖИТЕЛЬНЫЙ" << endl;
    else 
        cout << "ОТРИЦАТЕЛЬНЫЙ" << endl;
    
    // Показать все биты
    cout << "Биты: ";
    for (int i = 31; i >= 0; i--) {
        cout << биты[i];
        if (i % 4 == 0 && i != 0) cout << " ";  // Пробел каждые 4 бита
    }
    cout << endl << endl;
}

// 3. Функция для отображения двоичного представления float
void показатьБинарныйFloat(float число) {
    // Копируем биты float в int для чтения//
    unsigned int биты;
    memcpy(&биты, &число, sizeof(float));
    
    bitset<32> битыFloat(биты);
    
    cout << "Float: " << число << endl;
    cout << "Двоичное (IEEE 754): " << endl;
    
    
    cout << "Знак (бит 31): " << битыFloat[31] << endl;
    cout << "Экспонента (биты 23-30): ";
    for (int i = 30; i >= 23; i--) {
        cout << битыFloat[i];
    }
    cout << endl;
    
    cout << "Мантисса (биты 0-22): ";
    for (int i = 22; i >= 0; i--) {
        cout << битыFloat[i];
    }
    cout << endl << endl;
}

// 4. Функция для отображения двоичного представления double
void показатьБинарныйDouble(double число) {
    // Тот же принцип, но для double (64 бита)
    unsigned long long биты;
    memcpy(&биты, &число, sizeof(double));
    
    bitset<64> битыDouble(биты);
    
    cout << "Double: " << число << endl;
    cout << "Двоичное (64 бита IEEE 754): " << endl;
    

    
    cout << "Знак (бит 63): " << битыDouble[63] << endl;
    
    cout << "Экспонента (биты 52-62): ";
    for (int i = 62; i >= 52; i--) {
        cout << битыDouble[i];
    }
    cout << endl;
    
    cout << "Мантисса (биты 0-51): ";
    for (int i = 51; i >= 0; i--) {
        cout << битыDouble[i];
        if (i % 4 == 0 && i != 0) cout << " ";
    }
    cout << endl << endl;
}

// 5. Функция для изменения бита
int изменитьБит(int число, int позиция, int новоеЗначение) {
    if (новоеЗначение == 1) {
        // Установить бит в 1: использовать OR
        return число | (1 << позиция);
    } else {
        // Установить бит в 0: использовать AND с NOT
        return число & ~(1 << позиция);
    }
}

// 6. ЗАДАЧА 21: Инвертировать знак без умножения
int инвертироватьЗнак(int число) {
    // Метод: Дополнение до 2
    return ~число + 1;
}