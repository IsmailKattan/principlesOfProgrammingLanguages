/**
 * 
 */
package ColonialWars.production;

/**
 * @author smlkt
 *
 */
public abstract class Production {
	
	private String name;
	
	public Production(String name)
	{
		this.name = name; 
	}
	
	public String getName()
	{
		return this.name;
	}
	
	public abstract int Produce();
	
	public String toString()
	{
		return "üretim tekniği : " + this.name;
	}

}
