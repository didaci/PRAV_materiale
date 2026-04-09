// FILE timeslot_2

#include <stdio.h>
#include "timeslot.h"



int main()
{


    TimeSlot ts;
    ts= set_h_min(1, 10);

    printf("TIME SLOT (h, m): ");
    print_h_min(ts);
    printf("TIME SLOT (m): ");
    print_min(ts);


    ts= set_min(70);
    printf("TIME SLOT (h, m): ");
    print_h_min(ts);
    printf("TIME SLOT (m): ");
    print_min(ts);


    getchar();
    return 0;

}

