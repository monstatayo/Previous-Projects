#include <stdio.h>
#include <math.h>

void output_short_format(double loan_amount, double interest_rate, double term_years) {

	double interest_amount,total_amount,interest_month;

	printf("---------------------------------\n          LOAN TERMS\n---------------------------------");

	printf("\nLoan amount:                  ");
	scanf("%lf",&loan_amount);
	printf("Interest Rate:                ");
	scanf("%lf",&interest_rate);
	printf("Term:                         ");
	scanf("%lf",&term_years);
	printf("---------------------------------\n\n");
	
		int term_months=term_years*12;
		interest_rate=(interest_rate/100)/12;
	
 		double p = loan_amount * interest_rate * (pow((1+interest_rate),term_months)/(pow((1+interest_rate),term_months)-1));
		interest_amount=((p*(term_months))-(loan_amount));
		total_amount=(term_months*p);
	
	printf("Monthly payment is:        %.2f\n", p);
	printf("Total interest is:         %.2f\n",interest_amount);
	printf("Total amount paid is:      %.2f\n",total_amount);

	return;
}


void output_amortized(double loan_amount, double interest_rate, double term_years) {
    
    double loan = loan_amount;
    
    
    const int term_months = term_years * 12; 
    const double monthly_interest = (interest_rate / 100) / 12; 
    const double m_payment = (loan * monthly_interest * pow(1 + monthly_interest, term_months)) / (pow(1 + monthly_interest, term_months) - 1);

    double interest_c = 0; 
    double principal_c = 0; 

   

    int year, month;
  
    for(year = 1; year <= term_years; year++) {

        printf("-----------------------------------------------------------------\n");
        printf(" Year  Month  Interest  Principal  Balance  |  INTEREST  PRINCIPAL");
        printf("\n-----------------------------------------------------------------\n%d\n", year);

        for(month = 1; month <= 12; month++) {

            double interest_amount = loan * monthly_interest;

            double principal_amount = m_payment - interest_amount;

            interest_c += interest_amount; 
            principal_c += principal_amount; 

            
            loan -= principal_amount;
            
        printf("%12.d %9.0f %10.0f %9.0f | %9.0f %9.0f\n", month, interest_amount, principal_amount, loan, interest_c, principal_c);
			
			
        }
    }
}


void output_extra_monthly(double loan_amount, double interest_rate, double term_years, double extra) {

    double loan = loan_amount;
    
    double finalyear;
    double finalmonth;


    const int term_months = term_years * 12; 
    const double monthly_interest = (interest_rate / 100) / 12; 
    const double m_payment = (loan * monthly_interest * pow(1 + monthly_interest, term_months)) / (pow(1 + monthly_interest, term_months) - 1);
    double interest_c = 0; 
    double principal_c = 0; 


    int year, month;
    
  	for(year = 1; year <= term_years; year++) {
    	
    	if (loan-extra<=0){
		break;
	}

        printf("--------------------------------------------------------------------------\n");
        printf(" Year  Month  Interest  Principal  Balance  |  INTEREST  PRINCIPAL  EXTRA");
        printf("\n--------------------------------------------------------------------------\n%d\n", year);
 		
 		
 	finalyear = year;
 		
        for(month = 1; month <= 12; month++) {
           
	  if (loan-extra<=0){
		break;

	}
		    

	    double interest_amount = loan * monthly_interest;
            double principal_amount = m_payment - interest_amount;
            interest_c += interest_amount; 
            principal_c += principal_amount + extra; 
            loan -= principal_amount+extra;
	
    		printf("%12.d %9.0f %10.0f %9.0f | %9.0f %9.0f %7.0f\n", month, interest_amount, principal_amount, loan, interest_c, principal_c,extra);

		finalmonth = month;
		
			}
			
    	}
    	

        int months_saved=(( term_months - ( (int)finalyear * 12 + (int)finalmonth) ) + 12);
	double years_saved=( term_years - ( finalyear + (finalmonth * .08333) ) + 1);
    	int interest_saved= ( ( loan_amount * ( monthly_interest * 100) - ( loan_amount * monthly_interest ) ) - interest_c + extra);

    	printf("The payments are finished %d months (%.1f years) earlier!\nThe interest saving is %d",months_saved,years_saved,interest_saved);
    
    
	}

	
