Product Manufacturing 6

A company has to produce IOT products of different models,
Each product requires cpus,memories and boards. After production of models, some spare equipments may be left.
In these, cpus and memories can be sold as spare parts but boards cannot be sold.
Due to manufacturing constraints maximum 3 models can be produced.
Each product can be sold at the cost of its model.
Given N different models.
D cpus with price d each.
E memories with price e each.
F boards.

Input:-
T number of testcases, followed by testcases,
Each test case consists of
D total  number of cpus available.
E total number of memories available.
F total number of boards available.
N number of models followed by N lines consisting of
ai, bi, ci and pi where ai is the number of cpus,bi number of memories, ci number of boards
required for producing one unit of that model and pi is the selling price of the one unit of that model.

Output:-
Print the testcase number followed by the Maximum profit that can be made.

Note:- Maximum profit can also be attained without any production that is by just selling  its components.

Constraints:-
1 ≤ N ≤ 8,  1 ≤ D,E,F ≤ 100,  1 ≤ d,e ≤ 10,  1 ≤ ai,bi,ci ≤ 5,  1 ≤ pi ≤ 100

Complexity
----------------------

Simply question is :
	we need to choose up to 3 out of 8 (0-3)products, 
Answer = Value of products+ remaining CPU*CPU_COST+remaining MEMORY*MEM_COST

Lets try to calculate complexity for brute force approach.

1.We need to choose max 3 out of 8 products, so for that complexity is 8c3=56

2. (taking product-1 out of chosen products from 0 to MAX possible if we take only this product)*(taking product-1 out of chosen products from 0 to MAX possible if we take only this product)*(taking product-1 out of chosen products from 0 to MAX possible if we take only this product) = (100*100*100)
 
So final complexity is  = 8c3*100*100*100 < 10^9.

3. So If complexity is less than 10^9 we can freely go ahead


Input:
--------
7
2 2 2 1 1
1
2 2 2 6
5 10 10 1 1       
2
2 1 1 8
1 1 1 6
10 10 10 2 1      
1
1 2 2 3
4 6 4 2 1         
4
2 4 2 9
1 3 1 7
2 1 1 8
1 2 2 6
40 80 60 1 3      
7
3 2 2 56
5 4 2 12
3 5 3 65
1 2 5 78
5 5 2 85
4 2 3 76
5 5 1 48
100 100 100  6 10      
8
3 3 1 74
2 3 1 41
3 2 1 64
2 2 3 68
2 2 2 71
2 3 2 66
2 3 3 84
3 3 1 48 
100 100 100 1 1
8
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1

Output:

# 1 6
# 2 35
# 3 30
# 4 21
# 5 1338
# 6 3550
# 7 200

--------------------------------------------
Time taken including input reding.
# 1 time = 0.002
# 2 time = 0.002
# 3 time = 0.001
# 4 time = 0.003
# 5 time = 0.064
# 6 time = 0.203
# 7 time = 0.001

Precautions to take care:
--------------------------------

1.Question asked is we need to choose up to 3 out of 8 products, means we can choose no product also and sell all individual components.

2. When choosing a product we need to check whether the component I am spending for this product worth more than if I sell individual products, if not ignore product completely

3.When we apply 3 for loops to generate 8c3 combination, we need to consider N<3 also

4. Always calculate time roughly before selecting approach as explained above.

bruteforce.java

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

// Complexity can be 8c3 * 10^6(choosing 3 out of 8 products * (choosing 0 to mx possible (100*100*100))
public
class Product_BruteForce
{
	static int CPU;
	static int MEM;
	static int BRD;
	static int CPU_COST;
	static int MEM_COST;
	static int N;

	static class Pro
	{
		int c;
		int m;
		int b;
		int v;

		Pro(int _c, int _m, int _b, int _v)
		{
			c = _c;
			m = _m;
			b = _b;
			v = _v;
		}
	}

	static Pro[] products = new Pro[8];

	static int[] MAXNUM = new int[8];

public
	static void main(String[] args) throws FileNotFoundException
	{
		Scanner sc = new Scanner(new FileInputStream("product.txt"));

		int T = sc.nextInt();
		for (int t = 1; t <= T; t++)
		{
			long time = System.currentTimeMillis();
			CPU = sc.nextInt();
			MEM = sc.nextInt();
			BRD = sc.nextInt();
			CPU_COST = sc.nextInt();
			MEM_COST = sc.nextInt();
			N = sc.nextInt();
			for (int i = 0; i < N; i++)
			{
				products[i] = new Pro(sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt());
				MAXNUM[i] = findMax(products[i]);
			}

			int MAX = Integer.MIN_VALUE;
			// The Brute force approach

			for (int i = 0; i < N; i++)
			{ // for loop 1 for 1st product out of 3 choosen products
				for (int j = 0; j < N; j++)
				{ // for loop 2 for 1st product out of 3 choosen products
					for (int k = 0; k < N; k++)
					{ // for loop 3 for 1st product out of 3 choosen products
						int[] remaining = {CPU, MEM, BRD};
						for (int x = 0; x <= MAXNUM[i]; x++)
						{ // inner loop to cover by taking product-1 out of choosen products from 0 to MAX possible if we take only this product
							if (!decrese(remaining, products[i], x))
							{
								break;
							}
							int y = 0;
							for (; y <= MAXNUM[j]; y++)
							{ // inner loop to cover by taking product-2 out of choosen products from 0 to MAX possible if we take only this product
								if (!decrese(remaining, products[j], y))
								{
									y++;
									break;
								}
								int z = 0;
								for (; z <= MAXNUM[k]; z++)
								{ // inner loop to cover by taking product-3 out of choosen products from 0 to MAX possible if we take only this product
									if (!decrese(remaining, products[k], z))
									{
										z++;
										break;
									}

									int current = x * products[i].v + y * products[j].v + z * products[k].v + remaining[0] * CPU_COST + remaining[1] * MEM_COST;
									MAX = Math.max(MAX, current);
									if (k < 2)
									{ // To cover N<3 cases
										z++;
										break;
									}
								}
								increse(remaining, products[k], z - 1);
								if (j < 1)
								{ // To cover N<3 cases
									y++;
									break;
								}
							}

							increse(remaining, products[j], y - 1);
						}
					}
					if (j >= N - 1) // To cover N<3 cases
						break;
				}

				if (i >= N - 2) // To cover N<3 cases
					break;
			}
			System.out.println("#" + t + " " + MAX);
			System.out.println("#time = " + (double)(System.currentTimeMillis() - time) / 1000);
		}
	}

private
	static boolean canProceed(int[] remaining)
	{
		if (remaining[0] < 0 || remaining[1] < 0 || remaining[2] < 0)
		{
			return false;
		}
		return true;
	}

private
	static void increse(int[] remaining, Pro pro, int x)
	{
		remaining[0] += pro.c * x;
		remaining[1] += pro.m * x;
		remaining[2] += pro.b * x;
	}

private
	static boolean decrese(int[] remaining, Pro pro, int i)
	{
		if (i != 0)
		{
			remaining[0] -= pro.c;
			remaining[1] -= pro.m;
			remaining[2] -= pro.b;
		}
		return canProceed(remaining);
	}

private
	static int findMax(Pro p)
	{

		if ((p.c * CPU_COST + p.m * MEM_COST) >= p.v)
		{
			return 0;
		}
		return Math.min(Math.min(BRD / p.b, CPU / p.c), MEM / p.m);
	}
}

My Code

#include <stdio.h>
	int D,
	E, F, d, e, n;
int mat_model[9][4];
int max_model[9];
int check(int a, int b, int c, int i, int j, int k)
{
	int retVal = 0;
	if (((mat_model[a][0] * i) + (mat_model[b][0] * j) + (mat_model[c][0] * k)) > D ||
		((mat_model[a][1] * i) + (mat_model[b][1] * j) + (mat_model[c][1] * k)) > E ||
		((mat_model[a][2] * i) + (mat_model[b][2] * j) + (mat_model[c][2] * k)) > F)
	{
		return 0;
	}
	int remD = D - ((mat_model[a][0] * i) + (mat_model[b][0] * j) + (mat_model[c][0] * k));
	int remE = E - ((mat_model[a][1] * i) + (mat_model[b][1] * j) + (mat_model[c][1] * k));
	retVal = (mat_model[a][3] * i) + (mat_model[b][3] * j) + (mat_model[c][3] * k) + remD * d + remE * e;
	return retVal;
}
int compute(int a, int b, int c)
{
	int val = 0;
	for (int i = 0; i < max_model[a] + 1; i++)
	{
		for (int j = 0; j < max_model[b] + 1; j++)
		{
			for (int k = 0; k < max_model[c] + 1; k++)
			{
				int cost = check(a, b, c, i, j, k);
				if (cost > val)
				{
					val = cost;
				}
			}
		}
	}
	return val;
}
int process()
{
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				int value = compute(i, j, k);
				if (value > ans)
				{
					ans = value;
				}
			}
		}
	}
	return ans;
}
int main()
{
	int T;
	freopen("Text.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d%d%d%d%d%d", &D, &E, &F, &d, &e, &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d%d", &mat_model[i][0], &mat_model[i][1], &mat_model[i][2], &mat_model[i][3]);
		}
		for (int i = 0; i < n; i++)
		{
			int x = D / mat_model[i][0];
			int y = E / mat_model[i][1];
			int z = F / mat_model[i][2];
			if (x < y && x < z)
			{
				max_model[i] = x;
			}
			else if (y < x && y < z)
			{
				max_model[i] = y;
			}
			else
			{
				max_model[i] = z;
			}
		}
		printf("#%d %d\n", test_case, process());
	}
}

Rare element 5

Samsung wants to explore some of the rare elements for its semiconductor manufacturing. Scientists use one vehicle to explore the region in order to find the rare elements. The vehicle can move only in explored region where roads have already been constructed. The vehicle cannot move on unexplored region where roads are not there.  In the current situation, rare elements are present in explored region only. Unexplored regions do not contain any rare elements.

Square region is provided for exploration. Roads are represented by 1 and where roads are not present that area is represented by 0. Rare elements will only be on the roads where regions have already been explored. Vehicle can move in four directions – up, down, left and right.

The shortest path for vehicle to a rare element position is called Moving Path. The longest of the paths to all rare elements from a region called Longest Distance. 

Scientists need to construct one research center so that the research center will be at the position where the longest path to the rare elements will be shortest. This is called Shortest Longest Distance.

Image 9

In the above picture (Fig. 1), Red, Blue and Green area represents Rare Element area. (2, 2) is represented as Red, (2, 8) is represented as Blue and (7, 8) is represented as Green. So there are three rare elements. 

If research center is constructed at (4, 4) then distance to Red rare element will be 4, distance to Blue rare element will be 6 and distance to Green rare element will be 7. So the Longest distance will be 7.

Image 10

Now using the same region (Fig. 2), if research center is constructed at (4, 5) then distance to Red rare element will be 5, distance to Blue rare element will be 5 and distance to Green rare element will be 6. So the Longest distance will be 6.
So when research center is constructed at (4, 5) then the longest distance will be shortest. And the value of the Shortest Longest Distance will be 6. This will be the output.
There can be multiple locations from where the shortest longest distance can be same. For example if research center is constructed at (5, 5) then still the Shortest Longest distance will be 6.
So write a program to find the Shortest Longest Distance.

Constraints:
The region provided will be square region i.e. NxN (where 5 <=  N <= 20).
There can be minimum of 2 rare elements and maximum of 4 rare elements, i.e. 2 <= C <= 4.
Roads are represented by 1 while no road area is represented by 0.
Vehicle can move only on roads in explored area.
The rare elements will only be present where road are there. Rare elements will not be present where roads are not present.
Vehicle can move in UP, DOWN, LEFT and RIGHT directions.
The starting index for rare element is considers as 1.
 

Input:
First line will be the number of test cases. Second line will indicate region area (N) and number of rare elements (C). Next C lines will contain the position of rare elements. After that N lines will provide the region details where to tell where roads are present and where roads are not present.
 
Output:
Output #testcase followed by space and then shortest longest distance.

Approach

Using BFS on each cell to find out the longest path among rare elements from the cell. Then find the smallest in these longest paths. That will provide the solution.
Few people solved using BFS from rare elements positions. More optimized.

/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>

int Answer = 9999;
int region[22][22];
int visited[22][22];
int N, C;
int location[5][2];
int rear = -1;
int front = -1;
struct queue
{
	int row;
	int col;
} Q[10000];

void init()
{
	int m, n;
	rear = -1;
	front = -1;
	for (m = 0; m < 22; m++)
	{
		for (n = 0; n < 22; n++)
		{
			visited[m][n] = 0;
		}
	}

	for (m = 0; m < 10000; m++)
	{
		Q[m].row = 0;
		Q[n].col = 0;
	}
}

void discover(int row, int col, int val)
{
	int l, m, k;
	int cnt = 0;

	for (k = 0; k < C; k++)
	{
		if (visited[location[k][0]][location[k][1]] > 0)
			cnt++;
	}
	if (cnt >= C)
		return;

	if ((row - 1) >= 1 && visited[row - 1][col] == 0 && (region[row - 1][col] == 1 || region[row - 1][col] == 3))
	{
		visited[row - 1][col] = val + 1;
		++rear;
		Q[rear].row = row - 1;
		Q[rear].col = col;
	}
	if ((row + 1) <= N && visited[row + 1][col] == 0 && (region[row + 1][col] == 1 || region[row + 1][col] == 3))
	{
		visited[row + 1][col] = val + 1;
		++rear;
		Q[rear].row = row + 1;
		Q[rear].col = col;
	}
	if ((col - 1) >= 1 && visited[row][col - 1] == 0 && (region[row][col - 1] == 1 || region[row][col - 1] == 3))
	{
		visited[row][col - 1] = val + 1;
		++rear;
		Q[rear].row = row;
		Q[rear].col = col - 1;
	}
	if ((col + 1) <= N && visited[row][col + 1] == 0 && (region[row][col + 1] == 1 || region[row][col + 1] == 3))
	{
		visited[row][col + 1] = val + 1;
		++rear;
		Q[rear].row = row;
		Q[rear].col = col + 1;
	}

	while (front < rear)
	{
		++front;
		discover(Q[front].row, Q[front].col, visited[Q[front].row][Q[front].col]);
	}
}

int main(void)
{
	int T, test_case;

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int i, j, k;
		int x, y, c;
		int temp = 0;
		Answer = 9999;

		scanf("%d%d", &N, &C);

		for (i = 0; i < C; i++)
		{
			scanf("%d%d", &x, &y);
			location[i][0] = x;
			location[i][1] = y;
		}

		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				scanf("%d", &region[i][j]);
			}
		}
		for (k = 0; k < C; k++)
		{
			region[location[k][0]][location[k][1]] = 3;
		}

		init();
		Answer = 9999;
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				init();
				temp = 0;
				if (region[i][j] == 1)
				{
					visited[i][j] = 1;
					discover(i, j, 1);
					for (k = 0; k < C; k++)
					{
						if (temp < visited[location[k][0]][location[k][1]])
							temp = visited[location[k][0]][location[k][1]];
					}
					if (Answer > temp)
						Answer = temp;
				}
			}
		}

		// Print the answer to standard output(screen).
		printf("#%d %d\n", test_case + 1, Answer - 1);
	}

	return 0; // Your program should return 0 on normal termination.
}

Input

	2 5 2 4 3 3 4 1 1 0 0 0 1 1 0 0 0 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 8 2 5 6 6 4 1 1 1 1 1 1 0 0 1 1 1 1 1 1 1 0 1 1 0 1 0 1 1 0 1 1 1 1 0 1 1 0 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 15 4 11 15 15 9 1 2 14 3 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 0 1 1 0 1 0 0 0 1 0 0 0 0 1 1 0 1 1 0 1 0 0 0 1 0 0 0 0 1 1 0 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 0 0 0 1 0 0 0 0 1 1 0 1 1 0 1 0 0 0 1 1 1 1 1 1 1 1 1 1 0 1 0 0 0 1 0 0 0 0 1 1 0 1 1 0 1 0 0 0 1 0 0 0 0 1 1 0 1 1 0 1 0 0 0 1 0 0 0 0 1 1 0 1 1 0 1 0 0 0 1 0 0 0 0 1 1 0 1 1 0 1 0 0 0 1 0 0 0 0 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 0 0 0 1 1 1 1 1 1 1 0 1 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 20 4 13 6 20 4 1 2 17 16 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1 1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1 1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1 1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1 1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1 1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1 1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1 1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0

	Output
# 1 1
# 2 2
# 3 2
# 4 12
# 5 15

		My code

#include <iostream>
	using namespace std;
int n, c;
int rare[4][2] = {0};
int region[21][21] = {0};
int visited[21][21] = {0};
int queue[100000][2] = {0};
int front = -1;
int rear = -1;
void function(int x, int y, int val)
{
	int count = 0;
	for (int i = 0; i < c; i++)
	{
		if (visited[rare[i][0]][rare[i][1]] > 0)
			count++;
	}
	if (count >= c)
		return;

	if (((x + 1) <= n && visited[x + 1][y] == 0) && (region[x + 1][y] == 1 || region[x + 1][y] == 3))
	{
		visited[x + 1][y] = val + 1;
		rear++;
		queue[rear][0] = x + 1;
		queue[rear][1] = y;
	}
	if (((y + 1) <= n && visited[x][y + 1] == 0) && (region[x][y + 1] == 1 || region[x][y + 1] == 3))
	{
		visited[x][y + 1] = val + 1;
		rear++;
		queue[rear][0] = x;
		queue[rear][1] = y + 1;
	}
	if (((x - 1) > 0 && visited[x - 1][y] == 0) && (region[x - 1][y] == 1 || region[x - 1][y] == 3))
	{
		visited[x - 1][y] = val + 1;
		rear++;
		queue[rear][0] = x - 1;
		queue[rear][1] = y;
	}
	if (((y - 1) > 0 && visited[x][y - 1] == 0) && (region[x][y - 1] == 1 || region[x][y - 1] == 3))
	{
		visited[x][y - 1] = val + 1;
		rear++;
		queue[rear][0] = x;
		queue[rear][1] = y - 1;
	}
	while (front < rear)
	{
		front++;
		function(queue[front][0], queue[front][1], visited[queue[front][0]][queue[front][1]]);
	}
}

void init_visited()
{
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			visited[i][j] = 0;
		}
	}
	return;
}

void init_queue()
{
	for (int i = 0; i < 100000; i++)
	{
		queue[i][0] = 0;
		queue[i][1] = 0;
	}
	rear = -1;
	front = -1;
}

