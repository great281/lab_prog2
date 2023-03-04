#include "IntVector.h"
void show(IntVector *v)
{
    for(int i = 0; i < v->size; i++)
        printf("%d ", v->arr[i]);
    printf("\n");
}
void proc()
{
    while(getchar() != '\n')
        continue;
}
int Vector()
{
    char x[5];
    int true = 1;
    int answer;
    while(true)
    {
        printf("v = ");
        scanf("%s", x);
        x[4] = '\0';
        if((strcmp(x, "copy") == 0))
        {
            answer = 1;
            true = 0;
        }
        else if((strcmp(x, "new") == 0))
        {
            answer = 2;
            true = 0;
        }
        else
            printf("Введите имя вектора(\"copy\" или \"new\")\n");
    }
    return answer;
}
int main()
{
    int true_new = 1, true_copy = 1;
    int y = 1;
    char x;
    int vector;
    int index;
    int check;
    int item;
    size_t k;
    IntVector *new, *copy, *test;
    printf("Введите размер нового массива(int): ");
    while(scanf("%ld", &k) != 1)
    {
        printf("Введите целое число. Например: 11\n");
    }
    if((new = int_vector_new(k)) != NULL)
        printf("Массив создан.\n");
    else
    {
        printf("Ошибка выделения памяти!\n");
        true_new = 0;
    }
    printf("Попытка создания копии массива функцией \"int_vector_copy(const IntVector *v)\"\n");
    if((copy = int_vector_copy(new)))
        printf("Успешно!\n");
    else
    {
        printf("Ошибка выделения памяти!\n");
        true_copy = 0;
    }
    proc();
    while(y)
    {
        printf("Выберите функцию:\n");
        printf("1)int_vector_get_item(const IntVector *v, size_t index)\t2)int_vector_set_item(IntVector *v, size_t index, int item)\n");
        printf("3)int_vector_get_size(const IntVector *v)\t\t4)int_vector_get_capacity(const IntVector *v)\n");
        printf("5)int_vector_push_back(IntVector *v, int item)\t\t6)int_vector_pop_back(IntVector *v)\n");
        printf("7)int_vector_shrink_to_fit(IntVector *v)\t\t8)int_vector_resize(IntVector *v, size_t new_size)\n");
        printf("9)int_vector_reserve(IntVector *v, size_t new_capacity)\ts)Показать векторы\n");
        printf("q)Выход\tc)IntVector *int_vector_copy(const IntVector *v)\n");
        
        scanf("%c", &x);
        switch (x)
        {
        case '1':
            vector = Vector();
            printf("index = ");
            while((scanf("%d", &index)) != 1)
                printf("Введите целое число > 0\nindex = ");
            if(vector == 1)
                check = int_vector_get_item(copy, index);
            if(vector == 2)
                check = int_vector_get_item(new, index);
            if(check != -1)
                printf("Элемент с индексом %d равен %d\n", index, check);
            break;

        case '2':
            vector = Vector();
            printf("index = ");
            while((scanf("%d", &index)) != 1)
                printf("Введите целое число > 0\nindex = ");
            proc();
            printf("item = ");
            while((scanf("%d", &item)) != 1)
                printf("Введите целое число > 0\nitem = ");
            if(vector == 1)
                int_vector_set_item(copy, index, item);
            if(vector == 2)
                int_vector_set_item(new, index, item);
            break;

        case '3':
            vector = Vector();
            if(vector == 1)
                check = int_vector_get_size(copy);
            if(vector == 2)
                check = int_vector_get_size(new);
            if(check != -1)
                printf("Size = %d\n", check);
            break;

        case '4':
            vector = Vector();
            if(vector == 1)
                check = int_vector_get_capacity(copy);
            if(vector == 2)
                check = int_vector_get_capacity(new);
            if(check != -1)
                printf("Capacity = %d\n", check);
            break;

        case '5':
            vector = Vector();
            printf("item = ");
            while((scanf("%d", &item)) != 1)
                printf("Введите целое число > 0\nitem = ");
            if(vector == 1)
                check = int_vector_push_back(copy, item);
            if(vector == 2)
                check = int_vector_push_back(new, item);
            if(check != -1)
                printf("Элемент %d добавлен в конец массива\n", item);
            else
                printf("Ошибка при добавлении элемента %d в массив\n", item);
            break;

        case '6':
            vector = Vector();
            if(vector == 1)
                int_vector_pop_back(copy);
            if(vector == 2)
                int_vector_pop_back(new);
            break;

        case '7':
            vector = Vector();
            if(vector == 1)
                check = int_vector_shrink_to_fit(copy);
            if(vector == 2)
                check = int_vector_shrink_to_fit(new);
            if(check != -1)
                printf("Емкость массива уменьшена до размера\n");
            else
                printf("Ошибка при уменьшении емкости массива\n");
            break;
        
        case '8':
            vector = Vector();
            printf("new_size = ");
            while((scanf("%d", &item)) != 1)
                printf("Введите целое число > 0\nnew_size = ");
            if(vector == 1)
                check = int_vector_resize(copy, item);
            if(vector == 2)
                check = int_vector_resize(new, item);
            if(check != -1)
                printf("Размер массива изменен до %d\n", item);
            else
                printf("Ошибка при изменении размера массива\n");
            break;

        case '9':
            vector = Vector();
            printf("new_capacity = ");
            while((scanf("%d", &item)) != 1)
                printf("Введите целое число > 0\nnew_capacity = ");
            if(vector == 1)
                check = int_vector_reserve(copy, item);
            if(vector == 2)
                check = int_vector_reserve(new, item);
            if(check != -1)
                printf("Емкость массива изменена до %d\n", item);
            else
                printf("Ошибка при изменении емкости массива\n");
            break;

        case 'c':
            printf("Копируемый вектор:\n");
            vector = Vector();
            if(vector == 1)
            {
                printf("Копируем вектор copy в new\n");
                test = int_vector_copy(copy);
                if(test)
                {
                    int_vector_free(new);
                    new = test;
                    printf("Успешно!\n");
                }
                else
                    printf("Ошибка!\n");
            }
            if(vector == 2)
            {
                printf("Копируем вектор new в copy\n");
                test = int_vector_copy(new);
                if(test)
                {
                    int_vector_free(copy);
                    copy = test;
                    printf("Успешно!\n");
                }
                else
                    printf("Ошибка!\n");
            }
            break;

        case 's':
            printf("New: ");
            show(new);
            printf("Copy: ");
            show(copy);
            break;

        case 'q':
            y = 0;
            break;
        default:
            break;
        }
        proc();
    }

    if(true_new)
        int_vector_free(new);
    if(true_copy)
        int_vector_free(copy);
    printf("Завершение работы\n");
    return 0;
}