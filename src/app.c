#include <stdio.h>
#include "arithmetic.h"
#include "input.h"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "calendar.h"
#include "images.h"

bool error, continueRun;
char op, input;
float total, valueX, valueY;

void calculatorApp()
{
  do{
    do
    {
      system("clear");
      printf("\t\t\t\tCalculator v1.0\n\n");
      printf("\t\t\t  [0]Back\n\n\t\t\t  [+] For addition\n\t\t\t  [-] For subtraction\n\t\t\t  [*] For multiplying\n\t\t\t  [/] For Division\n");
      printf("\n\t\t\t  Special function:\n\t\t\t  [^] For square function\n");
      printf("Enter operator: ");
      op = getChar();
      if(op == '+' || op == '-' || op == '*' || op == 'x' || op == '/' || op == '^' || op == '0')
        error = false;
        else
        {
          error = true;
          system("clear");
          printf("Not a valid operator. Choose another\n");
          sleep(2);
        }
      }while(error);
      system("clear");
      switch(op)
      {
        case '+':
          printf("Enter first value: ");
          valueX = getValue();
          printf("Enter second value: ");
          valueY = getValue();
          total = add(valueX, valueY);
          printf("Total: %.2f\n", total);
          break;
        case '-':
          printf("Enter first value: ");
          valueX = getValue();
          printf("Enter second value: ");
          valueY = getValue();
          total = sub(valueX, valueY);
          printf("Total: %.2f\n", total);
          break;
        case '*':
          printf("Enter first value: ");
          valueX = getValue();
          printf("Enter second value: ");
          valueY = getValue();
          total = mty(valueX, valueY);
          printf("Total: %.2f\n", total);
          break;
        case '/':
          printf("Enter first value: ");
          valueX = getValue();
          printf("Enter second value: ");
          valueY = getValue();
          total = divs(valueX, valueY);
          printf("Total: %.2f\n", total);
          break;
        case '^':
          printf("Enter first value: ");
          valueX = getValue();
          float value = sqr(valueX);
          printf("\t\t\t  [+] For addition\n\t\t\t  [-] For subtraction\n\t\t\t  [*] For multiplying\n\t\t\t  [/] For Division\nPress _ to skip\n");
          do
          {
            printf("Enter an operator for to calculate the second value\nEnter operator: ");
            op = getChar();
            if(op == '+' || op == '-' || op == '*' || op == 'x' || op == '/' || op == '_')
            error = false;
            else if(op == ' ')
            {
              error = false;
              break;
            }
            else
            {
              error = true;
              printf("Not a valid operator. Choose another\n");
            }
          }while(error);
          system("clear");
          switch(op)
          {
            case '+':
              printf("Enter second value: ");
              valueY = getValue();
              total = add(value, valueY);
              printf("Total: %.2f\n", total);
              break;
            case '-':
              printf("Enter second value: ");
              valueY = getValue();
              total = sub(value, valueY);
              printf("Total: %.2f\n", total);
              break;
            case '*':
              printf("Enter second value: ");
              valueY = getValue();
              total = mty(value, valueY);
              printf("Total: %.2f\n", total);
              break;
            case '/':
              printf("Enter second value: ");
              valueY = getValue();
              total = divs(value, valueY);
              printf("Total: %.2f\n", total);
              break;
            case '_':
              printf("Total: %.2f\n", value);
              break;
            }
          }
          printf("\t\t\t  Calculate again?\n\t\t\t  [y]Yes\n\t\t\t  [n]No\n");
          continueRun = continueRunApp();

        }while(continueRun);
}
void clockApp()
{
  do
  {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    strftime(s, sizeof(s), "%c", tm);
    printf("%s\n", s);
    sleep(1);
    system("clear");
    if(keybrdHit())
      break;
    printf("Press any key to exit\n\n");
  }while(true);
  system("clear");
}

