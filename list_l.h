#ifndef FILATOV6_0_LIST_L_H
#define FILATOV6_0_LIST_L_H

#include <iostream>

using namespace std;


class list_L {
public:
    list_L();

    //получить размер списка
//    [[nodiscard]] int getListSize() const;

    // получение значения элемента
    int &operator[](int index) const;

    //удаление первого элемента
    void pop_front();

    void push_back(int data);


    //узел списка
    class Node {
    public:
        // указатель на следующий элемент
        Node *pointerNext;
        // информация внутри узла
        int data;

        // конструктор узла
        explicit Node(int data = 0, Node *pointerNext = nullptr) {
            this->data = data;
            this->pointerNext = pointerNext;
        }
    };

    int listSize;
    Node *head;

    int find_max(Node *head);
    void display();
};

//очистка консоли на мак
[[maybe_unused]] void cls();

//ждет пока пользователь продолжит работу
[[maybe_unused]] void pause();

#endif // FILATOV6_0_LIST_L_H
