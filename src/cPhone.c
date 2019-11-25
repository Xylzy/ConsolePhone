#include <stdio.h>
#include "arithmetic.h"
#include "app.h"
#include "input.h"
#include "security.h"
#include <unistd.h>
#include <stdlib.h>
bool errorInput;
char user;

int main()
{
  system("clear");
  printf("\t\t\t\tcPhone\n\t\t\t    OS: uniOS-v1.0\n\n");
  bool access = passwdAccept();
  if(access)
  {
    printf("Welcome!\n");
    sleep(2);
    do
    {
      home:
      system("clear");
      printf("\t\t\t\tcPhone\n\t\t\t    OS: uniOS-v1.0\n\n");
      printf("\t\t\t  [s]Shutdown system\n\t\t\t  [i]System Info\n\n\t\t\t  [c]Calculator App\n\t\t\t  [t]Clock App\n\t\t\t  [m]Music Player App\n\t\t\t  [g]Gallery App\n\t\t\t  [k]Calendar App\nEnter letter: ");
      user = getChar();
      if(user == 'k' || user == 'K' ||user == 'g' || user == 'G' || user == 'c' || user == 'C' || user == 't' || user == 'T' || user == 'm' || user == 'M' || user == 's' || user == 'S' || user == 'i' || user == 'I')
        errorInput = false;
      else
      {
        errorInput = true;
        system("clear");
        printf("ERROR: Application does not exist\n");
        sleep(2);
      }
    } while(errorInput);

    if(user == 'c' || user == 'C')
      calculatorApp();
    else if(user == 't' || user ==  'T')
      clockApp();
    else if(user == 'm' || user == 'M')
      musicPlayerApp();
    else if(user == 's' || user == 'S')
      shutdownSys();
    else if(user == 'i' || user == 'I')
      infoApp();
    else if(user == 'g' || user == 'G')
      galleryApp();
    else if(user == 'k' || user == 'K')
      calendarApp();
    else
      printf("ERROR: ");

    goto home;
  }
  return 0;
}
