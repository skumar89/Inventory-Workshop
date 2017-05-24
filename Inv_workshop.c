#include<stdio.h>

//Define constant
#define MAXITEMS 100

//Function prototypes
float calculateTotalValue(float price[], int quantity[],int numItems);

int main(){
        //Declare variables
        long long barcode[MAXITEMS];
        float price[MAXITEMS];
        int quantity[MAXITEMS];
        int numItems = 0;
        float totalValue;
        int i;

        printf("Grocery Store Inventory\n");
        printf("=======================\n");

        do{
                //Get barcode
                printf("Barcode  :  ");
                scanf("%lld",&barcode[numItems]);
                //Get price and quantity if barcode isn't 0
                if(barcode[numItems]){
                        printf("Price    :  ");
                        scanf("%f",&price[numItems]);
                        printf("Quantity :  ");
                        scanf("%d",&quantity[numItems]);
                }
                numItems++;
        }while(barcode[numItems-1]); //exit when 0 is entered for the barcode

        //Calculate the totalValue using the function calculateTotalValue
        totalValue = calculateTotalValue(price,quantity,numItems-1);

        //Print out table
        printf("            Goods in Stock\n");
        printf("            ==============\n");
        printf("Barcode     Price  Quantity  Value\n");
        printf("----------------------------------\n");
        for(i=0;i<numItems-1;i++){
                printf("%lld  %.2f   %8d  %.2f\n", barcode[i],price[i],quantity[i],price[i]*quantity[i]);
        }
        printf("                             -----\n");
        printf("Total value goods in stock   %.2f\n",totalValue);

        return 0;
}

/*Function that takes an array price, an array quantity, and an integer number of items as
  its arguments and returns a float totalValue which is the value of all the prices multiplied
  by their quantities added together*/
  
float calculateTotalValue(float price[], int quantity[], int numItems){
        int i;
        float totalValue = 0;
        for (i=0;i<numItems;i++){
                totalValue += (price[i] * quantity[i]);
        }
        return totalValue;
}
