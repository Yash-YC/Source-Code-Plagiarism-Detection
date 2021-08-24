#include"iostream"
#include"unordered_set"
#include"string"
#include"map"
#include"unordered_map"
#include"algorithm"
using namespace std;
struct Edge
{
public:
	unordered_set<int> In;
	int Out;
public:
	Edge() :In(), Out(-1){};
	~Edge(){};
};
vector<int> SolveDFS(unordered_map<int, Edge> &G, int Current, unordered_map<int, int> &Traveled)
{
	if (Traveled.find(Current) != Traveled.end())
	{ 
		return vector<int>();
	}

	Traveled.insert(make_pair(Current,0));

	vector<int> Res = SolveDFS(G, G[Current].Out, Traveled);

	Traveled[Current] = Res.size();

	Res.insert(Res.begin(), Current);

	return Res;
}
int Solve(unordered_map<int, Edge> &G, int Start)
{
	unordered_map<int,int> Traveled;

	vector<int> Res = SolveDFS(G, Start, Traveled);

	int Count = 0;

	for (const auto &v : Res)
	{
		int BFFID = G[v].Out;

		if ((G[v].In.empty()) && (G[BFFID].In.size()!=1) && (G[BFFID].In.find(G[BFFID].Out) == G[BFFID].In.end()))
		{
			
			Count = Count + 1;
		}
		if ((G[v].In.size() > 1) && (G[v].In.find(G[v].Out) != G[v].In.end()))
		{
			bool bFound = false;
			for (const auto in_v : G[v].In)
			{
				if (in_v == G[v].Out){ continue; }

				for (int seek = 0; seek < Res.size(); seek = seek + 1)
				{
					if (in_v == Res[seek])
					{ 
						bFound = true; 
						break; 
					}
				}
				if (bFound){ break; }
			}
			if (!bFound)
			{
				Count = Count - 1;
			}
		}
	}
	return Res.size() - Count;
}
int main()
{
	int Times = 0;
	::cin >> Times;

	for (int seek = 0; seek < Times; seek = seek + 1)
	{
		int ListSize;
		::cin >> ListSize;

		vector<int> List(ListSize);
		for (auto &v : List){ ::cin >> v; v = v - 1; }

		//BuildGraph
		unordered_map<int, Edge> G;
		for (int seek = 0; seek < List.size();seek=seek+1)
		{
			G.insert(make_pair(seek, Edge()));
		}
		for (int seek = 0; seek < List.size(); seek = seek + 1)
		{
			G[seek].Out = List[seek];
			G[List[seek]].In.insert(seek);
		}

		int Max = 0;

		for (int seek = 0; seek < List.size(); seek = seek + 1)
		{
			int CurrentDepth = Solve(G, seek);
			Max = Max < CurrentDepth ? CurrentDepth : Max;
		}


		::cout << "Case #" << seek + 1 << ": " << Max << endl;
	}

	//::system("pause");

	return 0;
}