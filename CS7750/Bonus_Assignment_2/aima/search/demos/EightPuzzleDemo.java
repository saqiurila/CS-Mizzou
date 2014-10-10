/*
 * Created on Sep 12, 2004
 *
 */
package aima.search.demos;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Properties;

import aima.search.eightpuzzle.EightPuzzleBoard;
import aima.search.eightpuzzle.EightPuzzleGoalTest;
import aima.search.eightpuzzle.EightPuzzleSuccessorFunction;
import aima.search.eightpuzzle.ManhattanHeuristicFunction;
import aima.search.eightpuzzle.MisplacedTilleHeuristicFunction;
import aima.search.framework.GraphSearch;
import aima.search.framework.Problem;
import aima.search.framework.Search;
import aima.search.framework.SearchAgent;
import aima.search.informed.AStarSearch;
import aima.search.informed.GreedyBestFirstSearch;
import aima.search.informed.HillClimbingSearch;
import aima.search.informed.SimulatedAnnealingSearch;
import aima.search.uninformed.DepthLimitedSearch;
import aima.search.uninformed.IterativeDeepeningSearch;

/**
 * @author Ravi Mohan
 * 
 */

public class EightPuzzleDemo {
	public static void main(String[] args) {
		eightPuzzleAStarManhattanDemo();
	}

	private static void eightPuzzleAStarManhattanDemo() {
		System.out.println("\nEightPuzzleDemo AStar Search (ManhattanHeursitic)-->");
		try {
			GenerateRandomEightPuzzleBoard generator=new GenerateRandomEightPuzzleBoard();
			ManhattanHeuristicFunction manhattan=new ManhattanHeuristicFunction();
			double distances[] = new double[50];
			EightPuzzleBoard boards[] = new EightPuzzleBoard[50];
			System.out.println("Random instances:");
			for(int i=0;i<50;i++){
				EightPuzzleBoard board=generator.generate();
				double manhattanDistance=manhattan.getHeuristicValue(board);
				distances[i]=manhattanDistance;
				boards[i]=board;
				if(i==24)
					System.out.println();
				System.out.print((int)manhattanDistance+" ");
			}
			System.out.println("\n***********************");
			System.out.println("Sorted by manhattan distance:");
			System.out.println("----------------------");
			sort(distances,boards);
			for(int i=0;i<50;i++){
				System.out.println("instance "+(i+1)+":");
				System.out.println("manhattan distance:"+(int)distances[i]);
				long startTime=System.currentTimeMillis();
				Problem problem = new Problem(boards[i],
					new EightPuzzleSuccessorFunction(),
					new EightPuzzleGoalTest(), new ManhattanHeuristicFunction());
				
				Search search = new AStarSearch(new GraphSearch());
				SearchAgent agent = new SearchAgent(problem, search);
				long endTime=System.currentTimeMillis();
				printActions(agent.getActions());
				printInstrumentation(agent.getInstrumentation());
				System.out.println("running time£º"+(endTime-startTime)+"ms");
				System.out.println("----------------------");
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

	}
	private static void sort(double distances[],EightPuzzleBoard boards[]){
		for(int i=0;i<50;i++){
			for(int j=i+1;j<50;j++){
				if(distances[i]>distances[j]){
					double temp=distances[i];					
					distances[i]=distances[j];
					distances[j]=temp;
					
					EightPuzzleBoard board=boards[i];
					boards[i]=boards[j];
					boards[j]=board;
				}
			}
		}
	}
	private static void printInstrumentation(Properties properties) {
		Iterator<Object> keys = properties.keySet().iterator();
		while (keys.hasNext()) {
			String key = (String) keys.next();
			String property = properties.getProperty(key);
			System.out.println(key + " : " + property);
		}

	}

	private static void printActions(List actions) {
		for (int i = 0; i < actions.size(); i++) {
			String action = (String) actions.get(i);
			System.out.println(action);
		}
	}

}