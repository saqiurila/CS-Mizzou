package com.bonus1.sqrl;


public class VacuumTest {
	public static void main(String[] args){
		VacuumState state[]={
			new VacuumState(0,0,"A"),
			new VacuumState(0,1,"A"),
			new VacuumState(1,0,"A"),
			new VacuumState(1,1,"A"),
			new VacuumState(0,0,"B"),
			new VacuumState(0,1,"B"),
			new VacuumState(1,0,"B"),
			new VacuumState(1,1,"B")
		};
		
		int totalScore=0;
		for(int i=0;i<state.length;i++){
			System.out.print("Initial state(");
			System.out.println(state[i].getIsAclean()+","+state[i].getIsBClean()+","+state[i].getPosition()+"):");
			int score=run(state[i]);			
			System.out.println("The performance score is: "+score);
			System.out.println();
			totalScore+=score;
		}
		System.out.println("The average performance score is: "+totalScore/state.length);
	}
	public static int run(VacuumState state){
		AbstractEnvironment vacuumEnvnmnt=new VacuumEnvironment(state);
		SimpleReflexVacuum vacuum=new SimpleReflexVacuum();
		vacuumEnvnmnt.addAgent(vacuum);
		
		int score=0;
		while(vacuum.isAlive()){
			String currentPosition=state.getPosition();
			Percept percept;
			if(currentPosition.equals("A")){
				percept=new VacuumPercept(currentPosition,state.getIsAclean());
			}
			else{
				percept=new VacuumPercept(currentPosition,state.getIsBClean());
			}
			Action action=vacuum.execute(percept);
			vacuumEnvnmnt.executeAction(vacuum,action);	
			score=score+state.getIsAclean()+state.getIsBClean();
		}
		return score;
	}
}
