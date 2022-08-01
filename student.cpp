class student
{
private:
    int age;
    int roll;
public:
    //Default constractor
    student()
    {
        cout << "called Default constractor." << endl;
    }
    student(int age) //paramiterise(1) constracture.
    {
        cout << "called paramiterise(1) constractor." << endl;
        this->age = age;
    }
    student(int age, int roll) //paramiterise(2) constractor.
    {
        cout << "called paramiterise(2) constractor." << endl;
        this->age = age;
        this->roll = roll;
    }
    ~student() //Destructor.
    {
        cout << "called Destructor." << endl;
    }
    void setRoll(int roll) //for set roll;
    {
        this->roll = roll;
    }
    int getRoll() //get roll
    {
        return roll;
    }
    void Display()
    {
        cout << age << " " << roll << endl;
    }
};