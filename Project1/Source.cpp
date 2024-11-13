#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//parent class for all display subclasses
class Display {
public:
	string displayType;
	void deviceDisplay();
};
//parent class for all battery subclasses
class Battery {
public:
	string batteryType;
	void deviceBattery();
};
//parent class for all processor subclasses
class Processor {
public:
	string processorType;
	void deviceProcessor();
};


class SmartphoneDisplay : public Display {
public:
	void deviceDisplay() {
		cout << displayType << endl;
	}
	SmartphoneDisplay() {
		displayType = "Display: Smartphone";
	}
};
class SmartphoneBattery : public Battery {
public:
	void deviceBattery() {
		cout << batteryType << endl;
	}
	SmartphoneBattery() {
		batteryType = "Battery: Smartphone";
	}
};
class SmartphoneProcessor : public Processor {
public:
	void deviceProcessor() {
		cout << processorType << endl;
	}
	SmartphoneProcessor() {
		processorType = "Processor: Smartphone";
	}
};
//Smartphone as a whole
class Smartphone : public SmartphoneDisplay, public SmartphoneBattery, public SmartphoneProcessor {
private:
public:
	Smartphone() {
		SmartphoneDisplay* tempDisplay;
		tempDisplay = new SmartphoneDisplay;
		SmartphoneBattery* tempBattery;
		tempBattery = new SmartphoneBattery;
		SmartphoneProcessor* tempProcessor;
		tempProcessor = new SmartphoneProcessor;
	}
};

//Tablet as a whole
class TabletDisplay : public Display {
public:
	void deviceDisplay() {
		cout << displayType << endl;
	}
	TabletDisplay() {
		displayType = "Display: Tablet";
	}
};
class TabletBattery : public Battery {
public:
	void deviceBattery() {
		cout << batteryType << endl;
	}
	TabletBattery() {
		batteryType = "Battery: Tablet";
	}
};
class TabletProcessor : public Processor {
public:
	void deviceProcessor() {
		cout << processorType << endl;
	}
	TabletProcessor() {
		processorType = "Processor: Tablet";
	}
};
class Tablet : public TabletDisplay, public TabletBattery, public TabletProcessor {
private:
public:
	Tablet() {
		TabletDisplay* tempDisplay;
		tempDisplay = new TabletDisplay;
		TabletBattery* tempBattery;
		tempBattery = new TabletBattery;
		TabletProcessor* tempProcessor;
		tempProcessor = new TabletProcessor;
	}
};

//Laptop as a whole
class LaptopDisplay : public Display {
public:
	void deviceDisplay() {
		cout << displayType << endl;
	}
	LaptopDisplay() {
		displayType = "Display: Laptop";
	}
};
class LaptopBattery : public Battery {
public:
	void deviceBattery() {
		cout << batteryType << endl;
	}
	LaptopBattery() {
		batteryType = "Battery: Laptop";
	}
};
class LaptopProcessor : public Processor {
public:
	void deviceProcessor() {
		cout << processorType << endl;
	}
	LaptopProcessor() {
		processorType = "Processor: Laptop";
	}
};
class Laptop : public LaptopDisplay, public LaptopBattery, public LaptopProcessor {
private:
public:
	Laptop() {
		LaptopDisplay* tempDisplay;
		tempDisplay = new LaptopDisplay;
		LaptopBattery* tempBattery;
		tempBattery = new LaptopBattery;
		LaptopProcessor* tempProcessor;
		tempProcessor = new LaptopProcessor;
	}
};

//Smartwatch as a whole
class SmartwatchDisplay : public Display {
public:
	void deviceDisplay() {
		cout << displayType << endl;
	}
	SmartwatchDisplay() {
		displayType = "Display: Smartwatch";
	}
};
class SmartwatchBattery : public Battery {
public:
	void deviceBattery() {
		cout << batteryType << endl;
	}
	SmartwatchBattery() {
		batteryType = "Battery: Smartwatch";
	}
};
class SmartwatchProcessor : public Processor {
public:
	void deviceProcessor() {
		cout << processorType << endl;
	}
	SmartwatchProcessor() {
		processorType = "Processor: Smartwatch";
	}
};
class Smartwatch : public SmartwatchDisplay, public SmartwatchBattery, public SmartwatchProcessor {
private:
public:
	Smartwatch() {
		SmartwatchDisplay* tempDisplay;
		tempDisplay = new SmartwatchDisplay;
		SmartwatchBattery* tempBattery;
		tempBattery = new SmartwatchBattery;
		SmartwatchProcessor* tempProcessor;
		tempProcessor = new SmartwatchProcessor;
	}
};

//Overarching class for Device
class DeviceFactory : public Smartphone, public Tablet, public Laptop, public Smartwatch {
public:

	virtual void createSmartphone(int counter) {
		if (counter < 2) {
			Smartphone* ptr_Smartphone;
			ptr_Smartphone = new Smartphone;
			ptr_Smartphone->deviceDisplay();
			ptr_Smartphone->deviceBattery();
			ptr_Smartphone->deviceProcessor();
			delete ptr_Smartphone;
		}
		else
			cout << "Error! Trying to create too many instances of Smartphone. Ignoring request" << endl;
	}
	virtual void createTablet(int counter) {
		if (counter < 2) {
			Tablet* ptr_Tablet;
			ptr_Tablet = new Tablet;
			ptr_Tablet->deviceDisplay();
			ptr_Tablet->deviceBattery();
			ptr_Tablet->deviceProcessor();
			delete ptr_Tablet;
		}
		else
			cout << "Error! Trying to create too many instances of Tablet. Ignoring request" << endl;
	}
	virtual void createLaptop(int counter) {
		if (counter < 2) {
			Laptop* ptr_Laptop;
			ptr_Laptop = new Laptop;
			ptr_Laptop->deviceDisplay();
			ptr_Laptop->deviceBattery();
			ptr_Laptop->deviceProcessor();
			delete ptr_Laptop;
		}
		else
			cout << "Error! Trying to create too many instances of Laptop. Ignoring request" << endl;
	}
	virtual void createSmartwatch(int counter) {
		if (counter < 2) {
			Smartwatch* ptr_Smartwatch;
			ptr_Smartwatch = new Smartwatch;
			ptr_Smartwatch->deviceDisplay();
			ptr_Smartwatch->deviceBattery();
			ptr_Smartwatch->deviceProcessor();
			delete ptr_Smartwatch;
		}
		else
			cout << "Error! Trying to create too many instances of Smartwatch. Ignoring request" << endl;
	}
};

class Client : public DeviceFactory, public Display, public Battery, public Processor {

};

int main() {
	ifstream file;
	string fileLine;
	Client start;
	int smartphoneCount = 0;
	int tabletCount = 0;
	int laptopCount = 0;
	int smartwatchCount = 0;
	file.open("Text.txt");
	if (file.is_open()) {
		while (file.good()) {
			file >> fileLine;
			if (fileLine == "Smartphone") {
				start.createSmartphone(smartphoneCount);
				smartphoneCount++;
			}
			else if (fileLine == "Tablet") {
				start.createTablet(tabletCount);
				tabletCount++;
			}
			else if (fileLine == "Laptop") {
				start.createLaptop(laptopCount);
				laptopCount++;
			}
			else if (fileLine == "Smartwatch") {
				start.createSmartwatch(smartwatchCount);
				smartwatchCount++;
			}
			else
				cout << "Invalid device type! Skipping request" << endl << endl;
		}
	}
	return 0;
}
