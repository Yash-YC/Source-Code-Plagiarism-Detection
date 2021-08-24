import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by Tor on 16.04.2016.
 */
public class BFF {

    public static void main(String[] args) {
        new BFF().go();
    }

    private void go() {
        Scanner s = new Scanner(System.in);

        int numCases = s.nextInt();

        for(int c=1;c<=numCases;c++) {
            int numKids = s.nextInt();
            Kid[] kids = new Kid[numKids];
            for(int i=0;i<numKids;i++) {
                kids[i] = new Kid(i+1);
            }


            for(int i=0;i<numKids;i++) {
                int bff = s.nextInt()-1;
                kids[i].bff = kids[bff];
                kids[i].friends.add(kids[bff]);
                kids[bff].friends.add(kids[i]);
            }

            List<Kid> bestPath = new ArrayList<Kid>();
            for(int i=0;i<numKids;i++) {
                List<Kid> path = search(kids[i], new LinkedList<Kid>());
//                System.out.println(path);

                if(path.size() > bestPath.size()) {
                    bestPath = path;
                }
            }
            System.out.format("Case #%d: %d\n", c, bestPath.size());
        }
    }


    private List<Kid> search(Kid kid, LinkedList<Kid> path) {
//        System.out.println("Handing kid #" +kid+": "+ path);

        LinkedList<Kid> newPath = new LinkedList<Kid>();
        newPath.addAll(path);
        newPath.add(kid);

        // If the previous kid was our bff, try all of them
        if(kid.bff.equals(path.peekLast())) {
            List<Kid> bestPath = newPath;
            for (Kid friend : kid.friends) {
                if (!path.contains(friend)) {
                    List<Kid> possiblePath = search(friend, newPath);

                    if (possiblePath.size() > bestPath.size()) {
                        bestPath = possiblePath;
                    }
                }
            }
            return bestPath;
        } else {
            // If not, we can only travel to our bff

            if(path.size() > 0 && path.get(0).equals(kid.bff)) { // Our BFF is the first, and we will be the last
                return newPath;
            }

            if(path.contains(kid.bff)) {
                return path;
            }

            List<Kid> potentialPath = search(kid.bff, newPath);
            if(!potentialPath.contains(kid.bff)) {
                return path;
            }
            return potentialPath;
        }
    }

    private class Kid {
        final int number;
        Kid bff;
        List<Kid> friends = new ArrayList<Kid>();

        public Kid(int number) {
            this.number = number;
        }

        @Override
        public String toString() {
            return String.valueOf(number);
        }
    }
}
