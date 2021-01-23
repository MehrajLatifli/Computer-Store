#include <iostream>
#include <assert.h>
#include <string.h>
#include <string>

using namespace std;

class Computer {
	int order_id;
	char* vendor;
	char* model;
	double cpu_hz;
	int cpu_core;
	int ram;
	char* videocard;
	char* monitor;
	bool isSSD;
	double disk_size;
public:

	static int id;

	Computer() :order_id(0), vendor(nullptr), model(nullptr), cpu_hz(0.0), cpu_core(0), ram(0), videocard(nullptr), monitor(nullptr), isSSD(false), disk_size(0.0) {}

	Computer(const char* vendor, const char* model, double cpu_hz, int cpu_core, int ram, const char* videocard, const char* monitor, bool isSSD, double disk_size)
	{
		this->order_id = ++id;
		setVendor(vendor);
		setModel(model);
		setCpu_hz(cpu_hz);
		setCpu_core(cpu_core);
		setRam(ram);
		setVideocard(videocard);
		setMonitor(monitor);
		setIsSSD(isSSD);
		setDisk_size(disk_size);
	}

	Computer(const Computer& other)
	{
		this->order_id = other.id;
		setVendor(other.vendor);
		setModel(other.model);
		setCpu_hz(other.cpu_hz);
		setCpu_core(other.cpu_core);
		setRam(other.ram);
		setVideocard(other.videocard);
		setMonitor(other.monitor);
		setIsSSD(other.isSSD);
		setDisk_size(other.disk_size);
	}

	Computer& operator=(const Computer& other)
	{
		this->order_id = other.id;
		setVendor(other.vendor);
		setModel(other.model);
		setCpu_hz(other.cpu_hz);
		setCpu_core(other.cpu_core);
		setRam(other.ram);
		setVideocard(other.videocard);
		setMonitor(other.monitor);
		setIsSSD(other.isSSD);
		setDisk_size(other.disk_size);

		return *this;
	}

	Computer(Computer&& other)
	{

		setVendor(other.vendor);
		setModel(other.model);
		setCpu_hz(other.cpu_hz);
		setCpu_core(other.cpu_core);
		setRam(other.ram);
		setVideocard(other.videocard);
		setMonitor(other.monitor);
		setIsSSD(other.isSSD);
		setDisk_size(other.disk_size);

		other.cpu_hz = 0.0;
		other.cpu_core = 0;
		other.ram = 0;
		other.isSSD = 0;
		other.disk_size = 0.0;

		delete other.model;
		other.model = nullptr;

		delete other.vendor;
		other.vendor = nullptr;

		delete other.videocard;
		other.videocard = nullptr;

		delete other.monitor;
		other.monitor = nullptr;
	}

	static int getCurrentId() {
		return id;
	}

	void setCurrentId(int id) {
		assert(id > 0);
		this->order_id = ++id;
	}

	char* getVendor() const {
		return vendor;
	}
	int getId() {
		return order_id;
	}
	void setVendor(const char* vendor) {
		assert(vendor != nullptr);
		int l = strlen(vendor);
		this->vendor = new char[l + 1];
		strcpy_s(this->vendor, l + 1, vendor);
	}

	char* getModel() const {
		return model;
	}

	void setModel(const char* model) {
		assert(model != nullptr);
		int l = strlen(model);
		this->model = new char[l + 1];
		strcpy_s(this->model, l + 1, model);
	}

	double getCpu_hz() const {
		return cpu_hz;
	}

	void setCpu_hz(double cpu_hz) {
		this->cpu_hz = cpu_hz;

	}

	int getCpu_core() const {
		return cpu_core;
	}

	void setCpu_core(int cpu_core) {
		this->cpu_core = cpu_core;

	}

	int getRam() const {
		return ram;
	}

	void setRam(int ram) {
		this->ram = ram;

	}

	char* getVideocard() const {
		return videocard;
	}

	void setVideocard(const char* videocard) {
		assert(videocard != nullptr);
		int l = strlen(videocard);
		this->videocard = new char[l + 1];
		strcpy_s(this->videocard, l + 1, videocard);
	}


