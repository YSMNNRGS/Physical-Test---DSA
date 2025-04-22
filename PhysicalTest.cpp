#include<iostream>
using namespace std;

struct Patient{
	int patientID, hieght, wieght, visionNo;
	string testStatus;
	Patient* next;
	int data;

	Patient(int p, int h, int w, int v, string t, Patient* n, int d){
		patientID = p;
		hieght = h;
		wieght = w;
		visionNo = v;
		testStatus = t;
		next = n;
		data = d;
	}
};

class PhysicalTest{
	Patient* front = NULL;
	Patient* rear = NULL;

	public:
	void AddPatient(int patientID, int hieght, int wieght, int visionNo, string testStatus, int data){
		Patient* newPatient = new Patient(patientID, hieght, wieght, visionNo, testStatus, NULL, data);
		if (rear == NULL){
			front = rear = newPatient;
		} else{
			rear->next = newPatient;
			rear = newPatient;
		}
	}

	void dischargePatient(){
		if (front == NULL){
			cout<<"Empty queue";
			return;
		}
		Patient* temp = front;
		front = front->next;
		if (front == NULL){
			rear = NULL;
		}
		delete temp;
	}
	
	void removeSendPatient(){
		if (front != NULL || front->next== NULL){
			cout<<" Patient 2nd in the line has left the line\n";
		}
	}

	void DisplayPatient(){
		Patient* temp = front;
		while (temp != NULL){
			cout<<"Patient id: "<<temp->patientID<<" ";
			cout<<" Patient Hieght: "<<temp->hieght<<" Patient Weight: "<<temp->wieght<<" Patient eyes sight vision number: "<<temp->visionNo;
			cout<<" Patient test status: "<<temp->testStatus;
			temp = temp->next;

		}
	}
};

int main(){
	PhysicalTest patient1;
	patient1.AddPatient(39849, 175, 65, 1, " done", 2);
	patient1.AddPatient(39850, 180, 65, 2, " pending", 2);
	patient1.AddPatient(39851, 171, 65, 1, " pending", 2);
	patient1.AddPatient(39852, 160, 65, 2, " done", 2);
	patient1.AddPatient(39853, 175, 65, 1, " done", 2);
	patient1.AddPatient(39854, 172, 65, 1, " pending", 2);
	patient1.AddPatient(39855, 171, 65, 2, " done", 2);
	patient1.removeSendPatient();
	
	patient1.DisplayPatient();

	
	
	return 0;
}
