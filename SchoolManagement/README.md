# School Management System in C

## Overview
The **School Management System** is a console-based application written in C. It allows users to manage the essential operations of a school, including student management, teacher management, attendance tracking, exam results, and fee management.

This project demonstrates the use of **data structures**, **file handling**, and **modular programming** in C. It also provides a user-friendly interface via a menu-driven system.

---

## Features
1. **Student Management:**
   - Add new students
   - View student details
   - Edit and delete student information

2. **Teacher Management:**
   - Add new teachers
   - View teacher details
   - Edit and delete teacher records

3. **Course Management:**
   - Add and view available courses
   - Assign courses to students and teachers

4. **Attendance Management:**
   - Mark student attendance
   - View attendance records

5. **Exam Management:**
   - Enter and view exam scores
   - Calculate and display grades

6. **Fee Management:**
   - Record fee payments
   - View pending fees for students

---

## Project Structure

📦school-management-system ┣ 📜student.c ┣ 📜teacher.c ┣ 📜attendance.c ┣ 📜exam.c ┣ 📜fees.c ┣ 📜main.c ┣ 📜README.md ┗ 📜school.h


- **student.c**: Handles all student-related functionalities.
- **teacher.c**: Manages teacher-related operations.
- **attendance.c**: Tracks student attendance.
- **exam.c**: Manages exam scores and grades.
- **fees.c**: Handles fee-related operations.
- **main.c**: Contains the main menu and program entry point.
- **school.h**: Header file containing structure definitions and function prototypes.

---

## Technologies Used
- **Programming Language**: C
- **Editor**: Visual Studio Code (or any C IDE)
- **File Handling**: Used for data persistence (saving and retrieving student/teacher records, attendance, etc.).

---

## How to Run the Project

### Prerequisites:
- A C compiler (e.g., GCC)
- Any text editor or IDE (e.g., VS Code)

### Steps to Run:
1. **Clone the repository**:

git clone https://github.com/your-username/school-management-system.git

 
 
2. **Navigate to the project directory**:
3. **Compile the code**:
4. **Run the executable**:



### Note:
All data will be stored in text files (e.g., `students.txt`, `teachers.txt`, etc.) for persistence across sessions.

---

## File Handling
Each module stores data using text files to ensure that records are saved even when the application is closed.

For example:
- Student details are stored in `students.txt`
- Teacher details in `teachers.txt`
- Attendance records in `attendance.txt`

---

## Future Enhancements
- Implement user authentication (admin login) to secure the system.
- Add more advanced reporting features (e.g., generate a full student report including attendance and exam performance).
- Include data backup and restore functionality.

---

## License
This project is open-source and available under the **MIT License**.

---

## Contact
For any queries or suggestions, please feel free to contact me at:  
**Email**: mdjavedshekh777@gmail.com  
**GitHub**: [JAVED-SHEKH](https://github.com/Javed-Shekh)

