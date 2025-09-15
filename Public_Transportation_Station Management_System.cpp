#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Forward declarations
class Passenger;

class Vehicle;

class Passenger {
private:
    string name;
    int id;
    vector<Vehicle*> bookedVehicles;

public:
    Passenger(string n, int i);
    void bookRide(Vehicle* v);
    void cancelRide(Vehicle* v);
    void displayInfo() const; // ? ch? khai báo, chua d?nh nghia
    int getId() const;
    string getName() const;
};

class Vehicle {
protected:
    string route;
    int capacity;
    int bookedSeats;
    string status;

public:
    Vehicle(string r, int c, string s = "On-time");
    virtual double calculateTravelTime(double distance);
    bool bookPassenger(Passenger* p); // ? ch? khai báo
    void cancelPassenger(Passenger* p);
    virtual void displayInfo() const;
    virtual string getRoute() const;
    string getStatus() const;
};


class ExpressBus : public Vehicle {
private:
    double speed;

public:
    ExpressBus(string r, int c, double s)
        : Vehicle(r, c), speed(s) {}

    double calculateTravelTime(double distance) override {
        return (distance / speed) * 0.8;
    }

    void displayInfo() const override {
        cout << "Express Bus on route " << route << ", Speed: " << speed
             << " km/h, Status: " << status << ", Capacity: " << capacity
             << ", Booked: " << bookedSeats << endl;
    }
};

class Station {
private:
    string name;
    string location;
    string type;
    vector<Vehicle*> schedules;

public:
    Station(string n, string l, string t)
        : name(n), location(l), type(t) {}

    bool addSchedule(Vehicle* v) {
        if (schedules.size() >= 10) {
            cout << "Station " << name << " has reached max schedules.\n";
            return false;
        }
        schedules.push_back(v);
        cout << "Added vehicle to station " << name << ".\n";
        return true;
    }

    void removeSchedule(string route) {
        for (auto it = schedules.begin(); it != schedules.end(); ++it) {
            if ((*it)->getRoute() == route) {
                schedules.erase(it);
                cout << "Removed vehicle from station " << name << ".\n";
                return;
            }
        }
        cout << "Vehicle not found in station " << name << ".\n";
    }

    void displaySchedules() const {
        cout << "--- Schedules at " << name << " Station ---\n";
        for (Vehicle* v : schedules) {
            v->displayInfo();
        }
    }
};

void showMenu() {
    cout << "\n===== HE THONG QUAN LY TRAM VAN TAI CONG CONG =====\n";
    cout << "1. Them tuyen duong (Route)\n";
    cout << "2. Them xe bus thuong\n";
    cout << "3. Them xe express bus\n";
    cout << "4. Dat ve cho hanh khach\n";
    cout << "5. Hien thi xe dang chay (On-time)\n";
    cout << "6. Hien thi xe bi tre (Delayed)\n";
    cout << "7. Hien thi thong tin tat ca xe\n";
    cout << "8. Hien thi thong tin hanh khach\n";
    cout << "0. Thoat chuong trinh\n";
    cout << "Chon chuc nang: ";
}

// ------------------------ Passenger method definitions ------------------------
Passenger::Passenger(string n, int i) : name(n), id(i) {}

void Passenger::bookRide(Vehicle* v) {
    bookedVehicles.push_back(v);
}

void Passenger::cancelRide(Vehicle* v) {
    for (auto it = bookedVehicles.begin(); it != bookedVehicles.end(); ++it) {
        if (*it == v) {
            bookedVehicles.erase(it);
            return;
        }
    }
}

void Passenger::displayInfo() const {
    cout << "Passenger: " << name << ", ID: " << id << ", Booked Vehicles:\n";
    for (Vehicle* v : bookedVehicles) {
        cout << "- " << v->getRoute() << endl;
    }
}

int Passenger::getId() const { return id; }
string Passenger::getName() const { return name; }


// ------------------------ Vehicle method definitions ------------------------

Vehicle::Vehicle(string r, int c, string s)
    : route(r), capacity(c), bookedSeats(0), status(s) {}

double Vehicle::calculateTravelTime(double distance) {
    return distance / 40.0; // gi? d?nh t?c d? 40 km/h
}

