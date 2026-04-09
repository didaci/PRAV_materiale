
#ifndef TIMESLOT_H
#define TIMESLOT_H


const int  minutesInHour;

typedef struct timeslot{
    int min;
}TimeSlot;


TimeSlot set_h_min(int h, int min);
TimeSlot set_min(int min);
void print_h_min(TimeSlot ts);
void print_min(TimeSlot ts);


#endif //TIMESLOT_H
