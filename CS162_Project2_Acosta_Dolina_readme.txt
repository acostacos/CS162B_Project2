struct Program 
- This is the program structure that represents a process in the processor
- It has the ff fields:
	int index - program identification number
	vector<int> current - number of resources it currently holds
	vector<int> required - number of resources more that it needs to run
- It has a default constructor that sets everything to null
- It has a constructur that takes in three paremeters. It sets the first parameter as the index of the program and the next two to the sizes of the arrays

vector<Program> bankersAlgorithm(vector<Program> ProcessList, vector<int> ResourceList, int numType)
- This is the implementation of Banker's Algorithm used in the code
- It takes in three parameters, the list of processes, the list of available resources and the number of types of resources
- The algorithm ends once the list of processes is empty
- First, it goes through all the processes in the process list. It checks if there are enough resources of each type that it can allocate to the process. If there is, then it will run the process (print the index of the number, add all the resources it holds to the available resources, remove the process from the list of processes)
- If all the processes are run properly, then it prints the output stringstream and returns an empty ProcessList
- Else if not all processes run properly, then it returns the ProcessList with the uncompleted processes

int main()
- This is the main function of the code
- It first accepts all the input as shown in the project specifications
- After this, it will end up with an array of Programs contaning the list of processes and an array of resources containing the available resources
- It then calls bankersAlgorithm and assigns the return value to vector<Program> result
- If it is empty, then that means that the algorithm sucessfully run and there are no deadlocks
- If it is not empty, that means the processes have reached a deadlock and thus the code terminates all processes who are involved in a deadlock. It goes through each program in result and terminates it (adds currently held resources to needed resources, adds currently held resources to available resources, sets all the currently held resources to 0)
- It then calls the bankersAlgorithm function again and the result should be the safe way to run the code.
