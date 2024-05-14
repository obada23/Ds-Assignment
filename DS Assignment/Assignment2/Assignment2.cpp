#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;
using namespace std::chrono;
template <class T>
class ArrayList
{
    protected:
        T* list;
        int maxSize;
        int length;

    public:
        ArrayList(int size=100);
        void print() const;
        virtual void insertAt(int location,const T& item);
        void isItemEqual(int location,const T& item) const;
        virtual void insertEnd(const T& item) ;
        void removeAt(int location);
        int seqSearch(const T& item);
        void insert(const T& insertitem);
        void removeAll(const T& removeItem);
        void findAll(const T& item);
        int min();

};

template <class T>
class OrderedArrayList : public ArrayList<T>
{
    public:
        void insertOrd(const T& item) ;
        int binarySearch(const T& item) const;
        void insertAt(int location,const T& item) override;
        void insertEnd(const T& item) override;
        OrderedArrayList(int size=100);

};
class Student 
{

    private:
        string name;
        string id;
        float gpa;
    
    public:
        Student();
        Student(const string& n,const  string& i,  const float& gpa);
        bool operator==(const Student& other) const;
        bool operator<(const Student& other) const;
        bool operator>(const Student& other) const;
        void setName(const string& n);
        void setId(const string& i);
        void setGpa(const float& g);
        string getId();
        void print();
        void length(int i);

};

Student::Student()
{
    this->name = "Empty";
    this->id = "0000";
    this->gpa = 0;
}
Student::Student(const string &n ,const string &i ,const float &g)
{
    this->name = n;
    this->id = i;
    this->gpa = g;
}

bool Student::operator==(const Student& other) const
{
    return this->id == other.id;
}

bool Student::operator<(const Student& other) const
{
    return this->id < other.id;
}

bool Student::operator>(const Student& other) const
{
    return this->id > other.id;
}

void Student::setName(const string& n)
{
    this->name = n;
}
void Student::setId(const string& i)
{
    this->id = i;
}
void Student::setGpa(const float& g)
{
    this->gpa = g;
}

string Student::getId()
{
    return this->id;
}

void Student::print()
{
    cout << "Name : " << this->name << ", " << "Id : " << this->id << ", " << "gpa : " << this->gpa << endl;   
}

void Student::length(int i)
{
    cout << i << endl;
}

template <class T>
void OrderedArrayList<T>::insertOrd(const T& item)
{
    int mid;
    int first=0;
    int last=this->length-1;
    bool found = false;

    if(this->length==0) 
    {
        this->list[0]=item;
        this->length++;
    }

    else if (this->length==this->maxSize)
        cout << "Cannot insert in full list " << endl; 
    else 
    {
        while(first <= last && !found)
        {
            mid = (first + last) / 2;
            if(this->list[mid]==item)
                found=true;
            else if(this->list[mid]>item)
                last = mid -1;
            else 
                first = mid +1;
        }
        if(found) {
            if(this->list[mid]<item) mid++;
            ArrayList<T>::insertAt(mid,item);}
        else 
        {
            if(this->list[mid]<item) mid++;
            ArrayList<T>::insertAt(mid,item);
        }
    }
}
template <class T>
int OrderedArrayList<T>::binarySearch(const T& item) const
{   
    int first=0;
    int last=this->length-1;
    int mid;
    bool found = false ;

    while(first<=last && !found)
    {
        mid = (first+last)/2;
        if(this->list[mid]==item)
            found = true;
        else if(this->list[mid]<item)
            first = mid + 1;
        else 
            last = mid - 1;
    }
    if(found) return mid;
    else return -1;
}
template <class T>
OrderedArrayList<T>::OrderedArrayList(int size) : ArrayList<T>(size){}

template <class T>
void OrderedArrayList<T>::insertAt(int location,const T& item)
{
    insertOrd(item);
}
template <class T>
void OrderedArrayList<T>::insertEnd(const T& item)
{
    insertOrd(item);
}


