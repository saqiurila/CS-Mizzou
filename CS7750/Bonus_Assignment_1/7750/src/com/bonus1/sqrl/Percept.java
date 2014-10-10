package com.bonus1.sqrl;

/**
 * Artificial Intelligence A Modern Approach (3rd Edition): pg 34.<br>
 * We use the term percept to refer the agent's perceptual inputs at any given
 * instant.
 * 
 * @author Ravi Mohan
 * @author Ciaran O'Reilly
 */
public interface Percept {
	public String getPosition();
	public void setPosition(String position);
	public int getIsClean();
	public void setIsClean(int isClean);
}
