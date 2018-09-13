
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip> 


using std::setw;
using namespace std;

void lerLinCol(int& a, int& b);
void lerPos(int& pos);



int main(int argc, const char * argv[]) {

    ofstream outFile;

	// Cria arquivo 
    outFile.open("output.txt");

    if(! outFile){
        cout << "erro output.txt" << endl; 
        abort(); 
    } 

	// Checa quantidade de argumentos passados por nlinhas de comando
    if(argc != 4){
        std::cout << "Erro, tente novamente. Exemplo de entrada: ./program 10 10 10 " << std::endl;
        return -1;
    }   
	// Número de puzzles
	int numPuz = atoi(argv[1]);
	int nlinhas = atoi(argv[2]);
	int ncol = atoi(argv[3]);
	 int a = nlinhas;
	 int b = ncol;
	
    vector<vector<int>> mat(nlinhas, std::vector<int>(ncol));            	
    

int pos =10;
 //ler nlinhas e ncol
    lerLinCol(nlinhas, ncol);
	
    // aloca na horizontal ou vertical
    //alocEsqHorVer(posicional);
	 lerPos(pos);
    if(pos == 1)
    {
        while((4 + ncol > b)||(mat[nlinhas][ncol]!=0)||
                (mat[nlinhas][ncol+1]!=0)||
                (mat[nlinhas][ncol+2]!=0)||
                (mat[nlinhas][ncol+3]!=0))
        {
          
            lerLinCol(nlinhas,ncol);
        }
        for(auto i=0; i<a; i++)
        {
            for(auto j=0; j<b; j++)
            {
                if(mat[i][j] == 0)
                {
                    mat[nlinhas][ncol] = 1;
                    mat[nlinhas][ncol+1] = 1;
                    mat[nlinhas][ncol+2] = 1;
                    mat[nlinhas][ncol+3] = 1;
                }
                //extremidade esquerda;
                if (ncol> 0)
                {
                    mat[nlinhas][ncol-1] = 5;
                    mat[nlinhas+1][ncol-1]= 5; /*erro*/ 
                    mat[nlinhas-1][ncol-1]= 5; /*erro*/ 
                }
                //extremidade direita;
                if (4 + ncol < b)
                {
                    mat[nlinhas][ncol+4] = 5;
       				mat[nlinhas-1][ncol+4]= 5; /*erro*/  
                    mat[nlinhas+1][ncol+4]= 5;/*erro*/ 
                }
                //nlinhas superior;
                if (nlinhas>0)
                {
                    mat[nlinhas-1][ncol]= 5;
                    mat[nlinhas-1][ncol+1]= 5;
                    mat[nlinhas-1][ncol+2]= 5;
                    mat[nlinhas-1][ncol+3]= 5;
                }
                //nlinhas inferior;
                mat[nlinhas+1][ncol]= 5;
                mat[nlinhas+1][ncol+1]= 5;
                mat[nlinhas+1][ncol+2]= 5;
                mat[nlinhas+1][ncol+3]= 5;
                

            }
        }
    }
    else if(pos == 0)
    {
        
        while((4 + nlinhas > a)||(mat[nlinhas][ncol]!=0)||
                (mat[nlinhas+1][ncol]!=0)||
                (mat[nlinhas+2][ncol]!=0))
        {
            //ler nlinhas, ncol
            lerLinCol(nlinhas, ncol);
        }
        for(auto i=0; i<a; i++)
        {
            for(auto j=0; j<b; j++)
            {
                if(mat[i][j] ==0)
                {
                    mat[nlinhas][ncol] = 1;
                    mat[nlinhas+1][ncol] = 1;
                    mat[nlinhas+2][ncol] = 1;
                    mat[nlinhas+3][ncol] = 1;
                    //nlinhas superior;
                    if (nlinhas>0)
                    {
                        mat[nlinhas-1][ncol] = 5;
                    }
                    //nlinhas inferior;
                   // mat[nlinhas+4][ncol] = 5;
                    //extremidade esquerda;
                    if (ncol> 0)
                    {
                        mat[nlinhas-1][ncol-1]= 5;
                        mat[nlinhas][ncol-1]= 5;
                        mat[nlinhas+1][ncol-1]= 5;
                        mat[nlinhas+2][ncol-1]= 5;
                        mat[nlinhas+3][ncol-1]= 5;
                        mat[nlinhas+4][ncol-1]= 5; /*erro*/ 
                    }
                    //extremidade direita;
                    if(1+ncol < a)
                    {
                        mat[nlinhas-1][ncol+1]= 5;  /*erro*/  
                        mat[nlinhas][ncol+1]= 5;
                        mat[nlinhas+1][ncol+1]= 5;
                        mat[nlinhas+2][ncol+1]= 5;
                        mat[nlinhas+3][ncol+1]= 5;
                        mat[nlinhas+4][ncol+1]= 5; /*erro*/
                    }
                    // printf("mat[%d][%d] == %d\n",i,j,mat[i][j]);
                }
            }
        }
    }
   
























    
	// Imprime
	for(auto i{0}; i < a; i++){
		for(auto j{0}; j < b; j++){
			std::cout << mat[i][j] << " ";
		}
		cout <<"\n";
	}



	





	
	//Armazena em arquivo
	outFile << setw(10) << "# Puzzles" << setw(20) << "Quantidade" << std::endl; 

		for(auto i{0}; i < a; i++){
			for(auto j{0}; j < b; j++){
				outFile  << setw(1) << mat[i][j] << " " ;
		}
		outFile <<"\n";
	}

	

		
	// Fecha o arquivo
	outFile.close();
	
	
    return 0;
}

void lerLinCol(int& a, int& b){
	srand(time(NULL));
    a = rand()%a+1;   
    b = rand()%b+1;
}

void lerPos(int& pos){
	srand(time(NULL));
	pos = rand()%2;

}