	char* getMonitor() const {
		return monitor;
	}

	void setMonitor(const char* monitor) {
		assert(monitor != nullptr);
		int l = strlen(monitor);
		this->monitor = new char[l + 1];
		strcpy_s(this->monitor, l + 1, monitor);
	}

	bool getIsSSD()const {
		return isSSD;
	}

	void setIsSSD(bool isSSD) {
		this->isSSD = isSSD;

	}

	double getDisk_size() const {
		return disk_size;
	}

	void setDisk_size(double disk_size) {
		this->disk_size = disk_size;

	}



	void show() const {

		cout << " Computer ID: \t\t\t" << this->order_id << endl;
		cout << " Computer Vendor: \t\t" << getVendor() << endl;
		cout << " Computer Model: \t\t" << getModel() << endl;
		cout << " Computer Cpu_hz: \t\t" << getCpu_hz() << " GHz" << endl;
		cout << " Computer Cpu_core: \t\t" << getCpu_core() << " Core" << endl;
		cout << " Computer Videocard: \t\t" << getVideocard() << endl;
		cout << " Computer Monitor: \t\t" << getMonitor() << endl;
		cout << " Computer SSD: \t\t\t" << getIsSSD() << endl;
		cout << " Computer disk size: \t\t" << getDisk_size() << " TB" << endl;
		cout << " \n ============================================================================================================= \n";
	}

	friend ostream& operator<<(ostream& out, const Computer& comp);
	friend istream& operator>>(istream& in, Computer& comp);

	~Computer() {
		delete[]  model;
		delete[] vendor;
		delete[]  videocard;
		delete[]  monitor;
	}
};

int Computer::id = 0;

ostream& operator<<(ostream& out, const Computer& comp) {

	out << " Computer Vendor: \t\t\t" << comp.getVendor() << endl;
	out << " Computer Model: \t\t" << comp.getModel() << endl;
	out << " Computer Cpu_hz: \t\t" << comp.getCpu_hz() << " GHz" << endl;
	out << " Computer Cpu_core: \t\t" << comp.getCpu_core() << " Core" << endl;
	out << " Computer Videocard: \t\t" << comp.getVideocard() << endl;
	out << " Computer Monitor: \t\t" << comp.getMonitor() << endl;
	out << " Computer SSD: \t\t\t" << comp.getIsSSD() << endl;
	out << " Computer disk size: \t\t" << comp.getDisk_size() << " TB" << endl;
	out << " \n ============================================================================================================= \n";

	return out;
}


istream& operator>>(istream& in, Computer& comp) {

	cout << "Enter the Vendor: ";
	char* buffer = new char[100];
	in.getline(buffer, 100);
	comp.setVendor(buffer);
	delete[]buffer;

	buffer = new char[100];
	cout << "Enter the Model : ";
	in.getline(buffer, 100);
	comp.setModel(buffer);
	delete[]buffer;

	cout << "Enter the Cpu_hz : " << endl;;
	double Cpu_hz;
	in >> Cpu_hz;
	comp.setCpu_hz(Cpu_hz);

	cout << "Enter the Cpu_core: ";
	int Cpu_core;
	in >> Cpu_core;
	comp.setCpu_core(Cpu_core);

	buffer = new char[100];
	cout << "Enter the Videocard : ";
	in.getline(buffer, 100);
	comp.setVideocard(buffer);
	delete[]buffer;

	buffer = new char[100];
	cout << "Enter the Monitor : ";
	in.getline(buffer, 100);
	comp.setMonitor(buffer);
	delete[]buffer;

	cout << "Have the SSD? (y -1; n-0) : " << endl;;
	bool IsSSD;
	in >> IsSSD;
	comp.setIsSSD(IsSSD);


	return in;
}






class ComputerStore {
	char* store_name;
	char* store_address;
	int count;
	Computer** computers;
public:
	ComputerStore() :store_name(nullptr), store_address(nullptr), count(0), computers(nullptr) {}


