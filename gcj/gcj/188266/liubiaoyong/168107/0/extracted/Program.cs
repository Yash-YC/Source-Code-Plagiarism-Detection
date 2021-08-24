using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GoogleCodeJam
{

    public class CaseItem : BaseCaseItem, IComparable<CaseItem>
    {
        private int ret = 1;
        private List<int> source_bases = new List<int>();
        private Dictionary<int, List<int>> happys = new Dictionary<int, List<int>>();


        public CaseItem(GoogleCodeJamRound round, int case_index, StreamReader sr)
            : base(round, case_index)
        {
            string s = sr.ReadLine();
            string[] a = s.Split(' ');
            for (int i = 0; i < a.Length; i++)
            {
                source_bases.Add(int.Parse(a[i]));
            }
        }


        private List<int> ToBase(int a, int b)
        {
            List<int> list = new List<int>(10);
            while (a >= 1)
            {
                if (a == 1)
                {
                    list.Add(1);
                    break;
                }
                else
                {
                    list.Add(a % b);
                    a = a / b;
                }
            }

            return list;
        }


        private bool ishappy(int a, int b)
        {
            List<int> target = new List<int>();
            
            for (int t1 = 0; t1 < int.MaxValue; t1++)
            {
                List<int> clist = this.ToBase(a, b);
                int sum = 0;
                for (int i = 0; i < clist.Count; i++)
                {
                    sum += clist[i] * clist[i];
                }

                if (sum == 1)
                {
                    return true;
                }
                if (target.Contains(sum))
                {
                    return false;
                }
                target.Add(sum);
                a = sum;
            }
            return false;
        }

        public void Play()
        {
            for (int h = 2; h < int.MaxValue; h++)
            {
                bool is_happy = true;
                for (int i = 0; i < source_bases.Count; i++)
                {
                    if (!ishappy(h, source_bases[i]))
                    {
                        is_happy = false;
                        break;
                    }
                }

                if (is_happy)
                {
                    this.ret = h;
                    break;
                }
            }
        }



        public void Write(StreamWriter sw)
        {
            sw.WriteLine(" {0}", ret);
        }


        public int CompareTo(CaseItem other)
        {
            return this.CaseIndex - other.CaseIndex;
        }
    }




    public abstract class BaseCaseItem 
    {
        private GoogleCodeJamRound m_round;
        private int m_case_index;
        private int m_order_index;

        /// <summary>
        /// 原始案例序号
        /// </summary>
        public int CaseIndex
        {
            get { return m_case_index; }
        }

        /// <summary>
        /// 排序后的案例序号, 从0开始
        /// </summary>
        public int OrderIndex
        {
            get { return this.m_order_index; }
        }
       

        public BaseCaseItem(GoogleCodeJamRound round, int case_index)
        {
            this.m_round = round;
            this.m_case_index = case_index;
        }

        /// <summary>
        /// 当前Round
        /// </summary>
        public GoogleCodeJamRound Round
        {
            get { return this.m_round; }
        }
      

        private CaseItem pre_case = null;
        /// <summary>
        /// 设置排序后的上一个案例，可为NULL
        /// </summary>
        /// <param name="item"></param>
        public void SetPreCase(CaseItem item)
        {
            pre_case = item;
        }

        /// <summary>
        /// 获取上一个案例，可为NULL
        /// </summary>
        public CaseItem PreCase
        {
            get { return pre_case; }
        }

        private CaseItem next_case = null;
        /// <summary>
        /// 设置排序后的下一个案例，可为NULL
        /// </summary>
        /// <param name="item"></param>
        public void SetNextCase(CaseItem item)
        {
            next_case = item;
        }

        /// <summary>
        /// 获取下个一案例，可为NULL
        /// </summary>
        public CaseItem NextCase
        {
            get { return next_case; }
        }

        /// <summary>
        /// 设置排序后的索引,从0开始
        /// </summary>
        /// <param name="order_index"></param>
        public void SetOrderIndex(int order_index)
        {
            this.m_order_index = order_index;
        }        
    }


    public class GoogleCodeJamRound
    {
        private List<CaseItem> m_source_items;
        private List<CaseItem> m_ordered_items;




        private void BeforePlay()
        {
        }





        private void Read()
        {
            string filepath = @"a.in";
            using (System.IO.StreamReader sr = new System.IO.StreamReader(filepath))
            {
                string first_line = sr.ReadLine();
                int case_num = int.Parse(first_line);
                m_source_items = new List<CaseItem>(case_num);
                for (int case_index = 0; case_index < case_num; case_index++)
                {
                    m_source_items.Add(new CaseItem(this, case_index, sr));
                }               
            }
        }

        private void Write()
        {
            string filepath = @"out.txt";
            using (System.IO.StreamWriter sw = new System.IO.StreamWriter(filepath, false))
            {
                foreach (CaseItem item in m_source_items)
                {
                    sw.Write("Case #{0}:", item.CaseIndex + 1);
                    item.Write(sw);
                }
            }
        }

        private void Play()
        {
            this.m_ordered_items = new List<CaseItem>(this.m_source_items);
            this.OrderItemsByKey(m_ordered_items);

            for (int i = 0; i < m_ordered_items.Count; i++)
            {
                CaseItem curr_case = m_ordered_items[i];

                curr_case.SetOrderIndex(i);

                CaseItem pre_case = null;
                CaseItem next_case = null;
                if (i > 0)
                {
                    pre_case = m_ordered_items[i - 1];
                    curr_case.SetPreCase(pre_case); 
                }
                
                if (i<m_ordered_items.Count - 1)
                {
                    next_case = m_ordered_items[i + 1];
                    curr_case.SetNextCase(next_case);                
                }                                
            }


            this.BeforePlay();

            for (int i = 0; i < m_ordered_items.Count; i++)
            {
                CaseItem curr_case = m_ordered_items[i];
                curr_case.Play();
            }
        }        

        public void Execute()
        {
            this.Read();
            this.Play();
            this.Write();
        }

        /// <summary>
        /// 没有排序的案例集合
        /// </summary>
        public List<CaseItem> SourceItems
        {
            get { return this.SourceItems; }
        }

        /// <summary>
        /// 排序后的案例集合
        /// </summary>
        public List<CaseItem> OrderedItems
        {
            get { return this.m_ordered_items; }
        }


        private void OrderItemsByKey(List<CaseItem> ordered_items)
        {
            for (int i = 0; i < ordered_items.Count; i++)
            {
                for (int j = i + 1; j < ordered_items.Count; j++)
                {
                    if (ordered_items[i].CompareTo(ordered_items[j]) > 0)
                    {
                        CaseItem t = ordered_items[i];
                        ordered_items[i] = ordered_items[j];
                        ordered_items[j] = t;
                    }
                }
            }
        }
    }

    
    public class GoogleCodeJamProgram
    {
        static void Main(string[] args)
        {
            (new GoogleCodeJamRound()).Execute();                        
        }
    }
}
