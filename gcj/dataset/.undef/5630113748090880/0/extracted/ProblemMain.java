import java.util.*;
import java.io.*;

public class ProblemMain {
    
    public static void solution(int i_test, long n)
    {
        System.out.println("Case #" + i_test + ": " + (1) );
    }
    
    public static class HeightList
    {
        HeightList(int length_n)
        {
            heights = new Vector<Integer>(length_n);
        }
        public Vector<Integer> heights;
    }
    public static class HeightListComparator implements Comparator<HeightList>
    {
        public int compare(HeightList c1, HeightList c2)
        {
            return Integer.compare(c1.heights.elementAt(0), c2.heights.elementAt(0));
        }
    }
    // return true if available_lists[0] fits in next row
    public static boolean check_row(int row_index, int missing_row_index, Vector<HeightList> columns, Vector<HeightList> available_lists)
    {
        HeightList possible_row = available_lists.elementAt(0);
        
        // matches row if columns match with current row position
        for( int i_col = 0; i_col < columns.size(); i_col ++ )
        {
            HeightList col = columns.elementAt(i_col);
            if( col.heights.elementAt(row_index) != 0
                    && possible_row.heights.elementAt(i_col) != col.heights.elementAt(row_index))
            {
                return false;
            }
        }
        
//        int col_count = possible_row.heights.size();
//        // find workable columns for other columns
//        for( int i_col = columns.size(); i_col < col_count; i_col++ )
//        {
//            for( int i_list = 1; i_list < available_lists.size(); i_list++ )
//            {
//                HeightList possible_column = 
//                if( row_index == missing_row_index )
//                {
//                    
//                }
//            }
//        }
        
        return true;
    }
    public static void main(String[] args) {
        try {
//            System.setIn(new FileInputStream("sample.txt"));
            System.setIn(new FileInputStream("B-small-attempt0.in"));
//            System.setIn(new FileInputStream("B-large.in"));
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int test_cases = in.nextInt(); // Scanner has functions to read ints,
                                       // longs, strings, chars, etc.
        
        // test code
//        for( int i_test_code = 1; i_test_code <= 200; i_test_code++ )
//        {
//            solution(i_test_code, i_test_code);
//        }
//        
//      
        in.nextLine();
        
        
        // actual code
        for (int i_test = 1; i_test <= test_cases; ++i_test) {
            int list_length_n = in.nextInt();
            int num_lists = (2*list_length_n - 1);
            Vector<HeightList> available_lists = new Vector<HeightList>();

            for( int i_list = 0; i_list < num_lists; i_list++ )
            {
                HeightList next_list = new HeightList(list_length_n);
                for( int i_height = 0; i_height < list_length_n; i_height++ )
                {
                    next_list.heights.addElement(in.nextInt());
                }
                available_lists.addElement(next_list);
            }

            // find missing digit
            // sort rows by first digit
            available_lists.sort(new HeightListComparator());
            
            Vector<HeightList> rows = new Vector<HeightList>();
            Vector<HeightList> columns = new Vector<HeightList>();
            
            int missing_row_index = 0;
          for( int i_list = 0; i_list < available_lists.size() - 1; i_list++ )
          {
              HeightList list = available_lists.elementAt(i_list);
              if( list.heights.elementAt(0) == available_lists.elementAt(i_list+1).heights.elementAt(0) )
              {
                  i_list++;
                  missing_row_index++;
              }
              else
              {
                  break;
              }
          }
          //System.out.println("missing_row_index=" + missing_row_index);
          
          HeightList missing_list = new HeightList(list_length_n);
          for( int i_height = 0; i_height < list_length_n; i_height++ )
          {
              missing_list.heights.addElement(0);
          }
          
         // int matrix[][] = new int[list_length_n][list_length_n];
//          rows.addElement(available_lists.remove(0));
//          columns.addElement(available_lists.remove(0));
//          
          // add each row such that the other available lists can be the columns
          int row_index = 0;
          boolean is_missing_row = false;
          while(available_lists.size() > 0)
          {
              if( row_index != missing_row_index )//&& available_lists.size() >= 2 )
              {
                  if( check_row(row_index, missing_row_index, columns, available_lists) )
                  {
                      rows.addElement(available_lists.remove(0));
                      columns.addElement(available_lists.remove(0));
                  }
                  else
                  {
                      columns.addElement(available_lists.remove(0));
                      rows.addElement(available_lists.remove(0));
                  }
              }
              else
              {
                  if( check_row(row_index, missing_row_index, columns, available_lists) )
                  {
                      rows.addElement(available_lists.remove(0));
                      columns.addElement(missing_list);
                  }
                  else
                  {
                      columns.addElement(available_lists.remove(0));
                      rows.addElement(missing_list);
                      is_missing_row = true;
                  }
              }
              row_index++;
          }
//
//          if( !is_missing_row )
//          {
//              // print columns
//            for( int i_list = 0; i_list < rows.size(); i_list++ )
//            {
//                HeightList list = rows.elementAt(i_list);
//                for( int i_height = 0; i_height < list_length_n; i_height++ )
//                {
//                    System.out.print(list.heights.elementAt(i_height) + " ");
//                }
//                System.out.println("");
//            }
//          }
//          else
//          {
//              // print rows
//              for( int i_list = 0; i_list < columns.size(); i_list++ )
//              {
//                  HeightList list = columns.elementAt(i_list);
//                  for( int i_height = 0; i_height < list_length_n; i_height++ )
//                  {
//                      System.out.print(list.heights.elementAt(i_height) + " ");
//                  }
//                  System.out.println("");
//              }
//          }
          System.out.print("Case #" + i_test + ": ");
          if( !is_missing_row )
          {
              // print values from row of missing column index
            for( int i_list = 0; i_list < rows.size(); i_list++ )
            {
                HeightList list = rows.elementAt(i_list);
                //for( int i_height = 0; i_height < list_length_n; i_height++ )
                {
                    System.out.print(list.heights.elementAt(missing_row_index) + " ");
                }
            }
            System.out.println("");
          }
          else
          {
              // print rows
              for( int i_list = 0; i_list < columns.size(); i_list++ )
              {
                  HeightList list = columns.elementAt(i_list);
//                  for( int i_height = 0; i_height < list_length_n; i_height++ )
                  {
                      System.out.print(list.heights.elementAt(missing_row_index) + " ");
                  }
              }
              System.out.println("");
         }
//            Vector<HeightList> paired_lists = new Vector<HeightList>();
//          int min_height_for_pos = 3000;
          // find min height

//            
//            Vector<HeightList> matrix = new Vector<HeightList>();
//            
//            HeightList previous_col_list = null;
//            HeightList new_previous_col_list = null;
//            int i_pos = 0;
//            while(available_lists.size() > 0)
//            {
//                int min_height_for_pos = 3000;
//                // find min height
//                for( int i_list = 0; i_list < available_lists.size(); i_list++ )
//                {
//                    HeightList list = available_lists.elementAt(i_list);
//                    if( list.heights.elementAt(i_pos) < min_height_for_pos )
//                    {
//                        min_height_for_pos = list.heights.elementAt(i_pos);
//                    }
//                }
//                
//                boolean added_list = false;
//                // add one of the lists with min_height to matrix
//                for( int i_list = 0; i_list < available_lists.size(); i_list++ )
//                {
//                    HeightList list = available_lists.elementAt(i_list);
//                    if( list.heights.elementAt(i_pos) == min_height_for_pos )
//                    {
//                        if(!added_list)
//                        {
////                            if(previous_col_list != null)
////                            {
////                                //check if matches
////                                if( previous_col_list.heights.elementAt(i_pos-1)
////                                        == list.heights.elementAt(i_pos-1) )
////                                {
////                                    matrix.addElement(list);
////                                    added_list = true;
////                                }
////                                else
////                                {
////                                    new_previous_col_list = list;
////                                }
////                            }
////                            else
//                            {
//                                matrix.addElement(list);
//                                added_list = true;
//                            }
//                        }
//                        else
//                        {
//                            new_previous_col_list = list;
//                        }
//                        available_lists.removeElementAt(i_list);
//                        i_list--;
//                    }
//                }
//                previous_col_list = new_previous_col_list;
//            }
//            
//            for( int i_list = 0; i_list < matrix.size(); i_list++ )
//            {
//                HeightList list = matrix.elementAt(i_list);
//                for( int i_height = 0; i_height < list_length_n; i_height++ )
//                {
//                    System.out.print(list.heights.elementAt(i_height) + " ");
//                }
//                System.out.println("");
//            }
            
            //solution(i_test, n);
            //System.out.println("Case #" + i_test + ": " + (lists) );
        }

        in.close();
    }

}
