
/*
 * This is the iterative method of the ternary search which returns the index of the element.
 */
int it_ternary_search(int left, int right, int A[],int target)
{
  while (1)
    {
      if(left<right)
	{
	  if(right-left < absolutePrecision)
	    {
	      for(int i=left;i<=right;i++)
		if(A[i] == target) return i;
	      
	      return -1;
	    }
	  
	  int oneThird = (left+right)/3+1;
	  int twoThird = (left+right)*2/3+1;
	  
	  if(A[oneThird] == target) return oneThird;
	  else if(A[twoThird] == target) return twoThird;
	  
	  else if(target > A[twoThird]) left = twoThird+1;
	  else if(target < A[oneThird]) right = oneThird-1;
	  
	  else left = oneThird+1, right = twoThird-1;
	}
      else return -1;
    }
}

/* 
 * This is the recursive method of the ternary search which returns the index of the element.
 */
int rec_ternary_search(int left, int right, int A[],int target)
{
  if(left<right)
    {
      if(right-left < absolutePrecision)
	{
	  for(int i=left;i<=right;i++)
	    if(A[i] == target) return i;
	  
	  return -1;
	}
      
      int oneThird = (left+right)/3+1;
      int twoThird = (left+right)*2/3+1;

      if(A[oneThird] == target) return oneThird;
      if(A[twoThird] == target) return twoThird;

      if(target < A[oneThird]) return rec_ternary_search(left, oneThird-1, A, target);
      if(target > A[twoThird]) return rec_ternary_search(twoThird+1, right, A, target);

      return rec_ternary_search(oneThird+1, twoThird-1, A, target);
    }
  else return -1;
}
