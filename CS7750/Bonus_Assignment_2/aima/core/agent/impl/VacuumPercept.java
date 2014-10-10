package aima.core.agent.impl;

import aima.core.agent.Percept;

/**
 * The vacuum agent's perceptual inputs
 * 
 * @author sqrl
 */
public class VacuumPercept implements Percept{
	private String position;
	private int isClean;
	
	public VacuumPercept(String position, int isClean){
		this.position=position;
		this.isClean=isClean;
	}
	public String getPosition() {
		return position;
	}
	public void setPosition(String position) {
		this.position = position;
	}
	public int getIsClean() {
		return isClean;
	}
	public void setIsClean(int isClean) {
		this.isClean = isClean;
	}
}
