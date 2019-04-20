#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Program{
	int index; //Program Number
	vector<int> current; //number of programs it currently has
	vector<int> required; //number of programs more that it needs to run

	Program(){
		index = 0;
		current.resize(0);
		required.resize(0);
	}

	Program(int i, int a, int b){
		index = i;
		current.resize(a);
		required.resize(b);
	}

};

//Banker's Algorithm
vector<Program> bankersAlgorithm(vector<Program> ProcessList, vector<int> ResourceList, int numType)
{  // ProcessList = requesting processes, ResourceList = available resources, numType = number of resource types
   stringstream out;
   out << "Safe Order of Processes: ";
   while( !ProcessList.empty() )
   {
      bool found = false; // safely allocated to a process?
      for( int j=0; j<ProcessList.size(); j++ )
      {
      	 Program p = ProcessList[j];

      	 bool canAlloc = true;
         for(int i=0; i<numType; i++){
         	if(p.required[i] > ResourceList[i]){
         		canAlloc = false;
         		break;
         	}
         }

         if(canAlloc)
         {  // can allocate resources; grant process' requests
     		out << p.index << " ";
            for(int i=0; i<numType; i++){
            	ResourceList[i]+=p.current[i];
            }
            ProcessList.erase( ProcessList.begin() + j );
            //need to subtract an index because you remove a process
            j--;
            found = true;
         }
      }
      if( !found )
         return ProcessList;
   }
   out << endl;
   cout << out.str();

   return ProcessList;
}


int main(){
	int numTest;
	cin >> numTest;

	for(int a=0; a<numTest; a++){

		//START Accepting user input
		int numProc; int numType;
		cin >> numProc;
		cin >> numType;

		//list for Resources
		vector<int> ResourceList;
		ResourceList.resize(numType);

		for (int b=0; b<numType; b++){
			int tempA;
			cin >> tempA;
			ResourceList[b] = tempA;
		}

		//list for Processes
		vector<Program> ProcessList;
		ProcessList.resize(numProc);

		for(int b=0; b<numProc; b++){
			Program p(b+1, numType, numType);
			for(int c=0; c<numType; c++){
				int tempC;
				cin >> tempC;
				p.current[c] = tempC;
			}
			ProcessList[b] = p;
		}

		for(int b=0; b<numProc; b++){
			Program p = ProcessList[b];
 			for(int c=0; c<numType; c++){
				int tempR;
				cin >> tempR;
				p.required[c] = tempR;
			}
			ProcessList[b] = p;
		}

		//END Accepting user input

		//FOR DEBUGGING ONLY
		cout << "Available Resources: ";
		for(int i=0; i<numType; i++){
			cout << ResourceList[i] << " ";
		}
		cout << endl;

		for(int i=0; i<numProc; i++){
			Program p = ProcessList[i];
			cout << "Process: " << p.index << endl;
			cout << "Current: ";
			for(int j=0; j<numType; j++){
				cout << p.current[j] << " ";
			}
			cout << endl;
			cout << "Required: ";
			for(int j=0; j<numType; j++){
				cout << p.required[j] << " ";
			}
			cout << endl;
		}


		//check for deadlocks with Banker's Algorithm
		vector<Program> result = bankersAlgorithm(ProcessList, ResourceList, numType);

		if(result.empty()){
			cout << "No deadlock has occured." << endl;
		}
		else{
			cout << "Deadlock has occured. Processes include: ";

			//Terminate all processes that are part of the deadlock
			for(int i=0; i<result.size(); i++){
				Program p = result[i];
				cout << p.index << " ";
				for(int j=0; j<numType; j++){
					p.required[j]+=p.current[j];
					ResourceList[j]+=p.current[j];
					p.current[j]=0;
				}
				ProcessList[p.index-1]=p;
			}
			cout << endl;

			//run Banker's Algorithm again
			bankersAlgorithm(ProcessList, ResourceList, numType);
		}
	}

	return 0;
}