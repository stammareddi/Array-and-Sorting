









#include<stdlib.h>
#include<stdio.h>

void merge(int arr[], int left, int middle, int right)
{


    int p1 = middle - left + 1;
    int p2 =  right - middle;

int Left[p1];
int Right[p2];

int i= 0 ;
 int j=0;
for ( ; i < p1; i++){
  Left[i] = arr[left + i];}
    for ( ; j < p2; j++){
 Right[j] = arr[middle + 1+ j];}


i = 0;
j = 0;

int  k = left;
   while (i < p1 && j < p2)
   {
       if (Left[i] <= Right[j])
       {
           arr[k] = Left[i];
           i++;
       }
       else
       {
           arr[k] = Right[j];
           j++;
       }
       k++;
   }

 while (i < p1)
   {
       arr[k] = Left[i];
      k++;
      i++;

   }

 while (j < p2)
   {
       arr[k] = Right[j];
      k++;
      j++;
   }
}


void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
int mid = left+(right-left)/2;
  mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }

}

int oddTotal=0;
int evenTotal=0;
int counter = 0;
void printArray(int A[], int S)
{
    int i=0;
    for ( ; i < S; i++)
        printf("%d ", A[i]);
    printf("\n");
}




void split(int A[], int size)
{
int i=0;
int j=0;
int k=0;
int  *Odd = (int*)malloc(20 *sizeof(int));
int *Even = (int*)malloc(20* sizeof(int));


for( ;i<=size;i++)
    {
        if (A[i]%2 != 0)
        {
           Odd[j] = A[i];
           j++;
        oddTotal++;
        counter++;
        }
        else
        {
          Even[k] = A[i];
           k++;
        evenTotal++;

        }

    };















printf("Odd array: ");
printArray(Odd,oddTotal);
printf("Even array: ");
printArray(Even,evenTotal);

 int *revOddArray = (int*)malloc(oddTotal *sizeof(int));


int index = 0;
counter--;

for( ;counter >=0; counter--){
        revOddArray[index] = Odd[counter];
index++;

}
printf("Reverse of Odd array: ");
printArray(revOddArray,oddTotal);


// combining array
 int total = oddTotal + evenTotal;

int fArray[total];



int fcounter = 0;
int countArray = 0;
printf("Final array: ");

for( ; countArray < evenTotal;countArray++)
{
        fArray[fcounter]= Even[countArray];
printf("%d ",fArray[fcounter]);
};
countArray = 0;
 for( ; countArray <  oddTotal; countArray++)
{
        fArray[fcounter] = revOddArray[countArray];
        printf("%d ", fArray[fcounter]);
};
printf("\n");

};

int main(int argc,char **argv)
{
 FILE* f = fopen(argv[1], "r");
  if (f == NULL) {
       printf("Could not open test.txt\n");
       return 1;
  };
   int x;
  fscanf(f,"%d",&x);
int arr[x];
int keepTrack=0;
 while (fscanf(f, "%d", &arr[keepTrack]) == 1)
 {
           keepTrack++;
 }
  fclose(f);

    int arr_size =x;
    printf("Given array is: ");
   printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);
  printf("Mergesort array: ");
 printArray(arr,arr_size);
split(arr,arr_size-1);

    return 0;
}
