	#include <iostream>
	using namespace std;	
	#include "StudentList.h"
	// Define a constructor to initialize the list. The list starts with no Students
    StudentList::StudentList(){
		head = nullptr;
		tail = nullptr;
		numStudents = 0;
	}

	// return the number of students currently in the list
	int StudentList::listSize(){
		return numStudents;
	}

	//add a Node with a student to the front (head) of the list.
	void StudentList::addFront(Student s) {
		if(head != tail){
			Node *n = new Node(s);
			head->prev = n;
			n->next = head;
			head = n;
		}
		else{
			Node *nn = new Node(s);
			head = nn;
		}
		numStudents++;
	}

	//add a Node with a student to the back (tail) of the list.
	void StudentList::addBack(Student s) {
		if(tail != head){
			Node *n = new Node(s);
			tail->next = n;
			n->prev = tail;
			tail = n;
		}
		else{
			Node *nn = new Node(s);
			tail = nn;
		}
		numStudents++;
	}

	//Print out the names of each student in the list.
	void StudentList::printList() {
		Node *curr = tail; 
    	if(tail != nullptr){
			while(curr != nullptr){
		    	cout << curr->data.name << " ";
				curr = curr->next;
			}	
			cout << endl;
		}
		else{
			cout << "Empty list!" << endl;
		}
	}

	// Remove the Node with the student at the back (tail) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
	void StudentList::popBack() {
		Node *t = tail;
		if(head != nullptr){
			if(head == tail){
				head = nullptr;
				tail = nullptr;
			}
			else{
				tail = tail->prev;
				tail->next = nullptr;
			}
			numStudents--;
		}
		else{
			cout << "Error, empty list." << endl;

		}

	}

	// Remove the Node with the student at the front (head) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
	void StudentList::popFront() {
		Node *t = head;
		if(head != nullptr){
		 	if(head == tail){
				head = nullptr;
				tail = nullptr;
			}
			else{
				head = head->next;
				head->prev = nullptr;
			}
			numStudents--;
		}
		else{
			cout << "Error, empty stack!"<< endl;
		}

	}

	//insert a student at the position "index".
	// for this list, count head as index 0
	// if index is outside of current list range, 
	// print a message and insert the student at the back of the list
	// the previous Node at your target index should be moved forward. "For exampe, Node with student at index i, becomes index i+1" 
	// Remember that you already have methods that can add students to the front or back of list if needed! Don't repeat this code.
	void StudentList::insertStudent(Student s, int index) {
		Node *t = head;
		Node *n = new Node(s);
		if(index > numStudents){
			cout << "Index does not exist, adding to end of list."<< endl;
			addBack(s);
		}
		if(t = head){
			n->next = t;
			t->prev = n;
			head = n;
			numStudents++;
		}
		else{
			
			for(int i = 0; i < index; i++){
				t = t->next;
			}
			n->prev = t->prev;
			n->next = t;
			t->prev = n;
			n->prev->next = n;
			
			numStudents++;
		}

	}

	//find the student with the given id number and return them
	// if no student matches, print a message 
	// and create and return a dummy student object
	Student StudentList::retrieveStudent(int idNum){
		Student *n;
		n = new Student;
		Node *b = new Node(*n);
		Node *t = head;
		int lpId = 0;
		if(head != nullptr){
			n->id = idNum;
			while(lpId < numStudents){
				while(b->data.id != t->data.id){
					t = t->next;
				}
				lpId++;
			}
			if(b->data.id == t->data.id){
				return t->data;
			}
		}
		return b->data;
	}

	// Remove a Node with a student from the list with a given id number
	// If no student matches, print a message and do nothing
	void StudentList::removeStudentById(int idNum) {
		Node *run = head;
		Student n = retrieveStudent(idNum);
		Node *s = new Node(n);
		int lpId = 0;
		while(lpId < numStudents){
			while(s->data.id != run->data.id){
				run = run->next;
			}
			lpId++;
		}
		if(s->data.id == run->data.id){
			run->next = run->prev;
			run->prev->next = run->next;
		}
		else{
			cout << "Student not found" << endl;
		}
	}

	//Change the gpa of the student with given id number to newGPA
	void StudentList::updateGPA(int idNum, float newGPA) {

	}

	//Add all students from otherList to this list.
	//otherlist should be empty after this operation.
	/*
	For example, if the list has 3 students:
	s1 <-> s2 <-> s3
	and otherList has 2 students
	s4 <-> s5
	then after mergeList the currently list should have all 5 students
	s1 <-> s2 <-> s3 <-> s4 <-> s5
	and otherList should be empty and have zero students.
	*/
	void StudentList::mergeList(StudentList &otherList) {}

	//create a StudentList of students whose gpa is at least minGPA.
	//Return this list.  The original (current) list should
	//not be modified (do not remove the students from the original list).
	StudentList StudentList::honorRoll(float minGPA) {
		StudentList fixthis;
		return fixthis;
	}
