//Algorithm

void max_heapify (int Arr[ ], int i, int N)
    {
        int left = 2*i                   //left child
        int right = 2*i +1           //right child
        if(left<= N and Arr[left] > Arr[i] )
              largest = left;
        else
             largest = i;
        if(right <= N and Arr[right] > Arr[largest] )
            largest = right;
        if(largest != i )
        {
            swap (Arr[i] , Arr[largest]);
            max_heapify (Arr, largest,N);
        }
     }
