public class Application extends SavingsAccount {
    public static void main(String[] args) {
        SavingsAccount saver1 = new SavingsAccount();
        SavingsAccount saver2 = new SavingsAccount();

        saver1.modifyInterestRate(0.04);
        saver1.setBalance(2000.00);
        saver1.calculateMonthlyInterest(12);

        saver2.modifyInterestRate(0.04);
        saver2.setBalance(3000.00);
        saver2.calculateMonthlyInterest(12);

        saver1.modifyInterestRate(0.05);
        saver1.calculateMonthlyInterest(1);

        saver2.modifyInterestRate(0.05);
        saver2.calculateMonthlyInterest(1);
    }


}
