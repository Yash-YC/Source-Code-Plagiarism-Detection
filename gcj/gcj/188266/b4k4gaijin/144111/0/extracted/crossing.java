import java.util.*;
public class crossing
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int numProblems = sc.nextInt();
        for(int prob = 1; prob <= numProblems; prob++)
        {
            int horizRoads = sc.nextInt();
            int vertRoads = sc.nextInt();
            int rows = horizRoads*2;
            int cols = vertRoads*2;
            
            boolean[][] currentReachable = new boolean[horizRoads*2][vertRoads*2];
            boolean[][] reachableInOne = new boolean[horizRoads*2][vertRoads*2];
            boolean[][] reachableInTwo = new boolean[horizRoads*2][vertRoads*2];
            
            int[][] timeNS = new int[horizRoads][vertRoads];
            int[][] timeEW = new int[horizRoads][vertRoads];
            int[][] cycleLength = new int[horizRoads][vertRoads];
            int[][] nsStartTime = new int[horizRoads][vertRoads];
            
            for(int i = 0; i < horizRoads; i++)
                for(int j = 0; j < vertRoads; j++)
                {
                    timeNS[i][j] = sc.nextInt();
                    timeEW[i][j] = sc.nextInt();
                    cycleLength[i][j] = timeNS[i][j] + timeEW[i][j];
                    nsStartTime[i][j] = sc.nextInt() % cycleLength[i][j];
                }
            
            int time = 0;
			currentReachable[rows-1][0] = true;
            while(! currentReachable[0][cols-1])
            {
                for(int i = 0; i < rows; i++)
                    for(int j = 0; j < cols; j++)
                    {
						if(currentReachable[i][j])
                        {
                            //we can move in four directions, or stay here till the next time step.
                            reachableInOne[i][j] = true;
                            
                            boolean crossNS = false;
							
                            int timeInCycle = (time + cycleLength[i/2][j/2] - nsStartTime[i/2][j/2]) % cycleLength[i/2][j/2];

                            if(timeInCycle < timeNS[i/2][j/2])
                            {
                                crossNS = true;
                            }
							                            
                            if(i%2 == 0)
                            {
                                if(i > 0)
                                //you're on the north side of the street
                                    reachableInTwo[i-1][j] = true;
                                if(crossNS && i < rows-1)
                                    reachableInOne[i+1][j] = true;
                                
                            }
                            else
							{
								if(i < rows-1)
									reachableInTwo[i+1][j] = true;
                                //you're on the south side of the street
                                if(crossNS && i > 0)
                                    reachableInOne[i-1][j] = true;
                            }
                            if(j%2 == 0)
                            {
                                //you're on the west side of the street
                                if(j > 0)
                                    reachableInTwo[i][j-1] = true;
                                
                                if(!crossNS && j < cols-1)
                                    reachableInOne[i][j+1] = true;
                            }
                            else
                            {
								if(j < cols-1)
									reachableInTwo[i][j+1] = true;
                                
                                if(!crossNS && j > 0)
                                    reachableInOne[i][j-1] = true;
                            }

                        }
                    }
                
                time++;
				
                currentReachable = reachableInOne;
                reachableInOne = reachableInTwo;
                reachableInTwo = new boolean[horizRoads*2][vertRoads*2];
            }
            System.out.println("Case #" + prob+": "+time);
        }
    }
}