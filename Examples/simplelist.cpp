
#include <iostream>  
using namespace std;  

int main()
{
	SimpleList list1;
	SimpleList list2;
	addItem()

}

class SimpleList  
{  
public:
   SimpleList();  
   int numberItems() const; 
   bool isFull() const;   
   bool addItem(int item);  
   void printList() const;  
   
   SimpleList operator+(const SimpleList& rhs);   
   const SimpleList& operator=(const SimpleList& rhs); 
   int& operator[](int index);        // for writing   
   int  operator[](int index) const;  // for reading 
   bool operator==(const SimpleList& rhs);    
   
   friend ostream& operator<<(ostream& out, const SimpleList& rhs);  
   
private:
   enum{maxSize_ = 100};  ///< maximum list size
   int list_[maxSize_];   ///< list of ints
   int size_;             ///< current size of list
};    


SimpleList::SimpleList()
{  size_ = 0;  } 


int SimpleList::numberItems() const  
{  return size_;  } 


bool SimpleList::addItem(int item)  
{  
   if(size_ >= maxSize_)  
      return false;  
   
   list_[size_] = item;  
   size_++;  
   
   return true;
} 


SimpleList SimpleList::operator+(const SimpleList& rhs) 
{  
   SimpleList temp;  ///< local to store the answer  
   int i = 0;  
   for(i = 0; i < size_; i++)  
      temp.list_[i] = list_[i];  
   temp.size_ = size_;  
   for(i = 0; (i < rhs.size_) && (i < (maxSize_ - size_)); i++)  
      temp.list_[size_ + i] = rhs.list_[i];  
   temp.size_ += i;  
   
   return temp;
}       


const SimpleList& SimpleList::operator=(const SimpleList& rhs) 
{  
   // check if the lhs object is the same as the rhs  
   if(this != &rhs)  
   {  
      size_ = rhs.size_;                 // copy the rhs size
      for(int i = 0; i < rhs.size_; i++) // copy the rhs values  
         list_[i] = rhs.list_[i];  
   }  
   return *this;  // must return the lefthand side
}       


int& SimpleList::operator[](int index)  
{
   if(index < 0 || index > (size_ - 1))  
   {  
      cerr << "SimpleList:operator[] write " << index 
           << " out of bounds \n";  
      index = 0;  // this might be dangerous...
   }  
   return list_[index];  
}


int SimpleList::operator[](int index) const  
{
   if(index < 0 || index > (size_ - 1))  
   {  
      cerr << "SimpleList:operator[] read " << index 
           << " out of bounds \n";  
      index = 0;  // this might be dangerous...
   }  
   return list_[index];  
}


ostream& operator<<(ostream& out, const SimpleList& rhs) 
{  
   for(int i = 0; i < rhs.size_; i++)  
      out << rhs.list_[i] << ' ';  
   return out;  
}     

bool SimpleList::operator==(const SimpleList& rhs) 
{
	bool same = false;

	if(size_ == rhs.size_)
	{
		same = true;
		for(int i = 0; i < size_ && same; i++)
		{
			if(list_[i] != rhs.list_[i])
				same = false;
		}
	}
	
	return same;
}


