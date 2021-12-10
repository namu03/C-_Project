#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void create();
void display();
void search();
void del();
void transaction();
void setpass();
void changepass();
int n;
int i,j,ch;
struct Customer
{
	int custid,ncustid;
	char cname[10];
	char mobno[10];
	char pass1[4],pass2[4];
	char opass[4],npass[4];


}cust[10];
struct Account
{
	int accno;
	char acctype[10];
	float accbal;
}a[10];
void setpass()
{
	int sid,cnt=0,cnt2=0;
	printf("\n\tEnter Customer id ::  ");
	scanf("%d",&sid);
	for(i=0;i<n;i++)
	{
		if(cust[i].custid==sid)
		{
	
			printf("\n\tID FOUND");
			for(j=0;j<3;j++)
			{
	    		printf("\n\tset ur 4 digit pin\t\t:");
				scanf("%d",&cust[i].pass1);
				printf("\n\tReEnter ur 4 digit pin\t\t:");
				scanf("%d",&cust[i].pass2);
				i=strcmp(cust[i].pass1,cust[i].pass2);
				if(i==0)
				{
					printf("\n\tPASSWORD SET SUCCESSFULLY");
					cnt2++;
					break;
				}
				else
				{
					printf("\n\tPASSWORD DOESN'T MATCH");
					printf("\n\tReEnter UR Password");
				}
				
			}
			break;	
		}
		else
		{
			cnt++;
		}
		
	}
	if(cnt=n-1)
	{
		if(cnt2==1)
		{
			printf("\n");
		}
		else
		{
			printf("\n\tINVALID ID.");

		}

	}
	else
	{
		printf("\n");

	}
	
}  
void changepass()
{
	int sid,m;
	printf("\n\tEnter Customer Id ::  ");
	scanf("%d",&sid);
	for(i=0;i<n;i++)
	{
		if(cust[i].custid==sid)
		{
	
			printf("\n\tID FOUND\n");
			for(j=0;j<3;j++)
			{
	    		printf("\n\tEnter Your  4 digit pin\t\t:");
				scanf("%d",&cust[i].opass);
				m=strcmp(cust[i].pass1,cust[i].opass);
				if(i==0)
				{
					printf("\n\tNew pass");
					scanf("%s",cust[i].npass);
					strcpy(cust[i].pass1,cust[i].npass);
					printf("\n\tPASSWORD  CHANGED SUCCESSFULLY");
					break;
				}
				else
				{
					printf("\n\tPASSWORD DOESN'T MATCH");
					printf("\n\tReEnter UR Password");
				}
				
			}
			break;	
		}
		else
		{
			printf("\n\tINVALID ID.");
		}
	}
}
void search()
{
	int sid,i,cnt=0;
	printf("\n\tEnter Customer Id to search \t::");
	scanf("%d",&sid);
 	for(i=0;i<n;i++)
	{
		if(cust[i].custid==sid)
		{
			printf("\n\tID FOUND");
			printf("\n...........................................................................................................");
			printf("\n\tCUSTOMER ID\tNAME\tACCOUNT TYPE\tACCOUNT NO\tACCOUNT BALANCE\t\tCUSTOMER MOBNO");
			printf("\n\t...........................................................................................................");
			printf("\n\t%d\t\t%s\t%s\t\t%d\t\t%.2f\t\t\t%s",cust[i].custid,cust[i].cname,a[i].acctype,a[i].accno,a[i].accbal,cust[i].mobno);
			printf("\n...........................................................................................................");
		}
		else
		{
			cnt++;
		}
	}
	if(cnt==n-1)
	{
		printf("\n");
	}
	else
	{
		printf("\n\tID NOT FOUND\n");

	}
}
void transaction()
{
	
  	int sid,l,cnt=0;
  	char j[4];
  	float amt=0;
	printf("\n\tEnter Customer Id to transaction");
	scanf("%d",&sid);
 	for(i=0;i<n;i++)
	{
		if(cust[i].custid==sid)
		{
			printf("\n\tID FOUND\n");
	     	printf("\n\tEnter your 4 digit pin\t\t:: ");
	     	scanf("%d",j);
	     	l=strcmp(cust[i].pass1,j);
		 	if(l==0)
	     	{
				printf("\n\tEnter\n\t1\t-\tWithdrawal\t::\n\t2\t-\tDeposit\t:: \t");
		     	scanf("%d",&ch);
		     	if(ch==1)
		    	{
		    		
		    		printf("\n\tEnter Withdrawal Amount : ");
		    		scanf("%f",&amt);
	
		    		a[i].accbal=a[i].accbal-amt;
		    		printf("\n\t%.2f amount has been withdrawn",amt);
		    	}
				else if(ch==2)
				{
				    printf("\n\tEnter Deposit Amount : ");
		    		scanf("%f",&amt);
		    		a[i].accbal=a[i].accbal+amt;
		    		printf("\n\t%.2f Amount has been deposited",amt);	
				}
				else
				{
					printf("\n\tInvalid Choice..");
				}					
			}
			else
			{
				printf("\n\tYOU HAVE ENTERED WRONG PIN\n\tTRY AGAIN.");
			}
	
		}
		else
		{
			cnt++;
		}
	}
	if(cnt==n-1)
	{
		printf("\n");
	}
	else
	{
		printf("\n\tID NOT FOUND\n");

	}
	
}

