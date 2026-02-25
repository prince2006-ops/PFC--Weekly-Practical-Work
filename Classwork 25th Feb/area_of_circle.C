#include<stdio.h>

int main(){
    float radius;
    const float PI = 3.14159265;  // Moved PI declaration outside the if block
    
    printf("Enter the radius: ");
    if(scanf("%f", &radius) != 1){
        printf("Invalid input\n");
        return 1;
    }
    
    if (radius >= 0){
        printf("Area is computable.\n");
        float area = PI * radius * radius;  // Calculate area before printing
        printf("Area of the circle = %.4f\n", area);
    }
    else{
        printf("Radius cannot be negative.\n");  // Fixed: used double quotes, not single quotes
        return 1;
    }
    
    return 0;  // Added successful termination
}