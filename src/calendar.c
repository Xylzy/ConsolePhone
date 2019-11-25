#include<stdio.h>
bool err;

int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
{
	" ",
	"\n\n\nJanuary",
	"\n\n\nFebruary",
	"\n\n\nMarch",
	"\n\n\nApril",
	"\n\n\nMay", //sort of like enum from C++, where each month have their ID indexes. 0 is empty month
	"\n\n\nJune",
	"\n\n\nJuly",
	"\n\n\nAugust",
	"\n\n\nSeptember",
	"\n\n\nOctober",
	"\n\n\nNovember",
	"\n\n\nDecember"
};


int inputyear(void)
{
	int year;

	do
	{
		printf("Please enter a year (max 4 digits and not less or equal to 0) : ");
		scanf("%d", &year);

		if(year > 0 || year <= 9999)
		{
			err = false;
			return year;
		}
		else
		{
			printf("Not a suitable year\nChoose again\n");
			//fseek(stdin, 0, 0);
			err = true;
		}
	}while(err);
}

int determinedaycode(int year)
{
	int daycode;
	int d1, d2, d3;

	d1 = (year - 1.)/ 4.0;
	d2 = (year - 1.)/ 100.;
	d3 = (year - 1.)/ 400.;
	daycode = (year + d1 - d2 + d3) %7;
	return daycode;
}


int determineleapyear(int year)
{
	if((year%4 == false && year%100 != false) || (year%400 == false))
	{
		days_in_month[2] = 29;
		return true;
	}
	else
	{
		days_in_month[2] = 28;
		return false;
	}
}

void calendar(int year, int daycode)
{
	int month, day;
	for ( month = 1; month <= 12; month++ )
	{
		printf("%s", months[month]);
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );

		// Correct the position for the first date
		for ( day = 1; day <= 1 + daycode * 5; day++ )
		{
			printf(" ");
		}

		// Print all the dates for one month
		for ( day = 1; day <= days_in_month[month]; day++ )
		{
			printf("%2d", day );

			// Is day before Sat? Else start next line Sun.
			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}
			// Set position for next month
			daycode = ( daycode + days_in_month[month] ) % 7;
	}
}

void unixEnd(int year)
{
	if(year == 2038)
	{
		printf("\n\n19 January at this year\nAll the 32-bit system in the world\nARE DEAD\n");
		printf("Go get a new 64-bit computer now if reaching this date\nLOL XD");
	}
}
