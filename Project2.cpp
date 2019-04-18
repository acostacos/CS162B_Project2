#include <iostream>
#include <vector>

using namespace std;

struct Program{
	vector<int> current; //number of programs it currently has
	vector<int> required; //number of programs needed for it to run
	Program(){
		current.resize(0);
		required.resize(0);
	}

	Program(int a, int b){
		current.resize(a);
		required.resize(b);
	}

};

int main(){
	int numTest;
	cin >> numTest;

	for(int a=0; a<numTest; a++){
		int numProc; numType;
		cin >> numProc;
		cin >> numType;

		Program procs[numProc];

		for(int b=0; b<numProc; b++){
			Program p(numType, numType);
			for(int c=0; c<numType; c++){
				int tempC;
				cin >> tempC;
				p.current[c] = tempC;
			}
			procs[b] = p;
		}

		for(int b=0; b<numProc; b++){
			Program p = procs[b];
			for(int c=0; c<numType; c++){
				int tempR;
				cin >> tempR;
				p.required[c] = tempR;
			}
		}

		for(int i=0; i<numProc; i++){
			cout << "Program " << i+1 << ": " << endl;
			for(int j=0; j<numType; j++){
				cout << "Current: " << list[i].current.[c] << " ";
			}
			cout << endl;
			for(int j=0; j<numType; j++){
				cout << "Required: " << list[i].required.[c] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}