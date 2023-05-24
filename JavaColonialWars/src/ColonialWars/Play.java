/**
 * 
 */
package ColonialWars;

import java.util.*;
import ColonialWars.production.*;
import ColonialWars.tactic.*;
import java.lang.Math;

/**
 * @author smlkt
 *
 */
public class Play {
	private int colonialWars;
	private ArrayList<Colony> colonies;
	private ArrayList<Character> flags;
	
	public Play(int[] arr) {
		this.colonies = new ArrayList<>();
		this.flags = new ArrayList<>();
		this.colonialWars = 0;
		
		for(int i = 0; i < arr.length; i++) {
			Random random = new Random();
			Flag flag = new Flag();
			while(flags.contains(flag.getFlag())) {
				flag.resetFlag();
			}
			flags.add(flag.getFlag());
			Tactic[] tactics = new Tactic[3];
			tactics[0] = new TacticA(arr[i]);
			tactics[1] = new TacticB(arr[i]);
			tactics[2] = new TacticC(arr[i]);
			Production[] pro = new Production[3];
			pro[0] = new ProductionA();
			pro[1] = new ProductionB();
			pro[2] = new ProductionC();
			Colony colony = new Colony(arr[i],flag,tactics[random.nextInt(3)],pro[random.nextInt(3)]);
			this.colonies.add(colony);
		}
	}
	
	public void cls() {
		 try {
	            String os = System.getProperty("os.name").toLowerCase();

	            if (os.contains("win")) {
	                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
	            } else {
	                new ProcessBuilder("clear").inheritIO().start().waitFor();
	            }
	        } catch (Exception e) {
	            e.printStackTrace();
	        }
		 System.out.println();
	}
	
	public void ColonialWars() {

		if(this.viables() <= 1) {
			System.out.println("oyun bitmiştir");
			return;
		}
		this.colonialWars++;
		this.setPeaceResult();
	    for (int i = 0; i < this.colonies.size(); i++)
	    {
	        /*
	        i: j j j j 
	        0:
	        1: 0
	        2: 0 1
	        3: 0 1 2
	        4: 0 1 2 3
	        5: 0 1 2 3 4
	        */
	        for (int j = 0; j < i; j++)
	        {
	        	if(colonies.get(i).isViable()&& colonies.get(j).isViable()) {
	        		fighting(this.colonies.get(i),this.colonies.get(j));
	        	}
	        }
	    }
	}
	
	public void fighting(Colony A,Colony B)
	{
		Random random = new Random();
		int pickOne = random.nextInt(2);
		int a = A.War();
		int b = B.War();
		float rate = (float) Math.abs(a-b)/1000;
		if(a > b) {
			setFightingResult(A, B, rate);
		} else if(b > a) {
			setFightingResult(B, A, rate);
		} else {
			if(A.getPopulation() > B.getPopulation()) {
				setFightingResult(A, B, rate);
			} else if(B.getPopulation() > A.getPopulation()) {
				setFightingResult(B, A, rate);
			} else  {
				if(pickOne == 0) {
					setFightingResult(A, B, rate);
				} else {
					setFightingResult(B, A, rate);
				}
			}
		}
	}
	
	public int getWars()
	{
		return this.colonialWars;
	}
	
	public void printColonies() {
		System.out.println("tur :\t" + this.colonialWars);
		System.out.print(
				"| coloni | populasyon | yemek stogu | kazanma | kaybetme |\n" +
				"+--------+------------+-------------+---------+----------+\n");
		for(int i = 0;i < colonies.size();i++) {
			Colony colony = colonies.get(i);
			String text;
			if(colony.isViable()) {
				text = String.format("|%-8c|%-12d|%-13d|%-9d|%-10d|\n",colony.getFlag(),colony.getPopulation(),colony.getFoodStock(),colony.getWins(),colony.getDefeats());
			}
			else {
				text = "|   --   |     --     |     ---     |   ---   |    --    |\n";
			}
			System.out.print(text);
		}
		System.out.println("+--------+------------+-------------+---------+----------+\n");
	}
	
	public void printColoniesInfo() {
		for(int i = 0;i < this.colonies.size();i++) {
			System.out.println(
					"koloni         : " + colonies.get(i).getFlag() + "\n" +
					"populasyon     : " + colonies.get(i).getPopulation() + "\n" +
					"taktik         : " + colonies.get(i).tacticInfo() + "\n" +
					"yemek stogu    : " + colonies.get(i).getFoodStock() + "\n" +
					"uretim teknigi : " + colonies.get(i).productinInfo() + "\n");
		}
		System.out.println("----------------------------------------------------------------");
	}
	private void setFightingResult(Colony winner, Colony loser,float rate)
	{
		loser.defeat();
		winner.win();
		loser.setPopulation((int)(loser.getPopulation() * (1-rate)));
		int lostStock = (int)(loser.getFoodStock()*rate);
		loser.setFoodStock(loser.getFoodStock() - lostStock);
		winner.setFoodStock(winner.getFoodStock() + lostStock);
		if(loser.getPopulation()<=0||loser.getFoodStock()<=0) {
			loser.die();
		}
	}
	private void setPeaceResult() {
		for(int i = 0; i<this.colonies.size();i++) {
			if(this.colonies.get(i).isViable()) {
				this.colonies.get(i).setPopulation((int)(this.colonies.get(i).getPopulation()*(1.2)));
				this.colonies.get(i).setFoodStock(this.colonies.get(i).getFoodStock() - 2 * this.colonies.get(i).getPopulation() + colonies.get(i).Produce());
				if(this.colonies.get(i).getFoodStock()<0) {
					this.colonies.get(i).die();
				}
			}
		}
	}
	
	public int viables() {
		int counter = 0;
		for(int i = 0; i< this.colonies.size();i++) {
			if(this.colonies.get(i).isViable()) {
				counter++;
			}
		}
		return counter;
	}
	
	public void bekle() {
		System.out.println("Enter tusuna basin...");
        new java.util.Scanner(System.in).nextLine();
	}
}

