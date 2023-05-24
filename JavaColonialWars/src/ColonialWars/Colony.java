/**
 * 
 */
package ColonialWars;

import ColonialWars.production.*;
import ColonialWars.tactic.*;

/**
 * @author smlkt
 *
 */
public class Colony {
	private int defeats;
	private Flag flag;
	private int foodStock;
	private int population;
	private Production production;
	private Tactic tactic;
	private boolean viable;
	private int wins;
	
	public Colony(int population,Flag flag,Tactic tactic,Production production) {
		if(population>0) {
			this.viable = true;
		}
		else {
			this.viable = false;
		}
		this.population = population;
		this.foodStock = population * population;
		this.wins = 0;
		this.defeats = 0;
		this.flag = flag;
		this.tactic = tactic;
		this.production = production;
	}
	
	public void defeat(){
		this.defeats++;
	}
	
	public void die() {
		this.viable = false;
	}
	
	public int getDefeats() {
		return this.defeats;
	}
	
	public char getFlag(){
		return this.flag.getFlag();
	}
	
	public int getFoodStock() {
		return this.foodStock;
	}
	
	public int getPopulation() {
		return this.population;
	}
	public int getWins() {
		return this.wins;
	}
	
	public boolean isViable() {
		return this.viable;
	}
	
	public int Produce() {
		return this.production.Produce();
	}
	
	public String productinInfo() {
		return this.production.toString();
	}
	
	public void setFoodStock(int foodstock) {
		this.foodStock = foodstock;
	}

	public void setPopulation(int population) {
		this.population = population;
	}
	
	public String tacticInfo() {
		return this.tactic.toString() + "     " + this.tactic.printinfo();
		//           52               +    5    +         22       = 79
	}
	
	public int War() {
		return this.tactic.War();
	}
	
	public void win() {
		this.wins++;
	}
}

