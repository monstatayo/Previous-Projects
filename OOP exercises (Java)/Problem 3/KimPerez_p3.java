import java.util.Scanner;
public class KimPerez_p3 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		
		int rating;
		int users = 0;
		int userSelect=1;
		int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
		int [] [] responses = new int[5][11];
		String [] topics = new String[5];
		
		topics[0] = "The acceleration of global warming and the consequences of climate change";
		topics[1] = "The influence of money in politics";
		topics[2] = "The cost of healthcare to an individual";
		topics[3] = "Protests ongoing in Hong Kong";
		topics[4] = "A global economic recession within the coming years";
		
		
		while (userSelect == 1) {
			
			System.out.println("This program will prompt questions that you will rate in personal importance in your life.\n(Rate from 1 - 10, with 1 being of LEAST importance, and 10 being of MOST importance)");
			
			System.out.println("");
			
			System.out.println(topics[0]);
			
			rating = scn.nextInt();
			

			//This is meant as a failsafe in case the user inputs a value outside of 1-10.
			
			while (rating > 10 || rating < 1) {
				
				System.out.println("Please enter a number from 1-10.");
				
				rating = scn.nextInt();
				
			}
			
			responses[0][rating-1]++;
			
			sum1 = sum1 + rating;
			
			
			System.out.println(topics[1]);
			
			rating = scn.nextInt();
			
			
			while (rating > 10 || rating < 1) {
				
				System.out.println("Please enter a number from 1-10.");
				
				rating = scn.nextInt();
				
			}
			
			responses[1][rating-1]++;
			
			sum2 = sum2 + rating;
			
			System.out.println(topics[2]);
			
			rating = scn.nextInt();
			
			while (rating > 10 || rating < 1) {
				
				System.out.println("Please enter a number from 1-10.");
				
				rating = scn.nextInt();
				
			}
			
			responses[2][rating-1]++;
			
			sum3 = sum3 + rating;
			
			
			System.out.println(topics[3]);
			
			rating = scn.nextInt();
			
			
			
			while (rating > 10 || rating < 1) {
				
				System.out.println("Please enter a number from 1-10.");
				
				rating = scn.nextInt();
			}
			
			responses[3][rating-1]++;
			
			sum4 = sum4 + rating;
			
			
			System.out.println(topics[4]);
			
			rating = scn.nextInt();
			
			while (rating > 10 || rating < 1) {
				System.out.println("Please enter a number from 1-10.");
				rating = scn.nextInt();
			}
			
			responses[4][rating-1]++;
			sum5 = sum5 + rating;
			
			System.out.println("Thank you for participating in the poll!\n");
			System.out.println("1) Add another participant.\n2) Show poll results");
			
			users++;
			
			userSelect = scn.nextInt();
			
			
		}
		
		double avg1, avg2, avg3, avg4, avg5;
		
		avg1 = (double) sum1/users;
		
		
		
		avg2 = (double) sum2/users;
		
		
		
		avg3 = (double) sum3/users;
		
	
		
		
		avg4 = (double) sum4/users;
		
		
		
		avg5 = (double) sum5/users;
		
		
		
		
		
		
		//Now to deal with the printing of the values
		
		System.out.printf("%20d %d %d %d %d %d %d %d %d %d | Avg\n",1,2,3,4,5,6,7,8,9,10);
		System.out.print("---------------------------------------------\n");
		System.out.print("Global Warming:    ");
		
		for (int i = 0; i < 10; i++) {
			
			System.out.print(responses[0][i]+" ");
			
		}
			System.out.print(" | "+ avg1);
		
		System.out.print("\nMoney in politics: ");
		
		for (int j = 0; j < 10; j++) {
			
			System.out.print(responses[1][j]+" ");
			
		}
			System.out.print(" | "+ avg2);
		
		
		System.out.print("\nHealthcare:        ");
		
		for (int k = 0; k < 10; k++) {
			
			System.out.print(responses[2][k]+" ");
			
		}
			System.out.print(" | "+ avg3);
		
		
		System.out.print("\nHong Kong:         ");
		
		for (int l = 0; l < 10; l++) {
			
			System.out.print(responses[3][l]+" ");
			
		}
			System.out.print(" | "+ avg4);
		
		
		System.out.print("\nRecession:         ");
		
		for (int m = 0; m < 10; m++) {
			
			System.out.print(responses[4][m]+" ");
			
		}
			System.out.print(" | "+ avg5);
			
			double max = 0;
			double min = 10;
			
			int topicmax = 0;
			int topicmin = 0;
			
			//determining the max
			
			if ((double)avg1 > max) {
				
				max = avg1;
				topicmax = 0;
			}
			
			if ((double)avg2 > max) {
				
				max = avg2;
				topicmax = 1;
			}
			
			if ((double)avg3 > max) {
	
				max = avg3;
				topicmax = 2;
			}
			
			if ((double)avg4 > max) {
				
				max = avg4;
				topicmax = 3;
			}
			
			//Min
			
			if ((double)avg5 > max) {
	
				max = avg5;
				topicmax = 4;
			}
			
			if ((double)avg1 < min) {
				
				min = avg1;
				topicmin = 0;
			}
			
			if ((double)avg2 < min) {
				
				min = avg2;
				topicmin = 1;
			}
			
			if ((double)avg3 < min) {
	
				min = avg3;
				topicmin = 2;
			}
			
			if ((double)avg4 < min) {
				
				min = avg4;
				topicmin = 3;
			}
			if ((double)avg5 < min) {
	
				min = avg5;
				topicmin = 4;
			}
			
			
		System.out.printf("\n\nThe highest point total: %s (%.1f)",topics[topicmax] ,max );
		System.out.printf("\nThe lowest point total: %s (%.1f)",topics[topicmin] ,min );
		
		scn.close();
		
	}

}