#include <iostream>
#include <list>
#include <math.h>
#include <fstream>
#include <sstream>

using namespace std;


class dista
{
public:
	int no1;
	int no2;
	double dis;
};

class Route
{
public:
	int node1;
	int node2;
};

class graph
{
public:
	int Node;
	int x;
	int y;
};
list <graph> Graph;
list <Route> route;
list <int> Nodes;
list<dista>dist,finalr;



void readfile()
{
	graph G;
	Route R;
	ifstream myfile;
	myfile.open("Map.txt");
	if (myfile.is_open())
	{
		while (myfile >> G.Node >> G.x >> G.y)
		{
			Graph.push_back(G);
		}
		myfile.close();
	}

	myfile.open("Routes.txt");
	if (myfile.is_open())
	{
		while (myfile >> R.node1 >> R.node2)
		{
			route.push_back(R);
		}
		myfile.close();
	}

}

void breakK (list<dista>D,int a)
{
	dista dx1, dx2;
	list <dista> ::iterator ds;
	for (ds = dist.begin(); ds != dist.end(); ds++)
	{
		dx1.dis = (*ds).dis;
		dx1.no1 = (*ds).no1;
		dx1.no2 = (*ds).no2;
		++ds;
		if ( ds == dist.end())
		{
			list <dista> ::iterator dssss;
			for (dssss = finalr.begin(); dssss != finalr.end(); dssss++)
			{
				if ((*dssss).no1 == dx1.no1 && dx1.no2 == a)
				{
					finalr.erase(dssss);
					finalr.push_back(dx1);
					
					goto exit;
					
				}
				else
				{
					continue;
				}
			}
			
		}
		else{
			dx2.dis = (*ds).dis;
			dx2.no1 = (*ds).no1;
			dx2.no2 = (*ds).no2;
		}

		if (dx1.no1 == dx2.no1)
		{
			if (dx1.dis < dx2.dis)
			{
				finalr.push_back(dx1);
			}
			else
			{
				finalr.push_back(dx2);
			}
		}

		else 
		{
			finalr.push_back(dx1);
			--ds;
		}


	}
	exit:
	list <dista> ::iterator dss;
	for (dss = finalr.begin(); dss != finalr.end(); dss++)
	{
		cout << (*dss).no1 << "    " << (*dss).no2 << "    " << (*dss).dis<<endl;
	}

	list <dista> ::iterator dsss;
	for (dsss = dist.begin(); dsss != dist.end(); dsss++)
	{
		cout <<" NONO //"<< (*dsss).no1 << "    " << (*dsss).no2 << "    " << (*dsss).dis << endl;
	}
	


}

void distance(list<graph>G, list<Route>R, int nod1, int nod2)
{
	double sum = 0, sqr1 = 0, sqr2 = 0;

	int x;
	x = nod2;
	Route R1, R2;
	graph G1, G2;
	bool con = true;
	while (con)
	{

		list <Route> ::iterator it;
		for (it = R.begin(); it != R.end(); it++)
		{
			if ((*it).node1 == nod1)
			{
				R1.node1 = (*it).node1;
				R1.node2 = (*it).node2;
				R.erase(it);
				break;

			}
			else
			{
				continue;
			}

		}

		list<graph>::iterator itt;
		for (itt = G.begin(); itt != G.end(); itt++)
		{
			if ((*itt).Node == R1.node1)
			{
				G1.Node = (*itt).Node;
				G1.x = (*itt).x;
				G1.y = (*itt).y;

				continue;


			}
			else if ((*itt).Node == R1.node2)
			{
				G2.Node = (*itt).Node;
				G2.x = (*itt).x;
				G2.y = (*itt).y;
				break;


			}



		}
		sqr1 = pow(G2.x, 2) - pow(G1.x, 2);
		sqr2 = pow(G2.y, 2) - pow(G1.y, 2);

		sum = sqrt(sqr1 - sqr2);


		list <Route> ::iterator count;
		for (count = R.begin(); count != R.end(); count++)
		{
			if ((*count).node1 == nod1)
			{

				R2.node1 = (*count).node1;
				R2.node2 = (*count).node2;
				break;

			}
			else
			{
				R2.node1 = (*count).node1;
				R2.node2 = (*count).node2;
				break;
			}

		}




		Nodes.push_back(G1.Node);

		dista DD;
		DD.no1 = G1.Node;
		DD.no2 = G2.Node;
		DD.dis = sum;

		dist.push_back(DD);

		nod1 = R2.node1;
		nod2 = R2.node2;



		con = false;
		breakK(dist, x);

	}


}



void dijkstra(list<graph>G , list<Route>R , int nod1 , int nod2)
{
	double sum=0 , sqr1=0 , sqr2=0;

	int x;
	x = nod2;
	Route R1,R2;
	graph G1 , G2;
	bool con = true;
	if (nod1 == x)
	{
		
		con = false;
		breakK(dist,x);


		
		
		
		
		
	}
	else
	{

		while (con)
		{

			list <Route> ::iterator it;
			for (it = R.begin(); it != R.end(); it++)
			{
				if ((*it).node1 == nod1)
				{
					R1.node1 = (*it).node1;
					R1.node2 = (*it).node2;
					R.erase(it);
					break;

				}
				else
				{
					continue;
				}

			}

			list<graph>::iterator itt;
			for (itt = G.begin(); itt != G.end(); itt++)
			{
				if ((*itt).Node == R1.node1)
				{
					G1.Node = (*itt).Node;
					G1.x = (*itt).x;
					G1.y = (*itt).y;

					continue;


				}
				else if ((*itt).Node == R1.node2)
				{
					G2.Node = (*itt).Node;
					G2.x = (*itt).x;
					G2.y = (*itt).y;
					break;


				}



			}
			sqr1 = pow(G2.x, 2) - pow(G1.x, 2);
			sqr2 = pow(G2.y, 2) - pow(G1.y, 2);

			sum = sqrt(sqr1 - sqr2);


			list <Route> ::iterator count;
			for (count = R.begin(); count != R.end(); count++)
			{
				if ((*count).node1 == nod1)
				{

					R2.node1 = (*count).node1;
					R2.node2 = (*count).node2;
					break;

				}
				else
				{
					R2.node1 = (*count).node1;
					R2.node2 = (*count).node2;
					break;
				}

			}




			Nodes.push_back(G1.Node);

			dista DD;
			DD.no1 = G1.Node;
			DD.no2 = G2.Node;
			DD.dis = sum;

			dist.push_back(DD);

			nod1 = R2.node1;
			nod2 = R2.node2;


			if (nod2 == x)
			{
				
				con = false;
				distance(G, R, nod1, nod2);
				
			}


			else
			{

				continue;
			}



		}
	}



	




}; 




int main()

{
	
	readfile();

	cout << "enter The Two nodes you need to go from the one to the two" << endl;
	int node1;
	int node2;
	cin >> node1 >> node2;

	



	dijkstra(Graph, route, node1, node2);


	


	
	








	return 0;
}