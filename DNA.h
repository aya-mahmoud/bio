#ifndef DNA_H
#define DNA_H
#include "RNA.h"
#include "Sequence.h"
class RNA;
enum DNA_Type {promoter, motif, tail, noncoding};
class DNA : public Sequence
{
private:
    DNA_Type type;
    DNA * complementary_strand;
    int startIndex;
    int endIndex;

public:
    // constructors and destructor
    DNA();
    DNA(char *seq,DNA_Type atype ) ;
   // DNA(char*seq , DNA_Type type, int l);
    DNA(DNA& rhs);
    DNA (int startIndex, int endIndex) ;
    void setStartIndex(int startIndex);
    void setEndIndex(int endIndex);
    int getStartIndex()const;
    int getEndIndex()const;
    void setSequence(char* seq);
    char getSequence()const;
    void getType() ;
    bool operator ==(DNA &s1 );
    bool operator !=(DNA &s1 );
    char*operator + (DNA &s1) ;
    // friend void Align(char* s1,char* s2) ;
    /* void SaveSequenceToFile(char* filename) ;
     void LoadSequenceFromFile(char* filename) ; */
    ~DNA();
    // function printing DNA sequence information to user
    void Print() ;
    // function to convert the DNA sequence to RNA sequence
    // It starts by building the complementary_strand of the current
    // DNA sequence (starting from the startIndex to the endIndex), then,
    // it builds the RNA corresponding to that complementary_strand.
    RNA ConvertToRNA();
    // function to build the second strand/pair of DNA sequence
    // To build a complementary_strand (starting from the startIndex to
    // the endIndex), convert each A to T, each T to A, each C to G, and
    // each G to C. Then reverse the resulting sequence.
    void BuildComplementaryStrand();
    // function check that dna contains strange characters
    friend ostream& operator<< (ostream& out,DNA &s1);
    friend istream& operator>> (istream& in,DNA& s1);
};


#endif // DNA_H
