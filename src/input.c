#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <termios.h>
//#include <stropts.h>

float getValue()
{
  float value;
  scanf("%f", &value);
  return value;
}

char getChar()
{
  char charc;
  scanf(" %c", &charc);
  return charc;
}
bool continueRunApp()
{
  bool run, error;
  char inputChar;
  do
  {
    printf("Enter a letter: ");
    inputChar = getChar();

    if(inputChar == 'y' || inputChar == 'n' || inputChar == 'Y' || inputChar == 'N')
      error = false;
    else
    {
      error = true;
      printf("ERROR: Unknown command. Choose again\n");
    }
  }while(error);

  if(inputChar == 'y' || inputChar == 'Y')
    run = true;
  else
    run = false;
  system("clear");
  return run;
}

void mockLoading()
{
  for(int i = 0; i <= 100; i++)
  {
    printf("Loading..........%d\n", i);
    usleep(5000);
    system("clear");
  }
}

int keybrdHit()
{
    static const int STDIN = 0;
    static bool initialized = false;

    if(!initialized)
    {
      termios term;
      tcgetattr(STDIN, &term);
      term.c_lflag &= ~ICANON;
      tcsetattr(STDIN, TCSANOW, &term);
      setbuf(stdin, NULL);
      initialized = true;
    }
    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;
}
