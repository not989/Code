#include <stdio.h>
#include <string.h>
int main()
{
   char str[10000];

    long long int year,i,j,len,mod4,mod100,mod400,mod55,mod15,leap,flag,p=0;

    while(scanf("%s", str)!=EOF)
    {
        len=strlen(str);
        mod4=mod100=mod400=mod55=mod15=leap=flag=0;


        for(i=0; i<len; i++)
        {
            mod4=((mod4 * 10) +  str[i] - '0')%4;
            mod100=((mod100 * 10) +  str[i] - '0')%100;
            mod400=((mod400 * 10) +  str[i] - '0')%400;
            mod55=((mod55 * 10) +  str[i] - '0')%55;
            mod15=((mod15 * 10) +  str[i] - '0')%15;
        }

        if(p!=0)printf("\n");

        if(mod4==0 && mod100!=0 || mod4==0 && mod400==0)
        {
            printf("This is leap year.\n");
            leap=1;
            flag=1;
        }

        if(mod15==0)
        {
            flag=1;
            printf("This is huluculu festival year.\n");
        }

        if(mod55==0 && leap==1)
        {
            flag=1;
            printf("This is bulukulu festival year.\n");
        }

        if(flag==0)printf("This is an ordinary year.\n");

        p++;
    }

    return 0;
}
