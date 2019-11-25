#ifndef CALENDAR_H
#define CALENDAR_H

int inputyear(void);
int determinedaycode(int year);
int determineleapyear(int year);
void calendar(int year, int daycode);
void unixEnd(int year);

#endif
