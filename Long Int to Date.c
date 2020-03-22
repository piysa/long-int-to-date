/*
the following program takes user input as long int and convert to standard date format :
dd, month, yyyy
*/

#include <stdio.h>

int period_conv(long,int *, int *);

int main(void)
{
    long n;
    int year, date, mon;
    char *mon_data[20]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    char *month;
    printf("Please enter the period in long form: ");
    scanf("%ld",&n);        /*15081945 */
    mon=period_conv(n,&year,&date);
    if(mon>12)
    {
        printf("Incorrect Period\nRe-enter Period: ");
        scanf("%ld",&n);
        mon=period_conv(n,&year,&date);
    }
    month=mon_data[mon-1];
    printf("Period Entered: %d,%s,%d\n",date,month,year);
    getchar();
    getchar();
    return 0;
}

int period_conv(long n, int *y, int *d)
{
    int temp, mon;

    *y=n%10000;             /*1945*/
    temp=n/10000;           /*1508*/
    mon=temp%100;           /*08*/
    *d=temp/100;            /*15*/

    return mon;
}