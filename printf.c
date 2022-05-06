#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

//creat a function for converting any given number in a given base
char * BaseConvert(int number, int base){
    char set[]="0123456789ABCDEF";
    char buffer[100];
    char * result;
    result=&buffer[99];
    *result= '\0';

    do{
        *--result= set [number % base];
        number/=base;
    }while(number!=0);
    return result;
}

//rewrite the string copy function
char* my_strcpy(char* destination, char* source){
    int index;
    for(index=0;index<strlen(source);index++){
        destination[index]=source[index];
    }
    return destination;
}


//creat a function to manege the various flags
int my_printf(char * format,...){
    //initialise varaidic funtion argument 7
    va_list value;

    int index_1=0,index_2=0;
    int num;
    char * args;
    char buffer[100]={0};

    //start iteration on variadic function argument
    va_start(value,format);

    while(format && format[index_1]){
        if(format[index_1]=='%'){
            index_1++;

            //get and process flags
            switch(format[index_1]){
                //getting character
                case 'c' :
                    buffer[index_2]=(char)va_arg(value, int);
                    index_2++;
                    break;
                    //gtting string
                case 's' :
                    args=va_arg(value, char*);
                    my_strcpy(&buffer[index_2],args);
                    index_2+=strlen(args);
                    break;
                    //getting decimal
                case 'd' :
                    num=va_arg(value, int );
                    //incase of negative number
                    if(num<0){
                        num=-num;
                        buffer[index_2]='-';
                        index_2++;
                    }
                    my_strcpy(&buffer[index_2],BaseConvert(num,10));
                    index_2+=strlen(BaseConvert(num,10));
                    break;
                    //getting unsigned octal
                case 'o' :
                    num=va_arg(value, unsigned int);
                    my_strcpy(&buffer[index_2],BaseConvert(num,8));
                    index_2+=strlen(BaseConvert(num, 8));
                    break;
                    //getting unsigned hexadecimal
                case 'x' :
                    num=va_arg(value, unsigned int );
                    my_strcpy(&buffer[index_2],BaseConvert(num,16));
                    index_2+=strlen(BaseConvert(num,16));
                    break;
                    //getting unsigned decimal
                case 'u' :
                    num=va_arg(value, unsigned int);
                    my_strcpy(&buffer[index_2],BaseConvert(num, 10));
                    index_2+=strlen(BaseConvert(num,10));
                    break;
                    //getting pointer
                case 'p' :
                    args=va_arg(value, char*);
                    my_strcpy(&buffer[index_2],args);
                    index_2+=strlen(args);
                    break;
                case '%' :
                    buffer[index_2]='%';
                    index_2++;
            }
        }
        else {
            buffer[index_2]=format[index_1];
            index_2++;
        }
        index_1++;
    } 
    //print the result in standard output
    fwrite(buffer,index_2,1,stdout);
    //stop the iteration over variadic function arguments
    va_end(value);

}


