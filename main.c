#include <stdio.h>
int main() {
    unsigned long long temp=0,temp_1,temp_2;
    int d1,d2,d3,d4;
    unsigned long long one=0,two=0,three=0,four=0,step,password_1,password_2,password;
    unsigned long long one2,two2,three2,four2;
    unsigned long long a[5]={0};
    scanf("%lld",&temp);
    scanf("%d%d%d%d",&d1,&d2,&d3,&d4);
    one=temp>>24;
    two=(temp>>16)-(one<<8);
    three=(temp>>8)-(one<<16)-(two<<8);
    four=temp-(one<<24)-(two<<16)-(three<<8);
    a[1]=one;    a[2]=two;    a[3]=three;    a[4]=four;
    one2=a[d1]^a[d2];
    two2=a[d2]&a[d3];
    three2=a[d3]|a[d1];
    four2=~a[d4]+256;
    temp=(one2<<24)+(two2<<16)+(three2<<8)+four2;
    step=d1+d2+d3+d4;
    /****************************** Rotate vs Shift ************************************/
    temp_1=temp>>step;
    temp_2=temp-(temp_1<<step);
    temp=temp_1+(temp_2<<(32-step));
    /****************************** Rotate vs Shift ************************************/
    password_1=temp>>16;
    password_2=temp-(password_1<<16);
    password=password_1^password_2;
    password_1=(password>>16);
    password=password-(password_1<<16);
    printf("%lld",password);
    return 0;
}
