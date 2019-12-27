#include<stdio.h>
int mul(int a, int b);
int main()
{
  int num1, num2;
  printf("Enter first number: \n");
  scanf("%d",&num1);
  printf("Enter second number: \n");
  scanf("%d",&num2);
  mul(num1,num2);
  return 0;
}
int mul(int x, int y)
{
 int z = x*y;
 printf("Mul is : %d\n",z);
}
