/**
 * 
 */
package ColonialWars.production;

import java.util.Random;

/**
 * @author smlkt
 *
 */
public class ProductionB extends Production {

	/**
	 * @param name
	 */
	public ProductionB()
	{
		super("Kesintisiz Süreç");
	}

	@Override
	public int Produce()
	{
		Random random = new Random();
		return random.nextInt(20) / 2;
	}

}