void musicPlayerApp()
{
  system("clear");
  do
  {
    do
    {
      printf("Music Player\nv1.0\n\n");
      printf("Available music:\n[0]Back\n\n[1]Conway's Child\n[2]Liebestraume\n[3]Platinum\n[4]Vivere La Vita\n");
      printf("Enter number: ");
      input = getChar();
      if(input == '0' || input == '1' || input == '2' || input == '3' || input == '4')
        error = false;
      else
      {
        error = true;
        printf("Song doesn't exist\n\n");
        sleep(3);
        system("clear");
      }

    }while(error);

    system("clear");
    if(input == '1')
      system("mpg123 ../assets/Conway_Child.mp3");
    else if(input == '2')
      system("mpg123 ../assets/lieb.mp3");
    else if(input == '3')
      system("mpg123 ../assets/Platinum.mp3");
    else if(input == '4')
      system("mpg123 ../assets/vita.mp3");
    else if(input == '0')
      break;
    else
      printf("ERROR: Music file does not exist or corrupted\n");

    printf("Choose another song?\n[y]Yes\n[n]No\n");

    continueRun = continueRunApp();
  }while(continueRun);
  system("clear");
}

void shutdownSys()
{
  printf("Shutting down system\n");
  sleep(3);
  printf("bye\n");
  sleep(1);
  system("pkill cPhone");
}

void infoApp()
{
  system("clear");
  do
  {
    do
    {
      printf("System Info\n\n[0]Back\n\n[1]About\n[2]Version number\n[3]GNU GPLv3\nEnter number: ");
      input = getChar();
      if(input == '0' || input == '1' || input == '2' || input == '3')
        error = false;
        else
        {
          error = true;
          printf("Option doesn't exist\n\n");
          sleep(3);
          system("clear");
        }
      }while(error);
      system("clear");
      if(input == '0')
        break;
      else if(input == '1')
      {
        printf("About\n\n");
        printf("A phone written entirely in C\n");
        printf("Written in rush. Took one week\n");
      } else if(input == '2') {
        printf("Version Number\n\nuniOS-v0.2a\n");
      } else if(input == '3') {
        printf("GNU GPLv3\n\n");
        system("cat ../COPYING");
      } else {
        printf("ERROR: Unknown");
      }
    }while(true);
}

void galleryApp()
{
  system("clear");
  do
  {
    do
    {
      printf("Gallery ASCII v1.0\n\n[0]Back\n\n[1]Wolf\n[2]Bottle\n[3]Umbrella\nEnter number: ");
      input = getChar();

      if(input == '0' || input == '1' || input == '2' || input == '3')
        error = false;
        else
        {
          error = true;
          printf("Image not exist\n\n");
          sleep(3);
          system("clear");
        }
    }while(error);
    system("clear");
    if(input == '0')
      break;
    else if(input == '1')
      wolf();
    else if(input == '2')
      bottle();
    else if(input == '3')
      umbrella();
    else
      printf("ERROR: Unknown");

    printf("Choose another image?\n[y]Yes\n[n]No\n");
    continueRun = continueRunApp();
  }while(continueRun);
  system("clear");
}

void calendarApp()
{
  system("clear");
  do
  {
    do
    {
      printf("Calendar v1.0\n\n[0]Back\n\n[1]Display calendar\nEnter number: ");
      input = getChar();

      if(input == '0' || input == '1')
        error = false;
        else
        {
          error = true;
          printf("Option not exist\n\n");
          sleep(3);
          system("clear");
        }
    }while(error);

	int year, daycode;//, leapyear;

  if(input == '0')
    break;
  else if(input == '1')
  {
	   year = inputyear();
	   daycode = determinedaycode(year);
	   determineleapyear(year);
	   calendar(year, daycode);
     unixEnd(year);
	   printf("\n");
  } else {
    printf("ERROR: Unknown\n");
  }

  printf("Continue?\n[y]Yes\n[n]No\n");
  continueRun = continueRunApp();
}while(continueRun);

}
