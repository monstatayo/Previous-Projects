/* COP 3502C Final term Assignment 1
This program is written by : Gabriel Kim-Perez */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

 struct pair {

    int x;
    int y;

};

int Ox, Oy, Or, On, Fn; 

void merge(struct pair * arr, int l, int m, int r) {


    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    struct pair *Left = (struct pair* ) malloc (n1 * sizeof(struct pair));

    struct pair *Right = (struct pair*) malloc (n2 * sizeof(struct pair));

    for (i = 0; i < n1; i++) {

        Left[i].x = arr[l + i].x;
        Left[i].y = arr[l + i].y;

    }

    for (j = 0; j < n2; j++) {

        Right[j].x = arr[m + 1 + j].x;
        Right[j].y = arr[m + 1 + j].y;

    }
     
    k = l;
    j = 0, i = 0;

    while (i < n1 && j < n2) {
      
        if (Left[i].x < Right[j].x) {
            arr[k] = Left[i];
            i++;

        }

        else if (Left[i].x == Right[j].x) {

            int temp1 = Left[i].y;
            int temp2 = Right[j].y;

            if (temp1 < temp2) {

                arr[k] = Left[i];
                i++;

            }


            else if (temp1 >= temp2) {

                arr[k] = Right[j];
                j++;

            }
          
        }

        else if (Left[i].x > Right[j].x) {

            arr[k] = Right[j];
            j++;

        }

        k++;

    }

    while (i < n1) {
        arr[k] = Left[i];
        i++;
        k++;

    }


    while (j < n2) {
        arr[k] = Right[j];
        j++;
        k++;

    }
   
}


void mergeSort(struct pair * arr, int l, int r) {

    if (l < r) {
        
        int m = (l + r) / 2;

        mergeSort(arr, l, m);

        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int binarySearch(struct pair * arr, int l, int r, int x, int y) {
    
  if (r >= l) { 

        int mid = l + (r - l) / 2; 

        if ((arr[mid].x == x) && (arr[mid].y == y)) {

          return mid; 
  
        }
        
        if (arr[mid].x > x) {

            return binarySearch(arr, l, mid - 1, x, y);

        }


        else if (arr[mid].x < x) {

            return binarySearch(arr, mid + 1, r, x, y);

        }

        else if ((arr[mid].x == x) && (arr[mid].y < y)) {

            return binarySearch(arr, mid + 1, r, x, y); 

        }

        else if((arr[mid].x == x) && (arr[mid].y > y)) {

            return binarySearch(arr, l, mid - 1, x, y);

        }  
    } 


    return -1;  

    
}

struct pair * ReadData() {

    FILE* in;

    in = fopen("in.txt", "r");

    struct pair * ptr = (struct pair*) malloc (256);

    fscanf(in, "%d %d %d %d", &Ox, &Oy, &Or, &On);

    for (int i = 0; i < On; i++) {

        fscanf(in, "%d %d", &ptr[i].x, &ptr[i].y);

    }

  
  fclose(in);

  return ptr;
}

struct pair* FilterData(struct pair* coor) {

    FILE* out;

    struct pair* pairs = malloc(On * sizeof(struct pair));

    out = fopen("out.txt", "w");

    int x, y, sx ,sy, d, r;

    r = pow(Or,2);

    int j = 0;

    for (int k = 0; k < On; k++) {

        x = coor[k].x;

        y = coor[k].y;

       
        sx = pow(x, 2);

        sy = pow(y, 2);

        d = sx + sy;


         if (r >= d) {

            pairs[j].x = coor[k].x;
            pairs[j].y = coor[k].y;
            j++;

        }
    }

    Fn = j;

    mergeSort(pairs, 0, Fn-1);

    for (int z = 0; z < Fn; z++){

      fprintf(out, "%d %d\n", pairs[z].x, pairs[z].y);

    }

    printf("\nfiltered and sorted data written to out.txt");

    fclose(out);

    return pairs;


}

void SearchPhase(struct pair* points) {

    int x, y, n;

    n = Fn;
 

    while (1) {


        printf("\nSearch input (x y):");

        scanf("%d %d", &x, &y);

     if (x != -999 && y != -999){

        printf("\nOutput: ");

        int result = binarySearch(points, 0, n-1, x, y );

        if (result == -1){

            printf("Not found");

        }

        else printf("Found at record %d", result+1);
        
        }

     else {
       
       printf("\nOutput: exit"); 

       break; 

       }

    }


}


int main() {


    struct pair * initial = (struct pair *) malloc (256);

    initial = ReadData();

    struct pair * filtered = (struct pair *) malloc (256);
 
    filtered = FilterData(initial);

    SearchPhase(filtered);
       

      free(initial);
      free(filtered);
   
      
}