void output_extra_yearly(double loan_amount, double interest_rate, double term_years, double extra) {

    double loan = loan_amount;
    
    double finalyear;
    double finalmonth;

    const int term_months = term_years * 12; 
    const double monthly_interest = (interest_rate / 100) / 12; 

    const double m_payment = (loan * monthly_interest * pow(1 + monthly_interest, term_months)) / (pow(1 + monthly_interest, term_months) - 1);

    double interest_c = 0; 
    double principal_c = 0; 


    int year, month;
    
    
    
    for(year = 1; year <= term_years; year++) {
    	
    	if (loan-extra<=0) 
		break;
	

        printf("--------------------------------------------------------------------------\n");
        printf(" Year  Month  Interest  Principal  Balance  |  INTEREST  PRINCIPAL  EXTRA");
        printf("\n--------------------------------------------------------------------------\n%d\n", year);
 		
 		
 	finalyear = year;
 		
        for(month = 1; month <= 12; month++) {
           
		   if (loan<=0)
			break;
			
		    double interest_amount = loan * monthly_interest;
           	    double principal_amount = m_payment - interest_amount;
            	    interest_c += interest_amount; 
            
           if (month==12){ 

            principal_c += principal_amount+extra; 

            loan -= principal_amount+extra;

    		printf("%12.d %9.0f %10.0f %9.0f | %9.0f %9.0f %7.0f\n", month, interest_amount, principal_amount, loan, interest_c, principal_c,extra);
			
					}
		else if (month!=12) {

			principal_c += principal_amount; 

            		loan -= principal_amount;

		printf("%12.d %9.0f %10.0f %9.0f | %9.0f %9.0f \n", month, interest_amount, principal_amount, loan, interest_c, principal_c);
			
		}
		
		finalmonth = month;	
   		 
    	}

}


    	int months_saved=((term_months-((int)finalyear*12+(int)finalmonth))+12);

	double years_saved=(term_years-(finalyear+(finalmonth*.08333))+1);

    	int interest_saved= ((loan_amount*(monthly_interest*100)-(loan_amount*monthly_interest))-interest_c+(extra/12));

    	printf("The payments are finished %d months (%.1f years) earlier!\nThe interest saving is %d",months_saved,years_saved,interest_saved);
    
    
	}


main (){
	
	int select;
	int cont=1;
	
	printf("Welcome!\n\n");
	
	while (cont==1){
	

	printf("\nWhat would you like to do?\n\n 1. Short summary\n 2. Amortized Schedule\n 3. Amortized schedule with early payments (Monthly)\n 4. Amortized schedule with early payments (Yearly)\n 5. End program\n");
	scanf("%d",&select);
	
		if (!(select>=1 && select<=5)){
			select==5;
		}
		
	

	
	if (select==1){
		output_short_format(0,0,0);
		
	}
	if (select==2){
		
	int L1,I1,Y1;
	
		printf("------------------------------------\n          AMORTIZED SCHEDULE\n------------------------------------");
		printf("\nEnter Loan amount: ");	
		scanf("%d",&L1);
		printf("\nEnter interest rate: ");	
		scanf("%d",&I1);
		printf("\nEnter amount of years: ");	
		scanf("%d",&Y1);
		
		output_amortized(L1,I1,Y1);
		
	}
	if (select==3){
	int L2,I2,Y2,E1;
		printf("--------------------------------------------------------------------\n          AMORTIZED SCHEDULE (WITH EARLY MONTHLY PAYMENTS)\n--------------------------------------------------------------------");
		printf("\nEnter Loan amount: ");	
		scanf("%d",&L2);
		printf("\nEnter interest rate: ");	
		scanf("%d",&I2);
		printf("\nEnter amount of years: ");	
		scanf("%d",&Y2);
		printf("\nEnter extra amount (per month): ");
		scanf("%d",&E1);
		output_extra_monthly(L2,I2,Y2,E1);
		
	}
	if (select==4){
		int L3,I3,Y3,E2;
		printf("-------------------------------------------------------------------\n          AMORTIZED SCHEDULE (WITH EARLY YEARLY PAYMENTS)\n-------------------------------------------------------------------");
		printf("\nEnter Loan amount: ");	
		scanf("%d",&L3);
		printf("\nEnter interest rate: ");	
		scanf("%d",&I3);
		printf("\nEnter amount of years: ");	
		scanf("%d",&Y3);
		printf("\nEnter extra amount (per year): ");
		scanf("%d",&E2);
		output_extra_yearly(L3,I3,Y3,E2);
		
	}
	if (select==5){
		return 5;
	}
	
	printf("\n\nWould you like to do anything else? (Press 1 to continue, Press 2 to end.)");
	scanf("%d",&cont);
	
		if (cont!=1  && cont!=2){
			printf("Invalid input!");
			cont=1;
		}
	}
}
