
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip> 


using std::setw;
using namespace std;


int main(int argc, const char * argv[]) {

    ofstream outFile;

	// Cria arquivo 
    outFile.open("output.txt");

    if(! outFile){
        cout << "erro output.txt" << endl; 
        abort(); 
    } 

	// Checa quantidade de argumentos passados por linha de comando
    if(argc != 4){
        std::cout << "Erro, tente novamente. Exemplo de entrada: ./search 50 " << std::endl;
        return -1;
    }   
	// Número de puzzles
	int numPuz = atoi(argv[1]);
	int nlinhas = atoi(argv[2]);
	int ncol = atoi(argv[3]);

	
    int **mat = new int*[nlinhas];
 
    for(int i = 0;i < nlinhas; ++i)
        mat[i] = new int[ncol];
 
    //iniciando ela com zero
    for(int i = 0;i < nlinhas; ++i){
		for(int j = 0;j < ncol; ++j){
			 mat[i][j] = 0;
		}
           
	}
        

    
	// Imprime
	for(auto i{0}; i < nlinhas; i++){
		for(auto j{0}; j < ncol; j++){
			std::cout << mat[i][j] << " ";
		}
		cout <<"\n";
	}



	
	
	//Armazena em arquivo
	outFile << setw(10) << "# Puzzles" << setw(20) << "Quantidade" << std::endl; 

		for(auto i{0}; i < nlinhas; i++){
			for(auto j{0}; j < ncol; j++){
				outFile  << setw(1) << mat[i][j] << " " ;
		}
		cout <<"\n";
	}

	

		
	// Fecha o arquivo
	outFile.close();
	

	// Libera memória utilizaa por mat
	delete []mat; 
	
    return 0;
}
