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
	
	if(param==4)
	{
		d=control;
	}
	
	f = d;
	
	if(param==5)
	{
		e=control;
	}
	
	// gate2
	p = d*e;
	
	if(param==13)
	{
		p=control;
	}
	
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
	
	if(param==14)
	{
		q=control;
	}
	
	// gate8
	k = ( (q+c)>0 )?0:1;
	
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
	
	// gate9
	*y = (k+a>0)?1:0;
	// gate10
	*z = w*x;
	
	
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

int main()
{
	FILE *tb_file;
	char buffer[8];
	tb_file = fopen("testcases_exhaustive.txt", "r");
	int o1, o2, v1, v2;
	int in1, in2, in3, in4, in5;
	
	// iterating over test cases
	for(int i=0; i<32; i++)
	{	
		fscanf(tb_file, "%s", buffer);
		in1 = buffer[0]-48;
		in2 = buffer[1]-48;
		in3 = buffer[2]-48;
		in4 = buffer[3]-48;
		in5 = buffer[4]-48;
		
		printf("\nTestcase: %d\n", i+1);
		
		// iterating over nodes
		for(int node=1; node<=16; node++)
		{
			// check for s-a-0 and s-a-1
			for(int stuck=0; stuck<=1; stuck++)
			{
				logic2(node, stuck, in1, in2, in3, in4, in5, &o1, &o2);
				logic2(0, stuck, in1, in2, in3, in4, in5, &v1, &v2);
				
				if( (o1!=v1)||(o2!=v2) )
				{
					printf("node: %d s-a-%d, ", node, stuck);
				}
				
			}
			
		}
		
	}
	
	
	
	return 0;
}
	