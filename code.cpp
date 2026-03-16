#include<iostream>
using namespace std;

class Patient {
public:
    int pid;
    string pname;
    int page;
    string pdisease;
    Patient* next;

    Patient(int id, string name, int age, string disease) {
        pid = id;
        pname = name;
        page = age;
        pdisease = disease;
        next = NULL;
    }
};

class Doctor {
public:
    int did;
    string dname;
    string specialization;
    Doctor* next;

    Doctor(int id, string name, string spec) {
        did = id;
        dname = name;
        specialization = spec;
        next = NULL;
    }
};

class HMS {
private:
    Patient* patientHead;
    Doctor* doctorHead;

public:
    HMS() {
        patientHead = NULL;
        doctorHead = NULL;
    }

    void addPatient() {
        int id, age;
        string name, disease;

        cout << "Enter Patient ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Patient Name: ";
        getline(cin, name);

        cout << "Enter Patient Age: ";
        cin >> age;
        cin.ignore();

        cout << "Enter Disease: ";
        getline(cin, disease);

        Patient* newPatient = new Patient(id, name, age, disease);

        if (patientHead == NULL) {
            patientHead = newPatient;
        } else {
            Patient* temp = patientHead;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newPatient;
        }

        cout << "Patient added successfully!\n";
    }

    void viewPatients() {
        if (patientHead == NULL) {
            cout << "No patients found.\n";
            return;
        }

        Patient* temp = patientHead;
        while (temp != NULL) {
            cout << "\nPatient ID: " << temp->pid << endl;
            cout << "Name: " << temp->pname << endl;
            cout << "Age: " << temp->page << endl;
            cout << "Disease: " << temp->pdisease << endl;
            cout << "-------------------------\n";
            temp = temp->next;
        }
    }

    Patient* searchPatient(int id) {
        Patient* temp = patientHead;
        while (temp != NULL) {
            if (temp->pid == id) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void addDoctor() {
        int id;
        string name, spec;

        cout << "Enter Doctor ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Doctor Name: ";
        getline(cin, name);

        cout << "Enter Specialization: ";
        getline(cin, spec);

        Doctor* newDoctor = new Doctor(id, name, spec);

        if (doctorHead == NULL) {
            doctorHead = newDoctor;
        } else {
            Doctor* temp = doctorHead;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newDoctor;
        }

        cout << "Doctor added successfully!\n";
    }

    void viewDoctors() {
        if (doctorHead == NULL) {
            cout << "No doctors available.\n";
            return;
        }

        Doctor* temp = doctorHead;
        while (temp != NULL) {
            cout << "\nDoctor ID: " << temp->did << endl;
            cout << "Name: Dr. " << temp->dname << endl;
            cout << "Specialization: " << temp->specialization << endl;
            cout << "-------------------------\n";
            temp = temp->next;
        }
    }

    void assignDoctorToPatient() {
        int pid, did;

        cout << "Enter Patient ID: ";
        cin >> pid;

        cout << "Enter Doctor ID: ";
        cin >> did;

        Patient* patient = searchPatient(pid);

        Doctor* temp = doctorHead;
        Doctor* doctor = NULL;

        while (temp != NULL) {
            if (temp->did == did) {
                doctor = temp;
                break;
            }
            temp = temp->next;
        }

        if (patient != NULL && doctor != NULL) {
            cout << "\nDr. " << doctor->dname
                 << " is assigned to Patient "
                 << patient->pname << endl;
        } else {
            cout << "Invalid Patient ID or Doctor ID.\n";
        }
    }

    void generateBill() {
        int pid;
        cout << "Enter Patient ID: ";
        cin >> pid;

        Patient* patient = searchPatient(pid);

        if (patient == NULL) {
            cout << "Patient not found.\n";
            return;
        }

        double consultationFee, testFee, medicineFee;

        cout << "Enter Consultation Fee: ";
        cin >> consultationFee;

        cout << "Enter Test Fee: ";
        cin >> testFee;

        cout << "Enter Medicine Fee: ";
        cin >> medicineFee;

        double total = consultationFee + testFee + medicineFee;

        cout << "\n========= BILL =========\n";
        cout << "Patient Name: " << patient->pname << endl;
        cout << "Consultation Fee: " << consultationFee << endl;
        cout << "Test Fee: " << testFee << endl;
        cout << "Medicine Fee: " << medicineFee << endl;
        cout << "------------------------\n";
        cout << "Total Amount: " << total << endl;
        cout << "========================\n";
    }
};

int main() {
    HMS hms;
    int choice;

    while (true) {
        cout << "\n===== HOSPITAL MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Patient\n";
        cout << "2. View Patients\n";
        cout << "3. Add Doctor\n";
        cout << "4. View Doctors\n";
        cout << "5. Assign Doctor to Patient\n";
        cout << "6. Generate Bill\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            hms.addPatient();
            break;
        case 2:
            hms.viewPatients();
            break;
        case 3:
            hms.addDoctor();
            break;
        case 4:
            hms.viewDoctors();
            break;
        case 5:
            hms.assignDoctorToPatient();
            break;
        case 6:
            hms.generateBill();
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}