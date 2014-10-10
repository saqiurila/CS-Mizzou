package com.bonus1.sqrl;


public class SimpleReflexVacuum implements Agent{
	private int count=0;

	@Override
	public Action execute(Percept percept) {
		count++;
		if(percept.getIsClean()==0){
			Suck suck=new Suck();
			return suck;
			
		}
		else{
			if(percept.getPosition().equals("A")){
				return new Right();
			}
			else{
				return new Left();
			}				
		}
		
	}
	
	@Override
	public boolean isAlive() {
		if(count<1000){
			return true;
		}
		else
			return false;
	}
	@Override
	public void setAlive(boolean alive) {
		// TODO Auto-generated method stub
		
	}
}
