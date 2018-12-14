#ifndef RNA_H_INCLUDED
#define RNA_H_INCLUDED
#include "Sequence.h"
#include "DNA.h"
#include "Protein.h"
#include "CodonsTable.h"

class DNA;
class Protein;
class CodonsTable;
enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class RNA : public Sequence
{
private:
    RNA_Type type;
public:
    // constructors and destructor
    RNA();
   // RNA(char * seq, RNA_Type atype);
    RNA(RNA& rhs);
    ~RNA();
    RNA(char*seq , RNA_Type atype,int l) ;
    friend istream& operator>> (istream& in ,RNA &rna) ;
    friend ostream& operator>> (ostream& out ,RNA & s1);
    bool operator ==(RNA &s1 );
    bool operator !=(RNA &s1 );
    char*operator + (RNA &s1) ;
    // function to be overridden to print all the RNA information
    void Print();
    // function to convert the RNA sequence into protein sequence
    // using the codonsTable object
    Protein& ConvertToProtein(CodonsTable & table) ;
    // function to convert the RNA sequence back to DNA
    DNA ConvertToDNA();
};


#endif // RNA_H
