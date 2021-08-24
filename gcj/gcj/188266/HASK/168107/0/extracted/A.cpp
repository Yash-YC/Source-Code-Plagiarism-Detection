
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

class A
{
public:

  int Solve()
  {
    map<int, bool> mTab[10];
    map<int, bool>::iterator iter;
    set<int> sTab;

    for (int j = 0; j < m_nN; j++)
      {
	mTab[j][1] = true;
      }

    for (int i = 2; ; i++)
      {
	//cout << i << endl;

	int j;
	for (j = 0; j < m_nN; j++)
	  {
	    bool bHappy = false;
	    sTab.clear();
	    for (int nTmp = i; ; nTmp = Next(nTmp, m_nBase[j]))
	      {
		if (sTab.find(nTmp) != sTab.end())
		  break;
		sTab.insert(nTmp);

		iter = mTab[j].find(nTmp);
		if (iter != mTab[j].end())
		  {
		    bHappy = iter->second;
		    break;
		  }
	      }

	    for (set<int>::iterator sIter = sTab.begin(); 
		 sIter != sTab.end(); sIter++)
	      mTab[j][*sIter] = bHappy;

	    if (!bHappy)
	      {
		break;
	      }
	  }

	if (j >= m_nN)
	  return i;
      }

    return -1;
  }

  int Read()
  {
    char szBuf[64];
    char szTmp[4];

    memset(szBuf, 0, sizeof(szBuf));
    if (gets(szBuf) == 0)
      return -1;

    m_nN = 0;
    for (int i = 0; sscanf(szBuf + i, "%s", szTmp) != EOF; )
      {
	i += strlen(szTmp) + 1;
	sscanf(szTmp, "%d", &m_nBase[m_nN++]);
      }

    /*
    for (int i = 0; i < m_nN; i++)
      cout << m_nBase[i] << ' ';
    cout << endl;
    */
    return 0;
  }

private:
  inline int Next(int nNum, int nBase)
  {
    int nRes = 0;

    for (; nNum > 0; nNum /= nBase)
      {
	int nTmp = nNum % nBase;
	nRes += nTmp * nTmp;
      }

    return nRes;
  }

private:
  int m_nBase[10];
  int m_nN;
};

int main()
{
  freopen("o.txt", "w", stdout);

  A aa;
  int nTC;

  cin >> nTC;
  getchar();

  for (int nC = 1; nC <= nTC; nC++)
    {
      aa.Read();
      printf("Case #%d: %d\n", nC, aa.Solve());
    }

  return 0;
}
