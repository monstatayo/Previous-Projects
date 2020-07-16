import java.util.Scanner;
public class KimPerez_p2 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		
		System.out.println("BMI Calculator:\n\nPlease make a selection:\n1. Imperial (lbs/inches)\n2. Metric (kg/meters)\n");
		
		int select = scn.nextInt();
		
		if (select == 1) {
			
			System.out.println("Enter your weight in pounds: ");
			double weight = scn.nextDouble();
			
			System.out.println("Enter your height in inches: ");
			double height = scn.nextDouble();
			
			
			double BMI =((703*weight)/((height)*(height)));
			
			if (BMI < 18.5){
				
				System.out.printf("%.1f: Underweight", BMI);
				
			}
			
			else if (BMI >=18.5 && BMI <= 24.9) {
				
				System.out.printf("%.1f: Normal weight", BMI);
			}
			
			
			else if (BMI >=25 && BMI <= 29.9) {
				
				System.out.printf("%.1f: Overweight", BMI);
			}
			
			else if (BMI >= 30) {
				
				System.out.printf("%.1f: Obese", BMI);
			}
			
			
			else if (select ==2) {
				
				System.out.println("Enter your weight in kilograms: ");
				 weight = scn.nextDouble();
				
				System.out.println("Enter your height in meters: ");
				 height = scn.nextDouble();
				
				
				BMI =((weight)/((height)*(height)));
				
				if (BMI < 18.5){
					
					System.out.printf("%.1f: Underweight", BMI);
					
				}
				
				else if (BMI >=18.5 && BMI <= 24.9) {
					
					System.out.printf("%.1f: Normal weight", BMI);
				}
				
				
				else if (BMI >=25 && BMI <= 29.9) {
					
					System.out.printf("%.1f: Overweight", BMI);
				}
				
				else if (BMI >= 30) {
					
					System.out.printf("%.1f: Obese", BMI);
				}
			}
			
		}
		scn.close();
	}

}
