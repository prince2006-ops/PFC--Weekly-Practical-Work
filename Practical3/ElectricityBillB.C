#include <stdio.h>

int main() {
    int numCustomers;
    int customerId, units;
    float charge, totalAmount, surcharge;
    float grandTotal = 0;
    int totalUnits = 0;
    
  
    do {
        printf("Enter number of customers to process (1-10): ");
        scanf("%d", &numCustomers);
        
        if (numCustomers < 1 || numCustomers > 10) {
            printf("Invalid input! Please enter a number between 1 and 10.\n\n");
        }
    } while (numCustomers < 1 || numCustomers > 10);

    

    for (int i = 1; i <= numCustomers; i++) {
        printf("Customer #%d\n", i);
        printf("------------\n");
        
        // Get and validate customer ID
        do {
            printf("Enter Customer ID: ");
            scanf("%d", &customerId);
            
            if (customerId <= 0) {
                printf("Invalid ID! Customer ID must be positive.\n");
            }
        } while (customerId <= 0);
        
        // Get and validate units consumed
        do {
            printf("Enter Units Consumed: ");
            scanf("%d", &units);
            
            if (units < 0) {
                printf("Invalid input! Units cannot be negative.\n");
            }
        } while (units < 0);
        
        
        if (units <= 100) {
            charge = units * 0.50;
        }
        else if (units <= 300) {
            charge = 100 * 0.50 + (units - 100) * 0.75;
        }
        else {
            charge = 100 * 0.50 + 200 * 0.75 + (units - 300) * 1.20;
        }
        
        
        if (charge > 500) {
            surcharge = charge * 0.20;
        } else {
            surcharge = 0;
        }
        
        totalAmount = charge + surcharge;
        
        
        printf("\n--- Bill Summary ---\n");
        printf("Customer ID: %d\n", customerId);
        printf("Units Consumed: %d\n", units);
        printf("Base Charge: Rs. %.2f\n", charge);
        
        if (surcharge > 0) {
            printf("Surcharge (20%%): Rs. %.2f\n", surcharge);
        }
        
        printf("Total Amount: Rs. %.2f\n", totalAmount);
        printf("-------------------\n\n");
        
        // Update totals
        totalUnits += units;
        grandTotal += totalAmount;
    }
    
   
    printf("Total Customers Processed: %d\n", numCustomers);
    printf("Total Units Consumed: %d\n", totalUnits);
    printf("Average Units per Customer: %.2f\n", (float)totalUnits / numCustomers);
    printf("Total Revenue: Rs. %.2f\n", grandTotal);
    printf("Average Bill Amount: Rs. %.2f\n", grandTotal / numCustomers);
   
    return 0;
}