void init_region_rare()
{
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			region[i][j] = 0;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		rare[i][0] = 0;
		rare[i][1] = 0;
	}
	return;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> n >> c;
		init_region_rare();
		for (int i = 0; i < c; i++)
		{
			cin >> rare[i][0] >> rare[i][1];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> region[i][j];
			}
		}
		for (int i = 0; i < c; i++)
		{
			region[rare[i][0]][rare[i][1]] = 3;
		}
		int smol = 99999;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				init_visited();
				init_queue();
				if (region[i][j] == 1)
				{
					visited[i][j] = 1;
					function(i, j, 1);
					int big = 0;
					for (int a = 0; a < c; a++)
					{
						if (visited[rare[a][0]][rare[a][1]] > big)
							big = visited[rare[a][0]][rare[a][1]];
					}
					if (smol > big)
						smol = big;
				}
			}
		}

		cout << "#" << t + 1 << " " << smol - 1 << endl;
	}
}

1
5 2
1 5
3 4
1 1 0 1 1
1 1 0 1 0
1 1 1 1 1
1 1 1 0 1
1 1 1 1 1




Robot car fueling 7

There are N cars parked in a row in a parking lot of the newly  constructed club. as it is demonstrated in the picture below.

Image 11

There is a gasoline and diesel fueling station installed.at the left and right side of the park.
An automatic fueling robot  carries the fuel from station and fill up the parked car with fuel.The cars are divided into 2 types depending on whether it is a gasoline or diesel car.
1 is denoted as gasoline cars and 2 is denoted as diesel cars.
The automatic robot will be used to provide a cost free fueling service which is filling up  all cars with 1 litre of each corresponding fuel.
The robot will move in between the 2 fuelling stations as below :   1) The robot carries 2 litre of gasoline at the gasoline station and starts moving from there. 2) The robot can fill up the cars of the same type of gas it carries 1 litre each. 3) The robot can go back to the fuelling station at any time, Independent from the current amount of fuel it carries. 4) When the robot arrives at the fuelling station, it gets 2 litre of supply of the corresponding fuel.(If the robot has some remaining fuel it will be discarded).

5) There is an equal distance of 1 between each fueling station and the cars.

The fuel type of N Cars parked in the parking lot will be given.
Find the minimum moving distance of the automated fueling robot after it has filled up all the cars with 1 litre  of fuel each.

Time limit: C/C++/Java: 3 seconds. 
Test cases: 50
2<=N<=8
I/P format:
2  Total number of test cases
5  N(Number of cars between gasoline and Diesel stations)
1 2 1 2 1(1 Gasoline car, 2Diesel cars)
5
2 1 1 2 1

O/P:
# 1 12
# 2 14
Example 1)  Given the total number of cars N = 5 and the order of the parked cars such as G - D - G - D - G  (PS: G-> Gasoline, D->Diesel)
the process of finding the minimum moving distance for fueling the car is as follows :  

Image 12
Image 13
Image 14
Image 15 

Solution

We should always start from the Gasoline station.
Once we fuel any car, we have 3 options to perform.
	1) Fuel next car(gasoline or Diesel car, with all the combinations)
	2) Go to Gasoline station and start refueling 
	3) Go to Diesel station and start fueling. 
Keep updating the distances as we move, once all cars are over, store  result in global variable , if we find optimal distance with the current combination than the previous combinations.

#include <stdio.h>
#include <string.h>
#define MAX 9
int arr[MAX];
int visited[MAX];
int tdistance = 99999;
void calc_min(int n, int distance, int rem, int pindex, int cars, int ins, int g_or_d)
{
	int i;
	if (cars == n)
	{
		if (tdistance > distance)
		{
			tdistance = distance;
		}
		return;
	}
	if (rem <= 0)
		return;
	if (ins == 0 && g_or_d == 0)
	{
		int k;
		for (k = 1; k <= n; k++)
		{
			if (!visited[k] && arr[k] == 1)
			{
				visited[k] = 1;
				// go to next gas car
				calc_min(n, distance + (k > pindex ? k - pindex : pindex - k), rem - 1, k, cars + 1, 0, 0);
				// go to gas station
				calc_min(n, distance + (k > pindex ? k - pindex : pindex - k), 2, k, cars + 1, 1, 0);
				// go to diesel station
				calc_min(n, distance + (k > pindex ? k - pindex : pindex - k), 2, k, cars + 1, 2, 0);
				visited[k] = 0;
			}
		}
	}
	if (ins == 0 && g_or_d == 1)
	{
		int k;
		for (k = n; k >= 1; k--)
		{
			if (!visited[k] && arr[k] == 2)
			{
				visited[k] = 1;
				// go to next gas car
				calc_min(n, distance + (k > pindex ? k - pindex : pindex - k), rem - 1, k, cars + 1, 0, 1);
				// go to gas station
				calc_min(n, distance + (k > pindex ? k - pindex : pindex - k), 2, k, cars + 1, 1, 1);
				// go to diesel station
				calc_min(n, distance + (k > pindex ? k - pindex : pindex - k), 2, k, cars + 1, 2, 1);
				visited[k] = 0;
			}
		}
	}
	if (ins == 1)
	{
		// fill gas and recall
		calc_min(n, distance + (pindex - 0), 2, 0, cars, 0, 0);
	}
	if (ins == 2)
	{
		// fill diesel and recall
		calc_min(n, distance + ((n + 1) - pindex), 2, n + 1, cars, 0, 1);
	}
}
int main(void)
{
	int T, test_case;
	int n;
	int i;
	freopen("inp.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &arr[i]);
		}
		calc_min(n, 0, 2, 0, 0, 0, 0);
		if (tdistance == 99999)
		{
			// May be all cars are diesel cars, go to diesel bunk and fuel it from there
			calc_min(n, n + 1, 2, n + 1, 0, 0, 1);
		}
		printf("Case #%d %d\n", test_case + 1, tdistance);
		tdistance = 99999;
	}
	getch();
}

Approach 2

	Robot has Two Functions in the problem statement
		Robot @Pump
			Fill 2 Units of Fuel
				Move in next direction
					Increment count
						Robot @Car
							If fuel carried by robot and car not same
								increment count
									If fuel carried by robot and
	car is same same 3 decisions
		Don’t fill Fuel,
	continue to next car
			Fill the fuel and continue to next car
				Fill the fuel and continue backward
					Increment count
						Pseudo Algorithm

							If it is a Pump
								Fill 2 Units of Fuel
									Move in next
									direction(Gasoline right / Diesel left)
										Increment count
		If it is a Car
		If fuel carried by robot and car not same
		increment count
		move next
		If fuel carried by robot
		and car is same and empty if this is last car note the count return Don’t fill Fuel,
	continue to next spot
	Fill the fuel and continue to next spot
	Fill the fuel and continue backward

	Solution is attached :
#include <stdio.h>
#include <time.h>
#define GAS 1
#define DIESEL 2
#define NOTHING 0
#define RIGHT 1
#define LEFT -1
#define SPOT 10

	int A[SPOT];
int min;
struct Cars
{
	int Visited[SPOT];
	int nc; // no of cars
};

void fill(int step, int direction, int fuel, int quantity, int count, int cars_left, struct Cars station)
{
	if (count == min)
		return;
	if (step == 0)
	{ // GASOLINE station
		fill(1, RIGHT, GAS, 2, count + 1, cars_left, station);
		return;
	}
	if (step == SPOT - 1)
	{ // DIESEL station
		fill(SPOT - 2, LEFT, DIESEL, 2, count + 1, cars_left, station);
		return;
	}
	if (A[step] == 0)
	{ // spot not occupied by any car count does not increase
		fill(step + direction, direction, fuel, quantity, count, cars_left, station);
	}
	if (A[step] == fuel && station.Visited[step] == 0 && quantity > 0)
	{ // fill
		station.Visited[step] = 1;
		if (cars_left == 1)
		{
			if (count < min)
				min = count;
			return;
		} // go forward
		fill(step + direction, direction, fuel, quantity - 1, count + 1, cars_left - 1, station);
		// go back direction
		fill(step - direction, -(direction), NOTHING, 0, count + 1, cars_left - 1, station);
		// don't fill and go forward
		station.Visited[step] = 0;
		fill(step + direction, direction, fuel, quantity, count + 1, cars_left, station);
	}
	else
	{ // Already filled
		fill(step + direction, direction, fuel, quantity, count + 1, cars_left, station);
	}
}

int main()
{
	int T, i;
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		struct Cars station;
		int j;
		min = 65530; // reset  all data
		for (j = 0; j < SPOT; j++)
		{
			A[j] = 0;
			station.Visited[j] = 0;
		} // read ip
		scanf("%d", &station.nc);
		for (j = 1; j <= station.nc; j++)
		{
			scanf("%d", &A[j]);
		}
		fill(0, RIGHT, GAS, 2, 0, station.nc, station);
		fill(0, RIGHT, NOTHING, 2, 0, station.nc, station);
		printf("%d %d\n", i + 1, min);
	}
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("%f", cpu_time_used);
	return 0;
}

Rock climbing 8

There is a man who wants to climb a rock from a starting point to the destination point. Given a map of the rock mountain which N = height, M = width. In the map, character '-' is the possible foot place spot (where can climb).
He can freely move up/down at vertical spots which '-' exists sequentially. It's impossible to move horizontally in case there is more than one space between '-' in the same height level.
Depending on how high/low he moves towards the upper or lower direction at one time, the level of difficulty of rock climbing gets determined.
The maximum height of moving from the starting point to destination point is the level of difficulty of rock climbing .
The total distance of movement is not important. There are more than one path from the starting point to destination point. => Output: The minimum level of difficulty of all rock climbing paths level.
Hint: Start with difficulty level 0 and then keep increasing it one by one.


DFS with recursion
BFS can also be used with increase in code complexity
Few people solved it with Backtracking as well (not advised though)
If the visited array is marked as “steps_count” under consideration, then we need not initialize the visited array with 0 for every “step_count”.
Attached is DFS solution with TC generation as well as timing calculation

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50

clock_t start, end;
double cpu_time_used;

int matrix[MAX_SIZE][MAX_SIZE];
int visited_matrix[MAX_SIZE][MAX_SIZE];

int move[4][2] = {
	1, 0,
	-1, 0,
	0, -1,
	0, 1};

int check_for_level(int dest_x, int dest_y);
int check_for_last_row(int dest_x, int dest_y, int level);

int row = 0;
int col = 0;

int prob(int x)
{
	if (rand() % 100 < x)
		return 1;
	else
		return 0;
}

void init_visited_matrix()
{
	int i, j;
	for (i = 0; i < MAX_SIZE; i++)
		for (j = 0; j < MAX_SIZE; j++)
			visited_matrix[i][j] = 0;
}

void print_matrix(int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}

int main()
{
	srand(10);
	int i, j, m, n, p, t, ans, loc_x, loc_y;
	int tc = 50;
	start = clock();
	for (t = 0; t < tc; t++)
	{
		m = 20 + rand() % 30;
		n = 20 + rand() % 30;

		// For safety, fill the whole matrix with -1 to start with
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				matrix[i][j] = -1;

		// Fill the left corner with 2
		matrix[m - 1][0] = 2;

		// Fill the last line with all 1
		for (i = 1; i < n; i++)
			matrix[m - 1][i] = 1;

		// Pick a random location and fill it with 3
		loc_x = rand() % m;
		loc_y = rand() % n;
		matrix[loc_x][loc_y] = 3;

		// pick a random probability between 40 to 60 to fill with 1
		p = 0 + rand() % 20;

		// fill the rest of the matrix with 1s and 0s with probability p

		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
			{
				if (-1 == matrix[i][j])
				{
					if (prob(p))
						matrix[i][j] = 1;
					else
						matrix[i][j] = 0;
				}
			}
		row = m;
		col = n;
		// print_matrix(m,n);

		ans = check_for_level(loc_x, loc_y);

		// printf("Row %d Col %d Loc_x %d Loc_y %d\n", m, n, loc_x, loc_y);
		printf("Case#%d: %d\n", t, ans);
	}
	end = clock();
	cpu_time_used = ((double)(end - start));
	printf("%lf\n", cpu_time_used);
	return 0;
}

int check_for_level(int dest_x, int dest_y)
{
	int level = 1;
	while (1)
	{
		init_visited_matrix();
		visited_matrix[dest_x][dest_y] = 1;
		if (1 == check_for_last_row(dest_x, dest_y, level))
		{
			return level;
		}
		level++;
	}
}

int check_for_last_row(int dest_x, int dest_y, int level)
{
	if (dest_x == row - 1)
		return 1;

	int k, temp_x, temp_y;
	for (k = 0; k < (2 + 2 * level); k++)
	{
		if (k < 4)
		{
			temp_y = dest_y + move[k][1];
			temp_x = dest_x + move[k][0];
		}
		else
		{
			temp_y = dest_y;
			temp_x = dest_x + (k / 2) * move[k % 2][0];
		}
		if (temp_x >= 0 && temp_y >= 0 && temp_x < row && temp_y < col)
		{
			if (matrix[temp_x][temp_y] == 1 && visited_matrix[temp_x][temp_y] == 0)
			{
				visited_matrix[temp_x][temp_y] = 1;
				if (1 == check_for_last_row(temp_x, temp_y, level))
					return 1;
			}
		}
	}
	return 0;
}

