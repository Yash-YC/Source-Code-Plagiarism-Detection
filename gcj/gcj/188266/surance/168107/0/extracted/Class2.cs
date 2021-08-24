using System;
using System.Collections;
using System.Text;

namespace ConsoleApplication5
{
    public class Class2
    {
        public int AllJinzhi(int[] jinzhi)
        {
            int ret = 2;
          
           
            int okCount=0;
            do
            {
                okCount = 0;
                foreach (int i in jinzhi)
                {
                    if (!isHappy(ret, i))
                        ret++;
                    else
                        okCount++;
                }
            } while (okCount!=jinzhi.Length);

            return ret;
          
        }
        public int FindSmallest(int jinzhi)
        {
            int ret = 1;
            bool isH = false;
            while (!isH)
            {
                ret++;
                isH = isHappy(ret, jinzhi);

            }
            return ret;
        }

        //给定10进制的数
        public bool isHappy(int o, int jinzhi)
        {
            ArrayList used = new ArrayList();

            string ret = jinzhiHuan(o, jinzhi);
            while (ret != "1")
            {
                ret = Pocess(ret, jinzhi);
                if (used.Contains(ret))
                    return false;
                else
                    used.Add(ret);
            }

            return true;
        }
        //给定n进制的a
        public string Pocess(string a,int jinzhi)
        {
         
            int count10 = 0;
            foreach (char c in a)
            {
                int intc = int.Parse(c.ToString());
                int toBase = 10;
                int intc10 = Convert.ToInt32(c.ToString(), toBase);
                int ji10 = intc10 * intc10;
                count10 += ji10;
              
            }
          return jinzhiHuan(count10, jinzhi);


        }

        //给定10进制的
        public string jinzhiHuan(int o, int jinzhi)
        {
            string ret = "";
            int shang = o / jinzhi;
            int mod = o % jinzhi;
            ret = mod.ToString();
            while (shang != 0)
            {
                int temp = shang;
                shang = temp / jinzhi;
                mod = temp % jinzhi;
                ret = mod + ret;
            }
            return ret;
        }
    }



}
