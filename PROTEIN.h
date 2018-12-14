#ifndef PROTEIN_H_INCLUDED
#define PROTEIN_H_INCLUDED
#include <bits/stdc++.h>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
class DNA ;
class RNA;
enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};

class Protein : public Sequence
{
  	private:
        Protein_Type type;
        char* parr;
      public:
 	 	// constructors and destructor
 	 	Protein();
 	 	Protein(char * p ,Protein_Type atype , int l );
 	 	~Protein() ;
 	 	void Print();

 	 	// return an array of DNA sequences that can possibly
        // generate that protein sequence
        DNA* GetDNAStrandsEncodingMe(const DNA & bigDNA);
        friend istream& operator>> (istream& in ,Protein & p1) ;
        friend ostream& operator<< (ostream& out ,Protein& p1) ;
        bool operator ==(Protein &s1 );
        bool operator !=(Protein &s1 );
        char*operator + (Protein &s1) ;
};


#endif // PROTEIN_H_INCLUDED
