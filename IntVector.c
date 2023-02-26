#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int *arr;
    int size;
    int capacity;
}IntVector;
void int_vector_free(IntVector *v)
{
    free(v->arr);
    free(v);
}
IntVector *int_vector_new(size_t initial_capacity)
{
    IntVector *new;
    new = (IntVector *)malloc(sizeof(IntVector));
    if(new && initial_capacity >= 0)
    {
        new->arr = (int *)malloc(sizeof(int) * initial_capacity);
        if(new->arr == NULL)
        {
            int_vector_free(new);
            new = NULL;
        }
        else
        {
            new->size = 0;
            new->capacity = initial_capacity;
        }
        return new;
    }
    else
    {
        free(new);
        return NULL;
    }
}
IntVector *int_vector_copy(const IntVector *v)
{
    IntVector *copy;
    copy = (IntVector *)malloc(sizeof(*v));
    if(v && v->arr && copy)
    {
        if(v->capacity >= 0)
            copy->arr = (int *)malloc(sizeof(int) * v->capacity);
        if(copy->arr == NULL)
        {
            int_vector_free(copy);
            copy = NULL;
        }
        else
        {
            for(int i = 0; i < v->size; i++)
                copy->arr[i] = v->arr[i];
            copy->size = v->size;
            copy->capacity = v->capacity;
        }
        return copy;
    }
    else
    {
        free(copy);
        return NULL;
    }
}
int int_vector_get_item(const IntVector *v, size_t index)
{
    return v->arr[index];
}
void int_vector_set_item(IntVector *v, size_t index, int item)
{
    v->arr[index] = item;
}
size_t int_vector_get_size(const IntVector *v)
{
    if(v)
    {
        return v->size;
    }
    else
    {
        fprintf(stderr, "Пустой вектор!\n");
        return -1;
    }
}
size_t int_vector_get_capacity(const IntVector *v)
{
    if(v)
    {
        return v->capacity;
    }
    else
    {
        fprintf(stderr, "Пустой вектор!\n");
        return -1;
    }
}
int int_vector_push_back(IntVector *v, int item)
{
    if(v != NULL && v->arr != NULL)
    {
        if(v->size < v->capacity)
        {
            v->arr[v->size] = item;
            v->size++;
        }
        else if(v->capacity > 0)
        {
            v->arr = (int *) realloc(v->arr, sizeof(int) * v->capacity * 2);
            if(v->arr)
            {
                v->capacity *= 2;
                v->arr[v->size] = item;
                v->size++;
                for(int i = v->size; i < v->capacity; i++)
                    v->arr[i] = 0;
            }
            else
                return -1;
        }
        else if (v->capacity == 0)
        {
            v->arr = (int *) malloc(sizeof(int));
            if(v->arr)
            {
                v->capacity = 1;
                v->arr[0] = item;
                v->size = 1;
            }
            else
                return -1;
        }
        else
            return -1;
        return 0;
    }
    else
        return -1;
}
void int_vector_pop_back(IntVector *v)
{
    if(v && v->arr && v->size > 0)
    {
        v->arr[v->size - 1] = 0;
        v->size--;
    }
}
int int_vector_shrink_to_fit(IntVector *v)
{
    if(v && v->arr)
    {
        if(v->size < v->capacity)
        {
            v->arr = (int *)realloc(v->arr, sizeof(int) * v->size);
            if(v->arr)
            {
                v->capacity = v->size;
                return 0;
            }
            else
                return -1;
        }
        else if(v->size != v->capacity)
            return -1;
        else
            return 0;    //Если size == capacity
    }
    else
        return -1;
}
int int_vector_resize(IntVector *v, size_t new_size)
{
    if(v && v->arr && new_size >= 0)
    {
        if(new_size > v->size)
        {
            if(new_size <= v->capacity)
            {
                for(int i = v->size; i < new_size; i++)
                    v->arr[i] = 0;
                v->size = new_size;
            }
            else
            {
                v->arr = (int *)realloc(v->arr, sizeof(int) * new_size);
                if(v->arr)
                {
                    for(int i = v->size; i < new_size; i++)
                        v->arr[i] = 0;
                    v->capacity = new_size;
                    v->size = new_size;
                }
                else
                    return -1;
            }
        }
        if(new_size < v->size)
        {
            if(int_vector_shrink_to_fit(v) != 0)
            {
                return -1;
            }
        }
    }
    else
        return -1;
    return 0;
}
int int_vector_reserve(IntVector *v, size_t new_capacity)
{
    if(v && v->arr && new_capacity >= 0)
    {
        if(new_capacity > v->capacity)
        {
            v->arr = (int *)realloc(v->arr, sizeof(int) * new_capacity);
            if(v->arr)
            {
                v->capacity = new_capacity;
            }
            else
                return -1;
        }
    }
    else
        return -1;
    return 0;
}
