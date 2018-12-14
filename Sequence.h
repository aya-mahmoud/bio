#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <bits/stdc++.h>
using namespace std ;
class Sequence
{
    protected:
    char * seq;
    int length;
public:
    // constructors and destructor
    Sequence();
    Sequence(int length);
    Sequence(Sequence& rhs);
    virtual ~Sequence();
    // pure virtual function that should be overridden because every
    // type of sequence has its own details to be printed
    virtual void Print()= 0;
     // friend function that will find the LCS (longest common
     // subsequence) between 2 sequences of any type, according to
    // polymorphism
    //virtual void LoadSequenceFromFile(char* filename) = 0 ;
    //virtual void SaveSequenceToFile(char* filename) = 0 ;
    friend char* Align(Sequence* s1,Sequence* s2);
    friend ostream& operator<< (ostream& out , Sequence& s1);
    friend istream& operator>> (istream& in  , Sequence& s1);
    bool operator == (Sequence *s) ;
    bool operator != (Sequence &s);
    char* operator + (Sequence &s);
};
#endif // SEQUENCE_H
