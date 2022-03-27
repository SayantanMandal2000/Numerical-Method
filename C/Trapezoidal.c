#include<stdio.h>
#include<math.h>
float f(float x)
{
	return (1/(1+(x*x)));
}
int main()
{
	int i;
	float a,b,n,h,s1=0,s2=0,s,y0,yn;
	printf("Enter the upper limit : ");
	scanf("%f",&b);
	printf("Enter the lower limit : ");
	scanf("%f",&a);
	printf("Enter the number of intervals : ");
	scanf("%f",&n);
	h=(b-a)/n;
	y0=f(a+0*h);
	yn=f(a+n*h);
	for(i=1;i<n;i++)
		s1=s1+f(a+i*h);
	s=(h/2)*(y0+yn+2*s1);
	printf("The value of integration=%f",s);
	printf("\nThe value of pi=%f",(4*s));
	return 0;
}