template <class T>
ArrayList<T>::ArrayList(int size)
{
    if(size<0)
    {
        cout << "Max size cannot be a negative number reset to 100 " << endl;
        this->maxSize = 100;
    }
    this->maxSize = size;
    this->length = 0;
    this->list = new T[maxSize];
    cout << "Defult ArrayList Is Called " << endl;
}

template <class T>
void ArrayList<T>::print() const
{
    cout << "Max size = " << this->maxSize << endl;
    cout << "Length = " << this->length << endl;
    cout << "List = " ;
    if(this->length==0)
    {
        cout << "Empty";
    }
    else
        for(int i=0; i<this->length; i++)
        {
            cout << this->list[i] << " ";
        }
    cout << endl;
}
template <class T>
    void ArrayList<T>::insertAt(int location, const T& item)
    {

        if(location < 0 || location > this->length)
        {
            cout << "Out of range location" << endl;
            return;
        }

        else if(this->length >= this->maxSize)
        {
           int newMaxSize = this->maxSize*2;
           T* newList = new T [newMaxSize];
           for(int i=0; i<this->length; i++)
           {
                newList[i] = this->list[i];
           }
           delete [] this->list;
           this->maxSize=newMaxSize;
           this->list = newList;

        }
        for(int i=this->length; i>location; i--)
        {
            this->list[i] = this->list[i-1];
        }
           this->list[location] = item;
           this->length++;

    }

    template <class T>
    void ArrayList<T>::isItemEqual(int location,const T& item) const
{
    if(location<0||location>this->length)
    {
        cout << "Out of range location" << endl;
    }
    else if(this->list[location]==item)
    {
        cout << "Item is equal " << endl;
    }
    else 
        cout << "Item is not equal" << endl;

}
template <class T>
    void ArrayList<T>::insertEnd(const T& item)
    {
        if(this->length>=this->maxSize)
        {
           int newMaxSize = this->maxSize*=2;
           T *newList = new T [newMaxSize];
           for (int i=0; i<this->length;i++)
           {
                newList[i] = this->list[i];
           }
           delete [] this->list;
           this->list = newList;
           this->maxSize = newMaxSize;
        }
         list[this->length] = item;
         this->length++;

    }
template <class T>
    void ArrayList<T>::removeAt(int location)
    {
        if(this->length==0)
        {
            cout << "Cannot remove from empty list " << endl;
            return;
        }
        if(location<0)
        {
            cout << "Out of range location " << endl;
            return;
        }

        else if(location>=this->length)
        {
            cout << "Location is empty " << endl;
            return;
        }

        else for(int i=location; i<this->length; i++)
        {
            this->list[i] = this->list[i+1];
        }
        this->length--;

    }
   template <class T> 
 int ArrayList<T>::seqSearch(const T& item)
 {
    int loc;
    for (loc=0; loc<this->length; loc++)
    {
        if(this->list[loc]==item)
        {
            return loc;
        }
        
    }
    if (loc==this->length)
    {
        return -1;
    }
 }
template <class T>
 void ArrayList<T>::insert(const T& insertItem)
 {
    int loc=0;
    if(this->length==0)
    {
        /* list[this->length] = insertItem;
        this->length++; */
        list[this->length++] = insertItem;
    }
    else if(this->maxSize == this->length )
    {
        int newMaxSize = this->maxSize*2;
        T* newList = new T [newMaxSize];
        for (int i=0; i <this->length;i++)
        {
            this->list[i] = newList[i];
        }
        delete [] this->list;
        this->maxSize = newMaxSize;
        this->list = newList;
        loc = seqSearch(insertItem);
        if(loc == -1)
        this->list[this->length] = insertItem;
        this->length++;
    }
   
    else if(this->maxSize>this->length)
    {
        loc = seqSearch(insertItem);
        if(loc == -1)
        this->list[this->length] = insertItem;
        length++;
    }
    else
    cout << "The item to be inserted is alrady in the list " << endl;

 }

 
