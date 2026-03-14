#include <stdio.h>
 
int main(){
    double salary1, salary2, large_salary, small_salary;
  printf("Enter the salary1:");
  scanf("%lf",&salary1);
  printf("Enter the salary2:");
  scanf("%lf",&salary2);
  if (salary1>salary2)
  {
    large_salary=salary1;
  }
  else{
    small_salary=salary1;
  }
    if (salary1<salary2)
  {
    large_salary=salary2;
  }
  else{
    small_salary=salary2;
  }
  double mortgage = large_salary * 3;     
    mortgage += small_salary; 
     
    
    printf("The maximum size of mortgage is: 1 %.2lf \n", mortgage); 
return 0;
}