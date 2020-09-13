#include<bits/stdc++.h>

using namespace std;

#define endl "\n"

class Enter {
    public:
        int v;
        int dist;
};

int MinRoll(int move[], int k, int n) {

	bool *visited = new bool[n];

	for (int i = 0; i < n; i++)
		visited[i] = false;

	queue<Enter> q;

	visited[k] = true;
	Enter s = {0, k};
	q.push(s);

	Enter qe;

	while (!q.empty())
	{
		qe = q.front();
		int v = qe.v;
		if (v == n-1)
			break;
        q.pop();

		for (int j=v+1; j<=(v+6) && j<n; ++j) {
			if (!visited[j]) {
				Enter a;
				a.dist = (qe.dist + 1);
				visited[j] = true;

                if (move[j] != -1)
					a.v = move[j];
				else
					a.v = j;

				q.push(a);
			}
		}
	}

	return qe.dist;
}

int main(){

	int n,k,l,s ;

	cout<<"Enter the winning block number"<<endl;
	cin>>n;

    cout<<"Enter the block from where to check the minimum dice roll required to win"<<endl;
    cin>>k;

	int moves[n];
	for (int i =0; i<n; i++) moves[i] = -1;

    cout<<"Enter number of Ladders present"<<endl;
    cin>>l;

	cout<<"Enter Ladder's start and end"<<endl;
	int j=0;
	for(int i= 0;i<l;i++){
        cout<<"Ladder "<<i+1<<": ";
        cin>>j>>moves[j];
	}

    cout<<"Enter number of snakes present"<<endl;
    cin>>s;

	cout<<"Enter Snake's mouth and tail"<<endl;
	for(int i= 0;i<s;i++){
	    cout<<"snake "<<i<<": ";
        cin>>j>>moves[j];
    }

	cout << "Minimum Dice rolls you should Perform is " << MinRoll(moves, k, n);
	return 0;
}

