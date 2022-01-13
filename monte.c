#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {
 
  int i;
  int n = 0;
  int count = 0;
  int N = 1000000000;
  double x, y, z, pi, e;
  
  FILE *fp;
  
  fp = fopen("monte_kekka.txt", "w");
 
  //乱数を初期化
  srand(time(NULL));
    while(n < 10) {
      n++; 
      pi = 0;
      count = 0;
   
  //乱数を生成、出力
        for(i = 0; i < N; i++) {
        
          x = (double)rand()/RAND_MAX;
          y = (double)rand()/RAND_MAX;
          z = x*x + y*y;
          
          if(z < 1)
            count++;  
      }
 
  //円周率を計算、出力
        pi = (double)count / N * 4;
        e = fabs((pi - M_PI) / M_PI);
        printf("　　N = %d　　", N);
        printf("π = %.10f　　", pi);
        printf("円弧に入った点の数 = %d　　", count);
        printf("相対誤差 = %f\n", e);
        fprintf(fp, "%.10f\n", pi);
    }
    
  fclose(fp);  
  return 0;
  
  }