Errors

		Executed DFS from source and destination both at the same “step_count”.This can lead to error as it can now jump 2 *
	step_count.Did not change the visited array properly after incrementing the “step_count”
		Tried to jump only the current “step_count” in consideration.You should consider all the steps from 0 to “step_count” in every loop.

	50 1 31 29 0 0 1 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0 0 1 0 0 1 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 1 0 0 0 0 1 0 0 0 0 0 1 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 1 0 1 1 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 1 1 0 0 0 1 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 1 0 1 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 3 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 0 0 1 1 0 1 0 0 0 1 1 0 0 0 0 0 1 0 1 1 0 1 0 0 1 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 1 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 1 0 0 1 1 0 1 0 0 1 0 0 0 0 0 1 1 0 1 0 0 0 0 0 0 0 0 1 0 1 0 1 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 1 1 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 1 0 0 0 0 0 1 0 0 1 0 0 0 0 1 0 1 0 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	49 32

	0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	46 37

	1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 1 0 0 1 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 1 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 1 1 0 0 0 1 0 0 0 0 0 0 0 1

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 1 0 0 0 0 0 0 0 1 0

	1 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 1 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 3 0 0 1 0 0 0 0 1 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 1 0 0 1 0 0 0 0 0 1 0 1 0 0 0

	0 1 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 1 0 0 0 1 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 1 0 1 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 1 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0

	0 0 0 1 0 0 1 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 1 1 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	48 21

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1

	0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1

	0 0 0 0 0 1 0 1 0 1 0 0 0 0 1 0 0 0 1 0 0

	1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 1 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 1 0 1 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	3 1 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0

	1 1 0 0 1 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 1 0 1 0 0 0 0 1 0 0

	1 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0

	0 1 0 0 0 1 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 1 1 0 0 1 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	1 0 0 0 1 0 0 0 0 0 0 1 0 0 1 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1

	1 0 0 0 0 1 0 1 1 0 1 0 0 1 0 1 0 0 1 1 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0 0

	1 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 1 0 0 1 0 0 0 1 0 0 0 0 0 1 0

	0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 1 1 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 1 1 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0

	0 1 1 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 1 0 1 0 0 0 1 1 0 0

	0 0 0 0 0 0 1 0 0 1 0 0 1 0 0 0 0 0 0 0 1

	0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 1 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 1

	0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 1 0 0 0 1 0 0 1 0 0 1 0 1 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 1 0 0

	1 0 0 0 1 1 0 0 1 0 0 0 0 1 0 0 0 0 1 0 0

	1 0 1 1 0 0 0 0 1 0 0 0 1 0 0 1 0 1 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	23 25

	1 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	1 1 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0

	1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0

	0 0 0 1 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1

	1 0 0 1 0 1 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0

	0 0 0 1 1 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 1 0 0 1 0 0 1 0 0 0 0 0 1 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 1

	0 0 0 1 1 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 1 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 1 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	3 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 1 1 0 1 0 0 0 1 1

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 1

	0 0 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	29 49

	0 0 1 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 1 1 0 1 0 0 0 0 0 1 1 0 0 1 0 0 0 0 1 0 0 0 0 0 1 0 0 1 0 0

	0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 1 0 0 0 0 1 0

	0 0 0 0 0 0 0 1 1 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 1 0 1 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 1

	1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 1 0 1 0 0 1 0 0 1 1 1 0 0 0 0 0 1 1 0 0 0 0 0 0 1 0 0 0

	1 1 0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 3 0 0 0 0 0 0 0 0 1 1 0 0 0 0 1 1 0 1 0 0 1 1 0 0

	1 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 1 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 1 0 1 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 1 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 1 0 0 0 0 0 0

	1 0 0 0 1 0 0 0 0 0 0 1 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 1 0 0 0 0 0 1 0 1 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 1 1 0 1 0 1 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0

	0 0 1 1 0 1 0 0 1 0 0 0 0 1 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 1 1 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 1 1 0 0 1 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 1 1 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0

	1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 1 0 0 0 1 1 0 0 0 0 0 1 0 0 1 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 1 0 1 1 1 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 1 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 1 0 0 1 0 1 0 1 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	38 48

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 1

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0

	0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 1

	1 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 1 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 3 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	20 33

	0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 1 1 0 0 1 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 1 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 1 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	1 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 1 0 0 0 1 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 1 1 1 0

	1 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 1 1 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 1 1 0 0 0 0 0 1

	0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0

	0 0 1 0 0 1 0 0 1 0 0 0 0 0 1 0 0 1 0 1 0 0 1 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 0 1 0 0 0 0 0 0 0 0 1 1

	0 0 1 1 0 0 0 0 0 0 1 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 1 0 0 1 0 0 0 0

	0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 3 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	21 39

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 3 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	30 40

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 1 1 1 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0

	0 1 0 1 1 0 0 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 1 0 1 0 0 0 0 1 0 0

	0 1 0 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 1 0 0 0 0

	1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 1 0 0 0 1 0 0 0 0 0 1 0 1 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 1 0 1 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 0 1 1

	0 1 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 1 0 1 0 1 3 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 1 1 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 1 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 1 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 1 1 1 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	26 46

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 1 0 0 0 0 0 0 0 0 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	36 33

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 1 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	27 23

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 3

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	48 41

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 1 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 1 0 0 0 0

	1 0 0 1 0 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 1 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 1 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 3 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 1 1 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 1 0 0 0 1 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 1 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 1 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	22 46

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	49 30

	0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 1 0 0 0 1 0 1 0 0 1 0

	0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 1 0 0 0 1 0 0 1 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0

	0 1 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 1 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 1 1 0 0 0 0 0 0 1 1 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0

	0 1 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0

	0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 1 0 1 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 1 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 1

	0 0 0 1 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 3 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0

	1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 1 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 1 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0

	1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 1

	0 1 1 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	1 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	27 48

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0

	0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 3 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	21 43

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 1 0 1 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 1 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 1 1 0 1 1 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1

	1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 1 0 0 0 0 1 0

	0 0 1 0 0 0 0 0 1 1 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0

	1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 1 1 0 1 1 0 0 0 0 0 0 0 1 0 0 1 0 1 0 1 0 0 0 0 0 0 1 0 0 0 0 1 0 1 1 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 3 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 1 1 0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 1 0 1 0 1 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 1 0 0 1 0 0 1 0 0 0 0 1 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0

	1 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1 1 0 0 0 0 0 0

	0 1 1 0 1 0 0 0 1 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 1 0 0 0 1 0 0 0

	0 0 0 0 1 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 1

	0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	37 35

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 1 0 1 0 0

	1 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 1 0 1 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 1 0 0 0 0 3 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	1 1 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 1 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 1 0 0 1 1 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	1 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	1 0 1 1 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 1 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0

	0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	22 24

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 3 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	46 31

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0

	1 0 0 0 0 0 0 1 0 0 0 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 1 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 1 0 1 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 0 1 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	43 36

	0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 1 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 1 0 0 1 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 1 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 1 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 1 1 0 0 0 1 1

	0 3 1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 1 1 1 0 0 0 1 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 1 1 0 0

	0 1 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 1 0 0

	1 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 1 0 0 1 1 0 0 0 0

	0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 1 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 1 0 0 0 0 1 1

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 1 0 0 0 1 0 1 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 1 0 0 0 0 0 0 1

	1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1

	1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 1 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 1 1

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 1 0 0 0 1 0 0 0

	1 0 0 1 0 0 0 1 1 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 1 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 1 0

	0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0 0 0 1 0 1

	0 1 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 1 1 0 1 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 1 1 0 1 0 0 0 0 0 1 0 0 0 0 1

	0 0 0 0 0 1 0 1 0 0 1 0 0 0 0 1 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 0 0 0 1

	0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 1

	0 1 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	22 36

	0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 1 1 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 1 0 1 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 1 0 1 0

	0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 1 0 0 0 0 0 0 1 0 0 1 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0

	0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0

	0 0 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0

	0 0 0 1 1 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 1 1 0 0 0 1 1 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1

	0 1 1 0 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0

	0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 3 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	30 23

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1 1 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 1 0 1 0 0 0 0 0 0 0 1 0 1

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 1 0 0

	1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 1 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 1 0 0 1 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 3 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	31 44

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 3 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	45 24

	0 1 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 1 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 1 0 0 0 0 0 0 0 1 1 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 3 0 0 1 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 1 0

	0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 1 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 1 1 0 0 0 0 0 0 1 0 0

	1 0 0 1 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 1 0 0 0

	0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 1 1 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 1 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	1 1 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 1 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	33 49

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 1 0 0 1 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 1 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0

	0 0 0 0 0 0 0 0 1 1 0 0 1 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 1 1 1 0

	0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 1 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 1 0 1 0 0 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 1

	0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 1 1 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 1 0 1 0 0 0 0 0 1 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 3 0 0 0 0 1 0 0 0 0 0 0 1 0 1 0 0 1 0 0 0 1 0 0

	0 0 0 0 1 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 1 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 1 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 1 0 0 0 1 1 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 1 0 1 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 1 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	31 44

	0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 1 0 1 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 1 0 0 1 0 1 0 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 1 0 0 0 0

	0 1 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	1 1 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 1 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 1 0 0

	0 1 0 0 0 0 0 0 1 0 0 1 1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	1 1 0 0 1 1 1 0 0 0 0 0 0 0 0 1 1 0 0 0 1 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1

	0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 1 0 0 0 1 1 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 1 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0 1 0 0 0 0 0 0 0 1 1 1 0 1 0 0 0 0 0 0

	1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 1 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 1 0 1 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 1

	0 1 0 1 0 0 0 0 0 0 0 1 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 1 0 1 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 1 0 0 1 0 0 1 1 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 1 0 1 0

	0 0 0 0 1 0 1 0 0 0 0 1 1 3 0 0 0 0 0 1 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 0

	0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	41 46

	0 0 0 0 0 0 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 1 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 1 0 0 0 0 0 0 1 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 1 0 0 1 0 0 0 1 0 0 1 0 0 0

	0 1 0 0 1 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 1 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	41 21

	1 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 1 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 1 0 1 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0

	0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 3 0 0

	0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	35 22

	0 1 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0

	1 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 1 1 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 1

	0 1 1 0 0 1 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 1 0 0 1 0 0 0 0 0 1 1 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 1 0

	0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 1 0 0 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1 0 1 0 1 0 0

	0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 1 0 0 0 0 1 0

	0 1 1 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0

	0 1 0 0 1 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 1 0 1 1 0 0 1 0 0 0 0 0 1 0 0 0 0

	0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 1 0

	0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 1 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 3 0 0 0 0 1 1

	0 0 0 0 0 0 1 0 0 0 1 1 0 0 0 1 0 0 0 0 0 1

	0 1 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 1

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	49 27

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0

	0 0 0 1 0 0 0 0 1 0 0 0 1 1 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 1 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 3 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0

	0 0 0 1 0 0 0 0 0 0 1 0 0 1 0 0 1 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 1 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 1 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	31 42

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 3 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 1 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 1 1 0 0 0 0 0 1 0 1 0 1 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 1 1 0 0 0 0 0 0 0 1 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	35 41

	0 0 0 0 0 0 0 0 0 0 1 1 0 1 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 1 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 1 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0

	1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 1 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 1 0 0 0 1 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 1 0 0 0 0 1 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 3 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	23 23

	0 1 1 0 0 0 1 0 1 0 0 0 0 1 0 0 1 0 0 0 0 1 0

	0 0 0 0 0 1 1 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 1

	0 1 0 0 0 1 0 0 0 0 0 1 0 0 0 1 0 0 0 1 0 0 1

	0 0 0 0 0 0 0 0 1 1 0 1 0 0 0 0 0 0 0 1 0 1 0

	0 0 1 0 0 0 3 0 1 0 1 0 1 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 1 0 0 0 1 0 0 0 1 0 0 0 0

	0 0 0 1 0 0 1 0 0 1 0 0 0 0 0 0 1 0 1 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 1 0 0 0 1 1 0 0

	1 0 0 0 1 1 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 1 1 1 0 0

	0 1 0 0 0 0 1 1 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0

	0 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 1 1

	0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 1 0 0 0 0 1 1 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 1 0 1

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 1 0

	1 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 1 0 0 0 1 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	44 27

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 3 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	44 45

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 3 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0

	1 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	27 35

	0 0 0 0 0 1 1 0 0 0 0 0 0 1 0 0 0 0 1 0 1 1 1 0 0 0 0 1 0 0 0 0 1 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 1

	0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0

	0 0 1 0 1 0 0 0 1 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0

	1 0 0 1 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 1 1 0 0 0 3 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	1 0 0 0 0 0 0 1 1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 1 0 0 0 1 0 0 0 0 1 0 0 1 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 1 0

	0 0 0 0 1 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0 0 1 0 0 0 0 0

	0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 1 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 1 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 1 1 0 0 0 0 0 1 1 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 1 0 0 0 1 0 1 0 0 0 0 0 0

	1 1 1 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 1 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 1 0 0 1 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 1 0 0 1 0 0 0 0 1 0 0 1 0 1 0 1 1 0 0 1 0 0 0 0 0 0 1 0 0

	1 0 1 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 1 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	24 39

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 3 0 0 1 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	33 22

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 1

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 1 0

	0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 1 0

	0 0 0 0 0 0 1 1 1 0 0 1 0 0 0 0 1 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0

	0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 1 1

	0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 1 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 1

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 1 0 0 0 1

	0 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 0 0 0 0 0

	0 1 0 0 0 1 1 0 0 0 0 0 0 3 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	22 25

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 1 0

	0 0 0 0 0 1 0 0 1 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 1 1 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 1

	1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 1 3 0 0 0 0 0 0 0 0 1 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 1 1 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 1 0 0 0 1 0 0 0 1

	1 1 1 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 1 0 0 1 0 0

	1 0 0 0 1 0 1 0 1 1 1 1 0 0 0 0 0 0 0 0 0 1 1 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1

	0 0 1 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	20 25

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 3 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 1 0 1 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1

	0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	26 27

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 3 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 1 0 0 0 1 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 1 1 0 0

	0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 1 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 1 1 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 1 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	22 32

	0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0

	1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 1 0 0 0 0 0 0

	1 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 3 0 1 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 1 0 1 0 1 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	1 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 1 1 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 1 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 0 1 0 1 0 1 0 1 0 0 0 0 0

	0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	35 40

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 3 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 1 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	47 43

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 1 0 0 0 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 1 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 1 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	43 45

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	1 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 3 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	45 46

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 3 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	26 47

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0

	2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	41 32

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0

	0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 1 0 0 1

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0

	1 0 0 0 0 0 0 0 0 0 0 0 0 0 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

# 1 9
# 2 43
# 3 27
# 4 9
# 5 5 / 10
# 6 6
# 7 1
# 8 1
# 9 1
# 10 5
# 11 19
# 12 9
# 13 7
# 14 15
# 15 8
# 16 5
# 17 7
# 18 9
# 19 11
# 20 14
# 21 25
# 22 9
# 23 1
# 24 14
# 25 3
# 26 28
# 27 6
# 28 2
# 29 27
# 30 16
# 31 2
# 32 15
# 33 17
# 34 1
# 35 5
# 36 31
# 37 28
# 38 5
# 39 5
# 40 1
# 41 5
# 42 12
# 43 19
# 44 7
# 45 22
# 46 18
# 47 18
# 48 42
# 49 6
# 50 21

	Sales booth 9

	Samsung wants to introduce the promotions in mobile sale.They want to setup a booth to sell mobile phones.They will club all areas of same mobile model with 1 single booth.In
	areas(marked zero),
	where Samsung mobile is not established, they will consider selling the mobiles that are famous in adjacent areas of higher configuration.We are given N *N matrix which can have a number between 0 and 5.

												 5 5 1 4 4 4 0 2 4 2 5 0 0 2 0 5 4 3 0 1 1 3 3 2 1

												 5 5 1 4 4 4 5 2 4 2 5 5 5 2 2 5 4 3 3 1 1 3 3 2 1

												 In this case,
	11 independent clusters are formed.This means 11 booths have to be setup.

	We need to consider selling the mobile that are famous in adjacent areas.In below case,
	count is like this:
S3 mobile – 3
S2 mobile – 2
S1 mobile – 2

As S3 is famous in neighboring area, so S3 will be considered for selling at this location.

 	 	2	0
4	3	0	1
3	3	2	1

Problem Analysis:
We need to find clusters of Samsung mobiles around the place where Samsung mobile is not established yet ( marked 0 in matrix). After finding clusters, we can choose the famous handset of higher configuration. 

Let’s take below example, 

5	5		
4	0	2	
5	0	0	2
5	4	3	 
 	3	3	

While calculating for 0 located at (1,1) position in matrix, we need to find clusters around all the 0s which are connected with each other. For this group of 0, we can find clusters of Samsung mobiles around it and replace these 0s with famous mobile having highest configuration.

We can calculate cluster using BFS or DFS.  For above case, we will find below clusters around these 0s:

S5 Mobile – 4(Marked in Orange)
		S4 Mobile
	- 2(marked in red)S3 Mobile – 3 S2 Mobile – 2 S1 Mobile - 0

	Highest configuration famous mobile is S5; hence we can replace these 0s with S5 mobile.

5	5		
4	5	2	
5	5	5	2
5	4	3	 
 	3	3	

Approaches to the problem of traversal:

1)	Recursive Depth-first Search:
Find clusters around “Zero” or “Group of Zeros” which are connected using recursive DFS approach. Its simple approach using recursive Calls. However, it would be little slow as compare to other two approaches. DFS solution is given by Sasi. (Source: from sasi folder)

// GalaxyYesSix.cpp : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_N 100

char adjM[MAX_N + 1][MAX_N + 1];
char resM[MAX_N + 1][MAX_N + 1];
char visitedZ[MAX_N][MAX_N];
char visitedN[MAX_N][MAX_N];
char visitedRepZ[MAX_N][MAX_N];
char visitedRes[MAX_N][MAX_N];

#define TOP(i, j, x, y) (x = i - 1, y = j);
#define LEFT(i, j, x, y) (x = i, y = j - 1);
#define RIGHT(i, j, x, y) (x = i, y = j + 1);
#define BOTTOM(i, j, x, y) (x = i + 1, y = j);

#define DFS_Z_SUB_COND                                   \
	if ((x >= 0 && x < N) && (y >= 0 && y < N))          \
	{                                                    \
		if ((adjM[x][y] == 0) && (!visitedZ[x][y]))      \
		{                                                \
			applyDFS_Z_Sub(x, y);                        \
		}                                                \
		else if ((adjM[x][y] != 0) && (!visitedN[x][y])) \
		{                                                \
			applyDFS_N(x, y, adjM[x][y]);                \
		}                                                \
	}

#define DFS_N_COND(adjMat, num, funcDFS, visited)        \
	if ((x >= 0 && x < N) && (y >= 0 && y < N))          \
	{                                                    \
		if ((adjMat[x][y] == (num)) && (!visited[x][y])) \
		{                                                \
			funcDFS(x, y, (num));                        \
		}                                                \
	}

#define DFS_Z_REPLACE_COND(num, resMat)                  \
	if ((x >= 0 && x < N) && (y >= 0 && y < N))          \
	{                                                    \
		if ((resMat[x][y] == 0) && (!visitedRepZ[x][y])) \
		{                                                \
			applyDFS_Z_replace(x, y, (num));             \
		}                                                \
	}

int maxArr[MAX_N + 1];
int N;
int boothCnt;

int findMaxElem()
{
	int i;
	int max = 0;
	int num;
	for (i = 1; i <= MAX_N; i++)
	{
		if (maxArr[i] >= max)
		{
			max = maxArr[i];
			num = i;
		}
	}

	return num;
}

void applyDFS_Z_replace(int i, int j, int num)
{
	int x, y;
	visitedRepZ[i][j] = 1;
	resM[i][j] = num;

	// Top
	TOP(i, j, x, y)
	DFS_Z_REPLACE_COND(num, resM)

	// Left
	LEFT(i, j, x, y)
	DFS_Z_REPLACE_COND(num, resM)

	// Right
	RIGHT(i, j, x, y)
	DFS_Z_REPLACE_COND(num, resM)

	// Bottom
	BOTTOM(i, j, x, y)
	DFS_Z_REPLACE_COND(num, resM)
}

void applyDFS_N(int i, int j, int elem)
{
	int x, y;

	visitedN[i][j] = 1;
	maxArr[elem]++;

	// Top
	TOP(i, j, x, y)
	DFS_N_COND(adjM, elem, applyDFS_N, visitedN)

	// Left
	LEFT(i, j, x, y)
	DFS_N_COND(adjM, elem, applyDFS_N, visitedN)

	// Right
	RIGHT(i, j, x, y)
	DFS_N_COND(adjM, elem, applyDFS_N, visitedN)

	// Bottom
	BOTTOM(i, j, x, y)
	DFS_N_COND(adjM, elem, applyDFS_N, visitedN)
}

void applyDFS_Z_Sub(int i, int j)
{
	int x, y;
	visitedZ[i][j] = 1;

	// Top
	TOP(i, j, x, y)
	DFS_Z_SUB_COND

	// Left
	LEFT(i, j, x, y)
	DFS_Z_SUB_COND

	// Right
	RIGHT(i, j, x, y)
	DFS_Z_SUB_COND

	// Bottom
	BOTTOM(i, j, x, y)
	DFS_Z_SUB_COND
}

void applyDFS_Z_Main()
{
	int i, j;
	int maxElem = 0;
	int p, q;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (adjM[i][j] == 0 && !visitedZ[i][j])
			{
				applyDFS_Z_Sub(i, j);
				maxElem = findMaxElem();
				applyDFS_Z_replace(i, j, maxElem);
				for (p = 0; p < N; p++)
				{
					for (q = 0; q < N; q++)
					{
						visitedN[p][q] = 0;
					}
				}

				for (p = 1; p <= N; p++)
					maxArr[p] = 0;
			}
		}
	}
}

void applyDFS_Count_Booths_Sub(int i, int j, int num)
{
	int x, y;
	visitedRes[i][j] = 1;

	// Top
	TOP(i, j, x, y)
	DFS_N_COND(resM, num, applyDFS_Count_Booths_Sub, visitedRes)

	// Left
	LEFT(i, j, x, y)
	DFS_N_COND(resM, num, applyDFS_Count_Booths_Sub, visitedRes)

	// Right
	RIGHT(i, j, x, y)
	DFS_N_COND(resM, num, applyDFS_Count_Booths_Sub, visitedRes)

	// Bottom
	BOTTOM(i, j, x, y)
	DFS_N_COND(resM, num, applyDFS_Count_Booths_Sub, visitedRes)
}

void applyDFS_Count_Booths()
{
	int i, j;
	int maxElem = 0;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (!visitedRes[i][j])
			{
				applyDFS_Count_Booths_Sub(i, j, resM[i][j]);
				boothCnt++;
			}
		}
	}
}

int main()
{
	int T;
	int testCase, i, j;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	for (testCase = 1; testCase <= T; testCase++)
	{
		scanf("%d", &N);

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				scanf("%d", &adjM[i][j]);
				resM[i][j] = adjM[i][j];
				visitedN[i][j] = 0;
				visitedZ[i][j] = 0;
				visitedRepZ[i][j] = 0;
				visitedRes[i][j] = 0;
			}
			maxArr[i] = 0;
		}

		boothCnt = 0;

		applyDFS_Z_Main();
		applyDFS_Count_Booths();

		printf("\r\n #%d: %d", testCase, boothCnt);
	}
}

2)	DSF using Stack (Non Recursive):
We can avoid recursive function calls by implementing our own stack. 

