#include <string.h>

enum alligment{l, c, r};

void Border(int length,char c){
while(length--){
    printf("%c", c);
}
printf("\n");

}

void Margin(int lenght){
while (lenght--){
    printf(" ");
}

}


void Title(char title[], char style, int stylen, int Bmargine, enum alligment side ){
Margin(Bmargine);
Border(stylen, style);

if (side == r && ((stylen + Bmargine) - strlen(title)) >0){
 Margin((stylen + Bmargine) - strlen(title));
 printf("%s", title);

} else if(side == c){
Margin(Bmargine+ (stylen - strlen(title))/2);
printf("%s", title);
} else {
Margin(Bmargine);
printf("%s", title);
}

printf("\n");
Margin(Bmargine);
Border(stylen, style);
}



