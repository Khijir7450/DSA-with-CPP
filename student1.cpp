class student
{
  public:
  string name;
  int age;
  student(int age, string name)
  {
    this->age = age;
    this->name = name;
  }
  void display()
  {
    cout << this->name << " " << age << endl;
  }
};