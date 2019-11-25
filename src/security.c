#include <stdio.h>
#include <string.h>
#include "input.h"
#include <stdlib.h>
#include <unistd.h>
char userName[] = "bruh";
char password[] = "moment";
int waitTime = 30;
char inputName[10], inputPasswd[10];

bool passwdAccept()
{
  bool access;
  for(int tries = 3; tries > 0; tries--)
  {
    printf("[%d tries left]\nInput name: \n", tries);
    scanf("%s", inputName);
    printf("Please enter password: \n");
    scanf("%s", inputPasswd);
    if(strcmp(inputName, userName) == 0)
    {
      if(strcmp(inputPasswd, password) == 0)
      {
        printf("Access ok\n");
        mockLoading();
        access = true;
        break;
      }

    } else {
      printf("Wrong password or username\n");
      printf("DENIED\n");
      access = false;
      sleep(2);
      system("clear");
    }
  }
  return access;
}
