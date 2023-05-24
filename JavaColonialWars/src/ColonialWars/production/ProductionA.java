/**
 * 
 */
package ColonialWars.production;

import java.util.*;

/**
 * @author smlkt
 *
 */
public class ProductionA extends Production {

	/**
	 * @param name
	 */
	public ProductionA()
	{
		super("Proaktif yaklaşım");
	}

	@Override
	public int Produce()
	{
		Random random = new Random();
		return random.nextInt(10);
	}

}
