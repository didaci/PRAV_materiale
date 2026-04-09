
#include <stdio.h>
#include "timeslot.h"

const int  minutesInHour=60;


// VERSION 2



TimeSlot set_h_min(int h, int min){

    TimeSlot ts;
    ts.min=min+h*minutesInHour;
    return ts;
}

TimeSlot set_min(int min){
    TimeSlot ts;
    ts.min=min;
    return ts;
}


void print_h_min(TimeSlot ts){
    int h, min;
    h=ts.min/minutesInHour;
    min=ts.min-minutesInHour*h;

    printf("%d : %d\n",h, min);
    return;
}


void print_min(TimeSlot ts){
    printf("%d\n", ts.min);
    return;
}



