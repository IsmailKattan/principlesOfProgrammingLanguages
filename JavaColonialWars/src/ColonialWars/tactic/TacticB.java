/**
 * 
 */
package ColonialWars.tactic;

import java.util.*;

/**
 * @author smlkt
 *
 */
public class TacticB extends Tactic {

	private float rate = (float) 0.3;
	
	/**
	 * @param soldiers
	 * @param name
	 */
	public TacticB(int population)
	{
		super(population*25/100,"Part Vuruşu");
	}
	

	@Override
	public int War()
	{
		Random random = new Random();
		int num = random.nextInt(1240);
		return (int)(num - num * this.rate);
	}

	@Override
	public String printinfo()
	{
		return "başarma oranı = 50.16%";
	}

}
