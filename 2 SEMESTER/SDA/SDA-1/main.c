#include <stdio.h>
#include <math.h>

int fact(int n){
  return (n > 0)? n*fact(n-1) : 1;
}

int main() {
  int i, k, a, S = 0;
  FILE *f;
  f = fopen("binary.txt", "wb");
  if(!f){
    printf("Error with opening the file\n");
  } else {
    printf("Vvedit' i < 10: ");
    scanf("%d", &i);
    for(k = 1; k <= i; k++){
      S += pow(-1, k)*pow(3, k - 1) - fact(k);
      fwrite(&S, sizeof(S), 1, f);
    }
  }
  while(fread(&a, sizeof(a), 1, f)){
    printf("%d ",a);
  }
  fclose(f);
  return 0;
}
