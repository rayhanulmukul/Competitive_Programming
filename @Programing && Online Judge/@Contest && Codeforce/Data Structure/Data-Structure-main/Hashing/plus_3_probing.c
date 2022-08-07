#include <stdio.h>
#include <stdlib.h>

#define SIZE 11

int hash_table[SIZE];

int getHashValue(int item)
{
    return (item % SIZE);
}

int plus_3_hash_value(int item)
{
    return ((item + 3) % SIZE);
}

void insert(int item)
{
    int index = getHashValue(item);
    if (hash_table[index] == -1)
    {
        hash_table[index] = item;
        printf("%d inserted at %d\n", hash_table[index], index);
    }

    else
    {
        int start = index;
        index = plus_3_hash_value(index);

        for (int i = index; i != start;)
        {
            if (hash_table[i] == -1)
            {
                hash_table[i] = item;
                printf("%d inserted at %d\n", hash_table[i], i);
                break;
            }
            i = plus_3_hash_value(i);
        }
    }
}

void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d  ", hash_table[i]);
    }
    printf("\n");
}

int main()
{
    for (int i = 0; i < SIZE; i++)
    {
        hash_table[i] = -1;
    }

    int a[11] = {77, 89, 56, 45, 43, 32, 12, 48, 9, 87, 79};
    for (int i = 0; i < SIZE; i++)
    {
        insert(a[i]);
    }
    display();

    return 0;
}
