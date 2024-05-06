/*   │ ┤ ┐ ░ ▒ ▓ █ └ ┴ ┬ ├ ─ ┼ ┘ ┌ ► ◄ ▲ ▼

┌─────────────┐      ┌─────────────┐        ┌─────────────┐      ┌─────────────┐
│     HEAD    │      │             │        │     HEAD    │      │             │
│             │  ┌──>│             │        │             │  ┌──>│             │
├─────────────┤  │   ├─────────────┤        ├─────────────┤  │   ├─────────────┤
│     next    ┼──┘   │    next     │        │     next    ┼──┘   │    next     │
└─────────────┘      └─────────────┘        └─────────────┘      └─────────────┘
            создание                                    удаление
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {  // прототип
    int info;
    struct stack* next;  // неполный тип данных

} OBJECT;  // typedef - позволяет обращаться к структуре как OBJECT

OBJECT* push(OBJECT* HEAD, int info_v) {          // добавление элемента стека. Возвращает указатель на новый элемент стека
    OBJECT* p = malloc(sizeof(OBJECT));           // указатель на выделенную память для нового элемента стека
    p->info = info_v;                             // через указатель в поле info заносим значение info_v
    printf("Добавляется элемент: %d\n", info_v);  // показываем с какими данными создается элемент
    p->next = HEAD;                               // следующий элемент стека будет голова
    return p;                                     // возвращаем указатель на новый созданный объект
}

OBJECT* pop(OBJECT* HEAD) {  // удаление элемента стека. Параметром будет верхний элемент стека. Возвращает указатель на следующий элемент стека
    if (HEAD == NULL) {      // если верхний объект несуществует...
        return HEAD;         // то ничего не будем делать и возвратим указатель HEAD равный NULL
    }
    printf("Удаляется элемент: %d\n", HEAD->info);  // показываем с какими данными удаляется элемент
    OBJECT* p_next = HEAD->next;                    // меняем указатель на следующий элемент этого стека или NULL если элементов нет в стеке
    free(HEAD);                                     // освобождаем память на указатель текущего элемента
    return p_next;                                  // возвращаем адрес следующего элемента этого стека
}

void show(const OBJECT* HEAD) {    // функция отображения всех объектов стека. OBJECT* HEAD - ссылка на вершину стека
    const OBJECT* current = HEAD;  // временный указатель, который перебирает элементы стека с Головы
    while (current != NULL) {
        printf("Элемент: %p; значение: %d\n", current, current->info);  // выводим данные текущего элемента
        current = current->next;                                        // передвигаем указатель на следующий элемент стека
    }
}

int main() {
    OBJECT* HEAD = NULL;  // определяем начальный элемент стека (голова)

    printf("Создаем элементы стека: \n");
    HEAD = push(HEAD, 1);  // создаем новый элемент и меняем указатель на HEAD. Голова будет новым созданным объектом!
    HEAD = push(HEAD, 2);
    HEAD = push(HEAD, 3);

    show(HEAD);  // выводим все элементы стека

    printf("\nУдаляем элементы стека: \n");
    while (HEAD != NULL) {
        HEAD = pop(HEAD);  // удаляем все элементы последовательно из стека
    }

    return 0;
};