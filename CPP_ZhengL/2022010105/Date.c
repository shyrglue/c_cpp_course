#include <stdio.h>
#include <iso646.h>

typedef struct date{
	int year;
	int month;
	int day;
} DATE;

static int mon_d[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isleap(int year)
{
	if (year % 4 == 0 and year % 100 != 0)
		return 1;
	else if (year % 400 == 0)
		return 1;
	else
		return 0;
}

int cal_mon(int mon1, int day1, int mon2, int day2, int ex)
{
	int bmon, lmon, bday, lday, sum = 0, i;
	if (mon1 > mon2){
		bmon = mon1; bday = day1;}
	else if (mon1 < mon2){
		bmon = mon2; bday = day2;}
	else{
		bday = (day1 > day2) ? day1 : day2; bmon = mon1;}
	lmon = mon1 + mon2 - bmon;
	lday = day1 + day2 - bday;
	for (i = lmon; i < bmon; i++)
	{
		if (i == 2)
			sum += mon_d[1] + ex;
		else
			sum += mon_d[i - 1];
	}
	return sum + bday - lday;
}

int cal_year(int year1, int year2)
{
	int i, myear, lyear, res = 0;
	myear = (year1 > year2) ? year1 : year2;
	lyear = year1 + year2 - myear;
	for (i = lyear; i < myear; i++)
	{
		if (isleap(i))
			res += 366;
		else
			res += 365;
	}
	return res;
}

void cal(DATE maxd, DATE mind, int *res)
{
	*res += cal_year(maxd.year, mind.year);
	*res = *res + cal_mon(maxd.month, maxd.day, 1, 1, isleap(maxd.year)) - cal_mon(mind.month, mind.day, 1, 1, isleap(mind.year));
}

void main()
{
	DATE date1, date2, maxd, mind;
	int res = 0;
	scanf("%d %d %d", &date1.year, &date1.month, &date1.day);
	scanf("%d %d %d", &date2.year, &date2.month, &date2.day);
	if (date1.year > date2.year){
		maxd = date1; mind = date2;
		cal(maxd, mind, &res);
	}
	else if (date1.year < date2.year){
		maxd = date2; mind = date1;
		cal(maxd, mind, &res);
	}
	else
		res = cal_mon(date1.month, date1.day, date2.month, date2.day, isleap(date1.year));
	printf("%d", res);
}