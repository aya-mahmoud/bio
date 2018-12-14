#include "CodonsTable.h"
#include <fstream>
CodonsTable::CodonsTable()
{
    //ctor
}

CodonsTable::~CodonsTable()
{
    //dtor
}
void CodonsTable::LoadCodonsFromFile(string codonsFileName){
    ifstream codonsfile;
codonsfile.open(codonsFileName);
if(codonsfile.fail()){
    cout<<"error";
}
for(int i=0;!codonsfile.eof();i++){
      //cout<<i<<" ";
      string line;
      getline(codonsfile,line);

      for(int j=0;j<3;j++){

    codons[i].value[j]=line[j];
   //cout<<codons[i].value[j];
      }
    codons[i].AminoAcid=line[4];
    //cout<<" "<<codons[i].AminoAcid<<endl;
}
codonsfile.close();
}


void CodonsTable::setCodon(char * value, char AminoAcid, int index){
codons[index].value[0]=value[0];
codons[index].value[1]=value[1];
codons[index].value[2]=value[2];


}

char  CodonsTable:: getAminoAcid(char * value)


     { int counter;
               char x;
            for (int i=0;i<64;i++){
                      counter=0;
                    for(int j=0;j<3;j++) {

                       if( value[j]==codons[i].value[j]){
                           counter+=1;
                               //cout<<"cOUNTER: "<<counter;
                           } }
                       if(counter==3){
                            for(int j=0;j<3;j++)

                           codons[i].AminoAcid;
                            // cout<<"amino acid: "<<x;
                            return codons[i].AminoAcid;}
                      }
        }


