#include <stdio.h>
#include "Create/Loginsys.c"

int main(){
char User[25];
char Pass[25];

printf("Enetr User:");
scanf("%s", User);
printf("Enetr Password:");
scanf("%s", Pass);

//createUser(User, Pass);
printf("%d", checkUser(User));
}
