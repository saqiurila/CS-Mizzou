package com.bonus1.sqrl;



public class VacuumState implements EnvironmentState{
	private int isAclean ;
	private int isBClean;
	private String position;
	
	public VacuumState(int isAclean, int isBClean,String position){
		this.isAclean=isAclean;
		this.isBClean=isBClean;
		this.position=position;
	}

	public int getIsAclean() {
		return isAclean;
	}

	public void setIsAclean(int isAclean) {
		this.isAclean = isAclean;
	}

	public int getIsBClean() {
		return isBClean;
	}

	public void setIsBClean(int isBClean) {
		this.isBClean = isBClean;
	}

	public String getPosition() {
		return position;
	}

	public void setPosition(String position) {
		this.position = position;
	}
	
}