STACK s
visited[ ]
DFS(v)
         push( s, v )
         WHILE NOT isEmpty( s ) 
                  v ← pop(s)
                  IF NOT visited[v]
                           visit( v )
                           FOR each w in adjacency( v )  //adjacent in UP, RIGHT, DOWN, LEFT  dir
												  IF NOT visited[w] and Value is same as previous Node
                                                              push(s, w)


3)	Breadth-First Search:
We can find clusters around Zeros using BFS approach as well. BFS would need queue implementation.  

BFS(G,v) // Graph G, Starting point of search v
	Generate queue
	Insert the starting point v to the queue
	Indicate the point v as visited
	WHILE queue is not empty
		t ← return the first element of queue
		FOR every line connected to t
			u ← neighboring point of t  
			If u is not visited point, and value is same as pervious Node
			insert u into queue, and indicate as visited

#define _CRT_SECURE_NO_WARNINGS
#define MAX 105
int N;
												  char map[MAX][MAX];
												  char res[MAX][MAX];

												  char visited[MAX][MAX];
												  int count[10];

												  int M_x[] = {-1, 0, +1, 0};
												  int M_y[] = {0, 1, 0, -1};

												  // for storing 0 locations
												  int Qx[10000], Qy[10000], front, rear;
												  void enqueue(int x, int y)
												  {
													  ++rear, Qx[rear] = x;
													  Qy[rear] = y;
												  }
												  void dequeue(int *x, int *y)
												  {
													  ++front, *x = Qx[front];
													  *y = Qy[front];
												  }
												  int queue_empty() { return front == rear; }

												  // for BFS processing of 0s
												  int Qzx[10000], Qzy[10000], frontz, rearz;
												  void enqueue_zero(int x, int y)
												  {
													  ++rearz, Qzx[rearz] = x;
													  Qzy[rearz] = y;
												  }
												  void dequeue_zero(int *x, int *y)
												  {
													  ++frontz, *x = Qzx[frontz];
													  *y = Qzy[frontz];
												  }
												  int zero_queue_empty() { return frontz == rearz; }

												  // for BFS processing of Non Zero clusters
												  int Qnzx[10000], Qnzy[10000], frontNZ, rearNZ;
												  void enqueue_non_zero(int x, int y)
												  {
													  ++rearNZ, Qnzx[rearNZ] = x;
													  Qnzy[rearNZ] = y;
												  }
												  void dequeue_non_zero(int *x, int *y)
												  {
													  ++frontNZ, *x = Qnzx[frontNZ];
													  *y = Qnzy[frontNZ];
												  }
												  int non_zero_queue_empty() { return frontNZ == rearNZ; }

												  main_bfs.cpp

#include <stdio.h>
													  int
													  is_safe(int x, int y)
												  {
													  if (x < N && x >= 0 && y >= 0 && y < N && !visited[x][y])
														  return 1;

													  return 0;
												  }
												  int Answer;
												  void reset_visited()
												  {
													  int i, j;
													  for (i = 0; i < N; i++)
														  for (j = 0; j < N; j++)
															  visited[i][j] = 0;
												  }
												  int find_max()
												  {
													  int max = 0;
													  int idx = -1;
													  int i, j;

													  for (i = 0; i < 10; i++)
													  {
														  if (count[i] >= max)
														  {
															  max = count[i];
															  idx = i;
														  }
													  }

													  return idx;
												  }

												  void BFS_Non_Zero(int x, int y, char map[][MAX])
												  {
													  int i, j;
													  int X, Y;
													  int NextX, NextY;

													  enqueue_non_zero(x, y);

													  while (!non_zero_queue_empty())
													  {
														  dequeue_non_zero(&X, &Y);
														  count[map[X][Y]]++;
														  visited[X][Y] = 1;

														  for (i = 0; i < 4; i++)
														  {
															  NextX = X + M_x[i];
															  NextY = Y + M_y[i];
															  if (is_safe(NextX, NextY))
															  {
																  if (map[X][Y] == map[NextX][NextY])
																  {
																	  enqueue_non_zero(NextX, NextY);
																  }
															  }
														  }
													  }
												  }
												  void BFS_Zero(int x, int y)
												  {
													  int i, j;
													  int NextX, NextY;
													  int X, Y;

													  enqueue(x, y);
													  enqueue_zero(x, y);

													  while (!zero_queue_empty())
													  {
														  dequeue_zero(&X, &Y);
														  visited[X][Y] = 1;

														  for (i = 0; i < 4; i++)
														  {
															  NextX = X + M_x[i];
															  NextY = Y + M_y[i];

															  if (is_safe(NextX, NextY))
															  {
																  if (map[NextX][NextY] != 0)
																  {
																	  BFS_Non_Zero(NextX, NextY, map);
																  }
																  else
																  {
																	  enqueue_zero(NextX, NextY);
																	  enqueue(NextX, NextY);
																  }
															  }
														  }
													  }
												  }
												  int solve_util()
												  {
													  int i, j, k;
													  int x, y;
													  int result;
													  char max;
													  for (i = 0; i < N; i++)
													  {

														  for (j = 0; j < N; j++)
														  {
															  reset_visited();
															  front = rear = -1;
															  frontz = rearz = -1;
															  frontNZ = rearNZ = -1;

															  if (res[i][j] == 0 && !visited[i][j])
															  {
																  BFS_Zero(i, j);
																  max = find_max();

																  while (!queue_empty())
																  {
																	  dequeue(&x, &y);
																	  res[x][y] = max;
																  }

																  for (k = 0; k < 10; k++)
																  {
																	  count[k] = 0;
																  }
															  }
														  }
													  }

													  result = 0;
													  reset_visited();
													  for (i = 0; i < N; i++)
													  {

														  for (j = 0; j < N; j++)
														  {
															  if (!visited[i][j])
															  {

																  BFS_Non_Zero(i, j, res);
																  result++;
															  }
														  }
													  }

													  return result;
												  }

												  int main(void)
												  {
													  int T, test_case;
													  int i, j;

													  freopen("input.txt", "r", stdin);

													  setbuf(stdout, NULL);

													  scanf("%d", &T);
													  for (test_case = 0; test_case < T; test_case++)
													  {
														  scanf("%d", &N);

														  for (i = 0; i < N; i++)
															  for (j = 0; j < N; j++)
															  {
																  scanf("%d", &map[i][j]);
																  res[i][j] = map[i][j];
															  }

														  Answer = solve_util();

														  // Print the answer to standard output(screen).
														  printf("Case #%d\n", test_case + 1);
														  printf("%d\n", Answer);
													  }

													  return 0; // Your program should return 0 on normal termination.
												  }

sample_input

3
5
5 5 1 4 4 
4 0 2 4 2
5 0 0 2 0 
5 4 3 0 1
1 3 3 2 1
10
1 3 5 1 4 0 0 4 2 1
1 1 2 1 1 0 5 0 2 1
5 0 2 0 4 4 4 0 1 1
0 2 2 4 0 5 4 2 1 3
1 1 2 2 2 3 3 2 1 1
5 1 1 2 0 3 3 2 2 1
3 1 1 1 0 0 1 2 2 5
3 1 4 1 2 0 4 0 0 5
4 0 3 3 1 3 3 0 0 1
5 0 3 1 4 3 3 1 2 3
20
0 2 1 0 1 3 3 3 3 4 4 1 1 1 4 1 1 4 1 4
0 2 3 5 1 2 3 3 3 3 4 2 1 3 2 2 1 1 1 3
0 2 1 5 1 2 2 2 0 3 2 3 4 2 1 3 3 0 1 1
1 5 4 5 1 2 5 5 5 5 2 5 5 2 0 0 3 3 5 4
1 0 5 5 3 5 3 0 4 5 5 5 1 0 1 1 3 4 0 0
4 5 3 4 4 5 3 3 0 0 3 3 1 3 1 3 2 5 0 0
3 2 0 0 0 3 4 1 1 1 1 3 5 2 1 3 1 4 0 5
2 2 0 2 3 3 3 0 1 5 1 3 5 2 5 3 4 4 0 5
3 4 0 1 1 1 0 4 4 4 4 1 5 0 4 5 3 4 4 4
3 2 0 1 4 4 3 0 0 0 3 5 1 0 1 4 1 3 4 4
0 3 1 1 1 1 1 1 2 2 3 3 1 0 5 4 4 4 4 4
4 2 5 3 4 4 4 1 2 5 5 5 4 1 1 1 4 1 0 5
4 2 5 1 4 2 5 2 0 1 5 2 4 1 4 1 1 0 0 0
1 2 3 0 1 4 2 2 4 1 1 0 4 4 4 5 4 1 0 0
3 2 0 1 1 1 2 1 3 1 0 4 1 4 4 2 4 3 3 0
3 3 5 4 1 1 1 1 3 2 4 4 4 4 4 3 3 3 3 4
4 3 1 1 1 1 1 1 1 3 2 2 0 5 4 4 4 5 0 0
3 3 2 0 5 0 3 3 1 3 2 4 0 4 0 4 4 2 4 4
1 4 4 3 4 5 2 4 4 4 4 4 0 5 0 4 0 3 1 0
5 4 4 5 2 3 3 0 0 5 2 4 3 3 2 3 4 4 5 0

Sample Output:

# 1 : 11
# 2 : 31
# 3 : 130



shooting balloon 10

There will be a N Balloons marked with value Bi (where B(i…N)).
User will be given Gun with N Bullets and user must shot N times.
When any balloaon explodes then its adjacent balloons becomes next to each other.
User has to score highest points to get the prize and score starts at 0.
Below is the condition to calculate the score.
When Balloon Bi Explodes then score will be a product of Bi-1 & Bi+1 (score = Bi-I * Bi+1).
When Balloon Bi Explodes and there is only left Balloon present then score will be Bi-1.
When Balloon Bi Explodes and there is only right Balloon present then score will be Bi+1.
When Balloon Bi explodes and there is no left and right Balloon present then score will be Bi.
Write a program to score maximum points.
Conditions:
Execution time limits 3 seconds.
No of Balloons N, where 1 <= N <= 10
Bi value of the Balloon 1 <= Bi <= 1000.
No two Balloons explode at same time.

Input:
Consists of TC (1 <= TC <= 50).
N – No of Balloons.
B0…..BN  N Balloons with their values .
Output:
#TC SCORE

Sample Input:
5
4
1 2 3 4
5
3 10 1 2 5
7
12 48 28 21 67 75 85
8
245 108 162 400 274 358 366 166
10
866 919 840 944 761 895 701 912 848 799
 

Sample Output:
# 1 20
# 2 100
# 3 16057
# 4 561630
# 5 6455522

1)Aim is to find max score
2) Max score depend on points on neighbor, however there is no easy way to find which sequence which gives max score, so only way is to find the all possible sequence can get max out of it.
3) As order matters in sequence for input N we can have N! sequences, ie. nPn ways (1st balloon N ways, 2nd N-1 ways …last balloon 1 ways N*(N-1)(N-2)..2*1= N!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50

clock_t start, end;
double cpu_time_used;

int matrix[MAX_SIZE][MAX_SIZE];
int visited_matrix[MAX_SIZE][MAX_SIZE];

int move[4][2] = {
	1, 0,
	-1, 0,
	0, -1,
	0, 1
};

int check_for_level(int dest_x, int dest_y);
int check_for_last_row(int dest_x, int dest_y, int level);

int row = 0;
int col = 0;

int prob(int x)
{
	if (rand() % 100 < x)
		return 1;
	else
		return 0;
}

void init_visited_matrix()
{
	int i, j;
	for (i = 0; i < MAX_SIZE; i++)
		for (j = 0; j < MAX_SIZE; j++)
			visited_matrix[i][j] = 0;
}

void print_matrix(int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}

int main()
{
	srand(10);
	int i, j, m, n, p, t, ans, loc_x, loc_y;
	int tc = 50;
	start = clock();
	for (t = 0; t < tc; t++)
	{
		m = 20 + rand() % 30;
		n = 20 + rand() % 30;

		// For safety, fill the whole matrix with -1 to start with
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				matrix[i][j] = -1;

		// Fill the left corner with 2
		matrix[m - 1][0] = 2;

		// Fill the last line with all 1
		for (i = 1; i < n; i++)
			matrix[m - 1][i] = 1;

		// Pick a random location and fill it with 3
		loc_x = rand() % m;
		loc_y = rand() % n;
		matrix[loc_x][loc_y] = 3;

		// pick a random probability between 40 to 60 to fill with 1
		p = 0 + rand() % 20;

		// fill the rest of the matrix with 1s and 0s with probability p

		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
			{
				if (-1 == matrix[i][j])
				{
					if (prob(p))
						matrix[i][j] = 1;
					else
						matrix[i][j] = 0;
				}
			}
		row = m;
		col = n;
		// print_matrix(m,n);

		ans = check_for_level(loc_x, loc_y);

		// printf("Row %d Col %d Loc_x %d Loc_y %d\n", m, n, loc_x, loc_y);
		printf("Case#%d: %d\n", t, ans);
	}
	end = clock();
	cpu_time_used = ((double)(end - start));
	printf("%lf\n", cpu_time_used);
	return 0;
}

int check_for_level(int dest_x, int dest_y)
{
	int level = 1;
	while (1)
	{
		init_visited_matrix();
		visited_matrix[dest_x][dest_y] = 1;
		if (1 == check_for_last_row(dest_x, dest_y, level))
		{
			return level;
		}
		level++;
	}
}

int check_for_last_row(int dest_x, int dest_y, int level)
{
	if (dest_x == row - 1)
		return 1;

	int k, temp_x, temp_y;
	for (k = 0; k < (2 + 2 * level); k++)
	{
		if (k < 4)
		{
			temp_y = dest_y + move[k][1];
			temp_x = dest_x + move[k][0];
		}
		else
		{
			temp_y = dest_y;
			temp_x = dest_x + (k / 2) * move[k % 2][0];
		}
		if (temp_x >= 0 && temp_y >= 0 && temp_x < row && temp_y < col)
		{
			if (matrix[temp_x][temp_y] == 1 && visited_matrix[temp_x][temp_y] == 0)
			{
				visited_matrix[temp_x][temp_y] = 1;
				if (1 == check_for_last_row(temp_x, temp_y, level))
					return 1;
			}
		}
	}
	return 0;
}

Complexity

To generate the all sequence O(N!)
To Get the Score for 1 sequence, for each balloon in sequence we need to left and right neighbors worst case need complete traversal in array  so complexity is O(N*N)  
Total complexity is O(N!) * O(N*N)  (note: computation has done at end of each sequence)
50 TC , N<= 10 => 50 *  is O(N! * N*N)  => 50 * 100 * 10! => 5000 * 3628800 => 1.5 * 10^10 this cannot be executed in given 3 sec ( 10^9 instruction per second).
So need to look for optimization

Pseudo code to generate all sequences

INPUT[N]
CHOICE[N] <= -1 //initialize to -1
Permute(0)
Permute(Position)
{
	// stop condition
	If(all balloon shot)
	{
Compute the score for this sequence in CHOICE[]
If score better than previous then store
	}

	For i : 0 ~N - 1
	{
If (ith balloon not selected // CHOICE[i]==-1)
{
			Select ith balloon // CHOICE[Position]= i
			Permute(Position + 1)
				Unselect ith balloon // CHOICE[Position]= -1
}
	}
}

Optimization
We can see in above algorithm 2 major operation are carried out 1) generate all sequence O(N!) and 2) computing score for each sequence O(N*N)
We cannot optimize the algorithm generate all sequences however we can reduce the computing part further.
Optimization computing part
If can optimize the finding the neighbor to O(1) we can reduce computation part to O(N) which leads our algo to execute in 1.5 * 10^9 which can be achieved in 3 sec.
Alternatively we can compute the score for each chosen balloon to shoot “on the go” here finding neighbor is extra when each time balloon is chosen which can be  O(N) and also reduce 1.5 * 10^9
If we combine 1 and 2 we can further reduce the time to 1.5 * 10^8

Algorithm to get neighbors

Naïve method by O(N):
    Neighbor(chosen)
	For Left: chosen-1~0 if Left th balloon not chosen break;
For Right : chosen + 1 ~N - 1 if right th balloon not chosen break;
if (Right == N)
	Right = -1;
Return Left and right;
 Optimized way by O(1)
Keep 2 array left[] and right[] which contain neighbors of each balloon.
Initially neighbor are known, for ith balloon left is i-1 and right is i+1 except that 1st balloon will have no left and last have no right.
When balloon is chosen we can obtain its right and left by O(1)
When a balloon is shot update neighbor  left[i+1]=left[i]  right[i-1]=right[i]
Note:
Instead of calling the new function to get left and right calculating left and right inside the recursive faction will reduce many hidden instructions as to call  new function compiler add many instruction which can be reduced 

Alternate Way

Naïve method by O(N):
    Neighbor(chosen)
	For Left: chosen-1~0 if Left th balloon not chosen break;
 For Right : chosen + 1 ~N - 1 if right th balloon not chosen break;
 if (Right == N)
	 Right = -1;
 Return Left and right;
 Optimized way by O(1)
Keep 2 array left[] and right[] which contain neighbors of each balloon.
Initially neighbor are known, for ith balloon left is i-1 and right is i+1 except that 1st balloon will have no left and last have no right.
When balloon is chosen we can obtain its right and left by O(1)
When a balloon is shot update neighbor  left[i+1]=left[i]  right[i-1]=right[i]
Note:
Instead of calling the new function to get left and right calculating left and right inside the recursive faction will reduce many hidden instructions as to call  new function compiler add many instruction which can be reduced 

Errors

Error in algorithm to generate permutation
Not optimizing the Computing the score algorithm.
Stop condition in recursive problem 
Selecting greedy methods

Alternative optimized approach(Divide and Conquer) and Dynamic programming

The problem at first doesn't seem like a divide and conquer problem.
Reason: If we select a balloon(for bursting) then our array would be divided into two sub arrays. But these two sub arrays won't be independent sub problems.
Example
Consider 5 balloons B1,.., B5. Bursting B3 divides the array into two sub-array {B1, B2} and {B4, B5}. But these two sub array are not independent of each other ie. score for bursting B4 is dependent on bursting order of {B1, B2}. 

B1    B2    X    B4    B5

Key Insight
To divide the problem into two halves we have to ensure that any action(bursting of balloon) in one half doesn't affect score of the other half.
If we fix a balloon and ensure that we won't burst it until we burst all the balloons to the left of it and all the balloon to the right of it then we can successfully divide the problem into two sub-problems.
Example
Consider the previous case of five balloons. Now instead of bursting B3 we fix that we will burst B3 after all the balloons this makes {B1, B2} and {B4, B5} independent of each other ie score for bursting B4 is now independent of {B1, B2}.

