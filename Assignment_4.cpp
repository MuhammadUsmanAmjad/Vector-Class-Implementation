//#include<iostream>
//using namespace std;
//template<typename t>
////this is an iterator class that is used for an iterator object in vector class
//class Iterator {
//public:
//	t* ptr;//private data member
//	Iterator(t* vect)
//	{
//		ptr = vect;
//	}
//	//this function increments the Address of the vector..
//	t*& operator++()
//	{
//		ptr++;
//		return ptr;
//	}
//	//this function prints the iterator object..
//	bool operator<(const Iterator& it)
//	{
//		if (this->ptr >= it.ptr)
//			return false;
//		return true;
//	}
//	//This function is used to cout iterator object...
//	friend ostream& operator<<(ostream& o, const Iterator& it)
//	{
//		o << *(it.ptr) << "  ";
//		return o;
//	}
//};
////this is vector class which performs same functions as a built-in vector does..
//template<typename T>
//class Vector {
//	int size;
//	T* array;
//	int capacity=0;
//public:
//	//1-MEMBER FUNCTIONS
//
//	Vector(int s = 0)//default+parameterized constructor
//	{
//		if (s == 0) {
//			array = nullptr;
//			size = 0;
//			this->capacity = 0;
//		}
//		else {
//			array = new T[s];
//			size = s;
//			this->capacity *= s;
//		}
//	}
//
//	Vector& operator=(const Vector& obj)
//	{
//		if (*this != 0) {
//			delete[]this->array;
//			this->size = 0;
//			this->capacity = 0;
//		}
//		this->size = obj.size;
//		this->array = new T[this->size];
//		for (int c = 0; c < this->size; c++)
//			this->array[c] = obj.array[c];
//		this->capacity = obj.capacity;
//		return *this;
//	}
//
//	~Vector()
//	{
//		if (this != 0) {
//			delete[]this->array;
//			this->array = nullptr;
//			this->size = 0;
//		}
//	}
//
//	//2-ITERATORS FUNCTIONS:-
//	//This Function return the adress to First Element in the iterator object
//	Iterator<T> begin()
//	{
//		Iterator<T> it(&array[0]);
//		return it;
//	}
//	//This Function  returns Iterator to the element next to the last element
//	Iterator<T> end()
//	{
//		Iterator<T> it(&array[size]);
//		return it;
//	}
//	T* begin1()
//	{
//		return (&this->array[0]);
//	}
//	T* end1()
//	{
//		return(&this->array[size]);
//	}
//	//3-CAPACITY FUNCTIONS
//	//This Function Gives Size of the Vector Filled
//	int Size()
//	{
//		return size;
//	}
//	//This Function Gives The MMaximum Size constructed
//	int max_size()
//	{
//		return capacity;
//	}
//	//This Function tells whether Vector is Empty or Not
//	bool empty()
//	{
//		if (this)
//			return false;
//		else
//			return true;
//	}
//
//	//4-ACCESS ELEMENTS:-
//	//This is Subscript Operator
//	T& operator[](int a)
//	{
//		if (a >= 0 && a < this->size)
//			return this->array[a];
//		else
//			throw("Index out of bound\n");
//	}
//	//At function Returns Value of the Index Given
//	T& at(int idx)
//	{
//		return this->array[idx];
//	}
//	//this Function Return First element in the Vector
//	T front()
//	{
//		if (this != 0) {
//			return this->array[0];
//		}
//		else
//			throw("Vector is empty");
//	}
//	//this Function Return Last element in the Vector
//	T back()
//	{
//		if (this)
//		{
//			return this->array[this->size - 1];
//		}
//		else
//			throw("Vector is empty");
//	}
//	//This Function Returns A pointer To First Element in The Vector
//	T* data()
//	{
//		if (this) {
//			return &this->array[0];
//		}
//		else
//			return;
//	}
//
//	//5-MODIFIERS:-
//	//This Function Takes An Array and size and makes vector according to it
//	void assign(T*&arr, int val)
//	{
//		if (this)
//			delete[]this->array;
//		this->size = val;
//		for (int k = 0; k < this->size; k++)
//			this->array[k] = arr[k];
//		capacity *= val;
//	}
//	//This Function Inserts Element at the End of Vector
//	void push_back(T a)
//	{
//		if (size <= capacity)
//			capacity += 5;
//		if (this == 0)
//		{
//			this->array[0] = a;
//			size = 0;
//			size += 1;
//		}
//		else {
//			T* temp = new T[this->size + 1];
//			int c = 0;
//			for (; c < this->size; c++)
//				temp[c] = this->array[c];
//			temp[c] = a;
//			if (this != 0)
//			{
//				delete[]this->array;
//			}
//			this->size = this->size + 1;
//			this->array = temp;
//		}
//	}
//	//This Function Removes Element From the End of Vector
//	void pop_back()
//	{
//		T* temp = new T[this->size - 1];
//		int c = 0;
//		for (; c < this->size - 1; ++c)
//			temp[c] = this->array[c];
//		if (*this != 0)
//		{
//			delete[]this->array;
//		}
//		
//		this->size = this->size - 1;
//		this->array = temp;
//	}
//	//This Fuction Takes an An index and A Value and Inserts value before that specific index
//	void insert(int idx, T val)
//	{
//		if (size >= capacity)
//			capacity += 5;
//		T* temp = new T[this->size + 1];
//		int j = 0;
//		for (int k = 0; k < size + 1; k++)
//		{
//			if (k == idx - 1)
//				temp[k] = val;
//			else
//			{
//				temp[k] = this->array[j];
//				j++;
//			}
//		}
//		if (this != 0)
//			delete[]this->array;
//		this->size += 1;
//		this->array = temp;
//	}
//	//This function Removes Element at the particular Index given 
//	void erase(int p)
//	{
//		if (p < this->size) {
//			if (this) {
//				T* temp = new T[this->size - 1];
//				int c = 0;
//				for (int j = 0; j < this->size; j++)
//				{
//					if (j != p)
//					{
//						temp[c] = this->array[j];
//						c++;
//					}
//				}
//				delete[]this->array;
//				this->size -= 1;
//				this->array = temp;
//			}
//		}
//	}
//	//This function Removes Elements from a particular Index to Another index given 
//	void erase(int first, int last)
//	{
//		if (first >= 0 && last < this->size) {
//			if (this)
//			{
//				int a = last - first + 1;
//				T* temp = new T[this->size - a];
//				int c = 0;
//				for (int j = 0; j < this->size; j++)
//				{
//					if (j<first || j>last)
//					{
//						temp[c] = this->array[j];
//						c++;
//					}
//				}
//				delete[]this->array;
//				this->size -= a;
//				this->array = temp;
//			}
//
//		}
//	}
//	//
//	void clear()
//	{
//		if (this)
//		{
//			delete[]this->array;
//			this->size = 0;
//			this->array = nullptr;
//			this->capacity = 0;
//		}
//	}
//
//	//6-RELATIONAL OPERATORS:-
//
//	bool operator==(const Vector<T>& obj)
//	{
//		if (this->size != obj.size)
//			return false;
//		else
//		{
//			for (int l = 0; l < this->size; l++)
//			{
//				if (this->array[l] != obj.array[l])
//					return false;
//			}
//			return true;
//		}
//	}
//	//This function checks two Vectors are Equal or Not..
//	bool operator!=(const Vector<T>& obj)
//	{
//		if (this->size != obj.size)
//			return true;
//		else
//		{
//			for (int l = 0; l < this->size; l++)
//			{
//				if (this->array[l] != obj.array[l])
//					return true;
//			}
//			return false;
//		}
//	}
//
//	//7-SORTING FUNCTIONS:-
//
////This Function Sorts Vector In Ascending Order..
//	void sort()
//	{
//		for (int j = 0; j < size; j++)
//			for (int k = 0; k < size - 1 - j; k++)
//				if (this->array[k] > this->array[k + 1])
//					swap(this->array[k], this->array[k + 1]);
//	}
//};
//
////Specialized Class For Boolean VECTOR...
//template<>
//class Vector<bool> {
//	int size;
//	bool* array;
//	int capacity=0;
//public:
//	//1-MEMBER FUNCTIONS
//
//
//	Vector(int s = 0)//default+parameterized constructor
//	{
//		//cout << "\nIn Bool class\n";
//		if (s == 0) {
//			array = nullptr;
//			size = 0;
//			this->capacity = 0;
//		}
//		else {
//			array = new bool[s];
//			size = s;
//			this->capacity *= s;
//		}
//	}
//
//	Vector& operator=(const Vector& obj)
//	{
//		//cout << "\nIn Bool class\n";
//		if (*this != 0) {
//			delete[]this->array;
//			this->size = 0;
//		}
//		this->size = obj.size;
//		this->array = new bool[this->size];
//		for (int c = 0; c < this->size; c++)
//			this->array[c] = obj.array[c];
//		return *this;
//	}
//
//	~Vector()
//	{
//		//cout << "\nIn Bool class\n";
//		if (this != 0) {
//			delete[]this->array;
//			this->array = nullptr;
//			this->size = 0;
//		}
//	}
//
//	//2-ITERATORS FUNCTIONS:-
//	//This Function return the adress to First Element in the iterator object
//	Iterator<bool> begin()
//	{
//		//cout << "\nIn Bool class\n";
//		Iterator<bool> it(&array[0]);
//		return it;
//	}
//	//This Function  returns Iterator to the element next to the last element
//	Iterator<bool> end()
//	{
//		//cout << "\nIn Bool class\n";
//		Iterator<bool> it(&array[size]);
//		return it;
//	}
//	bool* begin1()
//	{
//		return (&this->array[0]);
//	}
//	bool* end1()
//	{
//		return(&this->array[size]);
//	}
//	//3-CAPACITY FUNCTIONS
//	//This Function Gives Size of the Vector Filled
//	int Size()
//	{
//		//cout << "\nIn Bool class\n";
//		return size;
//	}
//	//This Function Gives The MMaximum Size constructed
//	int max_size()
//	{
//		//cout << "\nIn Bool class\n";
//		return capacity;
//	}
//	//This Function tells whether Vector is Empty or Not
//	bool empty()
//	{
//		//cout << "\nIn Bool class\n";
//		if (this)
//			return false;
//		else
//			return true;
//	}
//
//	//4-ACCESS ELEMENTS:-
//	//This is Subscript Operator
//	bool& operator[](int a)
//	{
//		//cout << "\nIn Bool class\n";
//		if (a >= 0 && a < this->size)
//			return this->array[a];
//		else
//			throw("Index out of bound.");
//	}
//	//At function Returns Value of the Index Given
//	bool& at(int idx)
//	{
//		//cout << "\nIn Bool class\n";
//		if (idx >= 0 && idx < this->size)
//		{
//			return this->array[idx];
//		}
//		else
//			throw("index out of bound");
//	}
//	//this Function Return First element in the Vector
//	bool front()
//	{
//		//cout << "\nIn Bool class\n";
//		if (this != 0) {
//			return this->array[0];
//		}
//		else
//			throw("Boolean Vector is Empty");
//	}
//	//this Function Return Last element in the Vector
//	bool back()
//	{
//		//cout << "\nIn Bool class\n";
//		if (this)
//		{
//			return this->array[this->size - 1];
//		}
//		else
//			throw("Boolean Vector is Empty");
//			
//	}
//	//This Function Returns A pointer To First Element in The Vector
//	bool* data()
//	{
//		//cout << "\nIn Bool class\n";
//		if (this) {
//			return &this->array[0];
//		}
//		else
//			throw("Vector is NULL.Can't Return pointer at that index");
//	}
//
//	//5-MODIFIERS:-
//	//This Function Takes An Array and size and makes vector according to it
//	void assign(bool* arr, int val)
//	{
//		//cout << "\nIn Bool class\n";
//		
//		this->size = val;
//		for (int k = 0; k < this->size; k++)
//			this->array[k] = arr[k];
//		if (size >= capacity)
//			capacity += 5;
//	}
//	//This Function Inserts Element at the End of Vector
//	void push_back(bool a)
//	{
//		//cout << "\nIn Bool class\n";
//		if (this == 0)
//		{
//			this->array[0] = a;
//			size = 0;
//			size += 1;
//		}
//		else {
//			bool* temp = new bool[this->size + 1];
//			int c = 0;
//			for (; c < this->size; c++)
//				temp[c] = this->array[c];
//			temp[c] = a;
//			if (this != 0)
//			{
//				delete[]this->array;
//			}
//			this->size = this->size + 1;
//			this->array = temp;
//		}
//		if (size >= capacity)
//			capacity += 5;
//	}
//	//This Function Removes Element From the End of Vector
//	void pop_back()
//	{
//		//cout << "\nIn Bool class\n";
//		if (this) {
//			bool* temp = new bool[this->size - 1];
//			int c = 0;
//			for (; c < this->size - 1; ++c)
//				temp[c] = this->array[c];
//			if (this != 0)
//			{
//				delete[]this->array;
//			}
//			this->size = this->size - 1;
//			this->array = temp;
//		}
//	}
//	//This Fuction Takes an An index and A Value and Inserts value before that specific index
//	void insert(int idx, bool val)
//	{
//		//cout << "\nIn Bool class\n";
//		if (idx >= 0 && idx <= size) {
//			bool* temp = new bool[this->size + 1];
//			int j = 0;
//			for (int k = 0; k < size + 1; k++)
//			{
//				if (k == idx - 1)
//					temp[k] = val;
//				else
//				{
//					temp[k] = this->array[j];
//					j++;
//				}
//			}
//			if (this != 0)
//				delete[]this->array;
//			this->size += 1;
//			this->array = temp;
//			if (size >= capacity)
//				capacity += 5;
//		}
//	}
//	//This function Removes Element at the particular Index given 
//	void erase(int p)
//	{
//		//cout << "\n in bool class\n";
//		if (p < this->size) {
//			if (this) {
//				bool* temp = new bool[this->size - 1];
//				int c = 0;
//				for (int j = 0; j < this->size; j++)
//				{
//					if (j != p)
//					{
//						temp[c] = this->array[j];
//						c++;
//					}
//				}
//				delete[]this->array;
//				this->size -= 1;
//				this->array = temp;
//			}
//		}
//	}
//	//This function Removes Elements from a particular Index to Another index given 
//	void erase(int first, int last)
//	{
//		//cout << "\nIn Bool class\n";
//		if (first >= 0 && last < this->size) {
//			if (this)
//			{
//				int a = last - first + 1;
//				bool* temp = new bool[this->size - a];
//				int c = 0;
//				for (int j = 0; j < this->size; j++)
//				{
//					if (j<first || j>last)
//					{
//						temp[c] = this->array[j];
//						c++;
//					}
//				}
//				delete[]this->array;
//				this->size -= a;
//				this->array = temp;
//			}
//
//		}
//	}
//	//This Function Clears all the values at indices and makes size=0...
//	void clear()
//	{
//		cout << "\nIn Bool class\n";
//		if (this)
//		{
//			delete[]this->array;
//			this->size = 0;
//			this->array = nullptr;
//			this->capacity = 0;
//		}
//	}
//
//	//6-RELATIONAL OPERATORS:-
//	
//	//This Functions Checks Two VECTORS Are Equal or Not
//	bool operator==(const Vector<bool>& obj)
//	{
//		cout << "\nIn Bool class\n";
//		if (this->size != obj.size)
//			return false;
//		else
//		{
//			for (int l = 0; l < this->size; l++)
//			{
//				if (this->array[l] != obj.array[l])
//					return false;
//			}
//			return true;
//		}
//	}
//	//This function checks two Vectors are Equal or Not..
//	bool operator!=(const Vector<bool>& obj)
//	{
//		cout << "\nIn Bool class\n";
//		if (this->size != obj.size)
//			return true;
//		else
//		{
//			for (int l = 0; l < this->size; l++)
//			{
//				if (this->array[l] != obj.array[l])
//					return true;
//			}
//			return false;
//		}
//	}
//
//	//7-SORTING FUNCTIONS:-
//
////This Function Sorts Vector In Ascending Order..
//	void sort()
//	{
//		for (int j = 0; j < size; j++)
//			for (int k = 0; k < size - 1 - j; k++)
//				if (this->array[k] > this->array[k + 1])
//					swap(this->array[k], this->array[k + 1]);
//	}
//};
//int main()
//{
//	try {
//		Vector<int>iobj;
//		
//		for (int k = 0; k < 10; k++)
//			iobj.push_back(k);
//		cout << "Iterators output:" << endl;
//		Iterator<int> it = iobj.begin();
//		for (; it < iobj.end(); ++it)
//			cout << it << " ";
//		cout << endl;
//		iobj.pop_back();
//		for (int i = 0; i < iobj.Size(); i++)
//			cout << iobj.at(i)<<"  ";
//		Vector<int>iobj1(5);
//		for (int k = 0; k < 5; k++)
//			iobj1[k]=k;
//		cout << endl;
//		for (int k = 0; k < iobj1.Size();k++)
//			cout<<iobj1.at(k)<< "  ";
//		cout << endl;
//		if (iobj1.empty())
//			cout << "iobj1 is empty\n";
//		else
//			cout << "iobj1 is not empty\n";
//		if (iobj == iobj1)
//			cout << "both vectors are equal\n";
//		else
//			cout << "both vectors are not equal\n";
//		cout << endl;
//		Vector<bool>bobj;
//		for (int k = 0; k < 10; k++)
//			bobj.push_back(true);
//		cout << "Iterators output:" << endl;
//		Iterator<bool> bit = bobj.begin();
//		for (; bit<bobj.end(); ++bit)
//			cout << bit << " ";
//	}
//	
//	
//}