	ComputerStore(const char* store_name, const char* store_address, int count, Computer** computers)
	{
		setCount(count);
		setStore_name(store_name);
		setStore_address(store_address);
		setComputer(computers);

	}

	ComputerStore& operator=(const ComputerStore& other)
	{
		setCount(other.count);
		setStore_name(other.store_name);
		setStore_address(other.store_address);
		setComputer(other.computers);

	}

	char* getStore_name() const {
		return store_name;
	}

	void setStore_name(const char* store_name) {
		assert(store_name != nullptr);
		int l = strlen(store_name);
		this->store_name = new char[l + 1];
		strcpy_s(this->store_name, l + 1, store_name);
	}

	char* getStore_address() const {
		return store_address;
	}

	void setStore_address(const char* store_address) {
		assert(store_address != nullptr);
		int l = strlen(store_address);
		this->store_address = new char[l + 1];
		strcpy_s(this->store_address, l + 1, store_address);
	}

	int getCount() const {
		return count;
	}

	void setCount(int count) {
		this->count = count;

	}

	Computer** getComputer()const {
		return computers;
	}

	void setComputer(Computer** computers) {
		int c = getCount();
		this->computers = new Computer * [c];
		for (size_t i = 0; i < c; i++)
		{
			this->computers[i] = computers[i];
		}
	}
private:
	int getIndexOfElement(int id) {
		for (size_t i = 0; i < getCount(); i++)
		{
			if (computers[i]->getId() == id) {
				return i;
			}
		}
		return -1;
	}
public:
	void deleteComputer(int id) {
		int c = getCount();
		int index = getIndexOfElement(id);
		if (index != -1) {
			auto newcomputers = new Computer * [c - 1]{};
			for (size_t i = 0; i < index; i++)
			{
				newcomputers[i] = computers[i];
			}
			for (size_t i = index, i2 = index + 1; i < c - 1; i++, i2++)
			{
				newcomputers[i] = computers[i2];
			}
			delete[]computers;
			computers = newcomputers;
			newcomputers = nullptr;
			setCount(c - 1);

		}



	}

	void addComputer(Computer*& newComputer) {
		int c = getCount();
		auto newComputers = new Computer * [c + 1];
		for (size_t i = 0; i < c; i++)
		{
			newComputers[i] = computers[i];
		}
		newComputers[c] = newComputer;
		setCount(c + 1);

		computers = newComputers;
		newComputers = nullptr;
	}

	friend ostream& operator<<(ostream& out, const ComputerStore& computerStoreother);

	~ComputerStore() {
		delete[]  store_name;
		delete[] store_address;

	}
};

ostream& operator<<(ostream& out, const ComputerStore& computerStoreother) {
	for (size_t i = 0; i < computerStoreother.getCount(); i++)
	{
		computerStoreother.computers[i]->show();
	}
	return out;
}

void main() {
	Computer* c1 = new Computer("Asus", "TUF H370-PRO GAMING", 3.80, 4, 16, "nVidia Geforce GTX 1050", "Asus TUF VG259QM", false, 2.0);
	Computer* c2 = new Computer("ASRock", "Z390 Pro4 ", 3.6, 8, 32, "Asus Geforce GTX 1070", "Acer Nitro VG272 Xbmiipx", true, 2.0);
	Computer* c3 = new Computer("ASRock", "Z390 Pro4 ", 3.6, 8, 32, "Asus Geforce GTX 1080", "Acer Nitro VG272 Xbmiipx", false, 2.0);
	Computer** computers = new Computer * [2]{ c1,c2 };
	ComputerStore cs("Custom Computer", "Tebriz kuc 28 ", 2, computers);
	cout << cs;
	cout << "\n ************************************************************************************************************* \n";
	cout << "\n After add \n";
	cout << "\n ************************************************************************************************************* \n";
	cout << " \n ============================================================================================================= \n";
	cs.addComputer(c3);
	cout << cs;
	cout << "\n ************************************************************************************************************* \n";
	cout << "\n After delete \n";
	cout << "\n ************************************************************************************************************* \n";
	cout << " \n ============================================================================================================= \n";
	cs.deleteComputer(1);

	cout << cs;
}