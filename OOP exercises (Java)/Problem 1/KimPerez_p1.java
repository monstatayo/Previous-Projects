
import java.util.Scanner;
public class KimPerez_p1 {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int pass[] = new int[4];
		int i, temp;
		
		System.out.println("Select a function:\n1. Encrypt a 4-digit passcode.\n2. Decrypt a 4-digit passcode.");
		int select = scn.nextInt();

if (select == 1){
//the first part of this program will be for the encryption. 
		
		
		System.out.println("Please enter your passcode: ");
		
		for (i=0;i<4;i++) {
			
			pass[i] = scn.nextInt();
			
			pass[i] = pass[i]+7;
			
			pass[i]=pass[i]%10;
		
		}
		//replacing 1 and 3
		
		temp = pass[0];
		pass[0]=pass[2];
		pass[2]=temp;
		
		temp=pass[1];
		pass[1]=pass[3];
		pass[3]=temp;
		
		System.out.println("Your encrypted passcode is: ");
		
		for (int j=0; j<4; j++) {
			System.out.print(pass[j] + " ");
			
			}
		
		}
		
		//the second part is for the decryption
		
else if (select==2) {
		
	System.out.println("Please enter your passcode with spaces between digits: ");
	
	for (i=0;i<4;i++) {
		
		pass[i] = scn.nextInt();
		
		pass[i]= 10 + pass[i];
		
		pass[i] = pass[i]-7;
		
		if (pass[i]>10) {
			pass[i]= pass[i]-10;
		}
	}
	
	temp = pass[0];
	pass[0]=pass[2];
	pass[2]=temp;
	
	temp=pass[1];
	pass[1]=pass[3];
	pass[3]=temp;
	
	System.out.println("Your decrypted passcode is: ");
	
	for (int j=0; j<4; j++) {
		System.out.print(pass[j] + " ");
		
		}
	
	}


else 
	System.out.println("Invalid input");
	scn.close();
	return;
	
	}

}
