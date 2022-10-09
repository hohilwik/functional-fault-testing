#include <stdio.h>



int logic2( int param, int control, int a, int b, int c, int e, int h, int *y, int *z)
{
	int d, f, g, j, k, w, x, p, q;
	
	if(param==1)
	{
		a=control;
	}
	if(param==2)
	{
		b=control;
	}
	
	if(param==3)
	{
		c=control;
	}
	
	// gate1
	d = (a+b>0)?1:0;
	f=d;
	
	if(param==4)
	{
		d=control;
	}
	if(param==5)
	{
		e=control;
	}
	
	// gate2
	p = d*e;
	
	if(param==6)
	{
		f=control;
	}
	
	// gate3
	g = (p>0)?0:1;
	
	if(param==7)
	{
		g=control;
	}
	if(param==8)
	{
		h=control;
	}
	
	// gate4
	j = (g+h>0)?1:0;
	
	if(param==9)
	{
		j=control;
	}
	
	// gate5
	w = ( (b*j)==0 )? 1:0;
	// gate6
	x = j*g;
	// gate7
	q = (f>0)?0:1;
	// gate8
	k = ( (q+c)>0 )?0:1;
	// gate9
	*y = (k+a>0)?1:0;
	// gate10
	*z = w*x;
	
	if(param==10)
	{
		k=control;
	}
	if(param==11)
	{
		w=control;
	}
	if(param==12)
	{
		x=control;
	}
	if(param==13)
	{
		p=control;
	}
	if(param==14)
	{
		q=control;
	}
	if(param==15)
	{
		*y=control;
	}
	if(param==16)
	{
		*z=control;
	}
	
	return 0;
	
}