void create()
{
	
	printf("\n\tHow many Customer Account u want to register : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n.........................................");
		printf("\n\tEnter Customer Id\t:\t ");
		scanf("%d",&cust[i].custid);
		printf("\n\tEnter  Customer  Name\t:\t");
		scanf("%s",&cust[i].cname);
		printf("\n\tEnter Customer  Account Type SAVING oR CURRENT\t:\t");
		scanf("%s",&a[i].acctype);
		printf("\n\tEnter Account NO\t:\t");
		scanf("%d",&a[i].accno);
		printf("\n\tEnter Account Balance\t:\t");
		scanf("%f",&a[i].accbal);
		printf("\n\tEnter Customer Mobile No.\t:\t");
		scanf("%s",&cust[i].mobno);
	}

}

void display()
{
	printf("\n---------------------------------------------------------------------------------------------------------------");
	printf("\n\tCUSTOMER ID\tNAME\tACCOUNT TYPE\tACCOUNT NO\tACCOUNT BALANCE\t\tCUSTOMER MOBNO");
	printf("\n---------------------------------------------------------------------------------------------------------------");

	for(i=0;i<n;i++)
	{
		printf("\n\t%d\t\t%s\t%s\t\t%d\t\t%.2f\t\t\t%s",cust[i].custid,cust[i].cname,a[i].acctype,a[i].accno,a[i].accbal,cust[i].mobno);
    	printf("\n...........................................................................................................");

	}
	printf("\n---------------------------------------------------------------------------------------------------------------");

}
void del()
{
	int sid,i,j,cnt=0;
	printf("\n\tEnter Customer Id to Delete  : ");
	scanf("%d",&sid);
 	for(i=0;i<n;i++)
	{
		if(cust[i].custid==sid)
		{
			printf("\n\tID FOUND");//confirm delete
			printf("\n........................................................................");
			for(j=i;j<n-1;j++)
			{
				cust[j].custid=cust[j+1].custid;		
		    	strcpy(cust[j].cname,cust[j+1].cname);
				strcpy(a[j].acctype,a[j+1].acctype);
				a[j].accno=a[j+1].accno;
				a[j].accbal=a[j+1].accbal;
				strcpy(cust[j].mobno,cust[j+1].mobno);		
			}
			printf("\n\tID deleted");
			
			cnt++;
			break;
		}
	}
	if(cnt==1)
	{
		n--;
		printf("\n");
	}
	else
	{
		printf("\n\tID NOT FOUND\n");

	}
	
}
int main()
{
	int c;
	printf("\n`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`");
	printf("\n\t\t\t\t\tWELCOME\t\t\t\t\t\t\t\t\t\t");
	printf("\n`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`");
	do
	{
	    printf("\n\t1\t-\tCreate Account\n\t2\t-\tSet Password\n\t3\t-\tDisplay Account\n\t4\t-\tSearch Account\n\t5\t-\tDelete Account\n\t6\t-\tTransaction\n\t7\t-\tChange Password\n");
	    printf("\n\tEnter your Choice....");
    	scanf("%d",&ch);
    	
		switch(ch)
		{
		    case 1:
		      create();
		      break;
			case 2:	
				setpass();
			   break;
			case 3:
			    display();
				break;
			case 4:
				search();
				break;
			case 5:
				del();
				break;
			case 6:
				transaction();
				break;
			case 7:
			    changepass();
				break;
			default:
				printf("\n\tINVALID COICE");
		}
		printf("\n\tDo you Want to continue press 1");
		scanf("%d",&c);	
	}while(c==1);
	printf("\n\n**********************\t\tTHANK YOU FOR CHOOSING US\t***************************");
	printf("\n<<<<<<<<<<<<<<<<<<<<<<<<\t    CREATING FUTURES\t   >>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	return 0;
}
