#include <stdio.h>
/*Check digit computation[edit]
See also: Luhn algorithm
The last number of the IMEI is a check digit calculated using the Luhn algorithm, as defined in the IMEI Allocation and Approval Guidelines:

The Check Digit shall be calculated according to Luhn formula (ISO/IEC 7812). (See GSM 02.16 / 3GPP 22.016). The Check Digit is a function of all other digits in the IMEI. The Software Version Number (SVN) of a mobile is not included in the calculation.

The purpose of the Check Digit is to help guard against the possibility of incorrect entries to the CEIR and EIR equipment.

The presentation of the Check Digit both electronically and in printed form on the label and packaging is very important. Logistics (using bar-code reader) and EIR/CEIR administration cannot use the Check Digit unless it is printed outside of the packaging, and on the ME IMEI/Type Accreditation label.

The check digit is not transmitted over the radio interface, nor is it stored in the EIR database at any point. Therefore, all references to the last three or six digits of an IMEI refer to the actual IMEI number, to which the check digit does not belong.

The check digit is validated in three steps:

Starting from the right, double every other digit (e.g., 7 → 14).
Sum the digits (e.g., 14 → 1 + 4).
Check if the sum is divisible by 10.
Conversely, one can calculate the IMEI by choosing the check digit that would give a sum divisible by 10. For the example IMEI 49015420323751?,

IMEI	4	9	0	1	5	4	2	0	3	2	3	7	5	1	 ?
Double every other	4	18	0	2	5	8	2	0	3	4	3	14	5	2	8
Sum digits	4 + (1 + 8) + 0 + 2 + 5 + 8 + 2 + 0 + 3 + 4 + 3 + (1 + 4) + 5 + 2 + ? = 52 + ?
To make the sum divisible by 10, we set ? = 8, so the IMEI is 490154203237518

*/
void main()
{
 long int imei,sum=0,x,y,i,t;
printf("enter first 14 diits to find the check digit\n");
scanf("%ld",&imei);
printf("\n%ld are entered first 14 digits of imei\n",imei);
x=imei;
for( i=1;i<=14;i++)
{
y=x%10;
y=x/10;
if((i%2)==0)
  y=2*y;
if(y==10)
 sum=sum+1;
if(y<10)
 sum=sum+y;
if(y>10)
{
 t=y%10;
sum=sum+t;
t=y/10;
t=y/10;
sum=sum+t;
}
}
if((sum%10)==0)
  printf("\nyour imei will be  %ld0\n",imei);
else
  printf("\nyour imei will be %ld%ld\n",imei,10-(sum%10));
}




/*testing*/
