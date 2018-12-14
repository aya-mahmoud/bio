#include "Sequence.h"
Sequence::Sequence()
{
    this->seq = new char;
    *seq = 0;
}
Sequence::Sequence (int length)
{
    this->length = length;
    seq = new char[length] ;
}
Sequence::Sequence(Sequence& rhs)
{
    this->length = rhs.length;
    this->seq = rhs.seq;
   /* for (int i = 0 ; i < strlen(seq) ; i++)
    {
        seq[i] = rhs.seq[i] ;
    } */
}

ostream& operator<< (ostream& out, Sequence& sequence1)
{
    out << sequence1.seq << " \ " << sequence1.length << endl;
    return out;
}
istream& operator>> (istream& in, Sequence& sequence1)
{
    cout << "ENTER SEQUENCE : " << endl ;
    in >> sequence1.seq;
    cout << "ENTER LENGTH : " << endl;
    in >> sequence1.length;
    return in ;
}
Sequence::~Sequence()
{
    delete [] seq;
   // delete seq;
//    seq  = null
}
bool Sequence::operator==(Sequence * s1)
{

    if (this->seq == s1->seq)
    {
       // cout << "TWO SEQUENCES ARE EQUAL:" << endl ;
        return true ;
    }
    else
    {
      //  cout << "TWO SEQUENCES ARE NOT EQUAL" << endl ;
        return false ;
    }
}
bool Sequence::operator!=(Sequence& s1)
{
   // s1 = new char ;
    if (this->seq != s1.seq)
    {
       // cout << "TWO SEQUENCES ARE NOT EQUAL:" << endl ;
        return true ;
    }
    else
    {
       // cout << "TWO SEQUENCES ARE EQUAL" << endl ;
        return false ;
    }
}
// addition two sequences .
char* Sequence::operator+(Sequence &s1)
{
    char* s3 = new char[strlen(seq)+strlen(s1.seq) + 1] ;
    strcpy(s3 , seq) ;
    strcat(s3 ,s1.seq) ;
    return s3 ;
}

char* Align(Sequence* s1,Sequence* s2)
{
    int x = strlen(s1->seq) ;
    int y = strlen(s2->seq);
    int p[x+1][y+1];
   for (int i=0; i <= x; i++)
   {
     for (int j=0; j <= y; j++)
     {
       if (i == 0 || j == 0)
         p[i][j] = 0;
       else if (s1->seq[i-1] == s2->seq[j-1])
         p[i][j] = p[i-1][j-1] + 1;
       else
         p[i][j] = max(p[i-1][j], p[i][j-1]);
     }
   }
   int ind = p[x][y] ;
   char lcs[ind];
   lcs[ind] = NULL ;
   int i = x, j = y;
   while (i > 0 && j > 0)
   {
      if (s1->seq[i-1] == s2->seq[j-1])
      {
          lcs[ind-1] = s1->seq[i-1];
          i--; j--;
          ind--;
      }
      else if (p[i-1][j] > p[i][j-1])
         i--;
      else
         j--;
   }

   // Print the lcs
   cout << "THE LONGEST COMMON SEQUENCES OF : " << s1->seq << " AND " << s2->seq << " = " << lcs << endl;
}
