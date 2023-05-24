package ColonialWars.tactic;

import java.util.*;

public class TacticA extends Tactic {

	private float rate = (float) 0.2;
	
	public TacticA(int population) {
									// 15
		super(population*30/100,"Gerilla Taktiği");
	}

	@Override
	public int War() {
		Random random = new Random();
		int num = random.nextInt(1240);
		return num - (int) (num * this.rate);
	}

	@Override
	public String printinfo() {
		return "başarma oranı = 56.20%";
	}

}
