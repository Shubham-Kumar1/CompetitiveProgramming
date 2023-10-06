
int allIndexes(int input[], int size, int x, int output[]) {
  
  if(size==0) return 0;
    
    int smallAns = allIndexes(input,size-1,x,output);
    if(input[size-1]==x)
    {
        output[smallAns++] = size - 1;
    }
    return smallAns;
}
