/**
 * 
 */
package ColonialWars.tactic;

/**
 * @author smlkt
 *
 */
public abstract class Tactic {
	private int soldiers;
	private String name;
	
	public Tactic(int soldiers,String name) {
		this.soldiers = soldiers;
		this.name = name;
	}
	
	public int getSoldier()
	{
		return this.soldiers;
	}
	
	public String getName()
	{
		return this.name;
	}
	
	public void setSoldiers(int soldiers)
	{
		this.soldiers = soldiers;
	}
	
	public void setName(String name)
	{
		this.name = name;
	}
	
	public abstract int War();
	public abstract String printinfo();
	
	public String toString()
	{
		return "Taktik adi : " + this.getName() + "     asker sayisi : " + this.getSoldier();
	}//            13          +     15         +           20           +      4  = 52

}
