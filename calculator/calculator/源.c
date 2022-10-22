#include <stdio.h>

int main()
{
	int n1 = 0, n2 = 0;
	char op = 0, i = 0, emp = 10;
	double result = 0;
	
	do {
		scanf("%d %c %d", &n1, &op, &n2);
		scanf("%c", &emp);
		
		if (emp != '\n') {
			printf("error\n");
			while (getchar() != '\n') { getchar(); };
			scanf("%c", &i);
			continue;
		}
		
		switch (op) {
		case '+': 
			result = 1.0*n1 + 1.0*n2;
			printf("%.2lf %c %.2lf = %.2lf\n", (double)n1, op, (double)n2, result);
			break;
		case '-': 
			result = n1 - n2;
			printf("%.2lf %c %.2lf = %.2lf\n", (double)n1, op, (double)n2, result);
			break;
		case '*':
			result = n1 * n2;
			printf("%.2lf %c %.2lf = %.2lf\n", (double)n1, op, (double)n2, result);
			break;
		case '/': 
			if (n2 == 0) {printf("error\n"); scanf("%c", &i); continue;}
			result = 1.0*n1 / n2;
			printf("%.2lf %c %.2lf = %.2lf\n", (double)n1, op, (double)n2, result);
			break;
		default:printf("error\n");
			while (getchar() != '\n') { getchar(); };
			scanf("%c", &i);
			continue;
		}
		scanf("%c", &i);
		
	} while (i == 'y' || i == 'Y');

	return 0;

}