template <class T>
 void ArrayList<T>::removeAll(const T& removeItem)
 {
    int count=0;
    if(this->length==0)
    {
        cout << "Cannot delete from an empty list " << endl;
    }
    else
    {
        int loc;
        for (loc=0; loc<this->length; loc++)
        {
            if(this->list[loc]==removeItem)
            {
                count++;
            }
            else 
            {
                this->list[loc-count] = list[loc];
            }
        
        }
        this->length-=count;
        if(count==0)
        {
            cout << "The item to be deleted is not in the list " << endl;
        }

    }
 }
template <class T>
 void ArrayList<T>::findAll(const T& item)
{
    bool found = false;
    cout << "The list of the location have item " << item << " is: ";
    for(int i=0; i<this->length; i++)
    {
        if(item == this->list[i])
        {
            cout << i << " ";
            found = true ;
        }
    }
    if(found==false)
    {
        cout << "No item is found ";
    }
    cout << endl;
}
template <class T>
int ArrayList<T>::min()
{
    int min = this->list[0];
    for(int i=0;i<this->length;i++)
    {
        if(list[i]>min) min = min;
        else min = list[i];
    }
    cout << "Min value in the list is: ";
    return min;
}
template <class T>
 void func(ArrayList<T> LL)
 {
    LL.insertAt(170,0);
 }

 string generateUniqueId() 
 { 
    string uniqueId;
    time_t now = time(nullptr); 
    uniqueId = to_string(now); 
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1000, 9999); 
    int randomNumber = dist(gen);
    uniqueId += to_string(randomNumber); 
    return uniqueId;
}

string generateArbitraryName(int length) 
{ 
    string name;
    random_device rd; 
    mt19937 gen(rd());
    uniform_int_distribution<int> dist('a', 'z');
    for (int i = 0; i < length; ++i)   name += char(dist(gen)); 
    return name;
}

/* void Suiii()
{
    OrderedArrayList<Student> studentList;
    string id = generateUniqueId();
    string name = generateArbitraryName(3);
    float gpa = static_cast<float>(rand() % 401) / 100; 
    Student newStudent(name,id,gpa);
    studentList.insertOrd(newStudent);
} */

int main()
{cout << endl;
int i;
    ArrayList<int> L(10);
    // The first required
    cout << endl;
    cout << "--------The first required-------- " << endl;
    L.insertAt(0,80);
    L.insertAt(0,43);
    L.insertAt(0,77);
    L.insertAt(0,23);
    L.insertAt(0,80);
    L.insertAt(0,80);
    L.insertAt(0,55);
    L.insertAt(0,12);
    L.insertAt(0,84);
    L.insertAt(0,77);
    L.insertAt(0,77); // now in this point the list doubled
    L.print();
    cout << endl << "--------The secound required-------- " << endl;
    srand(time(nullptr));
    OrderedArrayList<Student> studentList(1000000);
    Student student;
    const int numStudent = 1000000;
    for (i=0 ; i<numStudent; i++)
    {
        student.setName(generateArbitraryName(5));
        student.setId(generateUniqueId());
        student.setGpa(static_cast<float>(rand() % 401) / 100);
        studentList.insertOrd(student);
        student.print();
    }
    //student.length(i);
    string searchID = student.getId();
    auto start = high_resolution_clock::now(); 
    int binarySearchResult = studentList.binarySearch(Student("", searchID, 0)); // Search for the Student with the given ID
    auto stop = high_resolution_clock::now();
    duration<double> duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    start = high_resolution_clock::now(); 
    int linearSearchResult = studentList.seqSearch(Student("", searchID, 0)); // Search for the Student with the given ID
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    

    cout << endl << "--------The third required--------" << endl;
    // The third required
    L.removeAll(80);
    L.print();
    cout << endl << "--------The fourth required--------" << endl;
    L.findAll(77);
    L.findAll(-1);
    cout << endl << "--------The fifth required--------" << endl;
    L.print();
    cout << L.min() << endl;

cout << endl;
    return 0;
}