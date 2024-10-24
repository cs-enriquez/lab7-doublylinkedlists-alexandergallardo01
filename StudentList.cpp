	#include "StudentList.h"
	using namespace std;

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
		student->next = head;
       if (head != nullptr) {
    head->prev = student;
     } 
      else {
    tail = student;  // If the list was empty
     }
     head = student;
     numStudents++;
    }
	

	//add a Node with a student to the back (tail) of the list.
	void StudentList::addBack(Student s) {
		Node *student = new Node(s);
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
		while(current != nullptr){
			std::cout << current->data.name << " ";
			current = current->next;
		}
	}

	// Remove the Node with the student at the back (tail) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
	void StudentList::popBack() {
		
		if (tail == nullptr){
			std::cout<< "List is empty" << endl;
			return;
		}
		else{
			Node *temp = tail -> prev;
			delete tail;
			tail = temp;
			if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;  // List is now empty
    }
		}
		numStudents --;
	}

	// Remove the Node with the student at the front (head) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
	void StudentList::popFront() {
		if (head == nullptr){
			std::cout << "List is empty" << endl;
			return ;
		}
		else{
			Node *temp = head -> next;
			delete head;
			head = temp;
			if (head != nullptr) {
        head->prev = nullptr;
    } 
	else {
        tail = nullptr;  // List is now empty
    }
		}
		numStudents --;

	}

	//insert a student at the position "index".
	// for this list, count head as index 0
	// if index is outside of current list range, 
	// print a message and insert the student at the back of the list
	// the previous Node at your target index should be moved forward. "For exampe, Node with student at index i, becomes index i+1" 
	// Remember that you already have methods that can add students to the front or back of list if needed! Don't repeat this code.
	void StudentList::insertStudent(Student s, int index) {
		
		if (index >= numStudents){
	    std:: cout << "Index is out bounds, will add at the end" << " ";
		addBack(s);

}
       else{
		Node *student = new Node(s);
		Node *current = head;
		for(int j = 0; j <index; j++){
			current = current -> next;
		}
		student->next = current->next;
		if (current->next != nullptr) {
         current->next->prev = student;
}
        current->next = student;
        student->prev = current;
        numStudents++;
     }
	
	}

	

	//find the student with the given id number and return them
	// if no student matches, print a message 
	// and create and return a dummy student object
	Student StudentList::retrieveStudent(int idNum) {
		Node *current = head;
		while(current!= nullptr){
			if((current->data.id) == idNum){
				return current->data;
			}
			current = current->next;
		}
		std:: cout << "There is no student with matching id" << endl;
		Student dummy;
		return dummy;
	}

	// Remove a Node with a student from the list with a given id number
	// If no student matches, print a message and do nothing
	void StudentList::removeStudentById(int idNum) {
		Node *current = head;
		while (current != nullptr) {
    if (current->data.id == idNum) {
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }
		numStudents--;
        delete current;
        
        return;
    }
    current = current->next;
}
std::cout << "No student matches" << std::endl;
	}

	//Change the gpa of the student with given id number to newGPA
	void StudentList::updateGPA(int idNum, float newGPA) {
		Node *current = head;
		while(current != nullptr){
			if((current->data.id) == idNum){
				current -> data.GPA = newGPA;
				return;
			}
			current = current->next;
	}
	std::cout << "No student matches" << std::endl;
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
	void StudentList::mergeList(StudentList &otherList) {
		tail->next = otherList.head;  
        otherList.head->prev = tail;  
        tail = otherList.tail;  
        numStudents += otherList.numStudents;
    otherList.head = nullptr;
    otherList.tail = nullptr;
    otherList.numStudents = 0;
}

		
	

	//create a StudentList of students whose gpa is at least minGPA.
	//Return this list.  The original (current) list should
	//not be modified (do not remove the students from the original list).
	StudentList StudentList::honorRoll(float minGPA) {
		StudentList honorroll;
		Node *current = head;
		while(current != nullptr){
		if((current->data.GPA) >= minGPA){
				honorroll.addBack(current->data);
			}
			current = current->next;
		}


		return honorroll;
	}
