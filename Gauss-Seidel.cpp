#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

struct valor{

	double x, y, z;
};

int main(){
    setlocale(LC_ALL, "portuguese");

    cout << "\n\tGabriel Mossini\t";
    cout << "\t\tCalculo Numerico";
    cout << "\t\tFernando Brito";
    cout << "\n\n\n\tPrograma para calculo de Gauss-Seidel\n\n";

	int a[3];
	int b[3];
	int c[3];
	int resultado[3];

	double x, y, z;

	valor valoresemK[1000];

	double erro;

	cout << "\n\tDigite o erro que deseja: " << endl;
	cin >> erro;

	double erX = 1;
	double erY = 1;
	double erZ = 1;

	int k = 0;

	for (int i = 0; i < 3; i++){
		cout << "\n\tDigite a posicao " << "X" << i+1  << endl;
		cin >> a[i];

		cout << "\n\tDigite a posicao " << "Y" << i+1  << endl;
		cin >> b[i];

		cout << "\n\tDigite a posicao " << "Z" << i+1  << endl;
		cin >> c[i];

		cout << "\n\tDigite o resultado da equacao " << i+1 << endl;
		cin >> resultado[i];
	}



	cout << "\n\n\tDigite o chute inicial em X: " << endl;
	cin >> valoresemK[0].x;

	cout << "\n\tDigite o chute inicial em Y: " << endl;
	cin >> valoresemK[0].y;

	cout << "\n\tDigite o chute inicial em Z: " << endl;
	cin >> valoresemK[0].z;

	while(erX > erro && erY > erro && erZ > erro){
		x = (resultado[0] - b[0]*valoresemK[k].y - c[0]*valoresemK[k].z) / a[0];
		y = (resultado[1] - a[1]*x - c[1]*valoresemK[k].z) / b[1];
		z = (resultado[2] - a[2]*x - b[2]*y)/c[2];

		k++;
		valoresemK[k] = {x, y, z};

		erX = abs((valoresemK[k].x - valoresemK[k-1].x)/ valoresemK[k].x);
		erY = abs((valoresemK[k].y - valoresemK[k-1].y)/ valoresemK[k].y);
		erZ = abs((valoresemK[k].z - valoresemK[k-1].z)/ valoresemK[k].z);
	}


	cout << "\n\tQuantidade de repeticoes: " << k << endl;
	cout << fixed << setprecision(3);
	cout << "\t\nX: " << valoresemK[k].x << " Y: " << valoresemK[k].y << " Z: " << valoresemK[k].z << endl;

}