Another way to visualize the divide and conquer approach is that we think of the problem in reverse. The parallel problem would be given a set of n deflated balloons each with a score, choose the order in which you will inflate the balloon. The score for inflating the balloon is equal to product of score attached to the balloons located left and right to the mentioned balloon.

Pseudo Code

Note:
 We store the the input score values in the array inp_arr[N + 2].The values corresponding to the ith baloon is store at inp_arr[i].inp_arr[0] = inp_arr[N + 1] = 1;

 getMaxScore(inp_arr, left_limit, right_limit, N)
 {
	 initialize max_score = 0; // Max Score Value to Be Returned
	 for (i : left + 1 to right - 1)
	 {
		 initialize curr_score = 0;
		curr_score = getMaxScore(inp_arr, left, i, N) + getMaxScore(inp_arr, i, right, 	
		if(left == 0 && right == N){
			curr_score += inp_arr[i];
		}
		else{
			curr_score += inp_arr[left] * inp_arr[right];
		}
		//Update max_score value
		if(curr_score> max_score){
			max_score = curr_score;
		}
	 }
	 return max_score;
 }

The above problem can be easily optimized to include memoization using 2 Dimensional DP Matrix.

Execution time for diff approach

For input given in this document.
Generating sequences and computing at end by list for finding neighbor
	Execution time: 0.934000 seconds.
On the way compute
 external call for finding neighbor : Execution time: 1.223000 seconds. 
Inline for finding neighbor: Execution time: 0.657000 seconds.
List for finding neighbor: Execution time: 0.616000 seconds.

Divide and conquer:
-  Execution time: 0.004000 seconds.
with DP:  Execution time: 0.001000 seconds.




Toll Gate 11

Image 16
Image 17

#include <iostream>
int N, cc[25], t[25], min_cost = 10000007;

void dfs(int p, int a, int b, int c, int cost)
{
	int asum = a + b + c;
	if (cost > min_cost)
		return;
	if (p == N - 1)
	{
		if (asum < t[p])
			cost += cc[p];
		if (cost < min_cost)
			min_cost = cost;
		return;
	}
	dfs(p + 1, a, b, c, cost + cc[p]);
	dfs(p + 1, a + t[p], b, c, cost + 2 * cc[p]);
	if (asum >= t[p])
	{
		if (t[p] > b + c)
			a = asum - t[p];
		if (t[p] > c)
			b = t[p] - c >= b ? 0 : b - t[p] + c;
		dfs(p + 1, 0, a, b, cost);
	}
}
int main()
{
	std::cin >> N;
	for (int i = 0; i < N; ++i)
		std::cin >> t[i] >> cc[i];
	dfs(0, 0, 0, 0, 0);
	std::cout << min_cost << std::endl;
	return 0;
}
/////////////////

#include <stdio.h>
#include <time.h>
// no.of.toll gate(between 5 and 20, cost at toll gate, total hire available at tollgate, minimum cost
int N, tc[22], th[22], min_cost = 1000000;
void dfs(int tp, int bp3, int bp2, int bp1, int cc);
int main()
{
	int i, TC;
	clock_t start, end;
	double cpu_time_used;

	printf("No.of.TC? ");
	scanf("%d", &TC);
	start = clock();
	while (TC--)
	{
		scanf("%d", &N);
		for (i = 0; i < N; ++i)
			scanf("%d %d", &th[i], &tc[i]);

		dfs(0, 0, 0, 0, 0);
		printf("\nMinCost= %d\n\n", min_cost);
		min_cost = 1000000; // some large number
	}
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("fun() took %f seconds to execute \n", cpu_time_used);
	getch();
	return 0;
}

Tunnel Construction 12

* There are V number of tunnels in parallel. A tunnel is a combination of blocks in horizontal direction. Number of   blocks is given as H. So total tunnels will be V and total blocks is V*H. * There are two construction machines, one at each end of the tunnel under construction. * Each machine will work for a day and will construct one block of the tunnel but only one of the machines will work for a day, both can’t work on the same day. * A cost is associated with each machine, for working for one day.(C1 and C2 for machine 1 and 2 respectively) * For every block there is a factor given as S, which  will be multiplied by the cost of one day’s work of a machine. So the cost of constructing one block will be S*C1 or S*C2. * Additional cost is there if a machine is working for 2 or more consecutive days and is given as R1 and R2. * Once we get to know the construction cost associated with all the tunnels(V) , we have to select N out of them such that the cost is minimum keeping in mind that there should be at least one tunnel between the chosen tunnels. Distance must at least be 2.  * A cost is associated with the movement of machines(M1 and M2) based on the distance between the construction sites(Tunnel distance) and is given as (M1*M1 + M2*M2)*D. D is the distance between chosen tunnels.  Output: The minimum cost associated with this construction of N Tunnels.  Inputs:  T as number of test cases, followed by test cases. Each test case consists of:  N,H,V (in the first line) V lines follow the first line, with factor S associated with each Block in one horizontal line. (H entries in each of the V lines). C1,R1,M1(for machine 1) C2,R2,M2(for machine 2)  Constraints:  1<=N<=5, 3<=H<=500, (N*2-1)<=V<=15, 1<=S<=300, 1<=C<=200, 1<=R<=500, 1<=M<=300

Calculate normal construction cost for every possible case by both the machines. By going through every possible case. starting with 0 working days for machine 1 and H for machine 2. Then keep on incrementing number of days for machine 1 and reduce for machine 2. Each time calculate normal cost. 
For every possible case, add the additional cost for a machine working on consecutive days.
Calculating normal cost is easy, additional cost should be such that the consecutive days for the machines should be minimum. Can be achieved by making them work on alternate days for maximum times. 
Note:- The example they gave for minimum cost as: 2->1->2->2->2 means that machine 1 will work on second day and machine 2 will work on 1st day, 3rd day, 4th day and the 5th day. This does not mean that machine 1 will construct the second block and machine 2 will construct rest of the blocks. The machines will construct the blocks in sequence, one machine from one end and the other machine from the other end. They will never cross each other. This was the most important observation.   So according to given example, minimum additional cost will come for 2 consecutive days. Ie. Machine 2 working on 3rd 4th and 5th day consecutively. So we will add the cost for 2 days(4th and 5th).  One more possible case to get minimum additional cost could be  2->2->1->2->2 or 2->2->2->1->2. All will give same additional cost as the number of consecutive days for machine 2 is same. Each will give additional cost of 2 days. We can analyze other cases also and can come to a general equation to get the minimum cost. (D2-D1-1)*R2 or (D1-D2-1)*R1, depending upon which machine has worked for more days.  D1=> days machine 1 has worked, D2=> days machine 2 has worked. Adding the above calculated cost to the normal cost and checking the minimum gives us the minimum cost to construct one tunnel. Same way, calculate for all the possible tunnels and finally select N out of them. 

Requirement: Construct N tunnels Max length of a tunnel is 500. To calculate normal cost(S*C), for all the scenarios, total cases = 500*500. A machine can construct all the bocks, or one machine can construct one block and other can construct the rest, or 2 blocks by machine 1 and rest by machine 2 and so on……  1) So total number cases for one tunnel = 500*500.  For Maximum of 15 Tunnels= 15*500*500.

2) Now to select N which can at max be 5, we have to calculate every possible case. Gives us the worst case complexity less than 7^5. (seven possible places for single tunnel)  3) So total complexity can at worst be < 15*500*500 + 7^5.

#include <stdio.h>
int S[16][501];
int N,H,V;
int ans[16];
int final_min_cost= 60000000;// VERY_LARGE(taken around 60000000)
int new_cost;
int main()
{
	int i,j,k1,k2,v,T,test_case;
	int C1,C2,R1,R2,M1,M2;
	int max=60000000;// VERY_LARGE(60000000)
	int cost=0;
	int n1,n2,n3,n4,n5;
	scanf("%d",&T);
	for(test_case=1;test_case<=T;test_case++)
	{
		for(i=0;i<16;i++)
		{
			for(j=0;j<501;j++)
				S[i][j]=0;
		}
		for(i=0;i<16;i++)
			ans[i]=0;
		final_min_cost= 60000000;
		scanf("%d%d%d",&N,&H,&V);
		for(i=1;i<=V;i++)
		{
			for(j=1;j<=H;j++)
				scanf("%d",&S[i][j]);
		}
		scanf("%d%d%d",&C1,&R1,&M1);
		scanf("%d%d%d",&C2,&R2,&M2);

		// all inputs scanned..
		//Logic starts here
		for(v=1;v<=V;v++)  // for all the possible tunnels, find the min cost
		{
			max= 60000000;
			for(k1=0;k1<=H;k1++) // k1=0 means machine 1 works for 0 days
			{
				k2=H-k1; // k2 indicates the number of days machine 2 will work
				for(i=0;i<=k1;i++)
					cost = cost + (S[v][i]*C1);
				for(j=H;j>k1;j--)
					cost = cost + (S[v][j]*C2);
				// we have to add the cost for consecutive work.. that will be based on the number of days machine 1 and 2 have to work.. ie. k1 and k2
				if(k1>k2)// machine 1 has to work for more days than machine 2
					cost= cost + ((k1-k2-1)*R1);
				else if (k2>k1)// machine 2 has to work for more days than machine 1
					cost= cost + ((k2-k1-1)*R2);
				// this can be inferred from the example they have shown.. no need to take the combinations... since min cost will come if machines work alternate
				if(max>=cost)
					max=cost;
				cost=0; // for next iteration.
			}
			ans[v]=max; // for every possible tunnel, find the min cost
		}
		// we have to find the combination for N number of tunnels out of V possible tunnels such that cost is min
		if(N==1)
		{
			for(n1=1;n1<=V;n1++)
			{
				if(final_min_cost>=ans[n1])
					final_min_cost=ans[n1];
			}
		}
		else if(N==2)// 2 tunnels
		{
			for(n1=1;n1<=(V-((N-1)*2));n1++)
			{
				for(n2=n1+2;n2<=V;n2++)
				{
					new_cost= ans[n1]+ans[n2]+ (M1*M1 + M2*M2)*(n2-n1);
					if(final_min_cost>=new_cost)
						final_min_cost= new_cost;
				}
			}

		}
		else if(N==3) 
		{
			for(n1=1;n1<=(V-((N-1)*2));n1++)
			{
				for(n2=n1+2;n2<=(V-((N-2)*2));n2++) // notice that n2<= V-((N-2)*2)... for n1 it is (N-1)
				{
					for(n3=n2+2;n3<=V;n3++)
					{
						new_cost= ans[n1]+ans[n2]+ ans[n3] + (M1*M1 + M2*M2)*(n3-n1); // last ie. n3 minus first ie. n1 (n3-n1)
						if(final_min_cost>=new_cost)
						final_min_cost= new_cost;
					}
				}
			}
		}
	//	similarly... go for (N==4) and (N==5) // using nested loops :)
		else if(N==4)
		{
			for(n1=1;n1<=(V-((N-1)*2));n1++)
			{
				for(n2=n1+2;n2<=(V-((N-2)*2));n2++)
				{
					for(n3=n2+2;n3<=(V-((N-3)*2));n3++)
					{
						for(n4=n3+2;n4<=V;n4++)
						{
							new_cost= ans[n1]+ans[n2]+ ans[n3] + ans[n4] + (M1*M1 + M2*M2)*(n4-n1); // last ie. n4 minus first ie. n1 (n4-n1)
						if(final_min_cost>=new_cost)
						final_min_cost= new_cost;
						}
					}
				}
			}
		}
		else if (N==5)
		{
			//similar code
		}
		//in place of nested loops, you can find some other way to cover all the cases

			printf("#%d %d\n",test_case,final_min_cost);
	}
	return 0;
}

input.txt

4
1 3 1
42 3 99
4 19 3
4 1 5
1 5 1
1 4 1 3 11
7 2 3
4 6 4
2 5 4
1 4 1 3 11
13 5 1 4 11
1 2 3 4 5
99 2 47 3 31
7 2 3
2 6 5
1 4 1
1 2 3 4
7 3 3
2 9 4

Output

507/576
57/95
170
34


My code

#include <iostream>
using namespace std;
int T, n, h, v, c1, r1, m1, c2, r2, m2;
int tunnels[16][501] = { 0 };
int tunnel_cost[16] = { 0 };
int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> n >> h >> v;
		for (int i = 0; i < 16; i++){
			for (int j = 0; j < 501; j++){
				tunnels[i][j] = 0;
			}
		}
		for (int i = 0; i < 16; i++){
			tunnel_cost[i] = 0;
		}
		for (int i = 0; i < v; i++){
			for (int j = 0; j < h; j++){
				cin >> tunnels[i][j];
			}
		}
		cin >> c1 >> r1 >> m1 >> c2 >> r2 >> m2;

		for (int a = 0; a < v; a++){
			int max_cost = 99999999;
			for (int i = 0; i <= h; i++){
				int cost = 0;
				for (int j = 0; j < i; j++){
					cost += tunnels[a][j] * c1;
				}
				for (int k = i; k < h; k++){
					cost += tunnels[a][k] * c2;
				}
				int m1_days = i;
				int m2_days = h - i;
				if (m1_days>m2_days){
					cost = cost + r1*(m1_days - m2_days - 1);
				}
				else if (m1_days == m2_days){
					cost += 0;
				}
				else{
					cost = cost + r2*(m2_days - m1_days - 1);
				}
				//cout << i << ": " << cost << endl;
				if (cost < max_cost)
					max_cost = cost;
			}
			tunnel_cost[a] = max_cost;
			//cout << tunnel_cost[a] << endl;
		}
		int res = 9999999;
		if (n == 1){

			for (int a = 0; a < v; a++){
				if (tunnel_cost[a] < res)
					res = tunnel_cost[a];
			}
		}
		if (n == 2){
			for (int a = 0; a < v - 2; a++){
				for (int b = a + 2; b < v; b++){
					int temp = tunnel_cost[a] + tunnel_cost[b] + (m1*m1 + m2*m2)*(b - a);
					if (temp < res)
						res = temp;
				}
			}
		}
		if (n == 3){
			for (int a = 0; a < v - 4; a++){
				for (int b = a + 2; b < v - 2; b++){
					for (int c = b + 2; b < v; c++){
						int temp = tunnel_cost[a] + tunnel_cost[b] + tunnel_cost[c] + (m1*m1 + m2*m2)*(c - a);
						if (temp < res)
							res = temp;
					}
				}
			}
		}
		if (n == 4){
			for (int a = 0; a < v - 6; a++){
				for (int b = a + 2; b < v - 4; b++){
					for (int c = b + 2; b < v - 2; c++){
						for (int d = c + 2; d < v; d++){
							int temp = tunnel_cost[a] + tunnel_cost[b] + tunnel_cost[c] + tunnel_cost[d] + (m1*m1 + m2*m2)*(d - a);
							if (temp < res)
								res = temp;
						}
					}
				}
			}
		}
		if (n == 5){
			for (int a = 0; a < v - 8; a++){
				for (int b = a + 2; b < v - 6; b++){
					for (int c = b + 2; b < v - 4; c++){
						for (int d = c + 2; d < v - 2; d++){
							for (int e = d + 2; e < v; e++){
								int temp = tunnel_cost[a] + tunnel_cost[b] + tunnel_cost[c] + tunnel_cost[d] + tunnel_cost[e] + (m1*m1 + m2*m2)*(e - a);
								if (temp < res)
									res = temp;
							}
						}
					}
				}
			}
		}
		cout << "#" << t << " " << res << endl;
	}
	return 0;
}

Airplane :
0

	QUESTION : We have a game where an airplane is placed in the middle column of the bottom row.The airplane can move right or
	left by one step and in every step the row moves down.When the airplane meets ‘1’(coin)the number of points increase by 1 and when the airplane meets ‘2’(bomb)the number of points decrease by 1. Whenever the airplane meets the bomb with score 0 the airplane dies and game is over.The user has one detonate option throughout the game where he can detonate all the bombs in the next 5 rows.Find the maximum number of points(coins) that can be collected by the user.Number of rows 1 <= N <= 12. Return - 1 if score < 0

																																	  Image 1;

SAMPLE INPUT
The first line denotes the number of test cases and the second line denotes the number of rows. The following lines in every test case have the
3
7
1 2 0 0 1
2 0 0 1 0
0 1 2 0 1
1 0 0 2 1
0 2 1 0 1
0 1 2 2 2
1 0 1 1 0
5
1 1 0 0 0
1 2 2 2 1
1 1 2 2 1
2 2 2 1 2
2 2 0 2 0
6
2 2 2 2 2
0 0 0 0 0
0 0 2 0 0
2 0 0 0 2
0 0 0 0 0
1 2 2 2 1
SAMPLE OUTPUT
6
3
-1

APPROACHES
APPROACH – 1
The brute force approach would be considering 3 options (move left, move right and current) for all the rows without considering detonate. If we have N rows, the time complexity would be 3^N.
By considering detonate, we can detonate bomb at any step. This means the time complexity would be N*3^N.
Here, the maximum value would of N is 12.
However, if we consider the top down approach, i.e. collecting the coins as the rows move down, we can prune away the tree paths as the score becomes zero.

SAMPLE CODE (Image 2)
#include <iostream> 
using namespace std; 
int a[13][5], b[5][5];
void detonate(int row){ 
	for (int i = row; i > row - 5; i--){ 
		for (int j = 0; j < 5; j++){ 
			b[row - i][j] = 0; 
			if (i >= 0 && a[i][j] == 2) { 
				b[row - i][j] = 2; 
				a[i][j] = 0; 
			} 
		} 
	} 
} 

void unDetonate(int row){ 
	for (int i = row; i > row - 5; i--){ 
		for (int j = 0; j < 5; j++) { 
			if (i >= 0 && b[row - i][j] == 2) { 
			a[i][j] = 2; 
			} 
		}	 
	} 
}

void getMaxCoins(int pos, int coins, int n, int &maxCoins){
	if (pos < 0 || pos > 4 || coins < 0) 
		return;
	if (a[n - 1][pos] == 2) 
		coins -= 1; 
	else if (a[n - 1][pos] == 1) 
		coins += 1;
	if (n == 1){ 
		if (coins > maxCoins) 
		maxCoins = coins; 
	return; 
	} 
	else{ 
	// 3 options 
	// move right 
	getMaxCoins(pos + 1, coins, n - 1, maxCoins); 
	// move left 
	getMaxCoins(pos - 1, coins, n - 1, maxCoins); 
	// not move 
	getMaxCoins(pos, coins, n - 1, maxCoins); 
	} 
}


