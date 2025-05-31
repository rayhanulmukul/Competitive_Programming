#include <stdio.h>
#include<stdlib.h>

void tower_of_hanoi(int disk, char start, char end, char aux) {
    if(disk == 1) {
      printf("disk 1 moved from %c to %c\n", start, end);
      return 0;
    }
    tower_of_hanoi(disk-1, start, aux, end);
    printf("disk %d moved from %c to %c\n", disk, start, end);
    tower_of_hanoi(disk-1, aux, end, start);
}

int main()
{
    int disks;
    printf("Enter the number of disk : ");
    scanf("%d", &disks);
    tower_of_hanoi(disks, 'a', 'b', 'c');
    
    return 0;
}


/*

Input : 3
  
Output:

Enter the number of disk : disk 1 moved from a to b
disk 2 moved from a to c
disk 1 moved from b to c
disk 3 moved from a to b
disk 1 moved from c to a
disk 2 moved from c to b
disk 1 moved from a to b

*/

