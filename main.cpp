#include <iostream> 

using namespace std; 

	void increase_temp(int* temp, int amount) {
		if (temp != nullptr){
			*temp += amount;
		}
	} 

void display_temp(const int* temp) {
	if (temp != nullptr) {
		cout << "Current Temparture: " << *temp << "C\n";
	} else {
		cout << "No tempature sensor available!\n";
	}
}

int main() {

	cout << "MEMORY EXPLORER\n"; 
	cout << "-----------------------\n\n"; 

	int cpuTemp = 62; 
	int gpuTemp = 55; //celsius
	double ramUsage = 7.5; //GB 
	char systemStatus = 'N'; // N = Normal 

	cout <<  "PART 1: HARDWARE MEMORY ADDRESSES\n"; 

	cout <<  "CPU TEMP: " << cpuTemp << " C\n"; 
	cout << "CPU ADDRESS: " << &cpuTemp << endl; 
	cout << "CPU Size: " << sizeof(cpuTemp) << " bytes\n\n";


	 cout <<  "GPU TEMP: " << gpuTemp << " C\n"; 
         cout << "GPU ADDRESS: " << &gpuTemp << endl; 
         cout << "GPU Size: " << sizeof(gpuTemp) << " bytes\n\n";


	 cout <<  "RAM USAGE: " << ramUsage << " C\n"; 
         cout << "RAM ADDRESS: " << &ramUsage << endl; 
         cout << "RAM Size: " << sizeof(ramUsage) << " bytes\n\n";


	 cout <<  "SYSTEM STATUS: " << systemStatus << " C\n"; 
         cout << "STATUS ADDRESS: " << static_cast<const void*>(&systemStatus) << endl; 
         cout << "STATUS Size: " << sizeof(systemStatus) << " bytes\n\n"; 

         // part 2 create pointers 

         cout << "PART 2:  HARDWARE POINTERS\n"; 

         int* cpuPtr = &cpuTemp; 
         double* ramPtr = &ramUsage; 

         cout << "CPU Temp: " << cpuTemp << endl; 
         cout << "CPU Address: " << &cpuTemp << endl; 
         cout << "Pointer Stores: " << cpuPtr << endl; 
         cout << "Pointer Address: " << &cpuPtr << endl; 

         cout << "GPU Temp: " << ramUsage << endl; 
         cout << "GPU Address: " << &ramUsage << endl; 
         cout << "Pointer Stores: " << ramPtr << endl; 
         cout << "Pointer Address: " << &ramPtr << endl; 

	cout << "PART 3: DEREFERENCING POINTERS\n"; 

	cout << "CPU Temp: " << cpuTemp << endl; 
	cout << "CPU Pointer Address: " << cpuPtr << endl; 
	cout << "CPU Deferenced Value: " << *cpuPtr << endl; 

	cout << endl; 

	cout << "RAM Usage: " << ramUsage << endl; 
	cout << "RAM Dereferenced Value: " << *ramPtr << endl; 


	cout << "\nPART 4: UPDATING HARDWARE READINGS\n"; 

	cout << "Orginal CPU Temp: " << cpuTemp << endl; 
	*cpuPtr = 78; 

	 cout << "Updated CPU Temp: " << cpuTemp << endl; 
	 cout << "Value through the pointer: " << *cpuPtr << endl; 

	 *ramPtr += 1.5; 

	 cout << "\nUpdated RAM Usage: " << ramUsage << endl;
	 
	 cout << "\nPART 5: SENSOR AVAILABILITY (nullptr)\n"; 
	 
	 int* sensorPtr = nullptr; 
	 
	 if (sensorPtr == nullptr) 
	 {
	 cout << "No temp sensor selected\n";
	 
	 }  

	 sensorPtr = &cpuTemp; 
	 if (sensorPtr != nullptr) {

	cout << "CPU sensor connected.\nCurrent reading: " << *sensorPtr << endl;
	 }

	cout << "\nPART 6: SWITCHING SENSORS\n\n"; 
	cout << "Active sensor: CPU, Reading: " << *sensorPtr << endl; 

	//actual switching part 
	sensorPtr = &gpuTemp; 

	cout << "Active sensor: GPU, Reading: " << *sensorPtr << endl;

	*sensorPtr = 65; 

	cout << "Updated GPU temp: " << gpuTemp << endl; 
	cout << "CPU temp: " << cpuTemp << endl;

	cout << "\nPART 7: POINTERS VS REFERENCES\n\n"; 

	// create reference to the cpu temp 
	int& cpuRef = cpuTemp; 

	// create a pint to the cpu temp 
	int* currentPtr = &cpuTemp; 

	cout << "CPU Temp: " << cpuTemp << endl; 
	cout << "Reference Value: " << cpuRef << endl; 
	cout << "Pointer Value: " << *currentPtr  << endl;
	
	
	cpuRef = 82; 

	cout << "After increasing through reference, CPU Temp: " << cpuTemp << endl; 

	*currentPtr = 85; 

	cout << "After increasing through pointer, CPU Temp: " << cpuTemp << endl;

	cout << "\nPART 8: POINTER FUNCTION PARAMETERS\n\n"; 

	cout << "Before CPU update: " << endl; 
	 display_temp(&cpuTemp); 

	//simulate cpu rising by 5deg 
	increase_temp(&cpuTemp, 5); 

	cout << "After CPU update: " << endl;
	 display_temp(&cpuTemp); 


	 increase_temp(&gpuTemp, 5); 

         cout << "After GPU update: " << endl;
         display_temp(&gpuTemp);
         
         cout << "Unavailable sensor: "; 
         display_temp(nullptr);
         
         cout << "\nPART 9: TEMPERTURE HISTORY\n"; 
         
         // simulated readings collected over time 
         int temperatures[5] = {62, 65, 68, 72, 75}; 
         
         // pointer to first element (default) 
         int* tempHPtr = temperatures; 
         
         cout << "Temperatures readings: \n"; 
         
         for (int i = 0; i < 5; i++) {
         	cout << "Reading " << i + 1 << ": " << temperatures[i] << endl;
         } 

         cout << "Memory Addresses:\n"; 

         for (int i = 0; i < 5; i++) { 
                 cout << "Reading " << i + 1 << "Address: " << &temperatures[i] << endl;
         }

          cout << "\nPointer Arithmetic\n"; 

          cout << "First Reading: " << *tempHPtr << endl; 
          cout << "Second Reading: " << *(tempHPtr + 1) << endl; 
          cout << "Third reading: " << *(tempHPtr + 2) << endl;


	return 0;
}


