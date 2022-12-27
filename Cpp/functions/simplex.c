#include <stdio.h>
#include<conio.h>
#include<limits.h>
#include <math.h>
#define CMAX 10             //maximum no of constraints
#define VMAX 10              //maximum no of variables 
int numberofconstraints, numberofvariables, notoptimalsolution , pivot1, pivot2 , X;   // declaring suitable varibales 
double ARRAY[CMAX][VMAX];     //2 dimensional array to store  constraint - coefficients

//double required as later procedure involves fractions 


//Collecting  data

void COLLECTDATA()
 {

double D1,D2;  

char T;// Character to know to whether it is maximize or minimize problem 

int i,j;

printf("\n\n SIMPLE SIMPLEX METHOD\n");

printf("\n\n Maximize (Y/N) ? ");

scanf("%c", &T);   //Type of optimization problem is decided 

printf("\n\n Enter Number  of variables of  the objective function : ");
scanf("%d", &numberofvariables);    //Integer input for no of variables

printf("\n Enter Number  of constraints : "); 
scanf("%d", &numberofconstraints);   //integer input for no of constraints


//Allowing user to enter any case(upper/lower) of letter for yes or no 
if (T == 'Y' || T=='y')
{
D1 = 1.0;
}                   // +  -  
else
{
D1 = -1.0;
}

printf("\n Enter the coefficients of objective function :\n");  //Printing the message to enter coefficienARRAY of the objective function 


//For loop iteration to take coefficients 

for (j = 1; j<=numberofvariables; j++) 

{
printf(" -->%d ", j);  // coefficients number indicator 

scanf("%lf", &D2);     //Inputting the coefficient

ARRAY[1][j+1] = D2 * D1;    //Storing the coefficienARRAY in array intialized first with either positive or negative sign based on Type T

}

printf(" RHS =  ");  //RHS of function if any (else input 0 )
scanf("%lf", &D2);
ARRAY[1][1] = D2 * D1;          

printf("\n Enter the coefficients of corresponding constraint equation :\n"); 

for (i= 1; i<=numberofconstraints; i++) {

printf("\n Constraint number %d:\n", i);//Printing the message to display  the constraint equation number

for (j = 1; j<=numberofvariables; j++) 

{

printf(" -->%d  ", j);
scanf("%lf", &D2);   //Taking input coefficienARRAY of Constraint equations 
ARRAY[i + 1][j + 1] = -D2;

}

printf(" RHS = "); 
scanf("%lf", &ARRAY[i+1][1]);

}


printf("\n\n Final Solution of SIMPLE SIMPLEX Method:\n\n");


for(j=1; j<=numberofvariables; j++) 
{
    ARRAY[0][j+1] = j;      // Assigning equation number
}

for(i=numberofvariables+1; i<=numberofvariables+numberofconstraints; i++)
{
     ARRAY[i-numberofvariables+1][0] = i;
}

}

void Pivot();   //Declaring the function to find the pivot variables 
void FORMULA();  //Main driving code of the procedure 
void OPTIMIZE();  //Function which can OPTIMIZE the solution further

void SIMPLESIMPLEX()
{
e10: Pivot();     //defining labels 
FORMULA();
OPTIMIZE();
if (notoptimalsolution == 1) goto e10; // Boolean 1 to store truthness of notoptimal solution 
}

void Pivot()
{

double U,V,XMAX;
int i,j;
XMAX = 0.0;   //init XMAX  

for(j=2;j<=numberofvariables+1; j++) 
{
if (ARRAY[1][j] > 0.0 && ARRAY[1][j] > XMAX)
{
XMAX = ARRAY[1][j];
pivot2 = j;
}
}
U = 10e6;
for (i=2; i<=numberofconstraints+1; i++) 
{

if (ARRAY[i][pivot2] >= 0.0) goto e10;

V = fabs(ARRAY[i][1] / ARRAY[i][pivot2]);   //minimum ratio test 

if (V < U) 
{
U = V;
pivot1 = i;
}
e10:;   //returning to pivot 
}

//swapping 
V = ARRAY[0][pivot2];
ARRAY[0][pivot2] = ARRAY[pivot1][0]; 
ARRAY[pivot1][0] = V;

}


void FORMULA()
{
int i,j;

for (i=1; i<=numberofconstraints+1; i++)
{
if (i == pivot1) goto e70;

for (j=1; j<=numberofvariables+1; j++)
{
if (j == pivot2) goto e60;
ARRAY[i][j] -= ARRAY[pivot1][j] * ARRAY[i][pivot2] / ARRAY[pivot1][pivot2];  //Calculating deviation row
e60:;
}
e70:;
}

//Finding the pivot row and coloumn and hence the entering and leaving the varibales 


ARRAY[pivot1][pivot2] = 1.0 / ARRAY[pivot1][pivot2];

for (j=1; j<=numberofvariables+1; j++)
{
if (j == pivot2) goto e100;

ARRAY[pivot1][j] *= fabs(ARRAY[pivot1][pivot2]);

e100:;
}
for (i=1; i<=numberofconstraints+1;i++)
{
if (i== pivot1) goto e110;
ARRAY[i][pivot2] *= ARRAY[pivot1][pivot2];
e110:;
}
}


// Checking whether the solution is OPTIMIZED

void OPTIMIZE()
{
int i,j;
for (i=2; i<=numberofconstraints+1; i++)
if (ARRAY[i][1] < 0.0) X = 1;
notoptimalsolution = 0;
if (X == 1) return;

for (j=2; j<=numberofvariables+1; j++)
if (ARRAY[1][j] > 0.0) notoptimalsolution = 1;   

}

void RESULTS() {
int i,j;

if (X == 0) goto e30;

printf(" No solution exisARRAY.\n");

goto e100;

e30:for (i=1; i<=numberofvariables; i++)

for (j=2; j<=numberofconstraints+1; j++)
{
if (ARRAY[j][0] != 1.0*i) goto e70;

printf(" Variable #%d: %f\n", i, ARRAY[j][1]);

e70: ;
}

printf("\n Maxmized or Minimized Value of the objective Function  : %f\n", ARRAY[1][1]);

e100:printf("\n");

}


// The driver Code 


void main()
{
COLLECTDATA(); //the COLLECTDATA collecting function 

SIMPLESIMPLEX();

RESULTS();

}