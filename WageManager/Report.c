#include <dirent.h>
#include <stdio.h>
//#include "Create/Customer.c"
//#include "Create/Format.c"
//#include "Create/Format.c"
int Reports(){
int choice=0;
printf("\n[1] Customer List");
printf("\n[2] Product List");

printf("\nSelect Report To Print: ");
scanf("%d", &choice);

switch (choice){
    case 1:
      CustomerList();
      break;
    case 2:
        ProductList();
        break;
    default:
        printf("\nInvalid Choice");
}

}

void ListProduct(){

}

void CoustomerInvoiceList(){

printf("Customer Name:");

Border(12, '=');
printf("Product ID");

printf("Product Name");

printf("Product Qty");


}

void CustomerList(){
  Customer Cus ;

Title("Customers", '-', 50, 0, c);
printf("\n");

  DIR *d;
  struct dirent *dir;
  d = opendir("./Database/Customer/");
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      dir->d_name[strlen(dir->d_name)-4] = '\0';
      strcpy(Cus.Contact, dir->d_name);
      if (CustomerExist(&Cus) == 1){
       GetCustomeData(&Cus);
       printf("Customer Name: %s\n", Cus.Name);
       printf("Customer Contact: %s\n", Cus.Name);
       printf("Customer Email: %s", Cus.Name);
       Border(50,'-');
       printf("\n");}
    }
    closedir(d);
  }

}

void ProductList(){
  ProductInInvo Pro ;

Title("Product", '-', 50, 0, c);
printf("\n");

  DIR *d;
  struct dirent *dir;
  d = opendir("./Database/Product/");
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      dir->d_name[strlen(dir->d_name)-4] = '\0';
      strcpy(Pro.ProId, dir->d_name);
      if (ProductExist(&Pro) == 1){
       GetProductData(&Pro);
       printf("Product ID: %s\n", Pro.ProId);
       printf("Product Name: %s\n", Pro.ProName);
       printf("Product Price: %0.2f \n", Pro.Price);
       //printf("Customer Email: %s\n", Cus.Name);
       Border(50,'-');
       printf("\n");}
    }
    closedir(d);
  }

}
