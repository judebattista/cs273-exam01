#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

namespace Simulation // NAMESPACE
{
	// STEP 1: Complete the implementation of the Aircraft base class 
	// as described in the UML diagram
	class Aircraft
	{
	protected:
		int num_engines;
	public:
		Aircraft(int num_engines) {
			// STEP 1: Complete the constructor in itialize member variable
			this->num_engines = num_engines;
		};
		virtual void Description() = 0;      // Description is a pure virtual function
	};

	// STEP 2: Complete the Engine class
	class Engine
	{
	private:
		string manuf;
	public:
		Engine() {}
		void set_manuf(string manuf) {
			this->manuf = manuf;
			// STEP 2: initialize the member variable
		}
	};

	// STEP 3:  Define the Glider class as described
	// in the UML diagram.   For this test, DO NOT separate
	// the class implementations into separate cpp and header files.
	class Glider : public Aircraft {
	public:
		// STEP 3: Complete the Glider Constructor
		Glider() : Aircraft(0) {}

		// STEP 3: Complete the Glider Description() method
		void Description() {
			std::cout << "I'm a glider with " << num_engines << " engines.\n";
		}
	};

	// STEP 4:  Define the Boeing777 class as described
	// in the UML diagram.  
	class Boeing777 : public Aircraft {
	private:
		// STEP 4: Define the member variables for the 777
		std::string color;
	public:
		// STEP 4: Complete the Boeing777 Constructor
		Boeing777(int num_engines, std::string color) : Aircraft(num_engines) {
			this->color = color;
		}

		// STEP 4: Complete the Boeing777 Description Method
		void Description() {
			std::cout << "I'm a Boeing 777 with " << num_engines << " engines.\n";
		}
	};


	// STEP 6:  Define the GenericAircraft class as described in the comments in main()
	class GenericAircraft : public Aircraft {
	private:
		// STEP 6: Define the member variables for the Generic Aircraft
		std::string name;
	public:
		// STEP 4: Complete the Boeing777 Constructor
		GenericAircraft(int num_engines, std::string name) : Aircraft(num_engines) {
			this->name = name;
		}

		// STEP 4: Complete the Boeing777 Description Method
		void Description() {
			std::cout << "I'm a " << name << " with " << num_engines << " engines.\n";
		}
	};
}

int main()
{
	Simulation::Aircraft * Airport[4];

	// STEP 5: Assign ONE new Glider AND ONE new Boeing777 object to each of the two elements
	// in the Aiport array.  Remember the classes are defined in the namespace Simulation.
	Airport[0] = new Simulation::Glider();
	Airport[1] = new Simulation::Boeing777(2, "Blue");

	// STEP 6: Create a new class in the Simulation for GenericAircraft.
	// It should derive from Aircraft. It should have the number of
	// engines and aircraft name be parameters passed to the
	// constructor.

	// STEP 7: Create two new instances of your GenericAircraft class
	// and add them to the Airport array.
	// The first instance should be an F18 with 4 engines
	// and the second one should be an F16 with 2 engines.
	Airport[2] = new Simulation::GenericAircraft(4, "F18");
	Airport[3]= new Simulation::GenericAircraft(2, "F16");
	for (int i = 0; i < 4; ++i)
	{
		// This line will output a description of each aircraft
		Airport[i]->Description();
	}

	return 0;
}