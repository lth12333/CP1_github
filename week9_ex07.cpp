#include<stdio.h>

enum days{SUN, MON, TUE, WED, THU, FRI, SAT};

char days_name[][10] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};

int main(void) {
	enum days d;
	d = WED;
	printf("%d��° ������ %s�Դϴ�.\n", d, days_name[d]);
	return 0;
}