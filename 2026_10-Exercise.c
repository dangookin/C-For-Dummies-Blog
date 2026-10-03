#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int hour,minute,h_angle,m_angle,degrees;

	/* gather input */
	printf("Enter the hour: ");
	scanf("%d",&hour);
	printf("Enter the minute: ");
	scanf("%d",&minute);

	/* confirm input */
	if( hour<1 || hour>12 )
	{
		printf("Invalid hour: %d\n",hour);
		exit(1);
	}
	if( minute<0 || minute>59 )
	{
		printf("Invalid minute: %d\n",minute);
		exit(1);
	}

	/* calculate angle */
	h_angle = hour * (360/12);		/* 12 hours on the clock */
	m_angle = minute * (360/60);	/* 60 minutes on the clock */
	if( hour > minute )
		degrees = abs(m_angle-h_angle);
	else
		degrees = abs(h_angle-m_angle);
	/* ensure that the smallest angle is set */
	degrees = 360-degrees < degrees ? 360-degrees : degrees;
	
	/* inform user */
	printf("The angle for %d:%02d is %d degrees\n",
			hour,minute,degrees);

	return 0;
}
