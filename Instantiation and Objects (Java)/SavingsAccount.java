public class SavingsAccount {

    private static double annualInterestRate;
    private double savingsBalance;



    public double setBalance(double newBalance){

        savingsBalance = newBalance;

        return savingsBalance;

    }

    public double getRate(){

        return annualInterestRate;
    }

    public static double modifyInterestRate(double newRate){

        annualInterestRate = newRate;

        return annualInterestRate;
    }

    public double calculateMonthlyInterest(int month){


        System.out.printf("\n\nInitial balance of: \n$%.2f\n",savingsBalance);

        System.out.printf("\nAnnual interest rate: \n%.2f %% \n",annualInterestRate*100);


        for (int i = month,j=1; i >= 1; i--,j++){

            savingsBalance = savingsBalance + (savingsBalance * (annualInterestRate / 12));

            System.out.printf("\nMonth %d: $%.2f",j,savingsBalance);

        }

        return savingsBalance;


    }

}
