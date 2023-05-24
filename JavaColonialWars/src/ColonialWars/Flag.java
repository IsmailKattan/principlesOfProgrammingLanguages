/**
 * 
 */
package ColonialWars;

import java.util.*;

/**
 * @author smlkt
 *
 */
public class Flag {

	private char flag;
	
	public Flag()
	{
		Random random = new Random();
		this.flag = (char) (random.nextInt('~' - '!' + 1) + '!');
	}
	
	public char getFlag()
	{
		return this.flag;
	}
	
	public void resetFlag()
	{
		Random random = new Random();
		this.flag = (char) (random.nextInt('~' - '!' + 1) + '!');
	}
	
	public String toString()
	{
		return "bayrak : " + this.getFlag();
	}
}
