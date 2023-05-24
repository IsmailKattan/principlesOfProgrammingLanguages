/**
 * 
 */
package ColonialWars;

import java.util.*;

/**
 * @author smlkt
 *
 */
public class Test {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			String input;
			while(true) {
				System.out.println("boşluk ile ayrılmış sayılar giriniz :");
				input = scanner.nextLine().trim(); 

			    if(input.contains("  ")) {
			    	System.out.println("iki boşluk veya daha fazlası girmeyiniz");
			    } else {
			    	break;
			    }
			}
			String[] numbersArray = input.split(" "); 

			int[] numbers = new int[numbersArray.length]; 

			for (int i = 0; i < numbersArray.length; i++) {
			    numbers[i] = Integer.parseInt(numbersArray[i]); 
			}

			System.out.println("girilen sayılar: ");
			for (int number : numbers) {
			    System.out.print(number+"\t");
			}
			System.out.print("\n");
			Play play = new Play(numbers);
			play.bekle();
			play.cls();
			play.printColoniesInfo();
			play.bekle();
			play.cls();
			play.printColonies();
			while(true) {
				play.bekle();
				play.cls();
				play.ColonialWars();
				play.printColonies();
				if(play.viables() <= 1) {
					break;
				}
			}
			play.bekle();
			play.cls();
			System.out.println("son durum : ");
			play.printColonies();
			play.bekle();
			play.cls();
			System.out.println("Anahtar :\n Aleppo\n Gaziantep\n AI\n Machine Learning ");
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}	

	}

}
