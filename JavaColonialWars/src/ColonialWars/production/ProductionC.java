/**
 * 
 */
package ColonialWars.production;

import java.util.Random;

/**
 * @author smlkt
 *
 */
public class ProductionC extends Production {

	/**
	 * @param name
	 */
	public ProductionC()
	{
		super("Standartlaşma");
	}

	@Override
	public int Produce()
	{
		Random random = new Random();
		return random.nextInt(5) * 2;
	}

}
