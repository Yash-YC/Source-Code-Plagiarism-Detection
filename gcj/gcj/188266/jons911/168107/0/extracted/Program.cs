using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;

namespace A {
    class Program {
		static void Main(string[] args) {
                DateTime now = DateTime.Now;
			string filename = @"c:\Documents and Settings\jshea\Desktop\test.txt";
			if (args.Length >= 1) {
				filename = args[0].ToString();
			}


            using (StreamReader file = new System.IO.StreamReader(filename)) {
                string currentLine;

                int numCases = 0;
                currentLine = file.ReadLine();
                if (!Int32.TryParse(currentLine, out numCases)) {
                    Console.WriteLine("Error.  First line (test cases) is not integer");
                }

                //Console.WriteLine("{0}: Base {1}: {2} IsHappy {3}", num, b, ToBase(num, b), IsHappy(ToBase(num, b), b));
                for (int i = 0; i < numCases; i++) {
                    currentLine = file.ReadLine();
                    List<int> arr = new List<int>();
                    foreach (string s in currentLine.Split()) {
                        if (s == "2" || s == "4") { } else {
                            arr.Add(Convert.ToInt32(s));
                        }
                    }

                    int found = -1;
                    for (int j = 2; j < 100000; j++) {
                        if (found == -1) {
                            for (int k = 0; k < arr.Count; k++) {
                                if (!IsHappy(ToBase(j, arr[k]), arr[k], new Dictionary<string,object>())) {
                                    break;
                                } else {
                                    if (k == arr.Count - 1) {
                                        found = j;
                                        break;
                                    }
                                }
                            }
                        } else {
                            break;
                        }
                    }
                    Console.WriteLine("Case #{0}: {1}", i+1, found);
                }
            }
        }

        public static string ToBase(int x, int b) {
            string r = "";
            while (x != 0) {
                r = (x % b).ToString() + r;
                x /= b;
            }
            return r;
        }

        public static bool IsHappy(string s, int b, Dictionary<string, object> past) {
            int i = 0;
            foreach (char c in s) {
                i += (c - '0') * (c - '0');
            }

            if (i == 1) {
                return true;
            } else {
                string next = ToBase(i, b);
                if(past.ContainsKey(next)) {
                    return false;
                } else {
                    past[next] = null;
                //switch(b) {
                //    case 3: 
                //        if(next == "2" || next == "12" || next == "22") {
                //            return false;
                //        }
                //        break;
                //    case 5:
                //        if(next == "4" || next == "23" || next == "33") {
                //            return false;
                //        }
                //        break;
                //    case 6:
                //        if(next == "32") {
                //            return false;
                //        }
                //        break;
                //    case 7:
                //        if(next == "22" || next == "34" || next == "13" || next == "16" || next == "63" || next == "44") {
                //            return false;
                //        }
                //        break;
                //    case 8:
                //        if(next == "5" || next == "4" || next == "32" || next == "24" || next == "64") {
                //            return false;
                //        }
                //        break;
                //    case 9:
                //        if(next == "55" || next == "58" || next == "45" || next == "75") {
                //            return false;
                //        }
                //        break;
                //}
                return IsHappy(next, b, past);
                }
            }
        }
    }
}