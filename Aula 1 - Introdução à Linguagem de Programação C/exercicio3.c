/*
 * Exercício: Distância de pontos
 * 
 * Leia os quatro valores correspondentes aos eixos x e y de dois pontos quaisquer no plano, P1 (x1,y1) e P2 (x2,y2) e calcule a distância entre eles, 
 * mostrando 4 casas decimais após a vírgula, segundo a fórmula:
 *
 * Distancia = Raiz((x2−x1)^2+(y2−y1)^2)^2
 */

#include <stdio.h>
#include <math.h>

int main() {
    float x1 = 0, x2 = 0, y1 = 0, y2 = 0, dist = 0;
    
    scanf("%f %f", &x1, &y1);
    scanf("%f %f", &x2, &y2);

    dist = sqrt(pow(x2-x1, 2)+pow(y2-y1,2));

    printf("%.4f\n", dist);

    return 0;
}
