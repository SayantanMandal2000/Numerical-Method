#include<stdio.h>
double f(float x,float y)
{
	return ((x*y)+(y*y));
}
void RK4(float x0, float y0, float x,float h)
{
	float y=y0,k1,k2,k3,k4;
	int i,n=0;
	n=(int)((x-x0)/h);
	for(i=1;i<=n;i++)
	{
		k1=h*f(x0,y);
		k2=h*f(x0+h/2,y+k1/2);
		k3=h*f(x0+h/2,y+k2/2);
		k4=h*f(x0+h,y+k3);
		y=y+(1.0/6.0)*(k1+2*k2+2*k3+k4);
		x0=x0+h;
	}
	printf("\n For h=%f,\n\ty(%f)=%f",h,x,y);
}
int main()
{
	float x0,y0,x,h;
	printf("---RK-4 Method---");
	printf("\n x0=");
	scanf("%f",&x0);
	printf("\n y0=");
	scanf("%f",&y0);
	printf("\n x1=");
	scanf("%f",&x);
	printf("\n h=");
	scanf("%f",&h);
	RK4(x0,y0,x,h);
	return 0;
}

