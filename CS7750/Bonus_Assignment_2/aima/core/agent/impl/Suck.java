package aima.core.agent.impl;

import aima.core.agent.Action;

/**
 * Describes an Action that can or has been taken by an Agent via one of its
 * Actuators.
 * 
 * @author sqrl
 */
public class Suck implements Action{
	
	public Suck(){
		System.out.println("Sucking...");
	}
	
	/**
	 * Indicates whether or not this Action is a 'No Operation'.<br>
	 * Note: AIMA3e - NoOp, or no operation, is the name of an assembly language
	 * instruction that does nothing.
	 * 
	 * @return true if this is a NoOp Action.
	 */
	public boolean isNoOp() {
		return false;
	}
}
