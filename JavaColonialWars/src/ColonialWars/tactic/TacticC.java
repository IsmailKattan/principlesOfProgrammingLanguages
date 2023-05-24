/**
 * 
 */
package ColonialWars.tactic;

import java.util.*;

/**
 * @author smlkt
 *
 */
public class TacticC extends Tactic {
	
	private float rate = (float) 0.4;
	
	/**
	 * @param soldiers
	 * @param name
	 */
	public TacticC(int population)
	{
		super(population*20/100,"fil Ordusu");
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
		return "başarma oranı = 43.30%";
	}

}
