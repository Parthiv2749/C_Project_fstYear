#include <stdio.h>
#include "Create/Customer.c"
#include "Create/Format.c"
#include "Create/Product.c"
#include "Create/CustomerInvoice.c"
#include "Create/Loginsys.c"
#include "Report.c"
#include <ctype.h>
#include <time.h>

//"Customer" Structure is already declared in Customer Library File.

int Invoice();
int Product();

int main()
{
char user[50];
char pass[50];
int userTry=0;


while(userTry<3){
printf("\nPlease enter UserName: ");
scanf("%s", user);
printf("Please enter Passowrd: ");
scanf("%s", pass);

    if (checkUser(user) == 1 && checkPassword(user,pass) == 1){
        submain();
    } else if (checkUser(user) == 0 ){
        printf("User Not Found.");

    } else if ( checkPassword(user,pass) == 0){
        printf("Incorrect Password");

    }
    userTry++;
}
}


int submain(){

int Choice;

Welcome:
printf("\n[1] Create New Invoice.\n");
printf("[2] Add Product.\n");
printf("[3] View Reports.\n");
printf("Choice:");
scanf("%d", &Choice);

if (Choice == 1){
Invoice();
goto Welcome;
} else if (Choice == 2){
Product();
goto Welcome;
} else if (Choice == 3){
Reports();
goto Welcome;
}



return 0;

}



int Invoice(){

Customer Cus ;
ProductInInvo P;

char MoreProduct;
char *FilePath;
float Total =0;
time_t current_time = time(NULL);

char date_string[20];
strftime(date_string, 20, "%d-%m-%Y", localtime(&current_time));


printf("Contact: ");
scanf("%s", Cus.Contact);

if (CustomerExist(&Cus) == 1) {

    GetCustomeData(&Cus);
    printf("Name: %s", Cus.Name);


    printf("Email: %s\n", Cus.Email);

}
 else{

fflush(stdin);
printf("Enter Name: ");
gets(Cus.Name);

printf("Enter Email: ");
scanf("%s", Cus.Email);

SaveCust(&Cus);

}





Title("Invoice", '-', 50, 0, c);


printf("Invoice No: %d\n", getInvoiceNum());
printf("Date: %s\n", date_string);
Border(50, '-');
FilePath = createInvoice(getInvoiceNum(), Cus.Contact);

Product:

printf("Product Id: ");
scanf("%s", P.ProId);

ProductExist(P.ProId) ? ({GetProductData(&P);}):({goto NotF;});



printf("Product Name: ");
printf("%s", P.ProName);

printf("Price: ");
printf("%0.2f\n", P.Price);

printf("Qty: ");
scanf("%f", &P.Qty);

Total = Total + P.Qty*P.Price;
printf("Subtotal: ");
printf("%0.2f\n", P.Qty*P.Price);

AddProductToInvoice(FilePath, &P);

Border(50, '-');

printf("Add More Product ? [Y/N]:");
scanf(" %c", &MoreProduct);

Border(50, '-');
MoreProduct = toupper(MoreProduct);
(MoreProduct == 'Y') ? ({goto Product;}): ({printf("Total: %0.2f\n\n", Total); return 0;});

if (0){
NotF:
    printf("Product Not Found\n");
    Border(50, '-');
    goto Product;
}



}

int Product(){
ProductInInvo Product;
char Update;

printf("\nAdd/Update Product.\n\n");
printf("Product ID:");
scanf("%s", Product.ProId);

if (ProductExist(Product.ProId)){
    GetProductData(&Product);
    printf("Previous Details-> \n\n");
    printf("Product Name: %s", Product.ProName);
    printf("Price: %0.2f\n\n", Product.Price);

    printf("Would you like to update[Y/N]:");
    scanf(" %c", &Update);
    Update = toupper(Update);
    if(Update == 'Y') {
            printf("New Product Details->\n\n");
            fflush(stdin);
            printf("Enter Product Name: ");
            gets(Product.ProName);
            printf("Enter Price: ");
            scanf("%f", &Product.Price);

            SaveProduct(&Product);
    } else{
return 0;
    }


} else {
    printf("Add New Product->\n");
    printf("Enter Product Name: ");
    scanf("%s", Product.ProName);
    printf("Enter Price: ");
    scanf("%f", &Product.Price);
}


}






