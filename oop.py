from abc import abstractmethod
class Employee():
    def __init__(self, name, emp_id, salary):
        self.name = name
        self.emp_id = emp_id
        self.salary = salary
        
    @abstractmethod
    def get_total_salary(self):
        pass
        
    def details(self):
        return f"Emp name is: {self.name}, emp_id is: {self.emp_id}, emp salary is: {self.salary}"
    
class Engineer(Employee):
    def __init__(self, name, emp_id, salary, overtime_hour, overtime_hourrate, experience, specilty):
        self.overtime_hour = overtime_hour
        self.overtime_hourrate = overtime_hourrate
        self.specilty = specilty
        self.experience = experience
        super().__init__(name, emp_id, salary)
        
    def set_overtime_hour(self, overtime_hour):
        self.overtime_hour = overtime_hour
        
    def set_overtime_hourrate(self, overtime_hourrate):
        self.overtime_hourrate = overtime_hourrate
        
    def print(self):
        x = super().details()
        print(x + f", over time hour is: {self.overtime_hourrate}, Over time hour rate: {self.overtime_hourrate}\nEng specilty is: {self.specilty}, Eng exp years: {self.experience}\n")
        
    def get_total_salary(self):
        return self.salary + (self.overtime_hour * self.overtime_hourrate)
        

class Sales(Employee):
    def __init__(self, name, emp_id, salary, gross_rate, commision_rate):
        self.gross_rate = gross_rate
        self.commision_rate = commision_rate
        super().__init__(name, emp_id, salary)
        
    def get_total_salary(self):
        return self.salary + (self.commision_rate * self.gross_rate)
    
    def print(self):
        y = super().details()
        print(y + f", Gross rate is: {self.gross_rate}, commision rate is: {self.commision_rate}\n")