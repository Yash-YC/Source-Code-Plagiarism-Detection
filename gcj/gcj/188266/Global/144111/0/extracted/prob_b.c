#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Intersect {
	int s;
	int w;
	int t;
	int can_move_up;
	int can_move_right;
} Intersect;

typedef struct State {
	int r;
	int c;
	int pos;
	int t;
	int wait_time;
} State;


Intersect a[10][10];
int m, n;

State queue[100000];
int start_queue, end_queue;

State dequeue()
{
	State t = queue[start_queue];
	start_queue++;

	return t;
}

void enqueue(State t)
{
	end_queue++;
	if (end_queue >= 100000)
	{
		end_queue = 0;
	}
	queue[end_queue] = t;
}

int time_arr[100000];

void updateWorld(int time)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			memset(time_arr, 0, sizeof(int) * 100000);
			int temp = a[i][j].t;
			int xxx = a[i][j].s + a[i][j].w;
			int k, m;
			for (k = 0; k < a[i][j].s; k++)
			{
				for (m = -100; m < 100; m++)
				{
					int index = a[i][j].t + ( xxx * m) + k;
					if (index >= 0)
					{
						time_arr[index] = 1;
					}
				}
			}

			if (time_arr[time] == 1)
			{
				a[i][j].can_move_up = 1;
				a[i][j].can_move_right = 0;
			}
			else
			{
				a[i][j].can_move_up = 0;
				a[i][j].can_move_right = 1;
			}
		}
	}
}

State move_up(State s)
{
	if (s.pos == 0) {
		s.pos = 6;
	} 
	else if (s.pos == 1)
	{
		s.pos = 3;
	}
	s.wait_time = 0;
	s.t++;
	return s;
}

State move_right(State s)
{
	if (s.pos == 0) {
		s.pos = 1;
	}
	else if (s.pos == 6)
	{
		s.pos = 3;
	}
	s.wait_time = 0;
	s.t++;
	return s;
}

State cross_up(State s)
{
	if (s.pos == 3)
	{
		s.pos = 5;
	}
	else if (s.pos == 5)
	{
		s.r--;
		s.pos = 1; 
	}
	else if (s.pos == 6)
	{
		s.pos = 7;
	}
	else if (s.pos == 7)
	{
		s.r--;
		s.pos = 0;
	}
	s.wait_time = 0;
	s.t++;
	return s;
}

State cross_right(State s)
{
	if (s.pos == 3)
	{
		s.pos = 4;
	}
	else if (s.pos == 4)
	{
		s.c++;
		s.pos = 6;
	}
	else if (s.pos == 1)
	{
		s.pos = 2;
	}
	else if (s.pos == 2)
	{
		s.c++;
		s.pos = 0;
	}
	s.wait_time = 0;
	s.t++;
	return s;
}

State wait(State s)
{
	s.wait_time++;
	s.t++;
	return s;
}

int keep_wait(State s)
{
	int aw = a[s.r][s.c].w;
	int as = a[s.r][s.c].s;
	int max = aw > as ? aw : as;

	return (s.wait_time < max);
}

State generate_state(State s)
{
	Intersect inter = a[s.r][s.c];

	if (s.pos == 0)
	{
		if (inter.can_move_up)
		{
			enqueue(move_up(s));
		}
		if (inter.can_move_right)
		{
			enqueue(move_right(s));
		}
		if (keep_wait(s))
		{
			enqueue(wait(s));
		}
	}
	else if (s.pos == 1)
	{
		if (inter.can_move_up)
		{
			enqueue(move_up(s));
		}
		
		if (s.c < n - 1)
			enqueue(cross_right(s));
	}
	else if (s.pos == 2)
	{
		if (s.c < n - 1)
			enqueue(cross_right(s));
	}
	else if (s.pos == 3)
	{
		if (s.c < n - 1)
			enqueue(cross_right(s));
		if (s.r > 0)	
			enqueue(cross_up(s));
	}
	else if (s.pos == 4)
	{
		if (s.c < n - 1)
			enqueue(cross_right(s));
	}
	else if (s.pos == 5)
	{
		if (s.r > 0)	
			enqueue(cross_up(s));
	}
	else if (s.pos == 6)
	{
		if (inter.can_move_right)
		{
			enqueue(move_right(s));
		}
		if (keep_wait(s))
		{
			enqueue(wait(s));
		}
		if (s.r > 0)	
			enqueue(cross_up(s));
	}
	else if (s.pos == 7)
	{
		if (s.r > 0)	
			enqueue(cross_up(s));		
	}
}

int main()
{
	int num_test, t;
	
	scanf("%d\n", &num_test);
	for (t = 1; t <= num_test; t++)
	{
		start_queue = end_queue = 0;

		scanf("%d %d\n", &m, &n);
		int i, j;

		for	(i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d %d %d ", &a[i][j].s, &a[i][j].w, &a[i][j].t);
			}
		}

		State start;
		start.r = m - 1;
		start.c = 0;
		start.pos = 0;
		start.t = 0;

		enqueue(start);
		int time = 0;
		while (1)
		{
			State s = dequeue();
			updateWorld(s.t);

			if (s.r == 0 && s.c == n - 1 && s.pos == 3)
			{
				printf("Case #%d: %d\n", t, s.t);
				break;
			}
			generate_state(s);
		}

//		enqueue(start);

//		printf("Case #%d: ", t);
	}
	return 0;
}

