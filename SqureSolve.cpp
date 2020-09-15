#include<iostream>
#include <stdio.h>
#include <math.h>

const int INF_SOL = 3;

//-----------------------------------------------------------------------------

int SqEquation(double a, double b, double c, double* x1, double* x2);
int ZeroCheck(double x);
int ZeroCheckTest();

//------------------------------------------------------------------------------
int main()
{
	printf("# Square equation solver v2\n"
		" #(c) Panshin 2020\n\n");
	ZeroCheckTest();

	printf("# Enter coefficients, please\n");

	double a = 0, b = 0, c = 0;

	printf("a=");
	scanf_s("%lg", &a);

	printf("\nb=");
	scanf_s("%lg", &b);

	printf("\nc=");
	scanf_s("%lg", &c);

	printf("\n");

	double x1 = 0, x2 = 0;

	int nSol;
	nSol = SqEquation(a, b, c, &x1, &x2);
	switch (nSol)
	{
	case 0:       printf("No roots\n");
		break;
	case 1:	   printf("x= %lg\n", x1);
		break;
	case 2:       printf("x1 = %lg\nx2 = %lg\n", x1, x2);
		break;
	case INF_SOL: printf("Any number");
		break;
	default:      printf("main(): ERROR: nSol = %d\n", nSol);
		return 1;

	}
}


//-----------------------------------------------------------------------------


int SqEquation(double a, double b, double c, double* x1, double* x2)
{
	if (ZeroCheck(a) == 0)
	{
		if (ZeroCheck(b) == 0)
		{
			return (ZeroCheck(c) == 0) ? INF_SOL : 0;
		}
		else
		{
			*x1 = (-c / b);
			return 1;
		}
	}
	else
	{
		double D = b * b - 4 * a * c;
		if (ZeroCheck(D) == 0)
		{
			*x1 = *x2 = (-b) / (2 * a);
			return 1;
		}
		else
		{
			if (D >= 1e-6)
			{
				double sqrt_D = sqrt(D);
				*x1 = (-b - sqrt_D) / (2 * a);
				*x2 = (-b + sqrt_D) / (2 * a);
				return 2;
			}
			else return 0;



		}
	}

}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int ZeroCheck(double x)
{
	if (fabs(x) < 1e-6) return 0;
	else return 1;
}

//------------------------------------------------------------------------------
int ZeroCheckTest()
{
	if (ZeroCheck(1e-6) == 1) printf("Test ZeroCheck: status ok\n");
	else                      printf("Test Zerocheck: status BAD: expected 1 but it gives %i\n", ZeroCheck(1e-6));
	return 0;
}
