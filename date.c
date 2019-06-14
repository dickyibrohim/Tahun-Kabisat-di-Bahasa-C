#include <stdio.h>
#include <time.h>

int IsLeapYear(const int year) {
	return ((year%400==0) || (year%4==0 && year%100!=0));
}


int GetDaysInMonth (const int year, const int month) {
	switch (month) {
		case 2: return IsLeapYear(year) ? 29 : 28;
		case 4:
		case 6:
		case 9:
		case 11: return 30;
		default: return 31;
	}   
}


int FirstDayOfMonth(const int year, const int month) {
	// 0 = Sunday
	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	int y = year - (month < 3);
	return (y + y/4 - y/100 + y/400 + t[month-1] + 1) % 7;
}


void ShowCal(const int year, const int month) {
	static char *monthName[] = {"January","February","March","April","May","June","July",
	"August","September","October","November","December"};
	int day, days, dow;
	
	days = GetDaysInMonth(year, month);
	dow = FirstDayOfMonth(year, month);

	printf("%s %d\n", monthName[month-1], year);
	printf(" Sun Mon Tue Wed Thu Fri Sat\n");
	printf(" --- --- --- --- --- --- ---\n ");
	for(day=0; day<dow; day++) { printf("    "); }
	for(day=1; day<=days; day++) {
		printf("%3d ", day);
		if (++dow>6) { dow = 0; printf("\n "); }
	}
	printf("\n");
}

int main(int argc, char** argv) {
	// test on today
	time_t curtime = time(NULL);
	struct tm *loctime = localtime(&curtime);
	ShowCal((loctime->tm_year + 1900), (loctime->tm_mon + 1));

    getche();
	return 0;
}

