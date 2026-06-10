# Student Record Management System

A console-based Student Record Management System developed in C that enables efficient storage, retrieval, and management of student information. The project demonstrates core concepts of C programming, including structures, file handling, functions, and data management operations.

## Overview

The Student Record Management System provides a simple and user-friendly interface for maintaining student records. It allows users to perform CRUD (Create, Read, Update, Delete) operations on student data while ensuring data persistence through file storage.

## Features

- Add new student records
- View all student records
- Search for a student by ID
- Update existing student information
- Delete student records
- Store records using file handling
- Menu-driven interface for easy navigation

## Technologies Used

- C Programming Language
- File Handling
- Structures
- Functions
- Standard C Libraries

## Key Concepts Implemented

- Structured data management using `struct`
- File operations (`fopen`, `fclose`, `fread`, `fwrite`, `fprintf`, `fscanf`)
- Modular programming
- Data validation
- Menu-driven application design

## Project Structure

```text
Start
  |
  v
Display Menu
  |
  v
User Choice
  |
  +----> Add Student ------+
  |                        |
  +----> Search Student ---|
  |                        |
  +----> Update Student ---|--> File Operations --> Save Data
  |                        |
  +----> Delete Student ---|
  |                        |
  +----> Display Records --+
  |
  v
Exit
```
The application supports the following operations:

1. Add Student Record
2. Display All Records
3. Search Student Record
4. Update Student Record
5. Delete Student Record
6. Exit

## Learning Outcomes

This project helped in understanding:

- File management in C
- Data organization using structures
- Implementation of CRUD operations
- Modular and maintainable code design
- Console-based application development

## Future Enhancements

- Password-based authentication
- Student attendance tracking
- Grade and GPA calculation
- Report generation
- Database integration (MySQL/SQLite)
- Graphical User Interface (GUI)


---

If you find this project useful, feel free to star the repository and provide feedback.
