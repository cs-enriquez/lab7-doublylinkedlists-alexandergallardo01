	#include "StudentList.h"

	// Define a constructor to initialize the list. The list starts with no Students
    StudentList::StudentList() {
		head = nullptr;
        tail = nullptr;
        numStudents  = 0;
	}

	// return the number of students currently in the list
	int StudentList::listSize() {
		return numStudents;
	}

	//add a Node with a student to the front (head) of the list.
	void StudentList::addFront(Student s) {
		Node *student = new Node(s);
		student -> next = head;
		head ->prev = student;
		head = student;
     numStudents++;
    }
	

	//add a Node with a student to the back (tail) of the list.
	void StudentList::addBack(Student s) {
		Node *student = new student(s)
		if(head == nullptr){
	    head = student ;
	    tail = student ;
}
       else{
	   tail -> next = student;
	   student ->prev = tail;
	   tail = student;
	   
     }
	 numStudents ++;
	}

	//Print out the names of each student in the list.
	void StudentList::printList() {
		Node *current = head;
		for(current->next != nullptr){
			std::cout << current->name << " ";
			current = current->next;
		}
	}

	// Remove the Node with the student at the back (tail) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
	void StudentList::popBack() {
		
		if (tail == nullptr){
			std::cout<< "List is empty" << endl;
		}
		else(
			Node *temp = tail -> prev;
			delete tail;
			tail = temp;
			tail->next = nullptr;
		)
		numStudents --;
	}

	// Remove the Node with the student at the front (head) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
	void StudentList::popFront() {
		if (head == nullptr){
			std::cout << "List is empty" << endl;
			return -1;
		}
		else{
			Node *temp = head -> next;
			delete head;
			head = temp;
		}
		numstudents --;

	}

	//insert a student at the position "index".
	// for this list, count head as index 0
	// if index is outside of current list range, 
	// print a message and insert the student at the back of the list
	// the previous Node at your target index should be moved forward. "For exampe, Node with student at index i, becomes index i+1" 
	// Remember that you already have methods that can add students to the front or back of list if needed! Don't repeat this code.
	void StudentList::insertStudent(Student s, int index) {
		
		if(i > numStudents-1){
	    std:: cout << "Index is out bounds, will add at the end" << " ";
		addBack(s);
		numStudents ++;

}
       else{
		Node *student = new student(s)
		Node *current = head;
		for(int j = 0; j <index; j++){
			current = current -> next;
		}
		current -> next -> next -> prev = student;
		current -> next = student;
		student -> prev = current;
     }
	 numStudents ++;
	}

	}

	//find the student with the given id number and return them
	// if no student matches, print a message 
	// and create and return a dummy student object
	Student StudentList::retrieveStudent(int idNum) {
		Node *current = head;
		for(current->next != nullptr){
			if((current->data->id) == idNum){
				return current->data;
			}
			current = current->next;
		}
		else{
			std:: cout << "There is no student with matching id" << endl;
		}
		Student dummy;
		return dummy;
	}

	// Remove a Node with a student from the list with a given id number
	// If no student matches, print a message and do nothing
	void StudentList::removeStudentById(int idNum) {}

	//Change the gpa of the student with given id number to newGPA
	void StudentList::updateGPA(int idNum, float newGPA) {}

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
