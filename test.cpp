#include "HuffmanCompress.hpp"
#include <iostream>
using namespace std;
int main(int argc, char* argv[]){
    if(argc != 4){
        cout<<"Usage: Huffman [-c/-x][source file] [destion file]"<<endl
        <<"         -c Compress"<<"          -x Decompress"<<endl;
        return -1;
    }
    string type = argv[1];
    string in_file_path = argv[2];
    string out_file_path = argv[3];
    
    HuffmanCompress hc;
    if(type == "-c"){
        hc.FileCompress(in_file_path,out_file_path);
    }else if (type == "-x"){
        hc.FileDeCompress(in_file_path,out_file_path);
    }
    return 0;
}