int main(){ 
	int t, n, i, j, k, coins, maxCoins; 
	cin >> t; 
	for (i = 0; i < t; i++){ 
		cin >> n; 
		maxCoins = -1; 
		for (j = 0; j < n; j++){ 
			for (k = 0; k < 5; k++){ 
			cin >> a[j][k]; 
			} 
		} 
		for (j = 0; j < 5; j++) 
			a[n][j] = 0; 
		a[n][2] = 3; 
		for (j = n - 1; j > 0 ; j--) {
			coins = -1; 
			//detonate 
			detonate(j); 
			getMaxCoins(2, 0, n, coins); 
			if (coins > maxCoins) 
				maxCoins = coins; 
			unDetonate(j); 
			// undetonate
		} 
		cout << ((maxCoins < 0) ? -1 : maxCoins) << endl;
}
}

// MY CODE

#include <iostream>

using namespace std;

int arr[13][5] = {0};
int maxCoinVal = -1;
// int mem[5][5] = {0};

void detonate(int row)
{
	for (int r = row; r > row - 5; r--)
	{
		if (r >= 0)
		{
			for (int j = 0; j < 5; j++)
			{
				if (arr[r][j] == 2)
					arr[r][j] = -1;
			}
		}
	}
}

void undetonate(int row)
{
	for (int r = row; r > row - 5; r--)
	{
		if (r >= 0)
		{
			for (int j = 0; j < 5; j++)
			{
				if (arr[r][j] == -1)
					arr[r][j] = 2;
			}
		}
	}
}

void maxCoins(int row, int col, int coins)
{
	if (col > 4 || col < 0 || coins < 0)
		return;
	if (arr[row - 1][col] == 1)
		coins++;
	else if (arr[row - 1][col] == 2)
		coins--;
	if (row == 0)
	{
		if (maxCoinVal < coins)
		{
			maxCoinVal = coins;
		}
		return;
	}
	else
	{
		maxCoins(row - 1, col - 1, coins);
		maxCoins(row - 1, col + 1, coins);
		maxCoins(row - 1, col, coins);
	}
}

int main()
{
	int test_cases;
	cin >> test_cases;
	for (int t = 0; t < test_cases; t++)
	{
		maxCoinVal = -1;
		cout << "testcase:" << t << endl;
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				arr[i][j] = 0;
			}
		}
		int rows;
		cin >> rows;
		for (int r = 0; r < rows; r++)
		{
			for (int c = 0; c < 5; c++)
			{
				cin >> arr[r][c];
			}
		}
		for (int i = rows - 1; i > 0; i--)
		{
			detonate(rows - 1);
			maxCoins(rows, 2, 0);
			maxCoins(rows, 1, 0);
			maxCoins(rows, 3, 0);
			undetonate(rows - 1);
		}
		cout << ((maxCoinVal < 0) ? -1 : maxCoinVal) << endl;
	}
	return 0;
}

#################################################################################




#########
Balloons burst#
#################################################################################
There will be a N Balloons marked with value Bi (where B(i…N)).
User will be given Gun with N Bullets and user must shot N times.
When any balloon explodes then its adjacent balloons becomes next to each other.
User has to score highest points to get the prize and score starts at 0.
Below is the condition to calculate the score.
When Balloon Bi Explodes then score will be a product of Bi-1 & Bi+1 (score = Bi-I * Bi+1).
When Balloon Bi Explodes and there is only left Balloon present then score will be Bi-1.
When Balloon Bi Explodes and there is only right Balloon present then score will be Bi+1.
When Balloon Bi explodes and there is no left and right Balloon present then score will be Bi.
Write a program to score maximum points.
Conditions:
Execution time limits 3 seconds.
No of Balloons N, where 1 <= N <= 10
Bi value of the Balloon 1 <= Bi <= 1000.
No two Balloons explode at same time.

Input:
Consists of TC (1 <= TC <= 50).
N – No of Balloons.
B0…..BN  N Balloons with their values .
Output:
#TC SCORE

Sample Input:
5
4
1 2 3 4
5
3 10 1 2 5
7
12 48 28 21 67 75 85
8
245 108 162 400 274 358 366 166
10
866 919 840 944 761 895 701 912 848 799
 

Sample Output:
# 1 20
# 2 100
# 3 16057
# 4 561630
# 5 6455522

Divide and concure approach

The problem at first doesn't seem like a divide and conquer problem.
Reason: If we select a balloon(for bursting) then our array would be divided into two sub arrays. But these two sub arrays won't be independent sub problems.
Example B1 B2 X B4 B5
Consider 5 balloons B1,.., B5. Bursting B3 divides the array into two sub-array {B1, B2} and {B4, B5}. But these two sub array are not independent of each other ie. score for bursting B4 is dependent on bursting order of {B1, B2}. 
B1 B2 X B4 B5

Key Insight
To divide the problem into two halves we have to ensure that any action(bursting of balloon) in one half doesn't affect score of the other half.
If we fix a balloon and ensure that we won't burst it until we burst all the balloons to the left of it and all the balloon to the right of it then we can successfully divide the problem into two sub-problems.
Example
Consider the previous case of five balloons. Now instead of bursting B3 we fix that we will burst B3 after all the balloons this makes {B1, B2} and {B4, B5} independent of each other ie score for bursting B4 is now independent of {B1, B2}.

Another way to visualize the divide and conquer approach is that we think of the problem in reverse. The parallel problem would be given a set of n deflated balloons each with a score, choose the order in which you will inflate the balloon. The score for inflating the balloon is equal to product of score attached to the balloons located left and right to the mentioned balloon


My Code

#include <iostream>
using namespace std;
int balloons[12];
int dp[12][12];
int function(int l, int r, int n){
	int max_val = 0;
	if (dp[l][r] != -1) return dp[l][r];
	for (int x = l + 1; x < r; x++){
		int curr_val = 0;
		curr_val = function(l, x, n) + function(x, r, n);
		if (l == 0 && r == n + 1)
			curr_val += balloons[x];
		else
			curr_val += balloons[l] * balloons[r];
		if (curr_val > max_val)
			max_val = curr_val;
	}
	dp[l][r] = max_val;
	return max_val;
}
int main(){
	int T;
	cin >> T;
	for (int t = 0; t < T; t++){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> balloons[i];
		}
		for (int i = 0; i < 12; i++){
			for (int j = 0; j <12; j++){
				dp[i][j] = -1;
			}
		}
		balloons[0] = 1;
		balloons[n + 1] = 1;
		cout << function(0, n + 1, n) << endl;
	}
	return 0;
}
###############################################################################




########
Basestations#
################################################################################

Constructing Basestation 1

Four 5G base station towers needs to be installed in a  Landscape which is divided as hexagon cells as shown in Fig below, which also contains number of people living in each cell. Need to find four cells  to install the 5G towers which can cover maximum number of people  combining all four cells, with below conditions
Only one tower can be placed in a cell
Each of the four chosen cell should be neighbor to atleast one of the remaining 3 cells. 
All four cells should be connected  (like  one island)

Refer next slide for some valid combinations

Input range:  1 <= N, M <= 15
Sample input Format for Fig in right
3 4
150 450 100 320
120 130 160 110
10 60 200 220

Output
Square of  Maximum number of people covered by 4 towers

Image 3

Approach 1: 
Get logic to find neighbor cells for odd and even cell (w.r.t column)
For each cell, do 
DFS of depth 4
combination for remaining number of cells with current cell’s  neighbor cells only
Approach 2: 
Read the input in hexagon format. Get logic to find neighbor cells. In this case logic will be same for both odd and even cell.
For each cell, do 
DFS of depth 4
combination for remaining  number of cells with current cell’s neighbor cells only. 
Approach 3:
For each cell give unique number  1, 2, 3, … m*n
Generate combination of four numbers from this set and check if these four cells are neighbours.
Approach 4: (Given by Bhargav Madishetty)
Get logic to find neighbor cells for odd and even cell (w.r.t column)
For each cell, do 
DFS of depth 4
Calculate Y as shown in figure 3 and also inverted Y. 
Solutions attached for Approach 1 and 2 in Basestation.c,  Approach 4 in hexagon.cpp


basestation.c -

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 16

///////////// Method #1

int N, M;
int cells[MAX][MAX];
int visited[MAX][MAX];
int maxcount;

int odir[2][6] = {{0, 0, -1, 1, 1, 1},
				  {-1, 1, 0, 1, -1, 0}};
int edir[2][6] = {{-1, -1, -1, 0, 1, 0},
				  {-1, 1, 0, 1, 0, -1}};

int isvalid(int i, int j)
{
	if (i < 0 || i >= N || j < 0 || j >= M)
		return 0;
	return 1;
}
int findmaxscore(int cX, int cY, int count, int curValue)
{

	int i, nX, nY;
	if (count == 4)
	{
		if (maxcount < curValue)
		{
			maxcount = curValue;
		}
		return;
	}

	for (i = 0; i < 6; i++)
	{
		if (cY % 2 == 0)
		{
			nX = cX + edir[0][i];
			nY = cY + edir[1][i];
		}
		else
		{
			nX = cX + odir[0][i];
			nY = cY + odir[1][i];
		}

		if (isvalid(nX, nY) && visited[nX][nY] == 0)
		{
			visited[nX][nY] = 1;
			findmaxscore(cX, cY, count + 1, curValue + cells[nX][nY]);
			findmaxscore(nX, nY, count + 1, curValue + cells[nX][nY]);
			visited[nX][nY] = 0;
		}
	}
}

///////////// Method #2

int Hcells[MAX * 2][MAX];
int visit2[MAX * 2][MAX];
int gmaxcore;

int dir[2][6] = {{-1, 1, 2, 1, -1, -2},
				 {1, 1, 0, -1, -1, 0}};

int issafe(int i, int j)
{
	if (i < 0 || i >= N * 2 || j < 0 || j >= M)
		return 0;
	return 1;
}
int findmax2(int cX, int cY, int count, int curValue)
{

	int i, nX, nY;
	if (count == 4)
	{
		if (gmaxcore < curValue)
		{
			gmaxcore = curValue;
		}
		return;
	}

	for (i = 0; i < 6; i++)
	{
		nX = cX + dir[0][i];
		nY = cY + dir[1][i];

		if (issafe(nX, nY) && visit2[nX][nY] == 0)
		{
			visit2[nX][nY] = 1;
			findmax2(cX, cY, count + 1, curValue + Hcells[nX][nY]);
			findmax2(nX, nY, count + 1, curValue + Hcells[nX][nY]);
			visit2[nX][nY] = 0;
		}
	}
}

int main(void)
{
	int T, test_case;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 0; test_case < T; test_case++)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////

		int i, j, k, l;
		scanf("%d %d", &N, &M);

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				scanf("%d", &cells[i][j]);
			}
		}

		maxcount = 0;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				visited[i][j] = 1;
				findmaxscore(i, j, 1, cells[i][j]);
				visited[i][j] = 0;
			}
		}

		//////////// Method 2  ////////////

		int x, y;
		for (i = 0, x = 0; i < N; i++, x += 2)
		{
			for (j = 0; j < M; j++)
			{
				if (j % 2 == 0)
					Hcells[x][j] = cells[i][j];
				else
					Hcells[x + 1][j] = cells[i][j];
			}
		}

		gmaxcore = 0;
		for (i = 0; i < N * 2; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (Hcells[i][j] != 0)
				{
					visit2[i][j] = 1;
					findmax2(i, j, 1, Hcells[i][j]);
					visit2[i][j] = 0;
				}
			}
		}

		// Print the answer to standard output(screen).
		printf("%d\n", maxcount * maxcount);
		printf("%d\n", gmaxcore * gmaxcore);
	}

	return 0; // Your program should return 0 on normal termination.
}

Hexagon.cpp

#include <iostream>
	using namespace std;

#define MAX 15

int ans;
int W, H;

int arr[MAX][MAX];
int visit[MAX][MAX];

int mOdd[6][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}};
int mEvn[6][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}, {1, -1}, {1, 1}};

int oddY[3][2] = {{-1, -1}, {-1, 1}, {1, 0}};
int evenY[3][2] = {{0, -1}, {0, 1}, {1, 0}};

int oddInvY[3][2] = {{0, -1}, {0, 1}, {-1, 0}};
int evenInvY[3][2] = {{-1, 0}, {-1, -1}, {-1, 1}};

void runDFS(int i, int j, int value, int count)
{
	if (count >= 4)
	{
		if (ans < value)
			ans = value;
		return;
	}

	for (int m = 0; m < 6; m++)
	{
		int x = -1, y = -1;
		if (j % 2)
		{
			x = i + mEvn[m][0];
			y = j + mEvn[m][1];
		}
		else
		{
			x = i + mOdd[m][0];
			y = j + mOdd[m][1];
		}
		if (!visit[x][y] && x >= 0 && x < H && y >= 0 && y < W)
		{
			visit[x][y] = 1;
			runDFS(x, y, value + arr[x][y], count + 1);
			visit[x][y] = 0;
		}
	}
}

void calculateY(int i, int j)
{
	int value = arr[i][j];
	int x = -1, y = -1;

	for (int m = 0; m < 3; m++)
	{
		if (j % 2)
		{
			x = i + evenY[m][0];
			y = j + evenY[m][1];
		}
		else
		{
			x = i + oddY[m][0];
			y = j + oddY[m][1];
		}
		if (x >= 0 && x < H && y >= 0 && y < W)
		{
			value += arr[x][y];
		}
		else
			return;
	}
	if (ans < value)
		ans = value;
}

void calculateInvertedY(int i, int j)
{
	int value = arr[i][j];
	int x = -1, y = -1;

	for (int m = 0; m < 3; m++)
	{
		if (j % 2)
		{
			x = i + evenInvY[m][0];
			y = j + evenInvY[m][1];
		}
		else
		{
			x = i + oddInvY[m][0];
			y = j + oddInvY[m][1];
		}
		if (x >= 0 && x < H && y >= 0 && y < W)
		{
			value += arr[x][y];
		}
		else
			return;
	}
	if (ans < value)
		ans = value;
}

int main()
{
	int test = 0;

	freopen("input.txt", "r", stdin);
	cin >> test;
	for (int tc = 1; tc <= test; tc++)
	{
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				arr[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		W = H = ans = 0;
		cin >> W >> H;

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				visit[i][j] = 1;
				runDFS(i, j, arr[i][j], 1);
				visit[i][j] = 0;

				calculateY(i, j);

				calculateInvertedY(i, j);
			}
		}

		cout << "#" << tc << " " << ans * ans << endl;
	}

	return 0;
}

Input.txt - 
6
3 4
150 450 100 320
120 130 160 110
10 60 200 220
1 4
10 20 30 40
3 5
300 410 150 55 370 
120 185 440 190 450 
165 70 95 420 50 
5 5
356 55 41 453 12 
401 506 274 506 379 
360 281 421 311 489 
425 74 276 371 164 
138 528 461 477 470 
3 13
197 51 443 274 47 552 160 96 501 102 469 318 308 
516 128 506 471 381 418 328 517 380 78 569 58 90 
113 238 179 444 541 27 444 62 264 93 245 353 37 
11 7
292 182 586 607 259 190 239 
511 716 425 367 511 462 714 
593 713 231 60 118 442 82 
626 577 579 682 136 176 681 
240 23 410 193 230 729 109 
453 231 287 383 444 578 409 
729 401 408 330 213 574 54 
684 224 75 62 660 472 227 
606 37 473 487 222 185 476 
84 477 158 94 141 484 122 
616 333 302 626 29 99 674

Mistakes:

Used same logic to find neighbour cells without differentiating for odd and even cells.
Some used row index to check even/odd instead of column index.
Used only DFS of depth 4 to get the combination, missed the combination which includes more than 2 neighbours of current cell as in case 3 in slide 3. 



My solution

#include <iostream>

using namespace std;

int cell[16][16] = {0};
int visited[16][16] = {0};
int odd[2][6] = {{0,0,-1,1,1,1}, {-1,1,0,-1,0,1}};
int even[2][6] = {{0,0,-1,-1,-1,1}, {-1,1,-1,0,1,0}};
int maxVal = 0, n, m;
int isValid(int i, int j){
    if(i<0 || j<0 || i>=n || j>=m) return 0;
    else return 1;
}

void findScore(int x, int y, int count, int currVal){
    if(count == 4){
        if (currVal > maxVal)
            maxVal = currVal;
        return;
    }
    
    int nx, ny;
    for(int i = 0; i < 6; i++){
        if(y%2 == 0){
            nx = x + even[0][i];
            ny = y + even[1][i];
        }
        else{
            nx = x + odd[0][i];
            ny = y + odd[1][i];
        }
        
        if((isValid(nx, ny) == 1) && (visited[nx][ny] == 0)){
            visited[nx][ny] = 1;
            findScore(x, y, count+1, currVal + cell[nx][ny]);
            findScore(nx, ny, count+1, currVal + cell[nx][ny]);
            visited[nx][ny] = 0;
        }
    }
    
}

int main(void)
{
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++){
		int i, j;
		cin >> n;
        cin >> m;
		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++){
				cin >> cell[i][j];
			}
		}
		for (i = 0; i < 16; i++){
			for (j = 0; j < 16; j++){
				visited[i][j] = 0;
			}
		}
		maxVal = 0;
		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++){
				visited[i][j] = 1;
				findScore(i, j, 1, cell[i][j]);
				visited[i][j] = 0;
			}
		}
		printf("%d\n", maxVal*maxVal);
	}

	return 0;
}

1276900
10000
225000
3748096
3928324
7236100

###############################################################################




#######
Endoscope#
################################################################################
Endoscope 2

We are given m*n matrix which can have a number between 0 and 7. Each number represents a pipe with a shape as follows:

Image 4

Two pipes are considered connected if their end points connect. For e.g.
If matrix is as follows:
0040
1360
5000
Pipe 1 and 3{1 opens to right. 3 opens to left} are connected. Other connected pipes are 3 and 6(3 opens to right. 6 opens to left).
4 and 6 are not connected as 6 does not open to top, and 4 does not open to bottom.
1 and 5 are also not connected as even though 1 opens to bottom, 5 is not open to top.
Given this matrix, start point (X, Y) and length of probe tool “L”, find out how many pipes{matrix elements} can be reached. 
Key Steps to solve:
1.	Find which of the neighboring pipe elements can be accessed from one starting point {Maintaining exhaustive list of checks to ascertain neighboring criteria as defined above}.
2.	Find a method to process through the elements to find the next set of elements which can be accessed. {Traversing through the graph}. It should be noted that we wish to reach all nodes which are accessible from start node with distance less than “L”. The focus is not on reaching lot of nodes, but on reaching them with lesser moves from start point (X, Y).
 
