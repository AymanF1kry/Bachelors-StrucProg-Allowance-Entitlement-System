#include <stdio.h>
#include <ctype.h>
#define length 10

//First Function Prototype
void user_input_calculation(int applicant_ID, char read_input, int user_age, double monthly_income, char marital_status, 
      int children_under18, char east_west_malaysia, double allowance_single, int single_eligible, 
      double east_west_allowance_single, double allowance_family, int married_eligible, double east_west_allowance_family, 
      double totalallowance_single, double totalallowance_family, double total_allowance_single_family, int size, double array_income[length]);

//Second Function Prototype
void display_results(int applicant_ID, int user_age, double monthly_income, char marital_status, char east_west_malaysia, 
   int single_eligible, int married_eligible, double totalallowance_single, double totalallowance_family,
   double total_allowance_single_family, int size, double array_income[length]);
   
//Third Function Prototype   
void array_sorting(double monthly_income, int size, double array_income[length]);


int main (){
  //Integer data types declaration
  int user_age;
  int single_eligible = 0;
  int married_eligible = 0;
  int applicant_ID = 9;
  int children_under18 = 0;
  int size = 1;
  
  //Character data types declaration
  char read_input = 'C';
  char marital_status;
  char east_west_malaysia;
  
  //Double data types declaration
  double allowance_single = 0;
  double allowance_family = 0;
  double total_allowance_single_family = 0;
  double monthly_income = 0;
  double allowance_entitlement = 0;
  double east_west_allowance_single = 0;
  double east_west_allowance_family = 0;
  double totalallowance_single = 0;
  double totalallowance_family = 0;
  double array_income[length];
  
  //Call First function
  user_input_calculation(applicant_ID, read_input, user_age, monthly_income, marital_status, children_under18, east_west_malaysia, allowance_single,
  single_eligible, east_west_allowance_single, allowance_family, married_eligible, east_west_allowance_family, totalallowance_single,
  totalallowance_family, total_allowance_single_family, size, array_income);

  //Message after exit system
  printf ("\f\t\t\t\t\t\t\t\t=======================================\n");
  printf ("\f\t\t\t\t\t\t\t\t\t      See you again\n\a");
  printf ("\f\t\t\t\t\t\t\t\t=======================================\n");
}

   //First Funtion  
   void user_input_calculation(int applicant_ID, char read_input, int user_age, double monthly_income, char marital_status, 
      int children_under18, char east_west_malaysia, double allowance_single, int single_eligible, 
      double east_west_allowance_single, double allowance_family, int married_eligible, double east_west_allowance_family, 
      double totalallowance_single, double totalallowance_family, double total_allowance_single_family, int size, double array_income[length]){
      
    //Beginning of the system
    while (toupper (read_input) == 'C'){
      printf ("\nHow old are you?\n\a");
      scanf ("%d", &user_age);
      
    //Check if the user is eligible based on their age  
    if (user_age >= 18){
      printf ("\nWhat is your monthly income?\n\a");
      scanf ("%lf", &monthly_income);
     }
     
    //Check if the user is eligible based on their age and monthly income
    //Eligible users may pass through here
    if ((user_age >= 18) && (monthly_income <= 5000)){
        
        //Increment unique applicant ID  
	    applicant_ID++;
	    
	  //Prompt user to ask their marital status  
	  printf ("\nAre you married or single?\n\a");
	  printf ("\n Type M / m if you are married\n");
	  printf ("\n Type S / s if you are single\n\f");
	  scanf (" %c", &marital_status);

    //Prompt user if they are married and ask the number of children 
	if (toupper (marital_status) == 'M')
	    {
	      printf
		("\nHow many children do you have that are under 18 years old?\n\a");
	      scanf ("%d", &children_under18);
	    }

      //Prompt user which parts they are staying in Malaysia
	  printf ("\nAre you staying in East or West Malaysia\n\a");
	  printf ("\n Type E / e if you are located in East of Malaysia\n");
	  printf ("\n Type W / w if you are located in West of Malaysia\n\f");
	  scanf (" %c", &east_west_malaysia);

    //Allowance conditions for single and married applicants   
	if ((user_age >= 18) && (toupper (marital_status) == 'S'))
	    {
	      allowance_single += 1000;
	      single_eligible++;
	if (toupper (east_west_malaysia) == 'E')
		{
		  east_west_allowance_single += 500;
		}
	   }
	else if ((user_age >= 18) && (toupper (marital_status) == 'M') && (children_under18 <= 4))
	   {
	      allowance_family += 2500;
	      married_eligible++;
	if (toupper (east_west_malaysia) == 'E')
		{
		  east_west_allowance_family += 500;
		}
	   }
	else if ((user_age >= 18) && (toupper (marital_status) == 'M') && (children_under18 > 4))
	   {
	      allowance_family += 3500;
	      married_eligible++;
	if (toupper (east_west_malaysia) == 'E')
		{
		  east_west_allowance_family += 500;
		}
	   }
	    
      //Calculations of user allowance
	  totalallowance_single = allowance_single + east_west_allowance_single;
	  totalallowance_family = allowance_family + east_west_allowance_family;
	  total_allowance_single_family = totalallowance_single + totalallowance_family;
	    
	    //Call Second Function
	  display_results(applicant_ID, user_age, monthly_income, marital_status, east_west_malaysia, 
	    single_eligible, married_eligible, totalallowance_single, totalallowance_family, total_allowance_single_family, size, array_income);
	    
	   //Increment size of array 
	   size++;
	}
  
    //Users that are not eligible will pass through here
    else
	{
	  if (user_age < 18)
	    {
	      printf ("\nSorry but you are not entitled for an allowance\n");
	      printf ("\nReason: You are underage\n");
	    }
	  else if (monthly_income > 5000)
	    {
	      printf ("\nSorry but you are not entitled for an allowance\n");
	      printf ("\nReason: Your income is more than RM5000 a month\n");
	    }
	}
	
	   
      //Prompt user choose to continue or exit the system	
      printf ("\fWould you like to continue?\n\a");
      printf ("\nType C / c to continue\n\a");
      printf ("\nType E / e to exit\n\f\a");
      scanf (" %c", &read_input);

    }
}

    //Second Function
    void display_results(int applicant_ID, int user_age, double monthly_income, char marital_status, char east_west_malaysia, 
      int single_eligible, int married_eligible, double totalallowance_single, double totalallowance_family, 
      double total_allowance_single_family, int size, double array_income[length]){
      
      //Displaying user inputs and unique applicant ID
	  printf("\f\t\t\t\t\t\t\t---------------Applicant's Credentials-----------------\n\a");
	  printf("\f\t\t\t\t\t\t\tApplicant ID \t\t\t\t          AID%d\n", applicant_ID);
	  printf ("\t\t\t\t\t\t\tAge \t\t\t\t\t\t     %d\n", user_age);
	  if(monthly_income == 0){
	     printf ("\t\t\t\t\t\t\tMonthly Income \t\t\t\t         RM0.00\n");
	  }else if((monthly_income >= 0.01) && (monthly_income <= 9.99)){
	     printf ("\t\t\t\t\t\t\tMonthly Income \t\t\t\t         RM%.2lf\n", monthly_income);  
	  }else if((monthly_income >= 10) && (monthly_income <= 99.99)){
	     printf ("\t\t\t\t\t\t\tMonthly Income \t\t\t\t        RM%.2lf\n", monthly_income);  
	  }else if((monthly_income >= 100) && (monthly_income <= 999.99)){
	     printf ("\t\t\t\t\t\t\tMonthly Income \t\t\t\t       RM%.2lf\n", monthly_income); 
	  }else{
	     printf ("\t\t\t\t\t\t\tMonthly Income \t\t\t\t      RM%.2lf\n", monthly_income);
	  }
	  
	  if (toupper (marital_status) == 'M')
	    {

	      printf ("\t\t\t\t\t\t\tMarital Status \t\t\t\t        Married\n");
	    }
	  else
	    {

	      printf ("\t\t\t\t\t\t\tMarital Status \t\t\t\t         Single\n");
	    }

	  if (toupper (east_west_malaysia) == 'E')
	    {

	      printf ("\t\t\t\t\t\t\tParts of Malaysia \t\t                   East\n");
	    }
	  else
	    {
	      printf ("\t\t\t\t\t\t\tParts of Malaysia \t\t                   West\n");
	    }
	  
	  //Display count of single and married applicants  
	  printf("\f\t\t\t\t\t\t\t---------------Allowance Summary Report----------------\n\a");  
	  printf ("\f\t\t\t\t\t\t\tSingle applicants \t\t\t\t      %d\n", single_eligible);
	  printf ("\t\t\t\t\t\t\tMarried applicants \t\t\t\t      %d\n", married_eligible);
	  
	  //Display total allowance for singles
	  if(totalallowance_single == 0){
	      printf ("\t\t\t\t\t\t\tTotal allowance for single applicants            RM0.00\n"); 
	  }else if((totalallowance_single >= 100) && (totalallowance_single <= 999.99)){
	      printf ("\t\t\t\t\t\t\tTotal allowance for single applicants \t       RM%.2lf\n",totalallowance_single);  
	  }else if((totalallowance_single >= 1000) && (totalallowance_single <= 9999.99)){
	      printf ("\t\t\t\t\t\t\tTotal allowance for single applicants \t      RM%.2lf\n",totalallowance_single); 
	  }else{
	      printf ("\t\t\t\t\t\t\tTotal allowance for single applicants \t     RM%.2lf\n",totalallowance_single);
	  }
	  
	  //Display total allowance for families
	  if(totalallowance_family == 0){
	      printf ("\t\t\t\t\t\t\tTotal allowance for families                     RM0.00\n"); 
	  }else if((totalallowance_family >= 100) && (totalallowance_family <= 999.99)){
	      printf ("\t\t\t\t\t\t\tTotal allowance for families \t               RM%.2lf\n",totalallowance_family);  
	  }else if((totalallowance_family >= 1000) && (totalallowance_family <= 9999.99)){
	      printf ("\t\t\t\t\t\t\tTotal allowance for families \t              RM%.2lf\n",totalallowance_family); 
	  }else{
	      printf ("\t\t\t\t\t\t\tTotal allowance for families \t             RM%.2lf\n",totalallowance_family);
	  }
	  
	  //Display total allowance of single and family
	  if((total_allowance_single_family >= 1000) && (total_allowance_single_family <= 9999.99)){
	  printf ("\t\t\t\t\t\t\tTotal allowance for single & families \t      RM%.2lf\n", total_allowance_single_family);
	  }else if((total_allowance_single_family >= 10000) && (total_allowance_single_family <= 99999.99)){
	  printf ("\t\t\t\t\t\t\tTotal allowance for single & families \t     RM%.2lf\n", total_allowance_single_family);    
	  }else{
	  printf ("\t\t\t\t\t\t\tTotal allowance for single & families \t    RM%.2lf\n", total_allowance_single_family);    
	  }
	  
     
     //Call Third Function
	 array_sorting(monthly_income, size, array_income);
     
}

    //Third Function
    void array_sorting(double monthly_income, int size, double array_income[length])
    {
        //Declaration for sorting and searching variables
        double temp, lowest, highest;
        
    //Sorting Applicant's Monthly Income    
       array_income[size-1] = monthly_income;
       
     for(int a = 0; a < size; a++)
     {
           for(int b = a + 1; b < size; b++)
           {
               
               if(array_income[a] > array_income[b])
               {
                   
                   temp = array_income[a];
                   array_income[a] = array_income[b];
                   array_income[b] = temp;
                   
               }
           }
       }
    //Display the sorted monthly incomes   
    printf("\f\t\t\t\t\t\t\t-----------------Monthly Income Report-----------------\n");
    printf("\f\t\t\t\t\t\t\tList in ascending order:\n");
    for(int j = 0; j < size; j++)
       {

        printf(" \t\t\t\t\t\t\t%d) RM%.2lf\n", j+1, array_income[j]);
        
       }
       
       
    //Search lowest monthly income   
    lowest = array_income[0];
    for(int i = 0; i < size; i++)
    {
        if(array_income[i]<lowest){
            lowest = array_income[i];
        }
    }
    
    //Search highest monthly income
    highest = array_income[0];
    for(int i = 0; i < size; i++)
    {
        if(array_income[i]>highest){
            highest = array_income[i];
        }
    }
    //Display the lowest monthly income
    if(lowest==0){
    printf(" \f\t\t\t\t\t\t\tLowest Monthly Income                            RM0.00\n");    
    }else if((lowest >= 0.01) && (lowest <=9.99)){
    printf(" \f\t\t\t\t\t\t\tLowest Monthly Income                            RM%.2lf\n", lowest);    
    }else if((lowest>=10) && (lowest<=99.99)){
    printf(" \f\t\t\t\t\t\t\tLowest Monthly Income                           RM%.2lf\n", lowest);    
    }else if((lowest>=100) && (lowest<=999.99)){
    printf(" \f\t\t\t\t\t\t\tLowest Monthly Income                          RM%.2lf\n", lowest);    
    }else{
    printf(" \f\t\t\t\t\t\t\tLowest Monthly Income                         RM%.2lf\n", lowest);    
    }
    
    //Display the highest monthly income
    if(highest==0){
    printf(" \t\t\t\t\t\t\tHighest Monthly Income                           RM0.00\n");    
    }else if((highest >= 0.01) && (highest <=9.99)){
    printf(" \t\t\t\t\t\t\tHighest Monthly Income                           RM%.2lf\n", highest);    
    }else if((highest>=10) && (highest<=99.99)){
    printf(" \t\t\t\t\t\t\tHighest Monthly Income                          RM%.2lf\n", highest);    
    }else if((highest>=100) && (highest<=999.99)){
    printf(" \t\t\t\t\t\t\tHighest Monthly Income                         RM%.2lf\n", highest);    
    }else{
    printf(" \t\t\t\t\t\t\tHighest Monthly Income                        RM%.2lf\n", highest);    
    }    
    
    //Display the count of monthly income
    if(size < 10){
    printf(" \t\t\t\t\t\t\tTotal number of monthly incomes                       %d\n", size);
    }else{
    printf(" \t\t\t\t\t\t\tTotal number of monthly incomes                      %d\n", size);    
    }
    } 










