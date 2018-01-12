/**
	Md.soharub hossen sajal
	Daffodil international university
	program: Multiply two big integer number
*/

#include<bits/stdc++.h>
using namespace std;
#define max 100000
int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        string s3,s4;
        s3=s1;
        s4=s2;
        stringstream s5,s6;
        int n,m;
        s5<<s3;
        s5>>n;
        s6<<s4;
        s6>>m;
        if(n==0 || m==0)
        {
            cout<<s1<<" * "<<s2<<" = "<<"0"<<endl;
            continue;
        }
        int a[max]= {0},b[max]= {0},c[max]= {0},d[max]= {0},e[max]= {0};
        int I=0,J=0;
        /***************Convert string to integer**************************/
        for(int i=s1.size()-1; i>=0; i--)a[I++]=s1[i]-'0';
        for(int i=s2.size()-1; i>=0; i--)b[J++]=s2[i]-'0';
        /**************Convert string to integer**************************/

        int Ma,Mi;

        /**************Take maximum number and minimum number*************/
        if(s1.size()>=s2.size())
        {
            Ma=s1.size();
            Mi=s2.size();
            for(int i=0; i<s1.size(); i++)d[i]=a[i];
            for(int i=0; i<s2.size(); i++)e[i]=b[i];
        }
        else if(s1.size()<s2.size())
        {
            Mi=s1.size();
            Ma=s2.size();
            for(int i=0; i<s1.size(); i++)e[i]=a[i];
            for(int i=0; i<s2.size(); i++)d[i]=b[i];
        }
        /***************Take maximum number and minimum number*************/

//[[[-------------------------------------------------------------]]]

        /**********************Multiplication part*************************/
        int carry=0,count=0;
        for(int i=0; i<Mi; i++)
        {
            for(int j=0; j<Ma; j++)
            {
                int sum=d[j]*e[i]+carry;
                if((c[i+j]+sum)>9)
                {
                    int cr=c[i+j]+sum;
                    c[i+j]=(c[i+j]+sum)%10;
                    if(!i)carry=sum/10;
                    else carry=(cr)/10;
                    if(j==Ma-1)Ma++;
                }
                else
                {
                    c[i+j]=c[i+j]+sum;
                    carry=sum/10;
                }
                if(i==Mi-1) count++;
            }
        }
        int I2=0;
        cout<<s1<<" * "<<s2<<" = ";
        for(int i=count+Mi-2; i>=0; i--)
        {
            if(!I2 && !c[i])continue;
            else I2=1,cout<<c[i];
        }
        cout<<endl;
        /**********************Multiplication part*************************/
    }
    return 0;
}

/**
	Note:
-------------------------------------------------------
	1. Take maximum number and minimum number:
-------------------------------------------------------

	==> ai khane 3 type er input hote pare (a) 1st number ta boro r 2nd number ta choto (b) 2tai soman (c)  1st er choto r 2nd ta boro..
	jetai hok na keno ami Ma er moddhe maximum value ta rakhbo r Mi te minimum value rakhbo..
	r array d te maximum length er number gula thakbe r e te minimum length er number gula thakbe

	222222
	   x99
	-------
	ai khatre ami Mi  er akta inder er shate Ma er sob gula value gun kore array te store korbo

	gun ta hobe ai rokom  99x
						  222222
						  ---------
						  jok fol

-----------------------------------------------------------
	2. Multiplication part:
-----------------------------------------------------------

	d=999
	e=99
	so.. d[0]=9,d[1]=9,d[2]=9; Ma
		 e[0]=9,e[1]=9; Mi

	Mi er zero inder er jonno Ma er sob gula value gun korbo..

-->63. int sum=d[j]*e[i]+carry; ai khane Mi(i) er proti ta value er jonno Ma(j) proti ta value gun korci

-->64. if((c[i+j]+sum)>9) ai khane c[i+j] bolte i=0,1,2...... r j=0,1,2,..... c[0+1] mane array er c[1] tomo inder niye kaj korci..
	akhon jodi c[i+j] tomo index a j value ache tar shate sum(48 line theke jeta aslo) er value jodi add kori r tader jog fol jodi 9 er chaite boro hoy tahole
	ai condition kaj korbe r choto hole else a chole jabe...
	jodi 50 line er condition ok hoy mane jog fol jodi 10 er besi hoy tahole

-->66. int cr=c[i+j]+sum; er khane cr er vitor a tader jog fol ta rekhe dibo

-->67. c[i+j]=(c[i+j]+sum)%10; suppose ai khane array er c[0+1] tomo inder er moddhe jodi amra value nite chai tokhon c[0+1]=(c[0+1] tomo index a j value ache
	setar shate sum er value jod kore oi jog fol k 10 da mod kore j vag ses pabo seta rakhbo oi array er c[1] tomo index a
	 9
	x9
	----
	so sum=d[j]*e[i]=81; jeta kina 10 er chaite boro... tokhon  c[i+j]=(c[i+j]+sum)%10; line a ese amra 81%10=1 rakhbo c[1]=1 tomo index a

-->68. if(!i)carry=sum/10; jokhon Mi value er 1st index er jonno value amra array te rakhbo tokhon shudu sum k 10 dara vag kore carry ber korbo karon amra ..

	999
	x99
	-----
	8991 <--Mi er 1st index er jonno
    ---()<--Mi er 2nd index er jonno

-->69.else carry=(cr)/10;

    jokhon 2nd loop a jabo tokhon c[2] er index niYe kaj korbo tokhon 1st loop a array  er index er value  r 2nd loop a oi index gular gunfol gula  cr=c[i+j]+sum;
    ai ta te store kore carry ber korbo...

-->70. if(j==Ma-1)Ma++; jodi j er value akdom last index a ase jemon 	 9
																		x9
																	   ----
																		 1 r 8 but loop kintu akbari gurbe tai oi 8 print korar jonno Ma er man r ek barye diye oita
																		 array er moddhe niye nibo

-->77. if(i==Mi-1) count++; i means Minimun value jokhon ses index a chole jabe tokhon oi index joto gula value pabo oi gula hocce amader final result er digit
	ai digit gula count kore print korte hobe

-->82. for(int i=count+Mi-2; i>=0; i--)cout<<c[i];  count er man j vabe pelam

	 999
	x999
    -----
	8991
   8991x
  -------
  8991xx

  ai khane last er line a digit ache 8991=4 ta tai count hobe 4 ta.. r amar aro 2ta print korte hobe... xx mane gun je vabe kore oi vabe korar jonno xx line er
  value gula r chane hobe na r oi gula ami pabo Mi er value jodi 3 hoy tahole loop ghurbe Mi er jonno 3 bar kintu jokhon 3 number loop a asbe tokhon ager ta se
  count korte parbe na karon i tokhon 3-1=2 number index theke kaj kora start korbe... ai oi bad pora gulo print korar jonno Mi theke 1 bad dibo...

  kintu 8991=4 count er man 4 r 8991xx=6 ta digit ache array er index start hobe 6-1=5 theke tai count er man 1 ta komate hobe tai Mi theke sora sori 2 minus
  kore dilam

*/
