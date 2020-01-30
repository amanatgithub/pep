class Intervals
{
 public :
   int st;
   int cl;
   Intervals(int st,int cl)
   {
    this->st=st;
    this->cl=cl;
    }
  bool operator<(const Intervals &o)const
   {
     return this->st<o.st; 
    }

};


vector<Intervals> vect;
 sort(vect.begin(),vect.end());
