#include <stdio.h>
#include <stdlib.h>
#include <math.h>


using namespace std;
float Current(float I01, float I02, float V, float I, float R);

//float Current2(float I01, float I02, float V, float I, float R);

float Current3(float I01, float I02, float V, float I, float R);



main()

{	

FILE *fp;

if ((fp=fopen("poglin.dat", "w"))==NULL)
    { 
      puts("Cannot open file");
      exit (1);
    } 
 
 
//for (T=280; T<=360; T+=10)
//{
const float I01=2.41e-8, I02=2e-5;
//const float T=295, k=8.625e-5;

float V;
float I,I1;

float a,b,c[5],R;

int j, j0;

 for (V=0.01; V<1; V+=0.01)
{
              
 for (j0=0; j0<5;++j0)
 {
   R=pow(10,j0+1);
   a=0;
   b=Current(I01, I02, V, 0, R);
//   printf("%g\n",b);

//int j=0;

   do
     {
      j++;     
   
      c[j0]=(a+b)/2.0;   
  //    printf("%g %g %g\n",a,b,fabs(b-a));
      if (Current3(I01, I02, V, a, R)*Current3(I01, I02, V, c[j0], R)<=0)
      b=c[j0];
       else a=c[j0];  
    //printf("V=%g I=%g  %g\n", V, c[j0],fabs(b-a));  
     }while (fabs(b-a)>1e-8);
   
 }
   printf("%g ", V); 
   fprintf(fp,"%g ", V); 

  for (j0=0; j0<5;++j0)
    {
    printf("%g ", c[j0]);  
    fprintf(fp,"%g ", c[j0]);  
    }

  printf("\n");  
  fprintf(fp,"\n");  
 
//  fprintf(fp,"%g %g\n", V, c);  
  
 
}
fclose(fp);
 
 
// while (fabs((I-I1)/I)>1e-2);
//}
// printf("%d %g %g\n", T, gam1, gam2);
// fprintf(fp,"%d %g %g\n", T, gam1, gam2);

//  printf("%d %g\n", T, Eg(Eg02,al,bet,T));

//}

 getchar();
//	return 0;
}


float Current(float I01, float I02, float V, float I, float R)
{
const float T=295, k=8.625e-5, n=1.7;
float rez;
rez=I01*(exp((V-I*R)/(n*T*k))-1)+I02*(1-exp(-I*R/k/T));
return rez;
}
/*
float Current2(float I01, float I02, float V, float I, float R)
{
const float T=295, k=8.625e-5, n=1.7;
float rez;
printf("4=%g \n", exp(I01*(exp(V/(n*k*T))*pow(I,R/n)-1)+I02*(1-pow(I,R))));
rez=-1.0/(k*T)*exp(I01*(exp(V/(n*k*T))*pow(I,R/n)-1)+I02*(1-pow(I,R)));
return rez;
}*/

float Current3(float I01, float I02, float V, float I, float R)
{
float rez;
rez=I-Current(I01, I02, V, I, R);
return rez;      
}


