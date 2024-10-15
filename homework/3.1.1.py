import csv


class Student:
    def __init__(self, student_id, name, gender, age, scores):
        self.student_id = student_id
        self.name = name
        self.gender = gender
        self.age = age
        self.scores = scores  
    
    def average_score(self):
        """计算三门课程的平均成绩"""
        if len(self.scores) == 0:
            return 0
        return sum(self.scores.values()) / len(self.scores)
    
    def __str__(self):
        return (f"{self.student_id}, {self.name}, {self.gender}, {self.age}, "
                f"{self.scores}, 平均成绩: {self.average_score():.2f}")
        
class Classroom:
    def __init__(self):
        """初始化班级列表，用于存储学生对象"""
        self.students = []

    def add_student(self, student):
        """添加学生到班级列表"""
        self.students.append(student)

    def load_students_from_file(self, file_name):
        try:
            with open(file_name, 'r') as file:
                reader = csv.reader(file)
                for row in reader:
                    student_id, name, gender, age = row[:4]
                    age = int(age)
                    # 将课程成绩转换为字典
                    scores = {}
                    for item in row[4:]:
                        course, score = item.split(':')
                        scores[course] = float(score)
                    # 创建学生对象并添加到班级
                    student = Student(student_id, name, gender, age, scores)
                    self.add_student(student)
        except FileNotFoundError:
            print(f"未找到文件 {file_name}")

    def update_score(self, student_id, course, score):
        for student in self.students:
            if student.student_id == student_id:
                student.scores[course] = score
                print(f"学号 {student_id} 的课程 {course} 成绩更新为 {score}")
                return
        print(f"未找到学号为 {student_id} 的学生")

    def calculate_ranking(self):
        ranked_students = sorted(self.students, key=lambda x: x.average_score())
        print("班级学生按平均成绩排名：")
        for rank, student in enumerate(ranked_students, start=1):
            print(f"排名 {rank} - 学号: {student.student_id}, 姓名: {student.name}, "
                  f"性别: {student.gender}, 年龄: {student.age}, 成绩: {student.scores}, "
                  f"平均成绩: {student.average_score():.2f}")
            
classroom = Classroom()
classroom.load_students_from_file('students.csv') 


classroom.update_score('1', 'English', 95)


classroom.calculate_ranking()

