#include "list_l.h"


// указываем размер списка 0, и первый элемент тоже null
list_L::list_L() {
    listSize = 0;
    head = nullptr;
}

//вставляем элемент в конец списка
void list_L::push_back(int data) {
    // если в первом узле что-то есть
    if (head == nullptr) {
        head = new Node(data);
    } else {
        Node *current = this->head;

        //пока не дошли до последнего элемента, а ссылка на следующий = nullptr
        while (current->pointerNext != nullptr) {
            current = current->pointerNext;
        }
        current->pointerNext = new Node(data);
    }
    listSize++;
}

//возвращает значение узла под номером index
int &list_L::operator[](int index) const {
    int counter = 0;
    Node *current = this->head;

    while (current != nullptr) {
        if (counter == index) {
            return current->data;
        }
        current = current->pointerNext;
        counter++;
    }
    throw out_of_range("Index out of borders");
}


//int list_L::getListSize() const {
//    return listSize;
//}


void list_L::pop_front() {
    Node *temp = head;

    head = head->pointerNext;
    delete temp;

    listSize--;
}

//рекурсивный алгоритм поиска максимального значения
int list_L::find_max(list_L::Node *head) {
    if (head == nullptr) {
        // базовый случай: конец списка
        return INT_MIN; // вернуть минимальное значение, если список пустой
    }

    int max = find_max(head->pointerNext);
    if (head->data > max) {
        return head->data;
    } else {
        return max;
    }
}


void list_L::display() {
    if (head == nullptr)
        return;

    cout << head->data << " ";
    pop_front();
    display();
}

//очистка консоли на мак
void cls() {
    system("/usr/bin/osascript -e 'tell application \"System Events\" to tell process \"Terminal\" to keystroke \"k\" using command down'\n");
}

//ждет пока пользователь продолжит работу
void pause() {
    int a;
    cin >> a;
}