Approaches to the problem of traversal:
1)	Recursion:
We mark all the nodes as unvisited and visited node count as 0. If a node marked as unvisited is processed during recursion, increment visited node count by 1 and mark it as visited. 
We start by visiting Start node (X, Y) and then recursively visiting all its connected neighbors (based on checks for connected criteria as defined above) till the recursion depth of “L”. 

Drawback:
In case of highly connected matrix (almost all pipes are connected together and multiple ways to reach a pipe exists), we reach a node multiple times and process it multiple times which may lead to high running time. We can optimize it by checking that we process a node again only if we have reached it with a lower recursion level.
This is not a DFS solution because we reprocess a node, even if already visited, as it is possible that the new visit may update the visiting depth of the node to lower level and greater depth be reached after this node.

2)	Breadth-First Search:
We mark all the nodes as unvisited and visited node count as 0. If a node marked as unvisited is processed during processing, increment visited node count by 1.
We start by pushing the start node (X, Y) into a queue with depth 1 and then start processing the queue till it is empty.
In each iteration a member of queue is taken out and its connected neighbors are analyzed. If neighbors are unvisited and depth of current element is not greater than L, connected elements are put into queue, marked visited and visited node count increased by 1. 

As BFS performs level order traversal of nodes, it is not possible that a visited node be reached in a smaller distance. So, drawback of previous method cannot exist. This is the optimal solution for this problem.

Simplification possible in the solutions for easy coding:
Since there are 7 types of pipes, we will have to put multiple if conditions leading to nested if statements which are difficult to debug. It can be simplified by converting the 7 values into direction based data. For e.g. each value can be transformed into a structure with 4 Boolean variables, one for each direction. Alternatively, each number can be mapped to a 4 bit number where each bit represents a direction. After this input reduction, checks will become simpler and with less complexity.

#include <iostream>
using namespace std;

struct node
{
	int xx;
	int yy;
	int dir;
};

int N, M, len, x, y;
int mat[1001][1001];
int visited[1001][1001];
struct node que[10000001];
int front, rear;

void push(int a, int b, int cost)
{
	if (front == -1)
		front = 0;
	struct node q;
	q.xx = a;
	q.yy = b;
	q.dir = cost;
	que[++rear] = q;
}

void pop()
{
	front++;
}

bool empty()
{
	if (front == -1 || front > rear)
		return true;
	return false;
}

void up(int x, int y, int lev)
{
	if (x - 1 >= 0 && visited[x - 1][y] == 0 && mat[x - 1][y] > 0 && lev + 1 <= len && (mat[x - 1][y] == 1 || mat[x - 1][y] == 2 || mat[x - 1][y] == 5 || mat[x - 1][y] == 6))
	{
		push(x - 1, y, lev + 1);
		visited[x - 1][y] = 1;
	}
}

void down(int x, int y, int lev)
{
	if (x + 1 < N && visited[x + 1][y] == 0 && mat[x + 1][y] > 0 && lev + 1 <= len && (mat[x + 1][y] == 1 || mat[x + 1][y] == 2 || mat[x + 1][y] == 4 || mat[x + 1][y] == 7))
	{
		push(x + 1, y, lev + 1);
		visited[x + 1][y] = 1;
	}
}

void right(int x, int y, int lev)
{
	if (y + 1 < M && visited[x][y + 1] == 0 && mat[x][y + 1] > 0 && lev + 1 <= len && (mat[x][y + 1] == 1 || mat[x][y + 1] == 3 || mat[x][y + 1] == 6 || mat[x][y + 1] == 7))
	{
		push(x, y + 1, lev + 1);
		visited[x][y + 1] = 1;
	}
}

void left(int x, int y, int lev)
{
	if (y - 1 >= 0 && visited[x][y - 1] == 0 && mat[x][y - 1] > 0 && lev + 1 <= len && (mat[x][y - 1] == 1 || mat[x][y - 1] == 3 || mat[x][y - 1] == 4 || mat[x][y - 1] == 5))
	{
		push(x, y - 1, lev + 1);
		visited[x][y - 1] = 1;
	}
}

void bfs(int x1, int y1)
{
	visited[x1][y1] = 1;
	push(x1, y1, 1);

	while (!empty())
	{
		struct node p = que[front];
		int x = p.xx;
		int y = p.yy;
		int lev = p.dir;
		pop();

		if (mat[x][y] == 1)
		{
			up(x, y, lev);
			right(x, y, lev);
			down(x, y, lev);
			left(x, y, lev);
		}

		if (mat[x][y] == 2)
		{
			up(x, y, lev);
			down(x, y, lev);
		}

		if (mat[x][y] == 3)
		{
			right(x, y, lev);
			left(x, y, lev);
		}

		if (mat[x][y] == 4)
		{
			up(x, y, lev);
			right(x, y, lev);
		}

		if (mat[x][y] == 5)
		{
			right(x, y, lev);
			down(x, y, lev);
		}

		if (mat[x][y] == 6)
		{
			down(x, y, lev);
			left(x, y, lev);
		}

		if (mat[x][y] == 7)
		{
			up(x, y, lev);
			left(x, y, lev);
		}
	}
}

int main()
{
	int T, i, j, k;
	cin >> T;
	int count;

	for (k = 0; k < T; k++)
	{

		count = 0;
		cin >> N >> M >> x >> y >> len;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				cin >> mat[i][j];
				visited[i][j] = 0;
			}
		}

		front = -1;
		rear = -1;

		if (len > 0 && mat[x][y])
		{

			bfs(x, y);

			for (i = 0; i < N; i++)
			{
				for (j = 0; j < M; j++)
				{
					if (visited[i][j])
						count++;
				}
			}
		}

		cout << count << endl;
	}
}

################################################################################



#####
Fishery#
################################################################################
Fishery 3

Given:
Fishing Spots: 1 to N
3 Gates with gate position and number of fishermen waiting to get in
Distance between consecutive spots = distance between gate and nearest spot = 1 m
 
Fishermen are waiting at the gates to get in and occupy nearest fishing spot. Only 1 gate can be opened at a time and all fishermen of that gate must occupy spots before next gate is open.  
There could be 2 spots closest to the gate. Assign only 1 spot to the last fisherman in such a way that we get minimum walking distance. For rest of the fishermen, ignore and assign any one.

Write a program to return sum of minimum distance need to walk for fishermen.
 
Distance is calculated as gate to nearest spot + nearest spot to closest vacant spot.
If the gate is at position 4, then fishermen occupying spot 4 will walk 1 m, fishermen occupying spot 3 or 5 will walk 2 m (1m for gate to spot#4 + 1M for spot #4 to spot #3 or 5).

Ex: 3 gates at position 4,6 and 10. Total fishing spots = 10

Image 5
Image 6
Image 7
Image 8

Write function which takes gate # as input and assigns fishermen to nearest spots for that gate. It returns minimum distance and total number of position possible for last fishermen. If number of positions are 2, returns both positions.
Generate all combinations and assigns fishermen in all gate combinations to calculate minimum walking distance.

Generating combination can be done in both recursive and iterative way.

fishery_iterative.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 3

int fishspot[61];
int gate[MAX];
int fishermen[MAX];
int N;
int visited[MAX];
int Answer;

// To unmark spots occupied by fishermen of gate# index
void reset_fishspot(int index)
{
	int i;
	for (i = 1; i <= N; i++)
		if (fishspot[i] == index + 1)
			fishspot[i] = 0;
}

// Calculate minimum distance while allotting spots to fishermen of gate# index.
// Returns number of positions possible with minimum disance.
// pos1, pos2 is used to return positions
int calculate_distance(int index, int *pos1, int *pos2, int *score)
{
	int i, sum = 0, left_min = 999999, right_min = 999999, left, right, npos = 0;
	*pos1 = *pos2 = *score = 0;

	left = right = gate[index];

	// Allot spots to all fishermen except last based on minimum distance
	for (i = 1; i < fishermen[index]; i++)
	{
		if (fishspot[gate[index]] == 0)
		{
			sum++;
			fishspot[gate[index]] = index + 1;
		}
		else
		{
			left_min = right_min = 999999;

			while ((left > 0) && (fishspot[left] > 0))
				left--;

			while ((right <= N) && (fishspot[right] > 0))
				right++;

			if ((left > 0) && (fishspot[left] == 0))
				left_min = gate[index] - left + 1;

			if ((right <= N) && (fishspot[right] == 0))
				right_min = right - gate[index] + 1;

			if (right_min == left_min)
			{
				// Place 2 fishermen, if avaiable
				if ((fishermen[index] - i - 1) > 1)
				{
					fishspot[left] = fishspot[right] = index + 1;
					sum += (2 * left_min);
					i++;

					// If all fishermen are alloted spots
					if (i == fishermen[index])
					{
						npos = 1;
						*score = sum;
						return npos;
					}
				}
				else
				{
					sum += left_min;
					fishspot[left] = index + 1;
				}
			}
			else if (left_min < right_min)
			{
				sum += left_min;
				fishspot[left] = index + 1;
			}
			else if (right_min < left_min)
			{
				sum += right_min;
				fishspot[right] = index + 1;
			}
		}
	}

	left_min = right_min = 99999;

	// Allot spot to last fishermen
	while ((left > 0) && (fishspot[left] > 0))
		left--;

	if ((left > 0) && (fishspot[left] == 0))
		left_min = gate[index] - left + 1;

	while ((right <= N) && (fishspot[right] > 0))
		right++;

	if ((right <= N) && (fishspot[right] == 0))
		right_min = right - gate[index] + 1;

	if ((sum + left_min) == (sum + right_min))
	{
		npos = 2;
		*pos1 = left;
		*pos2 = right;
		*score = sum + left_min;
	}
	else if ((sum + left_min) > (sum + right_min))
	{
		npos = 1;
		*score = sum + right_min;
		fishspot[right] = index + 1;
	}
	else if ((sum + left_min) < (sum + right_min))
	{
		npos = 1;
		*score = sum + left_min;
		fishspot[left] = index + 1;
	}

	return npos;
}

void solve()
{
	int index1, index2, index3;
	int sum = 0;
	int pos[MAX][2];
	int npos[MAX];
	int score[MAX];
	int i, j;

	for (index1 = 0; index1 < MAX; index1++)
	{
		sum = 0;
		visited[index1] = 1;
		npos[index1] = calculate_distance(index1, &pos[index1][0], &pos[index1][1], &score[index1]);
		sum += score[index1];
		for (i = 0; i < npos[index1]; i++)
		{
			fishspot[pos[index1][i]] = index1 + 1;
			for (index2 = 0; index2 < MAX; index2++)
			{
				if (visited[index2] == 0)
				{
					visited[index2] = 1;
					npos[index2] = calculate_distance(index2, &pos[index2][0], &pos[index2][1], &score[index2]);
					sum += score[index2];
					for (j = 0; j < npos[index2]; j++)
					{
						fishspot[pos[index2][i]] = index2 + 1;
						for (index3 = 0; index3 < MAX; index3++)
						{
							if (visited[index3] == 0)
							{
								visited[index3] = 1;
								npos[index3] = calculate_distance(index3, &pos[index3][0], &pos[index3][1], &score[index3]);
								sum += score[index3];
								if (sum < Answer)
									Answer = sum;
								sum -= score[index3];
								visited[index3] = 0;
								reset_fishspot(index3);
							}
						}
						fishspot[pos[index2][i]] = 0;
					}
					sum -= score[index2];
					visited[index2] = 0;
					reset_fishspot(index2);
				}
			}
			fishspot[pos[index1][i]] = 0;
		}
		sum -= score[index1];
		visited[index1] = 0;
		reset_fishspot(index1);
	}
}

int main()
{
	int T, testcase, i;

	scanf("%d", &T);
	for (testcase = 1; testcase <= T; testcase++)
	{
		scanf("%d", &N);
		for (i = 0; i < MAX; i++)
		{
			scanf("%d %d", &gate[i], &fishermen[i]);
			visited[i] = 0;
		}

		for (i = 1; i <= N; i++)
			fishspot[i] = 0;

		Answer = 999999;

		solve();

		printf("#%d %d\n", testcase, Answer);
	}
	return 0;
}

fishery_recursive.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 3

	int fishspot[61];
int gate[MAX];
int fishermen[MAX];
int N;
int visited[MAX];
int Answer;

// To unmark spots occupied by fishermen of gate# index
void reset_fishspot(int index)
{
	int i;
	for (i = 1; i <= N; i++)
		if (fishspot[i] == index + 1)
			fishspot[i] = 0;
}

// Calculate minimum distance while allotting spots to fishermen of gate# index.
// Returns number of positions possible with minimum disance.
// pos1, pos2 is used to return positions
int calculate_distance(int index, int *pos1, int *pos2, int *score)
{
	int i, sum = 0, left_min = 999999, right_min = 999999, left, right, npos = 0;
	*pos1 = *pos2 = *score = 0;

	left = right = gate[index];

	// Allot spots to all fishermen except last based on minimum distance
	for (i = 1; i < fishermen[index]; i++)
	{
		if (fishspot[gate[index]] == 0)
		{
			sum++;
			fishspot[gate[index]] = index + 1;
		}
		else
		{
			left_min = right_min = 999999;

			while ((left > 0) && (fishspot[left] > 0))
				left--;

			while ((right <= N) && (fishspot[right] > 0))
				right++;

			if ((left > 0) && (fishspot[left] == 0))
				left_min = gate[index] - left + 1;

			if ((right <= N) && (fishspot[right] == 0))
				right_min = right - gate[index] + 1;

			if (right_min == left_min)
			{
				// Place 2 fishermen, if avaiable
				if ((fishermen[index] - i - 1) > 1)
				{
					fishspot[left] = fishspot[right] = index + 1;
					sum += (2 * left_min);
					i++;

					// If all fishermen are alloted spots
					if (i == fishermen[index])
					{
						npos = 1;
						*score = sum;
						return npos;
					}
				}
				else
				{
					sum += left_min;
					fishspot[left] = index + 1;
				}
			}
			else if (left_min < right_min)
			{
				sum += left_min;
				fishspot[left] = index + 1;
			}
			else if (right_min < left_min)
			{
				sum += right_min;
				fishspot[right] = index + 1;
			}
		}
	}

	left_min = right_min = 99999;

	// Allot spot to last fishermen
	while ((left > 0) && (fishspot[left] > 0))
		left--;

	if ((left > 0) && (fishspot[left] == 0))
		left_min = gate[index] - left + 1;

	while ((right <= N) && (fishspot[right] > 0))
		right++;

	if ((right <= N) && (fishspot[right] == 0))
		right_min = right - gate[index] + 1;

	if ((sum + left_min) == (sum + right_min))
	{
		npos = 2;
		*pos1 = left;
		*pos2 = right;
		*score = sum + left_min;
	}
	else if ((sum + left_min) > (sum + right_min))
	{
		npos = 1;
		*score = sum + right_min;
		fishspot[right] = index + 1;
	}
	else if ((sum + left_min) < (sum + right_min))
	{
		npos = 1;
		*score = sum + left_min;
		fishspot[left] = index + 1;
	}

	return npos;
}

// Solve is used to select next gate and generate all combinations.
void solve(int index, int sum, int count)
{
	int npos, pos1, pos2, score, i;

	visited[index] = 1;

	if (sum > Answer)
		return;

	npos = calculate_distance(index, &pos1, &pos2, &score);
	sum += score;

	if (count == MAX)
	{
		if (Answer > sum)
			Answer = sum;

		return;
	}

	if (npos == 1)
	{
		for (i = 0; i < MAX; i++)
		{
			if (visited[i] == 0)
			{
				solve(i, sum, count + 1);
				visited[i] = 0;
				reset_fishspot(i);
			}
		}
	}
	else if (npos == 2)
	{
		fishspot[pos1] = index + 1;
		for (i = 0; i < MAX; i++)
		{
			if (visited[i] == 0)
			{
				solve(i, sum, count + 1);
				visited[i] = 0;
				reset_fishspot(i);
			}
		}

		fishspot[pos1] = 0;
		fishspot[pos2] = index + 1;
		for (i = 0; i < MAX; i++)
		{
			if (visited[i] == 0)
			{
				solve(i, sum, count + 1);
				visited[i] = 0;
				reset_fishspot(i);
			}
		}
		fishspot[pos2] = 0;
	}
}

int main()
{
	int T, testcase, i;

	scanf("%d", &T);
	for (testcase = 1; testcase <= T; testcase++)
	{
		scanf("%d", &N);
		for (i = 0; i < MAX; i++)
		{
			scanf("%d %d", &gate[i], &fishermen[i]);
			visited[i] = 0;
		}

		for (i = 1; i <= N; i++)
			fishspot[i] = 0;

		Answer = 999999;

		for (i = 0; i < MAX; i++)
		{
			solve(i, 0, 1);
			visited[i] = 0;
			reset_fishspot(i);
		}

		printf("#%d %d\n", testcase, Answer);
	}
	return 0;
}

Input.txt

5
10
4 5
6 2
10 2
10
8 5
9 1
10 2
24
15 3
20 4
23 7
39
17 8
30 5
31 9
60
57 12
31 19
38 16

output

# 1 18
# 2 25
# 3 57
# 4 86
# 5 339

########################################################################################




Marathon
########################################################################################
Marathon 4

Mr. Choi has to do a marathon of D distance. He can run at 5 different paces, each pace will have its time consumed per km and its energy consumption.
Mr. Choi can only run till he had energy left.
Find the minimum time required for choi to complete marathon if he has H energy.

Approaches

Using For loop to calculate all combination
Using recursion with Pruning to find all combinations
Using Recursion with for and While loops to find all combinations
Using DP to find the solution (more programming required in this approach)
Using recursion with memorization
Please find attached solutions for first 4 approaches

solutions.cpp

#include <iostream>

using namespace std;

#define MAX_P 6

struct node
{
	int timeSec;
	int energy;
};

struct node paceInfo[MAX_P] = {0};

int visited[MAX_P] = {0};

int H, D;
int finalTime;

void resetGlobal()
{
	for (int i = 0; i < MAX_P; i++)
		visited[i] = 0;
}

// Pure Recurrsion with Pruning
void calculate(int curr_time, int remain_dist, int remain_energy, int paceIndex)
{
	if (curr_time > finalTime)
	{
		return;
	}

	if (remain_energy < 0)
	{
		return;
	}

	if (remain_dist <= 0)
	{
		if (curr_time < finalTime)
		{
			finalTime = curr_time;
		}
		return;
	}

	if ((remain_dist * paceInfo[5].energy) > remain_energy)
	{
		return;
	}

	if (paceIndex == 1)
		calculate(paceInfo[1].timeSec + curr_time, remain_dist - 1, remain_energy - paceInfo[1].energy, 1);
	if (paceIndex == 2 || paceIndex == 1)
		calculate(paceInfo[2].timeSec + curr_time, remain_dist - 1, remain_energy - paceInfo[2].energy, 2);
	if (paceIndex == 3 || paceIndex == 1 || paceIndex == 2)
		calculate(paceInfo[3].timeSec + curr_time, remain_dist - 1, remain_energy - paceInfo[3].energy, 3);
	if (paceIndex == 4 || paceIndex == 1 || paceIndex == 2 || paceIndex == 3)
		calculate(paceInfo[4].timeSec + curr_time, remain_dist - 1, remain_energy - paceInfo[4].energy, 4);
	if (paceIndex == 5 || paceIndex == 1 || paceIndex == 2 || paceIndex == 3 || paceIndex == 4)
		calculate(paceInfo[5].timeSec + curr_time, remain_dist - 1, remain_energy - paceInfo[5].energy, 5);
}

// Only For loop Soluion and fastest
void comuteForLoopMin() // Working
{

	for (int m = 0; m <= H / paceInfo[4].energy && m <= D; m++)
		for (int k = 0; k <= H / paceInfo[3].energy && k <= D; k++)
			for (int j = 0; j <= H / paceInfo[2].energy && j <= D; j++)
				for (int i = 0; i <= H / paceInfo[1].energy && i <= D; i++)
				{
					int n = (D - (i + j + k + m));

					int tempTime = i * paceInfo[1].timeSec + j * paceInfo[2].timeSec + k * paceInfo[3].timeSec + m * paceInfo[4].timeSec + n * paceInfo[5].timeSec;

					int tempEnergy = i * paceInfo[1].energy + j * paceInfo[2].energy + k * paceInfo[3].energy + m * paceInfo[4].energy + n * paceInfo[5].energy;

					if (tempEnergy > H)
						continue;
					if (finalTime > tempTime)
						finalTime = tempTime;
				}
}

// Recursion with For Loop
void ComputeRecurssion(int tmpDist, int tmpEnergy, int tmpTime, int node)
{

	if (tmpTime > finalTime)
		return;

	if (tmpEnergy > H)
		return;

	if (tmpDist == D)
	{
		if (finalTime > tmpTime)
			finalTime = tmpTime;
		return;
	}

	for (int i = node; i <= 5; i++)
	{
		// if (visited[i] == 0)
		{
			visited[i] = 1;
			int j = 1; //  5;

			while (1)
			{
				if (j * paceInfo[i].energy + tmpEnergy <= H && j + tmpDist <= D)
				{
					ComputeRecurssion(j + tmpDist, j * paceInfo[i].energy + tmpEnergy, tmpTime + j * paceInfo[i].timeSec, i + 1);
				}
				else
					break;
				j++; // =5;
			}
		}
		// backtrack
		visited[i] = 0;
	}
}

int main(int argc, char **argv)
{
	int T, test_case;
	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int tempMin = 0, tempSec = 0;
		cin >> H >> D;
		finalTime = 9999999;
		resetGlobal();
		for (int i = 1; i <= 5; i++)
		{
			cin >> tempMin >> tempSec;
			paceInfo[i].timeSec = tempMin * 60 + tempSec;

			cin >> paceInfo[i].energy;
		}
		// Logic here

		// comuteForLoopMin();
		// ComputeRecurssion(0,0,0, 1);
		calculate(0, D, H, 1);

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << " " << (finalTime / 60) << " " << (finalTime % 60) << endl;
	}

	return 0; // Your program should return 0 on normal termination.
}