bool Vehicle::bookPassenger(Passenger* p) {
    if (bookedSeats >= capacity) {
        cout << "Xe " << route << " da day.\n";
        return false;
    }
    bookedSeats++;
    p->bookRide(this);
    cout << "Dat ve thanh cong tren tuyen " << route << ".\n";
    return true;
}

void Vehicle::cancelPassenger(Passenger* p) {
    if (bookedSeats > 0) bookedSeats--;
    p->cancelRide(this);
    cout << "Huy ve tren tuyen " << route << ".\n";
}

void Vehicle::displayInfo() const {
    cout << "Xe tuyen " << route << ", Trang thai: " << status
         << ", Suc chua: " << capacity << ", Da dat: " << bookedSeats << endl;
}

string Vehicle::getRoute() const {
    return route;
}

string Vehicle::getStatus() const {
    return status;
}



int main() {
    vector<Vehicle*> vehicles;
    vector<Passenger*> passengers;
    int choice;
    
    // Kh?i t?o s?n d? li?u m?u
	Vehicle* bus1 = new Vehicle("Route A", 3); // xe bus thu?ng
	Vehicle* express1 = new ExpressBus("Route B", 2, 60); // xe express bus
	
	vehicles.push_back(bus1);
	vehicles.push_back(express1);
	
	Passenger* p1 = new Passenger("Nguyen Van A", 101);
	Passenger* p2 = new Passenger("Tran Thi B", 102);
	
	passengers.push_back(p1);
	passengers.push_back(p2);
	
	// Ð?t vé cho hành khách
	bus1->bookPassenger(p1);
	express1->bookPassenger(p2);


    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string route;
                cout << "Nhap ten tuyen duong: ";
                getline(cin, route);
                cout << "Da them tuyen duong: " << route << endl;
                break;
            }
            case 2: {
                string route;
                int capacity;
                cout << "Nhap tuyen duong: "; getline(cin, route);
                cout << "Nhap suc chua: "; cin >> capacity; cin.ignore();
                vehicles.push_back(new Vehicle(route, capacity));
                cout << "Da them xe bus thuong.\n";
                break;
            }
            case 3: {
                string route;
                int capacity;
                double speed;
                cout << "Nhap tuyen duong: "; getline(cin, route);
                cout << "Nhap suc chua: "; cin >> capacity;
                cout << "Nhap toc do (km/h): "; cin >> speed; cin.ignore();
                vehicles.push_back(new ExpressBus(route, capacity, speed));
                cout << "Da them xe express bus.\n";
                break;
            }
            case 4: {
                string name;
                int id;
                cout << "Nhap ten hanh khach: "; getline(cin, name);
                cout << "Nhap ID hanh khach: "; cin >> id; cin.ignore();
                Passenger* p = new Passenger(name, id);
                passengers.push_back(p);

                cout << "Danh sach xe:\n";
                for (int i = 0; i < vehicles.size(); ++i) {
                    cout << i << ". "; vehicles[i]->displayInfo();
                }

                int vIndex;
                cout << "Chon xe (so thu tu): "; cin >> vIndex; cin.ignore();
                if (vIndex >= 0 && vIndex < vehicles.size()) {
                    vehicles[vIndex]->bookPassenger(p);
                } else {
                    cout << "Lua chon khong hop le.\n";
                }
                break;
            }
            case 5: {
                cout << "--- Xe dang chay (On-time) ---\n";
                for (Vehicle* v : vehicles)
                    if (v->getStatus() == "On-time")
                        v->displayInfo();
                break;
            }
            case 6: {
                cout << "--- Xe bi tre (Delayed) ---\n";
                for (Vehicle* v : vehicles)
                    if (v->getStatus() == "Delayed")
                        v->displayInfo();
                break;
            }
            case 7: {
                cout << "--- Tat ca xe ---\n";
                for (Vehicle* v : vehicles)
                    v->displayInfo();
                break;
            }
            case 8: {
                cout << "--- Thong tin hanh khach ---\n";
                for (Passenger* p : passengers)
                    p->displayInfo();
                break;
            }
            case 0:
                cout << "Da thoat chuong trinh. Tam biet!\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai.\n";
        }

    } while (choice != 0);

    // Giai phong bo nho
    for (Vehicle* v : vehicles) delete v;
    for (Passenger* p : passengers) delete p;

    return 0;
}

