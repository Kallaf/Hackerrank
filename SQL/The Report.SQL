SELECT Students.NAME, Grades.GRADE, Students.MARKS FROM Students INNER JOIN Grades ON Students.MARKS >=  Grades.MIN_MARK AND Students.Marks <= Grades.Max_Mark WHERE Grades.GRADE > 7 ORDER BY Grades.GRADE DESC,Students.NAME;

SELECT "NULL", Grades.GRADE, Students.MARKS FROM Students INNER JOIN Grades ON Students.MARKS >=  Grades.MIN_MARK AND Students.Marks <= Grades.Max_Mark WHERE Grades.GRADE < 8 ORDER BY Grades.GRADE DESC,Students.Marks;