dpsolution.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
	using namespace std;

int abc[41][601];
int Energy;
int dist;
int gears[5][2];

int min(int x, int g)
{
	int mina = 99999;
	for (int i = 0; i < 5; i++)
	{
		if (g - gears[i][1] > 0)
			if ((abc[x - 1][g - gears[i][1]] + gears[i][0]) < mina)
				mina = abc[x - 1][g - gears[i][1]] + gears[i][0];
	}
	return mina;
}

int main()
{
	// freopen("input1.txt", "r", stdin);
	// freopen("output_our.txt", "w", stdout);
	int tc;
	int a, b;
	int minb = 99999;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		minb = 99999;
		cin >> Energy >> dist;
		for (int i = 0; i < 5; i++)
		{
			cin >> a >> b >> gears[i][1];
			gears[i][0] = a * 60 + b;
		}
		for (int i = 1; i <= Energy; i++)
			for (int j = 0; j <= dist; j++)
			{
				abc[j][i] = 99999;
			}
		for (int i = 1; i <= 5; i++)
		{
			abc[1][gears[i - 1][1]] = gears[i - 1][0];
		}
		for (int i = 2; i <= dist; i++)
		{
			for (int j = 1; j <= Energy; j++)
			{
				abc[i][j] = min(i, j);
			}
		}
		for (int i = 1; i <= Energy; i++)
		{
			if (abc[dist][i] < minb)
				minb = abc[dist][i];
		}
		cout << "#" << t + 1 << " " << minb / 60 << " " << minb % 60 << endl;
	}
	return 0;
}

INPUT :
Input order :
Total test cases
Total Energy(10) Total Dist(5)
Next 5 lines - input for 5 different paces in min,sec and energy order

eg.
Total_energy Total_distance
Min(pace1) sec(pace1) engery_consumption(pace1)
Min(pace2) sec(pace2) engery_consumption(pace2)
Min(pace3) sec(pace3) engery_consumption(pace3)
Min(pace4) sec(pace4) engery_consumption(pace4)
Min(pace5) sec(pace5) engery_consumption(pace5)

********************


2
10 5
6 19 6
6 29 5
6 39 4
6 49 3
6 59 2
600 40
3 11 20
3 18 16
3 36 14
3 41 13
3 53 12    =>answer : 137min 11sec for 2nd TC

// MY CODE
// DP Solution

#include <iostream>
#define max_dist 602
#define max_energy 42
#define big_num 999999
using namespace std;
int time_energy[5][2];
int dp[41][601];
int total_energy, total_distance;

int solve(int x, int j)
{
	int temp = 999999;
	for (int i = 0; i < 5; i++)
	{
		if (j - time_energy[i][1] > 0)
		{
			if ((time_energy[i][0] + dp[x - 1][j - time_energy[i][1]]) < temp)
				temp = time_energy[i][0] + dp[x - 1][j - time_energy[i][1]];
		}
	}
	return temp;
}
int main()
{
	int t;
	cin >> t;
	for (int p = 0; p < t; p++)
	{

		cin >> total_energy >> total_distance;
		for (int i = 0; i < 5; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			time_energy[i][0] = a * 60 + b;
			time_energy[i][1] = c;
		}
		for (int i = 0; i <= total_energy; i++)
		{
			for (int j = 0; j <= total_distance; j++)
			{
				dp[j][i] = big_num;
			}
		}

		for (int i = 0; i < 5; i++)
		{
			dp[1][time_energy[i][1]] = time_energy[i][0];
		}

		for (int i = 2; i <= total_distance; i++)
		{
			for (int j = 1; j <= total_energy; j++)
			{
				dp[i][j] = solve(i, j);
			}
		}
		int temp = big_num;
		for (int i = 1; i <= total_energy; i++)
		{
			if (dp[total_distance][i] < temp)
			{
				temp = dp[total_distance][i];
			}
		}
		cout << "#" << t + 1 << " " << temp / 60 << " " << temp % 60 << endl;
	}
}

// Recursion Solution

#include <iostream>
#define big_num 999999
using namespace std;
int time_energy[5][2];
int total_energy, total_distance;
int glob = 999999;
void rec_func(int index, int rem_energy, int rem_dist, int curr_time)
{
	if (rem_energy < 0)
		return;
	if (rem_dist <= 0)
	{
		if (curr_time < glob)
			glob = curr_time;
		return;
	}
	if (curr_time > glob)
		return;

	if (index == 0)
	{
		rec_func(0, rem_energy - time_energy[0][1], rem_dist - 1, curr_time + time_energy[0][0]);
	}
	if (index == 0 || index == 1)
	{
		rec_func(1, rem_energy - time_energy[1][1], rem_dist - 1, curr_time + time_energy[1][0]);
	}
	if (index == 0 || index == 1 || index == 2)
	{
		rec_func(2, rem_energy - time_energy[2][1], rem_dist - 1, curr_time + time_energy[2][0]);
	}
	if (index == 0 || index == 1 || index == 2 || index == 3)
	{
		rec_func(3, rem_energy - time_energy[3][1], rem_dist - 1, curr_time + time_energy[3][0]);
	}
	if (index == 0 || index == 1 || index == 2 || index == 3 || index == 4)
	{
		rec_func(4, rem_energy - time_energy[4][1], rem_dist - 1, curr_time + time_energy[4][0]);
	}
}

int main()
{
	int t;
	cin >> t;
	for (int p = 0; p < t; p++)
	{

		cin >> total_energy >> total_distance;
		for (int i = 0; i < 5; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			time_energy[i][0] = a * 60 + b;
			time_energy[i][1] = c;
		}
		glob = 999999;
		rec_func(0, total_energy, total_distance, 0);
		cout << "#" << t + 1 << " " << glob / 60 << " " << glob % 60 << endl;
	}
}

&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&samsung - interview - questions 2 of 2 votes 28 Answers

																					Mr.Kim has to deliver refrigerators to N customers.From the office,
	he is going to visit all the customers and then return to his home.Each location of the office, his home, and the customers is given in the form of integer coordinates(x, y)(0≤x≤100, 0≤y≤100).The distance between two arbitrary locations(x1, y1) and (x2, y2) is computed by | x1 - x2 | + | y1 - y2 |, where | x | denotes the absolute value of x; for
	instance, | 3 |= | -3 |= 3. The locations of the office, his home, and the customers are all distinct.You should plan an optimal way to visit all the N customers and return to his among all the possibilities.

																		   You are given the locations of the office,
		Mr.Kim’s home, and the customers;
the number of the customers is in the range of 5 to 10. Write a program that, starting at the office, finds a(the)
shortest path visiting all the customers and returning to his home.Your program only have to report the distance of a(the) shortest path.



You don’t have to solve this problem efficiently. You could find an answer by looking up all the possible ways. If you can look up all the possibilities well, you will get a perfect score.

[Constraints]

5≤N≤10. Each location (x,y) is in a bounded grid, 0≤x≤100, 0≤y≤100, and x, y are integers.



[Input]

You are given 10 test cases. Each test case consists of two lines; the first line has N, the number of the customers, and the following line enumerates the locations of the office, Mr. Kim’s home, and the customers in sequence. Each location consists of the coordinates (x,y), which is reprensented by ‘x y’.


Mr. Kim_TSP

#include <stdio.h>
#define MAX 100000
struct vertex{
	int x;
	int y;
};
int n;
struct vertex home, office, customers[10];
int abs(int num){
	if(num >= 0) return num;
	return (-1*num);
}
int dist(int i, int j){
	if (i == 0) return(abs(office.x - customers[j-1].x) + abs(office.y - customers[j-1].y));
	return(abs(customers[i-1].x - customers[j-1].x) + abs(customers[i-1].y - customers[j-1].y));
}
int map[11][11];
int visited_all;
int dp[2048][11];
int min(int a, int b){
	if (a >= b) return b;
	return a;
}
int solve(int mask,int pos){
	if (mask == visited_all){
		return (abs(customers[pos - 1].x - home.x) + abs(customers[pos - 1].y - home.y));
	}
	if (dp[mask][pos] != -1){
		return dp[mask][pos];
	}
	int ans = MAX;
	for (int customer = 0; customer < n + 1; customer++){
		if ((mask&(1 << customer)) == 0){
			int n_ans = map[pos][customer] + solve((mask | 1 << customer), customer);
			ans = min(ans, n_ans);
		}
	}
	dp[mask][pos] = ans;
	return dp[mask][pos];
}
int main(){
	int T;
	freopen("Text.txt", "r", stdin);
	/*
	If you remove the statement below, your program's output may not be recorded
	when your program is aborted due to the time limit.
	For safety, please use setbuf(stdout, NULL); statement.
	*/
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++){
		scanf("%d", &n);
		visited_all = (1 << (n+1)) - 1;
		scanf("%d", &office.x);
		scanf("%d", &office.y);
		scanf("%d", &home.x);
		scanf("%d", &home.y);
		for (int i = 0; i < n; i++){
			scanf("%d", &customers[i].x);
			scanf("%d", &customers[i].y);
		}
		for (int i = 0; i < (1 << (n+1)); i++){
			for (int j = 0; j < n+1; j++){
				dp[i][j] = -1;
			}
		}
		for (int i = 0; i < n + 1; i++){
			for (int j = i; j < n + 1; j++){
				if (i == j){
					map[i][j] = 0;
				}
				else{
					map[i][j] = dist(i, j);
					map[j][i] = map[i][j];
				}
			}
		}
		printf("#%d %d",test_case,solve(1,0));
	}
}



#######################################



There is one spaceship. X and Y co-odinate of source of spaceship and destination spaceship is given. There are N number of warmholes each warmhole has 5 values.
First 2 values are starting co-ordinate of warmhole and after that value no. 3 and 4 represents ending co-ordinate of warmhole and last 5th value is represents cost to pass through this warmhole. Now these warmholes are bi-direction.
Now the to go from (x1,y1) to (x2,y2) is abs(x1-x2)+abs(y1-y2).
The main problem here is to find minimum distance to reach spaceship from source to destination co-ordinate using any number of warm-hole. It is ok if you wont use any warmhole.


Wormhole

// Adv Test: Intersteller  - finding shortest path between two nodes by utilzing the worm holes.
#include <stdio.h>
#include <conio.h>

//sample inputs are at the end of the program

int adj[13][13];	//matrix representation of start and end node + entry and exit as vertices of the worm hole
int X[13];			//x coordinate of all vertices of start and end node + entry and exit as vertices of the worm hole
int Y[13];			//y coordinate of (same as above)
int W[5];			// time from one vertices to another.  This is comes as input for every given worm hole.
int V;              //total number of vertices include tart and end node + entry and exit as vertices of the worm hole
int visited[13];	//visited the node or not
int key[13];		//Key - maintain the minimum time to reach from SOURCE to other vertices.

int getMin()		//function to find the next available minimum travel time vertex.
{
	int min = 100000;		//assume this is the max time - we call it infinity
	int min_vertex=1;		//next available vertex with minimum cost from the source.
	int i;

	for (i = 1; i <= V; i++)
	{
		if (min>key[i] && visited[i] == 0)
		{
			min = key[i];
			min_vertex = i;		//found the next available vertex with minimium cost and not visited as condition.
		}
	}
	return min_vertex;
}

int dijkstra(int adj[][13])          //  standard algorithm to compute shortest path from given source to any other vertex within a given graph.
{
	int i;
	for (i = 1; i <= V; i++){
		key[i] = 100000;
		visited[i] = 0;
	}//infinity initialized as time from source to destination (all vertices
	key[1] = 0;			//as the time is zero from source to source.  Hence it is zero.

	for (int i = 1; i <= V; i++)		//This loop for rest of the vertices will find minimium time from source to other vertices.
	{
		int u = getMin();
		visited[u] = 1;
		for (int v = 1; v <= V; v++)
		{
			if (key[u] + adj[u][v] < key[v])
				key[v] = key[u] + adj[u][v];			//adding the min time at the intermediate destination node from the source, which over write all infinite value with actuals.
		}
	}
	return key[2];// As 2 is the destination node here. 
}

int intersteller(int X[], int Y[])   // this function will setup out matrix graph and finally call dijkstra algorithm
{
	for (int i = 1; i <= V + 1; i++)
	{
		for (int j = 1; j <= V + 1; j++)   //calculate the min time between any 2 vertex (populating our full graph)
		{
			adj[i][j] = (X[i] - X[j] > 0 ? X[i] - X[j] : X[j] - X[i]) + (Y[i] - Y[j] > 0 ? Y[i] - Y[j] : Y[j] - Y[i]);
adj[j][i] = adj[i][j];
}
}

int j = 0;
for (int i = 3; i < V;) // updating min time between entry and exit point of the worm holes. This comes as input.
{
	adj[i][i + 1] = W[j];
	adj[i + 1][i] = W[j++];
	i = i + 2;
}

for (int i = 1; i <= V; i++)
{
	for (int j = 1; j <= V; j++)
		printf("%d ", adj[i][j]);
	printf("\n");
}
return dijkstra(adj);
}

int AnswerN;

int main()
{
	int T;
	freopen("Text.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		int i = 1;
		int n;
		scanf("%d", &n); // number of warmholes.

		scanf("%d%d", &X[i], &Y[i]);
		i++;
		scanf("%d%d", &X[i], &Y[i]);
		i++;
		AnswerN = 0;
		V = 2 * n + 2; // Total of warmhole gates, source and destination.
		int k = 0;
		for (int j = 1; j <= n; j++)
		{
			scanf("%d%d", &X[i], &Y[i]);
			i++;
			scanf("%d%d%d", &X[i], &Y[i], &W[k]);
			i++;
			k++;
		}
		for (int i = 0; i < n; i++)
		{
			printf("%d ", W[i]);
		}
		printf("\n");

		i = 1;
		int j = 2; // 1 : source, 2 : destination
		int s_d = (X[i] - X[j] > 0 ? X[i] - X[j] : X[j] - X[i]) + (Y[i] - Y[j] > 0 ? Y[i] - Y[j] : Y[j] - Y[i]);

		if (n == 0)
		{
			AnswerN = s_d;
		}
		else
			AnswerN = intersteller(X, Y);

		printf("#%d %d\n", test_case, AnswerN);
	}

	return 0;
}

/*  Smaple inputs..
5     // Number of test cases

0     // number of worm holes
0 0 60 60 // co-ordinates of start and end points.

1			// number of worm holes
0 0 2 0		// co-ordinates of start and end points.
1 0 1 2 0   // Co-ordinates of entry/exit and exit/entry with time taken to travel through the worm hole.

1
0 0 60 60
40 40 20 20 20

2
100 50 10 5
80 40 10 6 10
80 10 70 40 5

3
500 500 1000 1000
501 501 999 999 1000
1 1 499 499 100
1000 999 0 0 200
*/
